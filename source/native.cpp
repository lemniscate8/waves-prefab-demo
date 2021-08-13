//  This file is part of waves-prefab-demo
//  Copyright (C) Tait Weicht, 2021.
//  Released under MIT license; see LICENSE

#include <iostream>

#include "emp/base/vector.hpp"

#include "waves-prefab-demo/config_setup.hpp"
#include "waves-prefab-demo/example.hpp"
#include "waves-prefab-demo/ExampleConfig.hpp"

// This is the main function for the NATIVE version of waves-prefab-demo.

waves_prefab_demo::Config cfg;

int main(int argc, char* argv[])
{ 
  // Set up a configuration panel for native application
  setup_config_native(cfg, argc, argv);
  cfg.Write(std::cout);

  std::cout << "Hello, world!" << "\n";

  return example();
}
