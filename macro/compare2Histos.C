// root
// [] .L plot_eff.cpp
// [] run()

void run()
{

  TFile* root1  = new TFile("DY0jet_LO_histo.root");
  TFile* root2  = new TFile("DY0jet_NLO_histo.root");
  TFile* root3  = new TFile("DY1jet_LO_histo.root");


  TH1F* root1_nJet = (TH1F*)root1->Get("h_nGenJet");
  TH1F* root1_JPt  = (TH1F*)root1->Get("h_genJetPt");
  TH1F* root1_JEta = (TH1F*)root1->Get("h_genJetEta");  
  TH1F* root1_JPhi = (TH1F*)root1->Get("h_genJetPhi");
  TH1F* root1_ZPt  = (TH1F*)root1->Get("h_genZPt");
  TH1F* root1_ZEta = (TH1F*)root1->Get("h_genZEta");
  TH1F* root1_ZPhi = (TH1F*)root1->Get("h_genZPhi");
  TH1F* root1_ZMass= (TH1F*)root1->Get("h_genZMass");
  TH1F* root1_SumY = (TH1F*)root1->Get("h_SumY");
  TH1F* root1_DiffY= (TH1F*)root1->Get("h_DiffY");


  TH1F* root2_nJet = (TH1F*)root2->Get("h_nGenJet");
  TH1F* root2_JPt  = (TH1F*)root2->Get("h_genJetPt");
  TH1F* root2_JEta = (TH1F*)root2->Get("h_genJetEta");
  TH1F* root2_JPhi = (TH1F*)root2->Get("h_genJetPhi");
  TH1F* root2_ZPt  = (TH1F*)root2->Get("h_genZPt");
  TH1F* root2_ZEta = (TH1F*)root2->Get("h_genZEta");
  TH1F* root2_ZPhi = (TH1F*)root2->Get("h_genZPhi");
  TH1F* root2_ZMass= (TH1F*)root2->Get("h_genZMass");
  TH1F* root2_SumY = (TH1F*)root2->Get("h_SumY");
  TH1F* root2_DiffY= (TH1F*)root2->Get("h_DiffY");


  TH1F* root3_nJet = (TH1F*)root3->Get("h_nGenJet");
  TH1F* root3_JPt  = (TH1F*)root3->Get("h_genJetPt");
  TH1F* root3_JEta = (TH1F*)root3->Get("h_genJetEta");
  TH1F* root3_JPhi = (TH1F*)root3->Get("h_genJetPhi");
  TH1F* root3_ZPt  = (TH1F*)root3->Get("h_genZPt");
  TH1F* root3_ZEta = (TH1F*)root3->Get("h_genZEta");
  TH1F* root3_ZPhi = (TH1F*)root3->Get("h_genZPhi");
  TH1F* root3_ZMass= (TH1F*)root3->Get("h_genZMass");
  TH1F* root3_SumY = (TH1F*)root3->Get("h_SumY");
  TH1F* root3_DiffY= (TH1F*)root3->Get("h_DiffY");



  root1_ZPt->SetLineColor(2);
  root2_ZPt->SetLineColor(4);
  root3_ZPt->SetLineColor(32);

  root1_JPt->SetLineColor(2);
  root2_JPt->SetLineColor(4);
  root3_JPt->SetLineColor(32);

  root1_ZEta->SetLineColor(2);
  root2_ZEta->SetLineColor(4);
  root3_ZEta->SetLineColor(32);

  root1_JEta->SetLineColor(2);
  root2_JEta->SetLineColor(4);
  root3_JEta->SetLineColor(32);

  root1_ZPhi->SetLineColor(2);
  root2_ZPhi->SetLineColor(4);
  root3_ZPhi->SetLineColor(32);

  root1_JPhi->SetLineColor(2);
  root2_JPhi->SetLineColor(4);
  root3_JPhi->SetLineColor(32);

  root1_ZMass->SetLineColor(2);
  root2_ZMass->SetLineColor(4);
  root3_ZMass->SetLineColor(32);

  root1_nJet->SetLineColor(2);
  root2_nJet->SetLineColor(4);
  root3_nJet->SetLineColor(32);

  root1_SumY->SetLineColor(2);
  root2_SumY->SetLineColor(4);
  root3_SumY->SetLineColor(32);

  root1_DiffY->SetLineColor(2);
  root2_DiffY->SetLineColor(4);
  root3_DiffY->SetLineColor(32);



  
  gROOT->SetStyle("Plain");




  TCanvas *c1= new TCanvas("c1","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_ZPt->GetXaxis()->SetTitle("Z P_{T} [GeV]");
  root2_ZPt->GetXaxis()->SetTitle("Z P_{T} [GeV]");
  root3_ZPt->GetXaxis()->SetTitle("Z P_{T} [GeV]");
  root2_ZPt->Draw("histe");
  root1_ZPt->Draw("histesame");
  root3_ZPt->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_ZPt,"DY_0Jet_LO","L");
  leg->AddEntry(root2_ZPt,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_ZPt,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img1 = TImage::Create();
  img1->FromPad(c1);
  img1->WriteImage("canvas1.png");
  delete c1;
  delete img1;


  TCanvas *c6= new TCanvas("c6","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_JPt->GetXaxis()->SetTitle("Jet P_{T} [GeV]");
  root2_JPt->GetXaxis()->SetTitle("Jet P_{T} [GeV]");
  root3_JPt->GetXaxis()->SetTitle("Jet P_{T} [GeV]");
  root2_JPt->Draw("histe");
  root1_JPt->Draw("histesame");
  root3_JPt->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_JPt,"DY_0Jet_LO","L");
  leg->AddEntry(root2_JPt,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_JPt,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img6 = TImage::Create();
  img6->FromPad(c6);
  img6->WriteImage("canvas6.png");
  delete c6;
  delete img6;




  TCanvas *c2= new TCanvas("c2","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_ZEta->GetXaxis()->SetTitle("Z #eta");
  root2_ZEta->GetXaxis()->SetTitle("Z #eta");
  root3_ZEta->GetXaxis()->SetTitle("Z #eta");
  root3_ZEta->Draw("histe");
  root1_ZEta->Draw("histesame");
  root2_ZEta->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_ZEta,"DY_0Jet_LO","L");
  leg->AddEntry(root2_ZEta,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_ZEta,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img2 = TImage::Create();
  img2->FromPad(c2);
  img2->WriteImage("canvas2.png");
  delete c2;
  delete img2;




  TCanvas *c7= new TCanvas("c7","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_JEta->GetXaxis()->SetTitle("Jet #eta");
  root2_JEta->GetXaxis()->SetTitle("Jet #eta");
  root3_JEta->GetXaxis()->SetTitle("Jet #eta");
  root2_JEta->Draw("histe");
  root1_JEta->Draw("histesame");
  root3_JEta->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_JEta,"DY_0Jet_LO","L");
  leg->AddEntry(root2_JEta,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_JEta,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img7 = TImage::Create();
  img7->FromPad(c7);
  img7->WriteImage("canvas7.png");
  delete c7;
  delete img7;



  TCanvas *c3= new TCanvas("c3","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_ZPhi->GetXaxis()->SetTitle("Z #phi");
  root2_ZPhi->GetXaxis()->SetTitle("Z #phi");
  root3_ZPhi->GetXaxis()->SetTitle("Z #phi");
  root3_ZPhi->Draw("histe");
  root2_ZPhi->Draw("histesame");
  root1_ZPhi->Draw("histesame");



  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_ZPhi,"DY_0Jet_LO","L");
  leg->AddEntry(root2_ZPhi,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_ZPhi,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img3 = TImage::Create();
  img3->FromPad(c3);
  img3->WriteImage("canvas3.png");
  delete c3;
  delete img3;




  TCanvas *c8= new TCanvas("c8","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_JPhi->GetXaxis()->SetTitle("Jet #phi");
  root2_JPhi->GetXaxis()->SetTitle("Jet #phi");
  root3_JPhi->GetXaxis()->SetTitle("Jet #phi");
  root3_JPhi->Draw("histe");
  root1_JPhi->Draw("histesame");
  root2_JPhi->Draw("histesame");
 

  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_JPhi,"DY_0Jet_LO","L");
  leg->AddEntry(root2_JPhi,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_JPhi,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img8 = TImage::Create();
  img8->FromPad(c8);
  img8->WriteImage("canvas8.png");
  delete c8;
  delete img8;



  TCanvas *c4= new TCanvas("c4","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_ZMass->GetXaxis()->SetTitle("M_{ll} [GeV]");
  root2_ZMass->GetXaxis()->SetTitle("M_{ll} [GeV]");
  root3_ZMass->GetXaxis()->SetTitle("M_{ll} [GeV]");
  root2_ZMass->Draw("histe");
  root1_ZMass->Draw("histesame");
  root3_ZMass->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_ZMass,"DY_0Jet_LO","L");
  leg->AddEntry(root2_ZMass,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_ZMass,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img4 = TImage::Create();
  img4->FromPad(c4);
  img4->WriteImage("canvas4.png");
  delete c4;
  delete img4;




  TCanvas *c5= new TCanvas("c5","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_nJet->GetXaxis()->SetTitle("nGenJet");
  root2_nJet->GetXaxis()->SetTitle("nGenJet");
  root3_nJet->GetXaxis()->SetTitle("nGenJet");
  root3_nJet->Draw("histe");
  root1_nJet->Draw("histesame");
  root2_nJet->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_nJet,"DY_0Jet_LO","L");
  leg->AddEntry(root2_nJet,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_nJet,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img5 = TImage::Create();
  img5->FromPad(c5);
  img5->WriteImage("canvas5.png");
  delete c5;
  delete img5;



  TCanvas *c9= new TCanvas("c9","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_SumY->GetXaxis()->SetTitle("Rapidity Sum");
  root2_SumY->GetXaxis()->SetTitle("Rapidity Sum");
  root3_SumY->GetXaxis()->SetTitle("Rapidity Sum");
  root2_SumY->Draw("histe");
  root1_SumY->Draw("histesame");
  root3_SumY->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_SumY,"DY_0Jet_LO","L");
  leg->AddEntry(root2_SumY,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_SumY,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img9 = TImage::Create();
  img9->FromPad(c9);
  img9->WriteImage("canvas9.png");
  delete c9;
  delete img9;


  TCanvas *c10= new TCanvas("c10","",200,10,800,800);

  gStyle->SetOptStat(0);
  root1_DiffY->GetXaxis()->SetTitle("Rapidity Difference");
  root2_DiffY->GetXaxis()->SetTitle("Rapidity Difference");
  root3_DiffY->GetXaxis()->SetTitle("Rapidity Difference");
  root3_DiffY->Draw("histe");
  root1_DiffY->Draw("histesame");
  root2_DiffY->Draw("histesame");


  leg = new TLegend(0.76,0.84,0.9,0.89);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_DiffY,"DY_0Jet_LO","L");
  leg->AddEntry(root2_DiffY,"DY_0Jet_NLO","L");
  leg->AddEntry(root3_DiffY,"DY_1Jet_LO","L");
  leg->Draw("same");

  gSystem->ProcessEvents();
  TImage *img10 = TImage::Create();
  img10->FromPad(c10);
  img10->WriteImage("canvas10.png");
  delete c10;
  delete img10;




}
