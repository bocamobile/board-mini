# Datasheet
The **mini::grid** is based around the SIMCOM SIM868, featuring GPS L1 C/A code
and quad-band GSM connection. Antennas can be connected via the respective u.fl
connectors and a nanoSIMcard slot is located on the backside. Connect it to
your custom application via the two Binder subminiatur connectors with wire out
CAN, power supply and IOs.

## Microcontroller
 * Manufacturer: SIMCOM
 * Type: SIM868

## Key Features
Designed for global market, SIM868 is integrated with a high performance
GSM/GPRS part and a GNSS part. The GSM part is a quad-band GSM/GPRS that works
on frequencies GSM 850 MHz, EGSM 900MHz, DCS 1800MHz and PCS 1900MHz. GSM
features GPRS multi-slot class 12/class 10 (optional) and supports the GPRS
coding schemes CS-1, CS-2, CS-3 and CS-4.

The GNSS part solution offers best-in-class acquisition and tracing
sensitivity, Time-To-First-Fix (TTFF) and accuracy. With built-in LNA, GNSS
doesn’t need external LNA. GNSS can track as low as -167dBm signal even without
network assistance. The GNSS has excellent low power consumption characteristic
(acquisition 24mA, tracking 22mA). GNSS supports various location and
navigation applications, including autonomous GPS, GLONASS, BEIDOU, QZSS, SBAS
(WAAS, EGNOS, GAGAN, and MSAS) and A-GPS.

With a tiny configuration of 17.6*15.7*2.3mm, SIM868 can meet almost all the
space requirements in customers’ applications, such as smart phone, PDA and
other mobile devices.

* One three-line serial port, one full modem serial port and one GNSS serial
  port.
* USB interface
* Audio channels which include a microphone input and two speakers output
* Programmable general purpose input and output
* Two SIM card interfaces
* SD card interface
* I2C interface
* ADC interface
* Support GNSS function
* 33tracking/99 acquisition-channel GNSS receiver
* 12 multi-tone active interference cancellers and jamming elimination
* Max fixed update rate up to 10 HZ (1Hz default)
* Accuracy 2.5m CEP

## Board

![mini::grid](./pictures/mini-grid-front.png "mini::grid")

* Size: 54mm x 42.5 mm - exactly half a credit card
* Mounting Holes:
 * ø 3.2mm (for M3 bolt)
 * spaced 48mm and 36.5mm from each other
* Board-to-Board Connectors:
 * 2x Würth WR-MM Male 26p, 690357102672
 * pinout symmetrical - top boards can be rotated
* Auxilary Conectors
 * 1x 4-Pin BINDER (PWR) for Power Supply and CAN
 * 1x 5-Pin BINDER (CH1) for digital and analog Sensor Input, 5V Sensorsupply
* u.fl connector for GSM and GPS antenna
* NanoSIM Card holder WR-CRD Nano SIM Card Connector

## License
![mini::grid License](./pictures/mini-grid-license.png "mini::grid License")

