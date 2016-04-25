//Logic.h

#define LOGIC_H
#include <string>
namespace EquationApp
{
	class Logic	//place method stubs to be implemented here
	{
	public:
		__declspec(dllexport) float functionDecider(std::string equation);	//Recursive
	private:
		bool isOperator(char op);
		float doMath(float a, char op, float b);
		float normalMath(std::string equation);
	};
}