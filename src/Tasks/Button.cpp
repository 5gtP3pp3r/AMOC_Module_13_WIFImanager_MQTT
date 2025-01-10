#include "Tasks/Button.h"

Button::Button(
    uint8_t p_pin,
    uint8_t p_actionDelayMS,
    Action* p_action
    ) :    
        m_pin(p_pin),
        m_buttonState(HIGH),
        m_lastButtonState(HIGH),
        m_lastButtonStableState(HIGH),
        m_actualTime(DEFAULT_ZERO),
        m_lastTimeChange(DEFAULT_ZERO),
        m_actionDelayMS(p_actionDelayMS),
        m_action(p_action) {
            pinMode(m_pin, INPUT);
        }
void Button::tick() {
    // this->m_buttonState = digitalRead(this->m_pin);
    // this->m_actualTime = millis();
    // if (this->m_buttonState != this->m_lastButtonState) {
    //     this->m_lastTimeChange = this->m_actualTime;
    //     this->m_lastButtonState = this->m_buttonState;
    // }
    // if (this->m_actualTime - this->m_lastTimeChange >  this->m_actionDelayMS) {
    //     if (this->m_lastButtonStableState == LOW && this->m_buttonState == HIGH) {
    //         this->m_action->execute();
    //     }
    //     this->m_lastButtonStableState = this->m_buttonState;
    // }
}  
