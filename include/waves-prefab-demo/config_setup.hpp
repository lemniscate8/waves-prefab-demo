#pragma once

#include <filesystem>

#include "emp/config/ArgManager.hpp"
#include "emp/prefab/ConfigPanel.hpp"
#include "emp/web/UrlParams.hpp"
#include "emp/web/web.hpp"

#include "waves-prefab-demo/DemoConfig.hpp"

void use_existing_config_file(waves_prefab_demo::Config & config, emp::ArgManager & am) {
  if(std::filesystem::exists("waves-prefab-demo.cfg")) {
    std::cout << "Configuration read from waves-prefab-demo.cfg" << "\n";
    config.Read("waves-prefab-demo.cfg");
  }
  am.UseCallbacks();
  if (am.HasUnused())
    std::exit(EXIT_FAILURE);
}

void setup_config_web(waves_prefab_demo::Config & config)  {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  use_existing_config_file(config, am);
}

void setup_config_native(waves_prefab_demo::Config & config, int argc, char* argv[]) {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(argc, argv, specs);
  use_existing_config_file(config, am);
}

