#define trigPin1 3 // Door 2 Sensor (RIGHT)
#define echoPin1 2  // Door 2 Sensor (RIGHT)
#define trigPin2 4 // Door 1 Sensor (LEFT)
#define echoPin2 5 // Door 1 Sensor (LEFT)
int Door1=8;
int Door2=9;
int UV=10;

long duration, distance, RightSensor,LeftSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(Door1, OUTPUT);
pinMode(Door2, OUTPUT);
pinMode(UV, OUTPUT);
}

void loop() 
{
SonarSensor(trigPin1, echoPin1);
RightSensor = distance;
SonarSensor(trigPin2, echoPin2);
LeftSensor = distance;

Serial.print(LeftSensor);
Serial.print(" - ");

Serial.println(RightSensor);

digitalWrite(Door1,HIGH);
digitalWrite(Door2,HIGH);
digitalWrite(UV,HIGH);

if(((LeftSensor<10)&&(RightSensor>10))||((LeftSensor>10)&&(RightSensor<10)))
{
if (LeftSensor<10)
{
  digitalWrite(Door1,LOW); //Door1 open
  digitalWrite(UV,LOW);   // UV Off
  delay(2000);
  digitalWrite(Door1,HIGH);
  digitalWrite(Door2,HIGH);
  digitalWrite(UV,HIGH);
  delay(10000);
}

if(RightSensor<10)
{
  
  digitalWrite(Door2,LOW);
  digitalWrite(UV,LOW);
  delay(2000);             //4time door will be opened for: 2 sec
  digitalWrite(Door1,HIGH);
  digitalWrite(Door2,HIGH);
  digitalWrite(UV,HIGH);
  delay(10000);             //time uv light on for: 10 sec
}
}
else
{
  digitalWrite(Door1,HIGH);
  digitalWrite(Door2,HIGH);
  digitalWrite(UV,HIGH);
}
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
