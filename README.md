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

## ROOT + DUNE Environment Setup (DUNEGPVM)

```bash
# Step 1: Login to DUNE GPVM
kinit mazam@FNAL.GOV      
ssh -KY mazam@dunegpvm13.fnal.gov

# Step 2.1: Running SL7 inside a container
/cvmfs/oasis.opensciencegrid.org/mis/apptainer/current/bin/apptainer shell --shell=/bin/bash \
-B /cvmfs,/exp,/nashome,/pnfs/dune,/opt,/run/user,/etc/hostname,/etc/hosts,/etc/krb5.conf --ipc --pid \
/cvmfs/singularity.opensciencegrid.org/fermilab/fnal-dev-sl7:latest

# Step 2.2: If you plan to use UPS inside SL7 container
export UPS_OVERRIDE="-H Linux64bit+3.10-2.17"

# Step 3: Navigate to your directory
cd /exp/dune/app/users/mazam/production/CAFs/MiniRun6.1

# Step 4: Setup DUNE and required packages
source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
setxkbmap us
setup cmake v3_22_2
setup gcc v9_3_0
setup pycurl
setup ifdhc
setup geant4 v4_11_0_p01c -q e20:debug
setup dk2nugenie   v01_10_01k -q debug:e20
setup genie_xsec   v3_04_00 -q AR2320i00000:e1000:k250
setup genie_phyopt v3_04_00 -q dkcharmtau
setup jobsub_client
setup eigen v3_3_5
setup duneanaobj v03_02_01 -q e20:prof
setup hdf5 v1_10_5a -q e20
setup fhiclcpp v4_15_03 -q debug:e20

# GEANT + DUNEANOBJ environment adjustments
G4_cmake_file=`find ${GEANT4_FQ_DIR}/lib -name 'Geant4Config.cmake'`
export Geant4_DIR=`dirname $G4_cmake_file`
export PATH=$PATH:$GEANT4_FQ_DIR/bin
export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$GENIE_INC/GENIE
export PYTHONPATH=${PYTHONPATH}:${PWD}/DUNE_ND_GeoEff/lib/
export LD_LIBRARY_PATH=${DUNEANAOBJ_LIB}:$LD_LIBRARY_PATH
mydir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
export LD_LIBRARY_PATH=$mydir/lib:$LD_LIBRARY_PATH
export PATH=$mydir/bin:$PATH
```

### For NERSC users

To mount CVMFS inside NERSC via Shifter:

```bash
shifter --image=fermilab/fnal-wn-sl7:latest --module=cvmfs -- /bin/bash
```

This allows file copying or running ROOT-based workflows in NERSC with access to Fermilab software stacks.

## Notes

- These scripts are modular and can be adapted for different `.root` structures
- ROOT version compatibility: Tested on v6.22.08
