# Methodology

## 1. System Overview

The prototype combines a four-wheel Bluetooth-controlled
robotic platform with an Arduino-based physiological
monitoring subsystem.

The two subsystems are documented separately because
their original firmware uses different microcontrollers.

## 2. Mechanical and Electrical Assembly

The robotic platform uses:
- Four DC gear motors
- A four-wheel chassis
- An Arduino UNO R3
- An L298N motor driver
- Rechargeable batteries
- An HC-05 Bluetooth module

The motor driver receives digital direction commands
and PWM speed settings from the Arduino UNO.

## 3. Bluetooth-Based Movement

The Arduino UNO receives serial commands through
the HC-05 Bluetooth module.

The firmware implements:
- Forward movement
- Backward movement
- Left rotation
- Right rotation
- Stop
- Four predefined PWM speed settings

## 4. Physiological Monitoring

An Arduino Mega 2560 interfaces with:
- MAX30102 optical sensor
- DS18B20 digital temperature sensor

The MAX30102 supplies optical samples used by the
SpO2 estimation algorithm.

The DS18B20 provides temperature measurements.

The original firmware also calculates a heart-rate
estimate internally; however, its displayed BPM field
uses randomly generated demonstration values.

## 5. Communication

The monitoring firmware sends formatted output
through serial and Bluetooth communication.

## 6. Demonstration and Evaluation

The original report documents:
- An assembled robotic prototype
- Bluetooth-based movement
- Physiological monitoring output

The available report does not provide systematic
clinical accuracy, communication latency, or
navigation reliability benchmarks.

## 7. Reproducibility

The original Arduino source is preserved separately
for the mobility and monitoring subsystems.

The code and hardware connections require independent
compilation and physical verification.

## Source

Original project report, Chapters 3-6 and Appendix.
