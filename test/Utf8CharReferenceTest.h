#ifndef __UTFSTRINGTEST_UTF8CHARREFERENCETEST_H__
#define __UTFSTRINGTEST_UTF8CHARREFERENCETEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the Utf8CharReference class
	*/
	class Utf8CharReferenceTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("Utf8CharReferenceTest");

			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestAssignmentOperator",
				&Utf8CharReferenceTest::TestAssignmentOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestAssignReference",
				&Utf8CharReferenceTest::TestAssignReference));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestConstructors",
				&Utf8CharReferenceTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestEqualsOperator",
				&Utf8CharReferenceTest::TestEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestIndexingOperator",
				&Utf8CharReferenceTest::TestIndexingOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestIsValid",
				&Utf8CharReferenceTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestNotEqualsOperator",
				&Utf8CharReferenceTest::TestNotEqualsOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestReferenceEqual",
				&Utf8CharReferenceTest::TestReferenceEqual));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestReferenceNotEqual",
				&Utf8CharReferenceTest::TestReferenceNotEqual));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestSize",
				&Utf8CharReferenceTest::TestSize));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestToUtf32",
				&Utf8CharReferenceTest::TestToUtf32));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestUtf8CharConversionOperator",
				&Utf8CharReferenceTest::TestUtf8CharConversionOperator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8CharReferenceTest>("TestUtf16CharConversionOperator",
				&Utf8CharReferenceTest::TestUtf16CharConversionOperator));

			return testSuite;
		}

		/*!
		\brief Tests the Utf8CharReference assignment operator
		*/
		void TestAssignmentOperator();

		/*!
		\brief Tests the assign_reference() function
		*/
		void TestAssignReference();

		/*!
		\brief Tests the Utf8CharReference constructors
		*/
		void TestConstructors();

		/*!
		\brief Tests the Utf8CharReference Equals operator
		*/
		void TestEqualsOperator();

		/*!
		\brief Tests the Utf8CharReference Indexing operator
		*/
		void TestIndexingOperator();

		/*!
		\brief Tests the is_valid() function
		*/
		void TestIsValid();

		/*!
		\brief Tests the Utf8CharReference Not-Equals operator
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
		\brief Tests the Utf8CharReference size() function
		*/
		void TestSize();

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
