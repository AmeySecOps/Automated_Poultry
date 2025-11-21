/***********************************************************
  NODEMCU + DHT11 + LDR + Firebase Automation System
************************************************************/

#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <DHT.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

// -------------------- SENSOR PINS ------------------------
#define DHTPIN 4
#define DHTTYPE DHT11
#define LDR_PIN A0
#define FAN_PIN 14
#define LED_PIN 12

DHT dht(DHTPIN, DHTTYPE);

// -------------------- WIFI CONFIG ------------------------
#define WIFI_SSID "amey"
#define WIFI_PASSWORD "123456789"

// -------------------- FIREBASE CONFIG ---------------------
#define API_KEY "AIzaSyDS37C27k2btbP0kzLV0trhkl1lni9Er4A"
#define DATABASE_URL "automated-poultry-farmin-46814-default-rtdb.asia-southeast1.firebasedatabase.app"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
bool signupOK = false;

// ----------------------------------------------------------
void setup() {
  Serial.begin(115200);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.println("\nWiFi Connected!");

  // Firebase
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;

  // Anonymous signup
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Firebase Signup OK!");
    signupOK = true;
  } else {
    Serial.printf("Signup Error: %s\n", config.signer.signupError.message.c_str());
  }

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

// ----------------------------------------------------------
void loop() {
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 2000)) {
    sendDataPrevMillis = millis();

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();
    int ldrValue = analogRead(LDR_PIN);

    Serial.println("Temp: " + String(temperature));
    Serial.println("Humidity: " + String(humidity));
    Serial.println("LDR: " + String(ldrValue));

    // LIGHT AUTOMATION
    if (ldrValue > 300) {
      digitalWrite(LED_PIN, HIGH);
      Firebase.RTDB.setString(&fbdo, "poultry/lightStatus", "ON");
    } else {
      digitalWrite(LED_PIN, LOW);
      Firebase.RTDB.setString(&fbdo, "poultry/lightStatus", "OFF");
    }

    // FAN AUTOMATION
    if (temperature > 33) {
      digitalWrite(FAN_PIN, HIGH);
      Firebase.RTDB.setString(&fbdo, "poultry/fanStatus", "ON");
    } else {
      digitalWrite(FAN_PIN, LOW);
      Firebase.RTDB.setString(&fbdo, "poultry/fanStatus", "OFF");
    }

    // PUSH LIVE DATA
    Firebase.RTDB.setFloat(&fbdo, "poultry/temperature", temperature);
    Firebase.RTDB.setFloat(&fbdo, "poultry/humidity", humidity);
    Firebase.RTDB.setInt(&fbdo, "poultry/ldr", ldrValue);
  }
}
