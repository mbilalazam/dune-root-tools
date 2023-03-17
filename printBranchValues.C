// Code to read and print the values of a branch 
#include <iostream>
#include <TFile.h>
#include <TTree.h>

void printBranchValues() {

  // Open the ROOT file
  TFile *file = TFile::Open("TrackMult2x2wTruth_RHC.root", "READ");

  // Get the tree from the file
  TTree *tree = (TTree*)file->Get("ana");

  // Declare variables for the branch data
  int nu_PDG;
  double nu_Q2;

  // Set the branch address to the variables
  tree->SetBranchAddress("nu_PDG", &nu_PDG);
  tree->SetBranchAddress("nu_Q2", &nu_Q2);

  // Loop over the entries in the tree and print the branch values
  for (Long64_t iEntry=0; iEntry<tree->GetEntries(); iEntry++) {
    tree->GetEntry(iEntry);
    std::cout << "Entry " << iEntry << ": nu_PDG = " << nu_PDG << ", nu_Q2 = " << nu_Q2 << std::endl;
  }

  // Close the file
  file->Close();
}


// run this code using
// root -l -b
// .L printBranchValues.C
// printBranchValues()
