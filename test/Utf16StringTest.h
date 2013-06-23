#ifndef __UTFSTRINGTEST_UTF16STRINGTEST_H__
#define __UTFSTRINGTEST_UTF16STRINGTEST_H__

#include "UtfStringUnitTests.h"

#include <utfstring/UtfString.h>

namespace UtfStringTest
{
	/*!
	\brief Provides the tests for the Utf16String class
	*/
	class Utf16StringTest : public CppUnit::TestFixture
	{
	public:
		/*!
		\brief Constructs and returns a test suite for the test runner
		*/
		static CppUnit::Test* suite()
		{
			CppUnit::TestSuite* testSuite = new CppUnit::TestSuite("Utf16StringTest");

			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestAppend",
				&Utf16StringTest::TestAppend));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestAssign",
				&Utf16StringTest::TestAssign));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestAt",
				&Utf16StringTest::TestAt));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestBegin",
				&Utf16StringTest::TestBegin));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestCapacity",
				&Utf16StringTest::TestCapacity));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestCharacterCodeUnitCount",
				&Utf16StringTest::TestCharacterCodeUnitCount));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestClear",
				&Utf16StringTest::TestClear));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestCodePointIndex",
				&Utf16StringTest::TestCodePointIndex));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestCodeUnitIndex",
				&Utf16StringTest::TestCodeUnitIndex));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestCompare",
				&Utf16StringTest::TestCompare));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestConstIterator",
				&Utf16StringTest::TestConstIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestConstIteratorReversal",
				&Utf16StringTest::TestConstIteratorReversal));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestConstReverseIterator",
				&Utf16StringTest::TestConstReverseIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestConstructors",
				&Utf16StringTest::TestConstructors));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestCopy",
				&Utf16StringTest::TestCopy));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestCStr",
				&Utf16StringTest::TestCStr));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestData",
				&Utf16StringTest::TestData));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestDecodeCharacter",
				&Utf16StringTest::TestDecodeCharacter));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestEmpty",
				&Utf16StringTest::TestEmpty));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestEncodeCharacter",
				&Utf16StringTest::TestEncodeCharacter));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestEnd",
				&Utf16StringTest::TestEnd));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestErase",
				&Utf16StringTest::TestErase));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestFind",
				&Utf16StringTest::TestFind));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestFindFirstNotOf",
				&Utf16StringTest::TestFindFirstNotOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestFindFirstOf",
				&Utf16StringTest::TestFindFirstOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestFindLastNotOf",
				&Utf16StringTest::TestFindLastNotOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestFindLastOf",
				&Utf16StringTest::TestFindLastOf));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestIndexer",
				&Utf16StringTest::TestIndexer));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestInsert",
				&Utf16StringTest::TestInsert));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestIsValid",
				&Utf16StringTest::TestIsValid));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestIsValidCharacter",
				&Utf16StringTest::TestIsValidCharacter));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestIsWhitespace",
				&Utf16StringTest::TestIsWhitespace));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestIterator",
				&Utf16StringTest::TestIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestIteratorReversal",
				&Utf16StringTest::TestIteratorReversal));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestLength",
				&Utf16StringTest::TestLength));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestPushBack",
				&Utf16StringTest::TestPushBack));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestRbegin",
				&Utf16StringTest::TestRbegin));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestRend",
				&Utf16StringTest::TestRend));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestReplace",
				&Utf16StringTest::TestReplace));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestReverseIterator",
				&Utf16StringTest::TestReverseIterator));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestRFind",
				&Utf16StringTest::TestRFind));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestSize",
				&Utf16StringTest::TestSize));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestStreamOperators",
				&Utf16StringTest::TestStreamOperators));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestSubstr",
				&Utf16StringTest::TestSubstr));
			testSuite->addTest(new CppUnit::TestCaller<Utf16StringTest>("TestSwap",
				&Utf16StringTest::TestSwap));

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
		\brief Tests Utf16String::const_iterator
		*/
		void TestConstIterator();

		/*!
		\brief Tests the functionality that allows conversion between const_iterator and const_reverse_iterator
		*/
		void TestConstIteratorReversal();

		/*!
		\brief Tests Utf16String::const_reverse_iterator
		*/
		void TestConstReverseIterator();

		/*!
		\brief Tests the Utf16String constructors
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
		\brief Tests the Utf16String indexer
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
		\brief Tests Utf16String::iterator
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
		\brief Tests Utf16String::reverse_iterator
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
		\brief Tests the Utf16String constructors a set of different types of strings
		*/
		void TestConstructorsWithStrings(const std::string& characterString,
			const UtfString::Utf8String& utf8String, const UtfString::Utf16String& utf16String);

		/*!
		\brief Tests the Utf16String::const_iterator class using a Utf16String that contains only ASCII
			characters that have one code unit in UTF-8 and one code unit in UTF-16
		*/
		void TestConstIteratorWithStringOne();

		/*!
		\brief Tests the Utf16String::const_iterator class using a Utf16String that contains characters
			that would have one or two code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestConstIteratorWithStringTwo();

		/*!
		\brief Tests the Utf16String::const_iterator class using a Utf16String that contains characters
			that would have one, two, or three code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestConstIteratorWithStringThree();

		/*!
		\brief Tests the Utf16String::const_iterator class using a Utf16String that contains characters
			that would have one, two, three, or four code units in UTF-8, but either one or two
			code units in UTF-16.
		*/
		void TestConstIteratorWithStringFour();

		/*!
		\brief Tests the Utf16String::iterator class using a Utf16String that contains only ASCII
			characters that have one code unit in UTF-8 and one code unit in UTF-16
		*/
		void TestIteratorWithStringOne();

		/*!
		\brief Tests the Utf16String::iterator class using a Utf16String that contains characters
			that would have one or two code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestIteratorWithStringTwo();

		/*!
		\brief Tests the Utf16String::iterator class using a Utf16String that contains characters
			that would have one, two, or three code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestIteratorWithStringThree();

		/*!
		\brief Tests the Utf16String::iterator class using a Utf16String that contains characters
			that would have one, two, three, or four code units in UTF-8, but either one or two
			code units in UTF-16.
		*/
		void TestIteratorWithStringFour();

		/*!
		\brief Tests the Utf16String::reverse_iterator class using a Utf16String that contains only ASCII
			characters that have one code unit in UTF-8 and one code unit in UTF-16
		*/
		void TestReverseIteratorWithStringOne();

		/*!
		\brief Tests the Utf16String::reverse_iterator class using a Utf16String that contains characters
			that would have one or two code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestReverseIteratorWithStringTwo();

		/*!
		\brief Tests the Utf16String::reverse_iterator class using a Utf16String that contains characters
			that would have one, two, or three code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestReverseIteratorWithStringThree();

		/*!
		\brief Tests the Utf16String::reverse_iterator class using a Utf16String that contains characters
			that would have one, two, three, or four code units in UTF-8, but either one or two
			code units in UTF-16.
		*/
		void TestReverseIteratorWithStringFour();

		/*!
		\brief Tests the Utf16String::const_reverse_iterator class using a Utf16String that contains only ASCII
			characters that have one code unit in UTF-8 and one code unit in UTF-16
		*/
		void TestConstReverseIteratorWithStringOne();

		/*!
		\brief Tests the Utf16String::const_reverse_iterator class using a Utf16String that contains characters
			that would have one or two code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestConstReverseIteratorWithStringTwo();

		/*!
		\brief Tests the Utf16String::const_reverse_iterator class using a Utf16String that contains characters
			that would have one, two, or three code units in UTF-8, but only one code unit in UTF-16
		*/
		void TestConstReverseIteratorWithStringThree();

		/*!
		\brief Tests the Utf16String::const_reverse_iterator class using a Utf16String that contains characters
			that would have one, two, three, or four code units in UTF-8, but either one or two
			code units in UTF-16.
		*/
		void TestConstReverseIteratorWithStringFour();
	};
}

#endif
