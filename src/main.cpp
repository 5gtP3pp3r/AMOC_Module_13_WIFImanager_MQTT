#include <Arduino.h>
#include "Program.h"

Program* program = nullptr;
void setup() {
    Serial.println("Initialisation...");
    delay(500);
    program = new Program();
    Serial.println("Programme initialisé");
 }

void loop() { 
    program->loop();
}
