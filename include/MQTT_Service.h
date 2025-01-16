#pragma once
#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFiClient.h>
#include "config.h"
#include "const.h"

class MQTT_Service {
private:
    WiFiClient* m_espClient;
    PubSubClient* m_pubSubClient;
    String m_espUnique;
    uint64_t m_lastSentMessageTime;
    uint16_t m_interval;
    void setupMQTT();
    bool reconnectMQTTIfNeeded();
    void continuousMessageSending();    
public:
    MQTT_Service();   
    void tick();
};