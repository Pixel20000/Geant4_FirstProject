#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

//Clipul3_ Detector Construction
#include "G4VUserDetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"


#include "G4GenericMessenger.hh"

//Clipul3_ Detector Construction
//clasa

//clip7
#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction //exitsa in G4
{

     public:                           
       MyDetectorConstruction();  //constructor
       ~MyDetectorConstruction(); //destructor
     
     
     //funct. care returneaza vol. logic
     G4LogicalVolume *GetScoringVolume() const {return 
                                                fScoringVolume;}
     
     
     virtual G4VPhysicalVolume *Construct(); //fct care cosntruieste detectorul
     
           
  //clipul7 
     private: 
       G4LogicalVolume *logicDetector;
       virtual void ConstructSDandField(); //for fileds and SD rep.
       
       
       //pentru volumul tinta;
       G4LogicalVolume *fScoringVolume;
       
       
       //o noua asociere(putem sa definim aici volumele);
       G4Box *solidWorld, *solidRadiator, *solidDetector;
       G4LogicalVolume *logicWorld, *logicRadiator;
       G4VPhysicalVolume *physWorld, *physRadiator, *physDetector;
       
       
       //include materials;
       
       G4Material *SiO2, *H2O, *Aerogel, *worldMat;
       G4Element *C;
       
       void DefineMaterials(); //a new function for materials
       G4GenericMessenger *fMessenger;
       
       G4int nCols, nRows;

};

#endif

//Clipul3_ Detector Construction
