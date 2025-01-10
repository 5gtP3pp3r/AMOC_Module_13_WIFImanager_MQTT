#include "Tasks/Button.h"

class StartConfigButton : public Button {
public:
    StartConfigButton(
        uint8_t p_pin,
        uint8_t p_actionDelayMS,
        Action *p_action
        );
    void tick() override;
};