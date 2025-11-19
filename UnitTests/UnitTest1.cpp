#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Test\SE_Lab_ShvedovaDaria\SE_Lab_ShvedovaDaria.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests 
{
TEST_CLASS(CalculationTest) 
	{
	public:

		TEST_METHOD(CalculateY_Xlessthanone)
		{
			double x = 0.5;
			int n = 5;
			double expected = 3.5;
			double result = CalculateY(x, n);

			Assert::AreEqual(expected, result, 0.0001, L"CalculateY did not return the expected result for x < 1.");
		}

		TEST_METHOD(CalculateY_Xgreaterthanone)
		{
			double x = 0.0;
			int n = 6;
			double expected = 1.5;
			double result = CalculateY(x, n);

			Assert::AreEqual(expected, result, 0.0001, L"Test failed for x = 0.0.");
		}

		TEST_METHOD(CalculateY_Xequalsone)
		{
			double x = 1.0;
			int n = 7;
			double expected = 336417027998868.5;
			double result = CalculateY(x, n);

			Assert::AreEqual(expected, result, 0.0001, L"Test failed for x = 1.0.");
		}
	};
	TEST_CLASS(ValidationTests)
	{
	public:

		TEST_METHOD(ValueValidation_withoutanythrow)
		{
			try {
				double n = 5, step = 1, a = 0, b = 10;
				if (n <=4 || step <= 0 || b <= a) 
					throw "Invalid input values.";
					Assert::IsTrue(true);
				}
			catch (...) {
				Assert::Fail(L"Value validation failed when it shouldn't have.");
			}
		}

		TEST_METHOD(Invalid_Nvalue_exceptionthrow)
		{
			try {
				double n = 0, step = 1, a = 0, b = 10;
				if (n <= 4)
					throw "value for n must be greater than 4.";
				Assert::Fail(L"Value exception wasn't thrown.");
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}

		TEST_METHOD(Invalid_Stepvalue_exceptionthrow)
		{
			try {
				double n = 5, step = -2, a = 0, b = 10;
				if (step <= 0)
					throw "Step must be positive!";
				Assert::Fail(L"Value exception wasn't thrown.");
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(Invalid_MinMaxvalue_exceptionthrow)
		{
			try {
				double n = 0, step = 1, a = 10, b = 0;
				if (b <= a)
					throw "b is max value so it must be bigger than min value a.";
				Assert::Fail(L"Value exception wasn't thrown.");
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
	};
}
