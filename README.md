# CS207-project
This project is a simple piano system that contains 8 keys but produces as many notes as a normal piano. This piano is built using an arduino uno and using the Capsense library.
# Repository Contents
- /src - here is the code for the project
- /libraries - any libraries you will need for the project
- /img - images for the readme
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
# Build Instructions

# Usage
To use the paino system follow these steps
- open the Arduino IDE
- upload the code to the Arduino
- once the code is uploaded press on the keyboard
- you used the project

other features include making the notes flat or sharp
- to make the notes sharp apply a bright light to the photoresistor
- to make the notes flat apply a shadow to the photoresistor

depending on the light in the room the notes may already be flat or sharp
- if flat may need to apply a bright light close to the resistor to get it sharp
- if sharp may need to get a darker shadow to make flat

another feature is the octave buttons
- pressing one of the buttons makes the octave range go up or down
- there are 7 octaves programmed in the code
- if you are at the lowest octave it won't go any lower
- if you are at the highest ovtave it won't go any higher
# Team
The team consists of me but with the help of some of my friends to help gather some of the materials
# Credits
- Trevor Tomesh - for providing a demo repo to base the README and structure of the repo
- Ikhsan Ismail - for the project idea and base code
