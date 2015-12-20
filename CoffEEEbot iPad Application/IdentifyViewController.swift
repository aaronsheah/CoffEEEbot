//
//  IdentifyViewController.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 15/12/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

// SUBSCRIBER
var questionSubscriber = RBSubscriber()

var firstMsg = question_msg()

class IdentifyViewController: UIViewController,RBManagerDelegate {
    
    @IBAction func existingCustomer(sender: AnyObject) {
        performSegueWithIdentifier("doneIdentify", sender: nil)
        sendExistingCustomer(1)
    }
    
    @IBAction func newCustomer(sender: AnyObject) {
        sendExistingCustomer(0)
    }
    
    func sendExistingCustomer(data:Int) {
        if RBManager.defaultManager().connected {
            let msg = IntMessage()
            msg.data = data
            existingCustomerPublisher.publish(msg)
        }
    }
    
    var existingCustomerPublisher = RBManager.defaultManager().addPublisher("/existingCustomer", messageType:"std_msgs/Int32")
    var idleStatePublisher = RBManager.defaultManager().addPublisher("/idleState", messageType:"std_msgs/Int32")
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let msg = IntMessage()
        msg.data = 1
        idleStatePublisher.publish(msg)
        
        // SUBSCRIBER
        questionSubscriber = RBManager.defaultManager().addSubscriber("/question", responseTarget: self, selector:Selector("questionReceivedFromROS2:"), messageClass: question_msg.self)
        questionSubscriber.subscribe()
    }
    
    func questionReceivedFromROS2(msg:question_msg) {
        firstMsg = msg
    }
}
