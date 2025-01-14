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
#ifndef GALLERY_FMWK_SUPERA_UBOONE_CLUSTER_H
#define GALLERY_FMWK_SUPERA_UBOONE_CLUSTER_H

#include "supera_module_base.h"

#include "larcv3/core/dataformat/ImageMeta.h"


/**
   \class ShowerRecoModuleBase
   User defined class ShowerRecoModuleBase ... these comments are used to generate
   doxygen documentation!
 */
namespace supera {

class ubooneCluster : SuperaModuleBase {

public:

    /// Default constructor
    ubooneCluster(){_name = "ubooneCluster";_verbose=false;}

    /// Default destructor
    ~ubooneCluster() {}

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
    void slice(gallery::Event * ev, larcv3::IOManager & io);

    /**
     * @brief Function to initialize the algorithm (such as setting up tree)
     */
    void initialize();

protected:

    /*
    Builds the map of particles from geant trackIDs to a list of particles in
    the larcv3 world
    */
    void build_particle_map(gallery::Event * ev, larcv3::IOManager & io);

    std::vector< std::vector< int> > _particle_to_trackID;
    std::map< int, int > _trackID_to_particle;


    std::string _name;

    bool _verbose;



};

} // showerreco

#endif
/** @} */ // end of doxygen group
