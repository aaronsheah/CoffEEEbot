//
//  Coffee.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 10/11/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

class Coffee {
    var name:String
    var location:Int
    var image = UIImage()
    var milkDuration:Int = 0
    var coffeeDuration:Int = 0
    
    var capsuleImage = UIImage()
    
    init() {
        self.name = "unassigned"
        self.location = -1
    }
    
    init(name:String) {
        self.name = name
        self.location = 0
    }
    
    init(name:String, location:Int) {
        self.name = name
        self.location = location
    }
    
    init(name:String, location:Int, imageName:String) {
        self.name = name
        self.location = location
        self.image = UIImage(named:imageName)!
    }
    
    init(name:String, location:Int, imageName:String, coffeeDuration:Int) {
        self.name = name
        self.location = location
        self.coffeeDuration = coffeeDuration
    }
    init(name:String, location:Int, imageName:String, coffeeDuration:Int, capsuleImageName:String) {
        self.name = name
        self.location = location
        self.coffeeDuration = coffeeDuration
        self.capsuleImage = UIImage(named: capsuleImageName)!
    }
    
    init(name:String, location:Int, imageName:String, milkDuration:Int, coffeeDuration:Int) {
        self.name = name
        self.location = location
        self.milkDuration = milkDuration
        self.coffeeDuration = coffeeDuration
    }
    init(name:String, location:Int, imageName:String, milkDuration:Int, coffeeDuration:Int, capsuleImageName:String) {
        self.name = name
        self.location = location
        self.milkDuration = milkDuration
        self.coffeeDuration = coffeeDuration
        self.capsuleImage = UIImage(named: capsuleImageName)!
    }
}