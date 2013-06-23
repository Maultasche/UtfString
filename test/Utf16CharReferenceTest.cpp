/*!
\file Utf16CharReferenceTest.cpp

This file contains the definition of the Utf16CharReferenceTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <string>

#include "Utf16CharReferenceTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void Utf16CharReferenceTest::TestAssignmentOperator()
{
	//Create a UTF-16 string composed of only single-code-unit characters
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Test the = operator that accepts a Utf16Char
	Utf16Char character;
	character[0] = (UInt16)L'\x00F6';

	utf16String[1] = character;
	CPPUNIT_ASSERT(character == utf16String[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', utf16String[1][0]);

	character.clear();

	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	character[0] = L'\xD808';
	character[1] = L'\xDC68';

	utf16String[1] = character;
	CPPUNIT_ASSERT(character == utf16String[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16String[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16String[1][1]);

	character.clear();

	//Create a UTF-16 string composed of one- and two-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Assign a single-code-unit character to an index that currently holds a two-code-unit character
	character[0] = (UInt16)L'\x00F6';

	size_t stringSize = utf16String.size();

	utf16String[3] = character;
	CPPUNIT_ASSERT(character == utf16String[3]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', utf16String[3][0]);

	//We should have one fewer code unit in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size() + 1);

	character.clear();

	//Assign a two-code-unit character to an index that currently holds a two-code-unit character
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	character[0] = L'\xD808';
	character[1] = L'\xDC68';

	stringSize = utf16String.size();

	utf16String[9] = character;
	CPPUNIT_ASSERT(character == utf16String[9]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16String[9][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16String[9][1]);

	//We should have the same number of code units in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size());

	character.clear();

	//Assign a single-code-unit character to an index that currently holds a single-code-unit character
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	character[0] = L'G';

	stringSize = utf16String.size();

	utf16String[6] = character;
	CPPUNIT_ASSERT(character == utf16String[6]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'G', utf16String[6][0]);

	//We should have the same number of code units in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size());

	character.clear();

	//Assign a two-code-unit character to an index that currently holds a single-code-unit character
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	character[0] = L'\xD808';
	character[1] = L'\xDC68';

	stringSize = utf16String.size();

	utf16String[5] = character;
	CPPUNIT_ASSERT(character == utf16String[5]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16String[5][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16String[5][1]);

	//We should have one more code unit in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size() - 1);

	character.clear();



	//Test the = operator that accepts a Utf16CharReference
	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	utf16String[1] = utf16String[4];
	CPPUNIT_ASSERT(utf16String[4] == utf16String[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', utf16String[1][0]);

	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Create a UTF-16 string composed of one- and two-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Assign a single-code-unit character to an index that currently holds a two-code-unit character
	stringSize = utf16String.size();

	utf16String[3] = utf16String[2];
	CPPUNIT_ASSERT(utf16String[3] == utf16String[2]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', utf16String[3][0]);

	//We should have one fewer code unit in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size() + 1);

	//Assign a two-code-unit character to an index that currently holds a two-code-unit character
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	stringSize = utf16String.size();

	utf16String[9] = utf16String[3];
	CPPUNIT_ASSERT(utf16String[9] == utf16String[3]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16String[9][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16String[9][1]);

	//We should have the same number of code units in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size());

	character.clear();

	//Assign a single-code-unit character to an index that currently holds a single-code-unit character
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	stringSize = utf16String.size();

	utf16String[6] = utf16String[1];
	CPPUNIT_ASSERT(utf16String[6] == utf16String[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', utf16String[6][0]);

	//We should have the same number of code units in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size());

	character.clear();

	//Assign a two-code-unit character to an index that currently holds a single-code-unit character
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	stringSize = utf16String.size();

	utf16String[5] = utf16String[3];
	CPPUNIT_ASSERT(utf16String[5] == utf16String[3]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16String[5][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16String[5][1]);

	//We should have one more code unit in the string
	CPPUNIT_ASSERT(stringSize == utf16String.size() - 1);

	character.clear();
}

void Utf16CharReferenceTest::TestAssignReference()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16CharReference characterReference = utf16String[0];

	characterReference.assign_reference(utf16String[4]);
	CPPUNIT_ASSERT(characterReference == utf16String[4]);
	
	characterReference.assign_reference(utf16String[9]);
	CPPUNIT_ASSERT(characterReference == utf16String[9]);

	characterReference.assign_reference(utf16String[3]);
	CPPUNIT_ASSERT(characterReference == utf16String[3]);

	characterReference.assign_reference(utf16String[1]);
	CPPUNIT_ASSERT(characterReference == utf16String[1]);
}

void Utf16CharReferenceTest::TestConstructors()
{
	//Create a UTF-16 string composed of only single-code-unit characters
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Create a Utf16CharReference using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	basic_string<UInt16> codeUnitString = utf16String;
	basic_string<UInt16>::iterator basicStringIterator = codeUnitString.begin() + 1;
	Utf16CharReference* constructedCharacterReference = new Utf16CharReference(codeUnitString, basicStringIterator, 
		Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', (*constructedCharacterReference)[0]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Create another Utf16CharReference using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringIterator = codeUnitString.end() - 1;
	constructedCharacterReference = new Utf16CharReference(codeUnitString, basicStringIterator, 
		Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', (*constructedCharacterReference)[0]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Now repeat the tests using two-code-unit characters

	//Create a UTF-16 string composed of one- and two-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Create a Utf16CharReference using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringIterator = codeUnitString.begin() + 5;
	constructedCharacterReference = new Utf16CharReference(codeUnitString, basicStringIterator, 
		Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)1, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', (*constructedCharacterReference)[0]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;

	//Create another Utf16Char using the constructor that accepts a std::basic_string<UInt16>::iterator
	//and a size_t
	codeUnitString = utf16String;
	basicStringIterator = codeUnitString.begin() + 3;
	constructedCharacterReference = new Utf16CharReference(codeUnitString, basicStringIterator, 
		Utf16String::CharacterCodeUnitCount(basicStringIterator));

	//Verify the results
	CPPUNIT_ASSERT_EQUAL((size_t)2, constructedCharacterReference->size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constructedCharacterReference)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constructedCharacterReference)[1]);

	delete constructedCharacterReference;
	constructedCharacterReference = NULL;
}

void Utf16CharReferenceTest::TestEqualsOperator()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16CharReference characterReference = utf16String[1];

	//Test the == operator that accepts a Utf16Char
	//Compare a single-code-unit character reference to single-code-unit character
	Utf16Char character;
	character[0] = L'\x1EAB';

	CPPUNIT_ASSERT(characterReference == character);

	character.clear();
	character[0] = 'i';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a single-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a two-code-unit character reference to a single-code-unit character
	characterReference = utf16String[3];

	character.clear();
	character[0] = L'w';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Compare a two-code-unit character reference to a two-code-unit character
	characterReference.assign_reference(utf16String[9]);

	character.clear();
	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(characterReference == character);

	character.clear();
	character[0] = L'\xD808';
	character[1] = L'\xDC68';

	CPPUNIT_ASSERT(!(characterReference == character));

	//Now test the == operator that accepts a Utf16CharReference
	//Compare a single-code-unit character reference to single-code-unit character reference
	Utf16CharReference otherCharacterReference = utf16String[1];
	characterReference.assign_reference(utf16String[1]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	otherCharacterReference.assign_reference(utf16String[6]);
	characterReference.assign_reference(utf16String[0]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	otherCharacterReference.assign_reference(utf16String[10]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a single-code-unit character reference to a two-code-unit character reference
	characterReference.assign_reference(utf16String[7]);
	otherCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a two-code-unit character reference to a single-code-unit character reference
	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[5]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	//Compare a two-code-unit character reference to a two-code-unit character reference
	characterReference.assign_reference(utf16String[9]);
	otherCharacterReference.assign_reference(utf16String[9]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);

	otherCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(characterReference == otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference == characterReference));

	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[11]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference == characterReference);
}

void Utf16CharReferenceTest::TestIndexingOperator()
{
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Get a reference to a character with one code unit
	Utf16CharReference characterReference = utf16String[1];

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', utf16String[1][0]);

	//Assign a single code unit character using the indexer
	characterReference[0] = (UInt16)L'\x00F6';

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', utf16String[1][0]);
	
	//Get a reference to a character with two code units
	characterReference.assign_reference(utf16String[3]);

	//Make sure the indexer returns the correct value
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16String[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16String[3][1]);

	//Assign a two code unit character using the indexer
	characterReference[0] = L'\xD800';
	characterReference[1] = L'\xDF46';

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', characterReference[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', characterReference[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', utf16String[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', utf16String[3][1]);
}

void Utf16CharReferenceTest::TestIsValid()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Validate valid one-code-unit characters
	CPPUNIT_ASSERT(utf16String[0].is_valid());

	CPPUNIT_ASSERT(utf16String[1].is_valid());

	//Validate invalid one-code-unit characters
	//Test the character on the lower boundary of the invalid range
	utf16String[0][0] = L'\xD800';

	CPPUNIT_ASSERT(!utf16String[0].is_valid());

	//Test a character in the middle of the invalid range
	utf16String[0][0] = L'\xDA92';

	CPPUNIT_ASSERT(!utf16String[0].is_valid());

	//Test a character at the end of the invalid range
	utf16String[0][0] = L'\xDFFF';

	CPPUNIT_ASSERT(!utf16String[0].is_valid());

	//Validate one-code-unit characters on the other side of the invalid range
	//Test a boundary character
	utf16String[0][0] = L'\xE000';

	CPPUNIT_ASSERT(utf16String[0].is_valid());

	//Test a character in the middle of the second valid range
	utf16String[0][0] = L'\xEFFF';

	CPPUNIT_ASSERT(utf16String[0].is_valid());

	//Test some valid two-code-unit characters
	CPPUNIT_ASSERT(utf16String[3].is_valid());

	CPPUNIT_ASSERT(utf16String[9].is_valid());

	//Test some invalid two-code-unit characters, where the first code unit is outside the range D800-DBFF
	//Test a character with the first code unit way outside the valid range
	Utf16CharReference characterReference = utf16String[3];

	characterReference[0] = L'\x0045';
	characterReference[1] = L'\xDF46';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with the first code unit just below the valid range
	characterReference[0] = L'\xD7FF';
	characterReference[1] = L'\xDF46';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with the first code unit just above the valid range
	characterReference[0] = L'\xDC00';
	characterReference[1] = L'\xDF46';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test some invalid two-code-unit characters, where the second code unit is outside the range DC00-DFFF
	//Test a character with the second code unit way outside the valid range
	characterReference[0] = L'\xD809';
	characterReference[1] = L'\x0045';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with the second code unit just below the valid range
	characterReference[0] = L'\xD809';
	characterReference[1] = L'\xDB99';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with the second code unit just above the valid range
	characterReference[0] = L'\xD809';
	characterReference[1] = L'\xE000';

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Now test a two-code-unit character with both code units outside the allowed ranges
	characterReference[0] = L'\x1ABC';
	characterReference[1] = L'\xF42A';

	CPPUNIT_ASSERT(!characterReference.is_valid());
}

void Utf16CharReferenceTest::TestNotEqualsOperator()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16CharReference characterReference = utf16String[1];

	//Test the != operator that accepts a Utf16Char
	//Compare a single-code-unit character reference to single-code-unit character
	Utf16Char character;
	character[0] = L'\x1EAB';

	CPPUNIT_ASSERT(!(characterReference != character));

	character.clear();
	character[0] = 'i';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a single-code-unit character reference to a two-code-unit character
	character.clear();
	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a two-code-unit character reference to a single-code-unit character
	characterReference = utf16String[3];

	character.clear();
	character[0] = L'w';

	CPPUNIT_ASSERT(characterReference != character);

	//Compare a two-code-unit character reference to a two-code-unit character
	characterReference.assign_reference(utf16String[9]);

	character.clear();
	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!(characterReference != character));

	character.clear();
	character[0] = L'\xD808';
	character[1] = L'\xDC68';

	CPPUNIT_ASSERT(characterReference != character);

	//Now test the == operator that accepts a Utf16CharReference
	//Compare a single-code-unit character reference to single-code-unit character reference
	Utf16CharReference otherCharacterReference = utf16String[1];
	characterReference.assign_reference(utf16String[1]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	otherCharacterReference.assign_reference(utf16String[6]);
	characterReference.assign_reference(utf16String[0]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	otherCharacterReference.assign_reference(utf16String[10]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a single-code-unit character reference to a two-code-unit character reference
	characterReference.assign_reference(utf16String[7]);
	otherCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a two-code-unit character reference to a single-code-unit character reference
	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[5]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	//Compare a two-code-unit character reference to a two-code-unit character reference
	characterReference.assign_reference(utf16String[9]);
	otherCharacterReference.assign_reference(utf16String[9]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));

	otherCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(characterReference != otherCharacterReference);
	CPPUNIT_ASSERT(otherCharacterReference != characterReference);

	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[11]);

	CPPUNIT_ASSERT(!(characterReference != otherCharacterReference));
	CPPUNIT_ASSERT(!(otherCharacterReference != characterReference));
}

void Utf16CharReferenceTest::TestReferenceEqual()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Character references point to same one-code-unit characters
	Utf16CharReference characterReference = utf16String[1];
	Utf16CharReference otherCharacterReference = utf16String[1];

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(utf16String[4]);
	otherCharacterReference.assign_reference(utf16String[5]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to difference one-code-unit characters with the same values
	characterReference.assign_reference(utf16String[7]);
	otherCharacterReference.assign_reference(utf16String[1]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(utf16String[9]);
	otherCharacterReference.assign_reference(utf16String[9]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[9]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to difference two-code-unit characters with the same values
	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[11]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));
}

void Utf16CharReferenceTest::TestReferenceNotEqual()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Character references point to same one-code-unit characters
	Utf16CharReference characterReference = utf16String[1];
	Utf16CharReference otherCharacterReference = utf16String[1];

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(utf16String[4]);
	otherCharacterReference.assign_reference(utf16String[5]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to difference one-code-unit characters with the same values
	characterReference.assign_reference(utf16String[7]);
	otherCharacterReference.assign_reference(utf16String[1]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(utf16String[9]);
	otherCharacterReference.assign_reference(utf16String[9]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[9]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to difference two-code-unit characters with the same values
	characterReference.assign_reference(utf16String[3]);
	otherCharacterReference.assign_reference(utf16String[11]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));
}

void Utf16CharReferenceTest::TestSize()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16CharReference characterReference = utf16String[4];
	CPPUNIT_ASSERT_EQUAL((size_t)1, characterReference.size());
	
	characterReference.assign_reference(utf16String[9]);
	CPPUNIT_ASSERT_EQUAL((size_t)2, characterReference.size());

	characterReference.assign_reference(utf16String[3]);
	CPPUNIT_ASSERT_EQUAL((size_t)2, characterReference.size());

	characterReference.assign_reference(utf16String[1]);
	CPPUNIT_ASSERT_EQUAL((size_t)1, characterReference.size());
}

void Utf16CharReferenceTest::TestToUtf32()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Decode some one-code-unit characters
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, utf16String[1].to_utf_32());

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, utf16String[8].to_utf_32());

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000062, utf16String[2].to_utf_32());

	//Decode some two-code-unit characters
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, utf16String[3].to_utf_32());

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, utf16String[9].to_utf_32());
}

void Utf16CharReferenceTest::TestUtf16CharConversionOperator()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16Char character = utf16String[4];
	CPPUNIT_ASSERT(character == utf16String[4]);
	
	character = utf16String[9];
	CPPUNIT_ASSERT(character == utf16String[9]);

	character = utf16String[3];
	CPPUNIT_ASSERT(character == utf16String[3]);

	character = utf16String[1];
	CPPUNIT_ASSERT(character == utf16String[1]);
}

void Utf16CharReferenceTest::TestUtf8CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Assign a UTF-16 two-code-unit code point that will result in a UTF-8 four-code-unit code point
	utf8String[5] = utf16String[0];

	CPPUNIT_ASSERT(utf8String[5] == "\xF0\x92\x81\xA8");

	//Assign a UTF-16 one-code-unit code point that will result in a UTF-8 three-code-unit code point
	utf8String[0] = utf16String[2];

	CPPUNIT_ASSERT(utf8String[0] == "ẫ");

	//Assign a UTF-16 one-code-unit code point that will result in a UTF-8 two-code-unit code point
	utf8String[0] = utf16String[5];

	CPPUNIT_ASSERT(utf8String[0] == "ö");

	//Assign a UTF-16 one-code-unit code point that will result in a UTF-8 one-code-unit code point
	utf8String[0] = utf16String[4];

	CPPUNIT_ASSERT(utf8String[0] == "b");
}

/*Private Helper Functions*/

