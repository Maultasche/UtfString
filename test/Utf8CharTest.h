#ifndef __UTFSTRINGTEST_UTF8CHARTEST_H__
#define __UTFSTRINGTEST_UTF8CHARTEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the Utf8Char class
	*/
	class Utf8CharTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("Utf8CharTest");

			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestAssignmentOperator",
				&Utf8CharTest::TestAssignmentOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestClear",
				&Utf8CharTest::TestClear));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestConstructors",
				&Utf8CharTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestEqualsOperator",
				&Utf8CharTest::TestEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestIndexingOperator",
				&Utf8CharTest::TestIndexingOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestIsValid",
				&Utf8CharTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestNotEqualsOperator",
				&Utf8CharTest::TestNotEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestSize",
				&Utf8CharTest::TestSize));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestStreamOperators",
				&Utf8CharTest::TestStreamOperators));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestToUtf32",
				&Utf8CharTest::TestToUtf32));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharTest>("TestUtf16CharConversionOperator",
				&Utf8CharTest::TestUtf16CharConversionOperator));

			return testSuite;
		}

		/*!
		\brief Tests the Utf8Char assignment operator
		*/
		void TestAssignmentOperator();

		/*!
		\brief Tests the Utf8Char clear() function
		*/
		void TestClear();

		/*!
		\brief Tests the Utf8Char constructors
		*/
		void TestConstructors();

		/*!
		\brief Tests the Utf8Char Equals operator
		*/
		void TestEqualsOperator();

		/*!
		\brief Tests the Utf8Char Indexing operator
		*/
		void TestIndexingOperator();

		/*!
		\brief Tests the is_valid() function
		*/
		void TestIsValid();

		/*!
		\brief Tests the Utf8Char Not-Equals operator
		*/
		void TestNotEqualsOperator();

		/*!
		\brief Tests the Utf8Char size() function
		*/
		void TestSize();

		/*!
		\brief Test the Utf8Char stream operators
		*/
		void TestStreamOperators();

		/*!
		\brief Tests the to_utf_32() function
		*/
		void TestToUtf32();

		/*!
		\brief Tests the Utf16Char conversion operator
		*/
		void TestUtf16CharConversionOperator();

	private:

	};
}

#endif
