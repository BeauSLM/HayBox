#include "modes/FgcMode.hpp"

FgcMode::FgcMode(socd::SocdType horizontal_socd, socd::SocdType vertical_socd) {
    _socd_pair_count = 4;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left,   &InputState::right, horizontal_socd         },
 /* Mod X override C-Up input if both are pressed. Without this, neutral SOCD doesn't work
  properly if Down and both Up buttons are pressed, because it first resolves Down + Mod X
  to set both as unpressed, and then it sees C-Up as pressed but not Down, so you get an up
  input instead of neutral. */
        socd::SocdPair{ &InputState::mod_x, &InputState::c_up,  socd::SOCD_DIR1_PRIORITY},
        socd::SocdPair{ &InputState::down,  &InputState::mod_x, vertical_socd           },
        socd::SocdPair{ &InputState::down,  &InputState::up2,   vertical_socd           },
        socd::SocdPair{ &InputState::down,  &InputState::c_up,  vertical_socd           },
    };
}

void FgcMode::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x || inputs.up2 || inputs.c_up; // Mod X and Up2-W are mapped to Dpad Up

    // L Key, Mod Y, and Right Thumb keys
    outputs.leftStickClick = inputs.l || inputs.c_left;         // L now mapped to L3
    outputs.rightStickClick = inputs.a;                         // C Left now mapped to R3

    // Menu keys
    outputs.start = inputs.start;
    outputs.select = inputs.select;                             // Select now mapped to Select instead of the button it was before
    outputs.home = inputs.home;                                 // Home now mapped to Home instead of the button it was before

    // Right hand bottom row
    outputs.a = inputs.b;
    outputs.b = inputs.x;
    outputs.triggerLDigital = inputs.z;                         // Swapped Trigger from Right to Left
    outputs.triggerRDigital = inputs.up;                        // Swapped Trigger from Left to Right

    // Right hand top row
    outputs.x = inputs.r;
    outputs.y = inputs.y;
    outputs.buttonL = inputs.lightshield;                       // Swapped Bumper from Right to Left
    outputs.buttonR = inputs.midshield;                         // Swapped Bumper from Left to Right
}

void FgcMode::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
}
