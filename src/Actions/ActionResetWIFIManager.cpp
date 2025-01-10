#include "Actions/ActionResetWIFIManager.h"

ActionResetWIFIManager::ActionResetWIFIManager(
    WIFI_Manager* p_WIFIManager
    ) 
      : m_WIFIManager(p_WIFIManager) { ; }

 void ActionResetWIFIManager::execute() {
    m_WIFIManager->eraseConfig();
 }