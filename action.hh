//clip5_generatig Particles

#ifndef ACTION_HH
#define ACTION_HH

#include "G4VUserActionInitialization.hh" 
#include "generator.hh"

//clip8
#include "run.hh"

class MyActionInitialization : public G4VUserActionInitialization //our class
{
  public:
     MyActionInitialization();
     ~MyActionInitialization(); 

  virtual void Build() const; //particle gun function("main")
};

#endif
