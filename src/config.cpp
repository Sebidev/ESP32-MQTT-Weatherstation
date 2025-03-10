#include "config.h"

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
    41 /* DE */, 40 /* VSYNC */, 39 /* HSYNC */, 42 /* PCLK */,
    14 /* R0 */, 21 /* R1 */, 47 /* R2 */, 48 /* R3 */, 45 /* R4 */,
    9 /* G0 */, 46 /* G1 */, 3 /* G2 */, 8 /* G3 */, 16 /* G4 */, 1 /* G5 */,
    15 /* B0 */, 7 /* B1 */, 6 /* B2 */, 5 /* B3 */, 4 /* B4 */,
    0 /* hsync_polarity */, 180 /* hsync_front_porch */, 30 /* hsync_pulse_width */, 16 /* hsync_back_porch */,
    0 /* vsync_polarity */, 12 /* vsync_front_porch */, 13 /* vsync_pulse_width */, 10 /* vsync_back_porch */);
    
Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
    800 /* width */, 480 /* height */, rgbpanel, 1 /* rotation */, true /* auto_flush */);

const char* wifi_ssid = "your_ssid";
const char* wifi_password = "your_password";
const char* mqtt_server = "your_mqtt_server";
const char* mqtt_user = "your_mqtt_user";
const char* mqtt_userpassword = "your_mqtt_password";

const char* ts1_topic = "zigbee2mqtt/Außensensor";
const char* ts2_topic = "zigbee2mqtt/Wohnzimmer_Sensor";
const char* ts3_topic = "zigbee2mqtt/Sebis_Sensor";
