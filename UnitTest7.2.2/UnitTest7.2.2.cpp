#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2.2/project7.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest722
{
	TEST_CLASS(UnitTest722)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 3;
			int** a = new int* [rowCount];
			int min_value;
			int min_index;
			for (int i = 0; i < 2; i++)
			{
				a[i] = new int[colCount];
			}
			a[0][0] = 1;
			a[0][1] = 2;
			a[0][2] = 0;
			a[1][0] = 2;
			a[1][1] = 4;
			a[1][2] = 0;

			find_min_index(a, 0, 0, colCount, &min_value, &min_index);
			Assert::AreEqual(min_index, 2);
		}
	};
}
