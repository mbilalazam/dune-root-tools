//Code to find branch names in a root file
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

void findBranches() {
    TFile *f = new TFile("out.root");
    TTree *t = (TTree*)f->Get("gst");

    // Get the number of branches in the tree
    int nBranches = t->GetListOfBranches()->GetEntries();

    // Loop over the branches and print out their names
    for (int i = 0; i < nBranches; i++) {
        TBranch *b = (TBranch*)t->GetListOfBranches()->At(i);
        printf("Branch name: %s\n", b->GetName());
    }

    f->Close();
}


// run this code using
// root -l -b -q findBranches.cc
