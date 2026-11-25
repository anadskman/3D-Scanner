# Portable 3D Scanner
<img width="1768" height="926" alt="Screenshot 2026-11-02 200255" src="https://github.com/user-attachments/assets/cd03dc1a-822b-4394-810b-dc359ea0d356" />

A portable 3D scanner built from scratch. The scanner uses a nema 17 on the arch and rotating turntable to capture objects from different angles and create 3D models.
The design uses an ESP32, two NEMA 17 stepper motors, DRV8825 drivers and a 1080p USB camera.

## Overview

The scanner uses two motorised axes:
- Rotating turntable to move the object
- Motorised arch to move the camera around the object

The camera captures images from different angles while the ESP32 controls the movement of both motors.
The USB camera connects directly to a computer, where the images can be processed into a 3D model.
The main goal is to create a compact scanner that can be transported easily and used to scan smaller objects.

## Features

- Fully custom CAD design
- Custom designed PCB
- Motorised rotating turntable
- Motorised camera arch
- Internal gear mechanism
- 1080p USB camera
- WS2812 LED lighting
- Automatic homing using limit switches
- ESP32 motor control
- 3D printed components
- Modular and detachable components
- Designed to be portable

## Builds Guide

1. **Arch** the teeth will sit inside the arch base and optional glued into place if wished.
2. The camera should be screwed to the flat part of the arch
3. Attach the arch holder to the nema 17 and slide the arch into it
4. Put the gear onto the other nema 17
5. Use the motor connector to connect both motors together and bolt the motor to it.
6. **Turntable** Just slide the table onto the motor in-between the arch
7. **PCB Case** simply just screw the bottom, walls, and top together.

## Bill of Materials

| **Name** | **Purpose** | **Quantity Purchased** | **Quantity Used** | **Link** | **Total Cost (EUR)** | **Distributor** |
| -------- | ----------- | --------------------- | ----------------- | -------------------- | -------- | --------------- |
| InnoMaker 1080p USB Camera | Captures images of the object | 1 | 1 | [Amazon](https://www.amazon.ie/gp/product/B0CNCSFQC1/ref=ox_sc_act_title_5?smid=A3LR51RN935ZZX&psc=1) | €20.92  | Amazon |
| NEMA 17 Stepper Motors | Drives the turntable and arch | 3 | 2 | [Amazon](https://www.amazon.ie/gp/product/B0FSPZT9P4/ref=ox_sc_act_title_4?smid=A3JL2PT0MX26A6&psc=1) | €27.00 | Amazon |
| WS2812 LED Rings | Provides lighting around the object | 5 | 1 | [Amazon](https://www.amazon.ie/gp/product/B0CMW5LWM2/ref=ox_sc_act_title_3?smid=A35XDNP896ERNI&psc=1) | €8.19 | Amazon |
| Limit Switches | Used for homing and movement limits | 3 | 3 | [Amazon](https://www.amazon.ie/Official-Switch-3-Piece-Compatible-Printers/dp/B09R3TWDSV/ref=sr_1_20?sr=8-20) | €4.99  | Amazon |
| ESP32 Development Board | Main controller for the scanner | 1 | 1 | [Amazon](https://www.amazon.ie/DollaTek-Development-Bluetooth-compatible-Ultra-Low-Consumption/dp/B0CXT3978J/ref=rvi_d_sccl_16/257-0773453-0872007?psc=1) | 7.99  | Amazon |
| DRV8825 Stepper Drivers | Controls the NEMA 17 motors | 2 | 2 | [Owned](https://google.com) | Owned | Owned |
| Custom PCB | Connects the electronics together | 1 | 1 | [JlCPCB](https://cart.jlcpcb.com/quote/gerberviewThree/?qs=2035bd6f6bf045a4be76bd0e8a033c01_1_0_1_0_0.html) | €22.63 | JlCPCB |
| 12V DC Power Supply | Main power for the scanner | 1 | 1 | [Owned](https://google.com) | Owned | Owned |
| 5V Buck Converter | Converts 12V to 5V for the ESP32 and LEDs | 1 | 1 | [Amazon](https://www.amazon.ie/Converter-Adjustable-Voltage-Efficient-Regulator/dp/B0FLYNNNWL/ref=sr_1_1?sr=8-1) | €8.99 | Amazon |
| 74AHCT125 | Logic level shifting for the LED data signal | 1 | 1 | [Amazon](https://www.amazon.ie/Be-Your-Mind-SN74AHCT125N-Three-State/dp/B0DXK7PWTN/ref=sr_1_1?sr=8-1) | €9.49 | Amazon |
| 330Ω Resistor | LED data line protection | 1 | 1 | [Owned](https://google.com) | Owned | Owned |
| 1000µF Capacitor | Smooths the LED power supply | 1 | 1 | [Owned](https://google.com) | Owned | Owned |
| 100µF Capacitors | Filters power near the stepper drivers | 2 | 2 | [Owned](https://google.com) | Owned | Owned |
| 100nF Capacitors | Decoupling for the electronics | 2+ | 2+ | [Owned](https://google.com) | Owned | Owned |
| Barrel Jack | Main power input | 1 | 1 | [Owned](https://google.com) | Owned | Owned |
| Screw Terminals / Connectors | Connects motors and power wiring | As required | As required | [Owned](https://google.com) | Owned | Owned |
| Fuse | Protects the main power input | 1 | 1 | [Amazon](https://www.amazon.ie/SeKi-Micro-Fuse-Glass-Fuses/dp/B09JZHQYR6/ref=sr_1_2?sr=8-2) | €6.88 | Amazon |
| Fuse Holder | Holds the fuse | 1 | 1 | [Amazon](https://www.amazon.ie/ECSiNG-Holder-Transparent-Terminals-5x20mm/dp/B0C4983C7C/ref=sr_1_2?sr=8-2) | €7.49 | Amazon |
| SB540 Schottky diode | reverse polarary protection | 1 | 1 | [Amazon](https://www.amazon.ie/20-Pieces-SR540-Schottky-Rectifier/dp/B079KDRFY7/ref=sr_1_2?sr=8-2) | €6.26  | Amazon |
**Total** **€130.83**

Prices are for the full packs purchased, not the cost of only the parts used. The third stepper motor and spare LED rings are included in the purchase quantities.

## Project Images

### CAD

<img width="1768" height="926" alt="Screenshot 2026-11-02 200255" src="https://github.com/user-attachments/assets/23af5ca4-cc77-4605-89b7-836991024a5a" />

### PCB

<img width="1827" height="966" alt="Screenshot 2026-10-24 155852" src="https://github.com/user-attachments/assets/ea7f55a4-f6c3-487e-8415-9de4615c52b3" />

### Schematic

<img width="1700" height="1178" alt="Screenshot 2026-10-24 155925" src="https://github.com/user-attachments/assets/93237d53-f678-44f3-93bf-12346d0526df" />

## Cart Screenshots

### JLCPCB
<img width="1977" height="825" alt="image" src="https://github.com/user-attachments/assets/e909255d-49e2-4645-8cd7-7ed48e5b4acb" />

### Amazon
<img width="2514" height="1334" alt="Screenshot 2026-11-04 193047" src="https://github.com/user-attachments/assets/bca1e0dc-dc5b-4386-ac06-0829250fea5c" />
