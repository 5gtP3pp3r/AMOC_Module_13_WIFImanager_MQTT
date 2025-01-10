#include "Tasks/ResetButton.h"

ResetButton::ResetButton(
    uint8_t p_pin,
    uint8_t p_actionDelayMS,
    ActionResetWIFIManager* p_actionReset
    )
      : m_pin(p_pin),
        m_actionDelayMS(p_actionDelayMS),
        m_actionReset(p_actionReset),
        m_buttonState(HIGH),
        m_actualTime(DEFAULT_ZERO),
        m_lastTimeChange(DEFAULT_ZERO),
        m_lastButtonState(HIGH),
        m_lastButtonStableState(HIGH) {
            pinMode(this->m_pin,INPUT);
}

void ResetButton::tick() {
    this->m_buttonState = digitalRead(this->m_pin);
    this->m_actualTime = millis();
    if (this->m_buttonState != this->m_lastButtonState) {
        this->m_lastTimeChange = this->m_actualTime;
        this->m_lastButtonState = this->m_buttonState;
    }
    if (this->m_actualTime - this->m_lastTimeChange >  this->m_actionDelayMS) {
        if (this->m_lastButtonStableState == LOW && this->m_buttonState == HIGH) {
           this->m_actionReset->execute();
        }
        this->m_lastButtonStableState = this->m_buttonState;
    }
}