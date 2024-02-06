#include <iostream>
#include <fstream>
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
	void output();

	//friend double kilotolbs(double&);
	friend bool operator == (const Cargo& left, const Cargo& right);
};

void input();

int main() {

	input();
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

void input()
{
	string type;
	string unit;
	string identification;
	int aircraft;
	int weight;
	string destination;

	fstream inputFile;
	inputFile.open("cardata4.txt");
	if (!inputFile.is_open()) {
		cout << "Error opening the file\n";
		return;
	}
	while (inputFile.peek() != EOF) {
		inputFile >> type;
		inputFile >> unit;
		inputFile >> identification;
		inputFile >> aircraft;
		inputFile >> weight;
		inputFile >> destination;

		if (!inputFile.good()) {
			break;
		}

		Cargo temp(type, unit, identification, aircraft, weight, destination);
		temp.output();
	}
	inputFile.close();

}

void Cargo::output()
{
	cout << "\nThe Cargo loaded is a " << getuldtype() << endl;
	cout << "The Unit Abbreviation is " << getabbrev() << endl;
	cout << "The Unit ID is " << getuldid() << endl;
	cout << "The Aircraft Number is " << getaircraft() << endl;
	cout << "The Weight of the Cargo is " << getweight() << " pounds" << endl;
	cout << "The Destination is " << getdestination() << endl;

	return;
}

bool operator == (const Cargo& right, const Cargo& left) {
	return (left.unit == right.unit && left.identification == right.identification);
}