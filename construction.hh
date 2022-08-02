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
//Clipul3_ Detector Construction
//clasa

//clip7
#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction //exitsa in G4
{

     public:                           
       MyDetectorConstruction();  //constructor
       ~MyDetectorConstruction(); //destructor
     
     virtual G4VPhysicalVolume *Construct(); //fct care cosntruieste detectorul
     
           
  //clipul7 
    private: 
       G4LogicalVolume *logicDetector;
  
     virtual void ConstructSDandField(); //for fileds and SD rep.
};

#endif

//Clipul3_ Detector Construction
