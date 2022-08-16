#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::BuildForMaster() const
{
    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
}

void MyActionInitialization::Build() const
{ 
  //Generate the particles
  MyPrimaryGenerator *generator = new MyPrimaryGenerator();
  SetUserAction(generator);

  //divizarea de tip ...action;
  //
  MyRunAction *runAction = new MyRunAction();
  SetUserAction(runAction);
  
  //
  MyEventAction *eventAction = new MyEventAction(runAction);
  SetUserAction(eventAction);
  
  //
  MySteppingAction *steppingAction = new MySteppingAction(eventAction);
  SetUserAction(steppingAction);
  
}
