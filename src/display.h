#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino_GFX_Library.h>

void show_noWifi();
void show_waitsync();
void show_sensorvalue(String topic1, float temperature1, int humidity1, String batterystate1, String topic2, float temperature2, float temperature3,int humidity2, String batterystate2, String batterystate3);

#endif // DISPLAY_H
