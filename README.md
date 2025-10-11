# 🪖 Smart Helmet System

A safety-focused IoT project designed to enhance rider protection and ensure that a motorcycle only starts when the rider is wearing the helmet properly.  
This system uses wireless communication between a **helmet unit (transmitter)** and a **bike ECU unit (receiver)** to enforce safety and provide additional smart features.

---

## 🚀 Features

✅ Ensures the vehicle starts **only when the helmet is worn**  
✅ Wireless link between helmet and bike using **RF/Bluetooth**  
✅ Detects **helmet wear** using sensor input (e.g., IR, push switch, or proximity)  
✅ Alerts the rider in case of **no-helmet detection** or **communication loss**  
✅ Low power consumption and compact design  
✅ Optional extensions – accident detection, alcohol detection, GPS tracking  

---

## 🧩 System Overview

The Smart Helmet system consists of **two modules**:

### 1️⃣ Helmet Unit (Transmitter)
- Mounted inside the helmet  
- Detects whether the rider is wearing it using a **sensor**  
- Sends a signal to the ECU unit via **wireless transmitter**  
- Can include optional modules:
  - Alcohol sensor (MQ-3)
  - Vibration sensor for crash detection
  - Buzzer or LED for alerts

### 2️⃣ ECU Unit (Receiver)
- Mounted on the bike  
- Receives data from the helmet  
- Allows ignition only if the valid “helmet worn” signal is received  
- Controls a **relay** to enable or disable the ignition circuit  

---

## ⚙️ Components Used

| Component | Quantity | Description |
|------------|-----------|-------------|
| Arduino Uno / Nano | 2 | One for helmet, one for ECU |
| RF module (Tx/Rx pair) / Bluetooth | 1 pair | For wireless communication |
| Push switch / IR sensor | 1 | Detects helmet wearing |
| Relay module | 1 | Controls ignition circuit |
| Buzzer | 1 | Alert indicator |
| LED | 2 | System status indicators |
| Battery (9V / Li-ion) | 1 | Power supply for helmet unit |

---

## 🔌 Working Principle

1. When the rider wears the helmet, the **helmet sensor** activates.  
2. The **transmitter module** sends a coded signal to the ECU.  
3. The **receiver module** at the ECU validates the signal.  
4. If valid, it **activates a relay**, allowing ignition to start.  
5. If no signal or invalid signal is received, the ignition remains **disabled**, ensuring safety.

---

## 🧠 Code Files

| File Name | Description |
|------------|-------------|
| `Helmet (Receiver).ino` | Code for the helmet-side transmitter unit |
| `ECU (Transmitter).ino` | Code for the bike ECU-side receiver unit |

Each file contains setup and loop functions to handle sensor reading, wireless communication, and control logic.

---

## 🔧 How to Use

1. **Upload** the respective `.ino` files to two Arduino boards.  
2. **Connect** components as per pin configuration inside the code.  
3. Power both units (helmet and bike).  
4. Test the setup:
   - Helmet not worn → Ignition disabled.  
   - Helmet worn → Ignition enabled.  

---

## 🔋 Future Enhancements

- 📍 GPS & GSM integration for accident alert system  
- 💬 Voice assistant integration  
- 📱 Android app for status monitoring  
- ☁️ IoT cloud connectivity for real-time tracking  
- ⚡ Battery monitoring and auto shutdown features  

---

## 📸 Project Images (Add Here)

You can include photos or circuit diagrams here, for example:

---

## 🧑‍💻 Authors

**Developed by:**  
[Dhanraj Chavan](https://github.com/DhanrajjChavan)

---

## 🏁 License

This project is open-source and available under the **MIT License**.  
Feel free to use, modify, and distribute it with proper credits.

---

⭐ **If you like this project, give it a star on GitHub!**  
It motivates me to keep improving it.
