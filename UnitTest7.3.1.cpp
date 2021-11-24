#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.3.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest731
{
	TEST_CLASS(UnitTest731)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		
			int n = 2;
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
				a[i] = new int[n];
			a[0][0] = 3;
			a[0][1] = 1;
			a[1][0] = 2;
			a[1][1] = 1;

			int i_max;
			int j_max;


			max(a, 1, 1,  a[0][0], i_max, j_max);
			
			Assert::AreEqual(a[0][0], 3);


		}
	};
}
