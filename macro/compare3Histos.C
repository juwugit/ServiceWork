// root
// [] .L plot_eff.cpp
// [] run()

void run()
{

  TFile* root1  = new TFile("rootfile/dy0j_4f_LO_MLM.root");
  TFile* root2  = new TFile("rootfile/dy0j_4f_NLO.root");
  TFile* root3  = new TFile("rootfile/dy01j_4f_LO_MLM.root");


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


  root1_ZPt->SetLineColor(1);
  root1_ZPt->SetLineWidth(2);
  root1_ZPt->SetMarkerColor(1);
  root1_ZPt->SetMarkerStyle(20);
  root1_ZPt->SetMarkerSize(1);
  root2_ZPt->SetLineColor(8);
  root2_ZPt->SetFillColor(8);
  root2_ZPt->SetFillStyle(3313);
  root3_ZPt->SetFillColor(2);
  root3_ZPt->SetLineColor(2);
  root3_ZPt->SetFillStyle(3004);

  root1_ZEta->SetLineColor(1);
  root1_ZEta->SetLineWidth(2);
  root1_ZEta->SetMarkerColor(1);
  root1_ZEta->SetMarkerStyle(20);
  root1_ZEta->SetMarkerSize(1);
  root2_ZEta->SetLineColor(8);
  root2_ZEta->SetFillColor(8);
  root2_ZEta->SetFillStyle(3313);
  root3_ZEta->SetFillColor(2);
  root3_ZEta->SetLineColor(2);
  root3_ZEta->SetFillStyle(3004);

  root1_ZPhi->SetLineColor(1);
  root1_ZPhi->SetLineWidth(2);
  root1_ZPhi->SetMarkerColor(1);
  root1_ZPhi->SetMarkerStyle(20);
  root1_ZPhi->SetMarkerSize(1);
  root2_ZPhi->SetLineColor(8);
  root2_ZPhi->SetFillColor(8);
  root2_ZPhi->SetFillStyle(3313);
  root3_ZPhi->SetFillColor(2);
  root3_ZPhi->SetLineColor(2);
  root3_ZPhi->SetFillStyle(3004);

  root1_ZMass->SetLineColor(1);
  root1_ZMass->SetLineWidth(2);
  root1_ZMass->SetMarkerColor(1);
  root1_ZMass->SetMarkerStyle(20);
  root1_ZMass->SetMarkerSize(1);
  root2_ZMass->SetLineColor(8);
  root2_ZMass->SetFillColor(8);
  root2_ZMass->SetFillStyle(3313);
  root3_ZMass->SetFillColor(2);
  root3_ZMass->SetLineColor(2);
  root3_ZMass->SetFillStyle(3004);


  root1_JPt->SetLineColor(1);
  root1_JPt->SetLineWidth(2);
  root1_JPt->SetMarkerColor(1);
  root1_JPt->SetMarkerStyle(20);
  root1_JPt->SetMarkerSize(1);
  root2_JPt->SetLineColor(8);
  root2_JPt->SetFillColor(8);
  root2_JPt->SetFillStyle(3313);
  root3_JPt->SetFillColor(2);
  root3_JPt->SetLineColor(2);
  root3_JPt->SetFillStyle(3004);


  root1_JEta->SetLineColor(1);
  root1_JEta->SetLineWidth(2);
  root1_JEta->SetMarkerColor(1);
  root1_JEta->SetMarkerStyle(20);
  root1_JEta->SetMarkerSize(1);
  root2_JEta->SetLineColor(8);
  root2_JEta->SetFillColor(8);
  root2_JEta->SetFillStyle(3313);
  root3_JEta->SetFillColor(2);
  root3_JEta->SetLineColor(2);
  root3_JEta->SetFillStyle(3004);

  root1_JPhi->SetLineColor(1);
  root1_JPhi->SetLineWidth(2);
  root1_JPhi->SetMarkerColor(1);
  root1_JPhi->SetMarkerStyle(20);
  root1_JPhi->SetMarkerSize(1);
  root2_JPhi->SetLineColor(8);
  root2_JPhi->SetFillColor(8);
  root2_JPhi->SetFillStyle(3313);
  root3_JPhi->SetFillColor(2);
  root3_JPhi->SetLineColor(2);
  root3_JPhi->SetFillStyle(3004);

  root1_nJet->SetLineColor(1);
  root1_nJet->SetLineWidth(2);
  root1_nJet->SetMarkerColor(1);
  root1_nJet->SetMarkerStyle(20);
  root1_nJet->SetMarkerSize(1);
  root2_nJet->SetLineColor(8);
  root2_nJet->SetFillColor(8);
  root2_nJet->SetFillStyle(3313);
  root3_nJet->SetFillColor(2);
  root3_nJet->SetLineColor(2);
  root3_nJet->SetFillStyle(3004);


  root1_SumY->SetLineColor(1);
  root1_SumY->SetLineWidth(2);
  root1_SumY->SetMarkerColor(1);
  root1_SumY->SetMarkerStyle(20);
  root1_SumY->SetMarkerSize(1);
  root2_SumY->SetLineColor(8);
  root2_SumY->SetFillColor(8);
  root2_SumY->SetFillStyle(3313);
  root3_SumY->SetFillColor(2);
  root3_SumY->SetLineColor(2);
  root3_SumY->SetFillStyle(3004);


  root1_DiffY->SetLineColor(1);
  root1_DiffY->SetLineWidth(2);
  root1_DiffY->SetMarkerColor(1);
  root1_DiffY->SetMarkerStyle(20);
  root1_DiffY->SetMarkerSize(1);
  root2_DiffY->SetLineColor(8);
  root2_DiffY->SetFillColor(8);
  root2_DiffY->SetFillStyle(3313);
  root3_DiffY->SetFillColor(2);
  root3_DiffY->SetLineColor(2);
  root3_DiffY->SetFillStyle(3004);


  
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);


  TCanvas *c1= new TCanvas("c1","",200,10,1600,1600);
  c1->Divide(2,2);

  c1->cd(1);
  root2_ZPt->GetXaxis()->SetTitle("Z P_{T} [GeV]");
  root2_ZPt->Draw("histe");
  root1_ZPt->Draw("esame");
  root3_ZPt->Draw("histesame");

  leg = new TLegend(0.5,0.5,0.8,0.8);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_ZPt,"dy0j_4f_LO","lep");
  leg->AddEntry(root2_ZPt,"dy0j_4f_NLO","F");
  leg->AddEntry(root3_ZPt,"dy01j_4f_LO","F");
  leg->Draw("same");

  c1->cd(2);
  root2_ZEta->GetXaxis()->SetTitle("Z #eta");
  root2_ZEta->Draw("histe");
  root1_ZEta->Draw("esame");
  root3_ZEta->Draw("histesame");

  c1->cd(3);
  root3_ZPhi->GetXaxis()->SetTitle("Z #phi");
  root3_ZPhi->Draw("histe");
  root2_ZPhi->Draw("histesame");
  root1_ZPhi->Draw("esame");

  c1->cd(4);
  root3_ZMass->GetXaxis()->SetTitle("M_{ll} [GeV]");
  root3_ZMass->Draw("histe");
  root1_ZMass->Draw("esame");
  root2_ZMass->Draw("histesame");


  gSystem->ProcessEvents();
  TImage *img1 = TImage::Create();
  img1->FromPad(c1);
  img1->WriteImage("canvas4.png");
  delete c1;
  delete img1;


  TCanvas *c2= new TCanvas("c2","",200,10,1600,1600);
  c2->Divide(2,2);

  c2->cd(1);
  root2_JPt->GetXaxis()->SetTitle("Jet P_{T} [GeV]");
  root2_JPt->Draw("histe");
  root1_JPt->Draw("esame");
  root3_JPt->Draw("histesame");


  leg = new TLegend(0.5,0.5,0.8,0.8);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_JPt,"dy0j_4f_LO","lep");
  leg->AddEntry(root2_JPt,"dy0j_4f_NLO","F");
  leg->AddEntry(root3_JPt,"dy01j_4f_LO","F");
  leg->Draw("same");


  c2->cd(2);
  root2_JEta->GetXaxis()->SetTitle("Jet #eta");
  root2_JEta->Draw("histe");
  root1_JEta->Draw("esame");
  root3_JEta->Draw("histesame");


  c2->cd(3);
  root3_JPhi->GetXaxis()->SetTitle("Jet #phi");
  root3_JPhi->Draw("histe");
  root1_JPhi->Draw("esame");
  root2_JPhi->Draw("histesame");


  c2->cd(4);
  gPad->SetLogy();
  root3_nJet->GetXaxis()->SetTitle("nGenJet");
  root3_nJet->Draw("histe");
  root1_nJet->Draw("esame");
  root2_nJet->Draw("histesame");



  gSystem->ProcessEvents();
  TImage *img2 = TImage::Create();
  img2->FromPad(c2);
  img2->WriteImage("canvas5.png");
  delete c2;
  delete img2;






  TCanvas *c3= new TCanvas("c3","",200,10,1600,1600);
  c3->Divide(1,2);
 
  c3->cd(2);
  root3_SumY->GetXaxis()->SetTitle("Rapidity Sum");
  root3_SumY->Draw("histe");
  root1_SumY->Draw("esame");
  root2_SumY->Draw("histesame");


  c3->cd(1);
  root3_DiffY->GetXaxis()->SetTitle("Rapidity Difference");
  root3_DiffY->Draw("histe");
  root1_DiffY->Draw("esame");
  root2_DiffY->Draw("histesame");


  leg = new TLegend(0.7,0.7,0.8,0.8);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_JPt,"dy0j_4f_LO","lep");
  leg->AddEntry(root2_JPt,"dy0j_4f_NLO","F");
  leg->AddEntry(root3_JPt,"dy01j_4f_LO","F");
  leg->Draw("same");



  gSystem->ProcessEvents();
  TImage *img3 = TImage::Create();
  img3->FromPad(c3);
  img3->WriteImage("canvas6.png");
  delete c3;
  delete img3;






}
