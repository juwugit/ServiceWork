//root -q -b -l juwu.C++\(\"inputFile\"\,\"outputFile\"\)


#include <vector>
#include <iostream>
#include <algorithm>
#include <TH1D.h>
#include <TRandom.h>
#include <TLorentzVector.h>
#include <TFile.h>
#include "macro/untuplizer.h"


using namespace std;
void juwu(std::string inputFile, std::string outputFile){


  //get TTree from file ...
  TreeReader data(inputFile.data());


  //histogram anoucement
  TH1F* h_genZPt   = new TH1F("h_genZPt","",100,0,300);
  TH1F* h_genZEta  = new TH1F("h_genZEta","",40,-10,10);
  TH1F* h_genZPhi  = new TH1F("h_genZPhi","",40,-4,4);
  TH1F* h_genZMass = new TH1F("h_genZMass","",20,0,200);

  TH1F* h_nGenJet  = new TH1F("h_nGenJet","",10,0,10);
  TH1F* h_genJetPt = new TH1F("h_genJetPt","",100,0,300);
  TH1F* h_genJetEta= new TH1F("h_genJetEta","",30,-4,4);
  TH1F* h_genJetPhi= new TH1F("h_genJetPhi","",40,-4,4);

  TH1F* h_SumY     = new TH1F("h_SumY","",40,-4.5,4.5);
  TH1F* h_DiffY    = new TH1F("h_DiffY","",40,-4.5,4.5);


  h_genZMass->Sumw2();
  h_genZPt->Sumw2();
  h_genZEta->Sumw2();
  h_genZPhi->Sumw2();
  h_nGenJet->Sumw2();
  h_genJetPt->Sumw2();
  h_genJetEta->Sumw2();
  h_genJetPhi->Sumw2();
  h_DiffY->Sumw2();
  h_SumY->Sumw2();




  //Event loop
  for(long jEntry=0; jEntry<data.GetEntriesFast() ;jEntry++){

    data.GetEntry(jEntry);

    Int_t    nGenPar     = data.GetInt("nGenPar");
    Float_t* genParE     = data.GetPtrFloat("genParE");
    Float_t* genParPt    = data.GetPtrFloat("genParPt");
    Float_t* genParEta   = data.GetPtrFloat("genParEta");
    Float_t* genParPhi   = data.GetPtrFloat("genParPhi");
    Float_t* genParM     = data.GetPtrFloat("genParM");
    Int_t*   genParQ     = data.GetPtrInt("genParQ");
    Int_t*   genParId    = data.GetPtrInt("genParId");
    Int_t*   genParSt    = data.GetPtrInt("genParSt");
    Int_t*   genMomParId = data.GetPtrInt("genMomParId");
    Int_t    nGenJet     = data.GetInt("nGenJet");
    Float_t* genJetPt    = data.GetPtrFloat("genJetPt");
    Float_t* genJetEta   = data.GetPtrFloat("genJetEta");
    Float_t* genJetPhi   = data.GetPtrFloat("genJetPhi");
    Float_t* genJetE     = data.GetPtrFloat("genJetE");
    Float_t  weight      = data.GetFloat("mcWeight");


    if(weight>0) weight=1;
    else if(weight<0) weight=-1;



    cout<<"mcWeight:"<<weight<<endl;
    

    TLorentzVector plus(0,0,0,0);
    TLorentzVector minus(0,0,0,0);

    float plusPtMax=-999;
    float minusPtMax=-999;

    int plusMax=-1;
    int minusMax=-1;

    for(int i=0; i<nGenPar; i++){

	int PID = genParId[i];
	float pt = genParPt[i];
	int status = genParSt[i];

	if(status!=1)continue;

	if( (PID== -11 || PID== -13) && pt > plusPtMax){
		plusMax=i;
		plusPtMax=pt;
	}

	else if( (PID== 11 || PID== 13) && pt > minusPtMax){
		minusMax=i;
		minusPtMax=pt;
	}
    }
    
    if(plusMax>=0 && minusMax>=0){

      plus.SetPtEtaPhiE(genParPt[plusMax],genParEta[plusMax],genParPhi[plusMax],genParE[plusMax]);
      minus.SetPtEtaPhiE(genParPt[minusMax],genParEta[minusMax],genParPhi[minusMax], genParE[minusMax]);
      
      float zm   = (plus+minus).M();
      float zpt  = (plus+minus).Pt();
      float zeta = (plus+minus).Eta(); 
      float zphi = (plus+minus).Phi();
      
      h_genZMass->Fill(zm,weight);
      h_genZPt->Fill(zpt,weight);
      h_genZEta->Fill(zeta,weight);
      h_genZPhi->Fill(zphi,weight);
	  
    }
    
    
    TLorentzVector jet_l4(0,0,0,0);
    float jetPtMax=-999;
    int countjet=0;
    
    for(int j=0; j<nGenJet;j++){
	
	TLorentzVector thisJet(0,0,0,0);
	thisJet.SetPtEtaPhiE(genJetPt[j],genJetEta[j],genJetPhi[j],genJetE[j]);
	
	
	if(plusMax>=0)
	  {
	    float dR= thisJet.DeltaR(plus);
	    if(dR<0.5)continue;
	  }
	
	if(minusMax>=0)
	  {
	    float dR= thisJet.DeltaR(minus);
	    if(dR<0.5)continue;
	  }
	if(thisJet.Pt()>jetPtMax)
	  {
	    jet_l4 = thisJet;
	    jetPtMax = thisJet.Pt();
	  }
	
	countjet++;	
	
    } // loop jet
    
     h_nGenJet->Fill(countjet,weight);

     
     if(jetPtMax>0){
	 
	 h_genJetPt->Fill(jet_l4.Pt(),weight);
	 h_genJetEta->Fill(jet_l4.Eta(),weight);
	 h_genJetPhi->Fill(jet_l4.Phi(),weight);
	 
	 
	 if(plusMax>=0 && minusMax>=0){
	   
	   float ydif = 0.5*(((plus+minus).Rapidity())-(jet_l4.Rapidity()));
	   float ysum = 0.5*(((plus+minus).Rapidity())+(jet_l4.Rapidity()));
	   
	   h_DiffY->Fill(ydif,weight);
	   h_SumY->Fill(ysum,weight);
	   
	 } 
     }


  } // entries     

  
  
     
     
  //normalization
  h_genZPt->Scale(1/(h_genZPt->Integral()));                                                                       
  h_genZEta->Scale(1/(h_genZEta->Integral()));                             
  h_genZPhi->Scale(1/(h_genZPhi->Integral()));                                        
  h_genZMass->Scale(1/h_genZMass->Integral());                                        
  h_nGenJet->Scale(1/(h_nGenJet->Integral()));                                                   
  h_genJetPt->Scale(1/(h_genJetPt->Integral()));                                                              
  h_genJetEta->Scale(1/(h_genJetEta->Integral()));                               
  h_genJetPhi->Scale(1/(h_genJetPhi->Integral()));
  h_SumY->Scale(1/(h_SumY->Integral()));
  h_DiffY->Scale(1/(h_DiffY->Integral()));
  
  
  
  //save output
  TFile* outFile = new TFile(outputFile.data(),"recreate");
  
  h_genZPt->Write();        
  h_genZEta->Write();     
  h_genZPhi->Write(); 
  h_genZMass->Write();
  h_nGenJet->Write();
  h_genJetPt->Write();
  h_genJetEta->Write();
  h_genJetPhi->Write();
  h_SumY->Write();
  h_DiffY->Write();
     
  
  outFile->Close();
  
     
}
