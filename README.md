# Gas Leak Detection System  
## Subject: Introduction to Internet of Things (IoT)

## 📌 Introduction
The Internet of Things (IoT) enables physical devices to sense, monitor, and
respond to real-world conditions. One critical application of IoT is safety
monitoring, especially in environments where hazardous gases may be present.

This project focuses on designing and implementing a **Gas Leak Detection
System** using IoT concepts. The system continuously monitors gas levels using
a gas sensor and provides real-time alerts when a gas leak is detected. This
project demonstrates how sensors, actuators, and embedded systems work together
to improve safety.

---

## 🎯 Objectives
- To understand the fundamentals of IoT-based sensing systems  
- To detect gas leakage using a gas sensor  
- To provide visual and audio alerts when unsafe gas levels are detected  
- To display real-time system status on an LCD  

---

## 🧰 Hardware Components
- Arduino Uno  
- MQ-2 Gas Sensor  
- I2C LCD Display  
- Buzzer  
- Jumper Wires  

---

## 🧠 System Description
The MQ-2 gas sensor continuously monitors the surrounding air for combustible
gases such as LPG, methane, and smoke. The sensor outputs a digital signal when
the gas concentration exceeds a predefined threshold.

When gas leakage is detected:
- The buzzer is activated to alert users
- A warning message is displayed on the LCD
- The system continues monitoring in real time

This system represents a basic IoT sensing node commonly used in smart homes
and industrial safety systems.

---

## ⚙️ Features
- Continuous gas monitoring  
- Real-time alert using buzzer  
- LCD status display  
- Simple and reliable detection logic  

---

## 🖥️ Software & Tools
- Arduino IDE  
- Tinkercad (for simulation and circuit design)  
- Embedded C / Arduino Programming  

---

## 🔄 Working Principle
1. The MQ-2 sensor detects gas concentration
2. Arduino reads the sensor output
3. If gas is detected:
   - Buzzer turns ON
   - LCD displays “Gas Leak Detected”
4. If no gas is detected:
   - Buzzer remains OFF
   - LCD displays “Environment Safe”

---

## 🌍 Applications
- Smart home safety systems  
- Industrial gas monitoring  
- Fire prevention systems  
- IoT-based environmental monitoring  

---

## 📸 Circuit Diagram
Refer to `circuit.png` for the complete circuit connection.

---

## 👤 Student Information
**Name:** Haresh Varma Shan  
**Subject:** Introduction to IoT  
**Project Type:** Mini Project / Practical Assignment  
