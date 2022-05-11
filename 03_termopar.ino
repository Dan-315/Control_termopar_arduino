#include "max6675.h"

int ktcSO = 8;
int ktcCS = 9;
int ktcCLK = 10;
int led = 6;

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("C° = ");
  Serial.print(ktc.readCelsius());
  if(ktc.readCelsius()>35){
    digitalWrite(led,HIGH);
    Serial.println(" - Led encendido");
  }else{
    digitalWrite(led,LOW);
    Serial.println(" - Led apagado");
  }

  delay(500);
}
