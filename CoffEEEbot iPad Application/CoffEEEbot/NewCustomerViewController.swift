//
//  NewCustomerViewController.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 15/12/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

class NewCustomerViewController: UIViewController {
    @IBAction func submitName(sender: AnyObject) {
        if nameTextField.text != nil {
            let msg = StringMessage()
            msg.data = nameTextField.text!
            namePublisher.publish(msg)
            performSegueWithIdentifier("nameSubmitted", sender: nil)
        }
    }
    @IBOutlet weak var nameTextField: UITextField!
    
    var namePublisher = RBManager.defaultManager().addPublisher("/name", messageType:"std_msgs/String")
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        nameTextField.becomeFirstResponder()
    }
}
