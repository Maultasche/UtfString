#ifndef __UTFSTRINGTEST_UNICODESTRINGTEST_H__
#define __UTFSTRINGTEST_UNICODESTRINGTEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the UnicodeString class
	*/
	class UnicodeStringTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("UnicodeStringTest");

			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestAppend",
				&UnicodeStringTest::TestAppend));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestAssign",
				&UnicodeStringTest::TestAssign));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestAt",
				&UnicodeStringTest::TestAt));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestBegin",
				&UnicodeStringTest::TestBegin));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestClear",
				&UnicodeStringTest::TestClear));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestCompare",
				&UnicodeStringTest::TestCompare));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestConstIterator",
				&UnicodeStringTest::TestConstIterator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestConstIteratorReversal",
				&UnicodeStringTest::TestConstIteratorReversal));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestConstReverseIterator",
				&UnicodeStringTest::TestConstReverseIterator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestConstructors",
				&UnicodeStringTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestEmpty",
				&UnicodeStringTest::TestEmpty));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestEnd",
				&UnicodeStringTest::TestEnd));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestErase",
				&UnicodeStringTest::TestErase));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestFind",
				&UnicodeStringTest::TestFind));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestFindFirstNotOf",
				&UnicodeStringTest::TestFindFirstNotOf));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestFindFirstOf",
				&UnicodeStringTest::TestFindFirstOf));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestFindLastNotOf",
				&UnicodeStringTest::TestFindLastNotOf));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestFindLastOf",
				&UnicodeStringTest::TestFindLastOf));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestIndexer",
				&UnicodeStringTest::TestIndexer));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestInsert",
				&UnicodeStringTest::TestInsert));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestIsValid",
				&UnicodeStringTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestIsWhitespace",
				&UnicodeStringTest::TestIsWhitespace));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestIterator",
				&UnicodeStringTest::TestIterator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestIteratorReversal",
				&UnicodeStringTest::TestIteratorReversal));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestLength",
				&UnicodeStringTest::TestLength));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestPushBack",
				&UnicodeStringTest::TestPushBack));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestRbegin",
				&UnicodeStringTest::TestRbegin));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestRend",
				&UnicodeStringTest::TestRend));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestReplace",
				&UnicodeStringTest::TestReplace));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestReverseIterator",
				&UnicodeStringTest::TestReverseIterator));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestRFind",
				&UnicodeStringTest::TestRFind));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestSize",
				&UnicodeStringTest::TestSize));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestStreamOperators",
				&UnicodeStringTest::TestStreamOperators));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestSubstr",
				&UnicodeStringTest::TestSubstr));
			testSuite->addTest(new CppUnit::TestCaller<UnicodeStringTest>("TestSwap",
				&UnicodeStringTest::TestSwap));

			return testSuite;
		}

		/*!
		\brief Tests the append() function
		*/
		void TestAppend();

		/*!
		\brief Tests the assign() function
		*/
		void TestAssign();

		/*!
		\brief Tests the at() function
		*/
		void TestAt();

		/*!
		\brief Tests the begin() function
		*/
		void TestBegin();

		/*!
		\brief Tests the clear() function
		*/
		void TestClear();

		/*!
		\brief Tests the compare() function
		*/
		void TestCompare();

		/*!
		\brief Tests Utf8String::const_iterator
		*/
		void TestConstIterator();

		/*!
		\brief Tests the functionality that allows conversion between const_iterator and const_reverse_iterator
		*/
		void TestConstIteratorReversal();

		/*!
		\brief Tests Utf8String::const_reverse_iterator
		*/
		void TestConstReverseIterator();

		/*!
		\brief Tests the Utf8String constructors
		*/
		void TestConstructors();

		/*!
		\brief Tests the empty() function
		*/
		void TestEmpty();

		/*!
		\brief Tests the end() function
		*/
		void TestEnd();

		/*!
		\brief Tests the erase() function
		*/
		void TestErase();

		/*!
		\brief Tests the find() function
		*/
		void TestFind();

		/*!
		\brief Tests the find_first_not_of() function
		*/
		void TestFindFirstNotOf();

		/*!
		\brief Tests the find_first_of() function
		*/
		void TestFindFirstOf();

		/*!
		\brief Tests the find_last_not_of() function
		*/
		void TestFindLastNotOf();

		/*!
		\brief Tests the find_last_of() function
		*/
		void TestFindLastOf();

		/*!
		\brief Tests the Utf8String indexer
		*/
		void TestIndexer();

		/*!
		\brief Tests the insert() function
		*/
		void TestInsert();

		/*!
		\brief Tests the is_valid() function
		*/
		void TestIsValid();

		/*!
		\brief Tests the IsWhitespace() function
		*/
		void TestIsWhitespace();

		/*!
		\brief Tests Utf8String::iterator
		*/
		void TestIterator();

		/*!
		\brief Tests the functionality that allows conversion between iterator and reverse_iterator
		*/
		void TestIteratorReversal();

		/*!
		\brief Tests the length() function
		*/
		void TestLength();

		/*!
		\brief Tests the push_back() function
		*/
		void TestPushBack();

		/*!
		\brief Tests the rbegin() function
		*/
		void TestRbegin();

		/*!
		\brief Tests the rend() function
		*/
		void TestRend();

		/*!
		\brief Tests the replace() function
		*/
		void TestReplace();

		/*!
		\brief Tests Utf8String::reverse_iterator
		*/
		void TestReverseIterator();

		/*!
		\brief Tests the rfind() function
		*/
		void TestRFind();

		/*!
		\brief Tests the size() function
		*/
		void TestSize();

		/*!
		\brief Tests the << and >> stream operators
		*/
		void TestStreamOperators();

		/*!
		\brief Tests the substr() function
		*/
		void TestSubstr();

		/*!
		\brief Tests the swap() function
		*/
		void TestSwap();

	private:
		/*!
		\brief Tests the Utf8String constructors a set of different types of strings
		*/
		void TestConstructorsWithStrings(const UtfString::Utf8String& utf8String, 
			const UtfString::Utf16String& utf16String);

		/*!
		\brief Tests the Utf8String::const_iterator class using a Utf8String that contains only ASCII
			characters that have one code unit in UTF-8
		*/
		void TestConstIteratorWithStringOne();

		/*!
		\brief Tests the Utf8String::const_iterator class using a Utf8String that contains characters
			that would have one or two code units in UTF-8
		*/
		void TestConstIteratorWithStringTwo();

		/*!
		\brief Tests the Utf8String::const_iterator class using a Utf8String that contains characters
			that would have one, two, or three code units in UTF-8
		*/
		void TestConstIteratorWithStringThree();

		/*!
		\brief Tests the Utf8String::const_iterator class using a Utf8String that contains characters
			that would have one, two, three, or four code units in UTF-8
		*/
		void TestConstIteratorWithStringFour();

		/*!
		\brief Tests the Utf8String::iterator class using a Utf8String that contains only ASCII
			characters that have one code unit in UTF-8
		*/
		void TestIteratorWithStringOne();

		/*!
		\brief Tests the Utf8String::iterator class using a Utf8String that contains characters
			that would have one or two code units in UTF-8
		*/
		void TestIteratorWithStringTwo();

		/*!
		\brief Tests the Utf8String::iterator class using a Utf8String that contains characters
			that would have one, two, or three code units in UTF-8
		*/
		void TestIteratorWithStringThree();

		/*!
		\brief Tests the Utf8String::iterator class using a Utf8String that contains characters
			that would have one, two, three, or four code units in UTF-8
		*/
		void TestIteratorWithStringFour();

		/*!
		\brief Tests the Utf8String::reverse_iterator class using a Utf8String that contains only ASCII
			characters that have one code unit in UTF-8
		*/
		void TestReverseIteratorWithStringOne();

		/*!
		\brief Tests the Utf8String::reverse_iterator class using a Utf8String that contains characters
			that would have one or two code units in UTF-8
		*/
		void TestReverseIteratorWithStringTwo();

		/*!
		\brief Tests the Utf8String::reverse_iterator class using a Utf8String that contains characters
			that would have one, two, or three code units in UTF-8
		*/
		void TestReverseIteratorWithStringThree();

		/*!
		\brief Tests the Utf8String::reverse_iterator class using a Utf8String that contains characters
			that would have one, two, three, or four code units in UTF-8.
		*/
		void TestReverseIteratorWithStringFour();

		/*!
		\brief Tests the Utf8String::const_reverse_iterator class using a Utf8String that contains only ASCII
			characters that have one code unit in UTF-8
		*/
		void TestConstReverseIteratorWithStringOne();

		/*!
		\brief Tests the Utf8String::const_reverse_iterator class using a Utf8String that contains characters
			that would have one or two code units in UTF-8
		*/
		void TestConstReverseIteratorWithStringTwo();

		/*!
		\brief Tests the Utf8String::const_reverse_iterator class using a Utf8String that contains characters
			that would have one, two, or three code units in UTF-8
		*/
		void TestConstReverseIteratorWithStringThree();

		/*!
		\brief Tests the Utf8String::const_reverse_iterator class using a Utf8String that contains characters
			that would have one, two, three, or four code units in UTF-8
		*/
		void TestConstReverseIteratorWithStringFour();
	};
}

#endif
