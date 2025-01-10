#pragma once 
#include <Arduino.h>
#include <WiFiManager.h>
#include <uri/UriRegex.h>
#include "const.h"
#include "JSONManager.h"

class WIFI_Manager {
private:   
    char const* m_portalSSID;
    char const* m_portalPassWord;
    IPAddress m_portalIP;
    IPAddress m_gatewayIP;
    IPAddress m_portalMask;
    WiFiManager m_WiFiManager;
    WebServer m_webServer;
    WiFiManagerParameter m_customParameters;
    uint8_t m_timeout;
    bool m_debugOutput;
    JSONManager* m_JSONManager;
    void setupManager();

public:
    WIFI_Manager(
        char const* p_portalSSID,
        char const* p_portalPassWord,
        IPAddress p_portalIP,
        IPAddress p_gatewayIP,
        IPAddress p_portalMasck,
        WiFiManagerParameter p_customParameters,
        uint8_t p_timeout,   
        JSONManager* p_JSONManager
        );
    void toggleDebugMode();
    void startConfigPortal();
    void eraseConfig();
    void tick();
};
