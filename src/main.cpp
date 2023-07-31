#include <Arduino.h>
#include <SoftwareSerial.h>


SoftwareSerial HC12(D3, D4);

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);

  pinMode(D8, INPUT);

  Serial.printf("Hello world ESP8266\n");
}

void loop() {
  delay(500);
  // HC12.print("qqcoisa");

  if(Serial.available()) {
    Serial.printf("Dados na serial do PC\n"); 
    HC12.print(Serial.readString());
  }
  
  if(HC12.available()) {
    Serial.printf("Dados na serial do HC12\n");
    Serial.print(HC12.readString());
  }

  if(digitalRead(D8)) {
    Serial.printf("Botão clicado\n");
    HC12.print("k");
    delay(500);
  }
}
