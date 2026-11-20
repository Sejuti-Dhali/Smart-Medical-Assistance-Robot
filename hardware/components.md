# Hardware Components

## Overview
The prototype combines a Bluetooth-controlled four-wheel robot
with a separate physiological monitoring subsystem.

## Main Components

| Component | Function |
|---|---|
| Arduino UNO R3 | Robot movement controller |
| Arduino Mega 2560 R3 | Physiological monitoring controller |
| L298N motor driver | Motor direction and speed control |
| Four DC gear motors | Robot locomotion |
| HC-05 Bluetooth module | Wireless serial communication |
| MAX30102 | Optical PPG and SpO2 sensing |
| DS18B20 | Digital temperature sensing |
| Lithium-ion batteries | Portable power supply |
| Four-wheel chassis | Mechanical support |

## Hardware Architecture

### Mobility subsystem
Smartphone -> HC-05 -> Arduino UNO -> L298N -> Motors

### Monitoring subsystem
MAX30102 + DS18B20 -> Arduino Mega -> Serial/Bluetooth output

## Source
Project report, Chapters 3 and 4.

## Important Notes
- Sensor measurements are not clinically validated.
- The original firmware displays simulated BPM values.
- Pin assignments must be verified before hardware assembly.
- The battery configuration and power distribution require
  electrical verification before operation.

