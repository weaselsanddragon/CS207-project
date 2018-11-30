# CS207-project
This project is a simple piano system that contains 8 keys but produces as many notes as a normal piano. This piano is built using an arduino uno and using the Capsense library.

<img src=https://github.com/weaselsanddragon/CS207-project/blob/master/img/project.jpg width="500" height="500">

# Repository Contents
- /img - images for the readme
- /libraries - any libraries you will need for the project
- /src - here is the code for the project
- /README.md - the file you are reading right now
# Requirements and Materials
Software:
- Arduino IDE https://www.arduino.cc/en/Main/Software
- Capacitive Sensing Library https://playground.arduino.cc/Main/CapacitiveSensor?from=Main.CapSense
The Capacitive Sensing Library can also be found in the libraries folder.

Materials:
- 1 x Arduino UNO
- 1 x breadboard
- 8 x metal paperclips
- 1 x paper
- 1 x pencil
- 8 x 1M ohm resistor
- 1 x 220 ohm resistor
- 1 x piezo buzzer
- 1 x photoresistor
- 2 x push buttons
- ~30-40 x male-male wires
- tape
# Build Instructions
The first thing you will want to do is make the piano. On a 8 1/2 x 11 piece of white paper draw 8 piano keys on the piece of paper USING PENCIL. I found that if you draw the piano keys about 2 3/4 inchs tall and 1 inch wide you get a good sized key. The image below is NOT to scale but should give you an idea on what I mean. If you want you could style the keys to be more like a piano like the picture at the top of the README. Just make sure that the top of the key is at least a paperclip in width.

NOTE: When drawing the piano with pencil make use you use a lot and that it don't look 'thin' if you dont use enough the drawing will not be conductive enough for your sensor to work

![image of rough piano](https://github.com/weaselsanddragon/CS207-project/blob/master/img/rough%20keyboard.jpg)
The second thing you should do is build the circuit shown down below. in the images below the blue wires should connect to the paper piano you made and in the schematic you would connect a wire from pins 3-10 to the piano before the resistor. For more detailed instructions scroll down.
![image of arduino](https://github.com/weaselsanddragon/CS207-project/blob/master/img/diagram.JPG)
![image of schematic](https://github.com/weaselsanddragon/CS207-project/blob/master/img/diagram2.JPG)
Steps on how to build piano:
- attach a wire from pin 2 to the breadboard
- place a 1 megaohm (1M ohm) resistor connect that to pin 2
- attach a wire from pin 3 to the other end of the resistor
- repeat last 2 steps from pin 4 - pin 10
- on the same end of the resistor of pins 3-10 attach a wire and connect that to your paper piano one wire per key
- to help connect the wire to the paper use either a metal paperclip, tape or both

NOTE: If using tape it may effect the values read for your paper capsense and you may need to edit some lines of code

Steps on how to build speaker:
- attach a wire from pin 11 to speaker
- attach a wire from speaker to GND

NOTE: A resistor may be attached in the circuit to reduce the sound

Steps on how to build buttons:
- attach a wire from pin 12 to one side of the button
- attach a wire from the other side of the button to GND
- repeat for pin 13

NOTE: The button used in the project is a pullup button

NOTE: You could add a resistor and connect to button to 5V but you will need to edit some lines of code

NOTE: This method was done because my breadboard is small

Steps on how to build photoresistor:
- attach a wire from 5V to the photoresistor
- attach a wire from photoresistor to A5
- attach a 560 ohm resistor to photoresistor
- attach a wire from resistor to GND

# Usage
To use the paino system follow these steps
- open the Arduino IDE
- upload the code to the Arduino
- once the code is uploaded press on the keyboard
- you used the project

Other features include making the notes flat or sharp
- to make the notes sharp apply a bright light to the photoresistor
- to make the notes flat apply a shadow to the photoresistor

Depending on the light in the room the notes may already be flat or sharp
- if flat may need to apply a bright light close to the resistor to get it sharp
- if sharp may need to get a darker shadow to make flat

Another feature is the octave buttons
- pressing one of the buttons makes the octave range go up or down
- there are 7 octaves programmed in the code
- if you are at the lowest octave it won't go any lower
- if you are at the highest ovtave it won't go any higher
# Team
The team consists of me but with the help of some of my friends to help gather some of the materials.
# Credits
- Trevor Tomesh - for providing a demo repo to base the README and structure of the repo
- Ikhsan Ismail - for the project idea and base code https://www.hackster.io/San_Ismail/paper-piano-with-arduino-e27da7
