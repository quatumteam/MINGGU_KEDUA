int pinLED1 =10;
int pinLED2 =11;
int pinLED3 =12;
int pinLED4 =13;
// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 6;
const int echoPin = 5;
// Variables for the duration and the distance
long duration;
int distance;
Servo myServo; // Creates a servo object for controlling the servo motor
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(pinLED1,OUTPUT);
  pinMode(pinLED2,OUTPUT);
  pinMode(pinLED3,OUTPUT);
  pinMode(pinLED4,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // rotates the servo motor from 15 to 165 degrees
 
    distance = calculateDistance();
    // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    Serial.print("Distance:"); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.println(distance); // Sends the distance value into the Serial Port
    Serial.print("."); // Sends addition character right next to the previous value needed later in the Processing IDE for indexing    if (distance<=2)
    delay(100);
    if (distance<5)
    {
      digitalWrite(pinLED1,HIGH);
      digitalWrite(pinLED2,HIGH);
      digitalWrite(pinLED3,HIGH);
      digitalWrite(pinLED4,HIGH);
    }
    else if (distance>=5 && distance <10)
    {
      digitalWrite(pinLED1,HIGH);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,HIGH);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,HIGH);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,HIGH);
    }
        else if (distance>=10 && distance <15)
    {
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,HIGH);
      delay(100);
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,HIGH);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,HIGH);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,HIGH);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
    }
     else if (distance>=15 && distance <20)
    {
      digitalWrite(pinLED1,HIGH);
      digitalWrite(pinLED2,HIGH);
      digitalWrite(pinLED3,HIGH);
      digitalWrite(pinLED4,HIGH);
      delay(1000);
      digitalWrite(pinLED1,HIGH);
      digitalWrite(pinLED2,HIGH);
      digitalWrite(pinLED3,HIGH);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,HIGH);
      digitalWrite(pinLED2,HIGH);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,HIGH);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
      delay(100);
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
      delay(100);
    }
  else  
     {
      digitalWrite(pinLED1,LOW);
      digitalWrite(pinLED2,LOW);
      digitalWrite(pinLED3,LOW);
      digitalWrite(pinLED4,LOW);
      delay(1000);
 
      }
   

 }
  
// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
