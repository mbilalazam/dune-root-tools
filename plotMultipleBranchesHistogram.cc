//Code to plot histogram of two branches
#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TImage.h>
#include <TLegend.h>

void plotMultipleBranchesHistogram() {
    // Open the ROOT file
    TFile* file = TFile::Open("out.root");

    // Get the tree from the file
    TTree* tree = (TTree*)file->Get("gst");

    // Create a histogram for the first branch
    int nbins = 10;
    float nmin = 0;
    float nmax = 40;
    TH1F* hist1 = new TH1F("nfn", "Final State Neutrons", nbins, nmin, nmax);
    hist1->SetLineColor(kRed); // Set the color of the histogram to red
    hist1->SetFillColor(kRed); // Set the color of the lines of the bars to red
    hist1->SetLineWidth(2);    // Set the width of the lines of the bars


    // Fill the histogram with the first branch values
    tree->Draw("nfn>>nfn");

    // Create a histogram for the second branch
    int pbins = 10;
    float pmin = 0;
    float pmax = 40;
    TH1F* hist2 = new TH1F("nfp", "Final State Protons", pbins, pmin, pmax);
    hist2->SetLineColor(kBlue); // Set the color of the histogram to blue
    hist2->SetFillColor(kBlue); // Set the color of the lines of the bars to blue
    hist2->SetLineWidth(2);     // Set the width of the lines of the bars

    // Fill the histogram with the second branch values
    tree->Draw("nfp>>nfp");

    // Create a canvas to draw the histograms
    TCanvas* canvas = new TCanvas();

    // Draw the first histogram
    hist1->Draw("BAR");

    // Draw the second histogram on the same canvas
    hist2->Draw("BARSAME");

    // Add a legend to the canvas
    TLegend* legend = new TLegend(0.75, 0.75, 0.5, 0.5); //  top-left corner at (0.75, 0.75) and the bottom-right corner at (0.5, 0.5) coordinates of the canvas
    legend->AddEntry(hist1, "nfn", "f");
    legend->AddEntry(hist2, "nfp", "f");
    legend->Draw();
    legend->SetTextSize(0.05); // set the font size of the text in the legend
    legend->SetNColumns(1);
    legend->SetFillColor(0);
    canvas->Update();
    legend->Clear();
    legend->AddEntry(hist1, "nfn", "f");
    legend->AddEntry(hist2, "nfp", "f");
    legend->Draw("same");

    // Save the canvas to a PNG image
    TImage* img = TImage::Create();
    img->FromPad(canvas);
    img->WriteImage("nfn_nfp.png");

    // Show the canvas
    canvas->Draw();
}

// run this code using
// root -l -b -q plotMultipleBranchesHistogram.cc
