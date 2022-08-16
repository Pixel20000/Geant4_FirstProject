#include "stepping.hh"


//definim constructorul
MySteppingAction::MySteppingAction(MyEventAction *eventAction)
{
  fEventAction = eventAction; //accesam obiectul creat
}

//definim destructorul
MySteppingAction::~MySteppingAction()
{}


void MySteppingAction::UserSteppingAction(const G4Step *step)
{                                                                                                                
     G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume(); //lant
    
     const MyDetectorConstruction *detectorConstruction = static_cast<const MyDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    
     G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
    
     if(volume != fScoringVolume)
        return; // volumul tinta trebuie sa fie cel specificat
    
    G4double edep = step->GetTotalEnergyDeposit(); //obt energia totala/step
    fEventAction->AddEdep(edep); // acumulare;
}
