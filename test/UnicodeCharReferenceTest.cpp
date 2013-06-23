/*!
\file UnicodeCharReferenceTest.cpp

This file contains the definition of the UnicodeCharReferenceTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <string>

#include "UnicodeCharReferenceTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void UnicodeCharReferenceTest::TestAssignmentOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a Unicode string that contains a UTF-8 string
	UnicodeString unicodeUtf8String = utf8String;
	//Create a Unicode string that contains a UTF-16 string
	UnicodeString unicodeUtf16String = utf16String;

	//Test the = operator that accepts a UnicodeCharReference
	//Assign a UnicodeCharReference containing a UTF-8 character reference to a UnicodeCharReference containing a 
	//UTF-8 character reference
	UnicodeCharReference firstCharacterReference = unicodeUtf8String[3];
	UnicodeCharReference secondCharacterReference = unicodeUtf8String[0];

	firstCharacterReference = secondCharacterReference;
	CPPUNIT_ASSERT(secondCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x0053");
	CPPUNIT_ASSERT(unicodeUtf8String[3] == L"\x0053");

	//Assign a UnicodeCharReference containing a UTF-8 character reference to a UnicodeCharReference containing a 
	//UTF-16 character
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[3]);
	secondCharacterReference.assign_reference(unicodeUtf8String[0]);

	firstCharacterReference = secondCharacterReference;
	CPPUNIT_ASSERT(secondCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x0053");
	CPPUNIT_ASSERT(unicodeUtf16String[3] == L"\x0053");

	//Assign a UnicodeCharReference containing a UTF-16 character reference to a UnicodeCharReference containing a 
	//UTF-8 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf8String[3]);
	secondCharacterReference.assign_reference(unicodeUtf16String[0]);

	firstCharacterReference = secondCharacterReference;
	CPPUNIT_ASSERT(secondCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x0053");
	CPPUNIT_ASSERT(unicodeUtf8String[3] == L"\x0053");

	//Assign a UnicodeCharReference containing a UTF-16 character reference to a UnicodeCharReference containing a 
	//UTF-16 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[3]);
	secondCharacterReference.assign_reference(unicodeUtf16String[0]);

	firstCharacterReference = secondCharacterReference;
	CPPUNIT_ASSERT(secondCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x0053");
	CPPUNIT_ASSERT(unicodeUtf16String[3] == L"\x0053");


	//Test the = operator that accepts a Utf8CharReference
	//Assign a Utf8CharReference to a UnicodeCharReference containing a UTF-8 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf8String[0]);
	Utf8CharReference utf8CharacterReference = utf8String[1];

	firstCharacterReference = utf8CharacterReference;
	CPPUNIT_ASSERT(firstCharacterReference == utf8CharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x1EAB");
	CPPUNIT_ASSERT(unicodeUtf8String[0] == L"\x1EAB");

	//Assign a Utf8CharReference to a UnicodeCharReference containing a UTF-16 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[0]);
	utf8CharacterReference.assign_reference(utf8String[1]);

	firstCharacterReference = utf8CharacterReference;
	CPPUNIT_ASSERT(firstCharacterReference == utf8CharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x1EAB");
	CPPUNIT_ASSERT(unicodeUtf16String[0] == L"\x1EAB");


	//Test the = operator that accepts a Utf16CharReference
	//Assign a Utf16CharReference to a UnicodeCharReference containing a UTF-8 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf8String[0]);
	Utf16CharReference utf16CharacterReference = utf16String[1];

	firstCharacterReference = utf16CharacterReference;
	CPPUNIT_ASSERT(firstCharacterReference == utf16CharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x1EAB");
	CPPUNIT_ASSERT(unicodeUtf8String[0] == L"\x1EAB");

	//Assign a Utf16CharReference to a UnicodeCharReference containing a UTF-16 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[0]);
	utf16CharacterReference.assign_reference(utf16String[1]);

	firstCharacterReference = utf16CharacterReference;
	CPPUNIT_ASSERT(firstCharacterReference == utf16CharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x1EAB");
	CPPUNIT_ASSERT(unicodeUtf16String[0] == L"\x1EAB");


	//Test the = operator that accepts a UnicodeChar
	//Assign a UnicodeChar containing a UTF-8 character to a UnicodeCharReference containing a 
	//UTF-8 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf8String[0]);
	UnicodeChar unicodeChar = "ẫ";

	firstCharacterReference = unicodeChar;
	CPPUNIT_ASSERT(unicodeChar == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == "ẫ");
	CPPUNIT_ASSERT(unicodeUtf8String[0] == "ẫ");

	//Assign a UnicodeChar containing a UTF-8 character to a UnicodeCharReference containing a 
	//UTF-16 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[0]);
	unicodeChar = "ẫ";

	firstCharacterReference = unicodeChar;
	CPPUNIT_ASSERT(unicodeChar == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == "ẫ");
	CPPUNIT_ASSERT(unicodeUtf16String[0] == "ẫ");

	//Assign a UnicodeChar containing a UTF-16 character to a UnicodeCharReference containing a 
	//UTF-8 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf8String[0]);
	unicodeChar = L"\x1EAB";

	firstCharacterReference = unicodeChar;
	CPPUNIT_ASSERT(unicodeChar == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x1EAB");
	CPPUNIT_ASSERT(unicodeUtf8String[0] == L"\x1EAB");

	//Assign a UnicodeChar containing a UTF-16 character to a UnicodeCharReference containing a 
	//UTF-16 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[0]);
	unicodeChar = L"\x1EAB";

	firstCharacterReference = unicodeChar;
	CPPUNIT_ASSERT(unicodeChar == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == L"\x1EAB");
	CPPUNIT_ASSERT(unicodeUtf16String[0] == L"\x1EAB");


	//Test the = operator that accepts a Utf8Char
	//Assign a Utf8Char to a UnicodeCharReference containing a UTF-8 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf8String[1]);
	Utf8Char utf8Character = "\xF0\x92\x81\xA8";

	firstCharacterReference = utf8Character;
	CPPUNIT_ASSERT(firstCharacterReference == utf8Character);
	CPPUNIT_ASSERT(firstCharacterReference == "\xF0\x92\x81\xA8");
	CPPUNIT_ASSERT(unicodeUtf8String[1] == "\xF0\x92\x81\xA8");

	//Assign a Utf8Char to a UnicodeCharReference containing a UTF-16 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[1]);
	utf8Character = "\xF0\x92\x81\xA8";

	firstCharacterReference = utf8Character;
	CPPUNIT_ASSERT(firstCharacterReference == utf8Character);
	CPPUNIT_ASSERT(firstCharacterReference == "\xF0\x92\x81\xA8");
	CPPUNIT_ASSERT(unicodeUtf16String[1] == "\xF0\x92\x81\xA8");


	//Test the = operator that accepts a Utf8Char
	//Assign a Utf8Char to a UnicodeCharReference containing a UTF-8 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf8String[1]);
	Utf16Char utf16Character = L"\xD808\xDC68";

	firstCharacterReference = utf16Character;
	CPPUNIT_ASSERT(firstCharacterReference == utf16Character);
	CPPUNIT_ASSERT(firstCharacterReference == L"\xD808\xDC68");
	CPPUNIT_ASSERT(unicodeUtf8String[1] == L"\xD808\xDC68");

	//Assign a Utf8Char to a UnicodeCharReference containing a UTF-16 character reference
	unicodeUtf8String = utf8String;
	unicodeUtf16String = utf16String;

	firstCharacterReference.assign_reference(unicodeUtf16String[1]);
	utf16Character = L"\xD808\xDC68";

	firstCharacterReference = utf16Character;
	CPPUNIT_ASSERT(firstCharacterReference == utf16Character);
	CPPUNIT_ASSERT(firstCharacterReference == L"\xD808\xDC68");
	CPPUNIT_ASSERT(unicodeUtf16String[1] == L"\xD808\xDC68");
}

void UnicodeCharReferenceTest::TestAssignReference()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	UnicodeString unicodeString;

	//Test references to a UTF-8 string
	UnicodeCharReference characterReference = utf8String[0];

	characterReference.assign_reference(utf8String[4]);
	CPPUNIT_ASSERT(characterReference == utf8String[4]);
	
	characterReference.assign_reference(utf8String[9]);
	CPPUNIT_ASSERT(characterReference == utf8String[9]);

	characterReference.assign_reference(utf8String[5]);
	CPPUNIT_ASSERT(characterReference == utf8String[5]);

	characterReference.assign_reference(utf8String[1]);
	CPPUNIT_ASSERT(characterReference == utf8String[1]);

	//Do the same thing using a UnicodeString containing a UTF-8 string
	unicodeString = utf8String;

	characterReference.assign_reference(unicodeString[4]);
	CPPUNIT_ASSERT(characterReference == unicodeString[4]);
	
	characterReference.assign_reference(unicodeString[9]);
	CPPUNIT_ASSERT(characterReference == unicodeString[9]);

	characterReference.assign_reference(unicodeString[5]);
	CPPUNIT_ASSERT(characterReference == unicodeString[5]);

	characterReference.assign_reference(unicodeString[1]);
	CPPUNIT_ASSERT(characterReference == unicodeString[1]);

	//Test references to a UTF-16 string
	characterReference.assign_reference(utf16String[4]);
	CPPUNIT_ASSERT(characterReference == utf16String[4]);
	
	characterReference.assign_reference(utf16String[9]);
	CPPUNIT_ASSERT(characterReference == utf16String[9]);

	characterReference.assign_reference(utf16String[3]);
	CPPUNIT_ASSERT(characterReference == utf16String[3]);

	characterReference.assign_reference(utf16String[1]);
	CPPUNIT_ASSERT(characterReference == utf16String[1]);

	//Do the same thing using a UnicodeString containing a UTF-16 string
	unicodeString = utf16String;

	characterReference.assign_reference(unicodeString[4]);
	CPPUNIT_ASSERT(characterReference == unicodeString[4]);
	
	characterReference.assign_reference(unicodeString[9]);
	CPPUNIT_ASSERT(characterReference == unicodeString[9]);

	characterReference.assign_reference(unicodeString[5]);
	CPPUNIT_ASSERT(characterReference == unicodeString[5]);

	characterReference.assign_reference(unicodeString[1]);
	CPPUNIT_ASSERT(characterReference == unicodeString[1]);
}

void UnicodeCharReferenceTest::TestConstructors()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a Unicode string
	UnicodeString unicodeString = utf16String;

	//Test the constructor that accepts a UnicodeCharReference
	UnicodeCharReference* unicodeCharacterReference = new UnicodeCharReference(unicodeString[3]);

	//Verify the results
	CPPUNIT_ASSERT(unicodeCharacterReference->is_valid());
	CPPUNIT_ASSERT(*unicodeCharacterReference == L"\xD808\xDC68");

	delete unicodeCharacterReference;
	unicodeCharacterReference = NULL;

	//Test the constructor that accepts a Utf8CharReference
	unicodeCharacterReference = new UnicodeCharReference(utf8String[3]);

	//Verify the results
	CPPUNIT_ASSERT(unicodeCharacterReference->is_valid());
	CPPUNIT_ASSERT(*unicodeCharacterReference == L"\xD808\xDC68");

	delete unicodeCharacterReference;
	unicodeCharacterReference = NULL;

	//Test the constructor that accepts a Utf16CharReference
	unicodeCharacterReference = new UnicodeCharReference(utf16String[3]);

	//Verify the results
	CPPUNIT_ASSERT(unicodeCharacterReference->is_valid());
	CPPUNIT_ASSERT(*unicodeCharacterReference == L"\xD808\xDC68");

	delete unicodeCharacterReference;
	unicodeCharacterReference = NULL;
}

void UnicodeCharReferenceTest::TestEqualsOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Test the != operator that accepts another UnicodeCharReference
	//Compare a UnicodeCharReference referring to a UTF-8 character to a UnicodeCharReference referring to a UTF-8 character
	UnicodeCharReference firstCharacterReference = utf8String[1];
	UnicodeCharReference secondCharacterReference = utf8String[7];

	CPPUNIT_ASSERT(secondCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == secondCharacterReference);

	secondCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!(secondCharacterReference == firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == secondCharacterReference));

	//Compare a UnicodeCharReference referring to a UTF-8 character to a UnicodeCharReference referring to a UTF-16 character
	//and vice versa
	firstCharacterReference.assign_reference(utf16String[3]);
	secondCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(secondCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == secondCharacterReference);

	secondCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!(secondCharacterReference == firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == secondCharacterReference));

	//Assign a UnicodeCharReference referring to a UTF-16 character to a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	secondCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(secondCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == secondCharacterReference);

	firstCharacterReference.assign_reference(utf16String[1]);

	CPPUNIT_ASSERT(!(secondCharacterReference == firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == secondCharacterReference));

	//Test the == operator that accepts a Utf8CharReference
	//Compare a Utf8CharReference to a UnicodeCharReference referring to a UTF-8 character
	Utf8CharReference utf8CharacterReference = utf8String[0];
	firstCharacterReference.assign_reference(utf8String[0]);

	CPPUNIT_ASSERT(utf8CharacterReference == (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf8CharacterReference);

	firstCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!(utf8CharacterReference == (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf8CharacterReference));

	//Compare a Utf8CharReference to a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(utf8CharacterReference == (Utf16CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf8CharacterReference);

	firstCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!(utf8CharacterReference == (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf8CharacterReference));

	//Test the == operator that accepts a Utf16CharReference
	//Compare a Utf16CharReference to a UnicodeCharReference referring to a UTF-8 character
	Utf16CharReference utf16CharacterReference = utf16String[0];
	firstCharacterReference.assign_reference(utf8String[0]);

	CPPUNIT_ASSERT(utf16CharacterReference == (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf16CharacterReference);

	firstCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(!(utf16CharacterReference == (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf16CharacterReference));

	//Compare a Utf16CharReference to a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(utf16CharacterReference == (Utf16CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf16CharacterReference);

	firstCharacterReference.assign_reference(utf16String[5]);

	CPPUNIT_ASSERT(!(utf16CharacterReference == (Utf16CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf16CharacterReference));

	//Test the == operator that accepts a UnicodeCharReference
	//Compare a UnicodeCharReference containing a UTF-8 character reference with
	//a UnicodeChar containing a UTF-8 character

	//Test when the two references are referring to the same character value,
	//but not the exact same character
	firstCharacterReference.assign_reference(utf8String[1]);
	UnicodeCharReference unicodeCharacterReference = utf8String[7];

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == unicodeCharacterReference);

	//Test when the two references are referring to the exact same character
	unicodeCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == unicodeCharacterReference);

	firstCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == unicodeCharacterReference));

	//Compare a UnicodeCharReference referring to a UTF-8 character reference with
	//a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	unicodeCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == unicodeCharacterReference);

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == unicodeCharacterReference));

	//Compare a UnicodeCharReference referring to a UTF-16 character reference with
	//a UnicodeCharReference referring to a UTF-8 character
	firstCharacterReference.assign_reference(utf8String[3]);
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == unicodeCharacterReference);

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == unicodeCharacterReference));

	//Compare a UnicodeCharReference referring to a UTF-16 character reference with
	//a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(unicodeCharacterReference == firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == unicodeCharacterReference);

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference == firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == unicodeCharacterReference));

	//Test the == operator that accepts a Utf8CharReference
	//Compare a Utf8CharReference with a UnicodeCharReference referring to a UTF-8 character
	firstCharacterReference.assign_reference(utf8String[3]);
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(utf8CharacterReference == (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf8CharacterReference);

	firstCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(!(utf8CharacterReference == (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf8CharacterReference));

	//Compare a Utf8CharReference with a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(utf8CharacterReference == (Utf16CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf8CharacterReference);

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(!(utf8CharacterReference == (Utf16CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf8CharacterReference));

	//Test the == operator that accepts a Utf16CharReference
	//Compare a Utf16CharReference with a UnicodeCharReference referring to a UTF-8 character
	firstCharacterReference.assign_reference(utf8String[3]);
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(utf16CharacterReference == (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf16CharacterReference);

	firstCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(!(utf16CharacterReference == (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf16CharacterReference));

	//Compare a Utf16CharReference with a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(utf16CharacterReference == (Utf16CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference == utf16CharacterReference);

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(!(utf16CharacterReference == (Utf16CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference == utf16CharacterReference));
}

void UnicodeCharReferenceTest::TestInternalEncoding()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Assign a UTF-8 character reference and test
	UnicodeCharReference characterReference = utf8String[0];
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF8);
	
	characterReference.assign_reference(utf8String[1]);
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF8);

	characterReference.assign_reference(utf8String[3]);
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF8);

	characterReference.assign_reference(utf8String[5]);
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF8);

	//Assign a UTF-16 character reference and test
	characterReference.assign_reference(utf16String[0]);
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF16);
	
	characterReference.assign_reference(utf16String[1]);
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF16);

	characterReference.assign_reference(utf16String[3]);
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF16);

	characterReference.assign_reference(utf16String[5]);
	CPPUNIT_ASSERT(characterReference.internal_encoding() == ENCODING_UTF16);
}

void UnicodeCharReferenceTest::TestIsValid()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x11\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\x1C68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Test a character reference referring to a valid UTF-8 character
	UnicodeCharReference characterReference = utf8String[1];

	CPPUNIT_ASSERT(characterReference.is_valid());

	//Test a character with an invalid UTF-8 character
	characterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!characterReference.is_valid());

	//Test a character with a valid UTF-16 character
	characterReference.assign_reference(utf16String[1]);

	CPPUNIT_ASSERT(characterReference.is_valid());

	//Test a character with an invalid UTF-16 character
	characterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!characterReference.is_valid());
}

void UnicodeCharReferenceTest::TestNotEqualsOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Test the == operator that accepts another UnicodeCharReference
	//Compare a UnicodeCharReference referring to a UTF-8 character to a UnicodeCharReference referring to a UTF-8 character
	UnicodeCharReference firstCharacterReference = utf8String[1];
	UnicodeCharReference secondCharacterReference = utf8String[7];

	CPPUNIT_ASSERT(!(secondCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != secondCharacterReference));

	secondCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(secondCharacterReference != firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != secondCharacterReference);

	//Compare a UnicodeCharReference referring to a UTF-8 character to a UnicodeCharReference referring to a UTF-16 character
	//and vice versa
	firstCharacterReference.assign_reference(utf16String[3]);
	secondCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(secondCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != secondCharacterReference));

	secondCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(secondCharacterReference != firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != secondCharacterReference);

	//Assign a UnicodeCharReference referring to a UTF-16 character to a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	secondCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(secondCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != secondCharacterReference));

	firstCharacterReference.assign_reference(utf16String[1]);

	CPPUNIT_ASSERT(secondCharacterReference != firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != secondCharacterReference);

	//Test the == operator that accepts a Utf8CharReference
	//Compare a Utf8CharReference to a UnicodeCharReference referring to a UTF-8 character
	Utf8CharReference utf8CharacterReference = utf8String[0];
	firstCharacterReference.assign_reference(utf8String[0]);

	CPPUNIT_ASSERT(!(utf8CharacterReference != (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf8CharacterReference));

	firstCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(utf8CharacterReference != (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf8CharacterReference);

	//Compare a Utf8CharReference to a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(utf8CharacterReference != (Utf16CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf8CharacterReference));

	firstCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(utf8CharacterReference != (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf8CharacterReference);

	//Test the == operator that accepts a Utf16CharReference
	//Compare a Utf16CharReference to a UnicodeCharReference referring to a UTF-8 character
	Utf16CharReference utf16CharacterReference = utf16String[0];
	firstCharacterReference.assign_reference(utf8String[0]);

	CPPUNIT_ASSERT(!(utf16CharacterReference != (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf16CharacterReference));

	firstCharacterReference.assign_reference(utf8String[5]);

	CPPUNIT_ASSERT(utf16CharacterReference != (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf16CharacterReference);

	//Compare a Utf16CharReference to a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(utf16CharacterReference != (Utf16CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf16CharacterReference));

	firstCharacterReference.assign_reference(utf16String[5]);

	CPPUNIT_ASSERT(utf16CharacterReference != (Utf16CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf16CharacterReference);

	//Test the == operator that accepts a UnicodeCharReference
	//Compare a UnicodeCharReference containing a UTF-8 character reference with
	//a UnicodeChar containing a UTF-8 character

	//Test when the two references are referring to the same character value,
	//but not the exact same character
	firstCharacterReference.assign_reference(utf8String[1]);
	UnicodeCharReference unicodeCharacterReference = utf8String[7];

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != unicodeCharacterReference));

	//Test when the two references are referring to the exact same character
	unicodeCharacterReference.assign_reference(utf8String[1]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != unicodeCharacterReference));

	firstCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != unicodeCharacterReference);

	//Compare a UnicodeCharReference referring to a UTF-8 character reference with
	//a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	unicodeCharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != unicodeCharacterReference));

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != unicodeCharacterReference);

	//Compare a UnicodeCharReference referring to a UTF-16 character reference with
	//a UnicodeCharReference referring to a UTF-8 character
	firstCharacterReference.assign_reference(utf8String[3]);
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != unicodeCharacterReference));

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != unicodeCharacterReference);

	//Compare a UnicodeCharReference referring to a UTF-16 character reference with
	//a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	unicodeCharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(unicodeCharacterReference != firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != unicodeCharacterReference));

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(unicodeCharacterReference != firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != unicodeCharacterReference);

	//Test the == operator that accepts a Utf8CharReference
	//Compare a Utf8CharReference with a UnicodeCharReference referring to a UTF-8 character
	firstCharacterReference.assign_reference(utf8String[3]);
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(utf8CharacterReference != (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf8CharacterReference));

	firstCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(utf8CharacterReference != (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf8CharacterReference);

	//Compare a Utf8CharReference with a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf8CharacterReference.assign_reference(utf8String[3]);

	CPPUNIT_ASSERT(!(utf8CharacterReference != (Utf16CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf8CharacterReference));

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(utf8CharacterReference != (Utf16CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf8CharacterReference);

	//Test the == operator that accepts a Utf16CharReference
	//Compare a Utf16CharReference with a UnicodeCharReference referring to a UTF-8 character
	firstCharacterReference.assign_reference(utf8String[3]);
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(utf16CharacterReference != (Utf8CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf16CharacterReference));

	firstCharacterReference.assign_reference(utf8String[2]);

	CPPUNIT_ASSERT(utf16CharacterReference != (Utf8CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf16CharacterReference);

	//Compare a Utf16CharReference with a UnicodeCharReference referring to a UTF-16 character
	firstCharacterReference.assign_reference(utf16String[3]);
	utf16CharacterReference.assign_reference(utf16String[3]);

	CPPUNIT_ASSERT(!(utf16CharacterReference != (Utf16CharReference)firstCharacterReference));
	CPPUNIT_ASSERT(!(firstCharacterReference != utf16CharacterReference));

	firstCharacterReference.assign_reference(utf16String[2]);

	CPPUNIT_ASSERT(utf16CharacterReference != (Utf16CharReference)firstCharacterReference);
	CPPUNIT_ASSERT(firstCharacterReference != utf16CharacterReference);
}

void UnicodeCharReferenceTest::TestReferenceEqual()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xF0\x92\x81\xA8\x53\xE1\xBA\xAB\xC3\x9F\xE2\x88\x91\xF0\x90\x8D\x86\xE1\xBA\xAB\x62\xD0\xB4";
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	UnicodeString unicodeString;

	//Test using references to a UTF-8 string
	//Character references point to same one-code-unit characters
	UnicodeCharReference characterReference = utf8String[0];
	UnicodeCharReference otherCharacterReference = utf8String[0];

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


	//Do the same thing using a UnicodeString containing a UTF-8 string
	//Character references point to same one-code-unit characters
	unicodeString = utf8String;

	characterReference.assign_reference(unicodeString[0]);
	otherCharacterReference.assign_reference(unicodeString[0]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(unicodeString[0]);
	otherCharacterReference.assign_reference(unicodeString[2]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different one-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[0]);
	otherCharacterReference.assign_reference(unicodeString[8]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(unicodeString[5]);
	otherCharacterReference.assign_reference(unicodeString[5]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(unicodeString[4]);
	otherCharacterReference.assign_reference(unicodeString[5]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different two-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[5]);
	otherCharacterReference.assign_reference(unicodeString[10]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same three-code-unit characters
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[1]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different three-code-unit characters
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[11]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different three-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[9]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same four-code-unit characters
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[3]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different four-code-unit characters
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[12]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to different four-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[7]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));


	//Test using references to a UTF-16 string
	//Character references point to same one-code-unit characters
	characterReference.assign_reference(utf16String[1]);
	otherCharacterReference.assign_reference(utf16String[1]);

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


	//Do the same thing using a UnicodeString containing a UTF-16 string
	//Character references point to same one-code-unit characters
	unicodeString = utf16String;

	//Character references point to same one-code-unit characters
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[1]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(unicodeString[4]);
	otherCharacterReference.assign_reference(unicodeString[5]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to difference one-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[7]);
	otherCharacterReference.assign_reference(unicodeString[1]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(unicodeString[9]);
	otherCharacterReference.assign_reference(unicodeString[9]);

	CPPUNIT_ASSERT(characterReference.reference_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[9]);

	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));

	//Character references point to difference two-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[11]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(!characterReference.reference_equal(otherCharacterReference));
}

void UnicodeCharReferenceTest::TestReferenceNotEqual()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xF0\x92\x81\xA8\x53\xE1\xBA\xAB\xC3\x9F\xE2\x88\x91\xF0\x90\x8D\x86\xE1\xBA\xAB\x62\xD0\xB4";
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	UnicodeString unicodeString;

	//Test using references to a UTF-8 string
	//Character references point to same one-code-unit characters
	UnicodeCharReference characterReference = utf8String[0];
	UnicodeCharReference otherCharacterReference = utf8String[0];

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


	//Do the same thing using a UnicodeString containing a UTF-8 string
	//Character references point to same one-code-unit characters
	unicodeString = utf8String;

	characterReference.assign_reference(unicodeString[0]);
	otherCharacterReference.assign_reference(unicodeString[0]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(unicodeString[0]);
	otherCharacterReference.assign_reference(unicodeString[2]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different one-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[0]);
	otherCharacterReference.assign_reference(unicodeString[8]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(unicodeString[5]);
	otherCharacterReference.assign_reference(unicodeString[5]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(unicodeString[4]);
	otherCharacterReference.assign_reference(unicodeString[5]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different two-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[5]);
	otherCharacterReference.assign_reference(unicodeString[10]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same three-code-unit characters
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[1]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different three-code-unit characters
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[11]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different three-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[9]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same four-code-unit characters
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[3]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different four-code-unit characters
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[12]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to different four-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[7]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));


	//Test using references to a UTF-16 string
	//Character references point to same one-code-unit characters
	characterReference.assign_reference(utf16String[1]);
	otherCharacterReference.assign_reference(utf16String[1]);

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


	//Do the same thing using a UnicodeString containing a UTF-16 string
	//Character references point to same one-code-unit characters
	unicodeString = utf16String;

	//Character references point to same one-code-unit characters
	characterReference.assign_reference(unicodeString[1]);
	otherCharacterReference.assign_reference(unicodeString[1]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different one-code-unit characters
	characterReference.assign_reference(unicodeString[4]);
	otherCharacterReference.assign_reference(unicodeString[5]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to difference one-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[7]);
	otherCharacterReference.assign_reference(unicodeString[1]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to same two-code-unit characters
	characterReference.assign_reference(unicodeString[9]);
	otherCharacterReference.assign_reference(unicodeString[9]);

	CPPUNIT_ASSERT(!characterReference.reference_not_equal(otherCharacterReference));
	
	//Character references point to different two-code-unit characters
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[9]);

	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));

	//Character references point to difference two-code-unit characters with the same values
	characterReference.assign_reference(unicodeString[3]);
	otherCharacterReference.assign_reference(unicodeString[11]);

	CPPUNIT_ASSERT(characterReference == otherCharacterReference);
	CPPUNIT_ASSERT(characterReference.reference_not_equal(otherCharacterReference));
}

void UnicodeCharReferenceTest::TestToUtf32()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Decode references to UTF-8 characters
	UnicodeCharReference characterReference = utf8String[1];
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[0]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[5]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[3]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[9]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, characterReference.to_utf_32());

	//Decode references to UTF-8 characters
	characterReference.assign_reference(utf8String[1]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[0]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[5]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[3]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, characterReference.to_utf_32());

	characterReference.assign_reference(utf8String[9]);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, characterReference.to_utf_32());
}

void UnicodeCharReferenceTest::TestUnicodeCharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	UnicodeChar character;

	//Convert references to UTF-8 characters
	UnicodeCharReference characterReference = utf8String[0];
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, character.to_utf_32());

	characterReference.assign_reference(utf8String[1]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	characterReference.assign_reference(utf8String[5]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, character.to_utf_32());

	characterReference.assign_reference(utf8String[3]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	characterReference.assign_reference(utf8String[9]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());

	//Convert references to UTF-16 characters
	characterReference.assign_reference(utf16String[0]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, character.to_utf_32());

	characterReference.assign_reference(utf16String[1]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	characterReference.assign_reference(utf16String[5]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, character.to_utf_32());

	characterReference.assign_reference(utf16String[3]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	characterReference.assign_reference(utf16String[9]);
	character = (UnicodeChar)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());
}

void UnicodeCharReferenceTest::TestUtf8CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	Utf8Char character;

	//Convert references to UTF-8 characters
	UnicodeCharReference characterReference = utf8String[0];
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, character.to_utf_32());

	characterReference.assign_reference(utf8String[1]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	characterReference.assign_reference(utf8String[5]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, character.to_utf_32());

	characterReference.assign_reference(utf8String[3]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	characterReference.assign_reference(utf8String[9]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());

	//Convert references to UTF-16 characters
	characterReference.assign_reference(utf16String[0]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, character.to_utf_32());

	characterReference.assign_reference(utf16String[1]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	characterReference.assign_reference(utf16String[5]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, character.to_utf_32());

	characterReference.assign_reference(utf16String[3]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	characterReference.assign_reference(utf16String[9]);
	character = (Utf8Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());
}

void UnicodeCharReferenceTest::TestUtf16CharConversionOperator()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	Utf16Char character;

	//Convert references to UTF-8 characters
	UnicodeCharReference characterReference = utf8String[0];
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, character.to_utf_32());

	characterReference.assign_reference(utf8String[1]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	characterReference.assign_reference(utf8String[5]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, character.to_utf_32());

	characterReference.assign_reference(utf8String[3]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	characterReference.assign_reference(utf8String[9]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());

	//Convert references to UTF-16 characters
	characterReference.assign_reference(utf16String[0]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, character.to_utf_32());

	characterReference.assign_reference(utf16String[1]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, character.to_utf_32());

	characterReference.assign_reference(utf16String[5]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, character.to_utf_32());

	characterReference.assign_reference(utf16String[3]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, character.to_utf_32());

	characterReference.assign_reference(utf16String[9]);
	character = (Utf16Char)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, character.to_utf_32());
}

void UnicodeCharReferenceTest::TestUtf8CharReferenceConversionOperator()
{
	//Create a UnicodeString containing a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д");

	//Convert references to UTF-8 character references
	UnicodeCharReference characterReference = unicodeString[0];
	Utf8CharReference utf8CharacterReference = (Utf8CharReference)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, utf8CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[1]);
	utf8CharacterReference.assign_reference((Utf8CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, utf8CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[5]);
	utf8CharacterReference.assign_reference((Utf8CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, utf8CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[3]);
	utf8CharacterReference.assign_reference((Utf8CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, utf8CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[9]);
	utf8CharacterReference.assign_reference((Utf8CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, utf8CharacterReference.to_utf_32());
}

void UnicodeCharReferenceTest::TestUtf16CharReferenceConversionOperator()
{
	//Create a UnicodeString containing a UTF-16 string
	UnicodeString unicodeString = Utf16String(L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");

	//Convert references to UTF-16 characters
	UnicodeCharReference characterReference = unicodeString[0];
	Utf16CharReference utf16CharacterReference = (Utf16CharReference)characterReference;
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000053, utf16CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[1]);
	utf16CharacterReference.assign_reference((Utf16CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, utf16CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[5]);
	utf16CharacterReference.assign_reference((Utf16CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000DF, utf16CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[3]);
	utf16CharacterReference.assign_reference((Utf16CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, utf16CharacterReference.to_utf_32());

	characterReference.assign_reference(unicodeString[9]);
	utf16CharacterReference.assign_reference((Utf16CharReference)characterReference);
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, utf16CharacterReference.to_utf_32());
}

/*Private Helper Functions*/

