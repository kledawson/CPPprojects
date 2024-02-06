#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Cargo
{
private:
	string type;
	string unit;
	string identification;
	int aircraft;
	double weight;
	string destination;

public:
	///Default constructor prototype
	Cargo();
	///Full constructor prototype
	Cargo(const string uldtype, const string abbrev, const string uldid,
		const int aircraft, const int weight, const string destination);
	///Copy constructor prototype
	Cargo(const Cargo& unit);
	///Destructor prototype
	~Cargo();
	///Mutator (setters) prototypes
	void setuldtype(string);
	void setabbrev(string);
	void setuldid(string);
	void setaircraft(int);
	void setweight(double);
	void setdestination(string);
	///Accessor (getters) prototypes
	string getuldtype() const;
	string getabbrev() const;
	string getuldid() const;
	int getaircraft() const;
	int getweight() const;
	string getdestination() const;
	void input(Cargo&);
	void output(Cargo&);

	friend double kilotolbs(double&);
	friend bool operator == (const Cargo& left, const Cargo& right);
};

int main() {

	Cargo unit1;
	unit1.input(unit1);
	Cargo unit2(unit1);
	Cargo unit3;
	cout << "\nUnit 1:\n";
	unit1.output(unit1);
	cout << "\nUnit 2:\n";
	unit2.output(unit2);
	cout << "\nUnit 3:\n";
	unit3.output(unit3);
	if (unit1 == unit2) {
		cout << "\nUnit1 is the same as Unit2\n";
	}
	else {
		cout << "\nUnit1 is not the same as Unit2\n";
	}

	if (unit2 == unit3) {
		cout << "Unit2 is the same as Unit3\n\n";
	}
	else {
		cout << "Unit2 is not the same as Unit3\n\n";
	}

	return 0;
}

double kilotolbs(double&);
bool operator == (const Cargo& lhs, const Cargo& rhs);

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

Cargo::Cargo(const Cargo& unit1)
{
	type = unit1.type;
	unit = unit1.unit;
	identification = unit1.identification;
	aircraft = unit1.aircraft;
	weight = unit1.weight;
	destination = unit1.destination;
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

void Cargo::setweight(double w)
{
	char ans;
	cout << "Is the weight in Kilos (K) or Pounds (P)?\n";
	cin >> ans;
	if (ans == 'K' || ans == 'k')
	{
		w = kilotolbs(w);
	}
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

void Cargo::input(Cargo&)
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
	cout << "Enter Unit ID (Entire Full ID):\n";
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

void Cargo::output(Cargo& cPtr)
{
	cout << "The Cargo loaded is a " << getuldtype() << endl;
	cout << "The Unit Abbreviation is " << getabbrev() << endl;
	cout << "The Unit ID is " << getuldid() << endl;
	cout << "The Aircraft Number is " << getaircraft() << endl;
	cout << "The Weight of the Cargo is " << getweight() << " pounds" << endl;
	cout << "The Destination is " << getdestination() << endl;

	return;
}

double kilotolbs(double& pounds)
{
	pounds = pounds * 2.2;
	return pounds;
}

bool operator == (const Cargo& right, const Cargo& left)
{
	return (left.unit == right.unit && left.identification == right.identification);
}
