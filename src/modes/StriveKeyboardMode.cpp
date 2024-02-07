#include "modes/StriveKeyboardMode.hpp"

#include "core/socd.hpp"
#include "core/state.hpp"

StriveKeyboardMode::StriveKeyboardMode(socd::SocdType socd_type) {
    _socd_pair_count = 1;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
    };
}

void StriveKeyboardMode::UpdateKeys(InputState &inputs) {
    Press(HID_KEY_E, inputs.l);             // E        = ...               = ...
    Press(HID_KEY_A, inputs.left);          // A        = Left              = Left
    Press(HID_KEY_S, inputs.down);          // S        = Down              = Down
    Press(HID_KEY_D, inputs.right);         // D        = Right             = Right
    Press(HID_KEY_W, inputs.up2);           // W        = Up                = Up
    Press(HID_KEY_SPACE, inputs.mod_x);     // Space    = No Menu           = Position Reset
    Press(HID_KEY_F, inputs.mod_y);         // F        = ...               = ...  
    Press(HID_KEY_Z, inputs.select);        // Z        = ...               = ...
    Press(HID_KEY_X, inputs.home);          // X        = ...               = ...
    Press(HID_KEY_ENTER, inputs.start);     // Enter    = Enter             = Pause
    Press(HID_KEY_U, inputs.r);             // U        = Select/Okay       = Punch
    Press(HID_KEY_I, inputs.y);             // I        = Display Menu      = Slash
    Press(HID_KEY_O, inputs.lightshield);   // O        = Return            = Dust
    Press(HID_KEY_P, inputs.midshield);     // P        = ...               = ...
    Press(HID_KEY_J, inputs.b);             // J        = Filter            = Kick
    Press(HID_KEY_K, inputs.x);             // K        = Prev Page         = Heavy Slash 
    Press(HID_KEY_L, inputs.z);             // L        = Next Page         = ...
    Press(HID_KEY_V, inputs.up);            // V        = Toggle News       = ...
    Press(HID_KEY_H, inputs.c_up);          // H        = Battle Settings   = ...
    Press(HID_KEY_M, inputs.c_left);        // M        = Change Sort       = ...
    Press(HID_KEY_B, inputs.c_right);       // B        = Change Name       = ...
    Press(HID_KEY_Q, inputs.a);             // Q        = ...               = Dash Macro
    Press(HID_KEY_N, inputs.c_down);        // N        = Sub Menu          = ...
}                                           //|Output  | Default in Menu   | Default in Game
