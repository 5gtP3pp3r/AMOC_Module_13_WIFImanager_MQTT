#pragma once
#include <Arduino.h>
#include "Task.h"
#include "../Actions/Action.h"
#include "../const.h"

class Button : public Task{
protected:
    uint8_t m_pin;
    uint8_t m_buttonState;
    uint8_t m_lastButtonState;
    uint8_t m_lastButtonStableState;

    uint64_t m_actualTime;
    uint64_t m_lastTimeChange;
    uint8_t m_actionDelayMS;
    Action* m_action;
public:
    Button( 
        uint8_t p_pin,
        uint8_t p_actionDelayMS,
        Action* p_action
        );
    void tick() override;
};
 