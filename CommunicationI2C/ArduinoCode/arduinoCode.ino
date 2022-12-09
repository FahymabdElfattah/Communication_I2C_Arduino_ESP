#include <Wire.h>
#include <stdio.h>

String key[4]={"A","B","C","D"};
String valueSend[4]={"-","-","-","-"};

String valueReceive[4]={"-","-","-","-"};

String myString="" ;
String sendVar = "";

String messg1;
String messg2;
String messg3;

void setup() {
 //_________join i2c bus with address 8___________________
 Wire.begin(8);
 //_________register receive event # register request event               
 Wire.onReceive(receiveEvent); 
 Wire.onRequest(requestEvent);
 //________start serial for debug________________________ 
 Serial.begin(115200);          
}
void loop() {
  for(int i=0 ; i<4; i++){
    float h = random(0,100);
    valueSend[i]= String(h) ;
  }
  myDecomposition(myString);
  if (messg1.length()>1){
    valueReceive[0] = messg1;
  }else if(messg2.length()>1){
    valueReceive[1] = messg2;
  }else if(messg3.length()>1){
    valueReceive[2] = messg3;
  }
  Serial.print("messag1= ");
  Serial.println(valueReceive[0]);
  Serial.print("messag2= ");
  Serial.println(valueReceive[1]);
  Serial.print("messag3= ");
  Serial.println(valueReceive[2]);
  delay(100);
}

//____function that executes whenever data is received from master
void receiveEvent(int howMany) {
 myString="" ;
 while (0 <Wire.available()) {
    char c = Wire.read();      
    myString +=c;
  }  
  //Serial.println(myString);           
}

//___function that executes whenever data is requested from master
void requestEvent() {
  for (int i = 0; i <4; i++) {
    sendVar = key[i];
    Wire.print(sendVar);
    sendVar = valueSend[i];
    Wire.print(sendVar);
  }
  sendVar ="E";
  Wire.print(sendVar);
}

void myDecomposition(String str){
    int pos1 = str.indexOf("/");
    int pos2 = str.indexOf("*");
    int pos3 = str.indexOf("+");
    int pos4 = str.indexOf("#");
    
    messg1 = str.substring(pos1+1,pos2);
    messg2 = str.substring(pos2+1,pos3);
    messg3 = str.substring(pos3+1,pos4);
}