# System Architecture

## Project Overview

The project presents an Arduino-based biomedical
robotics prototype integrating Bluetooth-controlled
movement and physiological monitoring.

## 1. Robotic Mobility Subsystem

Smartphone Controller
        |
        v
HC-05 Bluetooth Module
        |
        v
Arduino UNO R3
        |
        v
L298N Motor Driver
        |
        v
Four DC Gear Motors

The Arduino firmware supports directional movement
and PWM-based speed control.

## 2. Physiological Monitoring Subsystem

MAX30102 Sensor -----+
                     |
                     v
                Arduino Mega 2560
                     ^
                     |
DS18B20 Sensor ------+
                     |
                     v
            Serial / Bluetooth Output

The MAX30102 provides optical sensor samples
for SpO2 estimation.

The DS18B20 provides temperature readings.

## 3. Communication

The HC-05 module supports Bluetooth serial
communication with the microcontroller.

## 4. Implementation Scope

Included:
- Bluetooth-controlled robotic mobility
- Arduino-based motor control
- Temperature sensing
- Optical physiological sensing
- Serial/Bluetooth monitoring output

## 5. Verification Status

The source code has not yet been independently
compiled or validated on the original hardware.

The reported BPM output is simulated rather
than directly measured.

## Reference

Original project report, Chapters 3-6 and Appendix.
