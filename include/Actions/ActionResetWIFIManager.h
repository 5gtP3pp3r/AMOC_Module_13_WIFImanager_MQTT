#pragma once
#include "WIFI_Manager.h"
#include "Action.h"

class ActionResetWIFIManager : public Action {
private:
    WIFI_Manager* m_WIFIManager;
public:
    ActionResetWIFIManager(WIFI_Manager* p_WIFIManager);
    void execute() override;
};