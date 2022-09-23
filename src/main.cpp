//I, Noe Puna, 000781646, I acknowledge that this my own work and no other
// person's work has been copied without acknowledgement.
#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:

  // configure the USB serial monitor 
  Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:

  int iVal; 
  double val;
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  val = map(iVal, 0, 1023, 0, 5000);
  analogWrite(9, val);
  val = val/100;
  String judgement;
 
  if (iVal < 10){
    judgement = ", which is Too Cold!";
  }else if(iVal > 9 && iVal < 16){
    judgement = ", which is Cool!";
  }else if(iVal > 14 && iVal < 26){
    judgement = ", which is Perfect!";
  }else if(iVal > 24 && iVal < 31){
    judgement = ", which is Warm!";
  }else if(iVal > 29 && iVal < 36){
    judgement = ", which is Hot!";
  }else if(iVal > 35){
    judgement = ", which is Too Hot!";
  }
  
  // print value to the USB port 
  Serial.println("Digitized Value = " + String(iVal) + " is equivalent to an Analog Voltage = " + val + " V" + judgement); 
  
 
  // wait 2 seconds (2000 ms) 
  delay(500);
}