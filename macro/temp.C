#define temp_cxx
#include "temp.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>

void temp::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L temp.C
//      Root > temp t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   TH1F* h_genZPt   = new TH1F("h_genZPt","",100,0,300);
   TH1F* h_genZEta  = new TH1F("h_genZEta","",40,-10,10);
   TH1F* h_genZPhi  = new TH1F("h_genZPhi","",40,-4,4);
   TH1F* h_genZMass = new TH1F("h_genZMass","",20,0,200);

   TH1F* h_nGenJet  = new TH1F("h_nGenJet","",10,0,10);
   TH1F* h_genJetPt = new TH1F("h_genJetPt","",100,0,300);
   TH1F* h_genJetEta= new TH1F("h_genJetEta","",30,-4,4);
   TH1F* h_genJetPhi= new TH1F("h_genJetPhi","",40,-4,4);

   TH1F* h_genElePt = new TH1F("h_genElePt","",100,0,300);
   TH1F* h_genEleEta= new TH1F("h_genEleEta","",40,-10,10);
   TH1F* h_genElePhi= new TH1F("h_genElePhi","",40,-4,4);

   TH1F* h_genMuPt  = new TH1F("h_genMuPt","",100,0,300);
   TH1F* h_genMuEta = new TH1F("h_genMuEta","",40,-10,10);
   TH1F* h_genMuPhi = new TH1F("h_genMuPhi","",40,-4,4);


   gROOT->SetStyle("Plain");

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;


      /*
      // ordering Electron array
      for(int i=0; i<nGenEle; i++){
        for(int j=0; j<i; j++){
          if(genElePt->at(i) < genElePt->at(j)){
            swap(genElePt->at(i), genElePt->at(j));
            swap(genEleEta->at(i), genEleEta->at(j));
            swap(genElePhi->at(i), genElePhi->at(j));
          }
        }
      }
      // Ordering Muon
      for(int i=0; i<nGenMu; i++){
        for(int j=0; j<i; j++){
          if(genMuPt->at(i) < genMuPt->at(j)){
            swap(genMuPt->at(i), genMuPt->at(j));
            swap(genMuEta->at(i), genMuEta->at(j));
            swap(genMuPhi->at(i), genMuPhi->at(j));
          }
        }
      }
      // ordering Jet
      for(int i=0; i<nGenJet; i++){
        for(int j=0; j<i; j++){
          if(genJetPt->at(i) < genJetPt->at(j)){
            swap(genJetPt->at(i), genJetPt->at(j));
            swap(genJetEta->at(i), genJetEta->at(j));
            swap(genJetPhi->at(i), genJetPhi->at(j));
          }
        }
      }
      */

      TLorentzVector plus(0,0,0,0);
      TLorentzVector minus(0,0,0,0);

      float plusPtMax=-999;
      float minusPtMax=-999;

      int plusMax=-1;
      int minusMax=-1;

       for(int i=0; i<genParId->size();i++)
	{
	  int PID = genParId->at(i);
	  float pt = genParPt->at(i);
	  int status = genParSt->at(i);
	  if(status!=1)continue;
	  if( (PID== -11 || PID== -13) && 
	      pt > plusPtMax)
	    {
	      plusMax=i;
	      plusPtMax=pt;
	    }

	  else if( (PID== 11 || PID== 13) && 
	      pt > minusPtMax)
	    {
	      minusMax=i;
	      minusPtMax=pt;
	    }
	}

      if(plusMax>=0 && minusMax>=0)
	{

	  plus.SetPtEtaPhiE(
			    genParPt->at(plusMax),
			    genParEta->at(plusMax),
			    genParPhi->at(plusMax),
			    genParE->at(plusMax)
			    );

	  minus.SetPtEtaPhiE(
			    genParPt->at(minusMax),
			    genParEta->at(minusMax),
			    genParPhi->at(minusMax),
			    genParE->at(minusMax)
		            );

	  float m = (plus+minus).M();
	  h_genZMass->Fill(m);

	}


/*
      if( plusMax>=0 && minusMax>=0 ){

        plus.SetPtEtaPhiM(genParPt->at(plusMax),genParEta->at(plusMax),genParPhi->at(plusMax),genParM->at(plusMax));
        minus.SetPtEtaPhiM(genParPt->at(minusMax),genParEta->at(minusMax),genParPhi->at(minusMax),genParM->at(minusMax));

        float zpt=0;
        zpt=(plus+minus).Pt();
        float zmass=0;
        zmass=(plus+minus).M();
        float zeta=0;
        zeta=(plus+minus).Eta();
        float zphi=0;
        zphi=(plus+minus).Phi();

        h_genZPt->Fill(zpt);
        h_genZMass->Fill(zmass);
        h_genZEta->Fill(zeta);
        h_genZPhi->Fill(zphi); 

      }
*/


/*
      // loop Ele
      TLorentzVector ele1(0,0,0,0);
      TLorentzVector ele2(0,0,0,0);
      TLorentzVector Zee(0,0,0,0);
      for(int i=0; i<nGenEle; i++){
        h_genElePt->Fill(genElePt->at(i));
        h_genEleEta->Fill(genEleEta->at(i));
        h_genElePhi->Fill(genElePhi->at(i));
      }


      // loop Mu
      TLorentzVector mu1(0,0,0,0);
      TLorentzVector mu2(0,0,0,0);
      TLorentzVector Zmm(0,0,0,0);
      for(int i=0; i<nGenMu; i++){
        h_genMuPt->Fill(genMuPt->at(i));
        h_genMuEta->Fill(genMuEta->at(i));
        h_genMuPhi->Fill(genMuPhi->at(i));
      }
   


      // loop Jet
      h_nGenJet->Fill(nGenJet);
      if(nGenJet>0){
        h_genJetPt->Fill(genJetPt->at(0));
        h_genJetEta->Fill(genJetEta->at(0));
        h_genJetPhi->Fill(genJetPhi->at(0));
      }
*/


   }// end of entries


/*
   float tZPt=0;
   h_genZPt->Sumw2();
   tZPt=h_genZPt->Integral();
   h_genZPt->Scale(1/tZPt);
   float tZEta=0;
   h_genZEta->Sumw2();
   tZEta=h_genZEta->Integral();
   h_genZEta->Scale(1/tZEta);
   float tZPhi=0;
   h_genZPhi->Sumw2();
   tZPhi=h_genZPhi->Integral();
   h_genZPhi->Scale(1/tZPhi);
   float tZMass=0;
   h_genZMass->Sumw2();
   tZMass=h_genZMass->Integral();
   h_genZMass->Scale(1/tZMass);
   float tNJet=0;
   h_nGenJet->Sumw2();
   tNJet=h_nGenJet->Integral();
   h_nGenJet->Scale(1/tNJet);
   float tJPt=0;
   h_genJetPt->Sumw2();
   tJPt=h_genJetPt->Integral();
   h_genJetPt->Scale(1/tJPt);
   float tJEta=0;
   h_genJetEta->Sumw2();
   tJEta=h_genJetEta->Integral();
   h_genJetEta->Scale(1/tJEta);
   float tJPhi=0;
   h_genJetPhi->Sumw2();
   tJPhi=h_genJetPhi->Integral();
   h_genJetPhi->Scale(1/tJPhi);
   float tEPt=0;
   h_genElePt->Sumw2();
   tEPt=h_genElePt->Integral();
   h_genElePt->Scale(1/tEPt);
   float tEEta=0;
   h_genEleEta->Sumw2();
   tEEta=h_genEleEta->Integral();
   h_genEleEta->Scale(1/tEEta);
   float tEPhi=0;
   h_genElePhi->Sumw2();
   tEPhi=h_genElePhi->Integral();
   h_genElePhi->Scale(1/tEPhi);
   float tMPt=0;
   h_genMuPt->Sumw2();
   tMPt=h_genMuPt->Integral();
   h_genMuPt->Scale(1/tMPt);
   float tMEta=0;
   h_genMuEta->Sumw2();
   tMEta=h_genMuEta->Integral();
   h_genMuEta->Scale(1/tMEta);
   float tMPhi=0;
   h_genMuPhi->Sumw2();
   tMPhi=h_genMuPhi->Integral();
   h_genMuPhi->Scale(1/tMPhi);
*/


   TFile* outFile = new TFile("output_histo.root","recreate");
   h_genZPt->Write();
   h_genZEta->Write();
   h_genZPhi->Write();
   h_genZMass->Write();
   h_nGenJet->Write();
   h_genJetPt->Write();
   h_genJetEta->Write();
   h_genJetPhi->Write();
   h_genElePt->Write();
   h_genEleEta->Write();
   h_genElePhi->Write();
   h_genMuPt->Write();
   h_genMuEta->Write();
   h_genMuPhi->Write();


   outFile->Close();


}

