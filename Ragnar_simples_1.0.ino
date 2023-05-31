//BIBLIOTECAS
#include <AFMotor.h>
int preto = 250;
//int branco = 80;

//Variaveis
AF_DCMotor motorD(2);
AF_DCMotor motorE(1);

int sensor_D = 0;
int sensor_E = 0;

int velocidade = 0;

//setup
void setup() {
  pinMode(A1,INPUT);
  pinMode(A3,INPUT);
  
  Serial.begin(9600);          
  
  motorD.run(RELEASE);
  motorE.run(RELEASE);
}

//loop
void loop() {
  //ler sensores
  sensor_D = analogRead(A1);
  sensor_E = analogRead(A3);
  
  motorD.setSpeed(velocidade);  
  motorE.setSpeed(velocidade);  


  Serial.print(sensor_D);
  Serial.print("\t");
  Serial.println(sensor_E);

// frente
  if(sensor_E < preto && sensor_D < preto){
    velocidade = 110;
    motorD.setSpeed(velocidade);  
    motorE.setSpeed(velocidade);  
    motorE.run(FORWARD);
    motorD.run(FORWARD);
    delay(15);
        
  }
//direita  
  else if(sensor_D > preto && sensor_E < preto){
    velocidade = 200;
    motorD.setSpeed(velocidade);  
    motorE.setSpeed(velocidade);  
    motorE.run(FORWARD);
    motorD.run(BACKWARD);
    delay(300);
  }
//esquerda
  else if(sensor_D < preto && sensor_E > preto){
    velocidade = 200;
    motorD.setSpeed(velocidade);  
    motorE.setSpeed(velocidade);  
    motorE.run(BACKWARD);
    motorD.run(FORWARD);
    delay(300);
  }
//cruzamento
  else if(sensor_E > preto && sensor_D > preto){
    motorD.run(RELEASE);
    motorE.run(RELEASE);
    delay(500);                
  }
/*
  //MOTOR E
  if(sensor_E < 100)
  {
    motorE.run(FORWARD);
    delay(preto);
  }
  else if(sensor_E > 100)
  {
    motorE.run(BACKWARD);
    delay(preto0);
  }
  //MOTOR D
  if(sensor_D < 100)
  {
    motorD.run(FORWARD);
    delay(preto);
  }
  else if(sensor_D > 100)
  {
    motorD.run(BACKWARD);
    delay(preto0);
  }
*/
}
