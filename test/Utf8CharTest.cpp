/*!
\file Utf8CharTest.cpp

This file contains the definition of the Utf8CharTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <string>

#include "Utf8CharTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void Utf8CharTest::TestAssignmentOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";

	//Test the = operator that accepts a Utf8Char
	Utf8Char firstCharacter;
	firstCharacter[0] = "ẫ"[0];
	firstCharacter[1] = "ẫ"[1];
	firstCharacter[2] = "ẫ"[2];

	Utf8Char secondCharacter;
	secondCharacter[0] = "ß"[0];
	secondCharacter[1] = "ß"[1];

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == "ß");

	firstCharacter.clear();
	firstCharacter = '\x53';

	secondCharacter.clear();
	secondCharacter = 'S';

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == '\x53');

	firstCharacter.clear();
	firstCharacter = '2';

	secondCharacter.clear();
	secondCharacter = 'T';

	secondCharacter = firstCharacter;
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);
	CPPUNIT_ASSERT(firstCharacter == '2');

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = '\xEA';

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT_EQUAL('\xEA', firstCharacter[0]);

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = '\xF0';
	secondCharacter[1] = '\x90';
	secondCharacter[2] = '\x8D';
	secondCharacter[3] = '\x86';

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT_EQUAL('\xF0', firstCharacter[0]);  
	CPPUNIT_ASSERT_EQUAL('\x90', firstCharacter[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', firstCharacter[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', firstCharacter[3]);

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = "д"[0];
	secondCharacter[1] = "д"[1];

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(firstCharacter == firstCharacter);
	CPPUNIT_ASSERT_EQUAL("д"[0], firstCharacter[0]);
	CPPUNIT_ASSERT_EQUAL("д"[1], firstCharacter[1]);

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = 'W';

	secondCharacter = firstCharacter;
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);
	CPPUNIT_ASSERT_EQUAL('\xF0', secondCharacter[0]);  
	CPPUNIT_ASSERT_EQUAL('\x92', secondCharacter[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', secondCharacter[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', secondCharacter[3]);

	//Test the = operator that accepts a Utf8CharReference
	//Create a UTF-8 string containing simple ASCII characters
	utf8String = "Simple String";
	
	firstCharacter.clear();
	firstCharacter[0] = '\x1E';

	firstCharacter = utf8String[3];
	CPPUNIT_ASSERT(firstCharacter == utf8String[3]);
	CPPUNIT_ASSERT_EQUAL('p', firstCharacter[0]);

	firstCharacter.clear();

	firstCharacter = utf8String[6];
	CPPUNIT_ASSERT(firstCharacter == utf8String[6]);
	CPPUNIT_ASSERT_EQUAL(' ', firstCharacter[0]);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	firstCharacter.clear();
	firstCharacter[0] = "ъ"[0];
	firstCharacter[1] = "ъ"[1];

	firstCharacter = utf8String[0];
	CPPUNIT_ASSERT(firstCharacter == utf8String[0]);
	CPPUNIT_ASSERT(firstCharacter == "ω");

	firstCharacter.clear();
	firstCharacter[0] = 'B';

	firstCharacter = utf8String[4];
	CPPUNIT_ASSERT(firstCharacter == utf8String[4]);
	CPPUNIT_ASSERT(firstCharacter == "ъ");

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "Sẫböß3ẫ∑д";

	firstCharacter.clear();
	firstCharacter[0] = "∑"[0];
	firstCharacter[1] = "∑"[1];

	firstCharacter = utf8String[4];
	CPPUNIT_ASSERT(firstCharacter == utf8String[4]);
	CPPUNIT_ASSERT(firstCharacter == "ß");

	firstCharacter.clear();
	firstCharacter[0] = 'B';

	firstCharacter = utf8String[1];
	CPPUNIT_ASSERT(firstCharacter == utf8String[1]);
	CPPUNIT_ASSERT(firstCharacter == "ẫ");

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	firstCharacter = utf8String[0];
	CPPUNIT_ASSERT(firstCharacter == utf8String[0]);
	CPPUNIT_ASSERT(firstCharacter == "S");

	firstCharacter.clear();
	firstCharacter[0] = 'B';

	firstCharacter = utf8String[9];
	CPPUNIT_ASSERT(firstCharacter == utf8String[9]);
	CPPUNIT_ASSERT(firstCharacter == "\xF0\x90\x8D\x86");
}

void Utf8CharTest::TestClear()
{
	Utf8Char character;
	character = "ß";

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character = "\xF0\x90\x8D\x86";

	CPPUNIT_ASSERT_EQUAL((size_t)4, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character = "S";

	CPPUNIT_ASSERT_EQUAL((size_t)1, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());
}

void Utf8CharTest::TestConstructors()
{
	//Create a UTF-8 string containing simple ASCII characters
	Utf8String utf8String = "Simple String";

	//Create a Utf8Char using the default constructor
	Utf8Char* constructedCharacter = new Utf8Char();

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)0, constructedCharacter->size());

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	string codeUnitString = utf8String;
	string::iterator basicStringIterator = codeUnitString.begin() + 1;
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('i', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.end() - 1;
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('g', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	string::const_iterator basicStringConstIterator = codeUnitString.begin() + 2;
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('m', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringConstIterator = codeUnitString.end() - 2;
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('n', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a char
	constructedCharacter = new Utf8Char('X');

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('X', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a char*
	//Create a character with one code unit
	constructedCharacter = new Utf8Char("A");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('A', (*constructedCharacter)[0]);

	delete constructedCharacter;
	constructedCharacter = NULL;


	//Now repeat the tests using two-code-unit characters
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	//Create a Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin();
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xCF\x89");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 5;
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xD1\x8A");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringConstIterator = codeUnitString.begin();
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xCF\x89");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringConstIterator = codeUnitString.begin() + 5;
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xD1\x8A");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a char*
	//Create a character with two code units
	constructedCharacter = new Utf8Char("\xD1\x8A");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('\xD1', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*constructedCharacter)[1]);

	delete constructedCharacter;
	constructedCharacter = NULL;


	//Now repeat the tests using three-code-unit characters
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	//Create a Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 1;
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)3, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xE1\xBA\xAB");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 13;
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)3, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xE2\x88\x91");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringConstIterator = codeUnitString.begin() + 1;
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)3, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xE1\xBA\xAB");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringConstIterator = codeUnitString.begin() + 13;
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)3, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xE2\x88\x91");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a char*
	//Create a character with three code units
	constructedCharacter = new Utf8Char("\xE2\x88\x91");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)3, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('\xE2', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*constructedCharacter)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*constructedCharacter)[2]);

	delete constructedCharacter;
	constructedCharacter = NULL;


	//Now repeat the tests using four-code-unit characters
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Create a Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 5;
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)4, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xF0\x92\x81\xA8");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 20;
	constructedCharacter = new Utf8Char(basicStringIterator, Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)4, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xF0\x90\x8D\x86");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringConstIterator = codeUnitString.begin() + 5;
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)4, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xF0\x92\x81\xA8");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create another Utf8Char using the constructor that accepts a std::string::const_iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringConstIterator = codeUnitString.begin() + 20;
	constructedCharacter = new Utf8Char(basicStringConstIterator, Utf8String::CharacterCodeUnitCount(basicStringConstIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)4, constructedCharacter->size());
	CPPUNIT_ASSERT((*constructedCharacter) == "\xF0\x90\x8D\x86");

	delete constructedCharacter;
	constructedCharacter = NULL;

	//Create a Utf8Char using the constructor that accepts a char*
	//Create a character with three code units
	constructedCharacter = new Utf8Char("\xF0\x90\x8D\x86");

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)4, constructedCharacter->size());
	CPPUNIT_ASSERT_EQUAL('\xF0', (*constructedCharacter)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', (*constructedCharacter)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', (*constructedCharacter)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', (*constructedCharacter)[3]);

	delete constructedCharacter;
	constructedCharacter = NULL;
}

void Utf8CharTest::TestEqualsOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";

	//Test the = operator that accepts a Utf8Char
	Utf8Char firstCharacter;
	firstCharacter[0] = "ẫ"[0];
	firstCharacter[1] = "ẫ"[1];
	firstCharacter[2] = "ẫ"[2];

	Utf8Char secondCharacter;
	secondCharacter[0] = "ß"[0];
	secondCharacter[1] = "ß"[1];

	CPPUNIT_ASSERT(!(secondCharacter == firstCharacter));

	firstCharacter.clear();
	firstCharacter[0] = "ẫ"[0];
	firstCharacter[1] = "ẫ"[1];
	firstCharacter[2] = "ẫ"[2];

	secondCharacter.clear();
	secondCharacter[0] = "ẫ"[0];
	secondCharacter[1] = "ẫ"[1];
	secondCharacter[2] = "ẫ"[2];

	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	firstCharacter.clear();
	firstCharacter = '\x53';

	secondCharacter.clear();
	secondCharacter = 'S';

	CPPUNIT_ASSERT(secondCharacter == firstCharacter);

	firstCharacter.clear();
	firstCharacter = '2';

	secondCharacter.clear();
	secondCharacter = 'T';

	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = '\xEA';

	CPPUNIT_ASSERT(!(secondCharacter == firstCharacter));

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = '\xF0';
	secondCharacter[1] = '\x92';
	secondCharacter[2] = '\x81';
	secondCharacter[3] = '\xA8';

	CPPUNIT_ASSERT(secondCharacter == firstCharacter);

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = "д"[0];
	secondCharacter[1] = "д"[1];

	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter.clear();
	firstCharacter[0] = "д"[0];
	firstCharacter[1] = "д"[1];

	secondCharacter.clear();
	secondCharacter[0] = "д"[0];
	secondCharacter[1] = "д"[1];

	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = 'W';

	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	//Test the == operator that accepts a Utf8CharReference
	//Create a UTF-8 string containing simple ASCII characters
	utf8String = "Simple String";
	
	firstCharacter.clear();
	firstCharacter[0] = 'l';

	CPPUNIT_ASSERT(firstCharacter == utf8String[4]);
	CPPUNIT_ASSERT(!(firstCharacter == utf8String[8]));

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	firstCharacter.clear();
	firstCharacter[0] = "ъ"[0];
	firstCharacter[1] = "ъ"[1];

	CPPUNIT_ASSERT(firstCharacter == utf8String[4]);
	CPPUNIT_ASSERT(!(firstCharacter == utf8String[0]));

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "Sẫböß3ẫ∑д";

	firstCharacter.clear();
	firstCharacter[0] = "∑"[0];
	firstCharacter[1] = "∑"[1];
	firstCharacter[2] = "∑"[2];

	CPPUNIT_ASSERT(firstCharacter == utf8String[7]);
	CPPUNIT_ASSERT(!(firstCharacter == utf8String[1]));

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	CPPUNIT_ASSERT(firstCharacter == utf8String[3]);
	CPPUNIT_ASSERT(!(firstCharacter == utf8String[8]));
}

void Utf8CharTest::TestIndexingOperator()
{
	Utf8Char character;
	character[0] = 'A';

	CPPUNIT_ASSERT_EQUAL('A', character[0]);
	
	character.clear();

	character[0] = "ъ"[0];
	character[1] = "ъ"[1];

	CPPUNIT_ASSERT_EQUAL("ъ"[0], character[0]);
	CPPUNIT_ASSERT_EQUAL("ъ"[1], character[1]);
	
	character.clear();

	character[0] = "∑"[0];
	character[1] = "∑"[1];
	character[2] = "∑"[2];

	CPPUNIT_ASSERT_EQUAL("∑"[0], character[0]);
	CPPUNIT_ASSERT_EQUAL("∑"[1], character[1]);
	CPPUNIT_ASSERT_EQUAL("∑"[2], character[2]);

	character.clear();

	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT_EQUAL('\xF0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', character[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', character[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', character[3]);
}

void Utf8CharTest::TestIsValid()
{
	Utf8Char character;

	//Validate an empty character
	CPPUNIT_ASSERT(!character.is_valid());

	//Validate valid one-code-unit characters
	character[0] = L'!';

	CPPUNIT_ASSERT(character.is_valid());

	character[0] = L'f';

	CPPUNIT_ASSERT(character.is_valid());

	//Validate invalid one-code-unit characters
	//Test a character whose most significant bit is 1
	character[0] = L'\xA8';

	CPPUNIT_ASSERT(!character.is_valid());


	//Test some valid two-code-unit characters
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(character.is_valid());

	character[0] = L'\xD8';
	character[1] = L'\x8F';

	CPPUNIT_ASSERT(character.is_valid());

	//For a two-code-unit UTF-8 character to be valid, the first code unit must start with 110, 
	//the second code unit must start with 10, and the encoded code point must be in the 
	//range 000080-0007FF

	//Test some invalid two-code-unit characters
	//Test a character with a first code unit that doesn't start with 110
	character[0] = '\xFA';
	character[1] = '\x86';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a second code unit that doesn't start with 10
	character[0] = '\xCF';
	character[1] = '\x44';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a first code unit that doesn't start with 110, and a second code 
	//unit that doesn't start with 10
	character[0] = '\xFA';
	character[1] = '\x44';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character that is outside the range 000080-0007FF
	character[0] = '\xC0';
	character[1] = '\x80';

	CPPUNIT_ASSERT(!character.is_valid());


	//Test some valid three-code-unit characters
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT(character.is_valid());

	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';

	CPPUNIT_ASSERT(character.is_valid());

	//For a three-code-unit UTF-8 character to be valid, the first code unit must start with 1110, 
	//the second and third code units must start with 10, and the encoded code point must be in the 
	//range 000800-00FFFF

	//Test some invalid three-code-unit characters
	//Test a character with a first code unit that doesn't start with 1110
	character[0] = '\xFA';
	character[1] = '\x86';
	character[2] = '\x92';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a second code unit that doesn't start with 10
	character[0] = '\xEF';
	character[1] = '\x44';
	character[2] = '\x88';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a third code unit that doesn't start with 10
	character[0] = '\xEF';
	character[1] = '\x92';
	character[2] = '\x21';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a first code unit that doesn't start with 1110, a second code 
	//unit that doesn't start with 10, and a third code unit that doesn't start with 10
	character[0] = '\xF3';
	character[1] = '\x40';
	character[2] = '\x03';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character that is outside the range 000800-00FFFF
	character[0] = '\xE0';
	character[1] = '\x81';
	character[2] = '\x8A';

	CPPUNIT_ASSERT(!character.is_valid());


	//Test some valid four-code-unit characters
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(character.is_valid());

	character[0] = '\xF2';
	character[1] = '\x90';
	character[2] = '\x8D';
	character[3] = '\x86';

	CPPUNIT_ASSERT(character.is_valid());

	//For a four-code-unit UTF-8 character to be valid, the first code unit must start with 11110, 
	//the second, third, and fourth code units  must start with 10, and the encoded code point must 
	//be in the range 010000-10FFFF

	//Test some invalid three-code-unit characters
	//Test a character with a first code unit that doesn't start with 11110
	character[0] = '\xFC';
	character[1] = '\x86';
	character[2] = '\x92';
	character[3] = '\xA4';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a second code unit that doesn't start with 10
	character[0] = '\xFC';
	character[1] = '\x44';
	character[2] = '\x88';
	character[3] = '\x89';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a third code unit that doesn't start with 10
	character[0] = '\xFC';
	character[1] = '\x92';
	character[2] = '\x21';
	character[3] = '\xA5';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a fourth code unit that doesn't start with 10
	character[0] = '\xFC';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\x05';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a first code unit that doesn't start with 1110, a second code 
	//unit that doesn't start with 10, a third code unit that doesn't start with 10,
	//and a fourth code unit that doesn't start with 10
	character[0] = '\xFC';
	character[1] = '\x40';
	character[2] = '\x03';
	character[3] = '\x3A';

	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character that is outside the range 010000-10FFFF
	character[0] = '\xFC';
	character[1] = '\x80';
	character[2] = '\x81';
	character[3] = '\x80';

	CPPUNIT_ASSERT(!character.is_valid());
}

void Utf8CharTest::TestNotEqualsOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";

	//Test the = operator that accepts a Utf8Char
	Utf8Char firstCharacter;
	firstCharacter[0] = "ẫ"[0];
	firstCharacter[1] = "ẫ"[1];
	firstCharacter[2] = "ẫ"[2];

	Utf8Char secondCharacter;
	secondCharacter[0] = "ß"[0];
	secondCharacter[1] = "ß"[1];

	CPPUNIT_ASSERT(secondCharacter != firstCharacter);

	firstCharacter.clear();
	firstCharacter[0] = "ẫ"[0];
	firstCharacter[1] = "ẫ"[1];
	firstCharacter[2] = "ẫ"[2];

	secondCharacter.clear();
	secondCharacter[0] = "ẫ"[0];
	secondCharacter[1] = "ẫ"[1];
	secondCharacter[2] = "ẫ"[2];

	CPPUNIT_ASSERT(!(firstCharacter != secondCharacter));

	firstCharacter.clear();
	firstCharacter = '\x53';

	secondCharacter.clear();
	secondCharacter = 'S';

	CPPUNIT_ASSERT(!(secondCharacter != firstCharacter));

	firstCharacter.clear();
	firstCharacter = '2';

	secondCharacter.clear();
	secondCharacter = 'T';

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = '\xEA';

	CPPUNIT_ASSERT(secondCharacter != firstCharacter);

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = '\xF0';
	secondCharacter[1] = '\x92';
	secondCharacter[2] = '\x81';
	secondCharacter[3] = '\xA8';

	CPPUNIT_ASSERT(!(secondCharacter != firstCharacter));

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = "д"[0];
	secondCharacter[1] = "д"[1];

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter.clear();
	firstCharacter[0] = "д"[0];
	firstCharacter[1] = "д"[1];

	secondCharacter.clear();
	secondCharacter[0] = "д"[0];
	secondCharacter[1] = "д"[1];

	CPPUNIT_ASSERT(!(firstCharacter != secondCharacter));

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	secondCharacter.clear();
	secondCharacter[0] = 'W';

	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	//Test the == operator that accepts a Utf8CharReference
	//Create a UTF-8 string containing simple ASCII characters
	utf8String = "Simple String";
	
	firstCharacter.clear();
	firstCharacter[0] = 'l';

	CPPUNIT_ASSERT(!(firstCharacter != utf8String[4]));
	CPPUNIT_ASSERT(firstCharacter != utf8String[8]);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	firstCharacter.clear();
	firstCharacter[0] = "ъ"[0];
	firstCharacter[1] = "ъ"[1];

	CPPUNIT_ASSERT(!(firstCharacter != utf8String[4]));
	CPPUNIT_ASSERT(firstCharacter != utf8String[0]);

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "Sẫböß3ẫ∑д";

	firstCharacter.clear();
	firstCharacter[0] = "∑"[0];
	firstCharacter[1] = "∑"[1];
	firstCharacter[2] = "∑"[2];

	CPPUNIT_ASSERT(!(firstCharacter != utf8String[7]));
	CPPUNIT_ASSERT(firstCharacter != utf8String[1]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";

	firstCharacter.clear();
	firstCharacter[0] = '\xF0';
	firstCharacter[1] = '\x92';
	firstCharacter[2] = '\x81';
	firstCharacter[3] = '\xA8';

	CPPUNIT_ASSERT(!(firstCharacter != utf8String[3]));
	CPPUNIT_ASSERT(firstCharacter != utf8String[8]);
}

void Utf8CharTest::TestSize()
{
	Utf8Char character;
	character[0] = L'!';

	CPPUNIT_ASSERT_EQUAL((size_t)1, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';

	CPPUNIT_ASSERT_EQUAL((size_t)3, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());

	character[0] = '\xF2';
	character[1] = '\x90';
	character[2] = '\x8D';
	character[3] = '\x86';

	CPPUNIT_ASSERT_EQUAL((size_t)4, character.size());
	
	character.clear();

	CPPUNIT_ASSERT_EQUAL((size_t)0, character.size());
}

void Utf8CharTest::TestStreamOperators()
{
	stringstream stringStream;

	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB \x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB \t\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8Char deserializedChar;

	//Write a series of characters to a stream
	stringStream << utf8String[0] << utf8String[1] << utf8String[2] << utf8String[4] << '\xE2';

	//Reset the stream position to the beginning
	stringStream.seekg(0, ios::beg);

	//Now read in a character from the stream.  Every time the >> operator is called, we should retrieve
	//one character

	//Read in the first one-code-unit character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL('\x53', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a three-code-unit character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)3, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL('\xE1', deserializedChar[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', deserializedChar[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', deserializedChar[2]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a space character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL('\x20', deserializedChar[0]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in a four-code-unit character
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL('\xF0', deserializedChar[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', deserializedChar[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', deserializedChar[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', deserializedChar[3]);
	CPPUNIT_ASSERT(deserializedChar.is_valid());

	//Read in an invalid character consisting of one invalid code unit
	stringStream >> deserializedChar;

	CPPUNIT_ASSERT_EQUAL((size_t)1, deserializedChar.size());
	CPPUNIT_ASSERT_EQUAL('\xE2', deserializedChar[0]);
	CPPUNIT_ASSERT(!deserializedChar.is_valid());

}

void Utf8CharTest::TestToUtf32()
{
	Utf8Char character;

	//Decode some one-code-unit characters
	character.clear();
	character[0] = '\x53';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, character.to_utf_32());

	character.clear();
	character[0] = '\x20';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000020, character.to_utf_32());

	//Decode some two-code-unit characters
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000F6, character.to_utf_32());

	character.clear();
	character[0] = '\xC3';
	character[1] = '\x9F';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, character.to_utf_32());

	//Decode some three-code-unit characters
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	character.clear();
	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, character.to_utf_32());

	//Decode some four-code-unit characters
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	character.clear();
	character[0] = '\xF0';
	character[1] = '\x90';
	character[2] = '\x8D';
	character[3] = '\x86';

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());
}


void Utf8CharTest::TestUtf16CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Assign a UTF-8 four-code-unit code point that will result in a UTF-16 two-code-unit code point
	Utf8Char utf8Char = utf8String[0];
	utf16String[5] = utf8Char;

	CPPUNIT_ASSERT(utf16String[5] == L"\xD808\xDC68");

	//Assign a UTF-8 three-code-unit code point that will result in a UTF-16 one-code-unit code point
	utf8Char = utf8String[2];
	utf16String[0] = utf8Char;

	CPPUNIT_ASSERT(utf16String[0] == L"\x1EAB");

	//Assign a UTF-8 two-code-unit code point that will result in a UTF-16 one-code-unit code point
	utf8Char = utf8String[5];
	utf16String[0] = utf8Char;

	CPPUNIT_ASSERT(utf16String[0] == L"\x00F6");

	//Assign a UTF-8 one-code-unit code point that will result in a UTF-16 one-code-unit code point
	utf8Char = utf8String[4];
	utf16String[0] = utf8Char;

	CPPUNIT_ASSERT(utf16String[0] == L"\x0062");
}

/*Private Helper Functions*/

