#pragma once
#include <Arduino.h>
#include <WiFiManager.h>

#define PORTAL_SSID "ConfigurationESP32"
#define PORTAL_PASSWWORD "Pouet&666"
#define TIMEOUT 180
#define PORTAL_IP (192, 168, 23, 1)
#define GATEWAY_IP (192, 168, 23, 1)
#define PORTAL_MASK (255, 255, 255, 0)

#define PARAM_1 "Identifiant_unique_champ"
#define PARAM_2 "Nom du champ"
#define PARAM_3 "ValeurQuiEtaitSauvegardee"
#define PARAM_4 40
