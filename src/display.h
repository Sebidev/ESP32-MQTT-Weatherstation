#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino_GFX_Library.h>

// Deklariere die Funktionen, die du in display.cpp definierst
void show_noWifi();
void show_waitsync();
void show_sensorvalue(String topic, float temperature, int humidity, String batterystate);

#endif // DISPLAY_H
