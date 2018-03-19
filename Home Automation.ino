#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRsend.h>
#include <IRremoteESP8266.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define firebaseURI "homeautomation-2dffc.firebaseio.com"
#define authCode "bR87efxHOaPVTG5GbV7eoBkkuzl9qYgnzz9DztAE"

#define wifiName "BELL4G-E439"
#define wifiPass "ahkam123"
IRsend irsend(4);

String chipId="123";
int led1=D0;

void firebaseSetup(){
  Firebase.begin(firebaseURI,authCode);
}


void wifiSetup(){

  WiFi.begin(wifiName,wifiPass);
  Serial.println("Im connecting");
  while(WiFi.status()!= WL_CONNECTED){
    Serial.println(".");
    delay(500);
  }
  Serial.println();
  Serial.println("I am connected and my ip address is:");
  Serial.println(WiFi.localIP());
}
void setup() {
  irsend.begin();
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
  pinMode(led1,OUTPUT);
  
  wifiSetup();
  firebaseSetup();
}

void getDate(){
  String path=chipId+"/states";
  
  FirebaseObject object= Firebase.get(path);
  bool ld1=object.getBool("001");
  bool ld2=object.getBool("002");
  bool ld3=object.getBool("003");
  bool ld4=object.getBool("004");
  bool ld5=object.getBool("005");
  bool ld6=object.getBool("006");
  bool ld7=object.getBool("007");
  bool ld8=object.getBool("008");
  bool ld9=object.getBool("009");
  bool ld10=object.getBool("010");
  digitalWrite(led1,ld1);
  if(ld2==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0x10, 12, 2); 
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld3==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0x810, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld4==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0x410, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld5==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0xC10, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld6==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0x210, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld7==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0x83E0B54, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld8==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0x610, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld9==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0xCB182DD8, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  if(ld10==true){
    #if SEND_SONY
      Serial.println("Sony");
      irsend.sendSony(0xCDF59634, 12, 2);
    #endif  // SEND_SONY
      delay(1100);
  }
  
}
void loop() {
  getDate();
}
