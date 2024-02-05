#include <iostream>
using namespace std;
const double PI = 3.14;
int main()
{
	double area;
	// declaration and definition of area
	float circumference;
	// declaration and definition of circumference
	double RADIUS = 8.3;
	cout << "Please enter the radius of the circle: ";
	cin >> RADIUS;
	circumference = 2 * PI * RADIUS;
	// computes circumference
	area = PI * RADIUS * RADIUS;
	// computes area
	cout << "The circumference of the circle is " << circumference << ", which is the enclosing boundary of the circle." << endl;
	cout << "The area of the circle is " << area << ", which is the space occupied by the circle." << endl;

	int a;
	cin >> a;

	return 0;
}