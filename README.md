# Automated_Poultry
IoT-based Poultry Farm Automation using ESP8266 + Firebase + Web Dashboard
# Automated Poultry Farm – IoT + Firebase + ESP8266

A fully automated poultry farm monitoring and control system using:

- ESP8266 NodeMCU  
- DHT11 Temperature/Humidity Sensor  
- LDR Sensor  
- Firebase Realtime Database  
- Modern Web Dashboard  
- Fan & LED automation  

This system monitors environmental conditions and automates actions such as:
✅ Turning fan ON/OFF based on temperature  
✅ Controlling poultry LED light based on LDR (day/night)  
✅ Live data dashboard hosted on GitHub Pages  

---

## 🔥 Features

- Real-time Temperature & Humidity Monitoring  
- Day/Night Detection using LDR  
- Firebase-based automation  
- Live Dashboard using Firebase SDK  
- GitHub Pages hosting supported  
- Clean + modern UI  

---

## 📂 Project Structure

```
automated-poultry-farm/
│
├── website/
│   └── index.html
│
├── esp8266-code/
│   └── poultry_iot.ino
│
├── README.md
└── LICENSE
```

---

## 🚀 Web Dashboard

Live dashboard built with Firebase Realtime Database (v8 JS SDK).
Displays:
- Temperature  
- Humidity  
- LDR (Day/Night)  
- Fan Status  
- LED Light Status  

---

## 🛠 Hardware Required

- NodeMCU ESP8266  
- DHT11 Sensor  
- LDR Sensor  
- 10k Resistor (for LDR)  
- LED + Fan (Relay optional)  

---

## 🔧 ESP8266 Setup

1. Install **Firebase ESP Client** library  
2. Add Firebase config  
3. Upload the code from:

```
esp8266-code/poultry_iot.ino
```



## 🌐 Hosting on GitHub Pages

1. Go to `Settings` → **Pages**
2. Select:
```
Branch: main  
Folder: /website  
```
3. Save → Site goes live at:

```
https://bucket-adjust-31985810.figma.site/
```
4. Default site link
```
https://ameysecops.github.io/Automated_Poultry/
```
---

## 📜 License

This project is licensed under MIT License.  
You are free to use, modify, and distribute this code.

---

## ⭐ Author

**Amey Jadhav**  
(Project Owner – Automated Poultry Farming System)
