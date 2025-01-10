#pragma once
#include "WIFI_Manager.h"
#include "Action.h"

class ActionStartConfigPortal : public Action {
private:
    WIFI_Manager* m_WIFIManager;
public:
    ActionStartConfigPortal(WIFI_Manager* p_WIFIManager);
    void execute() override;
};