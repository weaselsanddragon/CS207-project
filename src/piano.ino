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

// value of photoresistor
int value;


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
  
  
  
  if (value < 50) // flat tone
  {
    // When hand is touched the sensor, the speaker will produce a tone.
    // I set a threshold for it, so that the sensor won't be too sensitive.
    if (total1 > 1000) tone(speaker,123);   // frequency
    if (total2 > 1000) tone(speaker,139);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 1000) tone(speaker,156);
    if (total4 > 1000) tone(speaker,165);
    if (total5 > 1000) tone(speaker,185);
    if (total6 > 1000) tone(speaker,208);
    if (total7 > 1000) tone(speaker,233);
    if (total8 > 1000) tone(speaker,247);
  }
  else if (value > 700) // sharp tone
  {
    if (total1 > 1000) tone(speaker,139);   // frequency
    if (total2 > 1000) tone(speaker,156);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 1000) tone(speaker,175);
    if (total4 > 1000) tone(speaker,185);
    if (total5 > 1000) tone(speaker,208);
    if (total6 > 1000) tone(speaker,233);
    if (total7 > 1000) tone(speaker,262);
    if (total8 > 1000) tone(speaker,277);
  }
  else // base tone (white keys)
  {
    if (total1 > 1000) tone(speaker,131);   // frequency
    if (total2 > 1000) tone(speaker,147);   // you can see https://www.arduino.cc/en/Tutorial/toneMelody if you want to change frequency
    if (total3 > 1000) tone(speaker,165);
    if (total4 > 1000) tone(speaker,175);
    if (total5 > 1000) tone(speaker,196);
    if (total6 > 1000) tone(speaker,220);
    if (total7 > 1000) tone(speaker,247);
    if (total8 > 1000) tone(speaker,262);
  }
  
  // When hand didn't touch on it, no tone is produced.
  // because of change above change 500 to 1000
  if (total1<=1000  &  total2<=1000  &  total3<=1000 & total4<=1000  &  total5<=1000  &  total6<=1000 &  total7<=1000 &  total8<=1000)
    noTone(speaker);

  delay(10);                             // arbitrary delay to limit data to serial port 
}
