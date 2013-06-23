#ifndef __UTFSTRINGTEST_STRINGCONVERTERTEST_H__
#define __UTFSTRINGTEST_STRINGCONVERTERTEST_H__

#include "UtfStringUnitTests.h"

/*!
\namespace UtfStringTest

Contains the classes needed to test the UTF String library
*/

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the string conversion functionality
	*/
	class StringConverterTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("StringConverterTest");

			testSuite->addTest(new CppUnit::TestCaller<StringConverterTest>("TestUtf8ToUtf16String",
				&StringConverterTest::TestUtf8ToUtf16String));
			testSuite->addTest(new CppUnit::TestCaller<StringConverterTest>("TestUtf16ToUtf8String",
				&StringConverterTest::TestUtf16ToUtf8String));

			return testSuite;
		}

		/*!
		\brief Tests the Utf8ToUtf16String function
		*/
		void TestUtf8ToUtf16String();

		/*!
		\brief Tests the Utf16ToUtf8String function
		*/
		void TestUtf16ToUtf8String();
	};
}

#endif
