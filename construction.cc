#include "construction.hh"

 MyDetectorConstruction::MyDetectorConstruction()
 {}

 MyDetectorConstruction::~MyDetectorConstruction()
 {}
 
 //geometry and material
 G4VPhysicalVolume *MyDetectorConstruction::Construct() 
 {
    G4NistManager *nist = G4NistManager::Instance();
     
    //particular aerogel:(special material _ clip 6)
    
    //material1 SiO2
    G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2); //(formula, density, components)
    SiO2->AddElement(nist->FindOrBuildElement("Si"),1);
    SiO2->AddElement(nist->FindOrBuildElement("O"),2);
    
    
    //material2 H20
    G4Material *H2O = new G4Material("H2O",1.000*g/cm3, 2); //(formula, density, components)
    H2O->AddElement(nist->FindOrBuildElement("H"),2);
    H2O->AddElement(nist->FindOrBuildElement("O"),1);
    
    G4Element *C = nist->FindOrBuildElement("C"); //Carbon element("material" 3)
    
    G4Material *Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
    
    //composition(procents)
    Aerogel->AddMaterial(SiO2, 62.5*perCent);
    Aerogel->AddMaterial(H2O, 37.4*perCent);
    Aerogel->AddElement(C, 0.1*perCent);
    
    
    //indici de refractie(CLIP6) - for Cher. radiation angle
    G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2}; // first array - REFRACTIVE INDEX (material property vector)
    G4double rindexAerogel[2] = {1.1, 1.1};
    
    G4double rindexWorld[2] = {1.0, 1.0};
    
    G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
    mptAerogel->AddProperty("RINDEX", energy,  rindexAerogel, 2); // indice de refractie - prop de material
    
    Aerogel->SetMaterialPropertiesTable(mptAerogel); //insert material prop. table
    
    
    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR"); //MATERIAL + WorldVolume
    
    
    //for world material
    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2); //adauga prop
    
    worldMat->SetMaterialPropertiesTable(mptWorld);
    
    //1)solid + 2)logical + 3)physical (volume)( x3 volumes) - box VOLUME World
    
    G4Box *solidWrold = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);
    
    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWrold, worldMat, "logicWorld"); //a class for logical volume
    
    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //motherVolume
    
    
    
    //radiator box(clip6) - plate
    G4Box *solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m); //relativ subtire
    
    G4LogicalVolume *logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicRadiator"); //logical Volume Radiator
    
    G4VPhysicalVolume *physRadiator = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true); //motherVolume(no rotation, translation shift, logical volume, name, mother Volume)
    
    
    
   //clip7 - matrix with fotosensors 1
   
   //each detector(dimensions)
     G4Box *solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m, 0.01*m);
     
   //Logical Volume for fotosen.
    logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");
     
   //array with small sensitive detectors(matrix 100x100 cells)- phys. volumes
      for( G4int i=0; i<100; i++)
        {
           for(G4int j=0; j<100; j++)
            {
            
     G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/100, -0.5*m+(j+0.5)*m/100, 0.49*m), logicDetector, "physDetector", logicWorld, false, j+i*100, true); //false- not bool  + index of detector      
             }
         }    
    
    
    return physWorld;
 }
 
 //clip7;
 
 void MyDetectorConstruction::ConstructSDandField()
 {    //createan object
      MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
      
      //logic det. part
      logicDetector->SetSensitiveDetector(sensDet);  
 }
 
 //Clipul3_Detector_Construction
