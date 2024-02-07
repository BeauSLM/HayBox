#ifndef _MODES_MELEE20BUTTONMLG_HPP
#define _MODES_MELEE20BUTTONMLG_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

typedef struct {
    bool crouch_walk_os = false;
} Melee20ButtonMLGOptions;

class Melee20ButtonMLG : public ControllerMode {
  public:
    Melee20ButtonMLG(socd::SocdType socd_type, Melee20ButtonMLGOptions options = {});

  protected:
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);

  private:
    Melee20ButtonMLGOptions _options;
    bool _horizontal_socd;

    void HandleSocd(InputState &inputs);
};

#endif
