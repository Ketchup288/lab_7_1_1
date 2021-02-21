#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_7_1/Lab_7_1_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int b[3][3] = { {6, 9, 2}, {18, 12, 5}, {22, 19, 21} };
			
			int* pb[3] = { b[0], b[1], b[2] };
			int S = 0;
			int k = 0;
			int x = Calc(pb, 3, 3, S, k);
			Assert::AreEqual(x, 48);
		}
	};
}
