//
//  CoffeeCell.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 07/11/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

class ResponseCell: UICollectionViewCell {
    @IBOutlet weak var button: UIButton!
    @IBOutlet weak var image: UIImageView!
    @IBAction func buttonPressed(sender: AnyObject) {
        
        UIView.animateWithDuration(1, animations: {
            self.button.backgroundColor = UIColor(red: 0, green: 0, blue: 0, alpha: 0.2)
            self.button.backgroundColor = UIColor(red: 0, green: 0, blue: 0, alpha:0)
        })
    }
}
