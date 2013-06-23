/*!
\file UnicodeCharTest.cpp

This file contains the definition of the UnicodeCharTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

/*
TODO: Indicate in documentation that checking for validity is important for UnicodeChars and UnicodeStrings,
because they have to be valid in order to be converted to Utf8Char, Utf16Char, Utf8String, and Utf16String.
This is particularly because it is easy for the conversion operators to be implicitly called, even when
it is not obvious to the programmer.  An invalid character or string could cause a crash or assertion failure
during a conversion.
*/
#include <string>

#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

#include "UnicodeCharTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void UnicodeCharTest::TestAssignmentOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	Utf8Char utf8Character;
	Utf16Char utf16Character;

	//Test the = operator that accepts a UnicodeChar
	//Assign a UnicodeChar containing a UTF-8 character to a UnicodeChar containing a UTF-8 character
	UnicodeChar firstCharacter;
	firstCharacter = Utf8Char("ẫ");

	UnicodeChar secondCharacter;
	secondCharacter = Utf8Char("ß");

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == "ß");

	firstCharacter.clear();
	secondCharacter.clear();

	//Assign a UnicodeChar containing a UTF-8 character to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	secondCharacter = Utf8Char("ẫ");

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == "ẫ");

	firstCharacter.clear();
	secondCharacter.clear();
	
	//Assign a UnicodeChar containing a UTF-16 character to a UnicodeChar containing a UTF-8 character
	firstCharacter = Utf8Char("ẫ");
	secondCharacter = Utf16Char(L"\xD808\xDC68");

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == L"\xD808\xDC68");

	firstCharacter.clear();
	secondCharacter.clear();

	//Assign a UnicodeChar containing a UTF-16 character to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"ẫ");
	secondCharacter = Utf16Char(L"\xD808\xDC68");

	firstCharacter = secondCharacter;
	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == L"\xD808\xDC68");

	firstCharacter.clear();
	secondCharacter.clear();

	//Test the = operator that accepts a Utf8Char
	//Assign a Utf8Char to a UnicodeChar containing a UTF-8 character
	firstCharacter = Utf8Char("ß");
	utf8Character = "5";

	firstCharacter = utf8Character;
	CPPUNIT_ASSERT(firstCharacter == utf8Character);
	CPPUNIT_ASSERT(firstCharacter == "5");

	firstCharacter.clear();

	//Assign a Utf8Char to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	utf8Character = "5";

	firstCharacter = utf8Character;
	CPPUNIT_ASSERT(firstCharacter == utf8Character);
	CPPUNIT_ASSERT(firstCharacter == "5");

	firstCharacter.clear();

	//Test the = operator that accepts a Utf16Char
	//Assign a Utf16Char to a UnicodeChar containing a UTF-8 character
	firstCharacter = Utf8Char("ß");
	utf16Character = L"\xD808\xDC68";

	firstCharacter = utf16Character;
	CPPUNIT_ASSERT(firstCharacter == utf16Character);
	CPPUNIT_ASSERT(firstCharacter == L"\xD808\xDC68");

	firstCharacter.clear();

	//Assign a Utf16Char to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"A");
	utf16Character = L"\xD808\xDC68";

	firstCharacter = utf16Character;
	CPPUNIT_ASSERT(firstCharacter == utf16Character);
	CPPUNIT_ASSERT(firstCharacter == L"\xD808\xDC68");

	firstCharacter.clear();

	//Test the = operator that accepts a Utf8CharReference
	//Assign a Utf8CharReference to a UnicodeChar containing a UTF-8 character
	firstCharacter = Utf8Char("ß");
	Utf8CharReference utf8CharacterReference = utf8String[3];

	firstCharacter = utf8CharacterReference;
	CPPUNIT_ASSERT(firstCharacter == utf8CharacterReference);
	CPPUNIT_ASSERT(firstCharacter == "\xF0\x92\x81\xA8");

	firstCharacter.clear();

	//Assign a Utf8CharReference to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	utf8CharacterReference.assign_reference(utf8String[1]);

	firstCharacter = utf8CharacterReference;
	CPPUNIT_ASSERT(firstCharacter == utf8CharacterReference);
	CPPUNIT_ASSERT(firstCharacter == "ẫ");

	firstCharacter.clear();

	//Test the = operator that accepts a Utf16CharReference
	//Assign a Utf16CharReference to a UnicodeChar containing a UTF-8 character
	firstCharacter = Utf8Char("ß");
	Utf16CharReference utf16CharacterReference = utf16String[3];

	firstCharacter = utf16CharacterReference;
	CPPUNIT_ASSERT(firstCharacter == utf16CharacterReference);
	CPPUNIT_ASSERT(firstCharacter == L"\xD808\xDC68");

	firstCharacter.clear();

	//Assign a Utf16CharReference to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	utf16CharacterReference.assign_reference(utf16String[1]);

	firstCharacter = utf8CharacterReference;
	CPPUNIT_ASSERT(firstCharacter == utf16CharacterReference);
	CPPUNIT_ASSERT(firstCharacter == L"\x1EAB");

	firstCharacter.clear();
}

void UnicodeCharTest::TestClear()
{
	//Test the clear() function with UTF-8 strings
	UnicodeChar character;
	character = "ß";

	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)character).size());
	CPPUNIT_ASSERT(character == "ß");
	
	character.clear();

	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT_EQUAL(ENCODING_NONE, character.internal_encoding());
	CPPUNIT_ASSERT(character == "");

	character = "\xF0\x90\x8D\x86";

	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)character).size());
	CPPUNIT_ASSERT(character == "\xF0\x90\x8D\x86");

	character.clear();

	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT_EQUAL(ENCODING_NONE, character.internal_encoding());
	CPPUNIT_ASSERT(character == "");

	character = "S";

	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)character).size());
	CPPUNIT_ASSERT(character == "S");	

	character.clear();

	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT_EQUAL(ENCODING_NONE, character.internal_encoding());
	CPPUNIT_ASSERT(character == "");

	//Test the clear() function with UTF-16 strings
	character = L"\x00F6";

	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)character).size());
	CPPUNIT_ASSERT(character == L"\x00F6");	

	character.clear();

	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT_EQUAL(ENCODING_NONE, character.internal_encoding());
	CPPUNIT_ASSERT(character == L"");

	character = L"\xD800\xDF46";

	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)character).size());
	CPPUNIT_ASSERT(character == L"\xD800\xDF46");

	character.clear();

	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT_EQUAL(ENCODING_NONE, character.internal_encoding());
	CPPUNIT_ASSERT(character == L"");

	character = L"\xEF46";

	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)character).size());
	CPPUNIT_ASSERT(character == L"\xEF46");

	character.clear();

	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT_EQUAL(ENCODING_NONE, character.internal_encoding());
	CPPUNIT_ASSERT(character == L"");
}

void UnicodeCharTest::TestConstructors()
{
	//Test the default constructor 
	UnicodeChar* unicodeCharacter = new UnicodeChar();

	//Verify the results
	CPPUNIT_ASSERT(unicodeCharacter->empty());
	CPPUNIT_ASSERT(!unicodeCharacter->is_valid());
	CPPUNIT_ASSERT_EQUAL(ENCODING_NONE, unicodeCharacter->internal_encoding());

	delete unicodeCharacter;
	unicodeCharacter = NULL;

	//Test the constructor that accepts a UnicodeChar
	//Construct a UnicodeChar with a UnicodeChar that contains a UTF-8 character
	UnicodeChar parameterCharacter = "ö";

	unicodeCharacter = new UnicodeChar(parameterCharacter);

	//Verify the results
	CPPUNIT_ASSERT(!unicodeCharacter->empty());
	CPPUNIT_ASSERT(unicodeCharacter->is_valid());
	CPPUNIT_ASSERT_EQUAL(ENCODING_UTF8, unicodeCharacter->internal_encoding());
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000F6, unicodeCharacter->to_utf_32());

	delete unicodeCharacter;
	unicodeCharacter = NULL;

	//Construct a UnicodeChar with a UnicodeChar that contains a UTF-16 character
	parameterCharacter = L"\xD808\xDC68";

	unicodeCharacter = new UnicodeChar(parameterCharacter);

	//Verify the results
	CPPUNIT_ASSERT(!unicodeCharacter->empty());
	CPPUNIT_ASSERT(unicodeCharacter->is_valid());
	CPPUNIT_ASSERT_EQUAL(ENCODING_UTF16, unicodeCharacter->internal_encoding());
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, unicodeCharacter->to_utf_32());

	delete unicodeCharacter;
	unicodeCharacter = NULL;

	//Test the constructor that accepts a Utf8Char
	unicodeCharacter = new UnicodeChar(Utf8Char("\xF0\x92\x81\xA8"));

	//Verify the results
	CPPUNIT_ASSERT(!unicodeCharacter->empty());
	CPPUNIT_ASSERT(unicodeCharacter->is_valid());
	CPPUNIT_ASSERT_EQUAL(ENCODING_UTF8, unicodeCharacter->internal_encoding());
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, unicodeCharacter->to_utf_32());

	delete unicodeCharacter;
	unicodeCharacter = NULL;

	//Test the constructor that accepts a Utf16Char
	unicodeCharacter = new UnicodeChar(Utf16Char(L"\x1EAB"));

	//Verify the results
	CPPUNIT_ASSERT(!unicodeCharacter->empty());
	CPPUNIT_ASSERT(unicodeCharacter->is_valid());
	CPPUNIT_ASSERT_EQUAL(ENCODING_UTF16, unicodeCharacter->internal_encoding());
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, unicodeCharacter->to_utf_32());

	delete unicodeCharacter;
	unicodeCharacter = NULL;
}

void UnicodeCharTest::TestEmpty()
{
	UnicodeChar character;

	//Test an empty character
	CPPUNIT_ASSERT(character.empty());

	//Test a character containing a UTF-8 character
	character = "P";

	CPPUNIT_ASSERT(!character.empty());

	character.clear();

	CPPUNIT_ASSERT(character.empty());

	//Test a character containing a UTF-16 character
	character = L".";

	CPPUNIT_ASSERT(!character.empty());

	character.clear();

	CPPUNIT_ASSERT(character.empty());
}

void UnicodeCharTest::TestEqualsOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Test the == operator that accepts another UnicodeChar
	//Compare a UnicodeChar containing a UTF-8 character to a UnicodeChar containing a UTF-8 character
	UnicodeChar firstCharacter;
	firstCharacter = Utf8Char("ẫ");

	UnicodeChar secondCharacter;
	secondCharacter = Utf8Char("ẫ");

	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	secondCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(!(secondCharacter == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter.clear();
	secondCharacter.clear();

	//Compare a UnicodeChar containing a UTF-8 character to a UnicodeChar containing a UTF-16 character
	//and vice versa
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	secondCharacter = Utf8Char("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	secondCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(!(secondCharacter == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter.clear();
	secondCharacter.clear();
	
	//Assign a UnicodeChar containing a UTF-16 character to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	secondCharacter = Utf16Char(L"\xD808\xDC68");

	CPPUNIT_ASSERT(secondCharacter == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == secondCharacter);

	firstCharacter = Utf16Char(L"ẫ");

	CPPUNIT_ASSERT(!(secondCharacter == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == secondCharacter));

	firstCharacter.clear();
	secondCharacter.clear();

	//Test the == operator that accepts a Utf8Char
	//Compare a Utf8Char to a UnicodeChar containing a UTF-8 character
	Utf8Char utf8Character = "5";
	firstCharacter = Utf8Char("5");

	CPPUNIT_ASSERT(utf8Character == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf8Character);

	firstCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(!(utf8Character == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf8Character));

	firstCharacter.clear();

	//Compare a Utf8Char to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	utf8Character = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT(utf8Character == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf8Character);

	firstCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(!(utf8Character == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf8Character));

	firstCharacter.clear();

	//Test the == operator that accepts a Utf16Char
	//Compare a Utf16Char to a UnicodeChar containing a UTF-8 character
	Utf16Char utf16Character = L"5";
	firstCharacter = Utf8Char("5");

	CPPUNIT_ASSERT(utf16Character == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf16Character);

	firstCharacter = Utf8Char("\xC4\x92");

	CPPUNIT_ASSERT(!(utf16Character == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf16Character));

	firstCharacter.clear();

	//Compare a Utf16Char to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	utf16Character = L"\xD808\xDC68";

	CPPUNIT_ASSERT(utf16Character == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf16Character);

	firstCharacter = Utf16Char(L"ß");

	CPPUNIT_ASSERT(!(utf16Character == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf16Character));

	firstCharacter.clear();

	//Test the == operator that accepts a UnicodeCharReference
	//Compare a UnicodeCharReference containing a UTF-8 character reference with
	//a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	UnicodeCharReference unicodeCharacterReference = utf8String[3];

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == unicodeCharacterReference);

	firstCharacter = utf8String[2];

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == unicodeCharacterReference));

	firstCharacter.clear();

	//Compare a UnicodeCharReference containing a UTF-8 character reference with
	//a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	unicodeCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == unicodeCharacterReference);

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == unicodeCharacterReference));

	firstCharacter.clear();

	//Compare a UnicodeCharReference containing a UTF-16 character reference with
	//a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == unicodeCharacterReference);

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == unicodeCharacterReference));

	firstCharacter.clear();

	//Compare a UnicodeCharReference containing a UTF-16 character reference with
	//a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == unicodeCharacterReference);

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == unicodeCharacterReference));

	firstCharacter.clear();

	//Test the == operator that accepts a Utf8CharReference
	//Compare a Utf8CharReference with a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	Utf8CharReference utf8CharacterReference = utf8String[3];

	CPPUNIT_ASSERT(utf8CharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf8CharacterReference);

	firstCharacter = utf8String[2];

	CPPUNIT_ASSERT(!(utf8CharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf8CharacterReference));

	firstCharacter.clear();

	//Compare a Utf8CharReference with a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(utf8CharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf8CharacterReference);

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(!(utf8CharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf8CharacterReference));

	firstCharacter.clear();

	//Test the == operator that accepts a Utf16CharReference
	//Compare a Utf16CharReference with a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	Utf16CharReference utf16CharacterReference = utf16String[3];

	CPPUNIT_ASSERT(utf16CharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf16CharacterReference);

	firstCharacter = utf8String[2];

	CPPUNIT_ASSERT(!(utf16CharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf16CharacterReference));

	firstCharacter.clear();

	//Compare a Utf16CharReference with a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(utf16CharacterReference == firstCharacter);
	CPPUNIT_ASSERT(firstCharacter == utf16CharacterReference);

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(!(utf16CharacterReference == firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter == utf16CharacterReference));

	firstCharacter.clear();
}

void UnicodeCharTest::TestInternalEncoding()
{
	UnicodeChar character;

	//Test with an empty character
	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT(character.internal_encoding() == ENCODING_NONE);

	//Assign the character a UTF-8 character and test
	character = "t";

	CPPUNIT_ASSERT(!character.empty());
	CPPUNIT_ASSERT(character.internal_encoding() == ENCODING_UTF8);

	//Assign the character a UTF-16 character and test
	character = L";";

	CPPUNIT_ASSERT(!character.empty());
	CPPUNIT_ASSERT(character.internal_encoding() == ENCODING_UTF16);	
}

void UnicodeCharTest::TestIsValid()
{
	UnicodeChar character;

	//Test whether an empty character is valid
	CPPUNIT_ASSERT(character.empty());
	CPPUNIT_ASSERT(!character.is_valid());

	//Test a character with a valid UTF-8 character
	character = "\xC3\xB6";

	CPPUNIT_ASSERT(!character.empty());
	CPPUNIT_ASSERT(character.is_valid());

	character.clear();

	//Test a character with an invalid UTF-8 character
	character = "\xFA\x44";

	CPPUNIT_ASSERT(!character.empty());
	CPPUNIT_ASSERT(!character.is_valid());

	character.clear();

	//Test a character with a valid UTF-16 character
	character = L"\xD800\xDF46";

	CPPUNIT_ASSERT(!character.empty());
	CPPUNIT_ASSERT(character.is_valid());

	character.clear();

	//Test a character with an invalid UTF-16 character
	character = L"\xD809\x0045";

	CPPUNIT_ASSERT(!character.empty());
	CPPUNIT_ASSERT(!character.is_valid());

	character.clear();
}

void UnicodeCharTest::TestNotEqualsOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Test the != operator that accepts another UnicodeChar
	//Compare a UnicodeChar containing a UTF-8 character to a UnicodeChar containing a UTF-8 character
	UnicodeChar firstCharacter;
	firstCharacter = Utf8Char("ẫ");

	UnicodeChar secondCharacter;
	secondCharacter = Utf8Char("ẫ");

	CPPUNIT_ASSERT(!(secondCharacter != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != secondCharacter));

	secondCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(secondCharacter != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter.clear();
	secondCharacter.clear();

	//Compare a UnicodeChar containing a UTF-8 character to a UnicodeChar containing a UTF-16 character
	//and vice versa
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	secondCharacter = Utf8Char("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT(!(secondCharacter != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != secondCharacter));

	secondCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(secondCharacter != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter.clear();
	secondCharacter.clear();
	
	//Assign a UnicodeChar containing a UTF-16 character to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	secondCharacter = Utf16Char(L"\xD808\xDC68");

	CPPUNIT_ASSERT(!(secondCharacter != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != secondCharacter));

	firstCharacter = Utf16Char(L"ẫ");

	CPPUNIT_ASSERT(secondCharacter != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != secondCharacter);

	firstCharacter.clear();
	secondCharacter.clear();

	//Test the != operator that accepts a Utf8Char
	//Compare a Utf8Char to a UnicodeChar containing a UTF-8 character
	Utf8Char utf8Character = "5";
	firstCharacter = Utf8Char("5");

	CPPUNIT_ASSERT(!(utf8Character != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf8Character));

	firstCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(utf8Character != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf8Character);

	firstCharacter.clear();

	//Compare a Utf8Char to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	utf8Character = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT(!(utf8Character != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf8Character));

	firstCharacter = Utf8Char("ß");

	CPPUNIT_ASSERT(utf8Character != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf8Character);

	firstCharacter.clear();

	//Test the != operator that accepts a Utf16Char
	//Compare a Utf16Char to a UnicodeChar containing a UTF-8 character
	Utf16Char utf16Character = L"5";
	firstCharacter = Utf8Char("5");

	CPPUNIT_ASSERT(!(utf16Character != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf16Character));

	firstCharacter = Utf8Char("\xC4\x92");

	CPPUNIT_ASSERT(utf16Character != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf16Character);

	firstCharacter.clear();

	//Compare a Utf16Char to a UnicodeChar containing a UTF-16 character
	firstCharacter = Utf16Char(L"\xD808\xDC68");
	utf16Character = L"\xD808\xDC68";

	CPPUNIT_ASSERT(!(utf16Character != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf16Character));

	firstCharacter = Utf16Char(L"ß");

	CPPUNIT_ASSERT(utf16Character != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf16Character);

	firstCharacter.clear();

	//Test the != operator that accepts a UnicodeCharReference
	//Compare a UnicodeCharReference containing a UTF-8 character reference with
	//a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	UnicodeCharReference unicodeCharacterReference = utf8String[3];

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != unicodeCharacterReference));

	firstCharacter = utf8String[2];

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != unicodeCharacterReference);

	firstCharacter.clear();

	//Compare a UnicodeCharReference containing a UTF-8 character reference with
	//a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	unicodeCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != unicodeCharacterReference));

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != unicodeCharacterReference);

	firstCharacter.clear();

	//Compare a UnicodeCharReference containing a UTF-16 character reference with
	//a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != unicodeCharacterReference));

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != unicodeCharacterReference);

	firstCharacter.clear();

	//Compare a UnicodeCharReference containing a UTF-16 character reference with
	//a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != unicodeCharacterReference));

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != unicodeCharacterReference);

	firstCharacter.clear();

	//Test the != operator that accepts a Utf8CharReference
	//Compare a Utf8CharReference with a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	Utf8CharReference utf8CharacterReference = utf8String[3];

	CPPUNIT_ASSERT(!(utf8CharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf8CharacterReference));

	firstCharacter = utf8String[2];

	CPPUNIT_ASSERT(utf8CharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf8CharacterReference);

	firstCharacter.clear();

	//Compare a Utf8CharReference with a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(utf8CharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf8CharacterReference));

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(utf8CharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf8CharacterReference);

	firstCharacter.clear();

	//Test the != operator that accepts a Utf16CharReference
	//Compare a Utf16CharReference with a UnicodeChar containing a UTF-8 character
	firstCharacter = utf8String[3];
	Utf16CharReference utf16CharacterReference = utf16String[3];

	CPPUNIT_ASSERT(!(utf16CharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf16CharacterReference));

	firstCharacter = utf8String[2];

	CPPUNIT_ASSERT(utf16CharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf16CharacterReference);

	firstCharacter.clear();

	//Compare a Utf16CharReference with a UnicodeChar containing a UTF-16 character
	firstCharacter = utf16String[3];
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(utf16CharacterReference != firstCharacter));
	CPPUNIT_ASSERT(!(firstCharacter != utf16CharacterReference));

	firstCharacter = utf16String[2];

	CPPUNIT_ASSERT(utf16CharacterReference != firstCharacter);
	CPPUNIT_ASSERT(firstCharacter != utf16CharacterReference);

	firstCharacter.clear();
}


void UnicodeCharTest::TestToUtf32()
{
	UnicodeChar character;

	//Decode a UTF-8 character
	character = "\xE1\xBA\xAB";

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	//Decode a UTF-16 character
	character = L"\x1EAB";

	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());
}

void UnicodeCharTest::TestUtf8CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	UnicodeChar character;
	Utf8Char utf8Character;

	//Convert an empty character
	utf8Character = (Utf8Char)character;

	CPPUNIT_ASSERT(utf8Character.size() == 0);

	//Convert a character containing a UTF-8 string
	character = utf8String[0];

	utf8Character = (Utf8Char)character;

	CPPUNIT_ASSERT(utf8Character == utf8String[0]);

	//Convert a character containing a UTF-16 string
	character = utf16String[6];

	utf8Character = (Utf8Char)character;

	CPPUNIT_ASSERT(utf8Character == utf8String[6]);
}

void UnicodeCharTest::TestUtf16CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	UnicodeChar character;
	Utf16Char utf16Character;

	//Convert an empty character
	utf16Character = (Utf16Char)character;

	CPPUNIT_ASSERT(utf16Character.size() == 0);

	//Convert a character containing a UTF-8 string
	character = utf8String[0];

	utf16Character = (Utf16Char)character;

	CPPUNIT_ASSERT(utf16Character == utf16String[0]);

	//Convert a character containing a UTF-16 string
	character = utf16String[6];

	utf16Character = (Utf16Char)character;

	CPPUNIT_ASSERT(utf16Character == utf16String[6]);
}

/*Private Helper Functions*/

