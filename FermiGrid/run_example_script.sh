#!/bin/bash
echo 
echo "======= Setting up singularity container ====== " 
pwd 

source /products/setup
setup uboonecode v09_00_00 -q e19:prof
unsetup larlite -j -j
unset PYTHONPATH
source /software/ubcode/bin/activate
pip list 

echo "===== DONE...========"