#!/bin/bash
# Script to submit a job to the fermigrid using jobsub 
# It sets a custom singularity image by defaul. The singularity image is availabl through the /cvmfs repository 



jobsub_submit --resource-provides=usage_model=DEDICATED,OPPORTUNISTIC \
	      --role=Analysis \
	      --expected-lifetime=1h  \
	      --append_condor_requirements='(TARGET.HAS_SINGULARITY=?=true)' \
	      --lines='+SingularityImage=\"/cvmfs/singularity.opensciencegrid.org/lmlepin9/slf7-ubcode-gallery-fmwk:latest\"' \
	      --memory 15GB \
	      --disk 15GB \
	      -d DARKTRIDENT /pnfs/uboone/scratch/users/lmoralep \
	      -G uboone \
	      -L /pnfs/uboone/scratch/users/lmoralep/log_test.log \
	      file://test_singularity.sh 