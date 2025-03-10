#include <Arduino.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <stdint.h>
#include "config.h"
#include "display.h"

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE	(50)
char msg[MSG_BUFFER_SIZE];
int value = 0;

// Tuya Sensor 1 - ts1_topic
String ts1_battery_state = ""; 
float ts1_humidity = -1;       
float ts1_temperature = NAN;    
unsigned long lastTS1Msg = 0;

// Tuya Sensor 2 - ts2_topic
String ts2_battery_state = "";
float ts2_humidity = -1;
float ts2_temperature = NAN;
unsigned long lastTS2Msg = 0;

// Tuya Sensor 3 - ts3_topic
String ts3_battery_state = "";
float ts3_humidity = -1;
float ts3_temperature = NAN;
unsigned long lastTS3Msg = 0;

void setup_wifi() {
  show_noWifi();
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_userpassword)) {
      Serial.println("connected");
      client.subscribe(ts1_topic);
      client.subscribe(ts2_topic);
      client.subscribe(ts3_topic);
      client.publish("esp32-weatherstation", clientId.c_str());
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  payload[length] = '\0'; // Null-terminate the payload
  Serial.println((char*)payload);

  // Parse the JSON payload
  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, payload);

  if (error) {
    Serial.print("Failed to parse JSON: ");
    Serial.println(error.c_str());
    return;
  }

  unsigned long now = millis();

  if (strcmp(topic, ts1_topic) == 0) {
    ts1_battery_state = doc["battery_state"].as<String>();
    ts1_humidity = doc["humidity"];
    ts1_temperature = doc["temperature"];
    lastTS1Msg = now;
    Serial.println("Updated TS1 values");
  } 
  else if (strcmp(topic, ts2_topic) == 0) {
    ts2_battery_state = doc["battery_state"].as<String>();
    ts2_humidity = doc["humidity"];
    ts2_temperature = doc["temperature"];
    lastTS2Msg = now;
    Serial.println("Updated TS2 values");
  } 
  else if (strcmp(topic, ts3_topic) == 0) {
    ts3_battery_state = doc["battery_state"].as<String>();
    ts3_humidity = doc["humidity"];
    ts3_temperature = doc["temperature"];
    lastTS3Msg = now;
    Serial.println("Updated TS3 values");
  }

  show_sensorvalue("Outdoor", ts1_temperature, ts1_humidity, ts1_battery_state, 
                   "Indoor", ts2_temperature, ts3_temperature, ts2_humidity, 
                   ts2_battery_state, ts3_battery_state);
}


void setup(){
  Serial.begin(115200);

  #ifdef GFX_EXTRA_PRE_INIT
    GFX_EXTRA_PRE_INIT();
  #endif

  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(BLACK);

  #ifdef GFX_BL
    pinMode(GFX_BL, OUTPUT);
    digitalWrite(GFX_BL, HIGH);
  #endif

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  
  show_waitsync();
}


void loop(){
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}