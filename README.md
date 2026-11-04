# Portable 3D Scanner
<img width="1768" height="926" alt="Screenshot 2026-11-02 200255" src="https://github.com/user-attachments/assets/cd03dc1a-822b-4394-810b-dc359ea0d356" />

A custom-designed portable 3D scanner built from scratch in Fusion 360 and KiCad. The scanner uses a motorised arch and rotating turntable to capture objects from different angles and create 3D models.

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

## Design Process

### Initial Concept

The original idea was to make a portable 3D scanner using a rotating turntable and a camera mounted on a curved arch.

Instead of moving multiple cameras around the object, the design uses one camera that can move to different positions while the turntable rotates.

The main parts were designed in Fusion 360, with the electronics designed separately in KiCad.

### Arch Mechanism

The arch holds the camera and allows it to move around the object.

The design uses an internal gear system to move the camera along the arch using a NEMA 17 stepper motor.

The arch includes:

- Internal gear teeth
- NEMA 17 motor mounting
- Camera mounting bracket
- Detachable mounting points
- Space for cable routing

The gear teeth were generated using Helix Gear+ in Fusion 360 rather than modelling each tooth individually.

### Turntable

The turntable rotates the object during scanning.

It uses a separate NEMA 17 stepper motor controlled by a DRV8825 driver.

The turntable is designed to hold smaller objects while keeping them centred during rotation.

### Camera Mount

The camera mount was designed specifically around the InnoMaker USB camera.

It attaches to the moving arch and holds the camera in position while allowing it to point towards the centre of the turntable.

### PCB Housing

A custom housing was designed for the PCB.

The housing includes cutouts for the barrel jack, screw terminals and connectors. It also has mounting holes for attaching the top and bottom sections together.

The ESP32 is removable rather than permanently enclosed inside the case.

## Electronics

### Components

- ESP32 Development Board
- 2× DRV8825 Stepper Drivers
- 2× NEMA 17 Stepper Motors
- InnoMaker 1080p USB Camera
- WS2812 RGB LED Ring
- 3× Limit Switches
- 12V Power Supply
- 5V Buck Converter
- Custom PCB

### PCB

The PCB was designed in KiCad and exported as a STEP model so it could be imported into Fusion 360.

This allowed the electronics to be placed into the mechanical assembly to check clearances and mounting positions.

## CAD Improvements

Several improvements were made throughout the design:

- Custom internal gear mechanism
- Modular motor mounts
- Detachable arch assembly
- Custom camera mount
- PCB housing with removable ESP32
- Standardised screw sizes
- STEP exports for individual components
- Full assembly with joints for movement testing
- PCB imported into Fusion 360 for clearance checking

## Bill of Materials


## Project Images

### CAD

<img width="1768" height="926" alt="Screenshot 2026-11-02 200255" src="https://github.com/user-attachments/assets/23af5ca4-cc77-4605-89b7-836991024a5a" />

### PCB

<img width="1827" height="966" alt="Screenshot 2026-10-24 155852" src="https://github.com/user-attachments/assets/ea7f55a4-f6c3-487e-8415-9de4615c52b3" />

### Schematic

<img width="1700" height="1178" alt="Screenshot 2026-10-24 155925" src="https://github.com/user-attachments/assets/93237d53-f678-44f3-93bf-12346d0526df" />

---

**Designed and built by Jason Clark**
