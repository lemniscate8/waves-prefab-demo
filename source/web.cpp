//  This file is part of waves-prefab-demo
//  Copyright (C) Tait Weicht, 2021.
//  Released under MIT license; see LICENSE

#include <iostream>
#include <math.h>

#include "emp/web/web.hpp"
#include "emp/web/Button.hpp"
#include "emp/web/Div.hpp"
#include "emp/web/Element.hpp"
#include "emp/prefab/ReadoutPanel.hpp"
#include "emp/tools/string_utils.hpp"

#include "waves-prefab-demo/config_setup.hpp"
#include "waves-prefab-demo/example.hpp"
#include "waves-prefab-demo/DemoConfig.hpp"

emp::web::Document doc("emp_base");
waves_prefab_demo::Config cfg;

emp::vector<int> random_walker({0,0});
void take_step(emp::vector<int> & pt, bool diag=false);
double distance(emp::vector<int> & pt);

int main()
{
  // ----- Step to the tune -----
  emp::web::Div step{"step"};
  doc << step;
  step << emp::web::Button([]() {
    take_step(random_walker, cfg.ALLOW_DIAGONALS());
    std::cout << random_walker[0] << " " << random_walker[1] << std::endl;
  }, "Step!");

  // ----- Basic buttons -----
  emp::web::Div click{"click"};
  doc << click;
  click << "<hr>";
  emp::web::Element live{"span", "live"};
  click << emp::web::Button([live]() mutable {
    live.Redraw();
  }, "Show me");
  live << emp::web::Live(random_walker);
  click << live;


  // ----- Readout panel -----
  emp::web::Div readout{"readout"};
  doc << readout;
  readout << "<hr>";
  emp::prefab::ReadoutPanel stats{"Stats", 250};
  stats.AddValues(
    "Position", "the xy-coordinates of the random walker",
    random_walker,
    "Distance", "distance from the origin",
    []() { return distance(random_walker); }
  );
  readout << stats;

  // ----- Config panel -----
  emp::web::Div config{"config"};
  doc << config;
  config << "<hr>";

  setup_config_web(cfg);
  cfg.Write(std::cout);
  emp::prefab::ConfigPanel config_panel(cfg, false, "pconfig");
  config_panel.SetRange("SEED", "-1", "100", "1");
  config << config_panel;
  srand(cfg.SEED());

  // ----- Presentation management -----
  if(cfg.HIDE_STEP()) {
    step.SetCSS("display", "none");
  }
  if(cfg.HIDE_CLICK()) {
    click.SetCSS("display", "none");
  }
  if(cfg.HIDE_READOUT()) {
    readout.SetCSS("display", "none");
  }
  if(cfg.HIDE_CONFIG()) {
    config.SetCSS("display", "none");
  }
  if(cfg.HIDE_SUPER_SECRET()) {
    config_panel.ExcludeGroup("PRESENTATION");
  }

  std::cout << "Hello, console!" << std::endl;
  return 0;
}

void take_step(emp::vector<int> & pt, bool diag) {
  int main = (rand() % 2) ? 1 : -1;
  if(diag) {
    int secondary = (rand() < .5) ? 1 : -1;
    if(rand() % 2) {
      pt[1] = main;
      pt[1] += secondary;
    } else {
      int index = (rand() < .5) ? 0 : 1;
      pt[index] = main;
    }
  } else {
    int index = (rand() < .5) ? 0 : 1;
    pt[index] += main;
  }
}

double distance(emp::vector<int> & pt) {
  return sqrt(pt[0]*pt[0] + pt[1]*pt[1]);
}
