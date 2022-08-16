#include "run.hh"
//clip8_part2 Storing Hits in ROOT File

MyRunAction::MyRunAction()
{  
   G4AnalysisManager *man = G4AnalysisManager::Instance();
   
   man->OpenFile("output.root"); //deschide o fila tip root - pentru a afisa ce rezulta / event
    
   man->CreateNtuple("Hits", "Hits");
   man->CreateNtupleIColumn("fEvent"); //give names for colum.
   
 //FOR COORD. NAMES- DET. POSITION
   man->CreateNtupleDColumn("fX");
   man->CreateNtupleDColumn("fY");
   man->CreateNtupleDColumn("fZ");
   man->FinishNtuple(0);

//pentru volumul tinta; 
    man->CreateNtuple("Scoring", "Scoring");
    man->CreateNtupleDColumn("fEdep");
    man->FinishNtuple(1);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{
   G4AnalysisManager *man = G4AnalysisManager::Instance();
   
   //pentru a nu suprascrie output-ul
   G4int runID = run->GetRunID();
   
   std::stringstream strRunID;
   strRunID << runID;
   
   man->OpenFile("output"+ strRunID.str() +".root"); //deschide o fila tip root - pentru a afisa ce rezulta / event
  
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
   G4AnalysisManager *man = G4AnalysisManager::Instance();
   
   man->Write();
   man->CloseFile();
}
