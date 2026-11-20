# Experimental Results

## Evidence Scope

The original project report provides prototype
photographs, implementation descriptions, and
demonstration screenshots.

The following observations are based on the report,
not on an independent replication.

## 1. Robot Movement

The report describes a four-wheel robot controlled
through Bluetooth commands.

The implementation supports:
- Forward
- Backward
- Left
- Right
- Stop

The firmware also defines PWM speed settings.

No quantitative measurements of movement accuracy,
latency, maximum speed, or reliability were supplied.

## 2. Temperature Monitoring

The monitoring firmware reads temperature using
a DS18B20 digital sensor.

Readings are formatted in Celsius and Fahrenheit.

The report does not provide reference-device
comparisons or measurement-error statistics.

## 3. Optical Physiological Monitoring

The MAX30102 collects red and infrared optical samples.

The firmware invokes an algorithm to estimate SpO2
and checks whether the calculated value is valid.

The reported demonstration is not sufficient to
establish clinical SpO2 accuracy.

## 4. Heart-Rate Demonstration

The original firmware includes:

    randomBPM = random(70, 93);

Therefore, the displayed BPM values are simulated
demonstration values rather than measured heart rates.

The internally calculated heartRate variable is not
used as the displayed BPM output.

## 5. Interpretation

The report supports a proof-of-concept demonstration
of robotic mobility and physiological sensor integration.

It does not establish:
- Clinical diagnostic performance
- Validated heart-rate measurement
- Medical-grade monitoring accuracy
- Autonomous navigation performance

## Evidence

Original project report, Chapter 6 and Appendix.

Original experimental photographs and screenshots
should be added only with publication authorization.
