//Application layer, containing main method and Console UI code

#include "Logic.h"		//Neede for main program to use Logic class
#include <iostream>
#include <regex>		//Used to check user input string for letters
using namespace std;

class Application
{
	double a, b;
	char choice;
	
	
};

void displayWelcomeBanner()
{
	cout << "============================" << endl;
	cout << "==      Equation App      ==" << endl;
	cout << "============================" << endl << endl << endl;

	cout << "This program reads in an equation, performs math functions" << endl;
	cout << "and outputs the result. An acceptable input is shown below:" << endl << endl;

	cout << " 2*(3-2)" << "   (currently, only an A + B format is accepted)"<< endl;
	cout << "Do not leave spaces in between digits, operators or brackets" << endl << endl;
}

int main()
{
	string equation = "";

	displayWelcomeBanner();
	
	Logic logic;
	//logic.functionDecider("1 + (10 / 10) * 2 - 1");	//This type of 
	//cout << logic.functionDecider("1 + (10 / 10)") << endl;	//Returns 2
	
	char choice = ' ';
	while (choice != 'n')
	{
		try
		{
			cout << "Please enter an equation: " << endl;
			cin >> equation;

			if (std::regex_match(equation, std::regex("^[A-Za-z]+$")))
			{
				cout << "Letters cannot be accepted by this application, for multiplication," << endl;
				cout << "please use the '*' symbol" << endl;
			}
			else
			{
				cout << equation << " = " << to_string(logic.functionDecider(equation)) << endl;

				cout << "Would you like to enter another equation? (Type 'y' or 'n')" << endl;
				cin >> choice;
				system("cls");
			}
		}
		catch (exception e)	//To be coded (Detect Division by 0, etc)
		{
			
		}
	}

	cout << "Thank you for using this Equation Application" << endl;
	system("pause");
	return 0;
}