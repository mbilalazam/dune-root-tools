//Code to loop over all events in a root file
#include "TFile.h"
#include "TTree.h"

void loopEvents() {
    TFile *f = new TFile("out.root");
    TTree *t = (TTree*)f->Get("gst");

    // Set the number of events to loop over
    int nEvents = t->GetEntries();

    // Loop over the events in the tree
    for (int i = 0; i < nEvents; i++) {
        t->GetEvent(i);
        // Do something with the event here, e.g. print out a variable
        printf("Event number: %d, value: %f\n", i, t->GetLeaf("nf")->GetValue());
    }

    f->Close();
}


// run this code using
// root -l -b -q loopEvents.cc
