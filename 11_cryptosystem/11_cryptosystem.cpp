#include <iostream>
#include <string>
using namespace std;

// Obtains a string from the user to encrypt or decrypt
string inputString() {
	string input;
	getline(cin, input);
	return input;
}


void toEncrypt(string input) {

	// Converts the string to uppercase letters
	for (int i = 0; i < input.length(); i++) {
		input[i] = toupper(input[i]);
	}

	// Starter for ASCII table (for uppercase letters)
	int starter = 13;

	// Output variable
	string encryptedText;

	// Encrypts message
	for (int i = 0; i < input.length(); i++) {
		int temp = input[i] + starter;

		// Checks and adds spaces to encrypted message
		if (input[i] == 32) {
			encryptedText += " ";
		}

		// Uses ASCII table to return the correct decrypted letter
		else if (temp > 90) {
			temp -= 26;
			encryptedText += (char)temp;
		}

		else {
			encryptedText += (char)temp;
		}

	}

	// Displays encrypted text in terminal
	cout << "Encrypted Text: " << encryptedText;

}

void toDecrypt(string input) {

	// Converts the string to uppercase 
	for (int i = 0; i < input.length(); i++) {
		input[i] = toupper(input[i]);
	}

	// Starter for ASCII table (for uppercase letters)
	int starter = 13;

	// Output variable
	string decryptedText;

	//Decrypts message
	for (int i = 0; i < input.length(); i++) {
		int temp = input[i] - starter;

		// Checks and adds spaces to encrypted message
		if (input[i] == 32) {
			decryptedText += " ";
		}

		// Uses ASCII table to return the correct decrypted letter
		else if (temp < 65) {
			temp += 26;
			decryptedText += (char)temp;
		}

		else {
			decryptedText += (char)temp;
		}

	}

	cout << "Decrypted text is: " << decryptedText;

}

int main() {

	string* pointer = new string;
	cout << "Enter a string to encrypt/decrypt:" << endl;
	string input = inputString();
	pointer = &input;

	int choice;
	cout << "Press 1 to encrypt.\nPress 2 to decrypt.\n";
	cin >> choice;
	cin.ignore();

	if (choice == 1) {
		cout << "Encrypting...\n";
		toEncrypt(*pointer);
		return 0;
	}

	else if (choice == 2) {
		cout << "Decrypting...\n";
		toDecrypt(*pointer);
		return 0;
	}

	else {
		cout << "Invalid choice. Exiting...\n";
		return 0;
	}

	delete[] pointer;
	return 0;
}

