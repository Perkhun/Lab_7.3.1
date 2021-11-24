#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7.3.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest732
{
	TEST_CLASS(UnitTest732)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 2;
			int n = 2;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			a[0][0] = 3;
			a[0][1] = 1;
			a[1][0] = 2;
			a[1][1] = 1;
			
			int i_max;
			int j_max;


			  Max(a, 1, 1, 0, a[0][0], i_max, j_max, 0, 0);
			  Assert::AreEqual(a[0][0], 3);

		}
	};
}
