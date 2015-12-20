//
//  InstructionsViewController.swift
//  CoffEEEbot
//
//  Created by Aaron Sheah on 07/12/2015.
//  Copyright © 2015 Aaron Sheah. All rights reserved.
//

import UIKit

var instructionIndex:Int = 0

class InstructionsViewController: UIViewController {
    
    var responsePublisher = RBManager.defaultManager().addPublisher("/answer", messageType: "std_msgs/Int32")
    
    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var instructionLabel: UILabel!
    @IBOutlet weak var instructionImage: UIImageView!
    @IBAction func nextInstructionAction(sender: AnyObject) {
        if instructionIndex == (instructionDictionary.count-1) {
            instructionIndex = (instructionIndex+1)%(instructionDictionary.count)

            let msg = IntMessage()
            msg.data = 0
            responsePublisher.publish(msg)
            
            performSegueWithIdentifier("finishedInstructions", sender: nil)
        }
        else {
            instructionIndex = (instructionIndex+1)%(instructionDictionary.count)
            reloadLabels()
        }
    }
    
    @IBAction func doneWithInstructions(sender: AnyObject) {
        nextInstructionAction(0)
    }
    var instructionDictionaryCoffeeMilk = [
        Instruction(description: "Turn on the Coffee Machine", image: UIImage.gifWithName("turnon")!),
        Instruction(description: "Place a cup under the dispenser", image: UIImage.gifWithName("placecup")!),
        Instruction(description: "Look for your Coffee Choice '\(chosenCoffee.name)' in the Carousel. From the same column in the carousel, take both the Coffee capsule (black bottom) and the Milk (white bottom) capsule", image: chosenCoffee.capsuleImage),
        Instruction(description: "Open Coffee Machine Tray and Place the MILK tablet into the tray first", image: UIImage.gifWithName("placecapsule")!),
        Instruction(description: "Close the Cover and Tilt the Handle to the right for \(chosenCoffee.milkDuration) seconds. Then push the handle back to the center", image: UIImage.gifWithName("closeandtilt")!),
        Instruction(description: "Open the Cover and Remove the tablet. Then place the Coffee Capsule into the tray", image: UIImage.gifWithName("placecapsule")!),
        Instruction(description: "Close the Cover and Tilt the Handle to the right for \(chosenCoffee.coffeeDuration) seconds. Then push the handle back to the center", image: UIImage.gifWithName("closeandtilt")!),
        Instruction(description: "Your \(chosenCoffee.name) is ready!", image: UIImage.gifWithName("fireworks")!)
        
    ]
    var instructionDictionaryCoffee = [
        Instruction(description: "Turn on the Coffee Machine", image: UIImage.gifWithName("turnon")!),
        Instruction(description: "Place a cup under the dispenser", image: UIImage.gifWithName("placecup")!),
        Instruction(description: "Look for your Coffee Choice '\(chosenCoffee.name)' in the Carousel. Take Coffee tablet from the Carousel", image: chosenCoffee.capsuleImage),
        Instruction(description: "Open the Cover. Then place the Coffee Table into the tray", image: UIImage.gifWithName("placecapsule")!),
        Instruction(description: "Close the Cover and Tilt the Handle to the right for \(chosenCoffee.coffeeDuration) seconds. Then push the handle back to the center", image: UIImage.gifWithName("closeandtilt")!),
        Instruction(description: "Your \(chosenCoffee.name) is ready!", image: UIImage.gifWithName("fireworks")!)
    ]
    
    var instructionDictionary = []
    
    func reloadLabels() {
        let instruction = instructionDictionary[instructionIndex] as! Instruction
        titleLabel.text = "Step \(instructionIndex+1)"
        instructionLabel.text = instruction.description
        
        if instruction.image != UIImage() {
            instructionImage.image = instruction.image
        }
//        instructionImage.image = UIImage.gifWithName("jeremy")
        
//        fliteEngine.speakText(instruction.description)
    }

    var fliteEngine = FliteTTS()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
//        fliteEngine.setVoice("cmu_us_slt")
        
        if chosenCoffee.milkDuration > 0 {
            instructionDictionary = instructionDictionaryCoffeeMilk
        } else {
            instructionDictionary = instructionDictionaryCoffee
        }
        
        reloadLabels()
    }
}