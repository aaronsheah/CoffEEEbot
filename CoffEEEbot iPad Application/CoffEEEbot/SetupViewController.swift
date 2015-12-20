//
//  SetupViewController.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 18/12/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

class SetupViewController: UIViewController, RBManagerDelegate {

    @IBAction func connectROS(sender: AnyObject) {
        if ipAddressField.text != nil {
            let ip_address = ipAddressField.text
            RBManager.defaultManager().connect("ws://\(ip_address!):9090")
        }
    }
    @IBOutlet weak var ipAddressField: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        
        RBManager.defaultManager().delegate = self
        ipAddressField.becomeFirstResponder()
    }

    func managerDidConnect(manager: RBManager!) {
        performSegueWithIdentifier("connectedSegue", sender: nil)
    }

}
