#include "Process.h"
/*
       Name: Braydon Bieber
      myWSU: removed
Description: Implementation of Process class.
*/


// Getters 
int Process::getID()       { return id;}
int Process::getArrival()  { return arrival_time;}
int Process::getNeeded()   { return time_needed;}
int Process::getFinished() { return finished_time;}


//Setters 
void Process::setFinish(int time) { finished_time = time; }
void Process::setNeeded(int time) { time_needed = time; }



// Parameter Constructor 
Process::Process(int _id, int arrival, int needed) : id( _id ), arrival_time(arrival), time_needed(needed), finished_time(-1) {}