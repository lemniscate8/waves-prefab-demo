#pragma once

#include "emp/config/config.hpp"

namespace waves_prefab_demo {

  EMP_BUILD_CONFIG(Config,
    GROUP(WALK, "Random walk settings"),
    VALUE(SEED, int, -1, "Seed for random in simulation"),
    VALUE(ALLOW_DIAGONALS, bool, false, "Allow the walker to travel on diagonals"),
    GROUP(SIMULATION, "Simulation settings"),
    VALUE(N_STEPS, int, 5, "Number of steps to take every time"),
    VALUE(NAME, std::string, "Owl-face", "Name of the random walker"),
    GROUP(PRESENTATION, "Presentation controls"),
    VALUE(HIDE_STEP, bool, false, "Hides the step button"),
    VALUE(HIDE_CLICK, bool, false, "Hides the click button and readout div"),
    VALUE(HIDE_READOUT, bool, false, "Hides the readout panel"),
    VALUE(HIDE_CONFIG, bool, false, "Hides the config panel"),
    VALUE(HIDE_SUPER_SECRET, bool, false, "Hides this group in the config"),
  );
}
