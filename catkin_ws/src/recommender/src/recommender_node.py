#!/usr/bin/python2.7

import rospy
from std_msgs.msg import String, Int8
from recommender.msg import RecMsgStruc, Trx
import psycopg2 as pg2
import pandas as pd
import numpy as np
import datetime
from sklearn.neighbors import KNeighborsClassifier

# connect to database
try:
	conn = pg2.connect("dbname = 'coffeeebot_db'")
	print "Connected to DB"
except:
	print "Unable to establish connection to database"

# set up cursor
cur = conn.cursor()



def writeToDB_S0(data):
	# for stage 0 only - userID always = 0
	userID = 0
	cur.execute("INSERT INTO trx (userID, drink) VALUES (%s, %s);", [userID, data.data])
	conn.commit()
	# print 'commited'



def writeToDB_S12(data):
	if data.keep == 1:
		return
	else:
		drinks_df = pd.read_sql("SELECT drink, ROW_NUMBER() over () as drink_index FROM drinks", conn)
		print drinks_df
		temp = data.drink + 1
		print temp
		print type(temp)
		drinkOrdered = drinks_df.drink[drinks_df.drink_index == temp]
		print int(data.userID)
		print drinkOrdered
		cur.execute("INSERT INTO trx (userID, drink) VALUES (%s, %s);", [int(data.userID), drinkOrdered.iloc[0]])
		conn.commit()
		print drinkOrdered.iloc[0]
		print data.isExist
		if data.isExist == 0:
			cur.execute("INSERT INTO users VALUES (%s, %s);", [int(data.userID), data.name])
			conn.commit()
			print data.name
	
	

def recommender_func(data):
	print data.data
	if data.data == 'UnknownHead':
		userID = pd.read_sql("SELECT MAX(userID) FROM trx;", conn)
		userID = userID.iloc[0][0]+1
	else:
		userID = int(data.data)

	print 'userID = ', userID

	# initialisation
	recommendation = []
	rec_index = []
	current = np.datetime64(datetime.datetime.now())
	current = current.astype(np.int64) // 10 ** 9

	# pull drink information
	drinks_df = pd.read_sql("SELECT drink, caffeinated, ROW_NUMBER() over () as drink_index FROM drinks", conn)
	cur.execute("SELECT EXISTS (SELECT 1 FROM trx WHERE userID = %s);", [userID])
	repeatCus = cur.fetchall()
	repeatCus = repeatCus[0][0]
	# check if customer has visited today (True/False flag)
	cur.execute("SELECT EXISTS (SELECT 1 FROM trx WHERE userID = %s AND timestamp >= now()::date);", [userID])

	cameToday = cur.fetchall()
	cameToday = cameToday[0][0]

	# check if customer has ever visited (True/False flag)
	cur.execute("SELECT EXISTS (SELECT 1 FROM trx WHERE userID = %s);", [userID])
	repeatCus = cur.fetchall()
	repeatCus = repeatCus[0][0]

	print 'cameToday = ', cameToday
	print 'repeatCus = ', repeatCus


	if repeatCus:
		df = pd.read_sql("SELECT drink, COUNT(drink) FROM trx WHERE (userID = %s) GROUP BY drink ORDER BY COUNT(drink) DESC;", conn, params = [userID])
		df = pd.merge(df, drinks_df, how = 'left', on = 'drink')

		# check whether customer has consumed high dose of caffeine
		if cameToday:
			df_today = pd.read_sql("SELECT drink, COUNT(drink) FROM trx WHERE (userID = %s AND timestamp >= now()::date) GROUP BY drink;", conn, params = [userID])
			df_today = pd.merge(df_today, drinks_df, how = 'left', on = 'drink')
		
			# recommend decaf drinks
			if df_today[df_today.caffeinated == True].sum()['count'] >= 3:
				decaf_drinks = drinks_df[drinks_df.caffeinated == False]
				recommendation.extend(decaf_drinks.drink.tolist())
				rec_index.extend(decaf_drinks.drink_index.tolist())
				df = df[~df.drink.isin(decaf_drinks)]
	
		# recommend drinks in order of consumption pattern
		recommendation.extend(df.drink.tolist())
		rec_index.extend(df.drink_index.tolist())

	if len(rec_index) < len(drinks_df.index):
		# pull one month's data alone to avoid heavy data processing
		# also helps with seasonality (people's taste change with time)
		drinks_df = pd.read_sql("SELECT drink, ROW_NUMBER() over () as drink_index FROM drinks;", conn)
		df = pd.read_sql("SELECT * FROM trx WHERE timestamp BETWEEN (now() - '1 month'::interval)::timestamp AND now();", conn)
		df = pd.merge(df, drinks_df, how = 'left', on = 'drink')

		# extract timestamp and drink index
		# convert timestamp to unix timestamp
		data = df[['timestamp', 'drink_index']]
		data.loc[:, 'unix_timestamp'] = data.timestamp.astype(np.int64) // 10 ** 9
		data = data[['unix_timestamp', 'drink_index']]
		data_array = np.array(data)

		# set up classifier
		neighbor_size = 5
		classifier = KNeighborsClassifier(n_neighbors = neighbor_size, weights = 'distance')

		for i in range(0, len(drinks_df.index)-len(rec_index)):
			data = data[~data['drink_index'].isin(rec_index)]
			if len(data.index) < neighbor_size:
				neighbor_size = len(data.index)
				classifier = KNeighborsClassifier(n_neighbors = neighbor_size, weights = 'distance')
			data_array = np.array(data)
			classifier.fit(data_array[:,0].reshape(-1,1), data_array[:,1])
			prediction = classifier.predict(current)
			recommendation.extend(drinks_df.drink[prediction-1])
			rec_index.extend(prediction)
	

	# pull drink combinations (in pairs)
	sql_query = 'SELECT A.drink AS drink_a, B.drink AS drink_b, A.sweetness-B.sweetness AS sweetness, CAST(A.caffeinated as int)-CAST(B.caffeinated as int) AS caffeinated, CAST(A.milk as int)-CAST(B.milk as int) AS milk, CAST(A.tea as int)-CAST(B.tea as int) AS tea, A.strength-B.strength AS strength FROM drinks A, drinks B WHERE A.drink <> B.drink AND A.sweetness > B.sweetness;'
	drinks_combinations = pd.read_sql(sql_query, conn)
	
	msg_strc = [rec_index[0]]
	TeaQ = True
	MilkQ = True
	CaffQ = True
	StrengthQ = True

	for i in range(1, len(rec_index)-1):
		temp = drinks_combinations[((drinks_combinations.drink_a == recommendation[i]) & (drinks_combinations.drink_b == recommendation[i+1])) | ((drinks_combinations.drink_b == recommendation[i]) & (drinks_combinations.drink_a == recommendation[i+1]))]
		temp = temp.reset_index()


		if ((temp.tea[0] <> 0) & TeaQ):
			if ((temp.tea[0] > 0) & (recommendation[i] == temp.drink_a[0])) | ((temp.tea[0] < 0) & (recommendation[i] == temp.drink_b[0])):
				msg_strc.append('Would you like a cup of tea?')
			else:
				msg_strc.append('Would you prefer coffee over tea?')
			TeaQ = False


		elif ((temp.milk[0] <> 0) & MilkQ):
			if ((temp.milk[0] > 0) & (recommendation[i] == temp.drink_a[0])) | ((temp.milk[0] < 0) & (recommendation[i] == temp.drink_b[0])):
				msg_strc.append('Would you like a drink with milk?')
			else:
				msg_strc.append('Do you prefer drink without milk?')
			MilkQ = False


		elif ((temp.strength[0] <> 0) & StrengthQ):
			if ((temp.strength[0] > 0) & (recommendation[i] == temp.drink_a[0])) | ((temp.strength[0] < 0) & (recommendation[i] == temp.drink_b[0])):
				msg_strc.append('Would you like a stronger drink?')
			else:
				msg_strc.append('Do you prefer a drink that is less strong?')
			StrengthQ = False

		
		elif ((temp.caffeinated[0] <> 0) & CaffQ):
			if ((temp.caffeinated[0] > 0) & (recommendation[i] == temp.drink_a[0])) | ((temp.caffeinated[0] < 0) & (recommendation[i] == temp.drink_b[0])):
				msg_strc.append('Do you prefer a caffeinated drink to a decaf one?')
			else:
				msg_strc.append('Would you like a decaf drink?')
			CaffQ = False


		else:
			if (recommendation[i] == temp.drink_a[0]):
				msg_strc.append('Would you like a sweeter drink?')
			else:
				msg_strc.append('Woudl you like a drink that is less sweet?')
	

		msg_strc.append(rec_index[i])

		if (i+1) == len(rec_index)-1:
			msg_strc.append(rec_index[i+1])

	#for i in range(0, len(msg_strc)):
	#	print msg_strc[i]
	
	pub = rospy.Publisher('recommender', RecMsgStruc, queue_size = 10)
	rate = rospy.Rate(0.5)
	pub_msg = RecMsgStruc()
	
	userName = pd.read_sql('SELECT name FROM users WHERE userID = %s ;', conn, params = [userID])

	print 'before publish'
	
	if userName.empty:
		pub_msg.Name = ''
		pub_msg.isExist = 0
	else:
		pub_msg.Name = userName.loc[0][0]
		pub_msg.isExist = 1
	
	pub_msg.userID = str(userID)
	pub_msg.FirstRec = msg_strc[0]
	pub_msg.FirstQ = msg_strc[1]
	pub_msg.SecondRec = msg_strc[2]
	pub_msg.SecondQ = msg_strc[3]
	pub_msg.ThirdRec = msg_strc[4]
	pub_msg.ThirdQ = msg_strc[5]
	pub_msg.ForthRec = msg_strc[6]
	pub_msg.FifthRec = msg_strc[7]
	pub.publish(pub_msg)
	pub.publish(pub_msg)
	pub.publish(pub_msg)
	pub.publish(pub_msg)
	pub.publish(pub_msg)
	print 'after publish'
	rate.sleep()




def listener():
	rospy.init_node('recommender', anonymous=True)

	rospy.Subscriber('coffee', String, writeToDB_S0)
	rospy.Subscriber('privacy', Trx, writeToDB_S12)		
	rospy.Subscriber('userID', String, recommender_func)


	# spin() simply keeps python from exiting until this node is stopped
	rospy.spin()

if __name__ == '__main__':
	listener()
