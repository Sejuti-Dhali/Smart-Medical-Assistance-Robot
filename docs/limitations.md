# Limitations and Future Work

## 1. Simulated BPM

The displayed heart-rate value in the original
firmware is randomly generated for demonstration.

It must not be interpreted as a measured physiological
heart rate.

## 2. Sensor Validation

No reference-device calibration or clinical validation
dataset was supplied in the original report.

## 3. Pin-Mapping Discrepancy

The original DS18B20 wiring table specifies D7,
while the monitoring firmware specifies D2.

The actual hardware connection must be confirmed
before reproducing the system.

## 4. Bluetooth Control

Robot movement depends on manual Bluetooth commands.

Autonomous navigation and obstacle avoidance are
not demonstrated.

## 5. Communication Evaluation

Bluetooth latency, packet loss, operating range,
and communication reliability were not quantified.

## 6. Hardware Reproducibility

The exact battery configuration, dependency versions,
and complete electrical verification records were
not supplied.

## 7. Safety

This system is an educational engineering prototype.

It is not a certified medical device and must not
be used for clinical diagnosis or patient monitoring.

## Future Work

- Use validated heart-rate estimation
- Resolve the DS18B20 wiring discrepancy
- Calibrate sensors against reference instruments
- Measure Bluetooth communication reliability
- Evaluate movement accuracy and power consumption
- Document firmware dependencies and test procedures
- Conduct controlled experiments with appropriate
  ethical and safety oversight
