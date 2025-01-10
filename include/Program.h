#pragma once
#include <Arduino.h>
#include <WIFI_Manager.h>
#include "Actions/ActionResetWIFIManager.h"
#include "Tasks/ResetButton.h"
#include "config.h"
#include "JSONManager.h"

class Program {
private:
    JSONManager* m_JSONManager;
    WIFI_Manager* m_WIFIManager;
    ActionResetWIFIManager* m_ActionResetWIFIManager;
    ResetButton* m_ResetButton;
public:
    Program();
    void loop();
};
