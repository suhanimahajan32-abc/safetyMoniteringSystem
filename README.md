IoT-Based Industrial Safety Monitoring System
📌 Overview

This project is an IoT-based industrial safety monitoring system designed to enhance workplace safety by detecting hazardous gases and fire in real time. It uses sensors to monitor environmental conditions and alerts users through a buzzer and a cloud dashboard when unsafe conditions are detected.

🎯 Objectives
Detect hazardous gases using MQ-2 sensor
Detect fire using flame sensor
Monitor temperature and humidity using DHT11
Provide real-time data on a cloud dashboard (Blynk)
Trigger alerts (buzzer) during dangerous situations
Improve industrial safety and prevent accidents

⚙️ Components Used
ESP32 Microcontroller
DHT11 Temperature & Humidity Sensor
MQ-2 Gas Sensor
Flame Sensor
Buzzer
Jumper Wires
Breadboard
Power Supply

🛠️ Technologies Used
Embedded C / Arduino IDE
IoT (Internet of Things)
Blynk Cloud Platform
Wi-Fi Communication

🔄 Working Principle
Sensors continuously monitor environmental conditions.
MQ-2 detects gas leakage (smoke, LPG, methane, etc.).
Flame sensor detects fire presence.
DHT11 measures temperature and humidity.
ESP32 processes sensor data.
Data is sent to the Blynk cloud dashboard via Wi-Fi.
If values exceed threshold limits:
Buzzer is activated
Alert is shown on dashboard

📊 Features
Real-time monitoring
Wireless data transmission
Instant alert system
User-friendly dashboard
Low-cost and efficient solution
📱 Blynk Dashboard

The dashboard displays:
Gas level readings
Flame detection status
Temperature & humidity
Alert notifications

🚀 Installation & Setup
1. Hardware Setup
Connect sensors to ESP32:
DHT11 → GPIO 4
MQ-2 → GPIO 34
Flame Sensor → GPIO 27
Buzzer → Any digital pin
2. Software Setup
Install Arduino IDE
Install required libraries:
Blynk
DHT sensor library
Add ESP32 board in Board Manager
3. Configuration
Replace in code:
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "POCO X7";
char pass[] = "examplePassword";
4. Upload Code
Select ESP32 board
Upload code via USB
🎥 Project Demonstration Video
You can watch the working demo here:
👉 Click to View Project Video
https://drive.google.com/file/d/1fKB50B92AZ1CBcv-LTDoT3CA9V_AltiP/view?usp=drive_link

📈 Future Enhancements
Add SMS/Email alert system
Integrate mobile notifications
Use AI for predictive safety analysis
Add automatic fire suppression system
Expand with more industrial sensors

⚠️ Applications
Industrial plants
Chemical factories
Warehouses
Oil & gas industries
Smart buildings

👩‍💻 Author
Suhani
(SVPCET,IIOT, etc.)

📜 License

This project is for educational purposes. 
