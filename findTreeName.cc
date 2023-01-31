//Code to find tree name in a root file
#include <iostream>
#include "TFile.h"
#include "TTree.h"
#include "TGeoManager.h"
#include "TStopwatch.h"
#include "TLorentzVector.h"
#include "TH2D.h"
#include "TH1.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TGeoManager.h"
#include "TStyle.h"
#include "TPaveText.h"
#include "TBox.h"

void findTreeName() {
    TFile *f = new TFile("out.root");
    TIter next(f->GetListOfKeys());
    TKey *key;
    while ((key = (TKey*)next())) {
        if (strcmp(key->GetClassName(), "TTree") == 0) {
            printf("Tree name: %s\n", key->GetName());
        }
    }
    f->Close();
}


// run this code using
// root -l -b -q findTreeName.cc
