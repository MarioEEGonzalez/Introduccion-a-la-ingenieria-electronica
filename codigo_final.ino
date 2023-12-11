//rueda izquierda
#include "Servo.h";

Servo  servomotor_cargue;

Servo servomotor_descargue;

int IN1= 9;
int IN2= 8;
int EnableDer =3; 
//rueda derecha
int IN3 = 4;
int IN4 = 2;
int EnableIzq = 5;
// sensor de luz
int luz;
int lectura_descargue = 700;
int lectura_cargue=200;
//sensor de proximidad
//const int trigPin = 15;
//const int echoPin = 13;

//seguidor de linea
const int izquierda =11;
const int centro =12;
const int derecha =13;
// SERVOS
int speed_right = 230;
int cont = 0;

void front(int speed){
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EnableIzq,speed);
  analogWrite(EnableDer,speed);
 
  
  

}
void back(int time){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(time);
}
void stop(){
 
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
    
  
}
void turnRight(int speed){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EnableIzq,50);
  analogWrite(EnableDer,speed);
  
  

}
void turnLeft(int speed){
  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  analogWrite(EnableIzq,speed);
  analogWrite(EnableDer,90);
  

}
void turn_90_der(){
  stop();
  turnRight(200);
  delay(960);
}
void turn_90_izq(){
  stop();
  turnLeft(200);
  delay(960);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(A0,INPUT);
//servo
  servomotor_cargue.attach(A1);
  servomotor_descargue.attach(A2);

 // pinMode(trigPin,OUTPUT);
  //pinMode(echoPin,INPUT);
  pinMode(izquierda,INPUT);
  pinMode(centro,INPUT);
  pinMode(derecha,INPUT);
  pinMode(EnableIzq,OUTPUT);
  pinMode(EnableDer,OUTPUT);
  Serial.begin(9600);

  
  

  //pinMode(ENA,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  

// lectura sensor de luz  
    

luz= analogRead(A0);
  
  
//servomotor_descargue.attach(0);
//servomotor_cargue.attach(100);
 
 
//PARTE SEGUIDOR DE LINEA
int read_left = digitalRead(izquierda);
int read_right = digitalRead(derecha);
int read_center = digitalRead(centro);
int speed = 240;


servomotor_cargue.write(105);
servomotor_descargue.write(0);




  if((read_left== LOW) && (read_center == HIGH) && (read_right== HIGH)){
    turnLeft(speed);
    Serial.println("izquierda");
    
  }    
  if((read_left== HIGH) && (read_center == LOW) && (read_right== HIGH)){
    front(speed);
    Serial.println("front");
  }
  
  if((read_left== HIGH) && (read_center ==HIGH) && (read_right== LOW)){
    turnRight(speed);
    Serial.println("derecha");
    

  }   
  /*
  if((read_left== HIGH) && (read_center ==HIGH) && (read_right== HIGH)){
    front(speed);
    Serial.println(luz);
  } 
  */

  if((read_left== LOW) && (read_center == LOW) && (read_right== LOW)){
    stop();
    Serial.println(luz);
    
    /*
    if (luz < lectura_descargue && luz>lectura_cargue){
      servomotor_cargue.write(140);
      Serial.println(luz);
      delay(2500);
    }
    else if (luz > lectura_cargue && luz <lectura_descargue){
      servomotor_descargue.write(90);
      Serial.println(luz);
      delay(2500);
    }
    if(cont==1){
        turn_90_der();
      }
    else if(cont==3){
        turn_90_izq();
    }
      
    cont++;        
    Serial.println("stop");
    */      
  }
  
 





}
