#include <iostream>
using namespace std;
int main()
{
	string name = "Dawson Le";
	string address = "21250 Dawson Creek Boulevard";
	string city = "Cupertino";
	string state = "California";
	int zipcode = 95014;
	string phoneNumber = "(408)699-9595";

	cout << "My first and last name is: " << name << "." << endl;
	cout << "My address is " << address << "." << endl;
	cout << "The city that I live in is " << city << ". ";
	cout << "The state that I live in is " << state << ". ";
	cout << "My zip code is " << zipcode << "." << endl;
	cout << "My phone number is " << phoneNumber << "." << endl;

	int a;
	cin >> a;

	return 0;
}