#ifndef PHYSICS_HH
#define PHYSICS_HH

//to use the classes...;
#include "G4VModularPhysicsList.hh"
#include "G4EmStandardPhysics.hh"
#include "G4OpticalPhysics.hh"

//crearea unei liste pentru stocarea prop. de interactie
class MyPhysicsList : public G4VModularPhysicsList
{

public:
   MyPhysicsList(); //constr.
   ~MyPhysicsList(); //destr.

};

#endif
