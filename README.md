# Remote Patient Monitoring System (RPMS)

## Overview

The Remote Patient Monitoring System (RPMS) is an IoT-based healthcare solution designed to monitor a patient's vital parameters in real time. The system measures Heart Rate, Blood Oxygen Saturation (SpO₂), and Body Temperature, and displays the data on both an LCD screen and a web-based dashboard for remote monitoring.

## Features

* Real-time Heart Rate Monitoring
* SpO₂ (Blood Oxygen Level) Measurement
* Body Temperature Monitoring
* Wireless Data Transmission using Wi-Fi
* Web-Based Monitoring Dashboard
* Real-Time Data Visualization
* Embedded System Integration

## Technologies Used

### Hardware

* Arduino Uno
* NodeMCU ESP8266
* MAX30100 Pulse Oximeter Sensor
* LM35 Temperature Sensor
* 16x2 LCD Display
* Breadboard and Connecting Wires

### Software

* Arduino IDE
* Embedded C++

## System Architecture

1. Sensors collect patient health data.
2. Arduino Uno processes sensor readings.
3. NodeMCU ESP8266 receives data through serial communication.
4. Data is transmitted over Wi-Fi.
5. Users can access health information through a web dashboard.

## Project Workflow

* Acquire sensor readings from MAX30100 and LM35.
* Process data using Arduino Uno.
* Transfer readings to NodeMCU ESP8266.
* Display values on LCD.
* Host a web dashboard through Wi-Fi.
* Monitor patient health data remotely.

## Applications

* Remote Healthcare Monitoring
* Home Patient Care
* Health Monitoring Systems
* IoT-Based Medical Solutions

## Skills Demonstrated

* Embedded Systems
* Sensor Interfacing
* IoT Development
* Wireless Communication
* Real-Time Monitoring
* Troubleshooting and Testing

## Future Enhancements

* Cloud Database Integration
* Mobile Application Support
* Emergency Alert Notifications
* Historical Data Storage and Analytics

## Team Project

This project was developed as part of the final-year B.Tech curriculum by students of the Department of Electronics and Communication Engineering at Pranveer Singh Institute of Technology (PSIT), Kanpur.

## Team Members

- Saksham Srivastava
- Satyam Singh
- Rastapuram Sumanth
- Nitin Pal

**Department:** Electronics and Communication Engineering  
**Institute:** Pranveer Singh Institute of Technology (PSIT), Kanpur
**Session:** 2026
