#include "Tasks/Button.h"

class ResetButton : public Button {
public:
    ResetButton(
        uint8_t p_pin,
        uint8_t p_actionDelayMS,
        Action *p_action
        );
    void tick() override;
};
