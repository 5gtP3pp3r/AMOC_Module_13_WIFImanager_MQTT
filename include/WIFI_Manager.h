#pragma once 
#include <Arduino.h>
#include <WiFiManager.h>
#include <uri/UriRegex.h>
#include "const.h"

class WIFI_Manager {
private:   
    char const* m_portalSSID;
    char const* m_portalPassWord;
    IPAddress m_portalIP;
    IPAddress m_gatewayIP;
    IPAddress m_portalMask;
    WiFiManager m_WiFiManager;
    WebServer m_webServer;
    WiFiManagerParameter m_custmParameters;
    uint8_t m_timeout;
    bool m_debugOutput;
    void setupManager();

public:
    WIFI_Manager(
        char const* p_portalSSID,
        char const* p_portalPassWord,
        IPAddress p_portalIP,
        IPAddress p_gatewayIP,
        IPAddress p_portalMasck,
        WiFiManagerParameter p_custmParameters,
        uint8_t p_timeout      
        );
    void toggleDebugMode();
    void startConfigPortal();
    void eraseConfig();
    void tick();
};
