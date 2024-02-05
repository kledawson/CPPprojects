#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int loopOne;
	int loopTwo;

	cout << "How many times do you want the outer loop to run?\n";
	cin >> loopOne;
	cout << "How many times do you want the inner loop to run?\n";
	cin >> loopTwo;

	cout << "How many times does the outer loop run? " << loopOne << endl;
	cout << "How many times does the inner loop run? " << loopTwo << endl;

	for (int i = 1; i <= loopOne; i++)
	{
		cout << "Outer loop iteration: " << i << endl;

		for (int f = 1; f <= loopTwo; f++)
		{
			cout << "Inner loop iteration: " << f << endl;
		}
	}

	cout << "Wow! That was " << loopOne * loopTwo << " iterations total for the inner loop." << endl;

	return 0;
}