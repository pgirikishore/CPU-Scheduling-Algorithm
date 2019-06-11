
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>
#include "fcfs.h"
#include "sjf.h"
#include "ps.h"
using namespace std;

int main()
{
		time_t rawTime;
		time(&rawTime);
		tm time;
		localtime_s(&time, &rawTime);

		string hours = to_string(time.tm_hour % 12);
		string min = to_string(time.tm_min % 59);
		string sec = to_string(time.tm_sec % 59);
		vir *v1;
	fcfs f1;
	sjf f2;
	ps f3;
	v1 = &f1;
	char choice;
	cout << "-----------------------------------\n";
	cout << "\tOS SCHEDULING\n";
	cout << "------------------------------------\n";
	cout<<"                           " << hours << ":" << min << ":" << sec << endl;
	cout << "Enter your choice\n";
	cout << "1.First Come First Serve\n";
	cout << "2.Shortest Job First\n";
	cout << "3.Priority Scheduling\n";
	choice=_gettche();
	 system("cls");
	switch (choice)
	{
	case '1':v1->put();break;
	case '2':f2.put();break;
	case '3':f3.put();break;
	default:cout << "Invalid";
	}
	
	_gettche();
	return 0;
}


