/*
       Name: Braydon Bieber
      myWSU: removed
Description: Simulate round-robin scheduling with a queue
*/

#include <iostream>
#include <fstream>
#include <queue>
#include "Process.h"

using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::ifstream;

int main()
{
    queue<Process*>scheduling;
    vector<Process>process, finished;
    ifstream readtxt("round_robin.txt");
    int id, arrival, needed, time = 0, timeTotal = 0;

    for (int i = 0; i < 5; ++i) {
        readtxt >> id >> arrival >> needed; // assumption of good formatting 
        process.push_back(Process(id, arrival, needed)); // construct and store 
    }

    // checking to make sure all processes are not finished. All finished means all of them have time needed of zero and a sum of zeros is zero. 
    while (true) {
        // Update Schedule for Arrivals
        for (int i = 0; i < 5; ++i) 
            if (timeTotal == process[i].getArrival())
                scheduling.push(&process[i]);

        // if we are not still in time quota for updating queue and queue is not empty  
        if (!scheduling.empty() && ( (time > 0 && time % 4 == 0) || scheduling.front()->getNeeded() == 0)) { // pop and store the process at the back of queue 
            if (scheduling.front()->getNeeded() > 0) {
                scheduling.push(scheduling.front());
                scheduling.pop();
            }
            else { // update finished field pop and store process in finished vector
                scheduling.front()->setFinish(timeTotal);
                finished.push_back(*scheduling.front()); 
                scheduling.pop();
            }
            time = 0;
        }
        //let loop store finished result before breaking. 
        if ((process[0].getNeeded() + process[1].getNeeded() + process[2].getNeeded() + process[3].getNeeded() + process[4].getNeeded()) == 0)
            break;
        if (!scheduling.empty() && scheduling.front()->getNeeded() > 0)
             scheduling.front()->setNeeded(scheduling.front()->getNeeded() - 1);
        time++;
        timeTotal++;
    }

    // print finished processes in finishing order
    for (auto v : finished) {   
        cout << "ID: " << v.getID() << " Arrival: " << v.getArrival() << " Needed: " << v.getNeeded() << " Finished: " << v.getFinished();
        cout << endl;
    }
    
    return 0;
}



/*
CS 400 Assignment 6
Round Robin Simulation

Description:
Write a program that utilizes STL queue (or your own queue implementation) that simulates the round robin process scheduling algorithm.

Requirement:
- write a class Process that holds following integer information: id, arrival_time, time_needed, finished_time.
- read and initiate 5 Process objects from associated file (round_robin.txt)
- file format: id, arrival_time, time_needed
- once a process is finished, mark its finished_time accordingly.
- CPU time frame: 4.
- utilize a queue for process scheduling.
- store finished processes into a vector (first finished, first stored)
- output: print information about finished processes from the vector, in the finished order.

File_name:
- round_robin.cpp
- You may use extra source files for class Process.
*/