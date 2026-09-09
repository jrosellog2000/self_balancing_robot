#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 sensor;

//IMU variables
int16_t ax, ay, az;
int16_t gx, gy, gz;

//Motor driver variables
int PWMA = 11;
int AI1 = 12;
int AI2 = 13;

int PWMB = 6;
int BI1 = 21;
int BI2 = 7; 

int STBY = 38;

char command;
String direction = "";

void setup() {
  //IMU setup
  Serial.begin(115200);
  Wire.begin(8, 9);       
  sensor.initialize();

  if (sensor.testConnection()) Serial.println("Sensor iniciado correctamente");
  else Serial.println("Error al iniciar el sensor");

  //Motor driver setup
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);

  digitalWrite(AI1, LOW);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, LOW);

  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);


}

void loop() {
  sensor.getAcceleration(&ax, &ay, &az);
  sensor.getRotation(&gx, &gy, &gz);

  Serial.print("a[x y z] g[x y z]:\t");
  Serial.print(ax); Serial.print("\t");
  Serial.print(ay); Serial.print("\t");
  Serial.print(az); Serial.print("\t");
  Serial.print(gx); Serial.print("\t");
  Serial.print(gy); Serial.print("\t");
  Serial.println(gz);

  delay(100);
}
