//Logic method Implementation
#include "stdafx.h"
#include "Logic.h"
#include <iostream>
#include <string>
using namespace std;

//NP = Next Phase
namespace EquationApp
{
	float Logic::functionDecider(string equation)	//ReadString, if bracket, recursion
	{
		int bracketStart = 0, bracketEnd = 0;
		string bracket = "";
		float bracketMath = 0;

		if (equation.find("(") != string::npos)
		{
			bracketStart = equation.find("(") + 1;
			bracketEnd = equation.find(")") - bracketStart;		//Gets the number of characters to display
			//Issue with extra brackets (predicted), find
			//way to identify last bracket with find()				NP

			bracket = equation.substr(bracketStart, bracketEnd);

			bracketMath = functionDecider(bracket);
			equation = equation.substr(0, bracketStart - 1) + to_string(bracketMath);
		}
		return normalMath(equation);
	}


	float Logic::normalMath(string equation)	//Check if able to optimise												NP
	{
		string temp = "";
		char op = ' ';		//This to be replaced with char array for multiple operations								NP
		float a = 0, b = 0;		//This to be replaced with float array for multiple operations							NP

		for (int i = 0; i < equation.length(); i++)
		{
			if (isdigit(equation.at(i)) || equation.at(i) == '.')	//If the character is a digit
			{
				if (i == 0)		//If first iteration and is number, temp gets a value
					temp = equation.at(i);
				else if ((isdigit(equation.at(i)) || equation.at(i) == '.') && (isdigit(equation.at(i - 1)) || equation.at(i - 1) == '.'))	//If last char digit or decimal, append
					temp += equation.at(i);
				else if (isdigit(equation.at(i)) && !isdigit(equation.at(i - 1)) && equation.at(i - 1) != '.')	//If last char wasn't a digit, reset string
					temp = equation.at(i);

				if (i + 1 < equation.length())
				{
					if (isOperator(equation.at(i + 1)))
						a = stof(temp);
				}
				else
					b = stof(temp);
			}

			else if (isOperator(equation.at(i)))
			{
				op = equation.at(i);
			}
			else if (equation.at(i) == '.')
				temp += equation.at(i);
		}
		return doMath(a, op, b);
	}

	float Logic::doMath(float a, char op, float b)		//Takes in the numbers and the operator and performs math based on the Operator
	{
		switch (op)
		{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		}
	}

	bool Logic::isOperator(char op)		//Returns true if a character is a math operator
	{
		switch (op)	//If not one of the below cases, switch exited and false gets returned
		{
		case '+':
		case '-':
		case '*':
		case '/':
		{
			return true;
		}
		}

		return false;
	}
}