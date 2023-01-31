//Code to plot histogram of a branch
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TImage.h>

void plotBranchHistogram() {
    // Open the ROOT file
    TFile* file = TFile::Open("out.root");

    // Get the tree from the file
    TTree* tree = (TTree*)file->Get("gst");

    // Create a histogram for the branch
    int nbins = 100;
    float nmin = 0;
    float nmax = 100;
    TH1F* hist = new TH1F("histName", " Number of final state particles", nbins, nmin, nmax);

    // Fill the histogram with the branch values
    tree->Draw("nf>>histName");

    // Create a canvas to draw the histogram
    TCanvas* canvas = new TCanvas();

    // Draw the histogram
    hist->Draw();

    // Save the canvas to a PNG image
    TImage* img = TImage::Create();
    img->FromPad(canvas);
    img->WriteImage("nf.png");

    // Show the canvas
    canvas->Draw();
}



// run this code using
// root -l -b -q plotBranchHistogram.cc
