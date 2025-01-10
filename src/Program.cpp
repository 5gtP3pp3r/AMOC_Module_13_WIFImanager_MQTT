#include "Program.h"

Program::Program() 
  : m_JSONManager(nullptr),
    m_WIFIManager(nullptr),
    m_ActionResetWIFIManager(nullptr),
    m_ResetButton(nullptr) {
        Serial.begin(SERIAL_SPEED);
        this->m_JSONManager = new JSONManager();
        WiFiManagerParameter p_customParameters(PARAM_1, PARAM_2, PARAM_3, PARAM_4);
        this->m_WIFIManager = new WIFI_Manager(
            PORTAL_SSID,
            PORTAL_PASSWWORD,
            PORTAL_IP,
            GATEWAY_IP,
            PORTAL_MASK,
            p_customParameters,
            TIMEOUT,
            this->m_JSONManager
            );
        this->m_ActionResetWIFIManager = new ActionResetWIFIManager(this->m_WIFIManager);
        this->m_ResetButton = new ResetButton(
            BUTTON1_PIN,
            INTERVAL_40,
            this->m_ActionResetWIFIManager
        );
    }
void Program::loop() {
    this->m_WIFIManager->tick();
    this->m_ResetButton->tick();
}    
