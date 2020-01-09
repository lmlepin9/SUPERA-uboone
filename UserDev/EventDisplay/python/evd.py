#!/usr/bin/env python
import ROOT
ROOT.PyConfig.IgnoreCommandLineOptions = True
ROOT.gROOT.ProcessLine("gErrorIgnoreLevel = kError;")


from gui import evdgui
import argparse
import sys
import signal
from pyqtgraph.Qt import QtGui, QtCore


from ROOT import evd

from evdmanager import geometry, evd_manager_2D

try:
    import SBNDservices
    geometryCore    = SBNDservices.ServiceManager('Geometry')
    detProperties   = SBNDservices.ServiceManager('DetectorProperties')
    detClocks       = SBNDservices.ServiceManager('DetectorClocks')
    lar_properties  = SBNDservices.ServiceManager('LArProperties')
except:
    pass

try:
    import ICARUSservices
    geometryCore    = ICARUSservices.ServiceManager('Geometry')
    detProperties   = ICARUSservices.ServiceManager('DetectorProperties')
    detClocks       = ICARUSservices.ServiceManager('DetectorClocks')
    lar_properties  = ICARUSservices.ServiceManager('LArProperties')
except:
    pass


# This is to allow key commands to work when focus is on a box




def sigintHandler(*args):
    """Handler for the SIGINT signal."""
    sys.stderr.write('\r')
    sys.exit()


def main():

    parser = argparse.ArgumentParser(description='Python based event display.')
    geom = parser.add_mutually_exclusive_group()
    geom.add_argument('-A', '-a', '--argoneut',
                      action='store_true',
                      help="Run with the argoneut geometry")
    geom.add_argument('-U', '-u', '--uboone',
                      action='store_true',
                      help="Run with the microboone geometry")
    geom.add_argument('-T', '-t', '--uboonetruncated',
                      action='store_true',
                      help="Run with the truncated microboone geometry")
    geom.add_argument('-S', '-s', '--sbnd',
                      action='store_true',
                      help="Run with the SBND Geometry")
    geom.add_argument('-I', '-i', '--icarus',
                      action='store_true',
                      help="Run with the ICARUS Geometry")
    geom.add_argument('-L', '-l', '--lariat',
                      action='store_true',
                      help="Run with the lariat geometry")
    parser.add_argument('file', nargs='*', help="Optional input file to use")

    args = parser.parse_args()

    app = QtGui.QApplication(sys.argv)

    if args.uboone:
        geom = geometry.microboone()
    elif args.uboonetruncated:
        geom = geometry.microboonetruncated()
    elif args.lariat:
        geom = geometry.lariat()
    elif args.sbnd:
        geom = geometry.sbnd(geometryCore,detProperties,detClocks,lar_properties)
    elif args.icarus:
        geom = geometry.icarus()
    else:
        geom = geometry.argoneut()

    # If a file was passed, give it to the manager:

    manager = evd_manager_2D(geom)
    manager.setInputFiles(args.file)


    thisgui = evdgui(geom, manager, app)
    # manager.goToEvent(0)

    signal.signal(signal.SIGINT, sigintHandler)
    timer = QtCore.QTimer()
    timer.start(500)  # You may change this if you wish.
    timer.timeout.connect(lambda: None)  # Let the interpreter run each 500 ms.

    app.exec_()
    # sys.exit(app.exec_())


if __name__ == '__main__':
    main()
