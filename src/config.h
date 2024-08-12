#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino_GFX_Library.h>

extern Arduino_ESP32RGBPanel *rgbpanel;
extern Arduino_RGB_Display *gfx;

extern const char* wifi_ssid;
extern const char* wifi_password;
extern const char* mqtt_server;
extern const char* mqtt_user;
extern const char* mqtt_userpassword;

extern const char* ts1_topic;
extern const char* ts2_topic;
extern const char* ts3_topic;

#endif // CONFIG_H
