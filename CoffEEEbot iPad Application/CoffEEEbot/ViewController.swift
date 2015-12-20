//
//  ViewController.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 06/11/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//  Compile Error : If linker problem, add libicucore.tbd in (Build Phases) Link Binary with Libraries

import UIKit
import SceneKit

/********** Global Variables ***********/

var chosenCoffee = Coffee()
var finishedSubscriber = RBSubscriber()

/********** ViewController ***********/
class ViewController: UIViewController {
    
    /******** SceneKit for CoffEEEbot ********/
    @IBOutlet weak var myScene: SCNView!

    /******** ROSBridge Pub/Sub ********/
    // PUBLISHERS - To view these messages 'rostopic /test'
    var testPublisher = RBManager.defaultManager().addPublisher("/coffee", messageType: "std_msgs/String")
    var positionPublisher = RBManager.defaultManager().addPublisher("/to_arduino", messageType: "std_msgs/String")
    var responsePublisher = RBManager.defaultManager().addPublisher("/answer", messageType: "std_msgs/Int32")
    var namePublisher = RBManager.defaultManager().addPublisher("/name", messageType: "std_msgs/String")
    
    /******** CollectionView ********/
    @IBOutlet weak var collectionView: UICollectionView!
    private let reuseIdentifier = "ResponseCell"
    
    /******** Arrays ********/
    var coffeeChoices:NSArray = [
        Coffee(name: "Cappuccino", location: 2, imageName: "Cappuccino.jpg", milkDuration: 14, coffeeDuration: 4, capsuleImageName: "cappuccino_capsule.JPG"),
        Coffee(name: "Cafe au Lait", location: 1, imageName: "Cafe.jpg", coffeeDuration: 15, capsuleImageName: "cafe_capsule.JPG"),
        Coffee(name: "Caramel Latte Macchiato", location: 4, imageName: "Caramel.jpg", milkDuration: 14, coffeeDuration: 4, capsuleImageName: "caramel_capsule.JPG"),
        Coffee(name: "Tea Latte", location: 5, imageName: "Tea.jpg", milkDuration: 8, coffeeDuration: 8, capsuleImageName: "tea_capsule.JPG"),
        Coffee(name: "Lungo Decaf", location: 3, imageName: "Lungo.jpg", coffeeDuration: 10, capsuleImageName: "lungo_capsule.JPG")
    ]
    var responseChoices:NSMutableArray = [
        "Yes",
        "No"
    ]
    var responseAvail:NSMutableArray = [
        true,
        true
    ]
    
    override func viewDidLoad() {
        connectROSBridge()
        
        loadScene("waving")
        
        questionReceivedFromROS(firstMsg)
        
        questionSubscriber = RBManager.defaultManager().addSubscriber("/question", responseTarget: self, selector:Selector("questionReceivedFromROS:"), messageClass: question_msg.self)
        questionSubscriber.subscribe()
        finishedSubscriber = RBManager.defaultManager().addSubscriber("/finished", responseTarget: self, selector: Selector("finishedAction"), messageClass: IntMessage.self)
        finishedSubscriber.subscribe()
        collectionView.backgroundColor = UIColor.whiteColor()
        
//        let timer = NSTimer.scheduledTimerWithTimeInterval(10, target: self, selector: Selector("loadNextxScene"), userInfo: nil, repeats: true)
    }
    
    var animationIndex = 0
    let animationNames = [
        "bored",
        "happy",
        "happy_idle",
        "silly_dancing"
    ]
    func loadNextScene() {
//        print("nextscene")
        loadScene(animationNames[(animationIndex++)%animationNames.count])
    }
    
    var choosingState = false
    // Coffee Button Pressed
    @IBAction func buttonPressed(sender: AnyObject) {
        let choice = sender as! UIButton
        print("Response \(choice.tag)")
        
        let response = IntMessage()
        response.data = Int(choice.tag)
        responsePublisher.publish(response)
        
        if choosingState {
            // Coffee Choice selected
            if choice.tag < coffeeChoices.count {
                chosenCoffee = coffeeChoices[choice.tag] as! Coffee
//                performSegueWithIdentifier("toInstructions", sender: nil)
            }
        }
    }
    // Confirmation of Coffee Choice
    func confirmCoffeeChoice(coffee: Coffee) {
        let refreshAlert = UIAlertController(title: "Confirm Choice", message: "You chose '\(coffee.name)'. Are you sure?", preferredStyle: UIAlertControllerStyle.Alert)
        
        refreshAlert.addAction(UIAlertAction(title: "Yes", style: .Default, handler: { (action: UIAlertAction!) in
            self.presentInstructions()
            chosenCoffee = coffee
            print("Handle Ok logic here")
        }))
        
        refreshAlert.addAction(UIAlertAction(title: "No", style: .Default, handler: { (action: UIAlertAction!) in
            print("Handle Cancel Logic here")
        }))
        
        presentViewController(refreshAlert, animated: true, completion: nil)
    }
    // Segue to Instructions
    func presentInstructions(){
        performSegueWithIdentifier("toInstructions", sender: nil)
    }
    
    // Testing (Generate messages)
    @IBOutlet weak var speechBubble: UILabel!
    @IBAction func speechReceived(sender: AnyObject) {
        
    }
    
    @IBAction func responsesReceived(sender: AnyObject) {

        
        let msg1 = StringMessage()
        msg1.data = "1,12221"
        let msg2 = StringMessage()
        msg2.data = "2,0"
        let msg3 = question_msg()
        msg3.ans = 1
        msg3.stock = 12222
        msg3.dialogue = "HELLO WORLD"

        questionReceivedFromROS(msg3)
        
    }
    func translateResponses(data:[Int]) {
        
        let mode = data[0]
        // Coffee Choices
        if mode == 1 {
            choosingState = true
            let dataString = String(data[1])
            var tmp = NSMutableArray()
            
            for c in coffeeChoices {
                let coffee = c as! Coffee
                tmp.addObject(coffee.name as String)
            }
            responseChoices = tmp

            tmp.addObject("Intro to Coffee")
            
            tmp = NSMutableArray()
            for c in dataString.characters {
                let c_int = Int(String(c))
                if c_int == 1 {
                    tmp.addObject(false)
                }
                else if c_int == 2 {
                    tmp.addObject(true)
                }
            }
            tmp.addObject(true)
            responseAvail = tmp
        }
        // Yes/No
        else if mode == 2 {
            choosingState = false
            var tmp = NSMutableArray()
            tmp.addObject("Yes")
            tmp.addObject("No")
            responseChoices = tmp
            
            tmp = NSMutableArray()
            tmp.addObject(true)
            tmp.addObject(true)
            responseAvail = tmp
        }
        else if mode == 3 {
            chosenCoffee = coffeeChoices[data[1]] as! Coffee
            performSegueWithIdentifier("toInstructions", sender: nil)
        }
    }
    @IBAction func peformFinishedSegue(sender: AnyObject) {
        finsihedAction(0)
    }
}

/********** Load Animation ***********/
extension ViewController {
    func loadScene(sceneName:String) {
        myScene.scene = SCNScene(named: "\(sceneName).dae")
        myScene.allowsCameraControl = false
        myScene.autoenablesDefaultLighting = true
        myScene.backgroundColor = UIColor.lightGrayColor()
        myScene.backgroundColor = UIColor.whiteColor()
    }
}

/********** ROSBridge ***********/
extension ViewController: RBManagerDelegate {
    func connectROSBridge() {
        // install rosbridge-library
        // to start 'rosbridge' type 'source /opt/ros/indigo/setup.bash'
        // roslaunch rosbridge_server rosbridge_websocket.launch
        // to check what is IP on laptop (ubuntu) type 'hostname -I'
//        ROSMgr.connect("ws://129.31.198.112:9090")
    }
    func disconnectROSBridge() {
        RBManager.defaultManager().disconnect()
    }
    
    func sendMessageString(data:String) {
        let msg = StringMessage()
        msg.data = data
        testPublisher.publish(msg)
    }
    
    func questionReceivedFromROS(msg:question_msg) {
        
        
        
        if msg.ans != 0 {
            loadScene("talking")
            
            responseChoices = []
            responseAvail = []
            self.collectionView.reloadData()
            
            speechBubble.text = msg.dialogue
            translateResponses([msg.ans, msg.stock])
            self.collectionView.reloadData()
        }
        
    }
    
    func finsihedAction(data:Int32) {
        performSegueWithIdentifier("finishedSegue", sender: nil)
    }
}

/********** CollectionView ***********/
extension ViewController: UICollectionViewDataSource, UICollectionViewDelegate {
    func numberOfSectionsInCollectionView(collectionView: UICollectionView) -> Int {
        return 1
    }
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return responseChoices.count
    }
    
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        let cell:ResponseCell = collectionView.dequeueReusableCellWithReuseIdentifier(reuseIdentifier, forIndexPath: indexPath) as! ResponseCell
        
        cell.layer.borderWidth = 1
        cell.layer.borderColor = UIColor.blackColor().CGColor
        cell.layer.cornerRadius = 10
        
        cell.button.tag = indexPath.row
        cell.button.enabled = responseAvail[indexPath.row] as! Bool
        if !cell.button.enabled {
            cell.button.layer.backgroundColor = UIColor(red: 0, green: 0, blue: 0, alpha: 0.5).CGColor
        } else {
            cell.button.layer.backgroundColor = UIColor(red: 0, green: 0, blue: 0, alpha: 0).CGColor
        }
        
        
        let responseChoice = responseChoices[indexPath.row] as! String
        cell.button.titleLabel?.lineBreakMode = NSLineBreakMode.ByWordWrapping
        cell.button.titleLabel?.textAlignment = NSTextAlignment.Center
        if responseChoice == "Cappuccino" {
            cell.image.image = UIImage(named:"Cappuccino.jpg")
        } else if responseChoice == "Lungo Decaf" {
            cell.image.image = UIImage(named:"Lungo.jpg")
        } else if responseChoice == "Caramel Latte Macchiato" {
            cell.image.image = UIImage(named:"Caramel.jpg")
        } else if responseChoice == "Cafe au Lait" {
            cell.image.image = UIImage(named:"Cafe.jpg")
        } else if responseChoice == "Tea Latte" {
            cell.image.image = UIImage(named:"Tea.jpg")
        } else {
            cell.image.image = nil
            if responseChoice == "Yes" {
                cell.layer.backgroundColor = UIColor(red: 135/255, green: 211/255, blue: 124/255, alpha: 1).CGColor
            } else if responseChoice == "No" {
                cell.layer.backgroundColor = UIColor(red: 214/255, green: 69/255, blue: 65/255, alpha: 1).CGColor
            } else if responseChoice == "Intro to Coffee" {
                cell.layer.backgroundColor = UIColor(red: 89/255, green: 171/255, blue: 227/255, alpha: 1).CGColor
            } else {
                cell.layer.backgroundColor = UIColor(red: 89/255, green: 171/255, blue: 227/255, alpha: 1).CGColor
            }
        }
        cell.button.setTitle(responseChoice, forState: UIControlState.Normal)
        
        cell.button.titleLabel!.font = UIFont(name: cell.button.titleLabel!.font.fontName, size: 180/CGFloat(coffeeChoices.count))
        
        return cell
    }
}
extension ViewController: UICollectionViewDelegateFlowLayout {
    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: NSIndexPath) -> CGSize {
        let collectionViewSize = collectionView.frame.size
        let n = responseChoices.count
        var width_per_element = collectionViewSize.width/CGFloat(n) - 5
        var height_per_element = collectionViewSize.height - 5
        
        if n > 3 {
            let rows = CGFloat((n-1)/3 + 1)
            width_per_element = collectionViewSize.width/3 - 10
            height_per_element = collectionViewSize.height/rows - 10
        }
        
        return CGSize(width: width_per_element, height: height_per_element)
    }
}