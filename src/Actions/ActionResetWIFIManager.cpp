#include "Actions/ActionResetWIFIManager.h"

ActionResetWIFIManager::ActionResetWIFIManager(
    WIFI_Manager* p_WIFIManager
    ) 
      : m_WIFIManager(p_WIFIManager) { ; }

void ActionResetWIFIManager::execute() {
   Serial.println("ActionResetWIFIManager");
   Serial.print("Adresse de m_WIFIManager : ");
   Serial.println((uintptr_t)m_WIFIManager, HEX);
   m_WIFIManager->eraseWIFIConfig();
}