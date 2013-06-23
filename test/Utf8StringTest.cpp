/*!
\file Utf8StringTest.cpp

This file contains the definition of the Utf8StringTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <sstream>
#include <string>

#include "Utf8StringTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void Utf8StringTest::TestAppend()
{
	//Test the append functionality with a strings composed of 1-, 2-, and 3-byte UTF-8 characters,
	//and single-code-unit UTF-16 characters
	//Create a standard string class containing a 1-, 2-, and 3-byte UTF-8 characters
	string characterString = "Sẫböß3ẫ∑д";
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create a UTF-8 string that will be appended to
	Utf8String originalString = "∑Sbö";
	//Create the UTF-16 string that results from an append operation
	Utf8String finalString = "∑SböSẫböß3ẫ∑д";

	//Create a wstring version of the UTF-16 string to be appended
	wstring wideString;

	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the append() function that accepts a Utf8String
	Utf8String appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a string
	appendedString = originalString;
	appendedString.append((string)utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char*
	appendedString = originalString;
	appendedString.append(utf8String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char* and a size_t
	appendedString = originalString;
	appendedString.append(utf8String.c_str(), utf8String.size());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a wchar_t*
	appendedString = originalString;
	appendedString.append(wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a wchar_t* and a size_t
	appendedString = originalString;
	appendedString.append(wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a wstring
	appendedString = originalString;
	appendedString.append(wideString);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf16String
	appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append functionality with a strings composed of 1-, 2-, and 3-byte UTF-8 characters,
	//and single-code-unit UTF-16 characters
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	characterString = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UTF-8 string that will be appended to
	originalString = "ẫ∑\xF0\x90\x8D\x86";
	//Create the UTF-8 string that results from an append operation
	finalString = "ẫ∑\xF0\x90\x8D\x86\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";

	//Create a wstring version of the UTF-16 string to be appended
	wideString.clear();
	codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the append() function that accepts a Utf8String
	appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a string
	appendedString = originalString;
	appendedString.append((string)utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char*
	appendedString = originalString;
	appendedString.append(utf8String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char* and a size_t
	appendedString = originalString;
	appendedString.append(utf8String.c_str(), utf8String.size());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a wchar_t*
	appendedString = originalString;
	appendedString.append(wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a wchar_t* and a size_t
	appendedString = originalString;
	appendedString.append(wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a wstring
	appendedString = originalString;
	appendedString.append(wideString);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf16String
	appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf8Char

	//Create a UTF-8 string that will be the result of appending a one-code-unit character
	Utf8String oneCodeUnitFinalString = "ẫ∑\xF0\x90\x8D\x86\x53";
	//Create a UTF-8 string that will be the result of appending a two-code-unit character
	Utf8String twoCodeUnitFinalString = "ẫ∑\xF0\x90\x8D\x86ö";
	//Create a UTF-8 string that will be the result of appending a three-code-unit character
	Utf8String threeCodeUnitFinalString = "ẫ∑\xF0\x90\x8D\x86ẫ";
	//Create a UTF-8 string that will be the result of appending a four-code-unit character
	Utf8String fourCodeUnitFinalString = "ẫ∑\xF0\x90\x8D\x86\xF0\x92\x81\xA8";

	//Append a one-code-unit character
	appendedString = originalString;
	appendedString.append(utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, appendedString);

	//Append a two-code-unit character
	appendedString = originalString;
	appendedString.append(utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, appendedString);

	//Append a three-code-unit character
	appendedString = originalString;
	appendedString.append(utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitFinalString, appendedString);

	//Append a four-code-unit character
	appendedString = originalString;
	appendedString.append(utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitFinalString, appendedString);
}

void Utf8StringTest::TestAssign()
{
	//Test the assign functionality with a strings composed of 1-, 2-, and 3-byte UTF-8 characters,
	//and single-code-unit UTF-16 characters
	//Create a standard string class containing a 1-, 2-, and 3-byte UTF-8 characters
	string characterString = "Sẫböß3ẫ∑д";
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create a UTF-8 string that will be assigned to
	Utf8String originalString = "∑Sbö";

	//Create a wstring version of the UTF-16 string to be assigned
	wstring wideString;

	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the assign() function that accepts a Utf8String
	Utf8String assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a string
	assignedString = originalString;
	assignedString.assign((string)utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a char*
	assignedString = originalString;
	assignedString.assign(utf8String.c_str());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a char* and a size_t
	assignedString = originalString;
	assignedString.assign(utf8String.c_str(), utf8String.size());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a wchar_t*
	assignedString = originalString;
	assignedString.assign(wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a wchar_t* and a size_t
	assignedString = originalString;
	assignedString.assign(wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a wstring
	assignedString = originalString;
	assignedString.assign(wideString);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a Utf16String
	assignedString = originalString;
	assignedString.assign(utf16String);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign functionality with a strings composed of 1-, 2-, and 3-byte UTF-8 characters,
	//and single-code-unit UTF-16 characters
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	characterString = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UTF-8 string that will be appended to
	originalString = "ẫ∑\xF0\x90\x8D\x86";

	//Create a wstring version of the UTF-16 string to be assigned
	wideString.clear();
	codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a string
	assignedString = originalString;
	assignedString.assign((string)utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a char*
	assignedString = originalString;
	assignedString.assign(utf8String.c_str());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a char* and a size_t
	assignedString = originalString;
	assignedString.assign(utf8String.c_str(), utf8String.size());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a wchar_t*
	assignedString = originalString;
	assignedString.assign(wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a wchar_t* and a size_t
	assignedString = originalString;
	assignedString.assign(wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a wstring
	assignedString = originalString;
	assignedString.assign(wideString);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(utf8String, assignedString);

	//Test the assign() function that accepts a Utf16Char

	//Create a UTF-8 string that will be the result of assigning a one-code-unit character
	Utf8String oneCodeUnitFinalString = "\x53";
	//Create a UTF-8 string that will be the result of assigning a two-code-unit character
	Utf8String twoCodeUnitFinalString = "ö";
	//Create a UTF-8 string that will be the result of assigning a three-code-unit character
	Utf8String threeCodeUnitFinalString = "ẫ";
	//Create a UTF-8 string that will be the result of assigning a four-code-unit character
	Utf8String fourCodeUnitFinalString = "\xF0\x92\x81\xA8";

	//Assign a one-code-unit character
	assignedString = originalString;
	assignedString.assign(utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, assignedString);

	//Assign a two-code-unit character
	assignedString = originalString;
	assignedString.assign(utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, assignedString);

	//Assign a three-code-unit character
	assignedString = originalString;
	assignedString.assign(utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitFinalString, assignedString);

	//Assign a four-code-unit character
	assignedString = originalString;
	assignedString.assign(utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitFinalString, assignedString);

}

void Utf8StringTest::TestAt()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Get the character at the beginning of the string
	Utf8Char character = utf8String.at(0);

	CPPUNIT_ASSERT_EQUAL((size_t)1, character.size());
	CPPUNIT_ASSERT_EQUAL('\x53', character[0]);

	//Get the character at the end of the string
	character = utf8String.at(utf8String.length() - 1);

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	CPPUNIT_ASSERT_EQUAL('\xD0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', character[1]);

	//Get a two-code-unit character in the middle of the string
	character = utf8String.at(5);

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', character[1]);

	//Get a four-code-unit character in the middle of the string
	character = utf8String.at(3);

	CPPUNIT_ASSERT_EQUAL((size_t)4, character.size());
	CPPUNIT_ASSERT_EQUAL('\xF0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', character[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', character[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', character[3]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a character just past the end of the string
	CPPUNIT_ASSERT_THROW(utf8String.at(utf8String.length()), std::out_of_range);

	//Attempt to get a character way past the end of the string
	CPPUNIT_ASSERT_THROW(utf8String.at(utf8String.length() + 23), std::out_of_range);

	#pragma warning (pop)

	//Repeat the same tests with a constant string
	const Utf8String constUtf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Get the character at the beginning of the string
	character = constUtf8String.at(0);

	CPPUNIT_ASSERT_EQUAL((size_t)1, character.size());
	CPPUNIT_ASSERT_EQUAL('\x53', character[0]);

	//Get the character at the end of the string
	character = constUtf8String.at(constUtf8String.length() - 1);

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	CPPUNIT_ASSERT_EQUAL('\xD0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', character[1]);

	//Get a two-code-unit character in the middle of the string
	character = constUtf8String.at(5);

	CPPUNIT_ASSERT_EQUAL((size_t)2, character.size());
	CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', character[1]);

	//Get a four-code-unit character in the middle of the string
	character = constUtf8String.at(3);

	CPPUNIT_ASSERT_EQUAL((size_t)4, character.size());
	CPPUNIT_ASSERT_EQUAL('\xF0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', character[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', character[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', character[3]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a character just past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf8String.at(constUtf8String.length()), std::out_of_range);

	//Attempt to get a character way past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf8String.at(constUtf8String.length() + 23), std::out_of_range);

	#pragma warning (pop)
}

void Utf8StringTest::TestBegin()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8String::iterator stringIterator = utf8String.begin();

	CPPUNIT_ASSERT_EQUAL('\x53', (*stringIterator)[0]);

	utf8String = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	stringIterator = utf8String.begin();

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	const Utf8String constUtf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8String::const_iterator constStringIterator = constUtf8String.begin();

	CPPUNIT_ASSERT_EQUAL('\x53', (*constStringIterator)[0]);

	const Utf8String constUtf8StringTwo = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	constStringIterator = constUtf8StringTwo.begin();

	CPPUNIT_ASSERT_EQUAL('\xF0', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*constStringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*constStringIterator)[3]);
}

void Utf8StringTest::TestCapacity()
{
	Utf8String utf8String;

	CPPUNIT_ASSERT(utf8String.size() <= utf8String.capacity());

	utf8String.append("Bob");

	CPPUNIT_ASSERT(utf8String.size() <= utf8String.capacity());

	utf8String.append("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT(utf8String.size() <= utf8String.capacity());

	Utf8String appendString = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	utf8String.append(appendString);

	CPPUNIT_ASSERT(utf8String.size() <= utf8String.capacity());
}

void Utf8StringTest::TestCharacterCodeUnitCount()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Test the CharacterCodeUnitCount() function that accepts a string::const_iterator
	//Test with one-code-unit characters
	string codeUnitString = utf8String;

	string::const_iterator codeUnitIterator = codeUnitString.begin();
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	codeUnitIterator = codeUnitString.begin() + 4;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with two-code-unit characters
	codeUnitIterator = codeUnitString.begin() + 9;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	codeUnitIterator = codeUnitString.begin() + 24;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with the iterator pointing to the second code unit of a two-code-unit character
	codeUnitIterator = codeUnitString.begin() + 10;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with three-code-unit characters
	codeUnitIterator = codeUnitString.begin() + 1;
	CPPUNIT_ASSERT_EQUAL((size_t)3, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	codeUnitIterator = codeUnitString.begin() + 17;
	CPPUNIT_ASSERT_EQUAL((size_t)3, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with the iterator pointing to the second code unit of a three-code-unit character
	codeUnitIterator = codeUnitString.begin() + 18;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with the iterator pointing to the third code unit of a three-code-unit character
	codeUnitIterator = codeUnitString.begin() + 3;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with four-code-unit characters
	codeUnitIterator = codeUnitString.begin() + 5;
	CPPUNIT_ASSERT_EQUAL((size_t)4, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	codeUnitIterator = codeUnitString.begin() + 20;
	CPPUNIT_ASSERT_EQUAL((size_t)4, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with the iterator pointing to the second code unit of a four-code-unit character
	codeUnitIterator = codeUnitString.begin() + 21;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with the iterator pointing to the third code unit of a four-code-unit character
	codeUnitIterator = codeUnitString.begin() + 7;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with the iterator pointing to the fourth code unit of a four-code-unit character
	codeUnitIterator = codeUnitString.begin() + 23;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(codeUnitIterator));


	//Test the CharacterCodeUnitCount() function that accepts a string::const_reverse_iterator
	string::const_reverse_iterator reverseCodeUnitIterator = codeUnitString.rbegin() + 12;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	reverseCodeUnitIterator = codeUnitString.rbegin() + 21;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with two-code-unit characters
	reverseCodeUnitIterator = codeUnitString.rbegin();
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	reverseCodeUnitIterator = codeUnitString.rbegin() + 13;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with the iterator pointing to the first code unit of a two-code-unit character
	reverseCodeUnitIterator = codeUnitString.rbegin() + 14;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with three-code-unit characters
	reverseCodeUnitIterator = codeUnitString.rbegin() + 6;
	CPPUNIT_ASSERT_EQUAL((size_t)3, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	reverseCodeUnitIterator = codeUnitString.rbegin() + 22;
	CPPUNIT_ASSERT_EQUAL((size_t)3, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with the iterator pointing to the first code unit of a three-code-unit character
	reverseCodeUnitIterator = codeUnitString.rbegin() + 8;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with the iterator pointing to the second code unit of a three-code-unit character
	reverseCodeUnitIterator = codeUnitString.rbegin() + 23;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with four-code-unit characters
	reverseCodeUnitIterator = codeUnitString.rbegin() + 2;
	CPPUNIT_ASSERT_EQUAL((size_t)4, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	reverseCodeUnitIterator = codeUnitString.rbegin() + 17;
	CPPUNIT_ASSERT_EQUAL((size_t)4, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with the iterator pointing to the first code unit of a four-code-unit character
	reverseCodeUnitIterator = codeUnitString.rbegin() + 5;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with the iterator pointing to the second code unit of a four-code-unit character
	reverseCodeUnitIterator = codeUnitString.rbegin() + 19;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with the iterator pointing to the third code unit of a four-code-unit character
	reverseCodeUnitIterator = codeUnitString.rbegin() + 3;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf8String::CharacterCodeUnitCount(reverseCodeUnitIterator));
}


void Utf8StringTest::TestClear()
{
	Utf8String utf8String;

	CPPUNIT_ASSERT(utf8String.size() == 0);
	CPPUNIT_ASSERT(utf8String.length() == 0);

	utf8String.clear();

	CPPUNIT_ASSERT(utf8String.size() == 0);
	CPPUNIT_ASSERT(utf8String.length() == 0);

	utf8String = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT(utf8String.size() == 4);
	CPPUNIT_ASSERT(utf8String.length() == 1);

	utf8String.clear();

	CPPUNIT_ASSERT(utf8String.size() == 0);
	CPPUNIT_ASSERT(utf8String.length() == 0);

	utf8String = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	CPPUNIT_ASSERT(utf8String.size() == 15);
	CPPUNIT_ASSERT(utf8String.length() == 6);

	utf8String.clear();

	CPPUNIT_ASSERT(utf8String.size() == 0);
	CPPUNIT_ASSERT(utf8String.length() == 0);
}

void Utf8StringTest::TestCodePointIndex()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Test using the first code unit
	CPPUNIT_ASSERT_EQUAL((size_t)0, utf8String.code_point_index(0));

	//Test using the code unit of a one-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)2, utf8String.code_point_index(4));

	//Test using the first code unit of a two-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)5, utf8String.code_point_index(11));

	//Test using the second code unit of a two-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)5, utf8String.code_point_index(12));

	//Test using the first code unit of a three-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)5, utf8String.code_point_index(11));

	//Test using the second code unit of a three-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)5, utf8String.code_point_index(12));

	//Test using the third code unit of a three-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)5, utf8String.code_point_index(12));

	//Test using the last code unit
	CPPUNIT_ASSERT_EQUAL((size_t)10, utf8String.code_point_index(25));

}

void Utf8StringTest::TestCodeUnitIndex()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Test using the first code point
	CPPUNIT_ASSERT_EQUAL((size_t)0, utf8String.code_unit_index(0));

	//Test using a one-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)13, utf8String.code_unit_index(6));

	//Test using a two-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)11, utf8String.code_unit_index(5));

	//Test using a three-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)14, utf8String.code_unit_index(7));

	//Test using a four-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)5, utf8String.code_unit_index(3));

	//Test using the last code point
	CPPUNIT_ASSERT_EQUAL((size_t)24, utf8String.code_unit_index(10));
}

void Utf8StringTest::TestCompare()
{
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	std::string characterString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create an empty string
	Utf8String emptyString;
	Utf16String emptyUtf16String;
	std::string emptyCharacterString;

	//Create a string to do the comparison with
	Utf8String compareString;

	//Test the compare() function that accepts a Utf16String
	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyUtf16String) == 0);

	//Compare strings that are equal
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = "\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a four-code-unit code
	//point in the parameter string
	compareString = "ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "aö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = "\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two/four-code-unit code points where the first code unit differs
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF2\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two/four-code-unit code points where the second code unit differs
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x95\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a four-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "S\xF0\x91\x84\xA2\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "\xC3\xB4" "ẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAA";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);


	//Test the compare() function that accepts a Utf8String
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyString) == 0);

	//Compare strings that are equal
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = "ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the first code point differs
	compareString = "\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the second code unit differs
	compareString = "\xF0\x90\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a four-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bo\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Bẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = "\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "b∑\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both three-code-unit code points where the third code unit differs
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ\xE1\x86\xA2\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "\xC3\xAB" "ö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA9" "bö\xEF\xBF\x9F";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);



	//Test the compare() function that accepts a std::string
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyCharacterString) == 0);

	//Compare strings that are equal
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = "ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the first code point differs
	compareString = "\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the second code unit differs
	compareString = "\xF0\x90\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a four-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bo\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Bẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = "\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "b∑\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both three-code-unit code points where the third code unit differs
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ\xE1\x86\xA2\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "\xC3\xAB" "ö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA9" "bö\xEF\xBF\x9F";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);


	//Test the compare() function that accepts a char*
	compareString.clear();

	//Compare empty strings
	const char* characterStringBuffer = emptyCharacterString.c_str();
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) == 0);

	characterStringBuffer = characterString.c_str();

	//Compare strings that are equal
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = "ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the first code point differs
	compareString = "\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the second code unit differs
	compareString = "\xF0\x90\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a four-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bo\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Bẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = "\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "b∑\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both three-code-unit code points where the third code unit differs
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ\xE1\x86\xA2\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "\xC3\xAB" "ö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA9" "bö\xEF\xBF\x9F";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);



	//Test the compare() function that accepts a char* and a size_t
	compareString.clear();

	//Compare empty strings
	characterStringBuffer = emptyCharacterString.c_str();
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) == 0);

	characterStringBuffer = characterString.c_str();

	//Compare strings that are equal
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) == 0);

	//Compare a string that is less than the parameter string where the first code point differs
	compareString = "ẫ" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 11) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the first code point differs
	compareString = "\xF0\x92\x80\xA2" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 5) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both four-code-unit code points where the second code unit differs
	compareString = "\xF0\x90\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a four-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫt" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 9) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bo\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 17) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Aẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Bẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д\xC3\xB4";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 8) < 0);

	//Compare a string that is greater than the parameter string where the first code point differs
	compareString = "\xF1\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 4) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "b∑\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both three-code-unit code points where the third code unit differs
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 18) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a three-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\xAF" "3ẫ\xE1\x86\xA2\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 24) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "\xC3\xAB" "ö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = "\xF0\x92\x81\xA8" "Wẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 8) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA9" "bö\xEF\xBF\x9F";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) > 0);
}

void Utf8StringTest::TestConstIterator()
{
	TestConstIteratorWithStringOne();
	TestConstIteratorWithStringTwo();
	TestConstIteratorWithStringThree();
	TestConstIteratorWithStringFour();
}

void Utf8StringTest::TestConstIteratorReversal()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	const Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Create an iterator and put it in the middle of the string
	Utf8String::const_iterator stringIterator = utf8String.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT((*stringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT((*stringIterator)[1] == '\x9F');

	//Now convert to a reverse iterator
	Utf8String::const_reverse_iterator reverseStringIterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == '\x9F');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*reverseStringIterator)[3] == '\xA8');

	//Move the iterator to a four-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*stringIterator)[3] == '\xA8');

	//Now convert to a reverse iterator
	reverseStringIterator = Utf8String::const_reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*reverseStringIterator)[3] == '\xA8');

	//Now convert back to a normal iterator
	stringIterator = Utf8String::const_iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*stringIterator)[3] == '\xA8');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT((*stringIterator)[0] == '\x62');
}

void Utf8StringTest::TestConstReverseIterator()
{
	TestConstReverseIteratorWithStringOne();
	TestConstReverseIteratorWithStringTwo();
	TestConstReverseIteratorWithStringThree();
	TestConstReverseIteratorWithStringFour();
}

void Utf8StringTest::TestConstructors()
{
	//Create a Utf8String using the default constructor
	Utf8String* constructedString = new Utf8String();

	//The string should be an empty string
	CPPUNIT_ASSERT(constructedString->empty());
	CPPUNIT_ASSERT(constructedString->length() == 0);
	CPPUNIT_ASSERT(constructedString->size() == 0);

	delete constructedString;
	constructedString = NULL;

	//Create a standard string containing simple ASCII characters
	string characterString = "Simple String";
	//Create a UTF-8 string containing simple ASCII characters
	Utf8String utf8String = "Simple String";
	//Create the UTF-16 version
	Utf16String utf16String = L"Simple String";

	//Test the constructors with simple strings
	TestConstructorsWithStrings(characterString, utf8String, utf16String);

	//Create a standard string containing a mix of 1- and 2-byte UTF-8 characters
	characterString = "ωE4ڽhъ";
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "ωE4ڽhъ";
	//Create the UTF-16 version
	utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";

	//Test the constructors with strings containing a mix of 1- and 2-byte UTF-8 characters
	//and their UTF-16 equivalents
	TestConstructorsWithStrings(characterString, utf8String, utf16String);

	//Create a standard string class containing a 1-, 2-, and 3-byte UTF-8 characters
	characterString = "Sẫböß3ẫ∑д";
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Test the constructors with strings containing a mix of 1-, 2, and 3-byte UTF-8 characters
	//and their UTF-16 equivalents
	TestConstructorsWithStrings(characterString, utf8String, utf16String);

	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	characterString = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Test the constructors with strings containing a mix of 1-, 2, 3-, and 4-byte UTF-8 characters
	//and their UTF-16 equivalents
	TestConstructorsWithStrings(characterString, utf8String, utf16String);
}

void Utf8StringTest::TestCopy()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	char* codeUnitArray = NULL;
	size_t copiedCodeUnits;

	//Copy a string to a 0-length array
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[0];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 0, 10);

	CPPUNIT_ASSERT_EQUAL((size_t)0, copiedCodeUnits);

	//Copy a three-code-unit code point to an array of size 1
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[1];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 1, 1);

	CPPUNIT_ASSERT_EQUAL((size_t)0, copiedCodeUnits);

	//Copy a large section of a string into an array that is too small
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[8];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 8, 7);

	CPPUNIT_ASSERT_EQUAL((size_t)5, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL('\x53', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL('\xE1', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL('\xBA', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL('\xAB', codeUnitArray[3]);
	CPPUNIT_ASSERT_EQUAL('\x62', codeUnitArray[4]);

	//Copy part of a string using an offset
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[100];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 100, 3, 2);

	CPPUNIT_ASSERT_EQUAL((size_t)7, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL('\x62', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL('\xF0', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL('\x92', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL('\x81', codeUnitArray[3]);
	CPPUNIT_ASSERT_EQUAL('\xA8', codeUnitArray[4]);
	CPPUNIT_ASSERT_EQUAL('\xC3', codeUnitArray[5]);
	CPPUNIT_ASSERT_EQUAL('\xB6', codeUnitArray[6]);

	//Copy part of a string with the number of code points that would be past the end of the string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[100];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 100, 10, 9);

	CPPUNIT_ASSERT_EQUAL((size_t)6, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL('\xF0', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', codeUnitArray[3]);
	CPPUNIT_ASSERT_EQUAL('\xD0', codeUnitArray[4]);
	CPPUNIT_ASSERT_EQUAL('\xB4', codeUnitArray[5]);

	//Copy the last character of a string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[100];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 100, 1, utf8String.length() - 1);

	CPPUNIT_ASSERT_EQUAL((size_t)2, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL('\xD0', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', codeUnitArray[1]);

	//Copy a middle section of a string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[100];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 100, 5, 3);

	CPPUNIT_ASSERT_EQUAL((size_t)12, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL('\xF0', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', codeUnitArray[3]);
	CPPUNIT_ASSERT_EQUAL('\xC3', codeUnitArray[4]);
	CPPUNIT_ASSERT_EQUAL('\xB6', codeUnitArray[5]);
	CPPUNIT_ASSERT_EQUAL('\xC3', codeUnitArray[6]);
	CPPUNIT_ASSERT_EQUAL('\x9F', codeUnitArray[7]);
	CPPUNIT_ASSERT_EQUAL('\x33', codeUnitArray[8]);
	CPPUNIT_ASSERT_EQUAL('\xE1', codeUnitArray[9]);
	CPPUNIT_ASSERT_EQUAL('\xBA', codeUnitArray[10]);
	CPPUNIT_ASSERT_EQUAL('\xAB', codeUnitArray[11]);

	//Copy an entire string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new char[100];
	copiedCodeUnits = utf8String.copy(codeUnitArray, 100, utf8String.length());

	CPPUNIT_ASSERT_EQUAL((size_t)26, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL('\x53', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL('\xE1', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL('\xBA', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL('\xAB', codeUnitArray[3]);
	CPPUNIT_ASSERT_EQUAL('\x62', codeUnitArray[4]);
	CPPUNIT_ASSERT_EQUAL('\xF0', codeUnitArray[5]);
	CPPUNIT_ASSERT_EQUAL('\x92', codeUnitArray[6]);
	CPPUNIT_ASSERT_EQUAL('\x81', codeUnitArray[7]);
	CPPUNIT_ASSERT_EQUAL('\xA8', codeUnitArray[8]);
	CPPUNIT_ASSERT_EQUAL('\xC3', codeUnitArray[9]);
	CPPUNIT_ASSERT_EQUAL('\xB6', codeUnitArray[10]);
	CPPUNIT_ASSERT_EQUAL('\xC3', codeUnitArray[11]);
	CPPUNIT_ASSERT_EQUAL('\x9F', codeUnitArray[12]);
	CPPUNIT_ASSERT_EQUAL('\x33', codeUnitArray[13]);
	CPPUNIT_ASSERT_EQUAL('\xE1', codeUnitArray[14]);
	CPPUNIT_ASSERT_EQUAL('\xBA', codeUnitArray[15]);
	CPPUNIT_ASSERT_EQUAL('\xAB', codeUnitArray[16]);
	CPPUNIT_ASSERT_EQUAL('\xE2', codeUnitArray[17]);
	CPPUNIT_ASSERT_EQUAL('\x88', codeUnitArray[18]);
	CPPUNIT_ASSERT_EQUAL('\x91', codeUnitArray[19]);
	CPPUNIT_ASSERT_EQUAL('\xF0', codeUnitArray[20]);
	CPPUNIT_ASSERT_EQUAL('\x90', codeUnitArray[21]);
	CPPUNIT_ASSERT_EQUAL('\x8D', codeUnitArray[22]);
	CPPUNIT_ASSERT_EQUAL('\x86', codeUnitArray[23]);
	CPPUNIT_ASSERT_EQUAL('\xD0', codeUnitArray[24]);
	CPPUNIT_ASSERT_EQUAL('\xB4', codeUnitArray[25]);
}

void Utf8StringTest::TestCStr()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	const char* codeUnitString = utf8String.c_str();
	string baseString = utf8String;

	int codeUnitIndex = 0;

	//Iterate through the string, making sure all the code units are the same as the contents
	//of the null-terminated code unit string
	for(string::const_iterator stringIterator = baseString.begin(); 
		stringIterator != baseString.end(); ++stringIterator)
	{
		CPPUNIT_ASSERT_EQUAL(*stringIterator, codeUnitString[codeUnitIndex]);

		++codeUnitIndex;
	}

	//Make sure that the code unit string is indeed null-terminated
	CPPUNIT_ASSERT_EQUAL('\x00', codeUnitString[codeUnitIndex]);
}

void Utf8StringTest::TestData()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	const char* codeUnitString = utf8String.data();
	string baseString = utf8String;

	int codeUnitIndex = 0;

	//Iterate through the string, making sure all the code units are the same as the contents
	//of the null-terminated code unit string
	for(string::const_iterator stringIterator = baseString.begin(); 
		stringIterator != baseString.end(); ++stringIterator)
	{
		CPPUNIT_ASSERT_EQUAL(*stringIterator, codeUnitString[codeUnitIndex]);

		++codeUnitIndex;
	}
}

void Utf8StringTest::TestDecodeCharacter()
{
	//Test the DecodeCharacter() that accepts a char* and a size_t
	//Decode some one-code-unit characters
	char* characterBuffer = new char[1];

	characterBuffer[0] = '\x62';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000062, Utf8String::DecodeCharacter(characterBuffer, 1));

	characterBuffer[0] = '\x33';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000033, Utf8String::DecodeCharacter(characterBuffer, 1));

	//Decode some two-code-unit characters
	if(characterBuffer != NULL)
	{
		delete[] characterBuffer;
		characterBuffer = NULL;
	}

	characterBuffer = new char[2];

	characterBuffer[0] = '\xC3';
	characterBuffer[1] = '\xB6';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000F6, Utf8String::DecodeCharacter(characterBuffer, 2));

	characterBuffer[0] = '\xD0';
	characterBuffer[1] = '\xB4';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000434, Utf8String::DecodeCharacter(characterBuffer, 2));

	//Decode some three-code-unit characters
	if(characterBuffer != NULL)
	{
		delete[] characterBuffer;
		characterBuffer = NULL;
	}

	characterBuffer = new char[3];
	
	characterBuffer[0] = '\xE1';
	characterBuffer[1] = '\xBA';
	characterBuffer[2] = '\xAB';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, Utf8String::DecodeCharacter(characterBuffer, 3));

	characterBuffer[0] = '\xE2';
	characterBuffer[1] = '\x88';
	characterBuffer[2] = '\x91';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, Utf8String::DecodeCharacter(characterBuffer, 3));

	//Decode some four-code-unit characters
	if(characterBuffer != NULL)
	{
		delete[] characterBuffer;
		characterBuffer = NULL;
	}

	characterBuffer = new char[4];
	
	characterBuffer[0] = '\xF0';
	characterBuffer[1] = '\x92';
	characterBuffer[2] = '\x81';
	characterBuffer[3] = '\xA8';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, Utf8String::DecodeCharacter(characterBuffer, 4));

	characterBuffer[0] = '\xF0';
	characterBuffer[1] = '\x90';
	characterBuffer[2] = '\x8D';
	characterBuffer[3] = '\x86';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, Utf8String::DecodeCharacter(characterBuffer, 4));

	//Test the DecodeCharacter() that accepts a Utf8Char
	//Decode some one-code-unit characters
	Utf8Char character;

	//Decode some one-code-unit characters
	character.clear();
	character[0] = '\x62';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000062, Utf8String::DecodeCharacter(character));

	character.clear();
	character[0] = '\x33';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000033, Utf8String::DecodeCharacter(character));

	//Decode some two-code-unit characters
	character.clear();
	character[0] = '\xC3';
	character[1] = '\xB6';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x000000F6, Utf8String::DecodeCharacter(character));

	character.clear();
	character[0] = '\xD0';
	character[1] = '\xB4';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000434, Utf8String::DecodeCharacter(character));

	//Decode some three-code-unit characters
	character.clear();	
	character[0] = '\xE1';
	character[1] = '\xBA';
	character[2] = '\xAB';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, Utf8String::DecodeCharacter(character));

	character.clear();
	character[0] = '\xE2';
	character[1] = '\x88';
	character[2] = '\x91';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, Utf8String::DecodeCharacter(character));

	//Decode some four-code-unit characters
	character.clear();	
	character[0] = '\xF0';
	character[1] = '\x92';
	character[2] = '\x81';
	character[3] = '\xA8';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, Utf8String::DecodeCharacter(character));

	character.clear();
	character[0] = '\xF0';
	character[1] = '\x90';
	character[2] = '\x8D';
	character[3] = '\x86';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, Utf8String::DecodeCharacter(character));
}

void Utf8StringTest::TestEmpty()
{
	//Test the default string
	Utf8String utf8String;
	CPPUNIT_ASSERT(utf8String.empty());

	//Test a string with a single one-code-unit character
	utf8String = "\x33";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string with a single two-code-unit character
	utf8String = "\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string with a single three-code-unit character
	utf8String = "\xE1\xAB\xBA";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string with a single four-code-unit character
	utf8String = "\xF0\x92\x87\xA8";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string with a single invalid code unit
	utf8String = "\xF1";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string with a two invalid code units
	utf8String = "\xE1\x91";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string with three invalid code units
	utf8String = "\xF1\x83\x95";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string with four invalid code units
	utf8String = "\xF1\x83\xE2\xF3";
	CPPUNIT_ASSERT(!utf8String.empty());

	//Test a string that's set to an empty string
	utf8String = "";
	CPPUNIT_ASSERT(utf8String.empty());

	//Test a string with a lot of different characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.empty());
}

void Utf8StringTest::TestEncodeCharacter()
{
	//Encode some one-code-unit characters
	Utf8Char encodedCharacter;

	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x00000062);
	CPPUNIT_ASSERT_EQUAL((size_t)1, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\x62', encodedCharacter[0]);

	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x00000033);
	CPPUNIT_ASSERT_EQUAL((size_t)1, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\x33', encodedCharacter[0]);

	//Encode some two-code-unit characters
	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x000000F6);
	CPPUNIT_ASSERT_EQUAL((size_t)2, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\xC3', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', encodedCharacter[1]);

	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x00000434);
	CPPUNIT_ASSERT_EQUAL((size_t)2, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\xD0', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', encodedCharacter[1]);

	//Encode some three-code-unit characters
	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x00001EAB);
	CPPUNIT_ASSERT_EQUAL((size_t)3, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\xE1', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', encodedCharacter[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', encodedCharacter[2]);

	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x00002211);
	CPPUNIT_ASSERT_EQUAL((size_t)3, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\xE2', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', encodedCharacter[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', encodedCharacter[2]);

	//Encode some four-code-unit characters
	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x00012068);
	CPPUNIT_ASSERT_EQUAL((size_t)4, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\xF0', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', encodedCharacter[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', encodedCharacter[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', encodedCharacter[3]);

	encodedCharacter = Utf8String::EncodeCharacter((UInt32)0x00010346);
	CPPUNIT_ASSERT_EQUAL((size_t)4, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL('\xF0', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', encodedCharacter[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', encodedCharacter[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', encodedCharacter[3]);
}

void Utf8StringTest::TestEnd()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8String::iterator stringIterator = utf8String.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xD0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*stringIterator)[1]);

	utf8String = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	stringIterator = utf8String.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);

	//Run the test again with a constant string
	const Utf8String constUtf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";;

	Utf8String::const_iterator constStringIterator = constUtf8String.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xD0', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*constStringIterator)[1]);

	const Utf8String constUtf8StringTwo = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	constStringIterator = constUtf8StringTwo.end() - 1;

	CPPUNIT_ASSERT_EQUAL('\xE2', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*constStringIterator)[2]);
}

void Utf8StringTest::TestErase()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8String eraseString;
	Utf8String resultString;
	Utf8String::iterator resultIterator = utf8String.begin();

	//Test the erase() function that accepts two iterators
	//Try to remove characters from an empty string
	eraseString.clear();
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)0, eraseString.length());
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Remove characters at the beginning of a string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.begin() + 5);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\xC3\x9F");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(utf8String.begin() + 5));

	//Remove characters in the middle of a string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin() + 3, eraseString.begin() + 8);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == '\x53');
	CPPUNIT_ASSERT(eraseString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(eraseString[2] == '\x62');
	CPPUNIT_ASSERT(eraseString[3] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(eraseString[4] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(eraseString[5] == "\xD0\xB4");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(utf8String.begin() + 8));

	//Remove characters at the end of a string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin() + 8, eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[7] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts a single iterator
	//Remove a character from the beginning of the string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin());

	CPPUNIT_ASSERT_EQUAL(utf8String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(utf8String.begin() + 1));

	//Remove a one-code-unit character from the middle of the string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin() + 6);

	CPPUNIT_ASSERT_EQUAL(utf8String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[6] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 6);
	CPPUNIT_ASSERT(*resultIterator == *(utf8String.begin() + 7));

	//Remove a two-code-unit character from the middle of the string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin() + 4);

	CPPUNIT_ASSERT_EQUAL(utf8String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[4] == "\xC3\x9F");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 4);
	CPPUNIT_ASSERT(*resultIterator == *(utf8String.begin() + 5));

	//Remove a three-code-unit character from the middle of the string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin() + 1);

	CPPUNIT_ASSERT_EQUAL(utf8String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[1] == "\x62");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 1);
	CPPUNIT_ASSERT(*resultIterator == *(utf8String.begin() + 2));

	//Remove a four-code-unit character from the middle of the string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.begin() + 3);

	CPPUNIT_ASSERT_EQUAL(utf8String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[3] == "\xC3\xB6");
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(utf8String.begin() + 4));

	//Remove a character from the end of a string
	eraseString = utf8String;
	resultIterator = eraseString.erase(eraseString.end() - 1);

	CPPUNIT_ASSERT_EQUAL(utf8String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[eraseString.length() - 1] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts two size_t parameters
	//Remove characters at the beginning of a string
	eraseString = utf8String;
	resultString = eraseString.erase(0, 5);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\xC3\x9F");
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters in the middle of a string
	eraseString = utf8String;
	resultString = eraseString.erase(3, 5);

	CPPUNIT_ASSERT_EQUAL((size_t)6, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == '\x53');
	CPPUNIT_ASSERT(eraseString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(eraseString[2] == '\x62');
	CPPUNIT_ASSERT(eraseString[3] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(eraseString[4] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(eraseString[5] == "\xD0\xB4");
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string
	eraseString = utf8String;
	resultString = eraseString.erase(8, 3);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[7] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string where the count parameter causes the range to
	//go beyond the end of the string
	eraseString = utf8String;
	resultString = eraseString.erase(8, 12);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0] == "\x53");
	CPPUNIT_ASSERT(eraseString[7] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(resultString == eraseString);
}

void Utf8StringTest::TestFind()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	size_t foundIndex;

	//Find a single character at the beginning of the string
	foundIndex = utf8String.find(L"\x53");

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = utf8String.find("\x33");

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = utf8String.find("\xC3\x9F");

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = utf8String.find("\xE2\x88\x91");

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = utf8String.find("\xF0\x90\x8D\x86");

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = utf8String.find("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = utf8String.find("\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91");

	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = utf8String.find("\xF0\x90\x8D\x86\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = utf8String.find("\xE4\x90\xA8");

	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = utf8String.find("\xE1\xBA\xAB\xC3\x9F\x33");

	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf8String.find("\xF0\x90\x8D\x86", 5);

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);
}

void Utf8StringTest::TestFindFirstNotOf()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8String shortString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = shortString.find_first_not_of("\xE1\xBA\xAB\x62");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = "\xC3\x9F";

	//Find the first code point that contains a code unit other than the second code unit
	foundIndex = shortString.find_first_not_of("\x9F");

	//We should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find the first code point that contains a code unit other than the first code unit
	foundIndex = shortString.find_first_not_of("\xC3");

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of("\xC3\x9F");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = utf8String.find_first_not_of(utf8String);
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = utf8String.find_first_not_of("\x53\xE1\xBA\xAB\x62\xC3\x9F");
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = utf8String.find_first_not_of("\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\x9F");
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = utf8String.find_first_not_of("\x73\xE1\x90\xA2\xF3\x92\x8A\xA4");
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = utf8String.find_first_not_of("\x33", 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = utf8String.find_first_not_of("\xC3\x9F\x33", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);
}

void Utf8StringTest::TestFindFirstOf()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8String emptyString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of("\x33");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Find some characters in the string
	foundIndex = utf8String.find_first_of("\x53");
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = utf8String.find_first_of("\xC3\xB6");
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = utf8String.find_first_of("\xE1\xBA\xAB");
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = utf8String.find_first_of("\xF0\x92\x81\xA8");
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = utf8String.find_first_of("\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6");
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = utf8String.find_first_of("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = utf8String.find_first_of("\xE4\x97\x8A\x44\xC6\x96");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf8String.find_first_of("\xE1\xBA\xAB", 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = utf8String.find_first_of("\xE1\xBA\xAB", 4);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find something past the end of the string
	foundIndex = utf8String.find_first_of("\xE1\xBA\xAB", 14);
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);
}

void Utf8StringTest::TestFindLastNotOf()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8String shortString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = shortString.find_last_not_of("\xE1\xBA\xAB\x62");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = "\xC3\xB6";

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of("\xC3\xB6");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = utf8String.find_last_not_of(utf8String);
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = utf8String.find_last_not_of("\xE1\xBA\xAB\xC3\x9F\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = utf8String.find_last_not_of("\xF0\x92\x81\xA8\x53\x62");
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = utf8String.find_last_not_of("\x56\xC4\x96\x33");
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = utf8String.find_last_not_of("\x33", 6);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = utf8String.find_last_not_of("\x53", 0);
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	foundIndex = utf8String.find_last_not_of("\xF0\x92\x81\xA8", 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);
}

void Utf8StringTest::TestFindLastOf()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8String emptyString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of("\x53");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Find some characters in the string
	foundIndex = utf8String.find_last_of("\x33");
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = utf8String.find_last_of("\xF0\x90\x8D\x86\xD0\xB4");
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = utf8String.find_last_of("\xE1\xBA\xAB\xC3\xB6");
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = utf8String.find_last_of("\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Attempt to find some characters that aren't in the string
	foundIndex = utf8String.find_last_of("\x44\xF1\x86\xA2\x98\xC5\xAA");
	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf8String.find_last_of("\xE1\xBA\xAB", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = utf8String.find_last_of("\x62\xE1\xBA\xAB", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = utf8String.find_last_of("\x53\xE1\xBA\xAB", 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = utf8String.find_last_of("\x53\xE1\xBA\xAB", 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);
}

void Utf8StringTest::TestIndexer()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Get the character at the beginning of the string
	Utf8Char character = utf8String[0];

	CPPUNIT_ASSERT_EQUAL('\x53', character[0]);

	//Get the character at the end of the string
	character = utf8String[utf8String.length() - 1];

	CPPUNIT_ASSERT_EQUAL('\xD0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', character[1]);

	//Get a one-code-unit character in the middle of the string
	character = utf8String[6];

	CPPUNIT_ASSERT_EQUAL('\x33', character[0]);

	//Get a two-code-unit character in the middle of the string
	character = utf8String[4];

	CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

	//Get a four-code-unit character in the middle of the string
	character = utf8String[1];

	CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

	//Get a four-code-unit character in the middle of the string
	character = utf8String[3];

	CPPUNIT_ASSERT_EQUAL('\xF0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', character[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', character[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', character[3]);

	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String constUtf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Get the character at the beginning of the string
	character = constUtf8String[0];

	CPPUNIT_ASSERT_EQUAL('\x53', character[0]);

	//Get the character at the end of the string
	character = constUtf8String[constUtf8String.length() - 1];

	CPPUNIT_ASSERT_EQUAL('\xD0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', character[1]);

	//Get a one-code-unit character in the middle of the string
	character = constUtf8String[6];

	CPPUNIT_ASSERT_EQUAL('\x33', character[0]);

	//Get a two-code-unit character in the middle of the string
	character = constUtf8String[4];

	CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

	//Get a four-code-unit character in the middle of the string
	character = constUtf8String[1];

	CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

	//Get a four-code-unit character in the middle of the string
	character = constUtf8String[3];

	CPPUNIT_ASSERT_EQUAL('\xF0', character[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', character[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', character[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', character[3]);
}

void Utf8StringTest::TestInsert()
{
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	string characterString = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UTF-8 string that will be appended to
	Utf8String originalString = "ẫö∑b\xF0\x90\x8D\x86";
	//Create the UTF-8 string that results from an insert operation at the beginning of the string
	Utf8String finalBeginString = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86дẫö∑b\xF0\x90\x8D\x86";
	//Create the UTF-8 string that results from an insert operation in the middle of the string
	Utf8String finalMiddleString = "ẫö\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д∑b\xF0\x90\x8D\x86";
	//Create the UTF-8 string that results from an insert operation at the end of the string
	Utf8String finalEndString = "ẫö∑b\xF0\x90\x8D\x86\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the string on which the insert operations will be conducted
	Utf8String insertedString;


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

	CPPUNIT_ASSERT_EQUAL(utf8String, insertedString);


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

	CPPUNIT_ASSERT_EQUAL(utf8String, insertedString);


	//Test the insert() function that accepts a std::string
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, characterString);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, characterString);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, characterString);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString);

	CPPUNIT_ASSERT_EQUAL(utf8String, insertedString);


	//Test the insert() function that accepts a char*
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf8String, insertedString);


	//Test the insert() function that accepts a char* and a size_t
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(utf8String, insertedString);

	//Test the insert() function that accepts a Utf8Char

	//Create a UTF-8 string that will be the result when inserting a one-code-unit character
	//at the beginning
	Utf8String oneCodeUnitBeginFinalString = "Sẫö∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result when inserting a one-code-unit character
	//in the middle
	Utf8String oneCodeUnitMiddleFinalString = "ẫöS∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result when inserting a one-code-unit character
	//at the end
	Utf8String oneCodeUnitEndFinalString = "ẫö∑b\xF0\x90\x8D\x86S";
	//Create a UTF-8 string that will be the result inserting a two-code-unit character
	//at the beginning
	Utf8String twoCodeUnitBeginFinalString = "\xC3\xB6ẫö∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result inserting a two-code-unit character
	//at the beginning
	Utf8String twoCodeUnitMiddleFinalString = "ẫö\xC3\xB6∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result inserting a two-code-unit character
	//at the beginning
	Utf8String twoCodeUnitEndFinalString = "ẫö∑b\xF0\x90\x8D\x86\xC3\xB6";
	//Create a UTF-8 string that will be the result inserting a three-code-unit character
	//at the beginning
	Utf8String threeCodeUnitBeginFinalString = "\xE1\xBA\xABẫö∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result inserting a three-code-unit character
	//at the beginning
	Utf8String threeCodeUnitMiddleFinalString = "ẫö\xE1\xBA\xAB∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result inserting a three-code-unit character
	//at the beginning
	Utf8String threeCodeUnitEndFinalString = "ẫö∑b\xF0\x90\x8D\x86\xE1\xBA\xAB";
	//Create a UTF-8 string that will be the result inserting a four-code-unit character
	//at the beginning
	Utf8String fourCodeUnitBeginFinalString = "\xF0\x92\x81\xA8ẫö∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result inserting a four-code-unit character
	//at the beginning
	Utf8String fourCodeUnitMiddleFinalString = "ẫö\xF0\x92\x81\xA8∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result inserting a four-code-unit character
	//at the beginning
	Utf8String fourCodeUnitEndFinalString = "ẫö∑b\xF0\x90\x8D\x86\xF0\x92\x81\xA8";

	//Insert a one-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(utf8String.substr(1, 1), insertedString);

	//Insert a two-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(utf8String.substr(4, 1), insertedString);


	//Insert a three-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf8String[2]);

	CPPUNIT_ASSERT_EQUAL(utf8String.substr(2, 1), insertedString);


	//Insert a four-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(5, utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(utf8String.substr(0, 1), insertedString);

}

void Utf8StringTest::TestIsValid()
{
	//Test a valid UTF-8 string
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(utf8String.is_valid());

	//Test an empty string
	utf8String.clear();
	CPPUNIT_ASSERT(utf8String.is_valid());

	//Test a string where a multi-code-unit code point is missing some code units
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.is_valid());

	//Test a string where a multi-code-unit code point at the end of the string is missing some code units
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4\xF0";
	CPPUNIT_ASSERT(!utf8String.is_valid());

	//Test a string where a multi-code-unit code point is missing the first code unit
	utf8String = "\x53\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.is_valid());

	//Test a string where a multi-code-unit code point at the end of the string is missing the first code unit
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\x90\x8D\x86";
	CPPUNIT_ASSERT(!utf8String.is_valid());

	//Test a string containing the BOM code point 0xFFFE (0xEF, 0xBF, 0xBE)
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xEF\xBF\xBE\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.is_valid());

	//Test a string containing the BOM code point 0xFFFF (0xEF, 0xBF, 0xBF)
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xEF\xBF\xBF\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.is_valid());

	//Test a string containing one of the code points that are non-characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xF1\x8F\xBF\xBE\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.is_valid());

	//Test a string containing another one of the code points that are non-characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xEF\xB7\xAE\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	CPPUNIT_ASSERT(!utf8String.is_valid());
}

void Utf8StringTest::TestIsValidCharacter()
{
	//Test the IsValidCharacter() that accepts a Utf8Char
	Utf8Char character;

	//Validate an empty character
	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Validate valid one-code-unit characters
	character.clear();
	character = '\x33';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	character.clear();
	character = "\x7F";

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	//Validate invalid one-code-unit characters
	character.clear();
	character = '\x80';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	character.clear();
	character = '\xA8';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	character.clear();
	character = '\xFF';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));


	//Validate valid two-code-unit characters
	character.clear();
	character = "\xD4\xA3";

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	character.clear();
	character = "\xD8\x82";

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	//Validate invalid two-code-unit characters
	//Test a character with an invalid first code unit
	character.clear();
	character = "\xA8\x80";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with an invalid second code unit
	character.clear();
	character = "\xD8\x33";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with two invalid code units
	character.clear();
	character = "\x45\x7A";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));


	//Validate valid three-code-unit characters
	character.clear();
	character = "\xE1\xBA\xAB";

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	character.clear();
	character = "\xE2\x88\x91";

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	//Validate invalid three-code-unit characters
	//Test a character with an invalid first code unit
	character.clear();
	character = "\xB2\x88\x91";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with an invalid second code unit
	character.clear();
	character = "\xE2\x68\x91";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with an invalid third code unit
	character.clear();
	character = "\xE2\x68\xF1";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with two invalid code units
	character.clear();
	character = "\xE2\x45\x7A";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with three invalid code units
	character.clear();
	character = "\xC2\x45\x7A";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));


	//Validate valid four-code-unit characters
	character.clear();
	character = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	character.clear();
	character = "\xF0\x90\x8D\x86";

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(character));

	//Validate invalid four-code-unit characters
	//Test a character with an invalid first code unit
	character.clear();
	character = "\xE0\x90\x8D\x86";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with an invalid second code unit
	character.clear();
	character = "\xF0\xF0\x8D\x86";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with an invalid third code unit
	character.clear();
	character = "\xF0\x90\xCD\x86";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with an invalid fourth code unit
	character.clear();
	character = "\xF0\x90\x8D\x13";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with two invalid code units
	character.clear();
	character = "\xC0\x90\x8D\x16";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with three invalid code units
	character.clear();
	character = "\xA0\xF3\x8D\x56";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));

	//Test a character with four invalid code units
	character.clear();
	character = "\x98\xA2\x3D\xC6";

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(character));


	//Test the IsValidCharacter() that accepts a char* and a size_t
	char characterBuffer[4];

	//Validate an empty character
	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 0));

	//Validate valid one-code-unit characters
	characterBuffer[0] = '\x33';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 1));

	characterBuffer[0] = '\x7F';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 1));

	//Validate invalid one-code-unit characters
	characterBuffer[0] = '\x80';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 1));

	characterBuffer[0] = '\xA8';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 1));

	characterBuffer[0] = '\xFF';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 1));


	//Validate valid two-code-unit characters
	characterBuffer[0] = '\xD4';
	characterBuffer[1] = '\xA3';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 2));

	characterBuffer[0] = '\xD8';
	characterBuffer[1] = '\x82';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 2));

	//Validate invalid two-code-unit characters
	//Test a character with an invalid first code unit
	characterBuffer[0] = '\xA8';
	characterBuffer[1] = '\x80';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 2));

	//Test a character with an invalid second code unit
	characterBuffer[0] = '\xD8';
	characterBuffer[1] = '\x33';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 2));

	//Test a character with two invalid code units
	characterBuffer[0] = '\x45';
	characterBuffer[1] = '\x7A';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 2));


	//Validate valid three-code-unit characters
	characterBuffer[0] = '\xE1';
	characterBuffer[1] = '\xBA';
	characterBuffer[2] = '\xAB';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 3));

	characterBuffer[0] = '\xE2';
	characterBuffer[1] = '\x88';
	characterBuffer[2] = '\x91';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 3));

	//Validate invalid three-code-unit characters
	//Test a character with an invalid first code unit
	characterBuffer[0] = '\xB2';
	characterBuffer[1] = '\x88';
	characterBuffer[2] = '\x91';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 3));

	//Test a character with an invalid second code unit
	characterBuffer[0] = '\xE2';
	characterBuffer[1] = '\x68';
	characterBuffer[2] = '\x91';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 3));

	//Test a character with an invalid third code unit
	characterBuffer[0] = '\xE2';
	characterBuffer[1] = '\x68';
	characterBuffer[2] = '\xF1';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 3));

	//Test a character with two invalid code units
	characterBuffer[0] = '\xE2';
	characterBuffer[1] = '\x45';
	characterBuffer[2] = '\x7A';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 3));

	//Test a character with three invalid code units
	characterBuffer[0] = '\xC2';
	characterBuffer[1] = '\x45';
	characterBuffer[2] = '\x7A';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 3));


	//Validate valid four-code-unit characters
	characterBuffer[0] = '\xF0';
	characterBuffer[1] = '\x92';
	characterBuffer[2] = '\x81';
	characterBuffer[3] = '\xA8';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 4));

	characterBuffer[0] = '\xF0';
	characterBuffer[1] = '\x90';
	characterBuffer[2] = '\x8D';
	characterBuffer[3] = '\x86';

	CPPUNIT_ASSERT(Utf8String::IsValidCharacter(characterBuffer, 4));

	//Validate invalid four-code-unit characters
	//Test a character with an invalid first code unit
	characterBuffer[0] = '\xE0';
	characterBuffer[1] = '\x90';
	characterBuffer[2] = '\x8D';
	characterBuffer[3] = '\x86';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 4));

	//Test a character with an invalid second code unit
	characterBuffer[0] = '\xF0';
	characterBuffer[1] = '\xF0';
	characterBuffer[2] = '\x8D';
	characterBuffer[3] = '\x86';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 4));

	//Test a character with an invalid third code unit
	characterBuffer[0] = '\xF0';
	characterBuffer[1] = '\x90';
	characterBuffer[2] = '\xCD';
	characterBuffer[3] = '\x86';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 4));

	//Test a character with an invalid fourth code unit
	characterBuffer[0] = '\xF0';
	characterBuffer[1] = '\x90';
	characterBuffer[2] = '\x8D';
	characterBuffer[3] = '\x13';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 4));

	//Test a character with two invalid code units
	characterBuffer[0] = '\xC0';
	characterBuffer[1] = '\x90';
	characterBuffer[2] = '\x8D';
	characterBuffer[3] = '\x16';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 4));

	//Test a character with three invalid code units
	characterBuffer[0] = '\xA0';
	characterBuffer[1] = '\xF3';
	characterBuffer[2] = '\x8D';
	characterBuffer[3] = '\x56';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 4));

	//Test a character with four invalid code units
	characterBuffer[0] = '\x98';
	characterBuffer[0] = '\xA2';
	characterBuffer[0] = '\x3D';
	characterBuffer[0] = '\xC6';

	CPPUNIT_ASSERT(!Utf8String::IsValidCharacter(characterBuffer, 4));
}

void Utf8StringTest::TestIsWhitespace()
{
	//Test characters in Unicode considered to be whitespace characters
	char whitespaceCharacter[4];

	//Test the function that accepts a char* and a size_t
	whitespaceCharacter[0] = '\x20';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 1));

	whitespaceCharacter[0] = '\x09';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 1));

	whitespaceCharacter[0] = '\x0D';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 1));

	whitespaceCharacter[0] = '\x0A';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 1));

	whitespaceCharacter[0] = '\xA0';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 1));

	whitespaceCharacter[0] = '\xE1';
	whitespaceCharacter[1] = '\x9A';
	whitespaceCharacter[2] = '\x80';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE1';
	whitespaceCharacter[1] = '\xA0';
	whitespaceCharacter[2] = '\x8E';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\x80';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\x86';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\x89';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\x8A';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\xBF';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x81';
	whitespaceCharacter[2] = '\x9F';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE3';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\x80';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\xB8';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x80';
	whitespaceCharacter[2] = '\xB9';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(whitespaceCharacter, 3));

	//Test characters that shouldn't be considered whitespace
	whitespaceCharacter[0] = '\x00';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 1));

	whitespaceCharacter[0] = '\x68';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 1));

	whitespaceCharacter[0] = '\xD0';
	whitespaceCharacter[1] = '\xB4';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 2));

	whitespaceCharacter[0] = '\xC3';
	whitespaceCharacter[1] = '\x9F';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 2));

	whitespaceCharacter[0] = '\xE1';
	whitespaceCharacter[1] = '\xBA';
	whitespaceCharacter[2] = '\xAB';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xE2';
	whitespaceCharacter[1] = '\x88';
	whitespaceCharacter[2] = '\x91';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 3));

	whitespaceCharacter[0] = '\xF0';
	whitespaceCharacter[1] = '\x92';
	whitespaceCharacter[2] = '\x81';
	whitespaceCharacter[3] = '\xA8';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 4));

	whitespaceCharacter[0] = '\xF0';
	whitespaceCharacter[1] = '\x90';
	whitespaceCharacter[2] = '\x8D';
	whitespaceCharacter[3] = '\x86';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(whitespaceCharacter, 4));


	//Test the function that accepts a Utf8Char
	Utf8Char utf8Character;

	utf8Character[0] = '\x20';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\x09';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\x0D';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\x0A';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xA0';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE1';
	utf8Character[1] = '\x9A';
	utf8Character[2] = '\x80';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE1';
	utf8Character[1] = '\xA0';
	utf8Character[2] = '\x8E';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE3';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x80';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x86';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x89';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x8A';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\xBF';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x81';
	utf8Character[2] = '\x9F';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE3';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\x80';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\xB8';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x80';
	utf8Character[2] = '\xB9';
	CPPUNIT_ASSERT(Utf8String::IsWhitespace(utf8Character));

	//Test characters that shouldn't be considered whitespace
	utf8Character.clear();

	utf8Character[0] = '\x00';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\x68';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xD0';
	utf8Character[1] = '\xB4';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xC3';
	utf8Character[1] = '\x9F';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE1';
	utf8Character[1] = '\xBA';
	utf8Character[2] = '\xAB';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xE2';
	utf8Character[1] = '\x88';
	utf8Character[2] = '\x91';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xF0';
	utf8Character[1] = '\x92';
	utf8Character[2] = '\x81';
	utf8Character[3] = '\xA8';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));

	utf8Character[0] = '\xF0';
	utf8Character[1] = '\x90';
	utf8Character[2] = '\x8D';
	utf8Character[3] = '\x86';
	CPPUNIT_ASSERT(!Utf8String::IsWhitespace(utf8Character));
}

void Utf8StringTest::TestIterator()
{
	TestIteratorWithStringOne();
	TestIteratorWithStringTwo();
	TestIteratorWithStringThree();
	TestIteratorWithStringFour();
}

void Utf8StringTest::TestIteratorReversal()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Create an iterator and put it in the middle of the string
	Utf8String::iterator stringIterator = utf8String.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT((*stringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT((*stringIterator)[1] == '\x9F');

	//Now convert to a reverse iterator
	Utf8String::reverse_iterator reverseStringIterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == '\xC3');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == '\x9F');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*reverseStringIterator)[3] == '\xA8');

	//Move the iterator to a four-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*stringIterator)[3] == '\xA8');

	//Now convert to a reverse iterator
	reverseStringIterator = Utf8String::reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*reverseStringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*reverseStringIterator)[3] == '\xA8');

	//Now convert back to a normal iterator
	stringIterator = Utf8String::iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == '\xF0');
	CPPUNIT_ASSERT((*stringIterator)[1] == '\x92');
	CPPUNIT_ASSERT((*stringIterator)[2] == '\x81');
	CPPUNIT_ASSERT((*stringIterator)[3] == '\xA8');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT((*stringIterator)[0] == '\x62');
}

void Utf8StringTest::TestLength()
{
	//Get the length of the default string
	Utf8String utf8String;

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf8String.length());

	//Get the length of a 0-length string
	utf8String = "";

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf8String.length());

	//Get the length of a single character (one code unit) string
	utf8String = "\x48";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf8String.length());

	//Get the length of a single character (two code units) string
	utf8String = "\xC3\xB6";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf8String.length());

	//Get the length of a single character (three code units) string
	utf8String = "\xE2\x88\x91";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf8String.length());

	//Get the length of a single character (four code units) string
	utf8String = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf8String.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	utf8String = "Simple String";

	CPPUNIT_ASSERT_EQUAL((size_t)13, utf8String.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	CPPUNIT_ASSERT_EQUAL((size_t)8, utf8String.length());

	//Get the length of a multi-character string containing both one-, two-, and three-code-unit characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)9, utf8String.length());

	//Get the length of a multi-character string containing both one-, two-, three- and four-code-unit characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)11, utf8String.length());


	//Run the tests again with a constant string
	//Get the length of the default string
	const Utf8String constUtf8String;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf8String.length());

	//Get the length of a 0-length string
	const Utf8String constUtf8String1 = "";

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf8String1.length());

	//Get the length of a single character (one code unit) string
	const Utf8String constUtf8String2 = "\x48";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8String2.length());

	//Get the length of a single character (two code units) string
	const Utf8String constUtf8String3 = "\xC3\xB6";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8String3.length());

	//Get the length of a single character (three code units) string
	const Utf8String constUtf8String4 = "\xE2\x88\x91";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8String4.length());

	//Get the length of a single character (four code units) string
	const Utf8String constUtf8String5 = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8String5.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	const Utf8String constUtf8String6 = "Simple String";

	CPPUNIT_ASSERT_EQUAL((size_t)13, constUtf8String6.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	const Utf8String constUtf8String7 = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	CPPUNIT_ASSERT_EQUAL((size_t)8, constUtf8String7.length());

	//Get the length of a multi-character string containing both one-, two-, and three-code-unit characters
	const Utf8String constUtf8String8 = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)9, constUtf8String8.length());

	//Get the length of a multi-character string containing both one-, two-, three- and four-code-unit characters
	const Utf8String constUtf8String9 = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)11, constUtf8String9.length());
}

void Utf8StringTest::TestPushBack()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Create a UTF-8 string that will be appended to
	Utf8String originalString = "ẫö∑b\xF0\x90\x8D\x86";
	//Create a UTF-8 string that will be the result appending a one-code-unit character
	Utf8String oneCodeUnitFinalString = "ẫö∑b\xF0\x90\x8D\x86\x53";
	//Create a UTF-8 string that will be the result appending a two-code-unit character
	Utf8String twoCodeUnitFinalString = "ẫö∑b\xF0\x90\x8D\x86\xC3\xB6";
	//Create a UTF-8 string that will be the result appending a three-code-unit character
	Utf8String threeCodeUnitFinalString = "ẫö∑b\xF0\x90\x8D\x86\xE1\xBA\xAB";
	//Create a UTF-8 string that will be the result appending a four-code-unit character
	Utf8String fourCodeUnitFinalString = "ẫö∑b\xF0\x90\x8D\x86\xF0\x92\x81\xA8";

	//Create a string upon which the push_back() function will be called
	Utf8String appendedString;

	//Append a one-code-unit character
	appendedString = originalString;
	appendedString.push_back(utf8String[0]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, appendedString);

	//Append a two-code-unit character
	appendedString = originalString;
	appendedString.push_back(utf8String[4]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, appendedString);

	//Append a three-code-unit character
	appendedString = originalString;
	appendedString.push_back(utf8String[1]);

	CPPUNIT_ASSERT_EQUAL(threeCodeUnitFinalString, appendedString);

	//Append a four-code-unit character
	appendedString = originalString;
	appendedString.push_back(utf8String[3]);

	CPPUNIT_ASSERT_EQUAL(fourCodeUnitFinalString, appendedString);
}

void Utf8StringTest::TestRbegin()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8String::reverse_iterator stringIterator = utf8String.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xD0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*stringIterator)[1]);

	utf8String = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	stringIterator = utf8String.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);

	//Run the test again with a constant string
	const Utf8String constUtf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8String::const_reverse_iterator constStringIterator = constUtf8String.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xD0', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*constStringIterator)[1]);

	const Utf8String constUtf8StringTwo = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	constStringIterator = constUtf8StringTwo.rbegin();

	CPPUNIT_ASSERT_EQUAL('\xE2', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*constStringIterator)[2]);
}

void Utf8StringTest::TestRend()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8String::reverse_iterator stringIterator = utf8String.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\x53', (*stringIterator)[0]);

	utf8String = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	stringIterator = utf8String.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);

	//Run the test again with a constant string
	const Utf8String constUtf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	Utf8String::const_reverse_iterator constStringIterator = constUtf8String.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\x53', (*constStringIterator)[0]);

	const Utf8String constUtf8StringTwo = "\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91";

	constStringIterator = constUtf8StringTwo.rend() - 1;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*constStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*constStringIterator)[2]);
}

void Utf8StringTest::TestReplace()
{
	//Create a UTF-8 string, parts of which will be used to replace parts of other strings
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	//Create a UTF-8 string that will be the string before replacement
	Utf8String originalString = "ẫö∑b\xF0\x90\x8D\x86";
	//Create a string on which the replace() function is to be called
	Utf8String replaceString;

	//Create the string that results from a replace at the beginning of the string
	Utf8String finalBeginReplaceString = "\x53\xE1\xBA\xAB\x62ö∑b\xF0\x90\x8D\x86";
	//Create the string that results from a replace in the middle of the string
	Utf8String finalMiddleReplaceString = "ẫö\x53\xE1\xBA\xAB\x62" "b\xF0\x90\x8D\x86";
	//Create the string that results from a replace at the end of the string
	Utf8String finalEndReplaceString = "ẫö∑b\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	//Create the string that results from a replace where the replacement string is actually appended
	Utf8String finalAppendReplaceString = "ẫö∑b\xF0\x90\x8D\x86\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	//Create the string that results when the section begin iterator is at the same position as the
	//section end iterator
	Utf8String finalSamePositionReplaceString = "ẫö\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4" "∑b\xF0\x90\x8D\x86";
	//Create the string that results when the section begin iterator is pointing to a position
	//past that of the section end iterator
	Utf8String finalEarlierPositionReplaceString = "ẫö\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	//Create a character to be used as a replacement character
	Utf8Char replacementCharacter = 'X';
	//Create a string to use in storing the final result of a single character replacement
	Utf8String singleCharacterReplaceString;

	//Test the replace() function that accepts size_t, size_t, Utf8String
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
	replaceString.replace(0, 10, 5, replacementCharacter);

	singleCharacterReplaceString = "XXXXX";
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(0, 1, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, "XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(2, 1, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, "XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(4, 10, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(5, 4, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().append("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Test the replace() function that accepts Utf8String::iterator, Utf8String::iterator, Utf8String
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


	//Test the replace() function that accepts Utf8String::iterator, Utf8String::iterator, size_t, Utf8Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), 5, replacementCharacter);

	singleCharacterReplaceString = "XXXXX";
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, "XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 2, replaceString.begin() + 3, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).insert(2, "XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(4, 1).append("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().append("XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);
}

void Utf8StringTest::TestReverseIterator()
{
	TestReverseIteratorWithStringOne();
	TestReverseIteratorWithStringTwo();
	TestReverseIteratorWithStringThree();
	TestReverseIteratorWithStringFour();
}

void Utf8StringTest::TestRFind()
{
	//Create a UTF-8 string to be searched
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	size_t foundIndex;

	//Find a single character at the beginning of the string
	foundIndex = utf8String.rfind("\x53");

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = utf8String.rfind("\x33");

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = utf8String.rfind("\xC3\xB6");

	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Find a three-code-unit character in the middle of the string
	foundIndex = utf8String.rfind("\xE1\xBA\xAB");

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find a four-code-unit character in the middle of the string
	foundIndex = utf8String.rfind("\xF0\x92\x81\xA8");

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = utf8String.rfind("\x53\xE1\xBA\xAB");

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = utf8String.rfind("\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33");

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = utf8String.rfind("\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4");

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = utf8String.rfind("\xC1\x87");

	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = utf8String.rfind("\xE3\x89\xAA\x34\xC0\x99");

	CPPUNIT_ASSERT_EQUAL(Utf8String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf8String.rfind("\xE1\xBA\xAB", 6);

	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);
}

void Utf8StringTest::TestSize()
{
	//Get the length of the default string
	Utf8String utf8String;

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf8String.size());

	//Get the size of a 0-length string
	utf8String = "";

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf8String.size());

	//Get the size of a single character (one code unit) string
	utf8String = "\x48";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf8String.size());

	//Get the size of a single character (two code units) string
	utf8String = "\xC3\xB6";

	CPPUNIT_ASSERT_EQUAL((size_t)2, utf8String.size());

	//Get the size of a single character (three code units) string
	utf8String = "\xE2\x88\x91";

	CPPUNIT_ASSERT_EQUAL((size_t)3, utf8String.size());

	//Get the size of a single character (four code units) string
	utf8String = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT_EQUAL((size_t)4, utf8String.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	utf8String = "Simple String";

	CPPUNIT_ASSERT_EQUAL((size_t)13, utf8String.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	CPPUNIT_ASSERT_EQUAL((size_t)11, utf8String.size());

	//Get the size of a multi-character string containing both one-, two-, and three-code-unit characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)18, utf8String.size());

	//Get the size of a multi-character string containing both one-, two-, three- and four-code-unit characters
	utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)26, utf8String.size());


	//Run the tests again with a constant string
	//Get the size of the default string
	const Utf8String constUtf8String;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf8String.size());

	//Get the size of a 0-length string
	const Utf8String constUtf8String1 = "";

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf8String1.size());

	//Get the size of a single character (one code unit) string
	const Utf8String constUtf8String2 = "\x48";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf8String2.size());

	//Get the size of a single character (two code units) string
	const Utf8String constUtf8String3 = "\xC3\xB6";

	CPPUNIT_ASSERT_EQUAL((size_t)2, constUtf8String3.size());

	//Get the size of a single character (three code units) string
	const Utf8String constUtf8String4 = "\xE2\x88\x91";

	CPPUNIT_ASSERT_EQUAL((size_t)3, constUtf8String4.size());

	//Get the size of a single character (four code units) string
	const Utf8String constUtf8String5 = "\xF0\x92\x81\xA8";

	CPPUNIT_ASSERT_EQUAL((size_t)4, constUtf8String5.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	const Utf8String constUtf8String6 = "Simple String";

	CPPUNIT_ASSERT_EQUAL((size_t)13, constUtf8String6.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	const Utf8String constUtf8String7 = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	CPPUNIT_ASSERT_EQUAL((size_t)11, constUtf8String7.size());

	//Get the size of a multi-character string containing both one-, two-, and three-code-unit characters
	const Utf8String constUtf8String8 = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)18, constUtf8String8.size());

	//Get the size of a multi-character string containing both one-, two-, three- and four-code-unit characters
	const Utf8String constUtf8String9 = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	CPPUNIT_ASSERT_EQUAL((size_t)26, constUtf8String9.size());
}

void Utf8StringTest::TestStreamOperators()
{
	stringstream stringStream;

	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB \x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB \t\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8String deserializedString;

	//Write the string to a stream
	stringStream << utf8String;

	//Reset the stream position to the beginning
	stringStream.seekg(0, ios::beg);

	//Now read in a string from the stream.  Every time the >> operator is called, we should retrieve
	//the parts of the string up until whitespace is encountered, with the whitespace not included
	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL('\x53', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL('\xE1', deserializedString[1][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', deserializedString[1][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', deserializedString[1][2]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)13, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL('\x62', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL('\xF0', deserializedString[1][0]);
	CPPUNIT_ASSERT_EQUAL('\x92', deserializedString[1][1]);
	CPPUNIT_ASSERT_EQUAL('\x81', deserializedString[1][2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', deserializedString[1][3]);
	CPPUNIT_ASSERT_EQUAL('\xC3', deserializedString[2][0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', deserializedString[2][1]);
	CPPUNIT_ASSERT_EQUAL('\xC3', deserializedString[3][0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', deserializedString[3][1]);
	CPPUNIT_ASSERT_EQUAL('\x33', deserializedString[4][0]);
	CPPUNIT_ASSERT_EQUAL('\xE1', deserializedString[5][0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', deserializedString[5][1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', deserializedString[5][2]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)3, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)9, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL('\xE2', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL('\x88', deserializedString[0][1]);
	CPPUNIT_ASSERT_EQUAL('\x91', deserializedString[0][2]);
	CPPUNIT_ASSERT_EQUAL('\xF0', deserializedString[1][0]);
	CPPUNIT_ASSERT_EQUAL('\x90', deserializedString[1][1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', deserializedString[1][2]);
	CPPUNIT_ASSERT_EQUAL('\x86', deserializedString[1][3]);
	CPPUNIT_ASSERT_EQUAL('\xD0', deserializedString[2][0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', deserializedString[2][1]);
}

void Utf8StringTest::TestSubstr()
{
	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

	//Get a substring starting at index 0
	Utf8String subString = utf8String.substr(0, 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)11, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\x53");
	CPPUNIT_ASSERT(subString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[2] == "\x62");
	CPPUNIT_ASSERT(subString[3] == "\xF0\x92\x81\xA8");
	CPPUNIT_ASSERT(subString[4] == "\xC3\xB6");

	//Get a substring from the middle of the string
	subString = utf8String.substr(5, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)9, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xC3\x9F");
	CPPUNIT_ASSERT(subString[1] == "\x33");
	CPPUNIT_ASSERT(subString[2] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[3] == "\xE2\x88\x91");

	//Get a substring that ends on the last character of the string
	subString = utf8String.substr(7, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)12, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[1] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(subString[2] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(subString[3] == "\xD0\xB4");

	//Get a substring where the count extends past the end of the string
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)12, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[1] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(subString[2] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(subString[3] == "\xD0\xB4");

	//Get a substring of length 0
	subString = utf8String.substr(7, 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.size());
	
	//Get a substring of length 1
	subString = utf8String.substr(7, 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)3, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\xE1\xBA\xAB");

	//Get a substring using only the first parameter
	subString = utf8String.substr(6);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)13, subString.size());
	CPPUNIT_ASSERT(subString[0] == "\x33");
	CPPUNIT_ASSERT(subString[1] == "\xE1\xBA\xAB");
	CPPUNIT_ASSERT(subString[2] == "\xE2\x88\x91");
	CPPUNIT_ASSERT(subString[3] == "\xF0\x90\x8D\x86");
	CPPUNIT_ASSERT(subString[4] == "\xD0\xB4");

	//Get a substring using no parameters
	subString = utf8String.substr();

	CPPUNIT_ASSERT(utf8String == subString);
}

void Utf8StringTest::TestSwap()
{
	//Create a UTF-8 string composed of one-, two-, three- and four-code-unit characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB \x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB \t\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	Utf8String secondString = "\xF4\x94\xA2\x88\x85";
	Utf8String emptyString;

	Utf8String firstSwapString;
	Utf8String secondSwapString;

	//Swap two strings
	firstSwapString = utf8String;
	secondSwapString = secondString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(secondString, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(utf8String, secondSwapString);

	//Swap the two string back
	secondSwapString.swap(firstSwapString);

	CPPUNIT_ASSERT_EQUAL(utf8String, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(secondString, secondSwapString);

	//Swap a populated string with an empty string
	firstSwapString = utf8String;
	secondSwapString = emptyString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, emptyString);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, utf8String);

	//Swap an empty string with a populated string
	firstSwapString = emptyString;
	secondSwapString = utf8String;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, utf8String);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, emptyString);
}

/*Private Helper Functions*/

void Utf8StringTest::TestConstructorsWithStrings(const std::string& characterString,
	const UtfString::Utf8String& utf8String, const UtfString::Utf16String& utf16String)
{
	//Create a Utf16String using the constructor that accepts a Utf16String
	Utf8String* constructedString = new Utf8String(utf16String);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a wchar_t*
	wstring wideString;

	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	constructedString = new Utf8String(wideString.c_str());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf8String using the constructor that accepts a wchar_t* and a size_t
	constructedString = new Utf8String(wideString.c_str(), wideString.size());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf8String using the constructor that accepts a wstring
	constructedString = new Utf8String(wideString);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf8String using the constructor that accepts a Utf8String
	constructedString = new Utf8String(utf8String);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf8String using the constructor that accepts a string
	constructedString = new Utf8String(characterString);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf8String using the constructor that accepts a char*
	constructedString = new Utf8String(characterString.c_str());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf8String using the constructor that accepts a char* and a size_t
	constructedString = new Utf8String(characterString.c_str(), characterString.size());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf8String, *constructedString);

	delete constructedString;
	constructedString = NULL;
}

void Utf8StringTest::TestConstIteratorWithStringOne()
{
	//Create a UTF-8 string containing only ASCII characters
	const Utf8String utf8String = "Simple String";
	
	//Get an iterator to the beginning of the string
	Utf8String::const_iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('S', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a 'p'
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a 'g'
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('g', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::const_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('p', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('t', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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

void Utf8StringTest::TestConstIteratorWithStringTwo()
{
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	const Utf8String utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	//Get an iterator to the beginning of the string
	Utf8String::const_iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xCF', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', (*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than two code units
		CPPUNIT_ASSERT((*stringIterator).size() >= 1);
		CPPUNIT_ASSERT((*stringIterator).size() <= 2);

		//The third character should be a "\x34"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The fifth character should be a "\xD1\x8A"
		if(characterCount == 4)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::const_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xCF', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', (*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xCF', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', (*stringIterator)[1]);

	stringIterator -= 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x68', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator)[0]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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

void Utf8StringTest::TestConstIteratorWithStringThree()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	const Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::const_iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than three code units
		CPPUNIT_ASSERT((*stringIterator).size() >= 1);
		CPPUNIT_ASSERT((*stringIterator).size() <= 3);

		//The third character should be a '\x62'
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\xE2\x88\x91"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = *--stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = *stringIterator--;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x33', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = *++stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = *stringIterator++;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::const_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*newStringIterator)[1]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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

void Utf8StringTest::TestConstIteratorWithStringFour()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	const Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::const_iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and four code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT((*stringIterator).size() <= (size_t)4);

		//The second character should be a "\xE1\xBA\xAB"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 3);
		}

		//The fourth character should be a "\xF0\x92\x81\xA8"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', (*stringIterator)[1]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = (*--stringIterator);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator--);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = (*++stringIterator);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator++);
			CPPUNIT_ASSERT_EQUAL('\x62', character[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);
		}

		//The tenth character should be a "\xF0\x90\x8D\x86"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 4);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);


	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::const_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', (*newStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', (*newStringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', (*newStringIterator)[3]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x33', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x33', (*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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


void Utf8StringTest::TestConstReverseIteratorWithStringOne()
{
	//Create a UTF-8 string containing only ASCII characters
	const Utf8String utf8String = "Simple String";
	
	//Get an reverse iterator to the end of the string
	Utf8String::const_reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('g', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a 'r'
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('S', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::const_reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('r', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('l', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

void Utf8StringTest::TestConstReverseIteratorWithStringTwo()
{
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	const Utf8String utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	//Get an iterator to the beginning of the string
	Utf8String::const_reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should one or two code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT((*stringIterator).size() <= (size_t)2);

		//The fourth character should be a "\xD1\x8A"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 2);
		}

		//The fifth character should be a '\x34'
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::const_reverse_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

void Utf8StringTest::TestConstReverseIteratorWithStringThree()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	const Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::const_reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and three code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT((*stringIterator).size() <= (size_t)3);

		//The third character should be a "\xE1\xBA\xAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 3);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', (*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::const_reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\x33', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x33', (*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

void Utf8StringTest::TestConstReverseIteratorWithStringFour()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	const Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::const_reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and four code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT((*stringIterator).size() <= (size_t)4);

		//The second character should be a "\xF0\x90\x8D\x86"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 4);
		}

		//The fourth character should be a "\xE1\xBA\xAB"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 3);
		}

		//The eighth character should be a "\xF0\x92\x81\xA8"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = (*--stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator--);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = (*++stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator++);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::const_reverse_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*newStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*newStringIterator)[2]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*stringIterator)[1]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

void Utf8StringTest::TestIteratorWithStringOne()
{
	//Create a UTF-8 string containing only ASCII characters
	Utf8String utf8String = "Simple String";
	
	//Get an iterator to the beginning of the string
	Utf8String::iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('S', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "p"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('e', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "g"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('g', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('p', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('t', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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

void Utf8StringTest::TestIteratorWithStringTwo()
{
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	Utf8String utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	//Get an iterator to the beginning of the string
	Utf8String::iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xCF', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', (*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than two code units
		CPPUNIT_ASSERT((*stringIterator).size() >= 1);
		CPPUNIT_ASSERT((*stringIterator).size() <= 2);

		//The third character should be a "\x34"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The fifth character should be a "\xD1\x8A"
		if(characterCount == 4)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xCF', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', (*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xCF', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x89', (*stringIterator)[1]);

	stringIterator -= 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x68', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator)[0]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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

void Utf8StringTest::TestIteratorWithStringThree()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than three code units
		CPPUNIT_ASSERT((*stringIterator).size() >= 1);
		CPPUNIT_ASSERT((*stringIterator).size() <= 3);

		//The third character should be a '\x62'
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\xE2\x88\x91"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = *--stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = *stringIterator--;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x33', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = *++stringIterator;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = *stringIterator++;
			CPPUNIT_ASSERT_EQUAL('\xE1', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', character[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', character[2]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*newStringIterator)[1]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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

void Utf8StringTest::TestIteratorWithStringFour()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::iterator stringIterator = utf8String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x53', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either between 1 and four code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1 && (*stringIterator).size() <= (size_t)4);

		//The fourth character should be a "\xF0\x92\x81\xA8"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 4);
		}

		//The sixth character should be a "\xC3\x9F"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 2);
		}

		//The tenth character should be a "\xF0\x90\x8D\x86"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB4', (*stringIterator)[1]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = (*--stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator--);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = (*++stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator++);
			CPPUNIT_ASSERT_EQUAL('\xE2', character[0]);
			CPPUNIT_ASSERT_EQUAL('\x88', character[1]);
			CPPUNIT_ASSERT_EQUAL('\x91', character[2]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.begin();
	CPPUNIT_ASSERT(stringIterator != utf8String.end());

	stringIterator = utf8String.end();
	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the += operator
	stringIterator = utf8String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf8String.end());

	//Test the + operator
	stringIterator = utf8String.begin();
	Utf8String::iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', (*newStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', (*newStringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', (*newStringIterator)[3]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf8String.end());

	//Test the -= operator
	stringIterator = utf8String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xE2', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x88', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x91', (*stringIterator)[2]);

	stringIterator -= 8;

	CPPUNIT_ASSERT(stringIterator == utf8String.begin());

	//Test the - operator
	stringIterator = utf8String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\x33', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\x33', (*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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
	stringIterator = utf8String.begin();
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

void Utf8StringTest::TestReverseIteratorWithStringOne()
{
	//Create a UTF-8 string containing only ASCII characters
	Utf8String utf8String = "Simple String";
	
	//Get an reverse iterator to the end of the string
	Utf8String::reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('g', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a 'r'
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('S', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(' ', (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('S', (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('t', (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('r', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('r', (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('p', (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('l', (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('l', (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

void Utf8StringTest::TestReverseIteratorWithStringTwo()
{
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	Utf8String utf8String = "\xCF\x89\x45\x34\x68\xD1\x8A\xCF\x89\x45\x34";

	//Get an iterator to the beginning of the string
	Utf8String::reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should one or two code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT((*stringIterator).size() <= (size_t)2);

		//The fourth character should be a "\xD1\x8A"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 2);
		}

		//The fifth character should be a '\x34'
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x68', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x34', (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::reverse_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL('\x45', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	newStringIterator = stringIterator + 7;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x45', (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xD1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x8A', (*stringIterator)[1]);

	newStringIterator = stringIterator - 3;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

void Utf8StringTest::TestReverseIteratorWithStringThree()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and three code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT((*stringIterator).size() <= (size_t)3);

		//The third character should be a "\xE1\xBA\xAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 3);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', (*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL('\x33', (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\x33', (*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

void Utf8StringTest::TestReverseIteratorWithStringFour()
{
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\x53\xE1\xBA\xAB\x62\xF0\x92\x81\xA8\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";
	
	//Get an iterator to the beginning of the string
	Utf8String::reverse_iterator stringIterator = utf8String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL('\xD0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB4', (*stringIterator)[1]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf8String.length();

	while(stringIterator != utf8String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have between one and four code units
		CPPUNIT_ASSERT((*stringIterator).size() >= (size_t)1);
		CPPUNIT_ASSERT((*stringIterator).size() <= (size_t)4);

		//The second character should be a "\xF0\x90\x8D\x86"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x90', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x8D', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\x86', (*stringIterator)[3]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 4);
		}

		//The fourth character should be a "\xE1\xBA\xAB"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)3, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 3);
		}

		//The eighth character should be a "\xF0\x92\x81\xA8"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\x62', (*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			Utf8Char character = (*--stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator--);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x9F', (*stringIterator)[1]);

			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			character = (*++stringIterator);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			character = (*stringIterator++);
			CPPUNIT_ASSERT_EQUAL('\xC3', character[0]);
			CPPUNIT_ASSERT_EQUAL('\xB6', character[1]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)4, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
			CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
			CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf8String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf8String.rend());

	stringIterator = utf8String.rend();
	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the += operator
	stringIterator = utf8String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf8String.rend());

	//Test the + operator
	stringIterator = utf8String.rbegin();
	Utf8String::reverse_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*newStringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*newStringIterator)[2]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL('\xE1', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xBA', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\xAB', (*stringIterator)[2]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rend());

	//Test the -= operator
	stringIterator = utf8String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL('\xF0', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\x92', (*stringIterator)[1]);
	CPPUNIT_ASSERT_EQUAL('\x81', (*stringIterator)[2]);
	CPPUNIT_ASSERT_EQUAL('\xA8', (*stringIterator)[3]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf8String.rbegin());

	//Test the - operator
	stringIterator = utf8String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*newStringIterator)[1]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL('\xC3', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL('\xB6', (*stringIterator)[1]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf8String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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
	stringIterator = utf8String.rbegin();
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

