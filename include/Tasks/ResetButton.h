#pragma once
#include <Arduino.h>
#include "Task.h"
#include "../Actions/ActionResetWIFIManager.h"
#include "../const.h"

class ResetButton : Task {
private:
    uint8_t m_pin;
    uint8_t m_buttonState;
    uint8_t m_lastButtonState;
    uint8_t m_lastButtonStableState;

    uint8_t m_actualTime;
    uint8_t m_lastTimeChange;
    uint8_t m_actionDelayMS;
    ActionResetWIFIManager* m_actionReset;
public:
    ResetButton( 
        uint8_t p_pin,
        uint8_t p_actionDelayMS,
        ActionResetWIFIManager* p_actionReset
    );
    void tick() override;
};