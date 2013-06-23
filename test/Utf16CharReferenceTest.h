#ifndef __UTFSTRINGTEST_UTF16CHARREFERENCETEST_H__
#define __UTFSTRINGTEST_UTF16CHARREFERENCETEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the Utf16CharReference class
	*/
	class Utf16CharReferenceTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("Utf16CharReferenceTest");

			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestAssignmentOperator",
				&Utf16CharReferenceTest::TestAssignmentOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestAssignReference",
				&Utf16CharReferenceTest::TestAssignReference));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestConstructors",
				&Utf16CharReferenceTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestEqualsOperator",
				&Utf16CharReferenceTest::TestEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestIndexingOperator",
				&Utf16CharReferenceTest::TestIndexingOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestIsValid",
				&Utf16CharReferenceTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestNotEqualsOperator",
				&Utf16CharReferenceTest::TestNotEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestReferenceEqual",
				&Utf16CharReferenceTest::TestReferenceEqual));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestReferenceNotEqual",
				&Utf16CharReferenceTest::TestReferenceNotEqual));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestSize",
				&Utf16CharReferenceTest::TestSize));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestToUtf32",
				&Utf16CharReferenceTest::TestToUtf32));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestUtf16CharConversionOperator",
				&Utf16CharReferenceTest::TestUtf16CharConversionOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16CharReferenceTest>("TestUtf8CharConversionOperator",
				&Utf16CharReferenceTest::TestUtf8CharConversionOperator));

			return testSuite;
		}

		/*!
		\brief Tests the Utf16CharReference assignment operator
		*/
		void TestAssignmentOperator();

		/*!
		\brief Tests the assign_reference() function
		*/
		void TestAssignReference();

		/*!
		\brief Tests the Utf16CharReference constructors
		*/
		void TestConstructors();

		/*!
		\brief Tests the Utf16CharReference Equals operator
		*/
		void TestEqualsOperator();

		/*!
		\brief Tests the Utf16CharReference Indexing operator
		*/
		void TestIndexingOperator();

		/*!
		\brief Tests the is_valid() function
		*/
		void TestIsValid();

		/*!
		\brief Tests the Utf16CharReference Not-Equals operator
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
		\brief Tests the Utf16CharReference size() function
		*/
		void TestSize();

		/*!
		\brief Tests the Utf16Char conversion operator
		*/
		void TestUtf16CharConversionOperator();

		/*!
		\brief Tests the Utf8Char conversion operator
		*/
		void TestUtf8CharConversionOperator();
	};
}

#endif

