#include <Arduino.h>
// deklarasi pin
#define SINYAL1 7
#define SINYAL2 6
#define SINYAL3 5
#define SETTING_RPM_PIN A0

// input 60rpm sd 15000
int RPM = 60; // kecepatan dalam rpm
float variasiJeda = 1;
float RPMtoDelay(int nilai_rpm)
{
  variasiJeda = nilai_rpm / 60;
  variasiJeda = 1 / variasiJeda;
  variasiJeda *= 1000; // variasiJeda = variasiJeda * 1000;
  variasiJeda /= 4;    // variasiJeda = variasiJeda / 4;
  return variasiJeda;
}
void setup()
{
  // untuk menandakan output
  pinMode(SINYAL1, OUTPUT);
  pinMode(SINYAL2, OUTPUT);
  pinMode(SINYAL3, OUTPUT);
  digitalWrite(SINYAL1, LOW);
  digitalWrite(SINYAL2, LOW);
  digitalWrite(SINYAL3, LOW);

  Serial.begin(115200);
}

void loop()
{
  RPM = analogRead(SETTING_RPM_PIN);
  Serial.println("atur putaran:" + String(RPM) + "RPM, jedanya:" + RPMtoDelay(RPM) + "ms");
  digitalWrite(SINYAL1, HIGH);
  delay(variasiJeda);
  digitalWrite(SINYAL2, HIGH);
  delay(variasiJeda);
  digitalWrite(SINYAL1, LOW);
  digitalWrite(SINYAL3, HIGH);
  delay(variasiJeda);
  digitalWrite(SINYAL2, LOW);
  delay(variasiJeda);
  digitalWrite(SINYAL3, LOW);
}