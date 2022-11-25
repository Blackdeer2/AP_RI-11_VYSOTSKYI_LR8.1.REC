#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1.REC/PR8.1.REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[]{ "Who want free tea" };
			bool t = false;
			bool test = findOut(str, 0, t);
			Assert::AreEqual(test, false);
		}
	};
}
