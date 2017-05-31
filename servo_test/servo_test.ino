#include <Servo.h>
#define SERVO1_INIT 70
#define SERVO2_INIT 70

Servo servoGrande;
Servo servoChico;

int pos1 = 0;
int pos2 = 0;
int pos = 0;

String cmd = "";
String angulo_str;
char select;
char angulo_chr;
int digito1;
int digito2;

int angulo;

void setup()
{
  servoGrande.attach(9);
  servoChico.attach(10);
  servoGrande.write(SERVO1_INIT);
  servoChico.write(SERVO1_INIT); 
  Serial.begin(115200);
}

void loop()
{

  if(Serial.available() >= 1)
  {
    //pos = Serial.parseInt(); //Leer un entero por serial
    cmd = Serial.readString();
    Serial.print("cmd: "); Serial.println(cmd);
    select = cmd[0]-'0';
    angulo_str = cmd.substring(2, 4);
    Serial.print("angulo_str: "); Serial.println(angulo_str);
    digito1 = angulo_str[0]-'0';
    digito2 = angulo_str[1]-'0';
    angulo = digito1*10+digito2;
    Serial.print("angulo: "); Serial.println(angulo);
    if (select == 1) servoGrande.write(angulo);
    else if (select == 2) servoChico.write(angulo);
  }
}
