#ifndef __UTFSTRINGTEST_UTF16CHARTEST_H__
#define __UTFSTRINGTEST_UTF16CHARTEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the Utf16Char class
	*/
	class Utf16CharTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("Utf16CharTest");

			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestAssignmentOperator",
				&Utf16CharTest::TestAssignmentOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestClear",
				&Utf16CharTest::TestClear));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestConstructors",
				&Utf16CharTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestEqualsOperator",
				&Utf16CharTest::TestEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestIndexingOperator",
				&Utf16CharTest::TestIndexingOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestIsValid",
				&Utf16CharTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestNotEqualsOperator",
				&Utf16CharTest::TestNotEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestSize",
				&Utf16CharTest::TestSize));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestStreamOperators",
				&Utf16CharTest::TestStreamOperators));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestToUtf32",
				&Utf16CharTest::TestToUtf32));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharTest>("TestUtf8CharConversionOperator",
				&Utf16CharTest::TestUtf8CharConversionOperator));

			return testSuite;
		}

		/*!
		\brief Tests the Utf16Char assignment operator
		*/
		void TestAssignmentOperator();

		/*!
		\brief Tests the Utf16Char clear() function
		*/
		void TestClear();

		/*!
		\brief Tests the Utf16Char constructors
		*/
		void TestConstructors();

		/*!
		\brief Tests the Utf16Char Equals operator
		*/
		void TestEqualsOperator();

		/*!
		\brief Tests the Utf16Char Indexing operator
		*/
		void TestIndexingOperator();

		/*!
		\brief Tests the is_valid() function
		*/
		void TestIsValid();

		/*!
		\brief Tests the Utf16Char Not-Equals operator
		*/
		void TestNotEqualsOperator();

		/*!
		\brief Tests the Utf16Char size() function
		*/
		void TestSize();

		/*!
		\brief Test the Utf16Char stream operators
		*/
		void TestStreamOperators();

		/*!
		\brief Tests the to_utf_32() function
		*/
		void TestToUtf32();

		/*!
		\brief Tests the Utf8Char conversion operator
		*/
		void TestUtf8CharConversionOperator();

	private:

	};
}

#endif
