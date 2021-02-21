#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_1_1_recur/lab_7_1_1_recur.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int S = 0, k = 0;
			int b[3][3] = { {6, 9, 2}, {18, 12, 5}, {22, 19, 21} };
			int* pb[3] = { b[0], b[1], b[2] };
			int x = SumRows(pb, 3, 3, 0, S, k);
			Assert::AreEqual(x, 48);
		}
	};
}