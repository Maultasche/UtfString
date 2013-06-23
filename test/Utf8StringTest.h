#ifndef __UTFSTRINGTEST_UTF8STRINGTEST_H__
#define __UTFSTRINGTEST_UTF8STRINGTEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the Utf8String class
	*/
	class Utf8StringTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("Utf8StringTest");

			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestAppend",
				&Utf8StringTest::TestAppend));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestAssign",
				&Utf8StringTest::TestAssign));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestAt",
				&Utf8StringTest::TestAt));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestBegin",
				&Utf8StringTest::TestBegin));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestCapacity",
				&Utf8StringTest::TestCapacity));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestCharacterCodeUnitCount",
				&Utf8StringTest::TestCharacterCodeUnitCount));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestClear",
				&Utf8StringTest::TestClear));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestCodePointIndex",
				&Utf8StringTest::TestCodePointIndex));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestCodeUnitIndex",
				&Utf8StringTest::TestCodeUnitIndex));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestCompare",
				&Utf8StringTest::TestCompare));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestConstIterator",
				&Utf8StringTest::TestConstIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestConstIteratorReversal",
				&Utf8StringTest::TestConstIteratorReversal));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestConstReverseIterator",
				&Utf8StringTest::TestConstReverseIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestConstructors",
				&Utf8StringTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestCopy",
				&Utf8StringTest::TestCopy));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestCStr",
				&Utf8StringTest::TestCStr));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestData",
				&Utf8StringTest::TestData));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestDecodeCharacter",
				&Utf8StringTest::TestDecodeCharacter));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestEmpty",
				&Utf8StringTest::TestEmpty));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestEncodeCharacter",
				&Utf8StringTest::TestEncodeCharacter));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestEnd",
				&Utf8StringTest::TestEnd));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestErase",
				&Utf8StringTest::TestErase));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestFind",
				&Utf8StringTest::TestFind));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestFindFirstNotOf",
				&Utf8StringTest::TestFindFirstNotOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestFindFirstOf",
				&Utf8StringTest::TestFindFirstOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestFindLastNotOf",
				&Utf8StringTest::TestFindLastNotOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestFindLastOf",
				&Utf8StringTest::TestFindLastOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestIndexer",
				&Utf8StringTest::TestIndexer));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestInsert",
				&Utf8StringTest::TestInsert));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestIsValid",
				&Utf8StringTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestIsValidCharacter",
				&Utf8StringTest::TestIsValidCharacter));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestIsWhitespace",
				&Utf8StringTest::TestIsWhitespace));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestIterator",
				&Utf8StringTest::TestIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestIteratorReversal",
				&Utf8StringTest::TestIteratorReversal));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestLength",
				&Utf8StringTest::TestLength));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestPushBack",
				&Utf8StringTest::TestPushBack));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestRbegin",
				&Utf8StringTest::TestRbegin));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestRend",
				&Utf8StringTest::TestRend));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestReplace",
				&Utf8StringTest::TestReplace));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestReverseIterator",
				&Utf8StringTest::TestReverseIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestRFind",
				&Utf8StringTest::TestRFind));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestSize",
				&Utf8StringTest::TestSize));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestStreamOperators",
				&Utf8StringTest::TestStreamOperators));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestSubstr",
				&Utf8StringTest::TestSubstr));
			testSuite->addTest(new CppUnit::TestCaller<Utf8StringTest>("TestSwap",
				&Utf8StringTest::TestSwap));

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
		\brief Tests the capacity() function
		*/
		void TestCapacity();

		/*!
		\brief Tests the CharacterCodeUnitCount() function
		*/
		void TestCharacterCodeUnitCount();

		/*!
		\brief Tests the clear() function
		*/
		void TestClear();

		/*!
		\brief Tests the code_point_index() function
		*/
		void TestCodePointIndex();

		/*!
		\brief Tests the code_unit_index() function
		*/
		void TestCodeUnitIndex();

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
		\brief Tests the copy() function
		*/
		void TestCopy();

		/*!
		\brief Tests the c_str() function
		*/
		void TestCStr();

		/*!
		\brief Tests the data() function
		*/
		void TestData();

		/*!
		\brief Tests the DecodeCharacter() function
		*/
		void TestDecodeCharacter();

		/*!
		\brief Tests the empty() function
		*/
		void TestEmpty();

		/*!
		\brief Tests the EncodeCharacter() function
		*/
		void TestEncodeCharacter();

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
		\brief Tests the IsValidCharacter() function
		*/
		void TestIsValidCharacter();

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
		void TestConstructorsWithStrings(const std::string& characterString,
			const UtfString::Utf8String& utf8String, const UtfString::Utf16String& utf16String);

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
