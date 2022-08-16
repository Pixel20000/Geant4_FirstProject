//clip5_generatig Particles
#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh" //legatura cu actionInitialization

#include "G4ParticleGun.hh"   // construct the particle gun
#include "G4ParticleTable.hh" // clasa- pentru a stoca proprietatile intr-o lista
#include "G4SystemOfUnits.hh" // clasa- SI


class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction //our class
{
  public: //specificatorul de acces; 
     MyPrimaryGenerator();    //accesibile de oriunde
     ~MyPrimaryGenerator(); 

  virtual void GeneratePrimaries(G4Event*); //generator function("main") crate the primaries
  
  private:  
     G4ParticleGun *fParticleGun; // particle gun fct.
};

#endif
