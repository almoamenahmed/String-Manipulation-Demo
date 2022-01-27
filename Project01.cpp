#include<iostream>
#include<fstream>
#include<string>
#include "stringFuncs.h"
using namespace std;
int main() {
	int choice, sP, sP1, lngt;
	string x, parStr, x1, y, y1, str;
	ofstream stringFile("strFunc.txt");
	stringFile << "String\t\t\t String After Alteration (if changed) \t\t Action/Function Called\n";
	cout << "********************************************************************\n" << "Welcome! This Program Offers Different Functions Relating to Strings\n" << "********************************************************************\n";
		cout << "Enter a string you would like to use for this program: \n";
	cin >> str;
	stringFile << "\n" << str << "\t\t\t" << str << "\t\t\t\t" << " User string created";
	myString str1;
	str1.setString(str);
	cout << "\nThe string you are using for this program is: " << str1.getString() << "\n\n";
	cout << "Now choose which function to perform from this list: (PRESS 99 TO EXIT)\n"
		<< "0.) Print your string to the screen\n"
		<< "1.) Return size of string (how many characters are in string)\n"
		<< "2.) Add another string to the beginning of original string\n"
		<< "3.) Add another string to the end of original string\n"
		<< "4.) Replace part of your string by giving starting position \n"
		<< "5.) Display part of a string by giving starting position and length\n"
		<< "6.) Replace original string with a whole new string\n"
		<< "7.) Compare current string with a new string (If strings match 0 is outputted. Otherwise position where mismatch occurs is outputted)\n"
		<< "8.) Reset string to null value\n"
		<< "9.) Test whether data is numeric or not\n"
		<< "10.) Test whether data is fully alphabetic or not\n";
	do {
		cin >> choice;
		switch (choice) {
		case 0:
			cout << "Your string is: " << str1.printStringScreen() << endl;
			stringFile << "\n" << str1.printStringScreen() << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " printStringScreen()";
				break;
		case 1:
			cout << "The size of your string is: " << str1.size() << "\n";
			stringFile << "\n" << str1.printStringScreen() << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " size()";
				break;
		case 2:
			cout << "Enter a string to be added to front" << "\n";
			stringFile << "\n" << str1.printStringScreen();
			cin >> x;
			cout << "The new string after what you added to front of original string is:" << str1.addStart(x) << "\n";
			stringFile << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " addStart(string x)";
			break;
		case 3:
			cout << "Enter a string to be added to back" << "\n";
			stringFile << "\n" << str1.printStringScreen();
			cin >> x1;
			cout << " The new string after what you added to back of original string is:" << str1.addEnd(x1) <<
				"\n";
			stringFile << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " addEnd(string x1)";
			break;
		case 4:
			stringFile << "\n" << str1.printStringScreen();
			cout << "What is your desired starting position? ";
			cin >> sP1;
			cout << "Give a new string to replace the previous one: ";
			cin >> parStr;
			str1.replPartString(parStr, sP1);
			cout << "Your new word is " << str1.getString() << endl;
			stringFile << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " replPartString(parStr, sP1)";
			break;
		case 5:
			stringFile << "\n" << str1.printStringScreen();
			cout << "What is your desired starting position and length of string?\n";
			cin >> sP >> lngt;
			cout << "Partial string is: ";
			str1.partString(sP, lngt);
			stringFile << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " partString(sp, lngt)";
			break;
		case 6:
			stringFile << "\n" << str1.printStringScreen();
			cout << "Enter a string to replace your old string: \n";
			cin >> y;
			cout << "New string is: " << str1.replWholeString(y) << endl;
			stringFile << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " replWholeString(string y)";
			break;
		case 7:
			stringFile << "\n" << str1.printStringScreen() << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " compareString(string y1)";
				cout << "Enter a string to compare to previous string: \n";
			cin >> y1;
			cout << str1.compareString(y1);
			break;
		case 8:
			stringFile << "\n" << str1.printStringScreen();
			str1.initString();
			cout << "Your string is now reset!\n";
			stringFile << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " initString()";
			break;
		case 9:
			stringFile << "\n" << str1.printStringScreen() << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " numericString()";
				str1.printStringScreen();
			if (str1.numericString())
				cout << "Your string " << str1.getString() << " is integer\n";
			else
				cout << "Your string " << str1.getString() << " is not an integer\n";
			break;
		case 10:
			stringFile << "\n" << str1.printStringScreen() << "\t\t\t" << str1.printStringScreen() << "\t\t\t\t" << " alphabeticString()";
				if (str1.alphabeticString())
					cout << "Your string " << str1.getString() << " is completely alphabetic \n";
				else
					cout << "Your string " << str1.getString() << " is not completely alphabetic\n";
			break;
		default:
			break;
		}
	} while (choice != 99);
}