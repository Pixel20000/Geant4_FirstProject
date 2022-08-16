#ifndef EVENT_HH //if not define... then define
#define EVENT_HH

//Avem nevoie de;
#include "G4UserEventAction.hh"
#include "G4Event.hh"

//to store
#include "G4AnalysisManager.hh"

//to access the runAction
#include "run.hh"

//root
#include "G4AnalysisManager.hh"

//my class public derive ...
class MyEventAction : public G4UserEventAction
{
  public:
    MyEventAction(MyRunAction*);
    ~MyEventAction();
    
    //moments of the EVENT - 2 functii virtuale ... (membre)
    virtual void BeginOfEventAction(const G4Event*); //ce se intampla la inceput...
    virtual void EndOfEventAction(const G4Event*); //ce se intampla la sfarsit...
    
    void AddEdep(G4double edep) { 
                                  fEdep += edep; } //fct. de transfer a energiei depozitate(tip double)
    
  private:
    G4double fEdep; //energia depozitata este privata
};

#endif
