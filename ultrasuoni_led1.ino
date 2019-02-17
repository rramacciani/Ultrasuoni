#define trigPin 11
#define echoPin 12

#define LED 13

#define LED1 9
#define LED2 8
#define LED3 7
#define LED4 6
#define LED5 5


void setup()
{
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(LED, OUTPUT);
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop()
{
  float duration, distance;
  
  //Check spento
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  
  //Lancio i segnali
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Leggo i segnali
  duration = pulseIn(echoPin, HIGH);
  
  //Calcolo la distanza partendo dalla durata
  distance = (duration / 2) * 0.0344;

  digitalWrite(LED, HIGH);
  if (distance >= 400 || distance <= 2){
    lightLeds(9999);
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println("Out of range");
  } else {
    lightLeds(distance);
    
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  
  digitalWrite(LED, LOW);
}


void lightLeds(float distance){
  if(distance <= 4){
    //Distanza bassa = pieno d'acqua
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }else if(distance > 4 && distance <= 6){
    //Aumenta la distanza = un po' meno acqua
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }else if(distance > 6 && distance <= 8){
    //Aumenta la distanza = un po' meno acqua
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }else if(distance > 8 && distance <= 10){
    //Aumenta la distanza = un po' meno acqua
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }else if(distance > 10 && distance <= 12){
    //Aumenta la distanza = un po' meno acqua
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
  }else{
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
}
