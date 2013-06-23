#ifndef __UTFSTRINGTEST_UNICODECHARREFERENCETEST_H__
#define __UTFSTRINGTEST_UNICODECHARREFERENCETEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the UnicodeCharReference class
	*/
	class UnicodeCharReferenceTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("UnicodeCharReferenceTest");

			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestAssignmentOperator",
				&UnicodeCharReferenceTest::TestAssignmentOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestAssignReference",
				&UnicodeCharReferenceTest::TestAssignReference));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestConstructors",
				&UnicodeCharReferenceTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestEqualsOperator",
				&UnicodeCharReferenceTest::TestEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestInternalEncoding",
				&UnicodeCharReferenceTest::TestInternalEncoding));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestIsValid",
				&UnicodeCharReferenceTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestNotEqualsOperator",
				&UnicodeCharReferenceTest::TestNotEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestReferenceEqual",
				&UnicodeCharReferenceTest::TestReferenceEqual));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestReferenceNotEqual",
				&UnicodeCharReferenceTest::TestReferenceNotEqual));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestToUtf32",
				&UnicodeCharReferenceTest::TestToUtf32));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestUnicodeCharConversionOperator",
				&UnicodeCharReferenceTest::TestUnicodeCharConversionOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestUtf8CharConversionOperator",
				&UnicodeCharReferenceTest::TestUtf8CharConversionOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestUtf16CharConversionOperator",
				&UnicodeCharReferenceTest::TestUtf16CharConversionOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestUtf8CharReferenceConversionOperator",
				&UnicodeCharReferenceTest::TestUtf8CharReferenceConversionOperator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeCharReferenceTest>("TestUtf16CharReferenceConversionOperator",
				&UnicodeCharReferenceTest::TestUtf16CharReferenceConversionOperator));

			return testSuite;
		}

		/*!
		\brief Tests the UnicodeCharReference assignment operator
		*/
		void TestAssignmentOperator();

		/*!
		\brief Tests the assign_reference() function
		*/
		void TestAssignReference();

		/*!
		\brief Tests the UnicodeChar constructors
		*/
		void TestConstructors();

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
		\brief Tests the reference_equal() function
		*/
		void TestReferenceEqual();

		/*!
		\brief Tests the reference_not_equal() function
		*/
		void TestReferenceNotEqual();

		/*!
		\brief Tests the to_utf_32() function
		*/
		void TestToUtf32();

		/*!
		\brief Tests the UnicodeChar conversion operator
		*/
		void TestUnicodeCharConversionOperator();

		/*!
		\brief Tests the Utf8Char conversion operator
		*/
		void TestUtf8CharConversionOperator();

		/*!
		\brief Tests the Utf16Char conversion operator
		*/
		void TestUtf16CharConversionOperator();

		/*!
		\brief Tests the Utf8CharReference conversion operator
		*/
		void TestUtf8CharReferenceConversionOperator();

		/*!
		\brief Tests the Utf16CharReference conversion operator
		*/
		void TestUtf16CharReferenceConversionOperator();

	private:

	};
}

#endif
