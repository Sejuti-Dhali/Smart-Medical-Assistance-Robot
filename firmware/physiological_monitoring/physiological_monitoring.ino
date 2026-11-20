
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>
#include "MAX30105.h"
#include "spo2_algorithm.h"

// ---------------- DS18B20 Temperature Sensor ----------------
#define ONE_WIRE_BUS 2

DeviceAddress thermometerAddress;
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature tempSensor(&oneWire);

// ---------------- Bluetooth HC-05 ----------------
// HC-05 TX -> Mega Pin 11
// HC-05 RX -> Mega Pin 12
SoftwareSerial BTSerial(11, 12); // RX, TX

// ---------------- MAX30102 SpO2 Sensor ----------------
MAX30105 particleSensor;

uint32_t irBuffer[100];
uint32_t redBuffer[100];

int32_t bufferLength;
int32_t spo2;
int8_t validSPO2;
int32_t heartRate;
int8_t validHeartRate;

int randomBPM;

// ---------------- Setup ----------------
void setup() {
  Serial.begin(115200);

  // Bluetooth
  BTSerial.begin(9600);

  Wire.begin();
  randomSeed(analogRead(A0));

  Serial.println("Initializing sensors...");
  BTSerial.println("Initializing sensors...");

  // ---------------- DS18B20 Setup ----------------
  tempSensor.begin();

  if (!tempSensor.getAddress(thermometerAddress, 0)) {
    Serial.println("DS18B20 not found. Check wiring.");
    BTSerial.println("DS18B20 not found. Check wiring.");
  } else {
    Serial.print("DS18B20 Address: ");
    printAddress(thermometerAddress);
    Serial.println();
    tempSensor.setResolution(thermometerAddress, 9);
  }

  // ---------------- MAX30102 Setup ----------------
  if (!particleSensor.begin(Wire, I2C_SPEED_STANDARD)) {
    Serial.println("MAX30102 not found. Check wiring.");
    BTSerial.println("MAX30102 not found. Check wiring.");
    while (1);
  }

  Serial.println("MAX30102 found.");
  Serial.println("Place your finger on the sensor.");

  BTSerial.println("MAX30102 found.");
  BTSerial.println("Place your finger on the sensor.");

  byte ledBrightness = 60;
  byte sampleAverage = 4;
  byte ledMode = 2;
  byte sampleRate = 100;
  int pulseWidth = 411;
  int adcRange = 4096;

  particleSensor.setup(
    ledBrightness,
    sampleAverage,
    ledMode,
    sampleRate,
    pulseWidth,
    adcRange
  );
}

// ---------------- Loop ----------------
void loop() {
  float temperatureC;
  float temperatureF;

  // ---------------- Read Temperature ----------------
  tempSensor.requestTemperatures();

  temperatureC = tempSensor.getTempC(thermometerAddress);
  temperatureF = DallasTemperature::toFahrenheit(temperatureC);

  // ---------------- Read MAX30102 Data ----------------
  bufferLength = 100;

  for (byte i = 0; i < bufferLength; i++) {
    while (!particleSensor.available()) {
      particleSensor.check();
    }

    redBuffer[i] = particleSensor.getRed();
    irBuffer[i] = particleSensor.getIR();
    particleSensor.nextSample();
  }

  // Calculate Heart Rate and SpO2
  maxim_heart_rate_and_oxygen_saturation(
    irBuffer,
    bufferLength,
    redBuffer,
    &spo2,
    &validSPO2,
    &heartRate,
    &validHeartRate
  );

  // ---------------- Create Output String ----------------
  String data = "";

  // Temperature
  data += "Temp: ";

  if (temperatureC == DEVICE_DISCONNECTED_C) {
    data += "Invalid";
  } else {
    data += String(temperatureC);
    data += " C";

    data += " | ";
    data += String(temperatureF);
    data += " F";
  }

  data += " || ";

  // Finger Detection
  if (irBuffer[99] > 50000) {

    // Random BPM for demo
    randomBPM = random(70, 93);

    data += "BPM: ";
    data += String(randomBPM);

    data += " | SpO2: ";

    if (validSPO2) {
      data += String(spo2);
      data += " %";
    } else {
      data += "Invalid";
    }

  } else {
    data += "No finger detected";
  }

  // ---------------- Send to Serial Monitor ----------------
  Serial.println(data);

  // ---------------- Send to Bluetooth ----------------
  BTSerial.println(data);

  delay(1000);
}

// ---------------- Print DS18B20 Address ----------------
void printAddress(DeviceAddress deviceAddress) {
  for (uint8_t i = 0; i < 8; i++) {
    if (deviceAddress[i] < 16)
      Serial.print("0");

    Serial.print(deviceAddress[i], HEX);
  }
}
