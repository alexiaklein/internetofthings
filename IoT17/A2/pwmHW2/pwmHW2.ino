//define LEDs
int led1 = D5;
int led2 = D6;
int led3 = D7;
int led4 = D8;
//define potentiometer
int potPin = A0;  

//define variables
float val = 0;  

//mapping function
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

//LED function
int ledPower(int x){

  if(x == 0){
    analogWrite(led1, LOW);
    analogWrite(led2, LOW); 
    analogWrite(led3, LOW);
    analogWrite(led4, LOW); 
    }
  else if(x < 25){
    analogWrite(led1, HIGH);
    analogWrite(led2, LOW); 
    analogWrite(led3, LOW);
    analogWrite(led4, LOW); 
  }
  else if(x < 50){
    analogWrite(led1, HIGH);
    analogWrite(led2, HIGH); 
    analogWrite(led3, LOW);
    analogWrite(led4, LOW);
    }
   else if(x < 75){
    analogWrite(led1, HIGH);
    analogWrite(led2, HIGH); 
    analogWrite(led3, HIGH);
    analogWrite(led4, LOW); 
    } 
    else if (x < 100){
    analogWrite(led1, HIGH);
    analogWrite(led2, HIGH); 
    analogWrite(led3, HIGH);
    analogWrite(led4, HIGH); 
      }
}



void setup() {
  Serial.begin(115200);
  //define outputs
  pinMode(potPin, INPUT);
  //define inputs 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {

  //read sensor
  val = analogRead(potPin); 
  //map values  
  float valMapped = mapFloat(val, 0, 1023, 0, 99.99);
  Serial.println(valMapped);  

  //light LEDs
  ledPower(valMapped);

}
