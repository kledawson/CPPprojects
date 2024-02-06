#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

const int maxload737 = 46000;
const int maxload767 = 116000;

class Cargo
{
protected:
	string uldtype;
	string abbrev;
	string uldid;
	int aircraft;
	double weight;
	string destination;

public:
	///Default constructor prototype
	Cargo();

	///Full constructor prototype
	Cargo(const string& uldtype,
		const string& abbrev,
		const string& uldid,
		const int& aircraft,
		const int& weight,
		const string& destination);

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
	virtual void maxweight(double&, double) = 0;

	void output();
};

class Boeing737 : public Cargo
{
private:
	int total737wt;
public:

	Boeing737(const string& uldtype,
		const string& abbrev,
		const string& uldid,
		const int& aircraft,
		const double& weight,
		const string& destination);

	~Boeing737() {};

	void maxweight(double&, double)override;
};

class Boeing767 : public Cargo
{
private:
	int total767wt;
public:

	Boeing767(const string& uldtype,
		const string& abbrev,
		const string& uldid,
		const int& aircraft,
		const double& weight,
		const string& destination);

	~Boeing767() {};

	void maxweight(double&, double)override;
};

void input();
void checkPlane(int);
void checkType(string);
void checkAbrv(string, int);
void vectorprint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767);

int main() {

	input();
	return 0;
}


Cargo::Cargo()
{
	uldtype = "XXX";
	abbrev = " ";
	uldid = "xxxxxIB";
	aircraft = 700;
	weight = 0.0;
	destination = "none";
}

Cargo::Cargo(const string& type,
	const string& abrv,
	const string& id,
	const int& craft,
	const int& wt,
	const string& dest)
{
	uldtype = type;
	abbrev = abrv;
	uldid = id;
	aircraft = craft;
	weight = wt;
	destination = dest;
}

Cargo::Cargo(const Cargo& unit1)
{
	uldtype = unit1.uldtype;
	abbrev = unit1.abbrev;
	uldid = unit1.uldid;
	aircraft = unit1.aircraft;
	weight = unit1.weight;
	destination = unit1.destination;
}

Cargo::~Cargo()
{

}

void Cargo::setuldtype(string type)
{
	uldtype = type;
}

void Cargo::setabbrev(string abrv)
{
	abbrev = abrv;
}

void Cargo::setuldid(string id)
{
	uldid = id;
}

void Cargo::setaircraft(int air)
{
	aircraft = air;
}

void Cargo::setweight(double wt)
{
	weight = wt;
}

void Cargo::setdestination(string dest)
{
	destination = dest;
}

string Cargo::getuldtype() const
{
	return uldtype;
}

string Cargo::getabbrev() const
{
	return abbrev;
}

string Cargo::getuldid() const
{
	return uldid;
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

Boeing737::Boeing737(const string& type, const string& abrv, const string& id, const int& craft, const double& wt, const string& dest)
{
	uldtype = type;
	abbrev = abrv;
	uldid = id;
	aircraft = craft;
	weight = wt;
	destination = dest;
}

Boeing767::Boeing767(const string& type, const string& abrv, const string& id, const int& craft, const double& wt, const string& dest)
{
	uldtype = type;
	abbrev = abrv;
	uldid = id;
	aircraft = craft;
	weight = wt;
	destination = dest;
}

void load737(vector <Boeing737>& vectorptr737,
	const string type,
	const string abrv,
	const string id,
	const int craft,
	const double wt,
	const string dest,
	double& totwt737)
{
	Boeing737 unitobj737(type, abrv, id, craft, wt, dest);
	unitobj737.maxweight(totwt737, wt);
	vectorptr737.push_back(unitobj737);
}

void Boeing737::maxweight(double& totwt737, double wt) {
	totwt737 = totwt737 + wt;
	if (totwt737 > maxload737) {
		totwt737 -= wt;
		throw runtime_error("Too heavy for 737, removed\n");
	}
}

void load767(vector<Boeing767>& vectorptr767,
	const string type,
	const string abrv,
	const string id,
	const int craft,
	const double wt,
	const string dest,
	double& totwt767)
{
	Boeing767 unitobj767(type, abrv, id, craft, wt, dest);
	unitobj767.maxweight(totwt767, wt);
	vectorptr767.push_back(unitobj767);
}

void Boeing767::maxweight(double& totwt767, double wt)
{
	totwt767 = totwt767 + wt;
	if (totwt767 > maxload737) {
		totwt767 -= wt;
		throw runtime_error("Too heavy for 767, removed\n");
	}
}

void Cargo::output()
{
	cout << fixed << showpoint << setprecision(2);
	cout << setw(19) << "The Cargo loaded is a " << uldtype << endl;
	cout << setw(19) << "The Unit Abbreviation is " << abbrev << endl;
	cout << setw(19) << "The Unit ID is " << uldid << endl;
	cout << setw(19) << "The Aircraft Number is " << aircraft << endl;
	cout << setw(19) << "The Weight of the Cargo is " << weight << " pounds" << endl;
	cout << setw(19) << "The Destination is " << destination << endl;
}


void input()
{
	string type;
	string abrv;
	string id;
	int air;
	int wt;
	string dest;
	double totwt737 = 0;
	double totwt767 = 0;
	string dataFile;
	ifstream inputFile;

	vector<Boeing737> vectorptr737;
	vector<Boeing767> vectorptr767;

	do {
		try {
			inputFile.clear();
			cout << "What's the name of your data file? (cargodata.txt)\n";
			getline(cin, dataFile);
			inputFile.open(dataFile);
			if (!inputFile)
				throw runtime_error("\n" + dataFile + " is a bad filename\n\n");
			cout << "It's open\n";
		}
		catch (runtime_error& excpt) {
			cout << dataFile << " " << excpt.what();
		}
	} while (!inputFile);
	while (inputFile.peek() != EOF) {
		try {
			inputFile >> type;
			inputFile >> abrv;
			inputFile >> id;
			inputFile >> air;
			inputFile >> wt;
			inputFile >> dest;
			inputFile.get();
			checkType(type);
			checkPlane(air);

			if (air == 737) {
				checkAbrv(abrv, air);
				totwt737 = totwt737 + wt;
				cout << "The current total weight for 737 is: " << totwt737 << endl;
				load737(vectorptr737, type, abrv, id, air, wt, dest, totwt737);
			}

			if (air == 767) {
				checkAbrv(abrv, air);
				totwt767 = totwt767 + wt;
				cout << "The current total weight for 767 is: " << totwt767 << endl;
				load767(vectorptr767, type, abrv, id, air, wt, dest, totwt767);
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what();
		}
	}
	inputFile.close();
	vectorprint(vectorptr737, vectorptr767);
	cout << "\nTotal weight for 737 load is " << totwt737 << endl;
	cout << "Total weight for 767 load is " << totwt767 << endl;
}

void checkPlane(int air) {
	if (air != 737 && air != 767) {
		throw runtime_error("\n" + to_string(air) + " is a bad airplane type\n");
	}
}

void checkType(string type) {
	if (type != "Container" && type != "Pallet")
		throw runtime_error(type + " not Container or Pallet, rejected load\n");
}

void checkAbrv(string abrv, int plane) {
	if (plane == 737) {
		if (abrv != "AYF" &&
			abrv != "AYK" &&
			abrv != "AAA" &&
			abrv != "AYY" &&
			abrv != "PAG" &&
			abrv != "PMC" &&
			abrv != "PLA")
			throw runtime_error(abrv + " is a bad type for Boeing 737\n");
		else {
			cout << "\n" + abrv + " has been loaded\n";
		}
	}
	if (plane == 767) {
		if (abrv != "AKE" &&
			abrv != "APE" &&
			abrv != "AKC" &&
			abrv != "AQP" &&
			abrv != "AQF" &&
			abrv != "P1P" &&
			abrv != "P6P")
			throw runtime_error("\n" + abrv + " is a bad type for Boeing 737\n");
		else {
			cout << "\n" + abrv + " has been loaded\n";
		}
	}
}

void vectorprint(vector<Boeing737> vectorptr737, vector<Boeing767> vectorptr767) {
	for (int i = 0; i < vectorptr737.size(); i++) {
		cout << "\n737 unit number " << i + 1 << endl;
		cout << fixed << setprecision(2);
		cout << left << setw(20) << "Unit load type: " << vectorptr737[i].getuldtype() << endl;
		cout << left << setw(20) << "Unit abbrevation: " << vectorptr737[i].getabbrev() << endl;
		cout << left << setw(20) << "Unit identifer: " << vectorptr737[i].getuldid() << endl;
		cout << left << setw(20) << "Aircraft type: " << vectorptr737[i].getaircraft() << endl;
		cout << left << setw(20) << "Unit weight: " << vectorptr737[i].getweight() << endl;
		cout << left << setw(20) << "Destination code: " << vectorptr737[i].getdestination() << endl;
	}

	for (int i = 0; i < vectorptr767.size(); i++) {
		cout << "\n767 unit number " << i + 1 << endl;
		cout << fixed << setprecision(2);
		cout << left << setw(20) << "Unit load type: " << vectorptr767[i].getuldtype() << endl;
		cout << left << setw(20) << "Unit abbrevation: " << vectorptr767[i].getabbrev() << endl;
		cout << left << setw(20) << "Unit identifer: " << vectorptr767[i].getuldid() << endl;
		cout << left << setw(20) << "Aircraft type: " << vectorptr767[i].getaircraft() << endl;
		cout << left << setw(20) << "Unit weight: " << vectorptr767[i].getweight() << endl;
		cout << left << setw(20) << "Destination code: " << vectorptr767[i].getdestination() << endl;
	}
}


