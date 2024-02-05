#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	int daysOfWeek[7];
	string nameOfDay[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	int max = daysOfWeek[0];
	int t = 0;

	for (int i = 0; i < 7; i++)
	{
		cout << "Enter the number of mavericks on Day " << i + 1 << ": " << endl;
		cin >> daysOfWeek[i];
		t = t + daysOfWeek[i];
		cout << "Total of mavericks so far: " << t << endl;
	}

	for (int i = 0; i < 7; i++)
	{
		if (max < daysOfWeek[i])
		{
			max = daysOfWeek[i];
		}
	}

	cout << endl;
	cout << "Highest amount of mavericks: " << max << endl;

	for (int i = 0; i < 7; i++)
	{
		if (daysOfWeek[i] == max)
		{
			cout << nameOfDay[i] << " had the most (" << max << ") mavericks yielded." << endl;
		}
	}

	cout << "Total mavericks this week: " << t << endl;

	return 0;
}
