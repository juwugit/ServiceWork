//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul  9 15:56:33 2014 by ROOT version 5.27/04
// from TTree tree/tree
// found on file: DY0jet_LO.root
//////////////////////////////////////////////////////////

#ifndef temp_h
#define temp_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class temp {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         ptHat;
   Float_t         mcWeight;
   Int_t           nGenPar;
   vector<float>   *genParE;
   vector<float>   *genParPt;
   vector<float>   *genParEta;
   vector<float>   *genParPhi;
   vector<float>   *genParM;
   vector<int>     *genParQ;
   vector<int>     *genParId;
   vector<int>     *genParSt;
   vector<int>     *genMomParId;
   vector<int>     *genParIndex;
   Int_t           nGenEle;
   vector<float>   *genEleE;
   vector<float>   *genElePt;
   vector<float>   *genEleEta;
   vector<float>   *genElePhi;
   vector<float>   *genEleM;
   Int_t           nGenMu;
   vector<float>   *genMuE;
   vector<float>   *genMuPt;
   vector<float>   *genMuEta;
   vector<float>   *genMuPhi;
   vector<float>   *genMuM;
   vector<int>     *genNMo;
   vector<int>     *genNDa;
   vector<int>     *genMo1;
   vector<int>     *genMo2;
   vector<int>     *genDa1;
   vector<int>     *genDa2;
   Int_t           nGenJet;
   vector<float>   *genJetE;
   vector<float>   *genJetPt;
   vector<float>   *genJetEta;
   vector<float>   *genJetPhi;

   // List of branches
   TBranch        *b_ptHat;   //!
   TBranch        *b_mcWeight;   //!
   TBranch        *b_nGenPar;   //!
   TBranch        *b_genParE;   //!
   TBranch        *b_genParPt;   //!
   TBranch        *b_genParEta;   //!
   TBranch        *b_genParPhi;   //!
   TBranch        *b_genParM;   //!
   TBranch        *b_genParQ;   //!
   TBranch        *b_genParId;   //!
   TBranch        *b_genParSt;   //!
   TBranch        *b_genMomParId;   //!
   TBranch        *b_genParIndex;   //!
   TBranch        *b_nGenEle;   //!
   TBranch        *b_genEleE;   //!
   TBranch        *b_genElePt;   //!
   TBranch        *b_genEleEta;   //!
   TBranch        *b_genElePhi;   //!
   TBranch        *b_genEleM;   //!
   TBranch        *b_nGenMu;   //!
   TBranch        *b_genMuE;   //!
   TBranch        *b_genMuPt;   //!
   TBranch        *b_genMuEta;   //!
   TBranch        *b_genMuPhi;   //!
   TBranch        *b_genMuM;   //!
   TBranch        *b_genNMo;   //!
   TBranch        *b_genNDa;   //!
   TBranch        *b_genMo1;   //!
   TBranch        *b_genMo2;   //!
   TBranch        *b_genDa1;   //!
   TBranch        *b_genDa2;   //!
   TBranch        *b_nGenJet;   //!
   TBranch        *b_genJetE;   //!
   TBranch        *b_genJetPt;   //!
   TBranch        *b_genJetEta;   //!
   TBranch        *b_genJetPhi;   //!

   temp(TTree *tree=0);
   virtual ~temp();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef temp_cxx
temp::temp(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DY1jet_LO.root");
      if (!f) {
         f = new TFile("DY1jet_LO.root");
         f->cd("DY1jet_LO.root:/tree");
      }
      tree = (TTree*)gDirectory->Get("tree");

   }
   Init(tree);
}

temp::~temp()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t temp::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t temp::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void temp::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   genParE = 0;
   genParPt = 0;
   genParEta = 0;
   genParPhi = 0;
   genParM = 0;
   genParQ = 0;
   genParId = 0;
   genParSt = 0;
   genMomParId = 0;
   genParIndex = 0;
   genEleE = 0;
   genElePt = 0;
   genEleEta = 0;
   genElePhi = 0;
   genEleM = 0;
   genMuE = 0;
   genMuPt = 0;
   genMuEta = 0;
   genMuPhi = 0;
   genMuM = 0;
   genNMo = 0;
   genNDa = 0;
   genMo1 = 0;
   genMo2 = 0;
   genDa1 = 0;
   genDa2 = 0;
   genJetE = 0;
   genJetPt = 0;
   genJetEta = 0;
   genJetPhi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ptHat", &ptHat, &b_ptHat);
   fChain->SetBranchAddress("mcWeight", &mcWeight, &b_mcWeight);
   fChain->SetBranchAddress("nGenPar", &nGenPar, &b_nGenPar);
   fChain->SetBranchAddress("genParE", &genParE, &b_genParE);
   fChain->SetBranchAddress("genParPt", &genParPt, &b_genParPt);
   fChain->SetBranchAddress("genParEta", &genParEta, &b_genParEta);
   fChain->SetBranchAddress("genParPhi", &genParPhi, &b_genParPhi);
   fChain->SetBranchAddress("genParM", &genParM, &b_genParM);
   fChain->SetBranchAddress("genParQ", &genParQ, &b_genParQ);
   fChain->SetBranchAddress("genParId", &genParId, &b_genParId);
   fChain->SetBranchAddress("genParSt", &genParSt, &b_genParSt);
   fChain->SetBranchAddress("genMomParId", &genMomParId, &b_genMomParId);
   fChain->SetBranchAddress("genParIndex", &genParIndex, &b_genParIndex);
   fChain->SetBranchAddress("nGenEle", &nGenEle, &b_nGenEle);
   fChain->SetBranchAddress("genEleE", &genEleE, &b_genEleE);
   fChain->SetBranchAddress("genElePt", &genElePt, &b_genElePt);
   fChain->SetBranchAddress("genEleEta", &genEleEta, &b_genEleEta);
   fChain->SetBranchAddress("genElePhi", &genElePhi, &b_genElePhi);
   fChain->SetBranchAddress("genEleM", &genEleM, &b_genEleM);
   fChain->SetBranchAddress("nGenMu", &nGenMu, &b_nGenMu);
   fChain->SetBranchAddress("genMuE", &genMuE, &b_genMuE);
   fChain->SetBranchAddress("genMuPt", &genMuPt, &b_genMuPt);
   fChain->SetBranchAddress("genMuEta", &genMuEta, &b_genMuEta);
   fChain->SetBranchAddress("genMuPhi", &genMuPhi, &b_genMuPhi);
   fChain->SetBranchAddress("genMuM", &genMuM, &b_genMuM);
   fChain->SetBranchAddress("genNMo", &genNMo, &b_genNMo);
   fChain->SetBranchAddress("genNDa", &genNDa, &b_genNDa);
   fChain->SetBranchAddress("genMo1", &genMo1, &b_genMo1);
   fChain->SetBranchAddress("genMo2", &genMo2, &b_genMo2);
   fChain->SetBranchAddress("genDa1", &genDa1, &b_genDa1);
   fChain->SetBranchAddress("genDa2", &genDa2, &b_genDa2);
   fChain->SetBranchAddress("nGenJet", &nGenJet, &b_nGenJet);
   fChain->SetBranchAddress("genJetE", &genJetE, &b_genJetE);
   fChain->SetBranchAddress("genJetPt", &genJetPt, &b_genJetPt);
   fChain->SetBranchAddress("genJetEta", &genJetEta, &b_genJetEta);
   fChain->SetBranchAddress("genJetPhi", &genJetPhi, &b_genJetPhi);
   Notify();
}

Bool_t temp::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void temp::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t temp::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef temp_cxx
