#include <iostream>

#include "G4RunManager.hh"

//Simple Cherenkov Detector- all lib.(manager)
#include "G4UImanager.hh"
#include "G4VisManager.hh"

//executorul
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

//include headers
#include "construction.hh"
#include "physics.hh"
#include "action.hh"


// fct main;

int main(int argc, char** argv)
{
   G4RunManager *runManager = new G4RunManager();

   runManager->SetUserInitialization(new MyDetectorConstruction()); //use created geometry... detector construction
   runManager->SetUserInitialization(new MyPhysicsList()); //use created list... Physics list with prop.
   runManager->SetUserInitialization(new MyActionInitialization()); //use particle init.
   
   runManager->Initialize();
    
   G4UIExecutive *ui = 0;
   
   //nr comand lines =1 
  
   if(argc == 1)
   {
      ui = new G4UIExecutive(argc, argv);
   }

   
   // Initialize visualization
   G4VisManager *visManager= new G4VisExecutive();
   visManager->Initialize();

   G4UImanager *UImanager = G4UImanager::GetUIpointer();
   
   if(ui)
   {
    // I interactive mode;
   
   //to execute the vis.mac
   UImanager->ApplyCommand("/control/execute vis.mac");
   ui->SessionStart();
   //vis include mai multe sub-domenii
  }
 
  else //caz contrar
  {  // II batch mode;
  
     G4String command = "/control/execute";
     G4String fileName = argv[1];
     UImanager->ApplyCommand(command+fileName);
  
  }
   return 0;
}


//Clipul2_3_first

// ./sim ->G4Backtrace is activated 

// . software/geant4/geant4-v11.0.2-install/share/Geant4-11.0.2/geant4make/geant4make.sh ->activare librarii G4
// cmake .. -> for build files(config. + generating)
//make -> for compile and scanning (build target)
