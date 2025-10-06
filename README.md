# ROOT Utilities for ROOT Files

This repository provides general-purpose ROOT scripts for analyzing `.root` files in high-energy physics (HEP) workflows.

## Script Overview

| Script                             | Description                                      |
|------------------------------------|--------------------------------------------------|
| `findBranches.cc`                  | Lists all branch names in a ROOT file            |
| `findDataType.cc`                  | Lists branch names along with data types         |
| `findFinalStateParticles.cc`       | Finds branches representing final state particles|
| `findTreeName.cc`                  | Extracts the TTree name from a ROOT file         |
| `loopEvents.cc`                    | Loops over all events in a TTree                 |
| `plotBranchHistogram.cc`          | Plots histogram of a single branch               |
| `plotMultipleBranchesHistogram.cc`| Plots histogram using two branches               |
| `findLeavesAndBranches.C`         | Prints all leaves and their paths                |
| `printBranchValues.C`             | Prints values from selected branches             |
| `ListRootFile.C`                  | Lists contents of a ROOT file                    |

## How to Run

```bash
root -l -b -q scriptname.cc
```

## ROOT + DUNE Environment Setup

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
setup cmake v3_24_0 
setup gcc v9_3_0 
setup root v6_22_08d -q e20:p392:prof
```

## 📝 Notes

- These scripts are modular and can be adapted for different `.root` structures
- ROOT version compatibility: Tested on v6.22.08
