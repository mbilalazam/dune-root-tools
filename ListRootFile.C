// Code to find all trees, branches and leaf names and their different data types
#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TLeaf.h>
#include <iostream>

void ListRootFile(const char* filename)
{
    TFile *file = new TFile(filename);
    if (file->IsZombie()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::cout << "File: " << filename << std::endl;

    TList *treeList = file->GetListOfKeys();
    TIter next(treeList);
    TKey *key;
    while ((key = (TKey*)next())) {
        TObject *obj = key->ReadObj();
        if (obj->IsA()->InheritsFrom(TTree::Class())) {
            TTree *tree = (TTree*)obj;
            std::cout << "\nTree: " << tree->GetName() << std::endl;
            TObjArray *branches = tree->GetListOfBranches();
            for (Int_t i = 0; i < branches->GetEntries(); i++) {
                TBranch *branch = (TBranch*)branches->At(i);
                std::cout << "Branch: " << branch->GetName() << " (" << branch->GetTitle() << ")" << std::endl;
                TObjArray *leaves = branch->GetListOfLeaves();
                for (Int_t j = 0; j < leaves->GetEntries(); j++) {
                    TLeaf *leaf = (TLeaf*)leaves->At(j);
                    std::cout << "Leaf: " << leaf->GetName() << " (" << leaf->GetTypeName() << ")" << std::endl;
                }
            }
        }
    }

    file->Close();
}

void rootlist() {
    ListRootFile("TrackMult2x2wTruth.root"); // replace with the actual file name
}


// run this code using
// root -l -b 
// .L ListRootFile.C
// ListRootFile("TrackMult2x2wTruth.root")
