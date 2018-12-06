/*


Credit to Ikhsan Ismail for the original code
which can be found here:
https://www.hackster.io/San_Ismail/paper-piano-with-arduino-e27da7

Modified by Desmond Ku
*/
// Import the CapacitiveSensor Library.
#include <CapacitiveSensor.h>


// pin definition
#define speaker 11
#define light 5
#define button1 12
#define button2 13

// define notes
#define B0 31
#define C1 33
#define CS1 35
#define D1 37
#define DS1 39
#define E1 41
#define F1 44
#define FS1 46
#define G1 49
#define GS1 52
#define A1 55
#define AS1 58
#define B1 62
#define C2 65
#define CS2 69
#define D2 73
#define DS2 78
#define E2 82
#define F2 87
#define FS2 93
#define G2 98
#define GS2 104
#define A2 110
#define AS2 117
#define B2 123
#define C3 131
#define CS3 139
#define D3 147
#define DS3 156
#define E3 165
#define F3 175
#define FS3 185
#define G3 196
#define GS3 208
#define A3 220
#define AS3 233
#define B3 247
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define F4 349
#define FS4 370
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494
#define C5 523
#define CS5 554
#define D5 587
#define DS5 622
#define E5 659
#define F5 698
#define FS5 740
#define G5 784
#define GS5 831
#define A5 880
#define AS5 932
#define B5 988
#define C6 1047
#define CS6 1109
#define D6 1175
#define DS6 1245
#define E6 1319
#define F6 1397
#define FS6 1480
#define G6 1568
#define GS6 1661
#define A6 1760
#define AS6 1865
#define B6 1976
#define C7 2093
#define CS7 2217
#define D7 2349
#define DS7 2489
#define E7 2637
#define F7 2794
#define FS7 2960
#define G7 3136
#define GS7 3322
#define A7 3520
#define AS7 3729
#define B7 3951
#define C8 4186
#define CS8 4435

// value of photoresistor
int value;
// threshold of flat and sharp
int flat = 100;
int sharp = 500;
// octave
int mode = 3;
// button states
int cur1 = HIGH;
int last1 = HIGH;
int cur2 = HIGH;
int last2 = HIGH;


// Set the Send Pin & Receive Pin.
CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        
CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);         
CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);     
CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);     
CapacitiveSensor   cs_2_7 = CapacitiveSensor(2,7);      
CapacitiveSensor   cs_2_8 = CapacitiveSensor(2,8);         
CapacitiveSensor   cs_2_9 = CapacitiveSensor(2,9);  
CapacitiveSensor   cs_2_10 = CapacitiveSensor(2,10);     


void setup()                    
{
  cs_2_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  digitalWrite(button1, HIGH);
  digitalWrite(button2, HIGH);
  // Arduino start communicate with computer.
  Serial.begin(9600);
}

void loop()                    
{
  // Set a timer.
  long start = millis();
  
  // Set the sensitivity of the sensors.
  long total1 =  cs_2_3.capacitiveSensor(3000);
  long total2 =  cs_2_4.capacitiveSensor(3000);
  long total3 =  cs_2_5.capacitiveSensor(3000);
  long total4 =  cs_2_6.capacitiveSensor(3000);
  long total5 =  cs_2_7.capacitiveSensor(3000);
  long total6 =  cs_2_8.capacitiveSensor(3000);
  long total7 =  cs_2_9.capacitiveSensor(3000);
  long total8 =  cs_2_10.capacitiveSensor(3000);
  
  value = analogRead(light);
  last1 = cur1;
  last2 = cur2;
  cur1 = digitalRead(button1);
  cur2 = digitalRead(button2);

  if (cur1 == LOW && last1 == HIGH)
  {
    mode++;
    if (mode >= 7)
      mode = 7; 
  }
  if (cur2 == LOW && last2 == HIGH)
  {
    mode--;
    if (mode <= 1)
      mode = 1; 
  }
  
  Serial.print(millis() - start);        // check on performance in milliseconds
  Serial.print("\t");                    // tab character for debug windown spacing

  Serial.print(value);                   // print value of photoresistor
  Serial.print("\t");                    // Leave some space before print the next output
 
  Serial.print(total1);                  // print sensor output 1
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total2);                  // print sensor output 2
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total3);                  // print sensor output 3
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total4);                  // print sensor output 4
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total5);                  // print sensor output 5
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total6);                  // print sensor output 6
  Serial.print("\t");                    // Leave some space before print the next output
  Serial.print(total7);                   // print sensor output 7
                                          // Leave some space before print the next output
  Serial.print("\t");
  Serial.println(total8);                 // print sensor output 8
                                         // "println" - "ln" represent as "line", system will jump to next line after print the output.
  switch(mode)
  {
    case 1:
      Octave1(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;
    case 2:
      Octave2(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;
    case 3:
      Octave3(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;
    case 4:
      Octave4(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;
    case 5:
      Octave5(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;
    case 6:
      Octave6(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;
    case 7:
      Octave7(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;
    default:
      Octave3(total1,total2,total3,total4,total5,total6,total7,total8,value);
      break;  
  }
  
  // When hand didn't touch on it, no tone is produced.
  // because of change above change 500 to 1000
  if (total1<=500  &  total2<=500  &  total3<=500 & total4<=500  &  total5<=500  &  total6<=500 &  total7<=500 &  total8<=500)
    noTone(speaker);

  delay(10);                             // arbitrary delay to limit data to serial port 
}

void Octave1(long total1, long total2, long total3, long total4, long total5, long total6, long total7, long total8, int value)
{
  if (value < flat) // flat
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 500) tone(speaker,B0);   // frequency
    if (total2 > 500) tone(speaker,CS1);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,DS1);
    if (total4 > 500) tone(speaker,E1);
    if (total5 > 500) tone(speaker,FS1);
    if (total6 > 500) tone(speaker,GS1);
    if (total7 > 500) tone(speaker,AS1);
    if (total8 > 500) tone(speaker,B1);
  }
  else if (value > sharp) // sharp
  {
    if (total1 > 500) tone(speaker,CS1);   // frequency
    if (total2 > 500) tone(speaker,DS1);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,F1);
    if (total4 > 500) tone(speaker,FS1);
    if (total5 > 500) tone(speaker,GS1);
    if (total6 > 500) tone(speaker,AS1);
    if (total7 > 500) tone(speaker,C2);
    if (total8 > 500) tone(speaker,CS2);
  }
  else // white keys
  {
    if (total1 > 500) tone(speaker,C1);   // frequency
    if (total2 > 500) tone(speaker,D1);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,E1);
    if (total4 > 500) tone(speaker,F1);
    if (total5 > 500) tone(speaker,G1);
    if (total6 > 500) tone(speaker,A1);
    if (total7 > 500) tone(speaker,B1);
    if (total8 > 500) tone(speaker,C2);
  }
}

void Octave2(long total1, long total2, long total3, long total4, long total5, long total6, long total7, long total8, int value)
{
  if (value < flat) // flat
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 500) tone(speaker,B1);   // frequency
    if (total2 > 500) tone(speaker,CS2);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,DS2);
    if (total4 > 500) tone(speaker,E2);
    if (total5 > 500) tone(speaker,FS2);
    if (total6 > 500) tone(speaker,GS2);
    if (total7 > 500) tone(speaker,AS2);
    if (total8 > 500) tone(speaker,B2);
  }
  else if (value > sharp) // sharp
  {
    if (total1 > 500) tone(speaker,CS2);   // frequency
    if (total2 > 500) tone(speaker,DS2);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,F2);
    if (total4 > 500) tone(speaker,FS2);
    if (total5 > 500) tone(speaker,GS2);
    if (total6 > 500) tone(speaker,AS2);
    if (total7 > 500) tone(speaker,C3);
    if (total8 > 500) tone(speaker,CS3);
  }
  else // white keys
  {
    if (total1 > 500) tone(speaker,C2);   // frequency
    if (total2 > 500) tone(speaker,D2);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,E2);
    if (total4 > 500) tone(speaker,F2);
    if (total5 > 500) tone(speaker,G2);
    if (total6 > 500) tone(speaker,A2);
    if (total7 > 500) tone(speaker,B2);
    if (total8 > 500) tone(speaker,C3);
  }
}

void Octave3(long total1, long total2, long total3, long total4, long total5, long total6, long total7, long total8, int value)
{
  if (value < flat) // flat
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 500) tone(speaker,B2);   // frequency
    if (total2 > 500) tone(speaker,CS3);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,DS3);
    if (total4 > 500) tone(speaker,E3);
    if (total5 > 500) tone(speaker,FS3);
    if (total6 > 500) tone(speaker,GS3);
    if (total7 > 500) tone(speaker,AS3);
    if (total8 > 500) tone(speaker,B3);
  }
  else if (value > sharp) // sharp
  {
    if (total1 > 500) tone(speaker,CS3);   // frequency
    if (total2 > 500) tone(speaker,DS3);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,F3);
    if (total4 > 500) tone(speaker,FS3);
    if (total5 > 500) tone(speaker,GS3);
    if (total6 > 500) tone(speaker,AS3);
    if (total7 > 500) tone(speaker,C4);
    if (total8 > 500) tone(speaker,CS4);
  }
  else // white keys
  {
    if (total1 > 500) tone(speaker,C3);   // frequency
    if (total2 > 500) tone(speaker,D3);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,E3);
    if (total4 > 500) tone(speaker,F3);
    if (total5 > 500) tone(speaker,G3);
    if (total6 > 500) tone(speaker,A3);
    if (total7 > 500) tone(speaker,B3);
    if (total8 > 500) tone(speaker,C4);
  }
}

void Octave4(long total1, long total2, long total3, long total4, long total5, long total6, long total7, long total8, int value)
{
  if (value < flat) // flat
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 500) tone(speaker,B3);   // frequency
    if (total2 > 500) tone(speaker,CS4);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,DS4);
    if (total4 > 500) tone(speaker,E4);
    if (total5 > 500) tone(speaker,FS4);
    if (total6 > 500) tone(speaker,GS4);
    if (total7 > 500) tone(speaker,AS4);
    if (total8 > 500) tone(speaker,B4);
  }
  else if (value > sharp) // sharp
  {
    if (total1 > 500) tone(speaker,CS4);   // frequency
    if (total2 > 500) tone(speaker,DS4);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,F4);
    if (total4 > 500) tone(speaker,FS4);
    if (total5 > 500) tone(speaker,GS4);
    if (total6 > 500) tone(speaker,AS4);
    if (total7 > 500) tone(speaker,C5);
    if (total8 > 500) tone(speaker,CS5);
  }
  else // white keys
  {
    if (total1 > 500) tone(speaker,C4);   // frequency
    if (total2 > 500) tone(speaker,D4);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,E4);
    if (total4 > 500) tone(speaker,F4);
    if (total5 > 500) tone(speaker,G4);
    if (total6 > 500) tone(speaker,A4);
    if (total7 > 500) tone(speaker,B4);
    if (total8 > 500) tone(speaker,C5);
  }
}

void Octave5(long total1, long total2, long total3, long total4, long total5, long total6, long total7, long total8, int value)
{
  if (value < flat) // flat
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 500) tone(speaker,B4);   // frequency
    if (total2 > 500) tone(speaker,CS5);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,DS5);
    if (total4 > 500) tone(speaker,E5);
    if (total5 > 500) tone(speaker,FS5);
    if (total6 > 500) tone(speaker,GS5);
    if (total7 > 500) tone(speaker,AS5);
    if (total8 > 500) tone(speaker,B5);
  }
  else if (value > sharp) // sharp
  {
    if (total1 > 500) tone(speaker,CS5);   // frequency
    if (total2 > 500) tone(speaker,DS5);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,F5);
    if (total4 > 500) tone(speaker,FS5);
    if (total5 > 500) tone(speaker,GS5);
    if (total6 > 500) tone(speaker,AS5);
    if (total7 > 500) tone(speaker,C6);
    if (total8 > 500) tone(speaker,CS6);
  }
  else // white keys
  {
    if (total1 > 500) tone(speaker,C5);   // frequency
    if (total2 > 500) tone(speaker,D5);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,E5);
    if (total4 > 500) tone(speaker,F5);
    if (total5 > 500) tone(speaker,G5);
    if (total6 > 500) tone(speaker,A5);
    if (total7 > 500) tone(speaker,B5);
    if (total8 > 500) tone(speaker,C6);
  }
}

void Octave6(long total1, long total2, long total3, long total4, long total5, long total6, long total7, long total8, int value)
{
  if (value < flat) // flat
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 500) tone(speaker,B5);   // frequency
    if (total2 > 500) tone(speaker,CS6);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,DS6);
    if (total4 > 500) tone(speaker,E6);
    if (total5 > 500) tone(speaker,FS6);
    if (total6 > 500) tone(speaker,GS6);
    if (total7 > 500) tone(speaker,AS6);
    if (total8 > 500) tone(speaker,B6);
  }
  else if (value > sharp) // sharp
  {
    if (total1 > 500) tone(speaker,CS6);   // frequency
    if (total2 > 500) tone(speaker,DS6);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,F6);
    if (total4 > 500) tone(speaker,FS6);
    if (total5 > 500) tone(speaker,GS6);
    if (total6 > 500) tone(speaker,AS6);
    if (total7 > 500) tone(speaker,C7);
    if (total8 > 500) tone(speaker,CS7);
  }
  else // white keys
  {
    if (total1 > 500) tone(speaker,C6);   // frequency
    if (total2 > 500) tone(speaker,D6);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,E6);
    if (total4 > 500) tone(speaker,F6);
    if (total5 > 500) tone(speaker,G6);
    if (total6 > 500) tone(speaker,A6);
    if (total7 > 500) tone(speaker,B6);
    if (total8 > 500) tone(speaker,C7);
  }
}

void Octave7(long total1, long total2, long total3, long total4, long total5, long total6, long total7, long total8, int value)
{
  if (value < flat) // flat
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 500) tone(speaker,B6);   // frequency
    if (total2 > 500) tone(speaker,CS7);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,DS7);
    if (total4 > 500) tone(speaker,E7);
    if (total5 > 500) tone(speaker,FS7);
    if (total6 > 500) tone(speaker,GS7);
    if (total7 > 500) tone(speaker,AS7);
    if (total8 > 500) tone(speaker,B7);
  }
  else if (value > sharp) // sharp
  {
    if (total1 > 500) tone(speaker,CS7);   // frequency
    if (total2 > 500) tone(speaker,DS7);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,F7);
    if (total4 > 500) tone(speaker,FS7);
    if (total5 > 500) tone(speaker,GS7);
    if (total6 > 500) tone(speaker,AS7);
    if (total7 > 500) tone(speaker,C8);
    if (total8 > 500) tone(speaker,CS8);
  }
  else // white keys
  {
    if (total1 > 500) tone(speaker,C7);   // frequency
    if (total2 > 500) tone(speaker,D7);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 500) tone(speaker,E7);
    if (total4 > 500) tone(speaker,F7);
    if (total5 > 500) tone(speaker,G7);
    if (total6 > 500) tone(speaker,A7);
    if (total7 > 500) tone(speaker,B7);
    if (total8 > 500) tone(speaker,C8);
  }
}
