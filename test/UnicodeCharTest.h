#ifndef __UTFSTRINGTEST_UNICODECHARTEST_H__
#define __UTFSTRINGTEST_UNICODECHARTEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the UnicodeChar class
	*/
	class UnicodeCharTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("UnicodeCharTest");

			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestAssignmentOperator",
				&UnicodeCharTest::TestAssignmentOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestClear",
				&UnicodeCharTest::TestClear));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestConstructors",
				&UnicodeCharTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestEmpty",
				&UnicodeCharTest::TestEmpty));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestEqualsOperator",
				&UnicodeCharTest::TestEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestInternalEncoding",
				&UnicodeCharTest::TestInternalEncoding));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestIsValid",
				&UnicodeCharTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestNotEqualsOperator",
				&UnicodeCharTest::TestNotEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestToUtf32",
				&UnicodeCharTest::TestToUtf32));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestUtf8CharConversionOperator",
				&UnicodeCharTest::TestUtf8CharConversionOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharTest>("TestUtf16CharConversionOperator",
				&UnicodeCharTest::TestUtf16CharConversionOperator));

			return testSuite;
		}

		/*!
		\brief Tests the UnicodeChar assignment operator
		*/
		void TestAssignmentOperator();

		/*!
		\brief Tests the UnicodeChar clear() function
		*/
		void TestClear();

		/*!
		\brief Tests the UnicodeChar constructors
		*/
		void TestConstructors();

		/*!
		\brief Tests the empty() function
		*/
		void TestEmpty();

		/*!
		\brief Tests the UnicodeChar Equals operator
		*/
		void TestEqualsOperator();

		/*!
		\brief Tests the internal_encoding() function
		*/
		void TestInternalEncoding();

		/*!
		\brief Tests the is_valid() function
		*/
		void TestIsValid();

		/*!
		\brief Tests the UnicodeChar Not-Equals operator
		*/
		void TestNotEqualsOperator();

		/*!
		\brief Tests the to_utf_32() function
		*/
		void TestToUtf32();

		/*!
		\brief Tests the Utf8Char conversion operator
		*/
		void TestUtf8CharConversionOperator();

		/*!
		\brief Tests the Utf16Char conversion operator
		*/
		void TestUtf16CharConversionOperator();

	private:

	};
}

#endif
