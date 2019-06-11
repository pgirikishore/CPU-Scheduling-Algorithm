#include "stdafx.h"
#include "fcfs.h"


fcfs::fcfs()
{
	
}


fcfs::~fcfs()
{
}
void  findWaitingTime(int processes[], int n, int bt[],
	int wt[], int at[])
{
	int *service_time=new int[n];
	for (int i = 0;i < n;i++) { service_time[i] = 0; }
	wt[0] = 0;

	for (int i = 1; i < n; i++)
	{
		
	service_time[i] = service_time[i-1]+bt[i-1];
		wt[i] = service_time[i] - at[i];

		if (wt[i] < 0)
			wt[i] = 0;
		
	}
	delete service_time;
}


void fcfs::findTurnAroundTime(int processes[], int n, int bt[],
	int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}
void fcfs:: findavgTime(int processes[], int n, int bt[], int at[])
{
	int *wt = new int[n];
	int *tat = new int[n];
	for (int i = 0;i < n;i++) { wt[i] = 0; }
	for (int i = 0;i < n;i++) { tat[i] = 0; }
	
	findWaitingTime(processes, n, bt, wt, at);

	findTurnAroundTime(processes, n, bt, wt, tat);

	
	cout << "Processes " << " Burst Time " << " Arrival Time "
		<< " Waiting Time " << " Turn-Around Time "
		<< " Completion Time \n";
	int total_wt = 0, total_tat = 0;
	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		int compl_time = tat[i] + at[i];
		cout << " " << time[i] << "\t\t" << bt[i] << "\t\t"
			<< at[i] << "\t\t" << wt[i] << "\t\t "
			<< tat[i] << "\t\t " << compl_time << endl;
	}
	try {
		if (n == 0) throw n;
		cout << "Average waiting time = "
			<< (float)total_wt / (float)n;
		cout << "\nAverage turn around time = "
			<< (float)total_tat / (float)n;
		delete wt, tat;
	}
	catch (...)
	{
		cout << "Divide by zero";
	}
}

void fcfs::put()
{
	int processes[100], n;

	cout << "Enter the number of processes:";
	cin >> n;
	if (n == 0)
	{
		cout << "Not Valid";
		exit(0);
	}
	int burst_time[100];

	for (int i = 1;i <= n;i++)
	{
		processes[i] = i;
	}

	cout << "Enter the burst time" << endl;

	for (int i = 0;i < n;i++)
	{
		cout << i + 1 << ".";
		cin >> burst_time[i];
		time[i] = i + 1;
	}


	
	int arrival_time[100];
	cout << "Enter the arrival time"<<endl;
	for (int i = 0;i < n;i++)
	{
		cout << i + 1 << ".";
		cin >> arrival_time[i];

	}
	int temp,temp1,temp2;
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<n - 1;j++)
		{
			if (arrival_time[j]>arrival_time[j + 1])
			{
				temp = arrival_time[j];
				arrival_time[j] = arrival_time[j + 1];
				arrival_time[j + 1] = temp;

				temp2 = time[j];
				time[j] = time[j + 1];
				time[j + 1] = temp2;


				temp1 = burst_time[j];
				burst_time[j] = burst_time[j + 1];
				burst_time[j + 1] = temp1;
			}
		}
	}
	findavgTime(processes, n, burst_time, arrival_time);
}
