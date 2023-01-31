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
#include "TH1F.h"

void findFinalStateParticles() {
    TFile *f = new TFile("out.root");
    TTree *t = (TTree*)f->Get("gst");

    // Declare variables to hold the particle information
    int pdgf;
    int nf;

    // Link the variables to the branches in the tree
    t->SetBranchAddress("pdgf", &pdgf);
    t->SetBranchAddress("nf", &nf);


    // Create a histogram to hold the final state particle information
    TH1I *h = new TH1I("h", "Final State Particles", 100, 0, 100);


    // Set the number of events to loop over
    int nEvents = t->GetEntries();

    // Loop over the events in the tree
    for (int i = 0; i < nEvents; i++) {
        t->GetEvent(i);
        // Do something with the event here, e.g. print out a variable
        printf("Event number: %d, value: %f\n", i, t->GetLeaf("nf")->GetValue());
	//h->Fill(nf);
    }



//    for (int i = 0; i < t->GetEntries(); i++) {
//        t->GetEntry(i);
        // Apply a cut to select only final state particles
//        if (pdgf == 11 || pdgf == -11) {
//            h->Fill(nf);
//        }
//    }

    // Draw the histogram
    h->Draw();
}

// run this code using
// root -l -b -q findFinalStateParticles.cc
