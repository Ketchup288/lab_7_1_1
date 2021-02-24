#include "pch.h"
#include "CppUnitTest.h"
#include "../Labor_7_1_1_iter/Labor_7_1_1_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int b[3][4] = { {6, -9, 2, 5}, {18, -12, 5, -22}, {-22, 19, 21, 10} };
			int* pb[3] = { b[0], b[1], b[2] };
			int S = 0;
			int x = Sum(pb, 3, 4, S);
			Assert::AreEqual(x, 75);
		}
	};
}
