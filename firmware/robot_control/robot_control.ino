
#include <SoftwareSerial.h> // Bluetooth module (HC-05)

// Bluetooth setup
SoftwareSerial BT(11, 12); // RX, TX

// Motor Driver Pins
#define ENA 6
#define ENB 5
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10

// Global variables
int speedVal = 150;
char command;

// -------------------- Setup --------------------
void setup() {
  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Bluetooth initialization
  BT.begin(9600);

  // Initial speed
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
}

// -------------------- Movement Functions --------------------
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void back() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// -------------------- Main Loop --------------------
void loop() {
  if (BT.available()) {
    command = BT.read();

    switch (command) {
      case 'F': forward(); break;
      case 'B': back(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopMotor(); break;

      // Speed control
      case '0': speedVal = 100; break;
      case '1': speedVal = 150; break;
      case '2': speedVal = 200; break;
      case '3': speedVal = 255; break;
    }

    // Apply speed setting
    analogWrite(ENA, speedVal);
    analogWrite(ENB, speedVal);
  }
}
