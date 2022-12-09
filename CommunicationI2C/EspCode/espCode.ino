#include <Wire.h>
//_____DATA STORAGE_____________________________________________
String myString="" ;
String val1;
String val2;
String val3;
String val4;

void setup() {
 Serial.begin(115200);
 //_____JOIN I2C BUS WITH SDA=D1 AND SCL=D2_______________________
 Wire.begin(D1, D2); 
}

void loop() {
 //_____SEND DATA TO DEVICE ADDRESS 8___________________________
 Wire.beginTransmission(8); 
 Wire.write("Hello Arduino");  
 Wire.endTransmission();    

 delay(1000);
 //_____RECEIVE DATA FROM DEVICE ADDRESS 8___________________________
 Wire.requestFrom(8, 26); 
 myString="" ;
 while(Wire.available()){
   char c = Wire.read();
   myString +=c;
 }
 Serial.println(myString);
 myDecomposition(myString);
  
 Serial.print("A=");
 Serial.println(val1);
 Serial.print("B=");
 Serial.println(val2);
 Serial.print("C=");
 Serial.println(val3);
 Serial.print("D=");
 Serial.println(val4);
 /*float a;
 a= val1.toFloat();
 Serial.println(a*3); */
  
 delay(10000);
}

void myDecomposition(String str){
    int pos1 = str.indexOf("A");
    int pos2 = str.indexOf("B");
    int pos3 = str.indexOf("C");
    int pos4 = str.indexOf("D");
    int pos5 = str.indexOf("E");
    
    val1 = str.substring(pos1+1,pos2);
    val2 = str.substring(pos2+1,pos3);
    val3 = str.substring(pos3+1,pos4);
    val4 = str.substring(pos4+1,pos5);
}