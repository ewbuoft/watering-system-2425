/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.


*/

#include <DHT.h>

#define DHT1Pin 9 // pin number 1
#define DHT2Pin 11 // pin number 2

#define DHTTYPE DHT22
DHT dht1(DHT1Pin, DHTTYPE);
DHT dht2(DHT2Pin, DHTTYPE);
void setup() {
  Serial.begin(9600);
  pinMode(DHT1Pin, INPUT);
  pinMode(DHT2Pin, INPUT);
  dht1.begin();
  dht2.begin();
}
void loop() {
  float t1 = dht1.readTemperature(); // temp dht1
  float h1 = dht1.readHumidity(); // humidity dht1
  float t2 = dht2.readTemperature(); // temp dht2
  float h2 = dht2.readHumidity(); // humidity dht2
  
  // Printing the results on the serial monitor
  float t=(t1+t2)/2;
  float h=(h1+h2)/2;
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print("    Humidity = ");
  Serial.print(h);
  Serial.println(" % ");
  
  delay(2000); // Delays 2 secods, as the DHT22 sampling rate is 0.5Hz
}
