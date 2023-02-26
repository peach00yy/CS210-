/*
Austin Sacriste
Jan 25 2023
CS 210
*/

#include<iostream>
#include<chrono>
#include<thread>
#include<tuple>
#include<iomanip>

using namespace std;

int dataEdit;
int Hour24;
int minute;
int hour;
int second;
bool stop = false;

string AM_or_PM()
{
	if ((Hour24 >= 12) && (Hour24 <= 23))
	{
		return " P.M.";
	}
	else {
		return " A.M.";
	}
}
void clock_format(int j, int k)
{
	for (int m = 0; m < k; m++)
	{
		for (int i = 0; i < j; i++)
		{
			cout << " ";
		}
	}
}
tuple<int, int, int, int> timecheck()
{
	if (second >= 60)
	{
		second = 0;
		minute++;
	}
	if (minute >= 60)
	{
		hour++;
		Hour24++;
		minute = 0;
	}
	if ((hour == 12) && (second > 59))
	{
		hour = 1;
	}
	if (Hour24 >= 24)
	{
		Hour24 = 0;
	}
	return make_tuple(hour, minute, second, Hour24);
}

void Display12HourClock()
{
	cout << setfill('0') << setw(2) << get<0>(timecheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timecheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timecheck()) << AM_or_PM();

}
void Display24HourClock()
{
	cout << setfill('0') << setw(2) << get<3>(timecheck()) << ":";
	cout << setfill('0') << setw(2) << get<1>(timecheck()) << ":";
	cout << setfill('0') << setw(2) << get<2>(timecheck());
}

void OutputTime()
{
	clock_format(27, 2);
	cout << endl;
	cout << "*        12-Hour Clock        *    *        24-Hour Clock        *" << endl;
	cout << "*        ";
	Display12HourClock();
	cout << "        *" << "        *";
	Display24HourClock();
	cout << "        *" << endl;
	clock_format(27, 2);

	cout << endl;
	this_thread::sleep_for(chrono::seconds(1));
}

void Displaymenu()
{
	clock_format(27, 1);
	cout << endl << "*        1-Add One Hour          *" << endl;
	cout << endl << "*        2-Add One Minute        *" << endl;
	cout << endl << "*        3-Add One Second        *" << endl;
	cout << endl << "*        4-Exit                  *" << endl;
	clock_format(27, 1);

	cin >> dataEdit;

	switch (dataEdit)
	{
	case 1:
		hour++;
		Hour24;
		OutputTime();
		break;
	case 2:
		minute++;
		OutputTime();
		break;
	case 3:
		second++;
		second--;
		OutputTime();
		break;
	case 4:
		cout << "Goodbye." << endl;
		break;
	}
}
int main()
{
	while (!stop)
	{
		OutputTime();
	}
	return 0;
}

