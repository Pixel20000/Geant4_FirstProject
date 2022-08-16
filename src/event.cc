#include "event.hh"

//constructorul;
MyEventAction::MyEventAction(MyRunAction*)
{
    fEdep = 0.; //valoarea de start
}


//destructorul
MyEventAction::~MyEventAction()
{}


//cea mai importanta fct. ptr inceput;
void MyEventAction::BeginOfEventAction(const G4Event*)
{
    fEdep = 0.; //energia este setata la 0(la fiecare start, de fiecare data)
}


void MyEventAction::EndOfEventAction(const G4Event*)
{   //afisez val energiei depozitate;
    G4cout << "Energia depozitata: " << fEdep << G4endl;

    //accesarea unui manager pentru analiza distrib de energie depozitata
    G4AnalysisManager *man = G4AnalysisManager::Instance();
    
    //umplem lista cu valori;
    man->FillNtupleDColumn(1, 0, fEdep); //a new Tuple
    
    man->AddNtupleRow(1); //generam o alta intrare/row - pentru distributia de valori
}

//A tuple is a finite ordered list (sequence) of elements
