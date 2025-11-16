#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Test\SE_Lab_ShvedovaDaria\SE_Lab_ShvedovaDaria.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(CalculateY_Xlessthanone_return3_5)
		{
			double x = 0.5;
			int n = 5;
			double expected = 3.5;
			double result = CalculateY(x, n);

			Assert::AreEqual(expected, result, 0.0001, L"CalculateY did not return the expected result for x < 1.");
		}

		TEST_METHOD(CalculateY_Xgreaterthanone_return_nestedsum)
		{
			double x = 2.0;
			int n = 5;
			double expected = -28324158.666667;
			double result = CalculateY(x, n);

			Assert::AreEqual(expected, result, 0.0001, L"Test failed for x = 2.0.");
		}

		TEST_METHOD(CalculateY_Xequalsone_return_nestedsum)
		{
			double x = 1.0;
			int n = 5;
			double expected = -270185392.5;
			double result = CalculateY(x, n);

			Assert::AreEqual(expected, result, 0.0001, L"Test failed for x = 1.0.");
		}
	};
}
