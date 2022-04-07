#pragma once
/*
	   Name: Braydon Bieber
	  myWSU: removed
Description: Declaration of Process class. 
*/
class Process {
private:
	int id;
	int arrival_time;
	int time_needed;
	int finished_time;

public:
	int getID();
	int getArrival();
	int getNeeded();
	int getFinished();
	void setFinish(int time);
	void setNeeded(int time);

	Process(int _id, int arrival, int needed);
};