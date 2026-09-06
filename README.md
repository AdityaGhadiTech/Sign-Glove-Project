# Sign-Glove-Project
Arduino-based smart glove that detects finger gestures using flex sensors and displays corresponding messages on a 16×2 LCD.

# 🧤 Sign Glove – Gesture Based Communication System

A smart **Sign Glove** project that uses flex sensors to detect finger movements and converts predefined hand gestures into meaningful messages displayed on a **16×2 LCD**.

The project is designed to help people communicate basic needs and messages through simple hand gestures.

---

## 📌 Project Overview

Communication can be difficult for people who have speech or hearing disabilities. This project provides a simple gesture-based communication system using a glove equipped with flex sensors.

Each finger is connected to a flex sensor. When a finger bends, the resistance of the flex sensor changes. The Arduino reads this change as an analog value and determines whether the finger is **straight or bent**.

Based on the combination of finger states, the system identifies a predefined gesture and displays the corresponding message on the LCD.

---

## 🎯 Objectives

- Detect finger movements using flex sensors.
- Convert finger movements into digital states.
- Recognize predefined hand gestures.
- Display the corresponding message on a 16×2 LCD.
- Create a low-cost and simple assistive communication system.
- Provide a foundation for future voice-based or wireless communication.

---

## 🛠️ Components Used

| Component | Quantity |
|---|---:|
| Arduino Uno R3 | 1 |
| Flex Sensors | 5 |
| 16×2 LCD Display | 1 |
| 10KΩ Resistors | 5 |
| Jumper Wires | As required |
| Glove | 1 |
| Breadboard / PCB | 1 |

---

## 🔌 Pin Connections

### Flex Sensors

| Finger | Arduino Pin |
|---|---|
| Thumb | A1 |
| Index | A2 |
| Middle | A3 |
| Ring | A4 |
| Pinky | A5 |

Each flex sensor is connected using a voltage-divider circuit with a 10KΩ resistor.

### LCD Display

The LCD is connected using the following pins:

| LCD Pin | Arduino Pin |
|---      |---          |
| RS      | 12          |
| E       | 11          |
| D4      | 5           |
| D5      | 4           |
| D6      | 3           |
| D7      | 2           |

---

## ✋ Gesture Mapping

The current version recognizes five basic gestures.

| Gesture   | Finger Bent | Message         |
|---        |---          |---              |
| Gesture 1 | Thumb       | I NEED WATER    |
| Gesture 2 | Index       | PLEASE HELP ME  |
| Gesture 3 | Middle      | I AM HUNGRY     |
| Gesture 4 | Ring        | NEED RESTROOM   |
| Gesture 5 | Pinky       | THANK YOU!      |

### Finger State Representation

Each finger is represented using:

- `0` → Straight
- `1` → Bent

For example:

```text
1 0 0 0 0
