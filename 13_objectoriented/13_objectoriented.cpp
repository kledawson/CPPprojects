#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Cargo {
	string type;
	string unit;
	string identification;
	int aircraft;
	int weight;
	string destination;
};

void input(Cargo* cPtr);
void output(Cargo* cPtr);

int main() {
	Cargo* cPtr = new Cargo;
	input(cPtr);
	output(cPtr);
	delete cPtr;
	cPtr = nullptr;
	return 0;
}

void input(Cargo* cPtr) {
	cout << "Enter Type (Container or Pallet):\n";
	getline(cin, cPtr->type);
	cout << "Enter Unit Name Abbreviation:\n";
	getline(cin, cPtr->unit);
	cout << "Enter Unit ID:\n";
	getline(cin, cPtr->identification);
	cout << "Enter Destination:\n";
	getline(cin, cPtr->destination);
	cout << "Enter Aircraft Number:\n";
	cin >> cPtr->aircraft;
	cout << "Enter Cargo Weight:\n";
	cin >> cPtr->weight;

	cout << "\nProcessing...\n\n";
}

void output(Cargo* cPtr) {
	cout << "The Cargo loaded is a " << cPtr->type << endl;
	cout << "The Unit Abbreviation is " << cPtr->unit << endl;
	cout << "The Unit ID is " << cPtr->unit << cPtr->identification << "IB" << endl;
	cout << "The Aircraft Number is " << cPtr->aircraft << endl;
	cout << "The Weight of the Cargo is " << cPtr->weight << endl;
	cout << "The Destination is " << cPtr->destination << endl;
}
