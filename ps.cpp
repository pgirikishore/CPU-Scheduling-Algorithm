#include "stdafx.h"
#include "ps.h"


ps::ps()
{
}


ps::~ps()
{
}

void ps::put()
{
	int processes[100], n;

	cout << "Enter the number of processes:";
	cin >> n;

	int burst_time[100],priority[100];

	for (int i = 1;i <= n;i++)
	{
		processes[i] = i;
	}

	cout << "Enter the burst time and priority" << endl;

	for (int i = 0;i < n;i++)
	{
		cout << i + 1 <<".Burst Time=" ;
		cin >> burst_time[i];
		cout << "Priority=";
			cin>>priority[i];
			cout << endl;
		time[i] = i + 1;

	}
	
	sort(processes, burst_time,priority, n);



	
}