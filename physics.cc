#include "physics.hh"

MyPhysicsList::MyPhysicsList()
{
    RegisterPhysics (new G4EmStandardPhysics()); //Register for elm interaction
    RegisterPhysics (new G4OpticalPhysics());  //... for light

}

MyPhysicsList::~MyPhysicsList()
{}

//clipul4 phyList
