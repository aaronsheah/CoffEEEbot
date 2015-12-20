//
//  RememberViewController.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 15/12/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

class RememberViewController: UIViewController {

    var privacyPublisher = RBPublisher()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        privacyPublisher = RBManager.defaultManager().addPublisher("/privacy", messageType: "std_msgs/Int32")
    }
    
    @IBAction func yesRememberAction(sender: AnyObject) {
        sendPrivacy(1)
    }
    
    @IBAction func noRememberAction(sender: AnyObject) {
        sendPrivacy(0)
    }
    
    func sendPrivacy(pref:Int) {
        let msg = IntMessage()
        msg.data = pref
        privacyPublisher.publish(msg)
    }
}
