#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void input(string*&);
void rot13(string*, int);
void output(string*);

int main() {

	string* message = nullptr;
	int length = 0;

	char begin = 'y';

	while (begin == 'y') {
		input(message);
		length = message->size();
		rot13(message, length);

		output(message);

		cout << "Would you like to repeat this program? (Y or N)" << endl;
		cin >> begin;
		cin.ignore(10, '\n');
		begin = tolower(begin);

	}


	delete message;


	return 0;
}


void input(string*& message) {
	cout << "What message would you like to Encrypt/Decrypt?" << endl;
	message = new string;
	getline(cin, *message);

}

void rot13(string* message, int length) {
	int index = 0;

	while (index != length) {
		if (message->at(index) >= 'a' && message->at(index) <= 'm') {
			message->at(index) = (*message)[index] + 13;
		}
		else if ((*message)[index] >= 110 && message->at(index) <= 122) {
			message->at(index) = message->at(index) - 13;
		}
		else if (message->at(index) >= 65 && message->at(index) <= 77) {
			message->at(index) = message->at(index) + 13;
		}
		else if (message->at(index) >= 78 && message->at(index) <= 90) {
			message->at(index) = message->at(index) - 13;
		}
		index++;
	}
}

void output(string* message) {
	cout << "The encrypted/decrypted message is: " << *message << endl;
}
