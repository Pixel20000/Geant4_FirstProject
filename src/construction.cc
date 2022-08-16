#include "construction.hh"

 MyDetectorConstruction::MyDetectorConstruction()
 {
  //create a MESSENGER_Editor

   fMessenger = new G4GenericMessenger(this, "/detector/", "Detector Construction");
   
   fMessenger->DeclareProperty("nCols", nCols, "Number of columns");
   fMessenger->DeclareProperty("nRows", nRows, "Number of rows");
    
    
   //nr de coloane si de linii 
   nCols=100;
   nRows=100;
   
   DefineMaterials();
 }

 MyDetectorConstruction::~MyDetectorConstruction()
 {}
 
 void MyDetectorConstruction::DefineMaterials()
 {
     G4NistManager *nist = G4NistManager::Instance();
     
    //mat1
    SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2); //(formula, density, components)
    SiO2->AddElement(nist->FindOrBuildElement("Si"),1);
    SiO2->AddElement(nist->FindOrBuildElement("O"),2);
    
    //mat2
    H2O = new G4Material("H2O",1.000*g/cm3, 2); //(formula, density, components)
    H2O->AddElement(nist->FindOrBuildElement("H"),2);
    H2O->AddElement(nist->FindOrBuildElement("O"),1);
     
    //mat3
    C = nist->FindOrBuildElement("C"); 
    
    
    //mat4
    Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3); 

    //composition(procents)
    Aerogel->AddMaterial(SiO2, 62.5*perCent);
    Aerogel->AddMaterial(H2O, 37.4*perCent);
    Aerogel->AddElement(C, 0.1*perCent);
    
    //worldMaterial
    worldMat = nist->FindOrBuildMaterial("G4_AIR");
    
 
    G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2}; // first array - REFRACTIVE INDEX (material property vector)
    G4double rindexAerogel[2] = {1.1, 1.1};
    G4double rindexWorld[2] = {1.0, 1.0};
    
    

     //for world material and aerogel
    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();

    Aerogel->SetMaterialPropertiesTable(mptAerogel);
    worldMat->SetMaterialPropertiesTable(mptWorld);

    mptAerogel->AddProperty("RINDEX", energy,  rindexAerogel, 2);
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2);

 }
 
 //all geometry and material
 G4VPhysicalVolume *MyDetectorConstruction::Construct() 
 {
    

    //indici de refractie(CLIP6) - for Cher. radiation angle
    
      G4double xWorld=0.5*m;
      G4double yWorld=0.5*m;
      G4double zWorld=0.5*m;
    
    
    //1)solid + 2)logical + 3)physical (volume)( x3 volumes) - box VOLUME World
    
    solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);
    
    logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld"); //a class for logical volume
    
    physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //motherVolume
    
    
    
    //radiator box(clip6) - plate
    solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m); //relativ subtire
    
    logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator"); //logical Volume Radiator
    
    //stabilim volumul tinta care incaseaza doza;
    fScoringVolume = logicRadiator;
    
    physRadiator = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true); //motherVolume(no rotation, translation shift, logical volume, name, mother Volume)
    
    
    
   //clip7 - matrix with fotosensors 1
   
   //each detector(dimensions)
    solidDetector = new G4Box("solidDetector", xWorld/nRows, yWorld/nCols, 0.01*m);
     
   //Logical Volume for fotosen.
    logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");
     
   //array with small sensitive detectors(matrix 100x100 cells)- phys. volumes
      for( G4int i=0; i<nRows; i++)
        {
           for(G4int j=0; j<nCols; j++)
            {
            
    physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/nRows, -0.5*m+(j+0.5)*m/nCols, 0.49*m), logicDetector, "physDetector", logicWorld, false, j+i*nCols, true); //false- not bool  + index of detector      
             }
         }    
    
    
    return physWorld;
 }
 
 //clip7;
 
 void MyDetectorConstruction::ConstructSDandField()
 {    //createan object
      MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
      
      //logic det. part

     if(logicDetector != NULL)
      logicDetector->SetSensitiveDetector(sensDet);  
 }
 
 //Clipul3_Detector_Construction
