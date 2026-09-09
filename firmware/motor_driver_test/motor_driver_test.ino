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
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AI1, OUTPUT);
  pinMode(AI2, OUTPUT);
  pinMode(BI1, OUTPUT);
  pinMode(BI2, OUTPUT);
  pinMode(STBY, OUTPUT);

  digitalWrite(AI1, LOW);
  digitalWrite(AI2, LOW);
  digitalWrite(BI1, LOW);
  digitalWrite(BI2, LOW);
  digitalWrite(STBY, HIGH);

  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0)
  {
    command = Serial.read();
  }

  if (((direction == "forward") && (command == 'R')) || (direction == "reverse") && (command == 'F'))
  {
    digitalWrite(AI1, LOW);
    digitalWrite(AI2, LOW);
    digitalWrite(BI1, LOW);
    digitalWrite(BI2, LOW);
    delay(500);
  }

  if (command == 'F')
  {
    Serial.println("Forward");
    digitalWrite(AI1, LOW);
    digitalWrite(AI2, HIGH);
    digitalWrite(BI1, HIGH);
    digitalWrite(BI2, LOW);
    direction = "forward";
    command = '0';
  }

  if (command == 'R')
  {
    Serial.println("Reverse");
    digitalWrite(AI1, HIGH);
    digitalWrite(AI2, LOW);
    digitalWrite(BI1, LOW);
    digitalWrite(BI2, HIGH);
    direction = "reverse";
    command = '0';
  }

  if (command == 'S')
  {
    Serial.println("Stop");
    digitalWrite(AI1, LOW);
    digitalWrite(AI2, LOW);
    digitalWrite(BI1, LOW);
    digitalWrite(BI2, LOW);
    command = '0';
  }

  if (command == 'L')
  {
    Serial.println("LOW");
    analogWrite(PWMA, 180);
    analogWrite(PWMB, 180);
    command = '0';
  }

  if (command == 'M')
  {
    Serial.println("MEDIUM");
    analogWrite(PWMA, 215);
    analogWrite(PWMB, 215);
    command = '0';
  }

  if (command == 'H')
  {
    Serial.println("HIGH");
    analogWrite(PWMA, 255);
    analogWrite(PWMB, 255);
    command = '0';
  }


}





















