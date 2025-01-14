/**
 * \file ShowerRecoModuleBase.h
 *
 * \ingroup SuperaLight
 *
 * \brief Class def header for a class ShowerRecoModuleBase
 *
 * @author cadams
 */

/** \addtogroup ModularAlgo

    @{*/
#ifndef GALLERY_FMWK_SUPERA_MODULE_BASE_H
#define GALLERY_FMWK_SUPERA_MODULE_BASE_H

#include <iostream>

#include "canvas/Utilities/InputTag.h"
#include "gallery/Event.h"
#include "canvas/Persistency/Common/FindMany.h"

#include "Analysis/ana_base.h"

#include "larcv3/core/dataformat/IOManager.h"
#include "larcv3/core/dataformat/ImageMeta.h"

/**
   \class ShowerRecoModuleBase
   User defined class ShowerRecoModuleBase ... these comments are used to generate
   doxygen documentation!
 */
namespace supera {

class SuperaModuleBase {

public:

    /// Default constructor
    SuperaModuleBase();

    /// Default destructor
    ~SuperaModuleBase() {}

    /**
     * @brief get the name of this module, used in helping organize order of modules and insertion/removal
     * @return name
     */
    std::string name() {return _name;}

    /**
     * @brief Virtual function that is overridden in child class,
     * does the slicing work.
     *
     */
    void slice(gallery::Event * ev, larcv3::IOManager & io){};

    /**
     * @brief Verbosity setter function for each Modular Algo
     */
    void setVerbosity(bool on) { _verbose = on; }

    /**
     * @brief Function to initialize the algorithm (such as setting up tree)
     */
    void initialize(){}



protected:

    int projection_id(int channel);
    int column(int channel);
    int row(int tick, int channel);
    float wire_position(float x, float y, float z, int projection_id);
    float tick_position(float x, float time_offset, int projection_id);
 
    /*
    int n_ticks_per_chamber = 2500;
    int n_cathode_ticks = 110;
    int compression = 5;
    int tick_offset = 2500;*/ 

    int n_ticks_per_chamber =  7000;
    int n_cathode_ticks = 0; // This only applies to SBND 
    int compression = 6;
    int tick_offset = 2400;

    int total_ticks = -1;

    // int _max_tick;

    std::string _name;

    std::string _fcl_file_name = "$GALLERY_FMWK_BASEDIR/core/LArUtil/dat/services_microboone.fcl";

    std::vector<larcv3::ImageMeta2D> _base_image_meta_2D;
    larcv3::ImageMeta3D _base_image_meta_3D;


    bool _verbose;



};

} // showerreco

#endif
/** @} */ // end of doxygen group
