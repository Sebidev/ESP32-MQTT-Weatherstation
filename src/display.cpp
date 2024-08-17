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

void show_sensorvalue(String topic1, float temperature1, int humidity1, String batterystate1, String topic2, float temperature2, float temperature3,int humidity2, String batterystate2, String batterystate3) {
    gfx->fillScreen(BLACK);

    // Tuya Sensor 1
    gfx->setCursor(10, 10);  // Set cursor position
    gfx->setTextSize(2);
    gfx->setTextColor(WHITE);
    gfx->println(topic1);

    gfx->setCursor(10, 50);  // Set cursor position
    gfx->setTextSize(12);

    if (temperature1 >= -30 && temperature1 <= 0) {
        gfx->setTextColor(CYAN); // Cyan for temperatures around 0°C
    } else if (temperature1 > 0 && temperature1 <= 25) {
        gfx->setTextColor(GREEN); // Green for cool temperatures
    } else if (temperature1 > 25 && temperature1 <= 35) {
        gfx->setTextColor(ORANGE); // Orange for moderate temperatures
    } else if (temperature1 > 35 && temperature1 <= 40) {
        gfx->setTextColor(YELLOW); // Yellow for warm temperatures
    } else {
        gfx->setTextColor(RED); // Red for hot temperatures
    }

    gfx->print(temperature1, 1);
    gfx->println("C");

    gfx->setCursor(10, 150);  // Set cursor position
    gfx->setTextColor(WHITE);
    gfx->setTextSize(13);

    if (humidity1 < 30) {
        gfx->setTextColor(BLUE);  // Low humidity
    } else if (humidity1 >= 30 && humidity1 < 60) {
        gfx->setTextColor(GREEN);  // Normal humidity
    } else if (humidity1 >= 60 && humidity1 < 80) {
        gfx->setTextColor(YELLOW);  // Moderate humidity
    } else {
        gfx->setTextColor(RED);  // High humidity
    }

    gfx->print(humidity1);
    gfx->println("%");

    gfx->setTextColor(WHITE);
    gfx->setCursor(10, 260);  // Set cursor position
    gfx->setTextSize(2);

    if (batterystate1 == "low") {
        gfx->setTextColor(RED);
        gfx->print("Battery State");
    } else if (batterystate1 == "medium") {
        gfx->setTextColor(YELLOW);
        gfx->print("Battery State");
    } else if (batterystate1 == "high") {
        gfx->setTextColor(GREEN);
        gfx->print("Battery State");
    } else {
        gfx->setTextColor(WHITE);
        gfx->print("Battery State Error");
    }

    // Tuya Sensor 2
    gfx->setCursor(10, 310);  // Set cursor position
    gfx->setTextSize(2);
    gfx->setTextColor(WHITE);
    gfx->println(topic2);

    gfx->setCursor(10, 350);  // Set cursor position
    gfx->setTextSize(12);

    if (temperature2 >= -30 && temperature2 <= 0) {
        gfx->setTextColor(CYAN); // Cyan for temperatures around 0°C
    } else if (temperature2 > 0 && temperature2 <= 25) {
        gfx->setTextColor(GREEN); // Green for cool temperatures
    } else if (temperature2 > 25 && temperature2 <= 35) {
        gfx->setTextColor(ORANGE); // Orange for moderate temperatures
    } else if (temperature2 > 35 && temperature2 <= 40) {
        gfx->setTextColor(YELLOW); // Yellow for warm temperatures
    } else {
        gfx->setTextColor(RED); // Red for hot temperatures
    }

    gfx->print(temperature2, 1);
    gfx->println("C");

    gfx->setCursor(10, 470);  // Set cursor position
    gfx->setTextSize(12);

    if (temperature3 >= -30 && temperature3 <= 0) {
        gfx->setTextColor(CYAN); // Cyan for temperatures around 0°C
    } else if (temperature3 > 0 && temperature3 <= 25) {
        gfx->setTextColor(GREEN); // Green for cool temperatures
    } else if (temperature3 > 25 && temperature3 <= 35) {
        gfx->setTextColor(ORANGE); // Orange for moderate temperatures
    } else if (temperature3 > 35 && temperature3 <= 40) {
        gfx->setTextColor(YELLOW); // Yellow for warm temperatures
    } else {
        gfx->setTextColor(RED); // Red for hot temperatures
    }

    gfx->print(temperature3, 1);
    gfx->println("C");

    gfx->setCursor(10, 580);  // Set cursor position
    gfx->setTextColor(WHITE);
    gfx->setTextSize(13);

    if (humidity2 < 30) {
        gfx->setTextColor(BLUE);  // Low humidity
    } else if (humidity2 >= 30 && humidity2 < 60) {
        gfx->setTextColor(GREEN);  // Normal humidity
    } else if (humidity2 >= 60 && humidity2 < 80) {
        gfx->setTextColor(YELLOW);  // Moderate humidity
    } else {
        gfx->setTextColor(RED);  // High humidity
    }

    gfx->print(humidity2);
    gfx->println("%");

    gfx->setTextColor(WHITE);
    gfx->setCursor(10, 690);  // Set cursor position
    gfx->setTextSize(2);

    if (batterystate2 == "low") {
        gfx->setTextColor(RED);
        gfx->print("Battery State Sensor 2");
    } else if (batterystate2 == "medium") {
        gfx->setTextColor(YELLOW);
        gfx->print("Battery State Sensor 2");
    } else if (batterystate2 == "high") {
        gfx->setTextColor(GREEN);
        gfx->print("Battery State Sensor 2");
    } else {
        gfx->setTextColor(WHITE);
        gfx->print("Battery State Sensor 2 Error");
    }

    gfx->setTextColor(WHITE);
    gfx->setCursor(10, 720);  // Set cursor position
    gfx->setTextSize(2);

    if (batterystate3 == "low") {
        gfx->setTextColor(RED);
        gfx->print("Battery State Sensor 3");
    } else if (batterystate3 == "medium") {
        gfx->setTextColor(YELLOW);
        gfx->print("Battery State Sensor 3");
    } else if (batterystate3 == "high") {
        gfx->setTextColor(GREEN);
        gfx->print("Battery State Sensor 3");
    } else {
        gfx->setTextColor(WHITE);
        gfx->print("Battery State Sensor 3 Error");
    }

}