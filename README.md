# Gallery Framework


## What is this?

This is a light framework that interfaces with gallery to read art-root files.  You have probably used larlite, which gives a light framework for reading and writing larlite format root files.  Gallery is a system to read art-root files, but doesn't provide any of the other useful tools you're used to.  You have to write your own event loop, build your code yourself, make sure to get all the linked libraries correct, etc.

This framework tries to help with that.  It interfaces with gallery to provide a larlite-style interface.  You write classes that extend from ana_base.h, just like in larlite.  Instead of receiving storage_manager, you receive gallery::Event.  You still have access to a lot of tools from larlite like GeometryHelper and LArUtils in general.

NOTE: This forked repo includes files to convert larsoft-root files to larcv (hdf5) files for the MicroBooNE experiment. For details about the TITUS event display see the original repo: https://github.com/TITUS-EVD/gallery-framework. 


## Requirements


1) You need gallery.  For right now, that requires ups products, which means it uses it's own gcc/python/root and not the ones on your laptop.  If you are on the gpvms, getting gallery is super simple.  On your laptop, visit scisoft.fnal.gov to get gallery.

2) You need larsoft data products: nusimdata, larcoreobj, lardataobj.  If you get gallery via ups, get these via ups too.

3) We're working on a way to build gallery and larsoftobj systems without ups, using your own gcc and such.  This will come out later.

4) If you want to have the display you'll need numpy and PyQt.  You can get numpy and qt5 through scisoft and ups as well.  PyQt5 you can install once qt5 is built and ready, just make sure to install it to the ups python area.



## How to build and install the framework


1) Set up gallery and larsoftobj.

2) Source the setup script: `source config/setup.sh`

3) make from the top area: `make -j`

4) Develop in the user dev area.
