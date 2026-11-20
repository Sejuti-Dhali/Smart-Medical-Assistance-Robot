# Hardware Pin Connections

Source: Project report, Tables 4.2.1–4.2.6,
and Arduino firmware in the Appendix.

## 1. L298N to Arduino UNO

| L298N | Arduino UNO |
|---|---|
| ENA | D6 |
| IN1 | D7 |
| IN2 | D8 |
| IN3 | D9 |
| IN4 | D10 |
| ENB | D5 |

## 2. L298N to Motors

| L298N | Motor |
|---|---|
| OUT1 / OUT2 | Left motor group |
| OUT3 / OUT4 | Right motor group |

## 3. HC-05 to Arduino UNO

| HC-05 | Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| TXD | D11 (SoftwareSerial RX) |
| RXD | D12 (SoftwareSerial TX, inferred from code) |

The report's wiring table omits the HC-05 RXD connection.
The firmware specifies SoftwareSerial(11, 12).
Use appropriate voltage-level protection for the HC-05 RX input.

## 4. MAX30102 to Arduino Mega

| MAX30102 | Arduino Mega |
|---|---|
| VIN | 3.3V |
| GND | GND |
| SDA | D20 |
| SCL | D21 |

## 5. DS18B20 to Arduino Mega

| DS18B20 | Report Table | Appendix Firmware |
|---|---|---|
| VDD | 5V | Not explicitly defined |
| GND | GND | Not explicitly defined |
| DQ | D7 | D2 |

IMPORTANT: The report's DS18B20 wiring table
specifies D7, while the firmware specifies D2.
This discrepancy must be resolved on the actual hardware.

A suitable data-line pull-up resistor may be required,
depending on the sensor module and wiring configuration.

## 6. Power

The report describes lithium-ion batteries and
the L298N motor power connections.

Before powering the prototype, verify:
- Battery pack voltage and polarity
- Motor current requirements
- Arduino supply voltage
- Common ground
- Regulator and L298N jumper configuration

Do not connect an unverified battery arrangement.
