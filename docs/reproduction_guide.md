# Reproduction Guide

## Scope

This guide describes the Arduino-based robotics and
physiological monitoring subsystems.

Successful hardware reproduction has not yet been
independently verified.

## Required Hardware

- Arduino UNO R3
- Arduino Mega 2560 R3
- L298N motor driver
- Four DC gear motors and chassis
- HC-05 Bluetooth module
- MAX30102 sensor
- DS18B20 sensor
- Suitable power supply and wiring

## Software

- Arduino IDE
- Arduino AVR board support
- SoftwareSerial
- Wire
- OneWire
- DallasTemperature
- SparkFun MAX3010x sensor library
- Compatible SpO2 algorithm implementation

The exact dependency versions used in the original
project are not documented.

## Robot Control

1. Review hardware/pin_connections.md.
2. Verify motor-driver connections and power ratings.
3. Open firmware/robot_control/robot_control.ino.
4. Select Arduino UNO in Arduino IDE.
5. Compile the sketch.
6. Upload to the correct board and serial port.
7. Pair the Bluetooth controller with the HC-05.
8. Test each movement command safely.

## Physiological Monitoring

1. Verify the MAX30102 voltage and I2C connections.
2. Resolve the DS18B20 D7-versus-D2 discrepancy.
3. Install the required Arduino libraries.
4. Open the physiological_monitoring.ino sketch.
5. Select Arduino Mega 2560.
6. Compile and upload the sketch.
7. Inspect serial output.
8. Verify sensor detection and temperature readings.
9. Treat the displayed BPM field as simulated data.

## Validation Requirements

Before claiming reproducibility:
- Confirm successful compilation
- Confirm board-specific wiring
- Verify Bluetooth serial communication
- Verify motor direction and speed control
- Test temperature against a reference
- Evaluate optical sensor readings
- Record any deviations from the original firmware

## Safety

Use electrically appropriate power supplies.
Avoid connecting unverified voltages to sensors.
Do not use the prototype for clinical decisions.
