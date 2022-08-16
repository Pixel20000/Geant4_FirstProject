#ifndef STEPPING_HH
#define STEPPING_HH

//de inclus anumite file...
#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

#include "construction.hh"
#include "event.hh"

//similara cu MyRunAction...
class MySteppingAction : public G4UserSteppingAction
{
  public:
    MySteppingAction(MyEventAction* eventAction);
    ~MySteppingAction();
    
    virtual void UserSteppingAction(const G4Step*); //basic function
    
  private:
    MyEventAction *fEventAction;
};

#endif
