//Code to find branch names and their data types in a root file
#include "TFile.h"
#include "TTree.h"

void findDataType() {
    TFile *f = new TFile("out.root");
    TTree *t = (TTree*)f->Get("gst");

    // Get the number of branches in the tree
    int nBranches = t->GetListOfBranches()->GetEntries();

    // Loop over the branches and print out their data types
    for (int i = 0; i < nBranches; i++) {
        TBranch *b = (TBranch*)t->GetListOfBranches()->At(i);
        TLeaf *l = b->GetLeaf(b->GetName());
        printf("Branch name: %s, Data type: %s\n", b->GetName(), l->GetTypeName());
    }

    f->Close();
}


// run this code using
// root -l -b -q findDataType.cc
