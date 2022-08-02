#include <iostream>

#include "G4RunManager.hh"


//Simple Cherenkov Detector
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.hh"
#include "physics.hh"
#include "action.hh"


int main(int argc, char** argv)
{
   G4RunManager *runManager = new G4RunManager();

   runManager->SetUserInitialization(new MyDetectorConstruction()); //use created geometry
   runManager->SetUserInitialization(new MyPhysicsList()); //use created geometry
   runManager->SetUserInitialization(new MyActionInitialization()); //use particle init.
   
   runManager->Initialize();
    
   G4UIExecutive *ui = new G4UIExecutive(argc, argv);

   G4VisManager *visManager= new G4VisExecutive();
   visManager->Initialize();

   G4UImanager *UImanager = G4UImanager::GetUIpointer();
   
   //clip4
   UImanager->ApplyCommand("/vis/open OGL"); //for view/interface
   UImanager->ApplyCommand("/vis/drawVolume"); //show motherVolume
   
   //clip5_generare part.
   UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true"); // auto reimprospatare
   UImanager->ApplyCommand("/vis/scene/add/trajectories smooth"); //for tracks
   UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate"); //toate event-urile dintr-un singur run
   
   ui->SessionStart();

 
}


//Clipul2_3_first

// ./sim ->G4Backtrace is activated 

// . software/geant4/geant4-v11.0.2-install/share/Geant4-11.0.2/geant4make/geant4make.sh
// cmake .. -> for build files(config. + generating)
//make -> for compile and scanning (build target)
