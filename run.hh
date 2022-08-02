//clip8 stocare date(hits data ) intr-un Root file
#ifndef RUN_HH
#define RUN_HH

#include "G4AnalysisManager.hh"
#include "G4UserRunAction.hh"

class MyRunAction : public G4UserRunAction //define a class for action 
{

 public:
   MyRunAction();
   ~MyRunAction();
 
 //virtual functions for run;
   virtual void BeginOfRunAction(const G4Run*);
   virtual void EndOfRunAction(const G4Run*);

};

#endif
