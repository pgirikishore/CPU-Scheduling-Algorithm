#include "stdafx.h"
#include "sjf.h"

int arrival_time[100];
int timee;
sjf::sjf()
{
	
}


sjf::~sjf()
{
}
void sjf::sort(int processes[],int bt[],int n)
{
	int temp,temp1,temp2;
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<n - 1;j++)
		{
			if (bt[j]>bt[j + 1])
			{
				temp2 = time[j];
				time[j] = time[j + 1];
				time[j + 1] = temp2;

				temp1 = arrival_time[j];
				arrival_time[j] = arrival_time[j + 1];
				arrival_time[j + 1] = temp1;


				temp = bt[j];
				bt[j] = bt[j + 1];
				bt[j + 1] = temp;
			}
		}
	}
	findavgTime(processes, n, bt);
}

void sjf::sort(int processes[],int bt[],int p[], int n)
{
	int temp,temp1,temp2;
	for (int i = 0;i<n;i++)
	{
		for (int j = 0;j<n - 1;j++)
		{
			if (p[j]>p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			 

				temp2 = time[j];
				time[j] = time[j + 1];
				time[j + 1] = temp2;

				temp1 = bt[j];
				bt[j] = bt[j + 1];
				bt[j + 1] = temp1;
			}
		}
	}
	findavgTime(processes, n, bt);
}

void sjf::findWaitingTime(int processes[], int n,
	int bt[], int wt[])
{
	
	wt[0] = 0;

	
	for (int i = 1; i < n; i++)
		wt[i] = bt[i - 1] + wt[i - 1];
}




void sjf:: findavgTime(int processes[], int n, int bt[])
{
	int total_wt = 0, total_tat = 0;
	int *wt = new int[n];
	int *tat = new int[n];


	findWaitingTime(processes, n, bt, wt);


	findTurnAroundTime(processes, n, bt, wt, tat);
	
	for(int i=0;i<n;i++)
	{
		cout << "At time" << i<<endl;
	cout << "Processes  " << " Burst time  " << " Arrival time  "
		<< " Waiting time  " << " Turn around time"<< " Completion time   \n";
	
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		for (int j = 0;j < n;j++) {
			if (i >= arrival_time[j])
			{
				cout << "   " << time[j] << "\t\t" << bt[j] << "\t\t" << arrival_time[j] << "\t    "
					<< wt[j] << "\t\t  " << tat[j] << "\t\t  " << tat[j] + arrival_time[j] << endl;
			}
		}
		}

	delete wt, tat;
}

void sjf::put()
{
	int processes[100], n;

	cout << "Enter the number of processes:";
	cin >> n;
	

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
	
	
	cout << "Enter the arrival time" << endl;

	for (int i = 0;i < n;i++)
	{
		cout << i + 1 << ".";
		cin >> arrival_time[i];
	
	}

	
	sort(processes, burst_time,n);
}