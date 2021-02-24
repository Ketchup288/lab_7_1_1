#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7_1_1_recurs/Lab_7_1_1_recurs.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int S = 0, k = 0;
			int b[3][4] = { {6, -9, 2, 5}, {18, -12, 5, -22}, {-22, 19, 21, 10} };
			int* pb[3] = { b[0], b[1], b[2] };
			int x = SumRows(pb, 3, 4, 0, S);
			Assert::AreEqual(x, 75);
		}
	};
}
