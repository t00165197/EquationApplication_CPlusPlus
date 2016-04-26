#include "stdafx.h"
#include "CppUnitTest.h"
#include "Logic.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace EquationApp;

namespace EquationAppTest
{		
	TEST_CLASS(UnitTest1)
	{
		float expected = 0;
		string equation;

	public:
		
		//------------------------//
		//----- Adding Tests -----//
		//------------------------//

		TEST_METHOD(AddTest)
		{
			Logic log;
			equation = "1+1";
			expected = 2;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(AddTestBrackets)
		{
			Logic log;
			equation = "1+(1+1)";
			expected = 3;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(AddTestComplex)
		{
			Logic log;
			equation = "1894+97365";
			expected = 99259;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(AddTestBracketsComplex)
		{
			Logic log;
			equation = "10654+(99976+2954)";
			expected = 113584;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}


		//------------------------//
		//-- Subtracting Tests ---//
		//------------------------//

		TEST_METHOD(SubTest)
		{
			Logic log;
			equation = "1-1";
			expected = 0;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(SubTestBrackets)
		{
			Logic log;
			equation = "1-(1-1)";
			expected = 1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(SubTestComplex)
		{
			Logic log;
			equation = "1894-97365";
			expected = -95471;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(SubTestBracketsComplex)
		{
			Logic log;
			equation = "10654-(99976-2954)";
			expected = -86368;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}


		//------------------------//
		//-- Multiplying Tests ---//
		//------------------------//

		TEST_METHOD(MultiTest)
		{
			Logic log;
			equation = "1*1";
			expected = 1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(MultiTestBrackets)
		{
			Logic log;
			equation = "1*(1*1)";
			expected = 1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(MultiTestComplex)
		{
			Logic log;
			equation = "1894*97365";
			expected = 184409310;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(MultiTestBracketsComplex)
		{
			Logic log;
			equation = "10*(999*295)";
			expected = 2947050;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}


		//------------------------//
		//---- Dividing Tests ----//
		//------------------------//

		TEST_METHOD(DivTest)
		{
			Logic log;
			equation = "1/1";
			expected = 1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(DivTestBrackets)
		{
			Logic log;
			equation = "1/(1/1)";
			expected = 1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(DivTestComplex)
		{
			Logic log;
			equation = "189/973";
			expected = 0.1942446043165468;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(DivTestBracketsComplex)
		{
			Logic log;
			equation = "10/(990/290)";
			expected = 2.929292929292929;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}



		//------------------------//
		//--- Complexity Tests ---//
		//------------------------//


		//----- ADD AND SUBTRACT ------//

		TEST_METHOD(AddSubBracketTest)											//===================================== EXAMPLE TO SHOW HERE (CODE CHANGE TO PUSH)
		{
			Logic log;
			equation = "1+(2-1))";
			expected = 2;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(SubAddBracketTest)
		{
			Logic log;
			equation = "1-(2+1))";
			expected = -2;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}


		//----- MULTI AND DIVIDE -----//


		TEST_METHOD(MultiDivBracketTest)
		{
			Logic log;
			equation = "1*(2/1))";
			expected = 2;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}


		TEST_METHOD(DivMultiBracketTest)
		{
			Logic log;
			equation = "1/(2*1))";
			expected = 0.5;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}


		//----- MULTI AND ADD -----//


		TEST_METHOD(MultiAddBracketTest)
		{
			Logic log;
			equation = "1*(2+1))";
			expected = 3;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(AddMultiBracketTest)
		{
			Logic log;
			equation = "1+(2*1))";
			expected = 3;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		//----- MULTI AND SUB -----//


		TEST_METHOD(MultiSubBracketTest)
		{
			Logic log;
			equation = "1*(2-1))";
			expected = 1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(SubMultiBracketTest)
		{
			Logic log;
			equation = "1-(2*1))";
			expected = -1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}


		//----- DIV AND ADD -----//


		TEST_METHOD(DivAddBracketTest)
		{
			Logic log;
			equation = "1/(2+1))";
			expected = 0.3333333333333333;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(AddDivBracketTest)
		{
			Logic log;
			equation = "1+(2/1))";
			expected = 3;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		//----- DIV AND SUB -----//


		TEST_METHOD(DivSubBracketTest)
		{
			Logic log;
			equation = "1/(2-1))";
			expected = 1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

		TEST_METHOD(SubDivBracketTest)
		{
			Logic log;
			equation = "1-(2/1))";
			expected = -1;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}




		//--------------------------------------//
		//--- DoMath() Code Coverage Example ---//
		//--------------------------------------//

		TEST_METHOD(NormalMathDecimalTest)
		{
			Logic log;
			equation = "1.056-1.056";
			expected = 0;
			Assert::AreEqual(expected, log.functionDecider(equation));
		}

	};
}