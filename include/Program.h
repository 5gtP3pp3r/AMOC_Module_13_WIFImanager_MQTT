#pragma once
#include <Arduino.h>
#include <WIFI_Manager.h>
#include "Actions/ActionResetWIFIManager.h"
#include "Actions/ActionStartConfigPortal.h"
#include "Tasks/Button.h"
#include "Tasks/ResetButton.h"
#include "Tasks/StartConfigButton.h"
#include "config.h"
#include "JSONManager.h"

class Program {
private:
    JSONManager* m_JSONManager;
    WIFI_Manager* m_WIFIManager;
    Action* m_actionResetWIFIManager;
    Action* m_actionStartConfig;
    Button* m_resetButton;
    Button* m_configButton;
public:
    Program();
    void loop();
};
