#include "Program.h"

Program::Program() 
  : m_JSONManager(nullptr),
    m_WIFIManager(nullptr),
    m_actionResetWIFIManager(nullptr),
    m_actionStartConfig(nullptr),
    m_resetButton(nullptr),
    m_configButton(nullptr) {
        this->m_JSONManager = new JSONManager();
        WiFiManagerParameter p_customParameters(PARAM_1, PARAM_2, PARAM_3, PARAM_4);
        IPAddress p_portalIP(192, 168, 24, 1);
        IPAddress p_gateayIP(192, 168,24,1);
        IPAddress p_portalMask(255, 255, 255, 0);
        this->m_WIFIManager = new WIFI_Manager(
            PORTAL_SSID,
            PORTAL_PASSWWORD,
            p_portalIP,
            p_gateayIP,
            p_portalMask,
            p_customParameters,
            TIMEOUT,
            this->m_JSONManager
            );
        this->m_actionResetWIFIManager = new ActionResetWIFIManager(this->m_WIFIManager);
        this->m_actionStartConfig = new ActionStartConfigPortal(this->m_WIFIManager);
        this->m_resetButton = new ResetButton(
            BUTTON1_PIN,
            INTERVAL_40,
            this->m_actionResetWIFIManager
        );
        this->m_configButton = new StartConfigButton(
            BUTTON2_PIN,
            INTERVAL_40,
            this->m_actionStartConfig
        );

        Serial.print("Adresse de m_WIFIManager : ");
        Serial.println((uintptr_t)m_WIFIManager, HEX);
        Serial.print("Adresse de m_actionResetWIFIManager : ");
        Serial.println((uintptr_t)m_actionResetWIFIManager, HEX);
        Serial.print("Adresse de m_actionStartConfig : ");
        Serial.println((uintptr_t)m_actionStartConfig, HEX);

    }
void Program::loop() {
    this->m_WIFIManager->tick();
    this->m_resetButton->tick();
    this->m_configButton->tick();
}    
