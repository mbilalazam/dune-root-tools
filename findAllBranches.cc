//Code to find branches of all trees
#include <TFile.h>
#include <TTree.h>
#include <TObjArray.h>
#include <TBranch.h>

void findAllBranches()
{
    // Open the ROOT file
    TFile* file = new TFile("out.root");

    // Get the list of keys (i.e., objects) in the file
    TIter nextkey(file->GetListOfKeys());
    TKey* key;
    while ((key = (TKey*)nextkey())) {
        // Check if the object is a TTree
        TObject* obj = key->ReadObj();
        if (obj->IsA() == TTree::Class()) {
            TTree* tree = (TTree*)obj;
            // Print the name of the tree
            printf("Tree: %s\n", tree->GetName());
            // Get the list of branches for the tree
            TObjArray* branches = tree->GetListOfBranches();
            for (Int_t i = 0; i < branches->GetEntriesFast(); i++) {
                TBranch* branch = (TBranch*)branches->UncheckedAt(i);
                // Print the name of the branch
                printf("  Branch: %s\n", branch->GetName());
            }
        }
        delete obj;
    }

    // Close the ROOT file
    file->Close();
}


// run this code using
// root -l -b -q FindBranches.cc
