#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	char grades;
	char restart = 'y';

	while (restart == 'y')
	{
		cout << "Enter your letter grade:\n";
		cin >> grades;
		grades = tolower(grades);
		switch (grades) {
		case 'a' :
			cout << "You did excellent!\n";
			break;

		case 'b':
			cout << "You did a great job!\n";
			break;

		case 'c':
			cout << "You passed.\n";
			break;

		case 'd':
			cout << "You almost passed, study harder next time.\n";
			break;

		case 'f':
			cout << "You failed. Please attend tutoring.\n";
			break;

		default:
			cout << "Select a letter: A, B, C, D, F";
			break;
		}
		cout << "Do you want to enter another grade?\n";
		cin >> restart;

	}
	return 0;
}