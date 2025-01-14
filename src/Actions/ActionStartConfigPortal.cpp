#include "Actions/ActionStartConfigPortal.h"

ActionStartConfigPortal::ActionStartConfigPortal(
    WIFI_Manager* p_WIFIManager
    ) 
      : m_WIFIManager(p_WIFIManager) { ; }

void ActionStartConfigPortal::execute() {
    Serial.println("ActionStartConfigPortal");
    Serial.print("Adresse de m_WIFIManager : ");
    Serial.println((uintptr_t)m_WIFIManager, HEX);
    m_WIFIManager->startConfigPortal(); 
}
