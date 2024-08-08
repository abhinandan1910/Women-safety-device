#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <TinyGPS++.h>

// Pins
const int buzzerPin = 8;
const int lightSensorPin = A0;

// Thresholds
const int lightThreshold = 200;  // Adjust as per your environment
const float accelerationThreshold = 1.5;  // Change based on sensitivity

// GPS and GSM
SoftwareSerial gpsSerial(3, 4); // RX, TX
SoftwareSerial gsmSerial(5, 6); // RX, TX
TinyGPSPlus gps;

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  gsmSerial.begin(9600);
  
  pinMode(buzzerPin, OUTPUT);
  
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Found!");
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  // Initialize the GSM module (SIM900, etc.)
  gsmSerial.println("AT");
  delay(100);
}

void loop() {
  // Read accelerometer
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  float acceleration = sqrt(a.acceleration.x * a.acceleration.x + a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z);
  
  // Read light sensor
  int lightLevel = analogRead(lightSensorPin);

  // GPS data
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  if (acceleration > accelerationThreshold) {
    triggerAlert("Fall detected!");
  }

  if (lightLevel < lightThreshold) {
    triggerAlert("Low light detected!");
  }

  delay(1000);
}

void triggerAlert(String alertMessage) {
  // Activate buzzer
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);

  // Send alert via GSM
  if (gps.location.isValid()) {
    String message = alertMessage + " Location: http://maps.google.com/?q=" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
    sendSMS(message);
  } else {
    sendSMS(alertMessage + " Location not available.");
  }
}

void sendSMS(String message) {
  gsmSerial.println("AT+CMGF=1");  // Set SMS mode to text
  delay(100);
  gsmSerial.println("AT+CMGS=\"+1234567890\"");  // Replace with your phone number
  delay(100);
  gsmSerial.println(message);
  delay(100);
  gsmSerial.write(26);  // ASCII code of CTRL+Z to send SMS
  delay(1000);
}
