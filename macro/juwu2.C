//root -q -b -l juwu2.C++\(\"inputFile\"\,\"outputFile\"\)


#include <vector>
#include <iostream>
#include <algorithm>
#include <TH1D.h>
#include <TRandom.h>
#include <TLorentzVector.h>
#include <TFile.h>
#include "macro/untuplizer.h"


using namespace std;
void juwu2(std::string inputFile, std::string outputFile){


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

	  h_genZMass->Fill(zm);
          h_genZPt->Fill(zpt);
          h_genZEta->Fill(zeta);
          h_genZPhi->Fill(zphi);

     }


     
     TLorentzVector thisJet(0,0,0,0);
     bool overlape=false;
     double Jp=-999;
     double Jm=-999;


     for(int i=0; i<nGenJet; i++){
       for(int j=0; j<i; j++){
         
	 if(genJetPt[i]>genJetPt[j]){

		swap(genJetPt[i],genJetPt[j]);
		swap(genJetEta[i],genJetEta[j]);
		swap(genJetPhi[i],genJetPhi[j]);
		swap(genJetE[i],genJetE[j]);
		
         }

       }//for2
     }//for1



     for(int i=0; i<nGenJet; i++){

     thisJet.SetPtEtaPhiE(genJetPt[i],genJetEta[i],genJetPhi[i],genJetE[i]);

     if(plusMax>=0)  Jp = thisJet.DeltaR(plus);
     if(minusMax>=0) Jm = thisJet.DeltaR(minus);
     if((Jp<0.5 && Jp>=0) || (Jm<0.5 && Jm>=0)) overlape=true;
     }                                                                                                                
     if(overlape==true)continue;




     h_nGenJet->Fill(nGenJet);

     TLorentzVector leadJet(0,0,0,0);

     if(nGenJet>0){

     leadJet.SetPtEtaPhiE(genJetPt[0],genJetEta[0],genJetPhi[0],genJetE[0]);
     double JetY=leadJet.Rapidity();
     double SumY=-999;
     double DiffY=-999;

     if(plusMax>=0 && minusMax>=0){
       SumY=(JetY+((plus+minus).Rapidity()))*0.5;
       DiffY=(JetY-((plus+minus).Rapidity()))*0.5;

       if(SumY!=-999 && DiffY!=-999){
       h_SumY->Fill(SumY);
       h_DiffY->Fill(DiffY);
       }
     }


     h_genJetPt->Fill(genJetPt[0]);
     h_genJetEta->Fill(genJetEta[0]);
     h_genJetPhi->Fill(genJetPhi[0]);

     }



  } //entries 

    

  
  //normalization
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
  float tsy=0;
  h_SumY->Sumw2();
  tsy=h_SumY->Integral();
  h_SumY->Scale(1/tsy);
  float tdy=0;
  h_DiffY->Sumw2();
  tdy=h_DiffY->Integral();
  h_DiffY->Scale(1/tdy);
  




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
