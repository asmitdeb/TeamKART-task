// C++ code
//

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(13, INPUT);
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int button = 0;
int speed = 0;
int val = 0;
int temp = 0;
unsigned int lspeed = 0;
unsigned int rspeed = 0;
unsigned int lturn = 0;
unsigned int rturn = 0;
  
  
  temp = map(analogRead(A3), 20, 358, -40, 125);
  if(temp<=85){
  if (digitalRead(13) == HIGH) {
    button = digitalRead(2);
    if (button == HIGH) {
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    } else {
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    }
  } else {
    if (analogRead(A0) <= 118) {
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
    } else {
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
    }
  }
  if (analogRead(A2) <= 127) {
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
  } else if ((analogRead(A2) > 127)&&(analogRead(A2) < 895)) {
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
  }
	else {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
  }
  val = analogRead(A1);
  if(digitalRead(7) == HIGH){
    digitalWrite(8, HIGH);
    speed = 0;
  }
  else{
    digitalWrite(8, LOW);
    speed = map(val, 0, 1023, 0, 255);
  }
  
  //lturn = analogRead(A2); 
  //rturn = 1023 - lturn;
  //lspeed =(lturn*speed)/1023;
  //rspeed =(rturn*speed)/1023;
  //if(lspeed >=254){
    //lspeed = 254;
  //}
  //if(rspeed >=254){
    //rspeed = 254;
  //}
  analogWrite(6, speed);
  analogWrite(5, speed);
  
  
  //Serial.print("L:");Serial.println(lspeed);
  //Serial.print("R:");Serial.println(rspeed);
  }
  else{
    digitalWrite(9, HIGH);
  }
    
  delay(10); // Delay a little bit to improve simulation performance
}
