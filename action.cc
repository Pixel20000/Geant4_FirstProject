//clip5_generatig Particles
#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);
    
    //clip8_own(action)
    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);
}

//clip5_generatig Particles
