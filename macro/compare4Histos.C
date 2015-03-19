// root
// [] .L plot_eff.cpp
// [] run()

void run()
{

  TFile* root1  = new TFile("dy0j_5f_LO_flat.root");
  TFile* root2  = new TFile("dy0j_5f_NLO_flat.root");
  TFile* root3  = new TFile("dy0j_5f_LO_herwigpp_flat.root");
  TFile* root4  = new TFile("dy0j_5f_NLO_herwigpp_flat.root");


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


  TH1F* root4_nJet = (TH1F*)root4->Get("h_nGenJet");
  TH1F* root4_JPt  = (TH1F*)root4->Get("h_genJetPt");
  TH1F* root4_JEta = (TH1F*)root4->Get("h_genJetEta");
  TH1F* root4_JPhi = (TH1F*)root4->Get("h_genJetPhi");
  TH1F* root4_ZPt  = (TH1F*)root4->Get("h_genZPt");
  TH1F* root4_ZEta = (TH1F*)root4->Get("h_genZEta");
  TH1F* root4_ZPhi = (TH1F*)root4->Get("h_genZPhi");
  TH1F* root4_ZMass= (TH1F*)root4->Get("h_genZMass");
  TH1F* root4_SumY = (TH1F*)root4->Get("h_SumY");
  TH1F* root4_DiffY= (TH1F*)root4->Get("h_DiffY");




  root1_ZPt->SetLineColor(1);
  root1_ZPt->SetLineWidth(2);
  root1_ZPt->SetMarkerColor(1);
  root1_ZPt->SetMarkerStyle(20);
  root1_ZPt->SetMarkerSize(1);
  root2_ZPt->SetLineColor(8);
  root2_ZPt->SetFillColor(8);
  root3_ZPt->SetFillColor(2);
  root3_ZPt->SetLineColor(2);
  root3_ZPt->SetFillStyle(3004);
  root4_ZPt->SetLineColor(kBlue+1);
  root4_ZPt->SetLineWidth(kBlue+1);
  root4_ZPt->SetMarkerColor(kBlue+1);
  root4_ZPt->SetMarkerStyle(kBlue+1);
  root4_ZPt->SetMarkerSize(1);

  



  root1_ZEta->SetLineColor(1);
  root1_ZEta->SetLineWidth(2);
  root1_ZEta->SetMarkerColor(1);
  root1_ZEta->SetMarkerStyle(20);
  root1_ZEta->SetMarkerSize(1);
  root2_ZEta->SetLineColor(8);
  root2_ZEta->SetFillColor(8);
  //root2_ZEta->SetFillStyle(3005);
  root3_ZEta->SetFillColor(2);
  root3_ZEta->SetLineColor(2);
  root3_ZEta->SetFillStyle(3004);
  root4_ZEta->SetLineColor(kBlue+1);
  root4_ZEta->SetLineWidth(kBlue+1);
  root4_ZEta->SetMarkerColor(kBlue+1);
  root4_ZEta->SetMarkerStyle(kBlue+1);
  root4_ZEta->SetMarkerSize(1);



  root1_ZPhi->SetLineColor(1);
  root1_ZPhi->SetLineWidth(2);
  root1_ZPhi->SetMarkerColor(1);
  root1_ZPhi->SetMarkerStyle(20);
  root1_ZPhi->SetMarkerSize(1);
  root2_ZPhi->SetLineColor(8);
  root2_ZPhi->SetFillColor(8);
  //root2_ZPhi->SetFillStyle(3005);
  root3_ZPhi->SetFillColor(2);
  root3_ZPhi->SetLineColor(2);
  root3_ZPhi->SetFillStyle(3004);
  root4_ZPhi->SetLineColor(kBlue+1);
  root4_ZPhi->SetLineWidth(kBlue+1);
  root4_ZPhi->SetMarkerColor(kBlue+1);
  root4_ZPhi->SetMarkerStyle(kBlue+1);
  root4_ZPhi->SetMarkerSize(1);




  root1_ZMass->SetLineColor(1);
  root1_ZMass->SetLineWidth(2);
  root1_ZMass->SetMarkerColor(1);
  root1_ZMass->SetMarkerStyle(20);
  root1_ZMass->SetMarkerSize(1);
  root2_ZMass->SetLineColor(8);
  root2_ZMass->SetFillColor(8);
  //root2_ZMass->SetFillStyle(3005);
  root3_ZMass->SetFillColor(2);
  root3_ZMass->SetLineColor(2);
  root3_ZMass->SetFillStyle(3004);
  root4_ZMass->SetLineColor(kBlue+1);
  root4_ZMass->SetLineWidth(kBlue+1);
  root4_ZMass->SetMarkerColor(kBlue+1);
  root4_ZMass->SetMarkerStyle(kBlue+1);
  root4_ZMass->SetMarkerSize(1);




  root1_JPt->SetLineColor(1);
  root1_JPt->SetLineWidth(2);
  root1_JPt->SetMarkerColor(1);
  root1_JPt->SetMarkerStyle(20);
  root1_JPt->SetMarkerSize(1);
  root2_JPt->SetLineColor(8);
  root2_JPt->SetFillColor(8);
  //root2_JPt->SetFillStyle(3005);
  root3_JPt->SetFillColor(2);
  root3_JPt->SetLineColor(2);
  root3_JPt->SetFillStyle(3004);
  root4_JPt->SetLineColor(kBlue+1);
  root4_JPt->SetLineWidth(kBlue+1);
  root4_JPt->SetMarkerColor(kBlue+1);
  root4_JPt->SetMarkerStyle(kBlue+1);
  root4_JPt->SetMarkerSize(1);



  root1_JEta->SetLineColor(1);
  root1_JEta->SetLineWidth(2);
  root1_JEta->SetMarkerColor(1);
  root1_JEta->SetMarkerStyle(20);
  root1_JEta->SetMarkerSize(1);
  root2_JEta->SetLineColor(8);
  root2_JEta->SetFillColor(8);
  //root2_JEta->SetFillStyle(3005);
  root3_JEta->SetFillColor(2);
  root3_JEta->SetLineColor(2);
  root3_JEta->SetFillStyle(3004);
  root4_JEta->SetLineColor(kBlue+1);
  root4_JEta->SetLineWidth(kBlue+1);
  root4_JEta->SetMarkerColor(kBlue+1);
  root4_JEta->SetMarkerStyle(kBlue+1);
  root4_JEta->SetMarkerSize(1);



  root1_JPhi->SetLineColor(1);
  root1_JPhi->SetLineWidth(2);
  root1_JPhi->SetMarkerColor(1);
  root1_JPhi->SetMarkerStyle(20);
  root1_JPhi->SetMarkerSize(1);
  root2_JPhi->SetLineColor(8);
  root2_JPhi->SetFillColor(8);
  //root2_JPhi->SetFillStyle(3005);
  root3_JPhi->SetFillColor(2);
  root3_JPhi->SetLineColor(2);
  root3_JPhi->SetFillStyle(3004);
  root4_JPhi->SetLineColor(kBlue+1);
  root4_JPhi->SetLineWidth(kBlue+1);
  root4_JPhi->SetMarkerColor(kBlue+1);
  root4_JPhi->SetMarkerStyle(kBlue+1);
  root4_JPhi->SetMarkerSize(1);



  root1_nJet->SetLineColor(1);
  root1_nJet->SetLineWidth(2);
  root1_nJet->SetMarkerColor(1);
  root1_nJet->SetMarkerStyle(20);
  root1_nJet->SetMarkerSize(1);
  root2_nJet->SetLineColor(8);
  root2_nJet->SetFillColor(8);
  //root2_nJet->SetFillStyle(3005);
  root3_nJet->SetFillColor(2);
  root3_nJet->SetLineColor(2);
  root3_nJet->SetFillStyle(3004);
  root4_nJet->SetLineColor(kBlue+1);
  root4_nJet->SetLineWidth(kBlue+1);
  root4_nJet->SetMarkerColor(kBlue+1);
  root4_nJet->SetMarkerStyle(kBlue+1);
  root4_nJet->SetMarkerSize(1);





  root1_SumY->SetLineColor(1);
  root1_SumY->SetLineWidth(2);
  root1_SumY->SetMarkerColor(1);
  root1_SumY->SetMarkerStyle(20);
  root1_SumY->SetMarkerSize(1);
  root2_SumY->SetLineColor(8);
  root2_SumY->SetFillColor(8);
  //root2_SumY->SetFillStyle(3005);
  root3_SumY->SetFillColor(2);
  root3_SumY->SetLineColor(2);
  root3_SumY->SetFillStyle(3004);
  root4_SumY->SetLineColor(kBlue+1);
  root4_SumY->SetLineWidth(kBlue+1);
  root4_SumY->SetMarkerColor(kBlue+1);
  root4_SumY->SetMarkerStyle(kBlue+1);
  root4_SumY->SetMarkerSize(1);



  root1_DiffY->SetLineColor(1);
  root1_DiffY->SetLineWidth(2);
  root1_DiffY->SetMarkerColor(1);
  root1_DiffY->SetMarkerStyle(20);
  root1_DiffY->SetMarkerSize(1);
  root2_DiffY->SetLineColor(8);
  root2_DiffY->SetFillColor(8);
  //root2_DiffY->SetFillStyle(3005);
  root3_DiffY->SetFillColor(2);
  root3_DiffY->SetLineColor(2);
  root3_DiffY->SetFillStyle(3004);
  root4_DiffY->SetLineColor(kBlue+1);
  root4_DiffY->SetLineWidth(kBlue+1);
  root4_DiffY->SetMarkerColor(kBlue+1);
  root4_DiffY->SetMarkerStyle(kBlue+1);
  root4_DiffY->SetMarkerSize(1);


  
  gROOT->SetStyle("Plain");
  gStyle->SetOptStat(0);
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);


  TCanvas *c1= new TCanvas("c1","",200,10,1600,1600);
  c1->Divide(2,2);

  c1->cd(1);
  root3_ZPt->GetXaxis()->SetTitle("Z P_{T} [GeV]");
  root3_ZPt->Draw("histe");
  root2_ZPt->Draw("histesame");
  root3_ZPt->Draw("histesame");
  root1_ZPt->Draw("esame");
  root4_ZPt->Draw("esame");

  leg = new TLegend(0.5,0.5,0.8,0.8);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_ZPt,"dy0j_5f_LO_PYTHIA8","lep");
  leg->AddEntry(root2_ZPt,"dy0j_5f_NLO_PYTHIA8","F");
  leg->AddEntry(root3_ZPt,"dy0j_5f_LO_HerwigPP","F");
  leg->AddEntry(root4_ZPt,"dy0j_5f_NLO_HerwigPP","lep");
  leg->Draw("same");

  c1->cd(2);
  root3_ZEta->GetXaxis()->SetTitle("Z #eta");
  root3_ZEta->Draw("histe");
  root2_ZEta->Draw("histesame");  
  root3_ZEta->Draw("histesame");
  root1_ZEta->Draw("esame");
  root4_ZEta->Draw("esame");
  
  c1->cd(3);
  root2_ZPhi->GetXaxis()->SetTitle("Z #phi");
  root2_ZPhi->Draw("histe");
  root3_ZPhi->Draw("histesame");    
  root1_ZPhi->Draw("esame");
  root4_ZPhi->Draw("esame");
  
  c1->cd(4);
  root3_ZMass->GetXaxis()->SetTitle("M_{ll} [GeV]");
  root3_ZMass->Draw("histe");
  root2_ZMass->Draw("histesame");
  root3_ZMass->Draw("histesame");
  root1_ZMass->Draw("esame");  
  root4_ZMass->Draw("esame");


  gSystem->ProcessEvents();
  TImage *img1 = TImage::Create();
  img1->FromPad(c1);
  img1->WriteImage("canvas4.png");
  delete c1;
  delete img1;


  TCanvas *c2= new TCanvas("c2","",200,10,1600,1600);
  c2->Divide(2,2);

  c2->cd(1);
  root3_JPt->GetXaxis()->SetTitle("Jet P_{T} [GeV]");
  root3_JPt->Draw("histe");
  root2_JPt->Draw("histesame");
  root3_JPt->Draw("histesame");
  root1_JPt->Draw("esame");
  root4_JPt->Draw("esame");


  leg = new TLegend(0.5,0.5,0.8,0.8);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_JPt,"dy0j_5f_LO_PYTHIA8","lep");
  leg->AddEntry(root2_JPt,"dy0j_5f_NLO_PYTHIA8","F");
  leg->AddEntry(root3_JPt,"dy0j_5f_LO_HerwigPP","F");
  leg->AddEntry(root4_JPt,"dy0j_5f_NLO_HerwigPP","lep");
  leg->Draw("same");


  c2->cd(2);
  root2_JEta->GetXaxis()->SetTitle("Jet #eta");
  root2_JEta->Draw("histe");
  root3_JEta->Draw("histesame");
  root1_JEta->Draw("esame");  
  root4_JEta->Draw("esame");
  

  c2->cd(3);
  root2_JPhi->GetXaxis()->SetTitle("Jet #phi");
  root2_JPhi->Draw("histe");
  root3_JPhi->Draw("histesame");
  root1_JPhi->Draw("esame");
  root4_JPhi->Draw("esame");


  c2->cd(4);
  gPad->SetLogy();
  root2_nJet->GetXaxis()->SetTitle("nGenJet");
  root2_nJet->Draw("histe");
  root3_nJet->Draw("histesame");
  root1_nJet->Draw("esame");
  root4_nJet->Draw("esame");


  gSystem->ProcessEvents();
  TImage *img2 = TImage::Create();
  img2->FromPad(c2);
  img2->WriteImage("canvas5.png");
  delete c2;
  delete img2;






  TCanvas *c3= new TCanvas("c3","",200,10,1600,1600);
  c3->Divide(1,2);
 
  c3->cd(2);
  root2_SumY->GetXaxis()->SetTitle("Rapidity Sum");
  root2_SumY->Draw("histe");
  root3_SumY->Draw("histesame");
  root1_SumY->Draw("esame");
  root4_SumY->Draw("esame");
  
  c3->cd(1);
  root2_DiffY->GetXaxis()->SetTitle("Rapidity Difference");
  root2_DiffY->Draw("histe");
  root3_DiffY->Draw("histesame");
  //root2_DiffY->Draw("histesame");  
  root1_DiffY->Draw("esame");
  root4_DiffY->Draw("esame");
  


  leg = new TLegend(0.6,0.6,0.8,0.8);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(root1_JPt,"dy0j_5f_LO_PYTHIA8","lep");
  leg->AddEntry(root2_JPt,"dy0j_5f_NLO_PYTHIA8","F");
  leg->AddEntry(root3_JPt,"dy0j_5f_LO_HerwigPP","F");
  leg->AddEntry(root4_JPt,"dy0j_5f_NLO_HerwigPP","lep");
  leg->Draw("same");



  gSystem->ProcessEvents();
  TImage *img3 = TImage::Create();
  img3->FromPad(c3);
  img3->WriteImage("canvas6.png");
  delete c3;
  delete img3;






}
