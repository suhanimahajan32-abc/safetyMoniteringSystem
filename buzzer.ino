#include <WiFi.h>
#include <ThingSpeak.h>
#include <DHT.h>

// 🔌 Pins
#define DHTPIN 4
#define DHTTYPE DHT11
#define MQ2_PIN 34
#define FLAME_PIN 27
#define BUZZER 26

// WiFi
const char* ssid = "POCO X7";
const char* pass = "sumo6969";

// ThingSpeak
unsigned long channelID = 3348356;        // 🔁 replace
const char* writeAPIKey = "08E8PR2PEBYJRXBH"; // 🔁 replace

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);

// 🔧 Thresholds
int gasThreshold = 1500;
float tempThreshold = 35.0;
float humThreshold = 80.0;

void setup() {
  Serial.begin(115200);

  pinMode(MQ2_PIN, INPUT);
  pinMode(FLAME_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(BUZZER, LOW);

  dht.begin();

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");

  ThingSpeak.begin(client);
}

void loop() {

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  int gas    = analogRead(MQ2_PIN);
  int flame  = digitalRead(FLAME_PIN); // 0 = fire

  Serial.println("------ SENSOR DATA ------");
  Serial.print("Temp: "); Serial.println(temp);
  Serial.print("Humidity: "); Serial.println(hum);
  Serial.print("Gas: "); Serial.println(gas);
  Serial.print("Flame: "); Serial.println(flame);

  bool hazard = false;

  // 🔥 Fire → buzzer
  if (flame == 0) {
    Serial.println("🔥 Fire Detected");
    digitalWrite(BUZZER, HIGH);
    hazard = true;
  }

  // 🧪 Gas → buzzer
  else if (gas > gasThreshold) {
    Serial.println("⚠️ Gas Leakage");
    digitalWrite(BUZZER, HIGH);
    hazard = true;
  }

  // 🌡️ Temp warning
  if (temp > tempThreshold) {
    Serial.println("🌡️ High Temperature");
  }

  // 💧 Humidity warning
  if (hum > humThreshold) {
    Serial.println("💧 High Humidity");
  }

  // ✅ Normal → buzzer OFF
  if (!hazard) {
    digitalWrite(BUZZER, LOW);
    Serial.println("✅ System Safe");
  }

  // 📡 Send to ThingSpeak
  ThingSpeak.setField(1, temp);
  ThingSpeak.setField(2, hum);
  ThingSpeak.setField(3, gas);
  ThingSpeak.setField(4, flame);

  int status = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (status == 200) {
    Serial.println("✅ Data sent to ThingSpeak");
  } else {
    Serial.println("❌ Error sending data");
  }

  delay(15000); // ThingSpeak rule
}