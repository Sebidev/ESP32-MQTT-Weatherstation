#include "display.h"
#include "wifi_off_icon.c"
#include "sync_icon.c"
#include "config.h"

#define IMG_WIDTH 192
#define IMG_HEIGHT 192


void show_noWifi(){
  gfx->fillScreen(BLACK);
  gfx->draw16bitRGBBitmap(120, 150, (uint16_t *)wifi_off_icon, IMG_WIDTH, IMG_HEIGHT);
  gfx->setCursor(70, 420);
  gfx->setTextColor(RED);
  gfx->setTextSize(4);
  gfx->println("Wifi reconnect");
}

void show_waitsync(){
  gfx->fillScreen(BLACK);
  gfx->draw16bitRGBBitmap(120, 150, (uint16_t *)sync_icon, IMG_WIDTH, IMG_HEIGHT);
  gfx->setCursor(100, 400);
  gfx->setTextColor(RED);
  gfx->setTextSize(3);
  gfx->println("No Sensor Data");
  gfx->setCursor(60, 440);
  gfx->setTextColor(ORANGE);
  gfx->setTextSize(3);
  gfx->println("waiting for sync...");
}

void show_sensorvalue(String topic, float temperature, int humidity, String batterystate){
    gfx->fillScreen(BLACK);

    gfx->setCursor(10, 10);  // Set cursor position
    gfx->setTextSize(2);
    gfx->setTextColor(WHITE);
    gfx->println(topic);

    gfx->setCursor(10, 80);  // Set cursor position
    gfx->setTextSize(12);

    if (temperature > -30 || temperature == 0) {
        gfx->setTextColor(CYAN); // Cyan for temperatures around 0°C
    } else if (temperature > 0 && temperature <= 20) {
        gfx->setTextColor(CYAN); // Cyan for cool temperatures
    } else if (temperature > 20 && temperature <= 30) {
        gfx->setTextColor(GREEN); // Green for moderate temperatures
    } else if (temperature > 30 && temperature <= 40) {
        gfx->setTextColor(YELLOW); // Yellow for warm temperatures
    } else {
        gfx->setTextColor(RED); // Red for hot temperatures
    }

    gfx->print(temperature, 1);
    gfx->println("C");

    gfx->setCursor(10, 200);  // Set cursor position
    gfx->setTextColor(WHITE);
    gfx->setTextSize(13);

    if (humidity < 30) {
        gfx->setTextColor(BLUE);  // Low humidity
    } else if (humidity >= 30 && humidity < 60) {
        gfx->setTextColor(GREEN);  // Normal humidity
    } else if (humidity >= 60 && humidity < 80) {
        gfx->setTextColor(YELLOW);  // Moderate humidity
    } else {
        gfx->setTextColor(RED);  // High humidity
    }

    gfx->print(humidity);
    gfx->println("%");

    gfx->setTextColor(WHITE);
    gfx->setCursor(10, 320);  // Set cursor position
    gfx->setTextSize(2);

    if (batterystate == "low") {
        gfx->setTextColor(RED);
        gfx->print("Battery State");
    } else if (batterystate == "medium") {
        gfx->setTextColor(YELLOW);
        gfx->print("Battery State");
    } else if (batterystate == "high") {
        gfx->setTextColor(GREEN);
        gfx->print("Battery State");
    } else {
        gfx->setTextColor(WHITE);
        gfx->print("Battery State Error");
    }
}