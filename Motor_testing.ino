// need esp32 by espressif 2.0.17 not 3.0 code breaks due to changes in language 
//use board ESP32 DEV MODULE

#include <Arduino.h>

// Motor A
int motor1Pin1 = 26; 
int motor1Pin2 = 27; 
int enable1Pin = 14; 

// Motor B
int motor2Pin1 = 17; 
int motor2Pin2 = 16; 
int enable2Pin = 5; 

// Setting PWM properties
const int freq = 30000;
const int resolution = 8;
int dutyCycle = 200; // Duty cycle value from 0 to 255

// Define LEDC channels
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;

void setup() {
  // Set the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  // Configure LEDC PWM channels
  ledcSetup(pwmChannel1, freq, resolution);
  ledcAttachPin(enable1Pin, pwmChannel1);

  ledcSetup(pwmChannel2, freq, resolution);
  ledcAttachPin(enable2Pin, pwmChannel2);
  
  Serial.begin(115200);
  Serial.println("Testing DC Motor...");
}

void loop() {
  // Move the DC motors forward at the set speed
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);

  // Set the duty cycle to a constant value
  ledcWrite(pwmChannel1, dutyCycle); 
  ledcWrite(pwmChannel2, dutyCycle);     
  
  Serial.print("Motors running at duty cycle: ");
  Serial.println(dutyCycle);

  delay(10000); // Delay for 10 second
}

