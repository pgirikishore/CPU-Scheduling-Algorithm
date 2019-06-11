#pragma once
// C++ program for implementation of FCFS
// scheduling with different arrival time
#include<iostream>
using namespace std;


class vir
{
public:
	virtual void put() = 0;
};



class fcfs:public vir
{
protected:
	int time[100];
public:
	fcfs();
	~fcfs();
	friend void findWaitingTime(int processes[], int n, int bt[],
		int wt[], int at[]);
	void findTurnAroundTime(int processes[], int n, int bt[],
		int wt[], int tat[]);
	void findavgTime(int processes[], int n, int bt[], int at[]);
	
	void put();
};

