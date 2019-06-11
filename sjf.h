#pragma once
#include<iostream>
#include"fcfs.h"
using namespace std;
class sjf:public fcfs
{
protected:
	int time[100];
public:
	sjf();
	~sjf();
	void sort(int [],int [],int);
	void findWaitingTime(int processes[], int n,
		int bt[], int wt[]);
	void findavgTime(int processes[], int n, int bt[]);
	void put();
	void sort(int[], int [], int[],int);
};

