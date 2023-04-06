#include <Arduino.h>

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#define l1 8
#define l2 9
#define l3 3
#define l4 4
#define pwm 23
/*
BluetoothSerial SerialBle;

void setup() {
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
  pinMode(pwm,OUTPUT);
  Serial.begin(115200);
  SerialBle.begin("ESP33BLE"); //Bluetooth device name
  
}

void loop() {
  

  if(Serial.available())
  {

  
  if (SerialBle.available()) {
    int input=SerialBle.read();
    int pwmvalue=SerialBle.read();


    switch (input)
    {
    case 1:
        digitalWrite(l1,HIGH);
        digitalWrite(l2,HIGH);
        digitalWrite(l3,HIGH);
        digitalWrite(l4,HIGH);
        analogWrite(pwm,pwmvalue);
    
      break;
    case 2:
      digitalWrite(l1,LOW);
        digitalWrite(l2,LOW);
        digitalWrite(l3,LOW);
        digitalWrite(l4,LOW);
        analogWrite(pwm,pwmvalue);

      break;

      case 3:
      digitalWrite(l1,HIGH);
        digitalWrite(l2,LOW);
        analogWrite(pwm,pwmvalue);
        break;

        case 4:
        digitalWrite(l1,LOW);
        digitalWrite(l2,HIGH);
        analogWrite(pwm,pwmvalue);



       

    
      break;
    }
  }
  }
  
  
}*/

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(l3,OUTPUT);
  pinMode(l4,OUTPUT);
  pinMode(pwm,OUTPUT);
 
  Serial.begin(115200);
  SerialBT.begin("ESP32123"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()>0) {
    int input=Serial.read();
    int pwmvalue=Serial.read();
    SerialBT.write(Serial.read());
  

  switch (input)
    {
    case 1:
        digitalWrite(l1,HIGH);
        digitalWrite(l2,HIGH);
        digitalWrite(l3,HIGH);
        digitalWrite(l4,HIGH);
        analogWrite(pwm,pwmvalue);
    
      break;
    case 2:
      digitalWrite(l1,LOW);
        digitalWrite(l2,LOW);
        digitalWrite(l3,LOW);
        digitalWrite(l4,LOW);
        analogWrite(pwm,pwmvalue);

      break;

      case 3:
      digitalWrite(l1,HIGH);
        digitalWrite(l2,LOW);
        analogWrite(pwm,pwmvalue);
        break;

        case 4:
        digitalWrite(l1,LOW);
        digitalWrite(l2,HIGH);
        analogWrite(pwm,pwmvalue);



       

    
      break;
    }
  
  }
  delay(20);
}
  
