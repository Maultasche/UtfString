/*!
\file Utf16CharTest.cpp

This file contains the definition of the Utf16CharTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <string>

#include "Utf16CharTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void Utf16CharTest::TestAssignmentOperator()
{
	//Test the = operator that accepts a Utf16Char
	Utf16Char firstCharacter;
	firstCharacter[0] = (UInt16)L'\x00F6';

	Utf16Char secondCharacter;
	secondCharacter[0] = (UInt16)L'\x00A6';

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00A6', firstCharacter[0]);

	firstCharacter.clear();
	firstCharacter[0] = (UInt16)L'\x0053';

	secondCharacter.clear();
	secondCharacter[0] = (UInt16)L'S';

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0053', firstCharacter[0]);

	firstCharacter.clear();
	firstCharacter[0] = L'2';

	secondCharacter.clear();
	secondCharacter[0] = L'T';

	secondCharacter = firstCharacter;
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'2', firstCharacter[0]);

	firstCharacter.clear();
	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'\xEA0B';

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xEA0B', firstCharacter[0]);

	firstCharacter.clear();
	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'\xD800';
	secondCharacter[1] = L'\xDF46';

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', firstCharacter[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', firstCharacter[1]);

	firstCharacter.clear();
	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'\xD800';

	secondCharacter = firstCharacter;
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', secondCharacter[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', secondCharacter[1]);

	firstCharacter.clear();
	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'W';

	secondCharacter = firstCharacter;
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', secondCharacter[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', secondCharacter[1]);

	//Test the = operator that accepts a Utf16CharReference
	//Create a UTF-16 string composed of only single-code-unit characters
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	
	firstCharacter.clear();
	firstCharacter[0] = L'\x1EAB';

	firstCharacter = utf16String[3];
	CPPUNIT_ASSERT(utf16String[3] == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', firstCharacter[0]);

	firstCharacter.clear();

	firstCharacter = utf16String[6];
	CPPUNIT_ASSERT(utf16String[6] == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', firstCharacter[0]);

	//Create a UTF-16 string composed of one- and two-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	firstCharacter.clear();
	firstCharacter[0] = L'\xD800';
	firstCharacter[1] = L'\xDF46';

	firstCharacter = utf16String[2];
	CPPUNIT_ASSERT(utf16String[2] == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', firstCharacter[0]);

	firstCharacter.clear();
	firstCharacter[0] = L'\xD800';
	firstCharacter[1] = L'\xDF46';

	firstCharacter = utf16String[3];
	CPPUNIT_ASSERT(utf16String[3] == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', firstCharacter[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', firstCharacter[1]);

	firstCharacter.clear();

	firstCharacter = utf16String[9];
	CPPUNIT_ASSERT(utf16String[9] == firstCharacter);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', firstCharacter[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', firstCharacter[1]);

}

void Utf16CharTest::TestClear()
{
	Utf16Char character;
	character[0] = (UInt16)L'\x00F6';

	CPPUNIT_ASSERT_EQUAL((size_t)1, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character[1] = L'\xDF46';

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());
}

void Utf16CharTest::TestConstructors()
{
	//Create a UTF-16 string composed of only single-code-unit characters
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Create a Utf16Char using the default constructor
	Utf16Char* constructedCharacter = new Utf16Char();

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)0, constructedCharacter->size());

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf16Char using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	basic_string<UInt16> codeUnitString = utf16String;
	basic_string<UInt16>::iterator basicStringIterator = codeUnitString.begin() + 1;
	constructedCharacter = new Utf16Char(basicStringIterator, Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf16Char using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringIterator = codeUnitString.end() - 1;
	constructedCharacter = new Utf16Char(basicStringIterator, Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf16Char using the constructor that accepts a std::basic_string<UInt16>::const_iterator
	//and a size_t
	codeUnitString = utf16String;
	basic_string<UInt16>::const_iterator basicStringConstIterator = codeUnitString.begin() + 1;
	constructedCharacter = new Utf16Char(basicStringConstIterator, Utf16String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf16Char using the constructor that accepts a std::basic_string<UInt16>::const_iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringConstIterator = codeUnitString.end() - 1;
	constructedCharacter = new Utf16Char(basicStringConstIterator, Utf16String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Now repeat the tests using two-code-unit characters

	//Create a UTF-16 string composed of one- and two-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Create a Utf16Char using the default constructor
	constructedCharacter = new Utf16Char();

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)0, constructedCharacter->size());

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf16Char using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringIterator = codeUnitString.begin() + 5;
	constructedCharacter = new Utf16Char(basicStringIterator, Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf16Char using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringIterator = codeUnitString.begin() + 3;
	constructedCharacter = new Utf16Char(basicStringIterator, Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constructedCharacter)[1]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf16Char using the constructor that accepts a std::basic_string<UInt16>::const_iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringConstIterator = codeUnitString.begin() + 5;
	constructedCharacter = new Utf16Char(basicStringConstIterator, Utf16String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf16Char using the constructor that accepts a std::basic_string<UInt16>::const_iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringConstIterator = codeUnitString.begin() + 3;
	constructedCharacter = new Utf16Char(basicStringConstIterator, Utf16String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constructedCharacter)[1]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf16Char using the constructor that accepts a wchar_t
	constructedCharacter = new Utf16Char(L'\x03A1');

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x03A1', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf16Char using the constructor that accepts a char
	constructedCharacter = new Utf16Char('X');

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'X', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf16Char using the constructor that accepts a wchar_t*
	//Create a character with one code unit
	constructedCharacter = new Utf16Char(L"\x03A1");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x03A1', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a character with two code units
	constructedCharacter = new Utf16Char(L"\xD808\xDC68");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constructedCharacter)[1]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a character from a string with many code units
	constructedCharacter = new Utf16Char(L"\xD808\xDC68\x0543\x0053\x1EAB");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constructedCharacter)[1]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create an invalid character from a string with many code units
	constructedCharacter = new Utf16Char(L"\xD808\x0029\x0543\x0053\x1EAB");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0029', (*constructedCharacter)[1]);

	delete constructedCharacter;
	constructedCharacter = NULL;

}

void Utf16CharTest::TestEqualsOperator()
{
	//Test the == operator that accepts a Utf16Char
	Utf16Char firstCharacter;
	firstCharacter[0] = (UInt16)L'\x00F6';

	Utf16Char secondCharacter;
	secondCharacter[0] = (UInt16)L'\x00F6';

	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	firstCharacter[0] = (UInt16)L'\x0053';
	secondCharacter[0] = (UInt16)L'S';

	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	firstCharacter[0] = L'2';
	secondCharacter[0] = L'T';

	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter[0] = L'\xD808';
	secondCharacter[1] = L'\xDC68';

	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter[0] = L'\xD800';
	secondCharacter[1] = L'\xDF46';

	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'\xD800';

	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'W';

	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	//Test the == operator that accepts a Utf16Char
	//Create a UTF-16 string composed of only single-code-unit characters
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	
	firstCharacter.clear();
	firstCharacter[0] = L'\x1EAB';

	CPPUNIT_ASSERT(firstCharacter == utf16String[6]);

	//Create a UTF-16 string composed of one- and two-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	firstCharacter.clear();
	firstCharacter[0] = L'\xD800';
	firstCharacter[1] = L'\xDF46';

	CPPUNIT_ASSERT(firstCharacter == utf16String[9]);
}

void Utf16CharTest::TestIndexingOperator()
{
	Utf16Char character;
	character[0] = (UInt16)L'\x00F6';

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', character[0]);
	
	character.clear();

	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', character[1]);
	
	character.clear();
}

void Utf16CharTest::TestIsValid()
{
	Utf16Char character;

	//Validate an empty character
	CPPUNIT_ASSERT(!character.is_valid());

	//Validate valid one-code-unit characters
	character[0] = L'\x0033';

	CPPUNIT_ASSERT(character.is_valid());

	character[0] = L'\x1EAB';

	CPPUNIT_ASSERT(character.is_valid());

	//Validate invalid one-code-unit characters
	//Test the character on the lower boundary of the invalid range
	character[0] = L'\xD800';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character in the middle of the invalid range
	character[0] = L'\xDA92';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character at the end of the invalid range
	character[0] = L'\xDFFF';

	CPPUNIT_ASSERT(!character.is_valid());

	//Validate one-code-unit characters on the other side of the invalid range
	//Test a boundary character
	character[0] = L'\xE000';

	CPPUNIT_ASSERT(character.is_valid());

	//Test a character in the middle of the second valid range
	character[0] = L'\xEFFF';

	CPPUNIT_ASSERT(character.is_valid());

	//Test some valid two-code-unit characters
	character[0] = L'\xD808';
	character[1] = L'\xDC68';

	CPPUNIT_ASSERT(character.is_valid());

	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(character.is_valid());

	//Test some invalid two-code-unit characters, where the first code unit is outside the range D800-DBFF
	//Test a character with the first code unit way outside the valid range
	character[0] = L'\x0045';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with the first code unit just below the valid range
	character[0] = L'\xD7FF';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with the first code unit just above the valid range
	character[0] = L'\xDC00';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test some invalid two-code-unit characters, where the second code unit is outside the range DC00-DFFF
	//Test a character with the second code unit way outside the valid range
	character[0] = L'\xD809';
	character[1] = L'\x0045';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with the second code unit just below the valid range
	character[0] = L'\xD809';
	character[1] = L'\xDB99';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with the second code unit just above the valid range
	character[0] = L'\xD809';
	character[1] = L'\xE000';

	CPPUNIT_ASSERT(!character.is_valid());

	//Now test a two-code-unit character with both code units outside the allowed ranges
	character[0] = L'\x1ABC';
	character[1] = L'\xF42A';

	CPPUNIT_ASSERT(!character.is_valid());
}

void Utf16CharTest::TestNotEqualsOperator()
{
	//Test the != operator that accepts a Utf16Char
	Utf16Char firstCharacter;
	firstCharacter[0] = (UInt16)L'\x00F6';

	Utf16Char secondCharacter;
	secondCharacter[0] = (UInt16)L'\x0065';

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter[0] = (UInt16)L'b';
	secondCharacter[0] = (UInt16)L'S';

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter[0] = L'T';
	secondCharacter[0] = L'T';

	CPPUNIT_ASSERT(!(firstCharacter != secondCharacter));

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter[0] = L'\xD808';
	secondCharacter[1] = L'\xDC68';

	CPPUNIT_ASSERT(!(firstCharacter != secondCharacter));

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter[0] = L'\xD800';
	secondCharacter[1] = L'\xDF46';

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'\xD800';

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter[0] = L'\xD808';
	firstCharacter[1] = L'\xDC68';

	secondCharacter.clear();
	secondCharacter[0] = L'W';

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	//Test the != operator that accepts a Utf16CharReference
	//Create a UTF-16 string composed of only single-code-unit characters
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	
	firstCharacter.clear();
	firstCharacter[0] = L'\x0062';

	CPPUNIT_ASSERT(firstCharacter != utf16String[6]);

	//Create a UTF-16 string composed of one- and two-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	firstCharacter.clear();
	firstCharacter[0] = L'\xD800';
	firstCharacter[1] = L'\xDF46';

	CPPUNIT_ASSERT(firstCharacter != utf16String[8]);

	firstCharacter.clear();
	firstCharacter[0] = L'\xD800';
	firstCharacter[1] = L'\xDF46';

	CPPUNIT_ASSERT(!(firstCharacter != utf16String[9]));
}

void Utf16CharTest::TestSize()
{
	Utf16Char character;
	character[0] = (UInt16)L'\x00F6';

	CPPUNIT_ASSERT_EQUAL((size_t)1, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character[1] = L'\xDF46';

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());
}

void Utf16CharTest::TestStreamOperators()
{
	stringstream stringStream;

	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	Utf16Char deserializedChar;

	//Write a series of characters to a stream
	stringStream << utf16String[0] << utf16String[1] << utf16String[2];

	Utf16Char validChar = L"\xD808\xDC68";
	CPPUNIT_ASSERT(validChar.is_valid());

	stringStream << validChar;

	Utf16Char invalidChar = L"\xD803";
	CPPUNIT_ASSERT(!invalidChar.is_valid());

	stringStream << invalidChar;

	//Reset the stream position to the beginning
	stringStream.seekg(0, ios::beg);

	//Now read in a character from the stream.  Every time the >> operator is called, we should retrieve
	//one character

	//Read in the first one-code-unit character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0053', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a one-code-unit character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a one-code-unit character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a two-code-unit character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', deserializedChar[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', deserializedChar[1]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in an invalid character consisting of one invalid code unit
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD803', deserializedChar[0]);
	CPPUNIT_ASSERT(!deserializedChar.is_valid());

	//Run the tests again for the Utf16String wide stream operators
	wstringstream wideStringStream;

	//Write a series of characters to a stream
	wideStringStream << utf16String[0] << utf16String[1] << utf16String[2];

	validChar = L"\xD808\xDC68";
	CPPUNIT_ASSERT(validChar.is_valid());

	wideStringStream << validChar;

	invalidChar = L"\xD803";
	CPPUNIT_ASSERT(!invalidChar.is_valid());

	wideStringStream << invalidChar;

	//Reset the stream position to the beginning
	wideStringStream.seekg(0, ios::beg);

	//Now read in a character from the stream.  Every time the >> operator is called, we should retrieve
	//one character

	//Read in the first one-code-unit character
	wideStringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0053', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a one-code-unit character
	wideStringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a one-code-unit character
	wideStringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a two-code-unit character
	wideStringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', deserializedChar[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', deserializedChar[1]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in an invalid character consisting of one invalid code unit
	wideStringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD803', deserializedChar[0]);
	CPPUNIT_ASSERT(!deserializedChar.is_valid());
}

void Utf16CharTest::TestToUtf32()
{
	//Decode some one-code-unit characters
	Utf16Char character;

	character.clear();
	character[0] = L'\x1EAB';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	character.clear();
	character[0] = L'\x2211';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, character.to_utf_32());

	character.clear();
	character[0] = L'\x0062';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000062, character.to_utf_32());

	//Decode some two-code-unit characters
	character.clear();
	character[0] = L'\xD808';
	character[1] = L'\xDC68';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	character.clear();
	character[0] = L'\xD800';
	character[1] = L'\xDF46';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());
}

void Utf16CharTest::TestUtf8CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Assign a UTF-16 two-code-unit code point that will result in a UTF-8 four-code-unit code point
	Utf16Char utf16Char = utf16String[0];
	utf8String[5] = utf16Char;

	CPPUNIT_ASSERT(utf8String[5] == "\xF0\x92\x81\xA8");

	//Assign a UTF-16 one-code-unit code point that will result in a UTF-8 three-code-unit code point
	utf16Char = utf16String[2];
	utf8String[0] = utf16Char;

	CPPUNIT_ASSERT(utf8String[0] == "ẫ");

	//Assign a UTF-16 one-code-unit code point that will result in a UTF-8 two-code-unit code point
	utf16Char = utf16String[5];
	utf8String[0] = utf16Char;

	CPPUNIT_ASSERT(utf8String[0] == "ö");

	//Assign a UTF-16 one-code-unit code point that will result in a UTF-8 one-code-unit code point
	utf16Char = utf16String[4];
	utf8String[0] = utf16Char;

	CPPUNIT_ASSERT(utf8String[0] == "b");
}

/*Private Helper Functions*/

