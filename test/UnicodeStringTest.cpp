/*!
\file UnicodeStringTest.cpp

This file contains the definition of the UnicodeStringTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <sstream>
#include <string>

#include "UnicodeStringTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void UnicodeStringTest::TestAppend()
{
	//Test the append functionality with a strings composed of 1-, 2-, and 3-byte UTF-8 characters,
	//and single-code-unit UTF-16 characters
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create a UnicodeString that will be appended to
	UnicodeString originalString = Utf8String("∑Sbö");
	//Create the UnicodeString that results from an append operation
	UnicodeString finalString = Utf8String("∑SböSẫböß3ẫ∑д");
	//Create the UnicodeString that results from a character append operation
	UnicodeString finalCharacterString = Utf8String("∑Sbö∑");

	//Test the append() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	UnicodeString appendedString = originalString;
	appendedString.append(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test with the UnicodeString containing a UTF-16 string
	appendedString = originalString;
	appendedString.append(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf8String
	appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf16String
	appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UnicodeChar
	appendedString = originalString;
	appendedString.append(originalString[0]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, appendedString);

	//Repeat the same tests with the UnicodeString objects initialized with UTF-16 strings
	//Create a UnicodeString that will be appended to
	originalString = Utf16String("∑Sbö");
	//Create the UnicodeString that results from an append operation
	finalString = Utf16String("∑SböSẫböß3ẫ∑д");
	//Create the UnicodeString that results from a character append operation
	finalCharacterString = Utf16String("∑Sbö∑");

	//Test the append() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	appendedString = originalString;
	appendedString.append(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test with the UnicodeString containing a UTF-16 string
	appendedString = originalString;
	appendedString.append(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf8String
	appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf16String
	appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UnicodeChar
	appendedString = originalString;
	appendedString.append(originalString[0]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, appendedString);


	//Test the append functionality with a strings composed of 1-, 2-, 3-, and 4-byte UTF-8 characters,
	//and multi-code-unit UTF-16 characters
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a UTF-8 string containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UnicodeString that will be appended to
	originalString = Utf8String("ẫ∑\xF0\x90\x8D\x86");
	//Create the UnicodeString that results from an append operation
	finalString = Utf8String("ẫ∑\xF0\x90\x8D\x86\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д");
	//Create the UnicodeString that results from a character append operation
	finalCharacterString = Utf8String("ẫ∑\xF0\x90\x8D\x86\xF0\x90\x8D\x86");

	//Test the append() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	appendedString = originalString;
	appendedString.append(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test with the UnicodeString containing a UTF-16 string
	appendedString = originalString;
	appendedString.append(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf8String
	appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf16String
	appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UnicodeChar
	appendedString = originalString;
	appendedString.append(originalString[2]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, appendedString);

	//Repeat the same tests with the UnicodeString objects initialized with UTF-16 strings
	//Create a UnicodeString that will be appended to
	originalString = Utf16String("ẫ∑\xF0\x90\x8D\x86");
	//Create the UnicodeString that results from an append operation
	finalString = Utf16String("ẫ∑\xF0\x90\x8D\x86\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д");
	//Create the UnicodeString that results from a character append operation
	finalCharacterString = Utf16String("ẫ∑\xF0\x90\x8D\x86\xF0\x90\x8D\x86");

	//Test the append() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	appendedString = originalString;
	appendedString.append(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test with the UnicodeString containing a UTF-16 string
	appendedString = originalString;
	appendedString.append(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf8String
	appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf16String
	appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UnicodeChar
	appendedString = originalString;
	appendedString.append(originalString[2]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, appendedString);

	//Test appending characters with different numbers of code units
	//Test with UTF-8 characters
	//Create a UnicodeString string that will be the result of appending a one-code-unit UTF-8 character
	UnicodeString oneCodeUnitFinalString = Utf8String("ẫ∑\xF0\x90\x8D\x86\x53");
	//Create a UnicodeString string that will be the result of appending a two-code-unit UTF-8 character
	UnicodeString twoCodeUnitFinalString = Utf8String("ẫ∑\xF0\x90\x8D\x86ö");
	//Create a UnicodeString string that will be the result of appending a three-code-unit UTF-8 character
	UnicodeString threeCodeUnitFinalString = Utf8String("ẫ∑\xF0\x90\x8D\x86ẫ");
	//Create a UnicodeString string that will be the result of appending a four-code-unit UTF-8 character
	UnicodeString fourCodeUnitFinalString = Utf8String("ẫ∑\xF0\x90\x8D\x86\xF0\x92\x81\xA8");

	//Append a one-code-unit UTF-8 character
	appendedString = originalString;
	appendedString.append(utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, appendedString);

	//Append a two-code-unit UTF-8 character
	appendedString = originalString;
	appendedString.append(utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, appendedString);

	//Append a three-code-unit UTF-8 character
	appendedString = originalString;
	appendedString.append(utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitFinalString, appendedString);

	//Append a four-code-unit UTF-8 character
	appendedString = originalString;
	appendedString.append(utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitFinalString, appendedString);

	//Test with UTF-16 characters
	//Create a UTF-16 string that will be the result of appending a one-code-unit character
	UnicodeString utf16OneCodeUnitFinalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46\x0053");
	//Create a UTF-16 string that will be the result of appending a two-code-unit character
	UnicodeString utf16TwoCodeUnitFinalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68");

	//Append a one-code-unit character
	appendedString = originalString;
	appendedString.append(utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(utf16OneCodeUnitFinalString, appendedString);

	//Append a two-code-unit character
	appendedString = originalString;
	appendedString.append(utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(utf16TwoCodeUnitFinalString, appendedString);
}

void UnicodeStringTest::TestAssign()
{
	//Test the assign functionality with a strings composed of 1-, 2-, and 3-byte UTF-8 characters,
	//and single-code-unit UTF-16 characters
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create a UnicodeString that will be assigned to
	UnicodeString originalString = Utf8String("∑Sbö");
	//Create the UnicodeString that results from an assign operation
	UnicodeString finalString = Utf8String("Sẫböß3ẫ∑д");
	//Create the UnicodeString that results from a character assign operation
	UnicodeString finalCharacterString = Utf8String("∑");

	//Test the assign() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	UnicodeString assignedString = originalString;
	assignedString.assign(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test with the UnicodeString containing a UTF-16 string
	assignedString = originalString;
	assignedString.assign(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf16String
	assignedString = originalString;
	assignedString.assign(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a UnicodeChar
	assignedString = originalString;
	assignedString.assign(originalString[0]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, assignedString);

	//Repeat the same tests with the UnicodeString objects initialized with UTF-16 strings
	//Create a UnicodeString that will be assigned to
	originalString = Utf16String("∑Sbö");
	//Create the UnicodeString that results from an assign operation
	finalString = Utf16String("Sẫböß3ẫ∑д");
	//Create the UnicodeString that results from a character assign operation
	finalCharacterString = Utf16String("∑");

	//Test the assign() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	assignedString = originalString;
	assignedString.assign(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test with the UnicodeString containing a UTF-16 string
	assignedString = originalString;
	assignedString.assign(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf16String
	assignedString = originalString;
	assignedString.assign(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a UnicodeChar
	assignedString = originalString;
	assignedString.assign(originalString[0]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, assignedString);


	//Test the assign functionality with a strings composed of 1-, 2-, 3-, and 4-byte UTF-8 characters,
	//and multi-code-unit UTF-16 characters
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a UTF-8 string containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UnicodeString that will be assigned to
	originalString = Utf8String("ẫ∑\xF0\x90\x8D\x86");
	//Create the UnicodeString that results from an assign operation
	finalString = Utf8String("\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д");
	//Create the UnicodeString that results from a character assign operation
	finalCharacterString = Utf8String("\xF0\x90\x8D\x86");

	//Test the assign() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	assignedString = originalString;
	assignedString.assign(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test with the UnicodeString containing a UTF-16 string
	assignedString = originalString;
	assignedString.assign(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf16String
	assignedString = originalString;
	assignedString.assign(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a UnicodeChar
	assignedString = originalString;
	assignedString.assign(originalString[2]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, assignedString);

	//Repeat the same tests with the UnicodeString objects initialized with UTF-16 strings
	//Create a UnicodeString that will be assigned to
	originalString = Utf16String("ẫ∑\xF0\x90\x8D\x86");
	//Create the UnicodeString that results from an assign operation
	finalString = Utf16String("\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д");
	//Create the UnicodeString that results from a character assign operation
	finalCharacterString = Utf16String("\xF0\x90\x8D\x86");

	//Test the assign() function that accepts a UnicodeString
	//Test with the UnicodeString containing a UTF-8 string
	assignedString = originalString;
	assignedString.assign(UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test with the UnicodeString containing a UTF-16 string
	assignedString = originalString;
	assignedString.assign(UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a Utf16String
	assignedString = originalString;
	assignedString.assign(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, assignedString);

	//Test the assign() function that accepts a UnicodeChar
	assignedString = originalString;
	assignedString.assign(originalString[2]);

	CPPUNIT_ASSERT_EQUAL(finalCharacterString, assignedString);

	//Test assigning characters with different numbers of code units
	//Test with UTF-8 characters
	//Create a UnicodeString string that will be the result of assigning a one-code-unit UTF-8 character
	UnicodeString oneCodeUnitFinalString = Utf8String("\x53");
	//Create a UnicodeString string that will be the result of assigning a two-code-unit UTF-8 character
	UnicodeString twoCodeUnitFinalString = Utf8String("ö");
	//Create a UnicodeString string that will be the result of assigning a three-code-unit UTF-8 character
	UnicodeString threeCodeUnitFinalString = Utf8String("ẫ");
	//Create a UnicodeString string that will be the result of assigning a four-code-unit UTF-8 character
	UnicodeString fourCodeUnitFinalString = Utf8String("\xF0\x92\x81\xA8");

	//Assign a one-code-unit UTF-8 character
	assignedString = originalString;
	assignedString.assign(utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, assignedString);

	//Assign a two-code-unit UTF-8 character
	assignedString = originalString;
	assignedString.assign(utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, assignedString);

	//Assign a three-code-unit UTF-8 character
	assignedString = originalString;
	assignedString.assign(utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitFinalString, assignedString);

	//assign a four-code-unit UTF-8 character
	assignedString = originalString;
	assignedString.assign(utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitFinalString, assignedString);

	//Test with UTF-16 characters
	//Create a UTF-16 string that will be the result of assigning a one-code-unit character
	UnicodeString utf16OneCodeUnitFinalString = Utf16String(L"\x0053");
	//Create a UTF-16 string that will be the result of assigning a two-code-unit character
	UnicodeString utf16TwoCodeUnitFinalString = Utf16String(L"\xD808\xDC68");

	//Assign a one-code-unit character
	assignedString = originalString;
	assignedString.assign(utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(utf16OneCodeUnitFinalString, assignedString);

	//Assign a two-code-unit character
	assignedString = originalString;
	assignedString.assign(utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(utf16TwoCodeUnitFinalString, assignedString);
}

void UnicodeStringTest::TestAt()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Get a reference to the character at the beginning of the string
	UnicodeCharReference characterReference = unicodeString.at(0);

	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)characterReference).size());
	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)characterReference)[0]);

	//Get a referemce to the character at the end of the string
	characterReference.assign_reference(unicodeString.at(unicodeString.length() - 1));

	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)characterReference).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)characterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)characterReference)[1]);

	//Get a reference to a two-code-unit character in the middle of the string
	characterReference.assign_reference(unicodeString.at(5));

	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)characterReference).size());
	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)characterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)characterReference)[1]);

	//Get a reference to a four-code-unit character in the middle of the string
	characterReference.assign_reference(unicodeString.at(3));

	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)characterReference).size());
	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)characterReference)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)characterReference)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)characterReference)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)characterReference)[3]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a reference to a character just past the end of the string
	CPPUNIT_ASSERT_THROW(unicodeString.at(unicodeString.length()), std::out_of_range);

	//Attempt to get a reference to a character way past the end of the string
	CPPUNIT_ASSERT_THROW(unicodeString.at(unicodeString.length() + 23), std::out_of_range);

	#pragma warning (pop)

	//Repeat the same tests with a constant string
	const UnicodeString constUtf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Get a reference to the character at the beginning of the string
	UnicodeChar character = constUtf8UnicodeString.at(0);

	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)character).size());
	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)character)[0]);

	//Get the character at the end of the string
	character = constUtf8UnicodeString.at(constUtf8UnicodeString.length() - 1);

	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)character).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)character)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)character)[1]);

	//Get a two-code-unit character in the middle of the string
	character = constUtf8UnicodeString.at(5);

	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)character).size());
	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)character)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)character)[1]);

	//Get a four-code-unit character in the middle of the string
	character = constUtf8UnicodeString.at(3);

	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)character).size());
	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)character)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)character)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)character)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)character)[3]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a character just past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf8UnicodeString.at(constUtf8UnicodeString.length()), std::out_of_range);

	//Attempt to get a character way past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf8UnicodeString.at(constUtf8UnicodeString.length() + 23), std::out_of_range);

	#pragma warning (pop)
	
	//Test with a UnicodeString containing a UTF-16 string
	//Create a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Get a reference to the character at the beginning of the string
	characterReference.assign_reference(unicodeString.at(0));

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)characterReference)[0]);

	//Get a reference to the character at the end of the string
	characterReference.assign_reference(unicodeString.at(unicodeString.length() - 1));

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)characterReference)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)characterReference)[1]);

	//Get a reference to a one-code-unit character in the middle of the string
	characterReference.assign_reference(unicodeString.at(5));

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', ((Utf16Char)characterReference)[0]);

	//Get a reference to a two-code-unit character in the middle of the string
	characterReference.assign_reference(unicodeString.at(3));

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)characterReference)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)characterReference)[1]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a reference to a character just past the end of the string
	CPPUNIT_ASSERT_THROW(unicodeString.at(unicodeString.length()), std::out_of_range);

	//Attempt to get a reference to a character way past the end of the string
	CPPUNIT_ASSERT_THROW(unicodeString.at(unicodeString.length() + 23), std::out_of_range);

	#pragma warning (pop)

	//Repeat the same tests with a constant string
	const UnicodeString constUtf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Get the character at the beginning of the string
	character = constUtf16UnicodeString.at(0);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)character)[0]);

	//Get the character at the end of the string
	character = constUtf16UnicodeString.at(constUtf16UnicodeString.length() - 1);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)character)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)character)[1]);

	//Get a one-code-unit character in the middle of the string
	character = constUtf16UnicodeString.at(5);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', ((Utf16Char)character)[0]);

	//Get a two-code-unit character in the middle of the string
	character = constUtf16UnicodeString.at(3);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)character)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)character)[1]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a character just past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf16UnicodeString.at(constUtf16UnicodeString.length()), std::out_of_range);

	//Attempt to get a character way past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf16UnicodeString.at(constUtf16UnicodeString.length() + 23), std::out_of_range);

	#pragma warning (pop)
}

void UnicodeStringTest::TestBegin()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::iterator stringIterator = unicodeString.begin();

	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*stringIterator)[0]);

	unicodeString = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	stringIterator = unicodeString.begin();

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

	//Create a constant UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	const UnicodeString constUtf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::const_iterator constStringIterator = constUtf8UnicodeString.begin();

	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*constStringIterator)[0]);

	const UnicodeString constUtf8UnicodeStringTwo = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	constStringIterator = constUtf8UnicodeStringTwo.begin();

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*constStringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*constStringIterator)[3]);
}

void UnicodeStringTest::TestClear()
{
	UnicodeString unicodeString;

	CPPUNIT_ASSERT(unicodeString.size() == 0);
	CPPUNIT_ASSERT(unicodeString.length() == 0);

	unicodeString.clear();

	CPPUNIT_ASSERT(unicodeString.size() == 0);
	CPPUNIT_ASSERT(unicodeString.length() == 0);

	//Assign a UTF-8 string
	unicodeString = Utf8String("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT(unicodeString.size() == 1);
	CPPUNIT_ASSERT(unicodeString.length() == 1);

	unicodeString.clear();

	CPPUNIT_ASSERT(unicodeString.size() == 0);
	CPPUNIT_ASSERT(unicodeString.length() == 0);

	unicodeString = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	CPPUNIT_ASSERT(unicodeString.size() == 6);
	CPPUNIT_ASSERT(unicodeString.length() == 6);

	unicodeString.clear();

	CPPUNIT_ASSERT(unicodeString.size() == 0);
	CPPUNIT_ASSERT(unicodeString.length() == 0);

	//Assign a UTF-16 string
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	CPPUNIT_ASSERT(unicodeString.size() == 12);
	CPPUNIT_ASSERT(unicodeString.length() == 12);

	unicodeString.clear();
}

void UnicodeStringTest::TestCompare()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create an empty string
	UnicodeString emptyString;
	Utf16String emptyUtf16String;
	Utf8String emptyUtf8String;

	UnicodeString unicodeString;

	//Create a string to do the comparison with
	UnicodeString compareString;

	//Test the compare() function that accepts a Utf16String
	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyUtf16String) == 0);

	//Compare strings that are equal
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = Utf8String("\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a four-code-unit code
	//point in the parameter string
	compareString = Utf8String("ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "aö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = Utf8String("\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two/four-code-unit code points where the first code unit differs
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF2\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two/four-code-unit code points where the second code unit differs
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x95\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a four-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "S\xF0\x91\x84\xA2\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "\xC3\xB4" "ẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAA");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);


	//Test the compare() function that accepts a Utf8String
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyUtf8String) == 0);

	//Compare strings that are equal
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = Utf8String("ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the first code point differs
	compareString = Utf8String("\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the second code unit differs
	compareString = Utf8String("\xF0\x90\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a four-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bo\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Bẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = Utf8String("\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "b∑\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both three-code-unit code points where the third code unit differs
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ\xE1\x86\xA2\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "\xC3\xAB" "ö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA9" "bö\xEF\xBF\x9F");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);


	//Test the compare() function that accepts a UnicodeString containing a UTF-16 string
	unicodeString = utf16String;
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyString) == 0);

	//Compare strings that are equal
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = Utf8String("\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a four-code-unit code
	//point in the parameter string
	compareString = Utf8String("ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "aö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = Utf8String("\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two/four-code-unit code points where the first code unit differs
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF2\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two/four-code-unit code points where the second code unit differs
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x95\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a four-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "S\xF0\x91\x84\xA2\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "\xC3\xB4" "ẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAA");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Test the compare() function that accepts a UnicodeString containing a UTF-8 string
	unicodeString = utf8String;
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyString) == 0);

	//Compare strings that are equal
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = Utf8String("ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the first code point differs
	compareString = Utf8String("\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the second code unit differs
	compareString = Utf8String("\xF0\x90\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a four-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bo\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Bẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = Utf8String("\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "b∑\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both three-code-unit code points where the third code unit differs
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ\xE1\x86\xA2\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "\xC3\xAB" "ö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf8String("\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA9" "bö\xEF\xBF\x9F");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);


	//Test with the comparison string containing a UTF-16 string
	//Test the compare() function that accepts a Utf16String
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyUtf16String) == 0);

	//Compare strings that are equal
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = Utf16String(L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB");
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = Utf16String(L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6");
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);


	//Test the compare() function that accepts a Utf8String
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyUtf8String) == 0);

	//Compare strings that are equal
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = Utf8String(L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB");
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = Utf8String(L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6");
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);


	//Test the compare() function that accepts a UnicodeString containing a UTF-16 string
	unicodeString = utf16String;
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyString) == 0);

	//Compare strings that are equal
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = Utf16String(L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = Utf16String(L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf16String(L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);


	//Test the compare() function that accepts a UnicodeString containing a UTF-8 string
	unicodeString = utf8String;
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyString) == 0);

	//Compare strings that are equal
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = Utf8String(L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = Utf8String(L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = Utf8String(L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = Utf8String(L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6");
	CPPUNIT_ASSERT(compareString.compare(unicodeString) > 0);

}

void UnicodeStringTest::TestConstIterator()
{
	TestConstIteratorWithStringOne();
	TestConstIteratorWithStringTwo();
	TestConstIteratorWithStringThree();
	TestConstIteratorWithStringFour();
}

void UnicodeStringTest::TestConstIteratorReversal()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	const UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Create an iterator and put it in the middle of the string
	UnicodeString::const_iterator stringIterator = utf8UnicodeString.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[1] == '\x9F');

	//Now convert to a reverse iterator
	UnicodeString::const_reverse_iterator reverseStringIterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[1] == '\x9F');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[3] == '\xA8');

	//Move the iterator to a four-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[3] == '\xA8');

	//Now convert to a reverse iterator
	reverseStringIterator = UnicodeString::const_reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[3] == '\xA8');

	//Now convert back to a normal iterator
	stringIterator = UnicodeString::const_iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[3] == '\xA8');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\x62');


	//Test with a UnicodeString containing a UTF-16 string
	//Create a constant UTF-16 string composed of one- and two-code-unit characters
	const UnicodeString utf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Create an iterator and put it in the middle of the string
	stringIterator = utf16UnicodeString.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\x00DF');

	//Now convert to a reverse iterator
	reverseStringIterator = UnicodeString::const_reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[0] == L'\x00DF');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[1] == L'\xDC68');

	//Move the iterator to a two-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[1] == L'\xDC68');

	//Now convert to a reverse iterator
	reverseStringIterator = UnicodeString::const_reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[1] == L'\xDC68');

	//Now convert back to a normal iterator
	stringIterator = UnicodeString::const_iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[1] == L'\xDC68');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\x0062');
}

void UnicodeStringTest::TestConstReverseIterator()
{
	TestConstReverseIteratorWithStringOne();
	TestConstReverseIteratorWithStringTwo();
	TestConstReverseIteratorWithStringThree();
	TestConstReverseIteratorWithStringFour();
}

void UnicodeStringTest::TestConstructors()
{
	//Create a UnicodeString using the default constructor
	UnicodeString* constructedString = new UnicodeString();

	CPPUNIT_ASSERT(constructedString->empty());
	CPPUNIT_ASSERT(constructedString->length() == 0);
	CPPUNIT_ASSERT(constructedString->size() == 0);

	delete constructedString;
	constructedString = NULL;

	//Create a UTF-8 string containing simple ASCII characters
	Utf8String utf8String = "Simple String";
	//Create the UTF-16 version
	Utf16String utf16String = L"Simple String";

	//Test the constructors with simple strings
	TestConstructorsWithStrings(utf8String, utf16String);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "ωE4ڽhъ";
	//Create the UTF-16 version
	utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";

	//Test the constructors with strings containing a mix of 1- and 2-byte UTF-8 characters
	//and their UTF-16 equivalents
	TestConstructorsWithStrings(utf8String, utf16String);

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Test the constructors with strings containing a mix of 1-, 2, and 3-byte UTF-8 characters
	//and their UTF-16 equivalents
	TestConstructorsWithStrings(utf8String, utf16String);

	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Test the constructors with strings containing a mix of 1-, 2, 3-, and 4-byte UTF-8 characters
	//and their UTF-16 equivalents
	TestConstructorsWithStrings(utf8String, utf16String);
}

void UnicodeStringTest::TestEmpty()
{
	//Test a UnicodeString that contains a UTF-8 string
	//Test the default string
	UnicodeString unicodeString;
	CPPUNIT_ASSERT(unicodeString.empty());

	//Test a string with a single one-code-unit character
	unicodeString = Utf8String("\x33");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a single two-code-unit character
	unicodeString = Utf8String("\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a single three-code-unit character
	unicodeString = Utf8String("\xE1\xAB\xBA");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a single four-code-unit character
	unicodeString = Utf8String("\xF0\x92\x87\xA8");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a single invalid code unit
	unicodeString = Utf8String("\xF1");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a two invalid code units
	unicodeString = Utf8String("\xE1\x91");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with three invalid code units
	unicodeString = Utf8String("\xF1\x83\x95");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with four invalid code units
	unicodeString = Utf8String("\xF1\x83\xE2\xF3");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string that's set to an empty UTF-8 string
	//The UnicodeString will not be an empty string because a UTF-8 string 
	//(although it is empty) has been set
	unicodeString = Utf8String("");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a lot of different characters
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.empty());


	//Test a UnicodeString that contains a UTF-16 string
	//Test the default string
	unicodeString.clear();
	CPPUNIT_ASSERT(unicodeString.empty());

	//Test a string with a single one-code-unit character
	unicodeString = Utf16String(L"\x1EAB");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a single two-code-unit character
	unicodeString = Utf16String(L"\xD808\xDC68");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a single invalid code unit
	unicodeString = Utf16String(L"\xDC68");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string that's set to an empty UTF-16 string
	//The UnicodeString will not be an empty string because a UTF-16 string 
	//(although it is empty) has been set
	unicodeString = Utf16String(L"");
	CPPUNIT_ASSERT(!unicodeString.empty());

	//Test a string with a lot of different characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");
	CPPUNIT_ASSERT(!unicodeString.empty());
}

void UnicodeStringTest::TestEnd()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::iterator stringIterator = utf8UnicodeString.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*stringIterator)[1]);

	utf8UnicodeString = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	stringIterator = utf8UnicodeString.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);

	//Run the test again with a constant string
	const Utf8String constUtf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::const_iterator constStringIterator = constUtf8UnicodeString.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*constStringIterator)[1]);

	const Utf8String constUtf8UnicodeStringTwo = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	constStringIterator = constUtf8UnicodeStringTwo.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*constStringIterator)[2]);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string composed of one- and two-code-unit characters
	UnicodeString utf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	stringIterator = utf16UnicodeString.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)*stringIterator)[1]);

	utf16UnicodeString = Utf16String(L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB");

	stringIterator = utf16UnicodeString.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)*stringIterator)[0]);

	//Run the test again with a constant string
	const UnicodeString constUtf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	constStringIterator = constUtf16UnicodeString.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)*constStringIterator)[1]);

	const UnicodeString constUtf16UnicodeStringTwo = Utf16String(L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB");

	constStringIterator = constUtf16UnicodeStringTwo.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)*constStringIterator)[0]);
}

void UnicodeStringTest::TestErase()
{
	//Test a UnicodeString containing a UTF-8 string
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	UnicodeString eraseString;
	UnicodeString resultString;
	UnicodeString::iterator resultIterator = unicodeString.begin();

	//Test the erase() function that accepts two iterators
	//Try to remove characters from an empty string
	eraseString.clear();
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)0, eraseString.length());
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Remove characters at the beginning of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.begin() + 5);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\xC3\x9F");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 5));

	//Remove characters in the middle of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 3, eraseString.begin() + 8);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(eraseString[2] == "\x62");
	CPPUNIT_ASSERT(eraseString[3] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(eraseString[4] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(eraseString[5] == "\xD0\xB4");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 8));

	//Remove characters at the end of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 8, eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[7] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts a single iterator
	//Remove a character from the beginning of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin());

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 1));

	//Remove a one-code-unit character from the middle of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 6);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[6] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 6);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 7));

	//Remove a two-code-unit character from the middle of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 4);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[4] == "\xC3\x9F");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 4);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 5));

	//Remove a three-code-unit character from the middle of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 1);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[1] == "\x62");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 1);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 2));

	//Remove a four-code-unit character from the middle of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 3);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[3] == "\xC3\xB6");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 4));

	//Remove a character from the end of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.end() - 1);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[eraseString.length() - 1] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts two size_t parameters
	//Remove characters at the beginning of a string
	eraseString = unicodeString;
	resultString = eraseString.erase(0, 5);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\xC3\x9F");
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters in the middle of a string
	eraseString = unicodeString;
	resultString = eraseString.erase(3, 5);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(eraseString[2] == "\x62");
	CPPUNIT_ASSERT(eraseString[3] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(eraseString[4] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(eraseString[5] == "\xD0\xB4");
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string
	eraseString = unicodeString;
	resultString = eraseString.erase(8, 3);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[7] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string where the count parameter causes the range to
	//go beyond the end of the string
	eraseString = unicodeString;
	resultString = eraseString.erase(8, 12);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[7] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultString == eraseString);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");
	resultIterator = unicodeString.begin();

	//Test the erase() function that accepts two iterators
	//Try to remove characters from an empty string
	eraseString.clear();
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)0, eraseString.length());
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Remove characters at the beginning of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.begin() + 5);

	CPPUNIT_ASSERT_EQUAL((size_t)7, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x00DF');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 5));

	//Remove characters in the middle of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 3, eraseString.begin() + 10);

	CPPUNIT_ASSERT_EQUAL((size_t)5, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x0033');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[1])[0] == L'\x1EAB');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[2])[0] == L'\x0062');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[3])[0] == L'\x0434');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[4])[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[4])[1] == L'\xDC68');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 10));

	//Remove characters at the end of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 8, eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x0033');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[7])[0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts a single iterator
	//Remove a character from the beginning of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin());

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 1));

	//Remove a one-code-unit character from the middle of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 6);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[6])[0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 6);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 7));

	//Remove a two-code-unit character from the middle of the string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.begin() + 3);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[3])[0] == L'\x00F6');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(unicodeString.begin() + 4));

	//Remove a character from the end of a string
	eraseString = unicodeString;
	resultIterator = eraseString.erase(eraseString.end() - 1);

	CPPUNIT_ASSERT_EQUAL(unicodeString.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[eraseString.length() - 1])[0] == L'\x0434');
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts two size_t parameters
	//Remove characters at the beginning of a string
	eraseString = unicodeString;
	resultString = eraseString.erase(0, 5);

	CPPUNIT_ASSERT_EQUAL((size_t)7, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x00DF');
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters in the middle of a string
	eraseString = unicodeString;
	resultString = eraseString.erase(3, 7);

	CPPUNIT_ASSERT_EQUAL((size_t)5, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x0033');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[1])[0] == L'\x1EAB');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[2])[0] == L'\x0062');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[3])[0] == L'\x0434');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[4])[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[4])[1] == L'\xDC68');
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string
	eraseString = unicodeString;
	resultString = eraseString.erase(8, 4);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x0033');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[7])[0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string where the count parameter causes the range to
	//go beyond the end of the string
	eraseString = unicodeString;
	resultString = eraseString.erase(8, 12);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(((Utf16Char)eraseString[0])[0] == L'\x0033');
	CPPUNIT_ASSERT(((Utf16Char)eraseString[7])[0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultString == eraseString);
}

void UnicodeStringTest::TestFind()
{
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Test with a UnicodeString containing a UTF-8 string
	//Test the instance of find() that accepts a Utf8String
	//Create a UnicodeString containing UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = utf8String;
	size_t foundIndex;

	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(Utf8String("\x53"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf8String("\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf8String("\xC3\x9F"));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf8String("\xE2\x88\x91"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf8String("\xF0\x90\x8D\x86"));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(Utf8String("\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91"));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(Utf8String("\xF0\x90\x8D\x86\xD0\xB4"));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(Utf8String("\xE4\x90\xA8"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(Utf8String("\xE1\xBA\xAB\xC3\x9F\x33"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(Utf8String("\xF0\x90\x8D\x86"), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);


	//Test the instance of find() that accepts a Utf16String
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(Utf16String(L"\x0053"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\x0033"));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\x00DF"));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\x2211"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\xD800\xDF46"));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(Utf16String(L"\x0053\x1EAB\x0062\xD808\xDC68"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\x00DF\x0033\x1EAB\x2211"));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(Utf16String(L"\xD800\xDF46\x0434"));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(Utf16String(L"\xA483"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(Utf16String(L"\x0434\xD800\xDF46\x0062"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(Utf16String(L"\xD800\xDF46"), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);


	//Test the instance of find() that accepts a UnicodeString containing a Utf8String
	//Create a UnicodeString containing UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	unicodeString = utf8String;

	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\x53")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\x33")));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xC3\x9F")));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xE2\x88\x91")));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xF0\x90\x8D\x86")));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91")));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xF0\x90\x8D\x86\xD0\xB4")));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xE4\x90\xA8")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xE1\xBA\xAB\xC3\x9F\x33")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(UnicodeString(Utf8String("\xF0\x90\x8D\x86")), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);


	//Test the instance of find() that accepts a UnicodeString containing a Utf16String
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x0053")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x0033")));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x00DF")));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x2211")));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xD800\xDF46")));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x0053\x1EAB\x0062\xD808\xDC68")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x00DF\x0033\x1EAB\x2211")));

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xD800\xDF46\x0434")));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xA483")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x0434\xD800\xDF46\x0062")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xD800\xDF46")), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);


	//Test with a UnicodeString containing a UTF-16 string
	unicodeString = utf16String;

	//Test with the instance of find() that accepts a UTF-8 string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(Utf8String(L"\x0033"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf8String(L"\x2211"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf8String(L"\xD808\xDC68"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(Utf8String(L"\x0033\x1EAB\x0062"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(Utf8String(L"\x1EAB\x2211\xD800\xDF46\x0434"));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(Utf8String(L"\xD800\xDF46\x0434\xD808\xDC68"));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(Utf8String(L"\xA483"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(Utf8String(L"\x0434\xD800\xDF46\x0062"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(Utf8String(L"\xD808\xDC68"), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);


	//Test with the instance of find() that accepts a UTF-16 string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(Utf16String(L"\x0033"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\x2211"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\xD808\xDC68"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(Utf16String(L"\x0033\x1EAB\x0062"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(Utf16String(L"\x1EAB\x2211\xD800\xDF46\x0434"));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(Utf16String(L"\xD800\xDF46\x0434\xD808\xDC68"));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(Utf16String(L"\xA483"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(Utf16String(L"\x0434\xD800\xDF46\x0062"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(Utf16String(L"\xD808\xDC68"), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);


	//Test with the instance of find() that accepts a UnicodeString containing a UTF-8 string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\x0033")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\x2211")));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\xD808\xDC68")));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\x0033\x1EAB\x0062")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\x1EAB\x2211\xD800\xDF46\x0434")));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\xD800\xDF46\x0434\xD808\xDC68")));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\xA483")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\x0434\xD800\xDF46\x0062")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(UnicodeString(Utf8String(L"\xD808\xDC68")), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);


	//Test with the instance of find() that accepts a UnicodeString containing a UTF-16 string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x0033")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x2211")));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xD808\xDC68")));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x0033\x1EAB\x0062")));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x1EAB\x2211\xD800\xDF46\x0434")));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xD800\xDF46\x0434\xD808\xDC68")));

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xA483")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\x0434\xD800\xDF46\x0062")));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find(UnicodeString(Utf16String(L"\xD808\xDC68")), 5);

	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);
}

void UnicodeStringTest::TestFindFirstNotOf()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	UnicodeString shortString;

	size_t foundIndex;

	//Test with the instance of find_first_not_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = shortString.find_first_not_of(Utf8String("\xE1\xBA\xAB\x62"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String("\xC3\x9F");

	//Find the first code point that contains a code unit other than the second code unit
	foundIndex = shortString.find_first_not_of(Utf8String("\x9F"));

	//We should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find the first code point that contains a code unit other than the first code unit
	foundIndex = shortString.find_first_not_of(Utf8String("\xC3"));

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(Utf8String("\xC3\x9F"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(Utf8String("\x53\xE1\xBA\xAB\x62\xC3\x9F"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\x9F"));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(Utf8String("\x73\xE1\x90\xA2\xF3\x92\x8A\xA4"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(Utf8String("\x33"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf8String("\xC3\x9F\x33"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with the instance of find_first_not_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();
	foundIndex = shortString.find_first_not_of(Utf16String("\xE1\xBA\xAB\x62"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String("\xC3\x9F");

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(Utf16String("\xC3\x9F"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(Utf16String("\x53\xE1\xBA\xAB\x62\xC3\x9F"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf16String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\x9F"));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(Utf16String("\x73\xE1\x90\xA2\xF3\x92\x8A\xA4"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(Utf16String("\x33"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf16String("\xC3\x9F\x33"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with the instance of find_first_not_of() that accepts a UnicodeString containing a UTF-8 string
	//Attempt to find something in an empty string
	shortString.clear();
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf8String("\xE1\xBA\xAB\x62")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String("\xC3\x9F");

	//Find the first code point that contains a code unit other than the second code unit
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf8String("\x9F")));

	//We should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find the first code point that contains a code unit other than the first code unit
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf8String("\xC3")));

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf8String("\xC3\x9F")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String("\x53\xE1\xBA\xAB\x62\xC3\x9F")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\x9F")));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String("\x73\xE1\x90\xA2\xF3\x92\x8A\xA4")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String("\x33")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String("\xC3\x9F\x33")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with the instance of find_first_not_of() that accepts a UnicodeString containing a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf16String("\xE1\xBA\xAB\x62")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = UnicodeString(Utf16String("\xC3\x9F"));

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf16String("\xC3\x9F")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String("\x53\xE1\xBA\xAB\x62\xC3\x9F")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\x9F")));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String("\x73\xE1\x90\xA2\xF3\x92\x8A\xA4")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String("\x33")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String("\xC3\x9F\x33")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Test with the instance of find_first_not_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	shortString.clear();
	foundIndex = shortString.find_first_not_of(Utf8String(L"\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String(L"\xD808\xDC68");

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(Utf8String(L"\xD808\xDC68"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(Utf8String(L"\x0033\x1EAB\x0062"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf8String(L"\xD808\xDC68\x0033\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(Utf8String(L"\xD809\xDC22\x0054\x236B"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(Utf8String(L"\x0033"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf8String(L"\x00DF\x0033"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with the instance of find_first_not_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();
	foundIndex = shortString.find_first_not_of(Utf16String(L"\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf16String(L"\xD808\xDC68");

	//Find the first code point that doesn't contain the second code unit of a surrogate pair
	foundIndex = shortString.find_first_not_of(Utf16String(L"\xDC68"));

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find the first code point that doesn't contain the first code unit of a surrogate pair
	foundIndex = shortString.find_first_not_of(Utf16String(L"\xD808"));

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(Utf16String(L"\xD808\xDC68"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(Utf16String(L"\x0033\x1EAB\x0062"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf16String(L"\xD808\xDC68\x0033\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(Utf16String(L"\xD809\xDC22\x0054\x236B"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(Utf16String(L"\x0033"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(Utf16String(L"\x00DF\x0033"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with the instance of find_first_not_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	shortString.clear();
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf8String(L"\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String(L"\xD808\xDC68");

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf8String(L"\xD808\xDC68")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String(L"\x0033\x1EAB\x0062")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String(L"\xD808\xDC68\x0033\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String(L"\xD809\xDC22\x0054\x236B")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String(L"\x0033")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf8String(L"\x00DF\x0033")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with the instance of find_first_not_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf16String(L"\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf16String(L"\xD808\xDC68");

	//Find the first code point that doesn't contain the second code unit of a surrogate pair
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf16String(L"\xDC68")));

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find the first code point that doesn't contain the first code unit of a surrogate pair
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf16String(L"\xD808")));

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(UnicodeString(Utf16String(L"\xD808\xDC68")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_first_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String(L"\x0033\x1EAB\x0062")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String(L"\xD808\xDC68\x0033\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String(L"\xD809\xDC22\x0054\x236B")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String(L"\x0033")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_not_of(UnicodeString(Utf16String(L"\x00DF\x0033")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);
}

void UnicodeStringTest::TestFindFirstOf()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UnicodeString containing a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	UnicodeString emptyString;

	size_t foundIndex;

	//Test with an instance of find_first_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(Utf8String("\x33"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_first_of(Utf8String("\x53"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String("\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String("\xE1\xBA\xAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String("\xF0\x92\x81\xA8"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String("\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4"));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(Utf8String("\xE4\x97\x8A\x44\xC6\x96"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(Utf8String("\xE1\xBA\xAB"), 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String("\xE1\xBA\xAB"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find something past the end of the string
	foundIndex = unicodeString.find_first_of(Utf8String("\xE1\xBA\xAB"), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);


	//Test with an instance of find_first_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(Utf16String("\x33"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_first_of(Utf16String("\x53"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String("\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String("\xE1\xBA\xAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String("\xF0\x92\x81\xA8"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String("\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4"));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(Utf16String("\xE4\x97\x8A\x44\xC6\x96"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(Utf16String("\xE1\xBA\xAB"), 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String("\xE1\xBA\xAB"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find something past the end of the string
	foundIndex = unicodeString.find_first_of(Utf16String("\xE1\xBA\xAB"), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);


	//Test with an instance of find_first_of() that accepts a UnicodeString containing UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(UnicodeString(Utf8String("\x33")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\x53")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xE1\xBA\xAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xF0\x92\x81\xA8")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4")));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xE4\x97\x8A\x44\xC6\x96")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xE1\xBA\xAB")), 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xE1\xBA\xAB")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find something past the end of the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String("\xE1\xBA\xAB")), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);


	//Test with an instance of find_first_of() that accepts a UnicodeString containing a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(UnicodeString(Utf16String("\x33")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\x53")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xE1\xBA\xAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xF0\x92\x81\xA8")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4")));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xE4\x97\x8A\x44\xC6\x96")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xE1\xBA\xAB")), 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xE1\xBA\xAB")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find something past the end of the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String("\xE1\xBA\xAB")), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Test with an instance of find_first_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(Utf8String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_first_of(Utf8String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String(L"\xD800\xDF46\x0434\xD808\xDC68"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String(L"\x00DF\xD808\xDC68\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String(L"\x2211\x0043\x0434"));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(Utf8String(L"\x0043\xD8A0\xDCD2\x8E4C"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(Utf8String(L"\xD808\xDC68\x1EAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf8String(L"\xD808\xDC68\xE320"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Attempt to find soemthing past the end of the string
	foundIndex = unicodeString.find_first_of(Utf8String(L"\x0033\x1EAB"), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);


	//Test with an instance of find_first_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(Utf16String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_first_of(Utf16String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String(L"\xD800\xDF46\x0434\xD808\xDC68"));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String(L"\x00DF\xD808\xDC68\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String(L"\x2211\x0043\x0434"));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(Utf16String(L"\x0043\xD8A0\xDCD2\x8E4C"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(Utf16String(L"\xD808\xDC68\x1EAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_first_of(Utf16String(L"\xD808\xDC68\xE320"), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Attempt to find soemthing past the end of the string
	foundIndex = unicodeString.find_first_of(Utf16String(L"\x0033\x1EAB"), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);


	//Test with an instance of find_first_of() that accepts a UnicodeString containing a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(UnicodeString(Utf8String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\xD800\xDF46\x0434\xD808\xDC68")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\x00DF\xD808\xDC68\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\x2211\x0043\x0434")));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\x0043\xD8A0\xDCD2\x8E4C")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\xD808\xDC68\x1EAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\xD808\xDC68\xE320")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Attempt to find soemthing past the end of the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf8String(L"\x0033\x1EAB")), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);


	//Test with an instance of find_first_of() that accepts a UnicodeString containing a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(UnicodeString(Utf16String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\xD800\xDF46\x0434\xD808\xDC68")));
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\x00DF\xD808\xDC68\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\x2211\x0043\x0434")));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\x0043\xD8A0\xDCD2\x8E4C")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\xD808\xDC68\x1EAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\xD808\xDC68\xE320")), 4);
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Attempt to find soemthing past the end of the string
	foundIndex = unicodeString.find_first_of(UnicodeString(Utf16String(L"\x0033\x1EAB")), 14);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);
}

void UnicodeStringTest::TestFindLastNotOf()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	UnicodeString shortString;

	size_t foundIndex;

	//Test with an instance of find_last_not_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = shortString.find_last_not_of(Utf8String("\xE1\xBA\xAB\x62"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String("\xC3\xB6");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(Utf8String("\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(Utf8String("\xE1\xBA\xAB\xC3\x9F\xF0\x90\x8D\x86"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf8String("\xF0\x92\x81\xA8\x53\x62"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(Utf8String("\x56\xC4\x96\x33"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(Utf8String("\x33"), 6);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf8String("\x53"), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf8String("\xF0\x92\x81\xA8"), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);


	//Test with an instance of find_last_not_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();

	foundIndex = shortString.find_last_not_of(Utf16String("\xE1\xBA\xAB\x62"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String("\xC3\xB6");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(Utf16String("\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(Utf16String("\xE1\xBA\xAB\xC3\x9F\xF0\x90\x8D\x86"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf16String("\xF0\x92\x81\xA8\x53\x62"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(Utf16String("\x56\xC4\x96\x33"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(Utf16String("\x33"), 6);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf16String("\x53"), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf16String("\xF0\x92\x81\xA8"), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);


	//Test with an instance of find_last_not_of() that accepts a UnicodeString containing a UTF-8 string
	//Attempt to find something in an empty string
	shortString.clear();

	foundIndex = shortString.find_last_not_of(UnicodeString(Utf8String("\xE1\xBA\xAB\x62")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String("\xC3\xB6");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(UnicodeString(Utf8String("\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String("\xE1\xBA\xAB\xC3\x9F\xF0\x90\x8D\x86")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String("\xF0\x92\x81\xA8\x53\x62")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String("\x56\xC4\x96\x33")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String("\x33")), 6);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String("\x53")), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String("\xF0\x92\x81\xA8")), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);


	//Test with an instance of find_last_not_of() that accepts a UnicodeString containing a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();

	foundIndex = shortString.find_last_not_of(UnicodeString(Utf16String("\xE1\xBA\xAB\x62")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf8String("\xC3\xB6");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(UnicodeString(Utf16String("\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String("\xE1\xBA\xAB\xC3\x9F\xF0\x90\x8D\x86")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String("\xF0\x92\x81\xA8\x53\x62")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String("\x56\xC4\x96\x33")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String("\x33")), 6);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String("\x53")), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String("\xF0\x92\x81\xA8")), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Test with an instance of find_last_not_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	shortString.clear();

	foundIndex = shortString.find_last_not_of(Utf8String(L"\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf16String(L"\xD808\xDC68");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(Utf8String(L"\xD808\xDC68"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(Utf8String(L"\x0033\x1EAB\x0062"));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf8String(L"\xD808\xDC68\x0033\x0062\x1EAB\xD800\xDF46\x0434"));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(Utf8String(L"\xD809\xDC22\x0054\x236B"));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(Utf8String(L"\x0033"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf8String(L"\x0033"), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf8String(L"\xD808\xDC68"), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);


	//Test with an instance of find_last_not_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();

	foundIndex = shortString.find_last_not_of(Utf16String(L"\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf16String(L"\xD808\xDC68");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(Utf16String(L"\xD808\xDC68"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(Utf16String(L"\x0033\x1EAB\x0062"));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf16String(L"\xD808\xDC68\x0033\x0062\x1EAB\xD800\xDF46\x0434"));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(Utf16String(L"\xD809\xDC22\x0054\x236B"));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(Utf16String(L"\x0033"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf16String(L"\x0033"), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(Utf16String(L"\xD808\xDC68"), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);


	//Test with an instance of find_last_not_of() that accepts a UnicodeString containing a UTF-8 string
	//Attempt to find something in an empty string
	shortString.clear();

	foundIndex = shortString.find_last_not_of(UnicodeString(Utf8String(L"\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf16String(L"\xD808\xDC68");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(UnicodeString(Utf8String(L"\xD808\xDC68")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String(L"\x0033\x1EAB\x0062")));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String(L"\xD808\xDC68\x0033\x0062\x1EAB\xD800\xDF46\x0434")));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String(L"\xD809\xDC22\x0054\x236B")));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String(L"\x0033")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String(L"\x0033")), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf8String(L"\xD808\xDC68")), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);


	//Test with an instance of find_last_not_of() that accepts a UnicodeString containing a UTF-16 string
	//Attempt to find something in an empty string
	shortString.clear();

	foundIndex = shortString.find_last_not_of(UnicodeString(Utf16String(L"\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = Utf16String(L"\xD808\xDC68");

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(UnicodeString(Utf16String(L"\xD808\xDC68")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = unicodeString.find_last_not_of(unicodeString);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String(L"\x0033\x1EAB\x0062")));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String(L"\xD808\xDC68\x0033\x0062\x1EAB\xD800\xDF46\x0434")));
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String(L"\xD809\xDC22\x0054\x236B")));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String(L"\x0033")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String(L"\x0033")), 0);
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	foundIndex = unicodeString.find_last_not_of(UnicodeString(Utf16String(L"\xD808\xDC68")), 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);
}

void UnicodeStringTest::TestFindLastOf()
{
	//Test a UnicodeString containing a UTF-8 string
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	UnicodeString emptyString;

	size_t foundIndex;

	//Test with an instance of find_last_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(Utf8String("\x53"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_last_of(Utf8String("\x33"));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String("\xF0\x90\x8D\x86\xD0\xB4"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String("\xE1\xBA\xAB\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String("\xF0\x90\x8D\x86"));
	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Attempt to find some characters that aren't in the string
	foundIndex = unicodeString.find_last_of(Utf8String("\x44\xF1\x86\xA2\x98\xC5\xAA"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(Utf8String("\xE1\xBA\xAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String("\x62\xE1\xBA\xAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(Utf8String("\x53\xE1\xBA\xAB"), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(Utf8String("\x53\xE1\xBA\xAB"), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with an instance of find_last_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(Utf16String("\x53"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_last_of(Utf16String("\x33"));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String("\xF0\x90\x8D\x86\xD0\xB4"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String("\xE1\xBA\xAB\xC3\xB6"));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String("\xF0\x90\x8D\x86"));
	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Attempt to find some characters that aren't in the string
	foundIndex = unicodeString.find_last_of(Utf16String("\x44\xF1\x86\xA2\x98\xC5\xAA"));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(Utf16String("\xE1\xBA\xAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String("\x62\xE1\xBA\xAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(Utf16String("\x53\xE1\xBA\xAB"), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(Utf16String("\x53\xE1\xBA\xAB"), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with an instance of find_last_of() that accepts a UnicodeString containing a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(UnicodeString(Utf8String("\x53")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\x33")));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\xF0\x90\x8D\x86\xD0\xB4")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\xE1\xBA\xAB\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\xF0\x90\x8D\x86")));
	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Attempt to find some characters that aren't in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\x44\xF1\x86\xA2\x98\xC5\xAA")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\xE1\xBA\xAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\x62\xE1\xBA\xAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\x53\xE1\xBA\xAB")), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String("\x53\xE1\xBA\xAB")), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with an instance of find_last_of() that accepts a UnicodeString containing a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(UnicodeString(Utf16String("\x53")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find some characters in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\x33")));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\xF0\x90\x8D\x86\xD0\xB4")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\xE1\xBA\xAB\xC3\xB6")));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\xF0\x90\x8D\x86")));
	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Attempt to find some characters that aren't in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\x44\xF1\x86\xA2\x98\xC5\xAA")));
	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\xE1\xBA\xAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\x62\xE1\xBA\xAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\x53\xE1\xBA\xAB")), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String("\x53\xE1\xBA\xAB")), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test a UnicodeString containing a UTF-16 string
	//Create a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");


	//Test with an instance of find_last_of() that accepts a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(Utf8String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_last_of(Utf8String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String(L"\x0434\xD800\xDF46"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String(L"\x00DF\xD808\xDC68\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String(L"\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_last_of(Utf8String(L"\x0043\xD8A0\xDCD2\x8E4C"));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(Utf8String(L"\xD808\xDC68\x1EAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf8String(L"\x1EAB\xE320"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(Utf8String(L"\x0033\x1EAB"), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(Utf8String(L"\x0033\x1EAB"), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with an instance of find_last_of() that accepts a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(Utf16String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_last_of(Utf16String(L"\x0033"));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String(L"\x0434\xD800\xDF46"));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String(L"\x00DF\xD808\xDC68\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String(L"\x0062\x1EAB"));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_last_of(Utf16String(L"\x0043\xD8A0\xDCD2\x8E4C"));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(Utf16String(L"\xD808\xDC68\x1EAB"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_last_of(Utf16String(L"\x1EAB\xE320"), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(Utf16String(L"\x0033\x1EAB"), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(Utf16String(L"\x0033\x1EAB"), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with an instance of find_last_of() that accepts a UnicodeString containing a UTF-8 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(UnicodeString(Utf8String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x0434\xD800\xDF46")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x00DF\xD808\xDC68\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x0043\xD8A0\xDCD2\x8E4C")));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\xD808\xDC68\x1EAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x1EAB\xE320")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x0033\x1EAB")), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf8String(L"\x0033\x1EAB")), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);


	//Test with an instance of find_last_of() that accepts a UnicodeString containing a UTF-16 string
	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(UnicodeString(Utf16String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x0033")));
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x0434\xD800\xDF46")));
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x00DF\xD808\xDC68\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x0062\x1EAB")));
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x0043\xD8A0\xDCD2\x8E4C")));
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\xD808\xDC68\x1EAB")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x1EAB\xE320")), 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x0033\x1EAB")), 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = unicodeString.find_last_of(UnicodeString(Utf16String(L"\x0033\x1EAB")), 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);
}

void UnicodeStringTest::TestIndexer()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Get the character at the beginning of the string
	Utf8Char utf8Character = (Utf8Char)unicodeString[0];

	CPPUNIT_ASSERT_EQUAL('\x53', utf8Character[0]);

	//Get the utf8Character at the end of the string
	utf8Character = (Utf8Char)unicodeString[unicodeString.length() - 1];

	CPPUNIT_ASSERT_EQUAL('\xD0', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', utf8Character[1]);

	//Get a one-code-unit utf8Character in the middle of the string
	utf8Character = (Utf8Char)unicodeString[6];

	CPPUNIT_ASSERT_EQUAL('\x33', utf8Character[0]);

	//Get a two-code-unit utf8Character in the middle of the string
	utf8Character = (Utf8Char)unicodeString[4];

	CPPUNIT_ASSERT_EQUAL('\xC3', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', utf8Character[1]);

	//Get a four-code-unit utf8Character in the middle of the string
	utf8Character = (Utf8Char)unicodeString[1];

	CPPUNIT_ASSERT_EQUAL('\xE1', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8Character[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8Character[2]);

	//Get a four-code-unit utf8Character in the middle of the string
	utf8Character = (Utf8Char)unicodeString[3];

	CPPUNIT_ASSERT_EQUAL('\xF0', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8Character[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', utf8Character[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', utf8Character[3]);

	//Create a constant UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString constUtf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Get the character at the beginning of the string
	utf8Character = (Utf8Char)constUtf8UnicodeString[0];

	CPPUNIT_ASSERT_EQUAL('\x53', utf8Character[0]);

	//Get the utf8Character at the end of the string
	utf8Character = (Utf8Char)constUtf8UnicodeString[constUtf8UnicodeString.length() - 1];

	CPPUNIT_ASSERT_EQUAL('\xD0', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', utf8Character[1]);

	//Get a one-code-unit utf8Character in the middle of the string
	utf8Character = (Utf8Char)constUtf8UnicodeString[6];

	CPPUNIT_ASSERT_EQUAL('\x33', utf8Character[0]);

	//Get a two-code-unit utf8Character in the middle of the string
	utf8Character = (Utf8Char)constUtf8UnicodeString[4];

	CPPUNIT_ASSERT_EQUAL('\xC3', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', utf8Character[1]);

	//Get a four-code-unit character in the middle of the string
	utf8Character = (Utf8Char)constUtf8UnicodeString[1];

	CPPUNIT_ASSERT_EQUAL('\xE1', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', utf8Character[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', utf8Character[2]);

	//Get a four-code-unit character in the middle of the string
	utf8Character = (Utf8Char)constUtf8UnicodeString[3];

	CPPUNIT_ASSERT_EQUAL('\xF0', utf8Character[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', utf8Character[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', utf8Character[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', utf8Character[3]);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Get the character at the beginning of the string
	Utf16Char utf16Character = unicodeString[0];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', utf16Character[0]);

	//Get the character at the end of the string
	utf16Character = (Utf16Char)unicodeString[unicodeString.length() - 1];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16Character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16Character[1]);

	//Get a one-code-unit character in the middle of the string
	utf16Character = (Utf16Char)unicodeString[5];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', utf16Character[0]);

	//Get a two-code-unit character in the middle of the string
	utf16Character = (Utf16Char)unicodeString[3];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16Character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16Character[1]);

	//Repeat the same tests with a constant string
	const UnicodeString constUtf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Get the character at the beginning of the string
	utf16Character = (Utf16Char)constUtf16UnicodeString[0];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', utf16Character[0]);

	//Get the character at the end of the string
	utf16Character = (Utf16Char)constUtf16UnicodeString[constUtf16UnicodeString.length() - 1];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16Character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16Character[1]);

	//Get a one-code-unit character in the middle of the string
	utf16Character = (Utf16Char)constUtf16UnicodeString[5];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', utf16Character[0]);

	//Get a two-code-unit character in the middle of the string
	utf16Character = (Utf16Char)constUtf16UnicodeString[3];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', utf16Character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', utf16Character[1]);
}

void UnicodeStringTest::TestInsert()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UnicodeString containing a UTF-8 string that will be appended to
	UnicodeString originalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86");
	//Create the UnicodeString containing a UTF-8 string that results from an insert operation at the beginning of the string
	UnicodeString finalBeginString = Utf8String("\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86дẫö∑b\xF0\x90\x8D\x86");
	//Create the UnicodeString containing a UTF-8 string that results from an insert operation in the middle of the string
	UnicodeString finalMiddleString = Utf8String("ẫö\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д∑b\xF0\x90\x8D\x86");
	//Create the UnicodeString containing a UTF-8 string that results from an insert operation at the end of the string
	UnicodeString finalEndString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д");
	//Create the string on which the insert operations will be conducted
	UnicodeString insertedString;


	//Test the insert() function that accepts a Utf16String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String);

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a Utf8String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf8String);

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String), insertedString);


	//Test the insert() function that accepts a UnicodeString containing a Utf16String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a UnicodeString containg a Utf8String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String), insertedString);

	//Test the insert() function that accepts a UnicodeChar containing a Utf8Char
	//Create a UTF-8 string that will be the result when inserting a one-code-unit character
	//at the beginning
	UnicodeString oneCodeUnitBeginFinalString = Utf8String("Sẫö∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result when inserting a one-code-unit character
	//in the middle
	UnicodeString oneCodeUnitMiddleFinalString = Utf8String("ẫöS∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result when inserting a one-code-unit character
	//at the end
	UnicodeString oneCodeUnitEndFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86S");
	//Create a UTF-8 string that will be the result inserting a two-code-unit character
	//at the beginning
	UnicodeString twoCodeUnitBeginFinalString = Utf8String("\xC3\xB6ẫö∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result inserting a two-code-unit character
	//at the beginning
	UnicodeString twoCodeUnitMiddleFinalString = Utf8String("ẫö\xC3\xB6∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result inserting a two-code-unit character
	//at the beginning
	UnicodeString twoCodeUnitEndFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xC3\xB6");
	//Create a UTF-8 string that will be the result inserting a three-code-unit character
	//at the beginning
	UnicodeString threeCodeUnitBeginFinalString = Utf8String("\xE1\xBA\xABẫö∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result inserting a three-code-unit character
	//at the beginning
	UnicodeString threeCodeUnitMiddleFinalString = Utf8String("ẫö\xE1\xBA\xAB∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result inserting a three-code-unit character
	//at the beginning
	UnicodeString threeCodeUnitEndFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xE1\xBA\xAB");
	//Create a UTF-8 string that will be the result inserting a four-code-unit character
	//at the beginning
	UnicodeString fourCodeUnitBeginFinalString = Utf8String("\xF0\x92\x81\xA8ẫö∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result inserting a four-code-unit character
	//at the beginning
	UnicodeString fourCodeUnitMiddleFinalString = Utf8String("ẫö\xF0\x92\x81\xA8∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result inserting a four-code-unit character
	//at the beginning
	UnicodeString fourCodeUnitEndFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xF0\x92\x81\xA8");

	//Insert a one-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar(Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar(Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(1, 1)), insertedString);

	//Insert a two-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar(Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar(Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(4, 1)), insertedString);


	//Insert a three-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar(Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar(Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(2, 1)), insertedString);


	//Insert a four-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar(Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar(Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar(Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(0, 1)), insertedString);


	//Test the insert() function that accepts a UnicodeChar containing a Utf16Char
	//Insert a one-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar((Utf16Char)Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar((Utf16Char)Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[1])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(1, 1)), insertedString);

	//Insert a two-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar((Utf16Char)Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar((Utf16Char)Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[4])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(4, 1)), insertedString);


	//Insert a three-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar((Utf16Char)Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar((Utf16Char)Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[2])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(2, 1)), insertedString);


	//Insert a four-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar((Utf16Char)Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, UnicodeChar((Utf16Char)Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar((Utf16Char)Utf8Char(utf8String[0])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf8String.substr(0, 1)), insertedString);


	//Test with a UnicodeString containing a UTF-16 string
	//Test the insert functionality with a string composed of only single-code-unit characters
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = Utf8String("Sẫböß3ẫ∑д");
	//Create the UTF-16 version
	utf16String = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");
	//Create a UTF-16 string that will get another string inserted into it
	originalString = Utf16String(L"\x2211\x0053\x0062\x00F6");
	//Create the UTF-16 string that results from an insert operation at the beginning of the string
	finalBeginString = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434\x2211\x0053\x0062\x00F6");
	//Create the UTF-16 string that results from an insert operation in the middle of the string
	finalMiddleString = Utf16String(L"\x2211\x0053\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434\x0062\x00F6");
	//Create the UTF-16 string that results from an insert operation at the end of the string
	finalEndString = Utf16String(L"\x2211\x0053\x0062\x00F6\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");


	//Test the insert() function that accepts a Utf16String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String);

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a Utf8String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf8String);

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a UnicodeString containg a UTF-16 string
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a UnicodeString containing a UTF-8 string
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Now test the insert functionality with UTF-16 string containing characters with two code units
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = Utf8String("\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д");
	//Create the UTF-16 version
	utf16String = Utf16String(L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	//Create a UTF-16 string that will be appended to
	originalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46");
	//Create the UTF-16 string that results from an insert operation at the beginning of the string
	finalBeginString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x1EAB\x2211\xD800\xDF46");
	//Create the UTF-16 string that results from an insert operation in the middle of the string
	finalMiddleString = Utf16String(L"\x1EAB\x2211\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD800\xDF46");
	//Create the UTF-16 string that results from an insert operation at the end of the string
	finalEndString = Utf16String(L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");


	//Test the insert() function that accepts a Utf16String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, utf16String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String);

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a Utf8String
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, utf8String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf8String);

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a UnicodeString containing a UTF-16 string
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeString(utf16String));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a UnicodeString containing a UTF-8 string
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeString(utf8String));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String), insertedString);


	//Test the insert() function that accepts a UnicodeString containing a Utf16Char
	//Create a UnicodeString containing a UTF-16 string that will be the result when inserting a one-code-unit character
	//at the beginning
	oneCodeUnitBeginFinalString = Utf16String(L"\x0053\x1EAB\x2211\xD800\xDF46");
	//Create a UTF-16 string that will be the result when inserting a one-code-unit character
	//in the middle
	oneCodeUnitMiddleFinalString = Utf16String(L"\x1EAB\x2211\x0053\xD800\xDF46");
	//Create a UTF-16 string that will be the result when inserting a one-code-unit character
	//at the end
	oneCodeUnitEndFinalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46\x0053");
	//Create a UTF-16 string that will be the result inserting a two-code-unit character
	//at the beginning
	twoCodeUnitBeginFinalString = Utf16String(L"\xD808\xDC68\x1EAB\x2211\xD800\xDF46");
	//Create a UTF-16 string that will be the result inserting a two-code-unit character
	//at the beginning
	twoCodeUnitMiddleFinalString = Utf16String(L"\x1EAB\x2211\xD808\xDC68\xD800\xDF46");
	//Create a UTF-16 string that will be the result inserting a two-code-unit character
	//at the beginning
	twoCodeUnitEndFinalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68");

	//Insert a one-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar(Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar(Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, UnicodeChar(Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar(Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String.substr(1, 1)), insertedString);


	//Insert a two-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar(Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar(Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, UnicodeChar(Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar(Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String.substr(0, 1)), insertedString);


	//Test the insert() function that accepts a UnicodeString containing a Utf8Char
	//Insert a one-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar((Utf8Char)Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar((Utf8Char)Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, UnicodeChar((Utf8Char)Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar((Utf8Char)Utf16Char(utf16String[1])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String.substr(1, 1)), insertedString);


	//Insert a two-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, UnicodeChar((Utf8Char)Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, UnicodeChar((Utf8Char)Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, UnicodeChar((Utf8Char)Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, UnicodeChar((Utf8Char)Utf16Char(utf16String[0])));

	CPPUNIT_ASSERT_EQUAL(UnicodeString(utf16String.substr(0, 1)), insertedString);
}

void UnicodeStringTest::TestIsValid()
{
	//Test a UnicodeString containing a UTF-8 string
	//Test a valid UTF-8 string
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(unicodeString.is_valid());

	//Test an empty string
	unicodeString.clear();
	CPPUNIT_ASSERT(unicodeString.is_valid());

	//Test a string where a multi-code-unit code point is missing some code units
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string where a multi-code-unit code point at the end of the string is missing some code units
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4\xF0");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string where a multi-code-unit code point is missing the first code unit
	unicodeString = Utf8String("\x53\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string where a multi-code-unit code point at the end of the string is missing the first code unit
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\x90\x8D\x86");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing the BOM code point 0xFFFE (0xEF, 0xBF, 0xBE)
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xEF\xBF\xBE\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing the BOM code point 0xFFFF (0xEF, 0xBF, 0xBF)
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xEF\xBF\xBF\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing one of the code points that are non-characters
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xF1\x8F\xBF\xBE\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing another one of the code points that are non-characters
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xEF\xB7\xAE\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	
	//Test a UnicodeString containing a UTF-16 string
	//Test a valid UTF-16 string
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");
	CPPUNIT_ASSERT(unicodeString.is_valid());

	//Test an empty string
	unicodeString.clear();
	CPPUNIT_ASSERT(unicodeString.is_valid());

	//Test a string where a surrogate pair is missing the second code unit
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\x0434\xD808\xDC68");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string where a surrogate pair at the end of the string is missing the second code unit
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\x0434\xD808");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string where a surrogate pair is missing the first code unit
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string where a surrogate pair at the end of the string is missing the first code unit
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xDC68");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing the BOM code point 0xFFFE
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\xFFFE\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing the BOM code point 0xFFFF
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68\xFFFF");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing some of the one-code-unit code points that are non-characters(0xFDD0 - 0xFDEF)
	unicodeString = Utf16String(L"\x0033\x1EAB\xFDE2\xD808\xDC68\x00DF\x0033\x1EAB\xFDD8\xD800\xDF46\x0434\xD808\xDC68");
	CPPUNIT_ASSERT(!unicodeString.is_valid());

	//Test a string containing some of the two-code-unit code points that are non-characters(0xFDD0 - 0xFDEF)
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDFFE\x00DF\x0033\x1EAB\x2211\xD800\xDFFF\x0434\xD808\xDC68");
	CPPUNIT_ASSERT(!unicodeString.is_valid());
}

void UnicodeStringTest::TestIsWhitespace()
{
	//Test the function that accepts a UnicodeChar
	//Test using a UnicodeChar containing a UTF-8 character
	Utf8Char utf8Character;

	utf8Character[0] = '\x20';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\x09';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\x0D';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\x0A';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xA0';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE1';
	utf8Character[1] = '\x9A';
	utf8Character[2] = '\x80';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE1';
	utf8Character[1] = '\xA0';
	utf8Character[2] = '\x8E';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE3';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x80';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x86';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x89';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x8A';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\xBF';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x81';
	utf8Character[2] = '\x9F';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE3';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x80';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\xB8';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\xB9';
	CPPUNIT_ASSERT(UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	//Test characters that shouldn't be considered whitespace
	utf8Character.clear();

	utf8Character[0] = '\x00';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\x68';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xD0';
	utf8Character[1] = '\xB4';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xC3';
	utf8Character[1] = '\x9F';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE1';
	utf8Character[1] = '\xBA';
	utf8Character[2] = '\xAB';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x88';
	utf8Character[2] = '\x91';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xF0';
	utf8Character[1] = '\x92';
	utf8Character[2] = '\x81';
	utf8Character[3] = '\xA8';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	utf8Character[0] = '\xF0';
	utf8Character[1] = '\x90';
	utf8Character[2] = '\x8D';
	utf8Character[3] = '\x86';
	CPPUNIT_ASSERT(!UnicodeString::IsWhitespace(UnicodeChar(utf8Character)));

	//Test using a UnicodeChar containing a UTF-16 character
	//Test characters in Unicode considered to be whitespace characters
	Utf16Char utf16Character;

	utf16Character = L'\x0020';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x0009';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x000D';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x000A';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x00A0';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x1680';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x180E';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x2000';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x2006';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x2009';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x200A';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x202F';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x205F';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x3000';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x2028';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x2029';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	//Test characters that shouldn't be considered whitespace
	utf16Character = L'\x0000';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x0068';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\x1EAB';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(UnicodeChar(utf16Character)));

	utf16Character = L'\xD809';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(UnicodeChar(utf16Character)));
}

void UnicodeStringTest::TestIterator()
{
	TestIteratorWithStringOne();
	TestIteratorWithStringTwo();
	TestIteratorWithStringThree();
	TestIteratorWithStringFour();
}

void UnicodeStringTest::TestIteratorReversal()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Create an iterator and put it in the middle of the string
	UnicodeString::iterator stringIterator = utf8UnicodeString.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[1] == '\x9F');

	//Now convert to a reverse iterator
	UnicodeString::reverse_iterator reverseStringIterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[1] == '\x9F');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[3] == '\xA8');

	//Move the iterator to a four-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[3] == '\xA8');

	//Now convert to a reverse iterator
	reverseStringIterator = UnicodeString::reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*reverseStringIterator)[3] == '\xA8');

	//Now convert back to a normal iterator
	stringIterator = UnicodeString::iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[3] == '\xA8');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT(((Utf8Char)*stringIterator)[0] == '\x62');


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string composed of one- and two-code-unit characters
	UnicodeString utf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Create an iterator and put it in the middle of the string
	stringIterator = utf16UnicodeString.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\x00DF');

	//Now convert to a reverse iterator
	reverseStringIterator = UnicodeString::reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[0] == L'\x00DF');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[1] == L'\xDC68');

	//Move the iterator to a two-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[1] == L'\xDC68');

	//Now convert to a reverse iterator
	reverseStringIterator = UnicodeString::reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*reverseStringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*reverseStringIterator)[1] == L'\xDC68');

	//Now convert back to a normal iterator
	stringIterator = UnicodeString::iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[1] == L'\xDC68');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT(((Utf16Char)*stringIterator)[0] == L'\x0062');
}

void UnicodeStringTest::TestLength()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Get the length of the default string
	UnicodeString unicodeString;

	CPPUNIT_ASSERT_EQUAL((size_t)0, unicodeString.length());

	//Get the length of a 0-length string
	unicodeString = Utf8String("");

	CPPUNIT_ASSERT_EQUAL((size_t)0, unicodeString.length());

	//Get the length of a single character (one code unit) string
	unicodeString = Utf8String("\x48");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.length());

	//Get the length of a single character (two code units) string
	unicodeString = Utf8String("\xC3\xB6");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.length());

	//Get the length of a single character (three code units) string
	unicodeString = Utf8String("\xE2\x88\x91");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.length());

	//Get the length of a single character (four code units) string
	unicodeString = Utf8String("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	unicodeString = Utf8String("Simple String");

	CPPUNIT_ASSERT_EQUAL((size_t)13, unicodeString.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	unicodeString = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	CPPUNIT_ASSERT_EQUAL((size_t)8, unicodeString.length());

	//Get the length of a multi-character string containing both one-, two-, and three-code-unit characters
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)9, unicodeString.length());

	//Get the length of a multi-character string containing both one-, two-, three- and four-code-unit characters
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)11, unicodeString.length());


	//Run the tests again with a constant string
	//Get the length of the default string
	const UnicodeString constUtf8UnicodeString;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf8UnicodeString.length());

	//Get the length of a 0-length string
	const UnicodeString constUtf8UnicodeString1 = Utf8String("");

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf8UnicodeString1.length());

	//Get the length of a single character (one code unit) string
	const UnicodeString constUtf8UnicodeString2 = Utf8String("\x48");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8UnicodeString2.length());

	//Get the length of a single character (two code units) string
	const UnicodeString constUtf8UnicodeString3 = Utf8String("\xC3\xB6");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8UnicodeString3.length());

	//Get the length of a single character (three code units) string
	const UnicodeString constUtf8UnicodeString4 = Utf8String("\xE2\x88\x91");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8UnicodeString4.length());

	//Get the length of a single character (four code units) string
	const UnicodeString constUtf8UnicodeString5 = Utf8String("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8UnicodeString5.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	const UnicodeString constUtf8UnicodeString6 = Utf8String("Simple String");

	CPPUNIT_ASSERT_EQUAL((size_t)13, constUtf8UnicodeString6.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	const UnicodeString constUtf8UnicodeString7 = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	CPPUNIT_ASSERT_EQUAL((size_t)8, constUtf8UnicodeString7.length());

	//Get the length of a multi-character string containing both one-, two-, and three-code-unit characters
	const UnicodeString constUtf8UnicodeString8 = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)9, constUtf8UnicodeString8.length());

	//Get the length of a multi-character string containing both one-, two-, three- and four-code-unit characters
	const UnicodeString constUtf8UnicodeString9 = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)11, constUtf8UnicodeString9.length());


	//Test with a UnicodeString containing a UTF-16 string
	//Get the length of a cleared string
	unicodeString.clear();
	CPPUNIT_ASSERT_EQUAL((size_t)0, unicodeString.length());

	//Get the length of a 0-length string
	unicodeString = Utf16String(L"");

	CPPUNIT_ASSERT_EQUAL((size_t)0, unicodeString.length());

	//Get the length of a single character (one code unit) string
	unicodeString = Utf16String(L"\x2211");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.length());

	//Get the length of a single character (two code units) string
	unicodeString = Utf16String(L"\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	unicodeString = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");

	CPPUNIT_ASSERT_EQUAL((size_t)9, unicodeString.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)12, unicodeString.length());

	//Now run the tests again with constant string
	//Get the length of the default string
	const UnicodeString constUtf16UnicodeString1;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16UnicodeString1.length());

	//Get the length of a 0-length string
	const UnicodeString constUtf16UnicodeString2 = Utf16String(L"");

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16UnicodeString2.length());

	//Get the length of a single character (one code unit) string
	const UnicodeString constUtf16UnicodeString3 = Utf16String(L"\x2211");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf16UnicodeString3.length());

	//Get the length of a single character (two code units) string
	const UnicodeString constUtf16UnicodeString4 = Utf16String(L"\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf16UnicodeString4.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	const UnicodeString constUtf16UnicodeString5 = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");

	CPPUNIT_ASSERT_EQUAL((size_t)9, constUtf16UnicodeString5.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	const UnicodeString constUtf16UnicodeString6 = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)12, constUtf16UnicodeString6.length());
}

void UnicodeStringTest::TestPushBack()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Create a UTF-8 string that will be appended to
	UnicodeString originalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86");
	//Create a UTF-8 string that will be the result appending a one-code-unit character
	UnicodeString oneCodeUnitFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\x53");
	//Create a UTF-8 string that will be the result appending a two-code-unit character
	UnicodeString twoCodeUnitFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xC3\xB6");
	//Create a UTF-8 string that will be the result appending a three-code-unit character
	UnicodeString threeCodeUnitFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xE1\xBA\xAB");
	//Create a UTF-8 string that will be the result appending a four-code-unit character
	UnicodeString fourCodeUnitFinalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xF0\x92\x81\xA8");

	//Create a string upon which the push_back() function will be called
	UnicodeString appendedString;

	//Append a one-code-unit character
	appendedString = originalString;
	appendedString.push_back(unicodeString[0]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, appendedString);

	//Append a two-code-unit character
	appendedString = originalString;
	appendedString.push_back(unicodeString[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, appendedString);

	//Append a three-code-unit character
	appendedString = originalString;
	appendedString.push_back(unicodeString[1]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitFinalString, appendedString);

	//Append a four-code-unit character
	appendedString = originalString;
	appendedString.push_back(unicodeString[3]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitFinalString, appendedString);


	//Test with a UnicodeString containing a UTF-16 string
	unicodeString = Utf16String(L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");

	//Create a UTF-16 string that will be appended to
	originalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46");
	//Create a UTF-16 string that will be the result appending a one-code-unit character
	oneCodeUnitFinalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46\x0053");
	//Create a UTF-16 string that will be the result appending a two-code-unit character
	twoCodeUnitFinalString = Utf16String(L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68");

	//Append a one-code-unit character
	appendedString = originalString;
	appendedString.push_back(unicodeString[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, appendedString);

	//Append a two-code-unit character
	appendedString = originalString;
	appendedString.push_back(unicodeString[0]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, appendedString);
}

void UnicodeStringTest::TestRbegin()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::reverse_iterator stringIterator = unicodeString.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*stringIterator)[1]);

	unicodeString = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	stringIterator = unicodeString.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);

	//Run the test again with a constant string
	const UnicodeString constUtf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::const_reverse_iterator constStringIterator = constUtf8UnicodeString.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*constStringIterator)[1]);

	const UnicodeString constUtf8UnicodeStringTwo = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	constStringIterator = constUtf8UnicodeStringTwo.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*constStringIterator)[2]);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	stringIterator = unicodeString.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)*stringIterator)[1]);

	unicodeString = Utf16String(L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB");

	stringIterator = unicodeString.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)*stringIterator)[0]);

	//Run the test again with a constant string
	const UnicodeString constUtf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	constStringIterator = constUtf16UnicodeString.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)*constStringIterator)[1]);

	const UnicodeString constUtf16UnicodeStringTwo = Utf16String(L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB");

	constStringIterator = constUtf16UnicodeStringTwo.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)*constStringIterator)[0]);
}

void UnicodeStringTest::TestRend()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::reverse_iterator stringIterator = unicodeString.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*stringIterator)[0]);

	unicodeString = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	stringIterator = unicodeString.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);

	//Run the test again with a constant string
	const UnicodeString constUtf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	UnicodeString::const_reverse_iterator constStringIterator = constUtf8UnicodeString.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*constStringIterator)[0]);

	const UnicodeString constUtf8UnicodeStringTwo = Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	constStringIterator = constUtf8UnicodeStringTwo.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*constStringIterator)[2]);

	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	stringIterator = unicodeString.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)*stringIterator)[0]);

	unicodeString = Utf16String(L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB");

	stringIterator = unicodeString.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)*stringIterator)[1]);

	//Run the test again with a constant string
	const UnicodeString constUtf16UnicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	constStringIterator = constUtf16UnicodeString.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)*constStringIterator)[0]);

	UnicodeString constUtf16UnicodeStringTwo = Utf16String(L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB");

	constStringIterator = constUtf16UnicodeStringTwo.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)*constStringIterator)[1]);
}

void UnicodeStringTest::TestReplace()
{
	//Test with a UnicodeString containing a UTF-8 string
	//Create a UnicodeString containing a UTF-8 string, parts of which will be used to replace parts of other strings
	UnicodeString utf8String = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	//Create a UnicodeString containing a UTF-16 string, parts of which will be used to replace parts of other strings
	UnicodeString utf16String = Utf16String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	//Create a UTF-8 string that will be the string before replacement
	UnicodeString originalString = Utf8String("ẫö∑b\xF0\x90\x8D\x86");
	//Create a string on which the replace() function is to be called
	UnicodeString replaceString;

	//Create the string that results from a replace at the beginning of the string
	UnicodeString finalBeginReplaceString = Utf8String("\x53\xE1\xBA\xAB\x62ö∑b\xF0\x90\x8D\x86");
	//Create the string that results from a replace in the middle of the string
	UnicodeString finalMiddleReplaceString = Utf8String("ẫö\x53\xE1\xBA\xAB\x62" "b\xF0\x90\x8D\x86");
	//Create the string that results from a replace at the end of the string
	UnicodeString finalEndReplaceString = Utf8String("ẫö∑b\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	//Create the string that results from a replace where the replacement string is actually appended
	UnicodeString finalAppendReplaceString = Utf8String("ẫö∑b\xF0\x90\x8D\x86\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	//Create the string that results when the section begin iterator is at the same position as the
	//section end iterator
	UnicodeString finalSamePositionReplaceString = Utf8String("ẫö\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4" "∑b\xF0\x90\x8D\x86");
	//Create the string that results when the section begin iterator is pointing to a position
	//past that of the section end iterator
	UnicodeString finalEarlierPositionReplaceString = Utf8String("ẫö\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	//Create a UTF-8 character to be used as a replacement character
	Utf8Char utf8ReplacementCharacter = 'X';
	//Create a UTF-16 character to be used as a replacement character
	Utf16Char utf16ReplacementCharacter = 'X';
	//Create a string to use in storing the final result of a single character replacement
	UnicodeString singleCharacterReplaceString;

	//Test replacement with a UTF-8 string as a parameter
	//Test the replace() function that accepts size_t, size_t, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(0, 1, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(2, 1, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(4, 1, utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(5, 1, utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Test the replace() function that accepts size_t, size_t, size_t, Utf8Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = Utf8String("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(0, 1, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(2, 1, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(4, 10, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(5, 4, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);


	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Call replace() where the end iterator is pointing to the same place as the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 2, utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalSamePositionReplaceString, replaceString);

	//Call replace() where the end iterator is before the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin(), utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEarlierPositionReplaceString, replaceString);


	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, size_t, Utf8Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = Utf8String("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);


	//Test replacement with a UTF-16 string as a parameter
	//Test the replace() function that accepts size_t, size_t, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, utf16String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(0, 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(2, 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(4, 1, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(5, 1, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), utf16String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Call replace() where the end iterator is pointing to the same place as the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 2, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalSamePositionReplaceString, replaceString);

	//Call replace() where the end iterator is before the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin(), utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEarlierPositionReplaceString, replaceString);


	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, size_t, Utf16Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = Utf16String("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append(Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UTF-16 string that will be the string before replacement
	originalString = Utf16String("ẫö∑b\xF0\x90\x8D\x86");

	//Create the string that results from a replace at the beginning of the string
	finalBeginReplaceString = Utf16String("\x53\xE1\xBA\xAB\x62ö∑b\xF0\x90\x8D\x86");
	//Create the string that results from a replace in the middle of the string
	finalMiddleReplaceString = Utf16String("ẫö\x53\xE1\xBA\xAB\x62" "b\xF0\x90\x8D\x86");
	//Create the string that results from a replace at the end of the string
	finalEndReplaceString = Utf16String("ẫö∑b\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	//Create the string that results from a replace where the replacement string is actually appended
	finalAppendReplaceString = Utf16String("ẫö∑b\xF0\x90\x8D\x86\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	//Create the string that results when the section begin iterator is at the same position as the
	//section end iterator
	finalSamePositionReplaceString = Utf8String("ẫö\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4" "∑b\xF0\x90\x8D\x86");
	//Create the string that results when the section begin iterator is pointing to a position
	//past that of the section end iterator
	finalEarlierPositionReplaceString = Utf8String("ẫö\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Test replacement with a UTF-8 string as a parameter
	//Test the replace() function that accepts size_t, size_t, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(0, 1, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(2, 1, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(4, 1, utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(5, 1, utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Test the replace() function that accepts size_t, size_t, size_t, Utf8Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = Utf8String("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(0, 1, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(2, 1, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(4, 10, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(5, 4, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);


	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, utf8String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Call replace() where the end iterator is pointing to the same place as the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 2, utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalSamePositionReplaceString, replaceString);

	//Call replace() where the end iterator is before the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin(), utf8String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEarlierPositionReplaceString, replaceString);


	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, size_t, Utf8Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = Utf8String("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), 5, utf8ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(Utf8String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);


	//Test replacement with a UTF-16 string as a parameter
	//Test the replace() function that accepts size_t, size_t, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, utf16String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(0, 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(2, 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(4, 1, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(5, 1, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, UnicodeString
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), utf16String);

	CPPUNIT_ASSERT_EQUAL(utf8String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Call replace() where the end iterator is pointing to the same place as the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 2, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalSamePositionReplaceString, replaceString);

	//Call replace() where the end iterator is before the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin(), utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEarlierPositionReplaceString, replaceString);


	//Test the replace() function that accepts UnicodeString::iterator, UnicodeString::iterator, size_t, Utf16Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = Utf16String("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append(Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), 5, utf16ReplacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(Utf16String("XXXXX"));
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);
}

void UnicodeStringTest::TestReverseIterator()
{
	TestReverseIteratorWithStringOne();
	TestReverseIteratorWithStringTwo();
	TestReverseIteratorWithStringThree();
	TestReverseIteratorWithStringFour();
}

void UnicodeStringTest::TestRFind()
{
	//Create a UTF-8 string to be searched
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	size_t foundIndex;

	//Search using a UTF-8 search string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.rfind(Utf8String("\x53"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xC3\xB6"));

	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xF0\x92\x81\xA8"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.rfind(Utf8String("\x53\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.rfind(Utf8String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.rfind(Utf8String("\xC1\x87"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.rfind(Utf8String("\xE3\x89\xAA\x34\xC0\x99"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.rfind(Utf8String("\xE1\xBA\xAB"), 6);

	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);


	//Search using a UTF-16 search string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.rfind(Utf16String("\x53"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xC3\xB6"));

	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xF0\x92\x81\xA8"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.rfind(Utf16String("\x53\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.rfind(Utf16String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.rfind(Utf16String("\xC1\x87"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.rfind(Utf16String("\xE3\x89\xAA\x34\xC0\x99"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.rfind(Utf16String("\xE1\xBA\xAB"), 6);

	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);


	//Create a UTF-16 string to be searched
	unicodeString = Utf16String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Search using a UTF-8 search string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.rfind(Utf8String("\x53"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xC3\xB6"));

	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xF0\x92\x81\xA8"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.rfind(Utf8String("\x53\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.rfind(Utf8String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.rfind(Utf8String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.rfind(Utf8String("\xC1\x87"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.rfind(Utf8String("\xE3\x89\xAA\x34\xC0\x99"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.rfind(Utf8String("\xE1\xBA\xAB"), 6);

	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);


	//Search using a UTF-16 search string
	//Find a single character at the beginning of the string
	foundIndex = unicodeString.rfind(Utf16String("\x53"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xC3\xB6"));

	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xF0\x92\x81\xA8"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = unicodeString.rfind(Utf16String("\x53\xE1\xBA\xAB"));

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = unicodeString.rfind(Utf16String("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33"));

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = unicodeString.rfind(Utf16String("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4"));

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = unicodeString.rfind(Utf16String("\xC1\x87"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = unicodeString.rfind(Utf16String("\xE3\x89\xAA\x34\xC0\x99"));

	CPPUNIT_ASSERT_EQUAL(UnicodeString::npos, foundIndex);

	//Find a character using an offset
	foundIndex = unicodeString.rfind(Utf16String("\xE1\xBA\xAB"), 6);

	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);
}

void UnicodeStringTest::TestSize()
{
	//Use a UTF-8 string
	//Get the length of the default string
	UnicodeString unicodeString;

	CPPUNIT_ASSERT_EQUAL((size_t)0, unicodeString.size());

	//Get the size of a 0-length string
	unicodeString = Utf8String("");

	CPPUNIT_ASSERT_EQUAL((size_t)0, unicodeString.size());

	//Get the size of a single character (one code unit) string
	unicodeString = Utf8String("\x48");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.size());

	//Get the size of a single character (two code units) string
	unicodeString = Utf8String("\xC3\xB6");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.size());

	//Get the size of a single character (three code units) string
	unicodeString = Utf8String("\xE2\x88\x91");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.size());

	//Get the size of a single character (four code units) string
	unicodeString = Utf8String("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	unicodeString = Utf8String("Simple String");

	CPPUNIT_ASSERT_EQUAL((size_t)13, unicodeString.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	unicodeString = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	CPPUNIT_ASSERT_EQUAL((size_t)8, unicodeString.size());

	//Get the size of a multi-character string containing both one-, two-, and three-code-unit characters
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)9, unicodeString.size());

	//Get the size of a multi-character string containing both one-, two-, three- and four-code-unit characters
	unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)11, unicodeString.size());


	//Run the tests again with a constant string
	//Get the size of the default string
	const UnicodeString constUnicodeString;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUnicodeString.size());

	//Get the size of a 0-length string
	const UnicodeString constUnicodeString1 = Utf8String("");

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUnicodeString1.size());

	//Get the size of a single character (one code unit) string
	const UnicodeString constUnicodeString2 = Utf8String("\x48");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUnicodeString2.size());

	//Get the size of a single character (two code units) string
	const UnicodeString constUnicodeString3 = Utf8String("\xC3\xB6");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUnicodeString3.size());

	//Get the size of a single character (three code units) string
	const UnicodeString constUnicodeString4 = Utf8String("\xE2\x88\x91");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUnicodeString4.size());

	//Get the size of a single character (four code units) string
	const UnicodeString constUnicodeString5 = Utf8String("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUnicodeString5.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	const UnicodeString constUnicodeString6 = Utf8String("Simple String");

	CPPUNIT_ASSERT_EQUAL((size_t)13, constUnicodeString6.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	const UnicodeString constUnicodeString7 = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	CPPUNIT_ASSERT_EQUAL((size_t)8, constUnicodeString7.size());

	//Get the size of a multi-character string containing both one-, two-, and three-code-unit characters
	const UnicodeString constUnicodeString8 = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)9, constUnicodeString8.size());

	//Get the size of a multi-character string containing both one-, two-, three- and four-code-unit characters
	const UnicodeString constUnicodeString9 = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)11, constUnicodeString9.size());

	//Test with a UTF-16 string
	//Get the size of a 0-length string
	unicodeString = Utf16String(L"");

	CPPUNIT_ASSERT_EQUAL((size_t)0, unicodeString.size());

	//Get the size of a single character (one code unit) string
	unicodeString = Utf16String(L"\x2211");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.size());

	//Get the size of a single character (two code units) string
	unicodeString = Utf16String(L"\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)1, unicodeString.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	unicodeString = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");

	CPPUNIT_ASSERT_EQUAL((size_t)9, unicodeString.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)12, unicodeString.size());

	//Now run the tests again with constant string
	//Get the size of the default string
	const UnicodeString constUtf16String1;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16String1.size());

	//Get the size of a 0-length string
	const UnicodeString constUtf16String2 = Utf16String(L"");

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16String2.size());

	//Get the size of a single character (one code unit) string
	const UnicodeString constUtf16String3 = Utf16String(L"\x2211");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf16String3.size());

	//Get the size of a single character (two code units) string
	const UnicodeString constUtf16String4 = Utf16String(L"\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf16String4.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	const UnicodeString constUtf16String5 = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");

	CPPUNIT_ASSERT_EQUAL((size_t)9, constUtf16String5.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	const UnicodeString constUtf16String6 = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)12, constUtf16String6.size());
}

void UnicodeStringTest::TestStreamOperators()
{
	stringstream stringStream;

	//Test with a UTF-8 string
	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB \x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB \t\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	UnicodeString deserializedString;

	//Write the string to a stream
	stringStream << unicodeString;

	//Reset the read stream position to the beginning
	stringStream.seekg(0, ios::beg);

	//Now read in a string from the stream.  Every time the >> operator is called, we should retrieve
	//the parts of the string up until whitespace is encountered, with the whitespace not included
	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)deserializedString[1])[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)deserializedString[1])[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)deserializedString[1])[2]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)deserializedString[1])[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)deserializedString[1])[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)deserializedString[1])[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)deserializedString[1])[3]);
	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)deserializedString[2])[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)deserializedString[2])[1]);
	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)deserializedString[3])[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)deserializedString[3])[1]);
	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)deserializedString[4])[0]);
	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)deserializedString[5])[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)deserializedString[5])[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)deserializedString[5])[2]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)3, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)3, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)deserializedString[0])[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)deserializedString[0])[2]);
	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)deserializedString[1])[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)deserializedString[1])[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)deserializedString[1])[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)deserializedString[1])[3]);
	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)deserializedString[2])[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)deserializedString[2])[1]);

	//Test with a UTF-16 string
	//Reset the write stream position to the beginning
	stringStream.seekp(0, ios::beg);

	//Create a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB \x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB \x2211\xD800\xDF46\x0434\xD808\xDC68");
	
	//Assign a UTF-16 string to deserializedString so that we read UTF-16 characters from the stream instead of UTF-8 characters
	deserializedString = Utf16String();

	//Write the string to a stream
	stringStream << unicodeString;

	//Reset the read stream position to the beginning
	stringStream.seekg(0, ios::beg);

	//Now read in a string from the stream.  Every time the >> operator is called, we should retrieve
	//the parts of the string up until a space, with the space character not included
	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)deserializedString[1])[0]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', ((Utf16Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)deserializedString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)deserializedString[1])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', ((Utf16Char)deserializedString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', ((Utf16Char)deserializedString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)deserializedString[4])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)deserializedString[5])[0]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', ((Utf16Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', ((Utf16Char)deserializedString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', ((Utf16Char)deserializedString[1])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', ((Utf16Char)deserializedString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)deserializedString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)deserializedString[3])[1]);

	//Now repeat the tests for the wide stream operators
	wstringstream wideStringStream;

	//Write the string to a stream
	wideStringStream << unicodeString;

	//Reset the read stream position to the beginning
	wideStringStream.seekg(0, ios::beg);

	//Now read in a string from the stream.  Every time the >> operator is called, we should retrieve
	//the parts of the string up until a space, with the space character not included
	wideStringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)deserializedString[1])[0]);

	wideStringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', ((Utf16Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)deserializedString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)deserializedString[1])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', ((Utf16Char)deserializedString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', ((Utf16Char)deserializedString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)deserializedString[4])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)deserializedString[5])[0]);

	wideStringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', ((Utf16Char)deserializedString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', ((Utf16Char)deserializedString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', ((Utf16Char)deserializedString[1])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', ((Utf16Char)deserializedString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)deserializedString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)deserializedString[3])[1]);
}

void UnicodeStringTest::TestSubstr()
{
	//Test with a UTF-8 string
	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	//Get a substring starting at index 0
	UnicodeString subString = unicodeString.substr(0, 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\x53");
	CPPUNIT_ASSERT(subString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[2] == "\x62");
	CPPUNIT_ASSERT(subString[3] == "\xF0\x92\x81\xA8");
	CPPUNIT_ASSERT(subString[4] == "\xC3\xB6");

	//Get a substring from the middle of the string
	subString = unicodeString.substr(5, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xC3\x9F");
	CPPUNIT_ASSERT(subString[1] == "\x33");
	CPPUNIT_ASSERT(subString[2] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[3] == "\xE2\x88\x91");

	//Get a substring that ends on the last character of the string
	subString = unicodeString.substr(7, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[1] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(subString[2] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(subString[3] == "\xD0\xB4");

	//Get a substring where the count extends past the end of the string
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[1] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(subString[2] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(subString[3] == "\xD0\xB4");

	//Get a substring of length 0
	subString = unicodeString.substr(7, 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.size());
	
	//Get a substring of length 1
	subString = unicodeString.substr(7, 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)1, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xE1\xBA\xAB");

	//Get a substring using only the first parameter
	subString = unicodeString.substr(6);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\x33");
	CPPUNIT_ASSERT(subString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[2] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(subString[3] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(subString[4] == "\xD0\xB4");

	//Get a substring using no parameters
	subString = unicodeString.substr();

	CPPUNIT_ASSERT(unicodeString == subString);

	//Test with a UTF-16 string
	//Create a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");

	//Get a substring starting at index 0 of only one-code-unit characters
	subString = unicodeString.substr(0, 3);

	CPPUNIT_ASSERT_EQUAL((size_t)3, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)3, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)subString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', ((Utf16Char)subString[2])[0]);

	//Get a substring starting at index 0 of one- and two-code-unit characters
	subString = unicodeString.substr(0, 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)subString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', ((Utf16Char)subString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)subString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)subString[3])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', ((Utf16Char)subString[4])[0]);

	//Get a substring from the middle of the string composing of only one-code-unit characters
	subString = unicodeString.substr(5, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', ((Utf16Char)subString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)subString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', ((Utf16Char)subString[3])[0]);

	//Get a substring from the middle of the string composing of one- and two-code-unit characters
	subString = unicodeString.substr(7, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', ((Utf16Char)subString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', ((Utf16Char)subString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', ((Utf16Char)subString[2])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', ((Utf16Char)subString[3])[0]);

	//Get a substring that ends on the last character of the string
	subString = unicodeString.substr(7, 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', ((Utf16Char)subString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', ((Utf16Char)subString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', ((Utf16Char)subString[2])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', ((Utf16Char)subString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)subString[4])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)subString[4])[1]);

	//Get a substring where the count extends past the end of the string
	subString = unicodeString.substr(7, 10);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', ((Utf16Char)subString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', ((Utf16Char)subString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', ((Utf16Char)subString[2])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', ((Utf16Char)subString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)subString[4])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)subString[4])[1]);

	//Get a substring of length 0
	subString = unicodeString.substr(7, 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.size());
	
	//Get a substring of length 1
	subString = unicodeString.substr(7, 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)1, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[0])[0]);

	//Get a substring using only the first parameter
	subString = unicodeString.substr(6);
	CPPUNIT_ASSERT_EQUAL((size_t)6, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)6, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', ((Utf16Char)subString[0])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', ((Utf16Char)subString[1])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', ((Utf16Char)subString[2])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', ((Utf16Char)subString[3])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', ((Utf16Char)subString[3])[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', ((Utf16Char)subString[4])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', ((Utf16Char)subString[5])[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', ((Utf16Char)subString[5])[1]);

	//Get a substring using no parameters
	subString = unicodeString.substr();

	CPPUNIT_ASSERT(unicodeString == subString);
}

void UnicodeStringTest::TestSwap()
{
	//Test with a UTF=8 string
	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB \x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB \t\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	UnicodeString secondString = Utf8String("\xF4\x94\xA2\x88\x85");
	UnicodeString emptyString;

	UnicodeString firstSwapString;
	UnicodeString secondSwapString;

	//Swap two strings
	firstSwapString = unicodeString;
	secondSwapString = secondString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(secondString, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(unicodeString, secondSwapString);

	//Swap the two string back
	secondSwapString.swap(firstSwapString);

	CPPUNIT_ASSERT_EQUAL(unicodeString, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(secondString, secondSwapString);

	//Swap a populated string with an empty string
	firstSwapString = unicodeString;
	secondSwapString = emptyString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, emptyString);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, unicodeString);

	//Swap an empty string with a populated string
	firstSwapString = emptyString;
	secondSwapString = unicodeString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, unicodeString);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, emptyString);


	//Test using a UTF-16 string
	//Create a UTF-16 string composed of one- and two-code-unit characters
	unicodeString = Utf16String(L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68");
	secondString = Utf16String(L"\xD8A0\xDC79\x803C\x0085");

	//Swap two strings
	firstSwapString = unicodeString;
	secondSwapString = secondString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(secondString, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(unicodeString, secondSwapString);

	//Swap the two string back
	secondSwapString.swap(firstSwapString);

	CPPUNIT_ASSERT_EQUAL(unicodeString, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(secondString, secondSwapString);

	//Swap a populated string with an empty string
	firstSwapString = unicodeString;
	secondSwapString = emptyString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, emptyString);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, unicodeString);

	//Swap an empty string with a populated string
	firstSwapString = emptyString;
	secondSwapString = unicodeString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, unicodeString);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, emptyString);
}

/*Private Helper Functions*/

void UnicodeStringTest::TestConstructorsWithStrings(const UtfString::Utf8String& utf8String, 
												 const UtfString::Utf16String& utf16String)
{
	//Create a UnicodeString using the constructor that accepts a Utf16String
	UnicodeString* constructedString = new UnicodeString(utf16String);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT(*constructedString == utf16String);
	CPPUNIT_ASSERT(utf16String == *constructedString);

	CPPUNIT_ASSERT(constructedString->internal_encoding() == ENCODING_UTF16);

	delete constructedString;
	constructedString = NULL;

	//Create a UnicodeString using the constructor that accepts a Utf8String
	constructedString = new UnicodeString(utf8String);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT(*constructedString == utf8String);
	CPPUNIT_ASSERT(utf8String == *constructedString);
	CPPUNIT_ASSERT(constructedString->internal_encoding() == ENCODING_UTF8);

	delete constructedString;
	constructedString = NULL;
}

void UnicodeStringTest::TestConstIteratorWithStringOne()
{
	//Create a UnicodeString containing a UTF-8 string with only ASCII characters
	const UnicodeString unicodeString = Utf8String("Simple String");
	
	//Get an iterator to the beginning of the string
	UnicodeString::const_iterator stringIterator = unicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = unicodeString.length();

	while(stringIterator != unicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());

		//The fourth character should be a 'p'
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a 'g'
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('g', ((Utf8Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = unicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != unicodeString.end());

	stringIterator = unicodeString.end();
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the += operator
	stringIterator = unicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the + operator
	stringIterator = unicodeString.begin();
	UnicodeString::const_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.end());

	//Test the -= operator
	stringIterator = unicodeString.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == unicodeString.begin());

	//Test the - operator
	stringIterator = unicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with only ASCII characters
	const UnicodeString utf16UnicodeString = Utf16String(L"Simple String");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "p"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "g"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestConstIteratorWithStringTwo()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1- and 2-byte UTF-8 characters
	const UnicodeString unicodeString = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	//Get an iterator to the beginning of the string
	UnicodeString::const_iterator stringIterator = unicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xCF', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', ((Utf8Char)*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = unicodeString.length();

	while(stringIterator != unicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than two code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= 1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= 2);

		//The third character should be a "\x34"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);
		}

		//The fifth character should be a "\xD1\x8A"
		if(characterCount == 4)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = unicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != unicodeString.end());

	stringIterator = unicodeString.end();
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the += operator
	stringIterator = unicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the + operator
	stringIterator = unicodeString.begin();
	UnicodeString::const_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.end());

	//Test the -= operator
	stringIterator = unicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xCF', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', ((Utf8Char)*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xCF', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', ((Utf8Char)*stringIterator)[1]);

	stringIterator -= 5;

	CPPUNIT_ASSERT(stringIterator == unicodeString.begin());

	//Test the - operator
	stringIterator = unicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing UTF-16 string with characters that correspond to 1- or 2-code-unit characters in UTF-8
	const UnicodeString utf16UnicodeString = Utf16String(L"\x03C9\x0045\x0034\x06BD\x0068\x044A");

	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "\x06BD"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);
		}

		//The seventh character should be a "\x044A"
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestConstIteratorWithStringThree()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, and 3-byte UTF-8 characters
	const UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::const_iterator stringIterator = unicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = unicodeString.length();

	while(stringIterator != unicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than three code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= 1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= 3);

		//The third character should be a '\x62'
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\xE2\x88\x91"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = *--stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (Utf8Char)*stringIterator--;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = *++stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (Utf8Char)*stringIterator++;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = unicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != unicodeString.end());

	stringIterator = unicodeString.end();
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the += operator
	stringIterator = unicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the + operator
	stringIterator = unicodeString.begin();
	UnicodeString::const_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*newStringIterator)[1]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.end());

	//Test the -= operator
	stringIterator = unicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == unicodeString.begin());

	//Test the - operator
	stringIterator = unicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Create a UnicodeString containing a UTF-16 string with characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	const UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The third character should be a "\x0062"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\x2211"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestConstIteratorWithStringFour()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	const UnicodeString unicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::const_iterator stringIterator = unicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = unicodeString.length();

	while(stringIterator != unicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and four code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= (size_t)4);

		//The second character should be a "\xE1\xBA\xAB"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		//The fourth character should be a "\xF0\x92\x81\xA8"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*stringIterator)[1]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = ((Utf8Char)*--stringIterator);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = ((Utf8Char)*stringIterator--);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = ((Utf8Char)*++stringIterator);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = ((Utf8Char)*stringIterator++);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);
		}

		//The tenth character should be a "\xF0\x90\x8D\x86"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*stringIterator)[3]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = unicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != unicodeString.end());

	stringIterator = unicodeString.end();
	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the += operator
	stringIterator = unicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);


	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == unicodeString.end());

	//Test the + operator
	stringIterator = unicodeString.begin();
	UnicodeString::const_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*newStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*newStringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*newStringIterator)[3]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*stringIterator)[3]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.end());

	//Test the -= operator
	stringIterator = unicodeString.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == unicodeString.begin());

	//Test the - operator
	stringIterator = unicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == unicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = unicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	const UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == ((Utf16Char)*stringIterator).size() || (size_t)2 == ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "\xD808\xDC68"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);
		}

		//The sixth character should be a "\x00DF"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);
		}

		//The tenth character should be a "\xD800\xDF46"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), ((Utf16Char)*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 8;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestConstReverseIteratorWithStringOne()
{
	//Create a UnicodeString containing a UTF-8 string with only ASCII characters
	const UnicodeString utf8UnicodeString = Utf8String("Simple String");
	
	//Get an reverse iterator to the end of the string
	UnicodeString::const_reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('g', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());

		//The fourth character should be a 'r'
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::const_reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with only ASCII characters
	const UnicodeString utf16UnicodeString = Utf16String(L"Simple String");
	
	//Get an reverse iterator to the end of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "r"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestConstReverseIteratorWithStringTwo()
{
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	const UnicodeString utf8UnicodeString = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	//Get an iterator to the beginning of the string
	UnicodeString::const_reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should one or two code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= (size_t)2);

		//The fourth character should be a "\xD1\x8A"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);
		}

		//The fifth character should be a '\x34'
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::const_reverse_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with characters that correspond to 1- or 2-code-unit characters in UTF-8
	const UnicodeString utf16UnicodeString = Utf16String(L"\x03C9\x0045\x0034\x06BD\x0068\x044A");

	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "x0034"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);
		}

		//The fifth character should be a "\x03C9"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestConstReverseIteratorWithStringThree()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	const UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::const_reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and three code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= (size_t)3);

		//The third character should be a "\xE1\xBA\xAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::const_reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;
                               
	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	
	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	const UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The third character should be a "\x1EAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestConstReverseIteratorWithStringFour()
{
	//Create a UnicodeString containing UTF-8 string with a mix of 1-, 2-, and 3-byte UTF-8 characters
	const UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::const_reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and three code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= (size_t)3);

		//The third character should be a "\xE1\xBA\xAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::const_reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;
                               
	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	const UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == ((Utf16Char)*stringIterator).size() || (size_t)2 == ((Utf16Char)*stringIterator).size());

		//The second character should be a "\xD800\xDF46"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);
		}

		//The fourth character should be a "\x1EAB"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\xD808\xDC68"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestIteratorWithStringOne()
{
	//Create a UnicodeString containing a UTF-8 string with only ASCII characters
	UnicodeString utf8UnicodeString = Utf8String("Simple String");
	
	//Get an iterator to the beginning of the string
	UnicodeString::iterator stringIterator = utf8UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());

		//The fourth character should be a "p"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "g"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('g', ((Utf8Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.end());

	stringIterator = utf8UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the += operator
	stringIterator = utf8UnicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the + operator
	stringIterator = utf8UnicodeString.begin();
	UnicodeString::iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.end());

	//Test the -= operator
	stringIterator = utf8UnicodeString.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.begin());

	//Test the - operator
	stringIterator = utf8UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with only ASCII characters
	UnicodeString utf16UnicodeString = Utf16String(L"Simple String");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "p"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "g"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestIteratorWithStringTwo()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1- and 2-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	//Get an iterator to the beginning of the string
	UnicodeString::iterator stringIterator = utf8UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xCF', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', ((Utf8Char)*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than two code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= 1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= 2);

		//The third character should be a "\x34"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);
		}

		//The fifth character should be a "\xD1\x8A"
		if(characterCount == 4)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.end());

	stringIterator = utf8UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the += operator
	stringIterator = utf8UnicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the + operator
	stringIterator = utf8UnicodeString.begin();
	UnicodeString::iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.end());

	//Test the -= operator
	stringIterator = utf8UnicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xCF', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', ((Utf8Char)*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xCF', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', ((Utf8Char)*stringIterator)[1]);

	stringIterator -= 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.begin());

	//Test the - operator
	stringIterator = utf8UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with characters that correspond to 1- or 2-code-unit characters in UTF-8
	UnicodeString utf16UnicodeString = Utf16String(L"\x03C9\x0045\x0034\x06BD\x0068\x044A");

	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "\x06BD"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);
		}

		//The seventh character should be a "\x044A"
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestIteratorWithStringThree()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, and 3-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::iterator stringIterator = utf8UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than three code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= 1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= 3);

		//The third character should be a '\x62'
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\xE2\x88\x91"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = *--stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (Utf8Char)*stringIterator--;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = (Utf8Char)*++stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (Utf8Char)*stringIterator++;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.end());

	stringIterator = utf8UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the += operator
	stringIterator = utf8UnicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the + operator
	stringIterator = utf8UnicodeString.begin();
	UnicodeString::iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*newStringIterator)[1]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.end());

	//Test the -= operator
	stringIterator = utf8UnicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.begin());

	//Test the - operator
	stringIterator = utf8UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The third character should be a "\x0062"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\x2211"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestIteratorWithStringFour()
{
	//Create a UnicodeString containing UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::iterator stringIterator = utf8UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either between 1 and four code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1 && ((Utf8Char)*stringIterator).size() <= (size_t)4);

		//The fourth character should be a "\xF0\x92\x81\xA8"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);
		}

		//The sixth character should be a "\xC3\x9F"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);
		}

		//The tenth character should be a "\xF0\x90\x8D\x86"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*stringIterator)[3]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*stringIterator)[1]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*stringIterator)[3]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = (*--stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = ((Utf8Char)*stringIterator--);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = ((Utf8Char)*++stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = ((Utf8Char)*stringIterator++);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*stringIterator)[3]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.end());

	stringIterator = utf8UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the += operator
	stringIterator = utf8UnicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.end());

	//Test the + operator
	stringIterator = utf8UnicodeString.begin();
	UnicodeString::iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*newStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*newStringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*newStringIterator)[3]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*stringIterator)[3]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.end());

	//Test the -= operator
	stringIterator = utf8UnicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE2', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', ((Utf8Char)*stringIterator)[2]);

	stringIterator -= 8;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.begin());

	//Test the - operator
	stringIterator = utf8UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == ((Utf16Char)*stringIterator).size() || (size_t)2 == ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "\xD808\xDC68"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);
		}

		//The sixth character should be a "\x00DF"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);
		}

		//The tenth character should be a "\xD800\xDF46"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), ((Utf16Char)*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.begin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.end());

	stringIterator = utf16UnicodeString.end();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the += operator
	stringIterator = utf16UnicodeString.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.end());

	//Test the + operator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.end());

	//Test the -= operator
	stringIterator = utf16UnicodeString.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 8;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.begin());

	//Test the - operator
	stringIterator = utf16UnicodeString.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.begin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestReverseIteratorWithStringOne()
{
	//Create a UnicodeString containing a UTF-8 string with only ASCII characters
	UnicodeString utf8UnicodeString = Utf8String("Simple String");
	
	//Get an reverse iterator to the end of the string
	UnicodeString::reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('g', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());

		//The fourth character should be a 'r'
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', ((Utf8Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('S', ((Utf8Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('t', ((Utf8Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('r', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('p', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('l', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with only ASCII characters
	UnicodeString utf16UnicodeString = Utf16String(L"Simple String");
	
	//Get an reverse iterator to the end of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "r"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), ((Utf16Char)*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 6;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestReverseIteratorWithStringTwo()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1- and 2-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34");

	//Get an iterator to the beginning of the string
	UnicodeString::reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should one or two code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= (size_t)2);

		//The fourth character should be a "\xD1\x8A"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);
		}

		//The fifth character should be a '\x34'
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', ((Utf8Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::reverse_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x45', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with characters that correspond to 1- or 2-code-unit characters in UTF-8
	UnicodeString utf16UnicodeString = Utf16String(L"\x03C9\x0045\x0034\x06BD\x0068\x044A");

	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The fourth character should be a "x0034"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);
		}

		//The fifth character should be a "\x03C9"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 2;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 1;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestReverseIteratorWithStringThree()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, and 3-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and three code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= (size_t)3);

		//The third character should be a "\xE1\xBA\xAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x33', ((Utf8Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;
                               
	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());

		//The third character should be a "\x1EAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

void UnicodeStringTest::TestReverseIteratorWithStringFour()
{
	//Create a UnicodeString containing a UTF-8 string with a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	UnicodeString utf8UnicodeString = Utf8String("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	
	//Get an iterator to the beginning of the string
	UnicodeString::reverse_iterator stringIterator = utf8UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', ((Utf8Char)*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8UnicodeString.length();

	while(stringIterator != utf8UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and four code units
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT(((Utf8Char)*stringIterator).size() <= (size_t)4);

		//The second character should be a "\xF0\x90\x8D\x86"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', ((Utf8Char)*stringIterator)[3]);
		}

		//The fourth character should be a "\xE1\xBA\xAB"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);
		}

		//The eighth character should be a "\xF0\x92\x81\xA8"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf8Char)*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x62', ((Utf8Char)*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = (*--stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = ((Utf8Char)*stringIterator--);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x9F', ((Utf8Char)*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = ((Utf8Char)*++stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = ((Utf8Char)*stringIterator++);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)4, ((Utf8Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8UnicodeString.rend());

	stringIterator = utf8UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the += operator
	stringIterator = utf8UnicodeString.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rend());

	//Test the + operator
	stringIterator = utf8UnicodeString.rbegin();
	UnicodeString::reverse_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*newStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*newStringIterator)[2]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', ((Utf8Char)*stringIterator)[2]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf8UnicodeString.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', ((Utf8Char)*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', ((Utf8Char)*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', ((Utf8Char)*stringIterator)[3]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf8UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf8UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', ((Utf8Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', ((Utf8Char)*stringIterator)[1]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf8UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);


	//Test with a UnicodeString containing a UTF-16 string
	//Create a UnicodeString containing a UTF-16 string with 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	UnicodeString utf16UnicodeString = Utf16String(L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434");
	
	//Get an iterator to the beginning of the string
	stringIterator = utf16UnicodeString.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), ((Utf16Char)*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	characterCount = 0;
	stringLength = utf16UnicodeString.length();

	while(stringIterator != utf16UnicodeString.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == ((Utf16Char)*stringIterator).size() || (size_t)2 == ((Utf16Char)*stringIterator).size());

		//The second character should be a "\xD800\xDF46"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), ((Utf16Char)*stringIterator)[1]);
		}

		//The fourth character should be a "\x1EAB"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);
		}

		//The eighth character should be a "\xD808\xDC68"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), ((Utf16Char)*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), ((Utf16Char)*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, ((Utf16Char)*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16UnicodeString.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16UnicodeString.rend());

	stringIterator = utf16UnicodeString.rend();
	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the += operator
	stringIterator = utf16UnicodeString.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rend());

	//Test the + operator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rend());

	//Test the -= operator
	stringIterator = utf16UnicodeString.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), ((Utf16Char)*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), ((Utf16Char)*stringIterator)[1]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf16UnicodeString.rbegin());

	//Test the - operator
	stringIterator = utf16UnicodeString.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), ((Utf16Char)*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16UnicodeString.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator < newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator < newStringIterator));

	//Test the <= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator <= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(!(stringIterator <= newStringIterator));

	//Test the > operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(!(stringIterator > newStringIterator));

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator > newStringIterator);

	//Test the >= operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16UnicodeString.rbegin();
	newStringIterator = stringIterator + 4;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the operator when one iterator is one before the other iterator
	stringIterator += 3;

	CPPUNIT_ASSERT(!(stringIterator >= newStringIterator));

	//Test the iterator when the iterators are equal
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is one after the other iterator
	++stringIterator;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);

	//Test the operator when one iterator is a ways after the other iterator
	stringIterator += 4;

	CPPUNIT_ASSERT(stringIterator >= newStringIterator);
}

