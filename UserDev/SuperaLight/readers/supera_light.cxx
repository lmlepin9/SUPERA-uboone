#ifndef GALLERY_FMWK_SUPERA_CXX
#define GALLERY_FMWK_SUPERA_CXX

#include "supera_light.h"

#include "nusimdata/SimulationBase/MCTruth.h"

#include "uboone_rawdigit.h"

namespace supera {

bool supera_light::initialize() {

  raw_digit.initialize();
  wire.initialize();
  cluster.initialize();

  return true;
}

void supera_light::set_output_file(std::string outfile){
    _io.set_out_file(outfile);
    _io.initialize();
}

bool supera_light::analyze(gallery::Event* ev) {


  // Get the event ID information for this event:
  int run = ev->eventAuxiliary().run();
  int subrun = ev->eventAuxiliary().subRun();
  int event = ev->eventAuxiliary().event();

  raw_digit.slice(ev, _io);
  wire.slice(ev, _io);
  cluster.slice(ev, _io);

  // Save the event
  _io.set_id(run, subrun, event);
  _io.save_entry();

  return true;
}


bool supera_light::finalize() {

  _io.finalize();
  return true;
}
}
#endif
