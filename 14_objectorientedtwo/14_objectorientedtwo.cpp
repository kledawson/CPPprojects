#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Cargo
{
private:
	string type;
	string unit;
	string identification;
	int aircraft;
	int weight;
	string destination;

public:
	///Default constructor prototype
	Cargo();
	///Full constructor prototype
	Cargo(const string uldtype, const string abbrev, const string uldid,
		const int aircraft, const int weight, const string destination);
	///Destructor prototype
	~Cargo();
	///Mutator (setters) prototypes
	void setuldtype(string);
	void setabbrev(string);
	void setuldid(string);
	void setaircraft(int);
	void setweight(int);
	void setdestination(string);
	///Accessor (getters) prototypes
	string getuldtype() const;
	string getabbrev() const;
	string getuldid() const;
	int getaircraft() const;
	int getweight() const;
	string getdestination() const;
	void input(Cargo*);
	void output(Cargo*);
};

int main() {
	Cargo* cPtr = new Cargo;
	cPtr->input(cPtr);
	cPtr->output(cPtr);
	delete cPtr;
	cPtr = nullptr;

	Cargo* def = new Cargo;
	def->output(def);
	delete cPtr;
	cPtr = nullptr;
	return 0;
}

Cargo::Cargo()
{
	type = "none";
	unit = "none";
	identification = "none";
	aircraft = 700;
	weight = 0;
	destination = "none";
}

Cargo::Cargo(const string uldtype, const string abbrev, const string uldid,
	const int plane, const int w, const string place)
{
	type = uldtype;
	unit = abbrev;
	identification = uldid;
	aircraft = plane;
	weight = w;
	destination = place;
}

Cargo::~Cargo()
{
	cout << "Cargo deconstructor called" << endl;
}

void Cargo::setuldtype(string t)
{
	type = t;
}

void Cargo::setabbrev(string abrv)
{
	unit = abrv;
}

void Cargo::setuldid(string id)
{
	identification = id;
}

void Cargo::setaircraft(int air)
{
	aircraft = air;
}

void Cargo::setweight(int w)
{
	weight = w;
}

void Cargo::setdestination(string place)
{
	destination = place;
}

string Cargo::getuldtype() const
{
	return type;
}

string Cargo::getabbrev() const
{
	return unit;
}

string Cargo::getuldid() const
{
	return identification;
}

int Cargo::getaircraft() const
{
	return aircraft;
}

int Cargo::getweight() const
{
	return weight;
}

string Cargo::getdestination() const
{
	return destination;
}

void Cargo::input(Cargo* cPtr)
{
	string type;
	string unit;
	string identification;
	int aircraft;
	int weight;
	string destination;
	cout << "Input cargo load information...\n\n";
	cout << "Enter Type (Container or Pallet):\n";
	getline(cin, type);
	setuldtype(type);
	cout << "Enter Unit Abbreviation (3 Characters):\n";
	getline(cin, unit);
	setabbrev(unit);
	cout << "Enter Unit ID (Entire ID):\n";
	getline(cin, identification);
	setuldid(identification);
	cout << "Enter Aircraft Number:\n";
	cin >> aircraft;
	setaircraft(aircraft);
	cout << "Enter Cargo Weight:\n";
	cin >> weight;
	setweight(weight);
	cin.ignore();
	cout << "Enter Destination:\n";
	getline(cin, destination);
	setdestination(destination);

	return;
}

void Cargo::output(Cargo* cPtr)
{
	cout << "\nThe Cargo loaded is a " << getuldtype() << endl;
	cout << "The Unit Abbreviation is " << getabbrev() << endl;
	cout << "The Unit ID is " << getuldid() << endl;
	cout << "The Aircraft Number is " << getaircraft() << endl;
	cout << "The Weight of the Cargo is " << getweight() << endl;
	cout << "The Destination is " << getdestination() << endl;

	return;
}