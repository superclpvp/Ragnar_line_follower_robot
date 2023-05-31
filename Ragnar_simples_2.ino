//BIBLIOTECAS
#include <AFMotor.h>

//VARIAVEIS EDITAVEIS
int preto_D = 270; // valor de corte do sensor da direita
int preto_E = 210; // valor de corte do sensor da esquerda
int tempo_curva = 180; // tempo de rotacionar do robo na curva
int velocidade_frente = 100; // velocidade do robo quando esta indo para frente
int velocidade_curva = 250; // velocidade do robo quando esta virando

//VARIAVEIS NÃO EDITAVEIS
int sensor_D = 0;
int sensor_E = 0;
int velocidade_variavel = 0; 

//OBJETOS
AF_DCMotor motorD(2);
AF_DCMotor motorE(1);

//SETUP
void setup() {
  pinMode(A1,INPUT);
  pinMode(A3,INPUT);
  
  Serial.begin(9600);          
  
  motorD.run(RELEASE);
  motorE.run(RELEASE);
}

//LOOP
void loop() {
  //ler sensores
  sensor_D = analogRead(A1);
  sensor_E = analogRead(A3);
  
  motorD.setSpeed(velocidade_variavel);  
  motorE.setSpeed(velocidade_variavel);  


  Serial.print(sensor_D);
  Serial.print("\t");
  Serial.println(sensor_E);

// frente
  if(sensor_E < preto_E && sensor_D < preto_D){
    velocidade_variavel = velocidade_frente;
    motorD.setSpeed(velocidade_variavel);  
    motorE.setSpeed(velocidade_variavel);  
    motorE.run(FORWARD);
    motorD.run(FORWARD);
    //delay(15);
        
  }
//direita  
  else if(sensor_D > preto_D && sensor_E < preto_E){
    velocidade_variavel = velocidade_curva;
    motorD.setSpeed(velocidade_variavel);  
    motorE.setSpeed(velocidade_variavel);  
    motorE.run(FORWARD);
    motorD.run(BACKWARD);
    delay(tempo_curva);
  }
//esquerda
  else if(sensor_D < preto_D && sensor_E > preto_E){
    velocidade_variavel = velocidade_curva;
    motorD.setSpeed(velocidade_variavel);  
    motorE.setSpeed(velocidade_variavel);  
    motorE.run(BACKWARD);
    motorD.run(FORWARD);
    delay(tempo_curva);
  }
//cruzamento
  else if(sensor_E > preto_E && sensor_D > preto_D){
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
