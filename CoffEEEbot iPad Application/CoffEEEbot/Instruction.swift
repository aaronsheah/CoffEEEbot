//
//  Instruction.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 07/12/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

class Instruction {
    var description:String
    var imageName:String = ""
    var image:UIImage = UIImage()
    
    init(description:String) {
        self.description = description
    }
    init(description:String,imageName:String) {
        self.description = description
        self.imageName = imageName
        self.image = UIImage(named: imageName)!
    }
    init(description:String,image:UIImage) {
        self.description = description
        self.image = image
    }
}