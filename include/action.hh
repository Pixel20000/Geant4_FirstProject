#ifndef ACTION_HH
#define ACTION_HH

//use a class for action init. 
#include "G4VUserActionInitialization.hh" 

//include system generator
#include "generator.hh"
#include "run.hh"


//event+step
#include "event.hh"
#include "stepping.hh"


//class for action initialization
class MyActionInitialization : public G4VUserActionInitialization //our class
{
  public:
     MyActionInitialization();
     ~MyActionInitialization(); 

  virtual void BuildForMaster() const;
  virtual void Build() const; //particle gun function("main") - compute the steps... build particles
};

#endif
