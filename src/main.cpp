// Sensor reader module: 
// Irene Abad Londoño & Alejandro Hoyos Correa

#include <Arduino.h>
#include <Sensors/Sensor.h>
#include <llp.h>

Sensor A_Sensor = Sensor(0xA0, A0);

void setup() {
  Serial.begin(9600);
  pinMode(A_Sensor.getPin(), INPUT);
}

void loop() {
 
  A_Sensor.execute();

  if (A_Sensor.hasChanged()){
    uint16_t value = A_Sensor.getValue();
    value = 856;

    DataPack output = DataPack();

    output.addData(A_Sensor.getId(), value);
    output.write(Serial);

    /*Serial.print("Valor Sensor: ");
    Serial.println(value);*/
  }
}