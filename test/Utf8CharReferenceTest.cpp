/*!
\file Utf8CharReferenceTest.cpp

This file contains the definition of the Utf8CharReferenceTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <string>

#include "Utf8CharReferenceTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void Utf8CharReferenceTest::TestAssignmentOperator()
{
	Utf8Char character;
	Utf8String utf8String;

	//Create a UTF-8 string composed of only single-code-unit characters
	utf8String = "Simple String";

	//Test the = operator that accepts a Utf8Char
	//Assign a single-code-unit character to a single-code-unit character reference
	character[0] = 'X';

	utf8String[1] = character;
	CPPUNIT_ASSERT(utf8String[1] == character);
	CPPUNIT_ASSERT_EQUAL('X', utf8String[1][0]);

	//Assign a two-code-unit character to a single-code-unit character reference
	character.clear();
	character[0] = '\xCF';
	character[1] = '\x89';

	utf8String[1] = character;
	CPPUNIT_ASSERT(utf8String[1] == character);
	CPPUNIT_ASSERT_EQUAL('\xCF', utf8String[1][0]);
	CPPUNIT_ASSERT_EQUAL('\x89', utf8String[1][1]);

	//Assign a three-code-unit character to a single-code-unit character reference
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	utf8String[2] = character;
	CPPUNIT_ASSERT(utf8String[2] == character);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[2][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[2][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[2][2]);

	//Assign a four-code-unit character to a single-code-unit character reference
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	utf8String[4] = character;
	CPPUNIT_ASSERT(utf8String[4] == character);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8String[4][1]);
	CPPUNIT_ASSERT_EQUAL('\x81', utf8String[4][2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', utf8String[4][3]);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	//Test the = operator that accepts a Utf8Char
	//Assign a single-code-unit character to a two-code-unit character reference
	character.clear();
	character[0] = 'X';

	utf8String[0] = character;
	CPPUNIT_ASSERT(utf8String[0] == character);
	CPPUNIT_ASSERT_EQUAL('X', utf8String[0][0]);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	//Assign a two-code-unit character to a two-code-unit character reference
	character.clear();
	character[0] = '\xCF';
	character[1] = '\x89';

	utf8String[4] = character;
	CPPUNIT_ASSERT(utf8String[4] == character);
	CPPUNIT_ASSERT_EQUAL('\xCF', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\x89', utf8String[4][1]);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	//Assign a three-code-unit character to a two-code-unit character reference
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	utf8String[0] = character;
	CPPUNIT_ASSERT(utf8String[0] == character);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[0][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[0][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[0][2]);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A";

	//Assign a four-code-unit character to a two-code-unit character reference
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	utf8String[4] = character;
	CPPUNIT_ASSERT(utf8String[4] == character);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8String[4][1]);
	CPPUNIT_ASSERT_EQUAL('\x81', utf8String[4][2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', utf8String[4][3]);


	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	//Test the = operator that accepts a Utf8Char
	//Assign a single-code-unit character to a three-code-unit character reference
	character.clear();
	character[0] = 'X';

	utf8String[1] = character;
	CPPUNIT_ASSERT(utf8String[1] == character);
	CPPUNIT_ASSERT_EQUAL('X', utf8String[1][0]);

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	//Assign a two-code-unit character to a three-code-unit character reference
	character.clear();
	character[0] = '\xCF';
	character[1] = '\x89';

	utf8String[6] = character;
	CPPUNIT_ASSERT(utf8String[6] == character);
	CPPUNIT_ASSERT_EQUAL('\xCF', utf8String[6][0]);
	CPPUNIT_ASSERT_EQUAL('\x89', utf8String[6][1]);

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	//Assign a three-code-unit character to a three-code-unit character reference
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	utf8String[7] = character;
	CPPUNIT_ASSERT(utf8String[7] == character);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[7][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[7][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[7][2]);

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	//Assign a four-code-unit character to a three-code-unit character reference
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	utf8String[6] = character;
	CPPUNIT_ASSERT(utf8String[6] == character);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[6][0]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8String[6][1]);
	CPPUNIT_ASSERT_EQUAL('\x81', utf8String[6][2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', utf8String[6][3]);


	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Test the = operator that accepts a Utf8Char
	//Assign a single-code-unit character to a four-code-unit character reference
	character.clear();
	character[0] = 'X';

	utf8String[3] = character;
	CPPUNIT_ASSERT(utf8String[3] == character);
	CPPUNIT_ASSERT_EQUAL('X', utf8String[3][0]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a two-code-unit character to a four-code-unit character reference
	character.clear();
	character[0] = '\xCF';
	character[1] = '\x89';

	utf8String[9] = character;
	CPPUNIT_ASSERT(utf8String[9] == character);
	CPPUNIT_ASSERT_EQUAL('\xCF', utf8String[9][0]);
	CPPUNIT_ASSERT_EQUAL('\x89', utf8String[9][1]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a three-code-unit character to a four-code-unit character reference
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	utf8String[3] = character;
	CPPUNIT_ASSERT(utf8String[3] == character);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[3][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[3][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[3][2]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a four-code-unit character to a four-code-unit character reference
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	utf8String[9] = character;
	CPPUNIT_ASSERT(utf8String[9] == character);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[9][0]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8String[9][1]);
	CPPUNIT_ASSERT_EQUAL('\x81', utf8String[9][2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', utf8String[9][3]);


	//Test the = operator that accepts a Utf8CharReference
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a one-code-unit character reference to a one-code-unit character reference
	utf8String[0] = utf8String[2];
	CPPUNIT_ASSERT(utf8String[0] == utf8String[2]);
	CPPUNIT_ASSERT_EQUAL('\x62', utf8String[0][0]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a two-code-unit character reference to a one-code-unit character reference
	utf8String[0] = utf8String[5];
	CPPUNIT_ASSERT(utf8String[0] == utf8String[5]);
	CPPUNIT_ASSERT_EQUAL('\xC3', utf8String[0][0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', utf8String[0][1]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a three-code-unit character reference to a one-code-unit character reference
	utf8String[0] = utf8String[1];
	CPPUNIT_ASSERT(utf8String[0] == utf8String[1]);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[0][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[0][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[0][2]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a four-code-unit character reference to a one-code-unit character reference
	utf8String[0] = utf8String[9];
	CPPUNIT_ASSERT(utf8String[0] == utf8String[9]);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[0][0]);
	CPPUNIT_ASSERT_EQUAL('\x90', utf8String[0][1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', utf8String[0][2]);
	CPPUNIT_ASSERT_EQUAL('\x86', utf8String[0][3]);


	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a one-code-unit character reference to a two-code-unit character reference
	utf8String[4] = utf8String[2];
	CPPUNIT_ASSERT(utf8String[4] == utf8String[2]);
	CPPUNIT_ASSERT_EQUAL('\x62', utf8String[4][0]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a two-code-unit character reference to a two-code-unit character reference
	utf8String[4] = utf8String[5];
	CPPUNIT_ASSERT(utf8String[4] == utf8String[5]);
	CPPUNIT_ASSERT_EQUAL('\xC3', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', utf8String[4][1]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a three-code-unit character reference to a two-code-unit character reference
	utf8String[4] = utf8String[1];
	CPPUNIT_ASSERT(utf8String[4] == utf8String[1]);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[4][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[4][2]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a four-code-unit character reference to a two-code-unit character reference
	utf8String[4] = utf8String[9];
	CPPUNIT_ASSERT(utf8String[4] == utf8String[9]);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\x90', utf8String[4][1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', utf8String[4][2]);
	CPPUNIT_ASSERT_EQUAL('\x86', utf8String[4][3]);


	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a one-code-unit character reference to a three-code-unit character reference
	utf8String[1] = utf8String[2];
	CPPUNIT_ASSERT(utf8String[1] == utf8String[2]);
	CPPUNIT_ASSERT_EQUAL('\x62', utf8String[1][0]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a two-code-unit character reference to a three-code-unit character reference
	utf8String[1] = utf8String[5];
	CPPUNIT_ASSERT(utf8String[1] == utf8String[5]);
	CPPUNIT_ASSERT_EQUAL('\xC3', utf8String[1][0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', utf8String[1][1]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a three-code-unit character reference to a three-code-unit character reference
	utf8String[1] = utf8String[7];
	CPPUNIT_ASSERT(utf8String[1] == utf8String[7]);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[1][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[1][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[1][2]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a four-code-unit character reference to a three-code-unit character reference
	utf8String[1] = utf8String[9];
	CPPUNIT_ASSERT(utf8String[1] == utf8String[9]);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[1][0]);
	CPPUNIT_ASSERT_EQUAL('\x90', utf8String[1][1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', utf8String[1][2]);
	CPPUNIT_ASSERT_EQUAL('\x86', utf8String[1][3]);


	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a one-code-unit character reference to a four-code-unit character reference
	utf8String[3] = utf8String[2];
	CPPUNIT_ASSERT(utf8String[3] == utf8String[2]);
	CPPUNIT_ASSERT_EQUAL('\x62', utf8String[3][0]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a two-code-unit character reference to a four-code-unit character reference
	utf8String[3] = utf8String[5];
	CPPUNIT_ASSERT(utf8String[3] == utf8String[5]);
	CPPUNIT_ASSERT_EQUAL('\xC3', utf8String[3][0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', utf8String[3][1]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a three-code-unit character reference to a four-code-unit character reference
	utf8String[3] = utf8String[7];
	CPPUNIT_ASSERT(utf8String[3] == utf8String[7]);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[3][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[3][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[3][2]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Assign a four-code-unit character reference to a four-code-unit character reference
	utf8String[3] = utf8String[9];
	CPPUNIT_ASSERT(utf8String[3] == utf8String[9]);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[3][0]);
	CPPUNIT_ASSERT_EQUAL('\x90', utf8String[3][1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', utf8String[3][2]);
	CPPUNIT_ASSERT_EQUAL('\x86', utf8String[3][3]);
}

void Utf8CharReferenceTest::TestAssignReference()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8CharReference characterReference = utf8String[0];

	characterReference.assign_reference(utf8String[4]);
	CPPUNIT_ASSERT(characterReference == utf8String[4]);
	
	characterReference.assign_reference(utf8String[9]);
	CPPUNIT_ASSERT(characterReference == utf8String[9]);

	characterReference.assign_reference(utf8String[5]);
	CPPUNIT_ASSERT(characterReference == utf8String[5]);

	characterReference.assign_reference(utf8String[1]);
	CPPUNIT_ASSERT(characterReference == utf8String[1]);
}

void Utf8CharReferenceTest::TestConstructors()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Test using one-code-unit characters
	//Create a Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	string codeUnitString = utf8String;
	string::iterator basicStringIterator = codeUnitString.begin();
	Utf8CharReference* constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\x53', (*constructedCharacterReference)[0]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Create another Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.end() - 13;
	constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\x33', (*constructedCharacterReference)[0]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Now repeat the tests using two-code-unit characters

	//Create a Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 9;
	constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\xC3', (*constructedCharacterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*constructedCharacterReference)[1]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Create another Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 11;
	constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\xC3', (*constructedCharacterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*constructedCharacterReference)[1]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;


	//Now repeat the tests using three-code-unit characters

	//Create a Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 1;
	constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)3, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\xE1', (*constructedCharacterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*constructedCharacterReference)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*constructedCharacterReference)[2]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Create another Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.end() - 9;
	constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)3, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\xE2', (*constructedCharacterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*constructedCharacterReference)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*constructedCharacterReference)[2]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;


	//Now repeat the tests using four-code-unit characters

	//Create a Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.begin() + 5;
	constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)4, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\xF0', (*constructedCharacterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*constructedCharacterReference)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*constructedCharacterReference)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*constructedCharacterReference)[3]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Create another Utf8CharReference using the constructor that accepts a std::string::iterator
	//and a size_t
	codeUnitString = utf8String;
	basicStringIterator = codeUnitString.end() - 6;
	constructedCharacterReference = new Utf8CharReference(codeUnitString, basicStringIterator, 
		Utf8String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)4, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL('\xF0', (*constructedCharacterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', (*constructedCharacterReference)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', (*constructedCharacterReference)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', (*constructedCharacterReference)[3]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;
}

void Utf8CharReferenceTest::TestEqualsOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8CharReference characterReference = utf8String[0];

	//Test the == operator that accepts a Utf8Char
	//Compare a single-code-unit character reference to single-code-unit character
	Utf8Char character;
	character[0] = '\x53';

	CPPUNIT_ASSERT(characterReference == character);

	character.clear();
	character[0] = '\x13';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a single-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a single-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a single-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(!(characterReference == character));



	//Compare a two-code-unit character reference to single-code-unit character
	characterReference.assign_reference(utf8String[5]);

	character.clear();
	character[0] = '\x53';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a two-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\x9F';

	CPPUNIT_ASSERT(characterReference == character);

	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a two-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a two-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(!(characterReference == character));


	//Compare a three-code-unit character reference to single-code-unit character
	characterReference.assign_reference(utf8String[1]);

	character.clear();
	character[0] = '\x53';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a three-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a three-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT(characterReference == character);

	character.clear();
	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a three-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(!(characterReference == character));


	//Compare a four-code-unit character reference to single-code-unit character
	characterReference.assign_reference(utf8String[3]);

	character.clear();
	character[0] = '\x53';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a four-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a four-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a four-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(characterReference == character);

	character.clear();
	character[0] = '\xF0';
	character[1] = '\x90';
	character[2] = '\x8D';
	character[3] = '\x86';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xF0\x92\x81\xA8\x53\xE1\xBA\xAB\xC3\x9F\xE2\x88\x91\xF0\x90\x8D\x86\xE1\xBA\xAB\x62\xD0\xB4";

	//Now test the == operator that accepts a Utf8CharReference
	//Compare a single-code-unit character reference to single-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	Utf8CharReference otherCharacterReference = utf8String[0];
	characterReference.assign_reference(utf8String[0]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[8]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a single-code-unit character reference to a two-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a single-code-unit character reference to a three-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a single-code-unit character reference to a four-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a two-code-unit character reference to two-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	otherCharacterReference.assign_reference(utf8String[5]);
	characterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[10]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[4]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a two-code-unit character reference to a three-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a two-code-unit character reference to a four-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a three-code-unit character reference to three-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	otherCharacterReference.assign_reference(utf8String[1]);
	characterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[9]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[11]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a three-code-unit character reference to a four-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a four-code-unit character reference to four-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	otherCharacterReference.assign_reference(utf8String[3]);
	characterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[7]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[12]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));
}

void Utf8CharReferenceTest::TestIndexingOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Get a reference to a character with one code unit
	Utf8CharReference characterReference = utf8String[0];

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL('\x53', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\x53', utf8String[0][0]);

	//Assign a single-code-unit character using the indexer
	characterReference[0] = '\x45';

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL('\x45', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\x45', utf8String[0][0]);
	
	//Get a reference to a character with two code units
	characterReference.assign_reference(utf8String[4]);

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL('\xC3', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL('\xC3', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', utf8String[4][1]);

	//Assign a two-code-unit character using the indexer
	characterReference[0] = '\xC4';
	characterReference[1] = '\x85';

	CPPUNIT_ASSERT_EQUAL('\xC4', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\x85', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL('\xC4', utf8String[4][0]);
	CPPUNIT_ASSERT_EQUAL('\x85', utf8String[4][1]);

	//Get a reference to a character with three code units
	characterReference.assign_reference(utf8String[1]);

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL('\xE1', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', characterReference[2]);
	CPPUNIT_ASSERT_EQUAL('\xE1', utf8String[1][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8String[1][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8String[1][2]);

	//Assign a three-code-unit character using the indexer
	characterReference[0] = '\xE2';
	characterReference[1] = '\x85';
	characterReference[2] = '\x92';

	CPPUNIT_ASSERT_EQUAL('\xE2', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\x85', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL('\x92', characterReference[2]);
	CPPUNIT_ASSERT_EQUAL('\xE2', utf8String[1][0]);
	CPPUNIT_ASSERT_EQUAL('\x85', utf8String[1][1]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8String[1][2]);

	//Get a reference to a character with four code units
	characterReference.assign_reference(utf8String[3]);

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL('\xF0', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', characterReference[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', characterReference[3]);
	CPPUNIT_ASSERT_EQUAL('\xF0', utf8String[3][0]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8String[3][1]);
	CPPUNIT_ASSERT_EQUAL('\x81', utf8String[3][2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', utf8String[3][3]);

	//Assign a four-code-unit character using the indexer
	characterReference[0] = '\xF1';
	characterReference[1] = '\xA5';
	characterReference[2] = '\x83';
	characterReference[3] = '\x8A';

	CPPUNIT_ASSERT_EQUAL('\xF1', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL('\xA5', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL('\x83', characterReference[2]);
	CPPUNIT_ASSERT_EQUAL('\x8A', characterReference[3]);
	CPPUNIT_ASSERT_EQUAL('\xF1', utf8String[3][0]);
	CPPUNIT_ASSERT_EQUAL('\xA5', utf8String[3][1]);
	CPPUNIT_ASSERT_EQUAL('\x83', utf8String[3][2]);
	CPPUNIT_ASSERT_EQUAL('\x8A', utf8String[3][3]);
}

void Utf8CharReferenceTest::TestIsValid()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8CharReference characterReference = utf8String[0];

	//Validate valid one-code-unit characters
	CPPUNIT_ASSERT(utf8String[0].is_valid());

	CPPUNIT_ASSERT(utf8String[6].is_valid());

	//Validate invalid one-code-unit characters
	//Test a character whose most significant bit is 1
	characterReference.assign_reference(utf8String[0]);
	characterReference[0] = '\xA8';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	characterReference[0] = '\x53';

	//Test some valid two-code-unit characters
	CPPUNIT_ASSERT(utf8String[4].is_valid());

	CPPUNIT_ASSERT(utf8String[5].is_valid());

	//For a two-code-unit UTF-8 character to be valid, the first code unit must start with 110, 
	//the second code unit must start with 10, and the encoded code point must be in the 
	//range 000080-0007FF

	//Test some invalid two-code-unit characters
	characterReference.assign_reference(utf8String[4]);

	//Test a character with a first code unit that doesn't start with 110
	characterReference[0] = '\xFA';
	characterReference[1] = '\x86';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a second code unit that doesn't start with 10
	characterReference[0] = '\xCF';
	characterReference[1] = '\x44';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a first code unit that doesn't start with 110, and a second code 
	//unit that doesn't start with 10
	characterReference[0] = '\xFA';
	characterReference[1] = '\x44';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character that is outside the range 000080-0007FF
	characterReference[0] = '\xC0';
	characterReference[1] = '\x80';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	characterReference[0] = '\xC3';
	characterReference[1] = '\x9F';


	//Test some valid three-code-unit characters
	CPPUNIT_ASSERT(utf8String[1].is_valid());

	CPPUNIT_ASSERT(utf8String[8].is_valid());

	//For a three-code-unit UTF-8 character to be valid, the first code unit must start with 1110, 
	//the second and third code units must start with 10, and the encoded code point must be in the 
	//range 000800-00FFFF

	//Test some invalid three-code-unit characters
	characterReference.assign_reference(utf8String[1]);

	//Test a character with a first code unit that doesn't start with 1110
	characterReference[0] = '\xFA';
	characterReference[1] = '\x86';
	characterReference[2] = '\x92';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a second code unit that doesn't start with 10
	characterReference[0] = '\xEF';
	characterReference[1] = '\x44';
	characterReference[2] = '\x88';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a third code unit that doesn't start with 10
	characterReference[0] = '\xEF';
	characterReference[1] = '\x92';
	characterReference[2] = '\x21';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a first code unit that doesn't start with 1110, a second code 
	//unit that doesn't start with 10, and a third code unit that doesn't start with 10
	characterReference[0] = '\xF3';
	characterReference[1] = '\x40';
	characterReference[2] = '\x03';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character that is outside the range 000800-00FFFF
	characterReference[0] = '\xE0';
	characterReference[1] = '\x81';
	characterReference[2] = '\x8A';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	characterReference[0] = '\xE1';
	characterReference[1] = '\xBA';
	characterReference[2] = '\xAB';

	//Test some valid four-code-unit characters
	CPPUNIT_ASSERT(utf8String[3].is_valid());

	CPPUNIT_ASSERT(utf8String[9].is_valid());

	//For a four-code-unit UTF-8 character to be valid, the first code unit must start with 11110, 
	//the second, third, and fourth code units  must start with 10, and the encoded code point must 
	//be in the range 010000-10FFFF

	//Test some invalid four-code-unit characters
	characterReference.assign_reference(utf8String[3]);

	//Test a character with a first code unit that doesn't start with 11110
	characterReference[0] = '\xFC';
	characterReference[1] = '\x86';
	characterReference[2] = '\x92';
	characterReference[3] = '\xA4';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a second code unit that doesn't start with 10
	characterReference[0] = '\xFC';
	characterReference[1] = '\x44';
	characterReference[2] = '\x88';
	characterReference[3] = '\x89';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a third code unit that doesn't start with 10
	characterReference[0] = '\xFC';
	characterReference[1] = '\x92';
	characterReference[2] = '\x21';
	characterReference[3] = '\xA5';

	CPPUNIT_ASSERT(!utf8String[3].is_valid());

	//Test a character with a fourth code unit that doesn't start with 10
	characterReference[0] = '\xFC';
	characterReference[1] = '\x92';
	characterReference[2] = '\x81';
	characterReference[3] = '\x05';

	CPPUNIT_ASSERT(!utf8String[3].is_valid());

	//Test a character with a first code unit that doesn't start with 1110, a second code 
	//unit that doesn't start with 10, a third code unit that doesn't start with 10,
	//and a fourth code unit that doesn't start with 10
	characterReference[0] = '\xFC';
	characterReference[1] = '\x40';
	characterReference[2] = '\x03';
	characterReference[3] = '\x3A';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character that is outside the range 010000-10FFFF
	characterReference[0] = '\xFC';
	characterReference[1] = '\x80';
	characterReference[2] = '\x81';
	characterReference[3] = '\x80';

	CPPUNIT_ASSERT(!characterReference.is_valid());
}

void Utf8CharReferenceTest::TestNotEqualsOperator()
{

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8CharReference characterReference = utf8String[0];

	//Test the == operator that accepts a Utf8Char
	//Compare a single-code-unit character reference to single-code-unit character
	Utf8Char character;
	character[0] = '\x53';

	CPPUNIT_ASSERT(!(characterReference != character));

	character.clear();
	character[0] = '\x13';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a single-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a single-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a single-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(characterReference != character);



	//Compare a two-code-unit character reference to single-code-unit character
	characterReference.assign_reference(utf8String[5]);

	character.clear();
	character[0] = '\x53';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a two-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\x9F';

	CPPUNIT_ASSERT(!(characterReference != character));

	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a two-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a two-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(characterReference != character);


	//Compare a three-code-unit character reference to single-code-unit character
	characterReference.assign_reference(utf8String[1]);

	character.clear();
	character[0] = '\x53';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a three-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a three-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';

	CPPUNIT_ASSERT(!(characterReference != character));

	character.clear();
	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a three-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(characterReference != character);


	//Compare a four-code-unit character reference to single-code-unit character
	characterReference.assign_reference(utf8String[3]);

	character.clear();
	character[0] = '\x53';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a four-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a four-code-unit character reference to a three-code-unit character
	character.clear();
	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a four-code-unit character reference to a four-code-unit character
	character.clear();
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';

	CPPUNIT_ASSERT(!(characterReference != character));

	character.clear();
	character[0] = '\xF0';
	character[1] = '\x90';
	character[2] = '\x8D';
	character[3] = '\x86';

	CPPUNIT_ASSERT(characterReference != character);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xF0\x92\x81\xA8\x53\xE1\xBA\xAB\xC3\x9F\xE2\x88\x91\xF0\x90\x8D\x86\xE1\xBA\xAB\x62\xD0\xB4";

	//Now test the == operator that accepts a Utf8CharReference
	//Compare a single-code-unit character reference to single-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	Utf8CharReference otherCharacterReference = utf8String[0];
	characterReference.assign_reference(utf8String[0]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[8]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a single-code-unit character reference to a two-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a single-code-unit character reference to a three-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a single-code-unit character reference to a four-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a two-code-unit character reference to two-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	otherCharacterReference.assign_reference(utf8String[5]);
	characterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[10]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[4]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a two-code-unit character reference to a three-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a two-code-unit character reference to a four-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a three-code-unit character reference to three-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	otherCharacterReference.assign_reference(utf8String[1]);
	characterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[9]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[11]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a three-code-unit character reference to a four-code-unit character reference
	//and vice versa
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a four-code-unit character reference to four-code-unit character reference
	//and vice versa
	//Compare a reference to itself
	otherCharacterReference.assign_reference(utf8String[3]);
	characterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with the same value
	otherCharacterReference.assign_reference(utf8String[7]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	//Compare a reference to another reference with a different value
	otherCharacterReference.assign_reference(utf8String[12]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);
}

void Utf8CharReferenceTest::TestReferenceEqual()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xF0\x92\x81\xA8\x53\xE1\xBA\xAB\xC3\x9F\xE2\x88\x91\xF0\x90\x8D\x86\xE1\xBA\xAB\x62\xD0\xB4";
	
	//Character references point to same one-code-unit characters
	Utf8CharReference characterReference = utf8String[0];
	Utf8CharReference otherCharacterReference = utf8String[0];

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different one-code-unit characters with the same values
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[8]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(utf8String[4]);
	otherCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different two-code-unit characters with the same values
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[10]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same three-code-unit characters
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different three-code-unit characters
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[11]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different three-code-unit characters with the same values
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[9]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same four-code-unit characters
	characterReference.assign_reference(utf8String[3]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different four-code-unit characters
	characterReference.assign_reference(utf8String[3]);
	otherCharacterReference.assign_reference(utf8String[12]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different four-code-unit characters with the same values
	characterReference.assign_reference(utf8String[3]);
	otherCharacterReference.assign_reference(utf8String[7]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));
}

void Utf8CharReferenceTest::TestReferenceNotEqual()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xF0\x92\x81\xA8\x53\xE1\xBA\xAB\xC3\x9F\xE2\x88\x91\xF0\x90\x8D\x86\xE1\xBA\xAB\x62\xD0\xB4";
	
	//Character references point to same one-code-unit characters
	Utf8CharReference characterReference = utf8String[0];
	Utf8CharReference otherCharacterReference = utf8String[0];

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different one-code-unit characters with the same values
	characterReference.assign_reference(utf8String[0]);
	otherCharacterReference.assign_reference(utf8String[8]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(utf8String[4]);
	otherCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different two-code-unit characters with the same values
	characterReference.assign_reference(utf8String[5]);
	otherCharacterReference.assign_reference(utf8String[10]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same three-code-unit characters
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different three-code-unit characters
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[11]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different three-code-unit characters with the same values
	characterReference.assign_reference(utf8String[1]);
	otherCharacterReference.assign_reference(utf8String[9]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same four-code-unit characters
	characterReference.assign_reference(utf8String[3]);
	otherCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different four-code-unit characters
	characterReference.assign_reference(utf8String[3]);
	otherCharacterReference.assign_reference(utf8String[12]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different four-code-unit characters with the same values
	characterReference.assign_reference(utf8String[3]);
	otherCharacterReference.assign_reference(utf8String[7]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));
}

void Utf8CharReferenceTest::TestSize()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8CharReference characterReference = utf8String[0];
	CPPUNIT_ASSERT_EQUAL((size_t)1, characterReference.size());
	
	characterReference.assign_reference(utf8String[6]);
	CPPUNIT_ASSERT_EQUAL((size_t)1, characterReference.size());

	characterReference.assign_reference(utf8String[4]);
	CPPUNIT_ASSERT_EQUAL((size_t)2, characterReference.size());

	characterReference.assign_reference(utf8String[10]);
	CPPUNIT_ASSERT_EQUAL((size_t)2, characterReference.size());

	characterReference.assign_reference(utf8String[1]);
	CPPUNIT_ASSERT_EQUAL((size_t)3, characterReference.size());

	characterReference.assign_reference(utf8String[8]);
	CPPUNIT_ASSERT_EQUAL((size_t)3, characterReference.size());

	characterReference.assign_reference(utf8String[3]);
	CPPUNIT_ASSERT_EQUAL((size_t)4, characterReference.size());

	characterReference.assign_reference(utf8String[9]);
	CPPUNIT_ASSERT_EQUAL((size_t)4, characterReference.size());
}

void Utf8CharReferenceTest::TestToUtf32()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8CharReference characterReference = utf8String[0];

	//Decode some one-code-unit characters
	characterReference.assign_reference(utf8String[0]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000062, characterReference.to_utf_32());

	//Decode some two-code-unit characters
	characterReference.assign_reference(utf8String[4]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000F6, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, characterReference.to_utf_32());

	//Decode some three-code-unit characters
	characterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[8]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, characterReference.to_utf_32());

	//Decode some four-code-unit characters
	characterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[9]);

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, characterReference.to_utf_32());
}

void Utf8CharReferenceTest::TestUtf8CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8Char character = utf8String[0];
	CPPUNIT_ASSERT(character == utf8String[0]);
	
	character = utf8String[5];
	CPPUNIT_ASSERT(character == utf8String[5]);

	character = utf8String[1];
	CPPUNIT_ASSERT(character == utf8String[1]);

	character = utf8String[3];
	CPPUNIT_ASSERT(character == utf8String[3]);
}

void Utf8CharReferenceTest::TestUtf16CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Assign a UTF-8 four-code-unit code point that will result in a UTF-16 two-code-unit code point
	utf16String[5] = utf8String[0];

	CPPUNIT_ASSERT(utf16String[5] == L"\xD808\xDC68");

	//Assign a UTF-8 three-code-unit code point that will result in a UTF-16 one-code-unit code point
	utf16String[0] = utf8String[2];

	CPPUNIT_ASSERT(utf16String[0] == L"\x1EAB");

	//Assign a UTF-8 two-code-unit code point that will result in a UTF-16 one-code-unit code point
	utf16String[0] = utf8String[5];

	CPPUNIT_ASSERT(utf16String[0] == L"\x00F6");

	//Assign a UTF-8 one-code-unit code point that will result in a UTF-16 one-code-unit code point
	utf16String[0] = utf8String[4];

	CPPUNIT_ASSERT(utf16String[0] == L"\x0062");
}

/*Private Helper Functions*/

