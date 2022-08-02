//clip5_generatig Particles
#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh" 
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction //our class
{
  public:
     MyPrimaryGenerator();
     ~MyPrimaryGenerator(); 

  virtual void GeneratePrimaries(G4Event*); //generator function("main")
  
  private:
     G4ParticleGun *fParticleGun;
};

#endif

//clipul5
