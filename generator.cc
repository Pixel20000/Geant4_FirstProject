 #include "generator.hh" //include file 
 
 MyPrimaryGenerator::MyPrimaryGenerator() //create particle
 {
   fParticleGun = new G4ParticleGun(1); //1 primary vertex/event
 }
 
  MyPrimaryGenerator::~MyPrimaryGenerator() //delete particle
 {
   delete fParticleGun;
 }
 
 //basic function
 void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
 {
     G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable(); //stored particle prop. in table
     G4String particleName = "proton"; //name of the part.
     G4ParticleDefinition *particle = particleTable->FindParticle("proton"); //find particle and copy inf about the particle
     
     //vectors def.
     G4ThreeVector pos(0.,0.,0.); //position vector- cennter
     G4ThreeVector mom(0.,0.,1.); //z direction - momentum vector
     
     //special function for particle
     
     fParticleGun->SetParticlePosition(pos); //for position(in center)
     fParticleGun->SetParticleMomentumDirection(mom); //for z dir
     fParticleGun-> SetParticleMomentum(100 *GeV); //for momentum... in natural units
     fParticleGun->SetParticleDefinition(particle); //for identity
     
     fParticleGun->GeneratePrimaryVertex(anEvent); //generate primary vertex for event
 }
 
 //clipul5
