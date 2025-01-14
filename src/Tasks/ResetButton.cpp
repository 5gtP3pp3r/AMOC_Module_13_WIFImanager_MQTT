#include "Tasks/ResetButton.h"

ResetButton::ResetButton(
    uint8_t p_pin,
    uint8_t p_actionDelayMS,
    Action* p_action
    ) : Button(p_pin, p_actionDelayMS, p_action) { ; }

void ResetButton::tick() {
    
    this->m_buttonState = digitalRead(this->m_pin);
    this->m_actualTime = millis();
    if (this->m_buttonState != this->m_lastButtonState) {
        this->m_lastTimeChange = this->m_actualTime;
        this->m_lastButtonState = this->m_buttonState;
    }
    if (this->m_actualTime - this->m_lastTimeChange >  this->m_actionDelayMS) {
        if (this->m_lastButtonStableState == LOW && this->m_buttonState == HIGH) {
            Serial.println("BoutonReset");
            Serial.print("Adresse de m_actionResetWIFIManager : ");
            Serial.println((uintptr_t)m_action, HEX);
            this->m_action->execute();
        }
        this->m_lastButtonStableState = this->m_buttonState;
    }
}
