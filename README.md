# rootCern

### This repository contains some general root scripts.

- `findBranches.cc` This is to find branch names in a root file. 
- `findDataType.cc` This is to find branch names and their data types in a root file. 
- `findFinalStateParticles.cc` This is to find branch names in a root file. 
- `findTreeName.cc` This is to find tree name in a root file. 
- `loopEvents.cc` This is to loop over all events in a root file. 
- `plotBranchHistogram.cc` This is to plot histogram of a branch. 
- `plotMultipleBranchesHistogram.cc` This is to plot histogram of two branches. 


### To run these files, use:
```bash
root -l -b -q filename.cc
```

### To install root and other scripts, use:
```bash
export LANGUAGE=en_US.UTF-8 
export LC_ALL=en_US.UTF-8 
export LANG=en_US.UTF-8 
export LC_CTYPE=en_US.UTF-8 

source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh 
setup duneutil v09_63_00d00 -q e20:prof 
setup_fnal_security 

setup ifdhc 
setup jobsub_client 
setup pycurl 
setup cmake	v3_24_0 
setup gcc v9_3_0 
setup root v6_22_08d -q e20:p392:prof
```
