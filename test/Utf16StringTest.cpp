/*!
\file Utf16StringTest.cpp

This file contains the definition of the Utf16StringTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <sstream>
#include <string>

#include "Utf16StringTest.h"
#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

/*Public Test Functions*/

void Utf16StringTest::TestAppend()
{
	//Test the append functionality with a string composed of only single-code-unit characters
	//Create a standard string class containing a 1-, 2-, and 3-byte UTF-8 characters
	string characterString = "Sẫböß3ẫ∑д";
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create a UTF-16 string that will be appended to
	Utf16String originalString = L"\x2211\x0053\x0062\x00F6";
	//Create the UTF-16 string that results from an append operation
	Utf16String finalString = L"\x2211\x0053\x0062\x00F6\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Create a wstring version of the UTF-16 string to be appended
	wstring wideString;

	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}


	//Test the append() function that accepts a Utf16String
	Utf16String appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a basic_string<UInt16>
	appendedString = originalString;
	appendedString.append((basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UInt16*
	appendedString = originalString;
	appendedString.append(utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UInt16* and a size_t
	appendedString = originalString;
	appendedString.append(utf16String.c_str(), utf16String.size());

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

	//Test the append() function that accepts a Utf8String
	appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a string
	appendedString = originalString;
	appendedString.append(characterString);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char*
	appendedString = originalString;
	appendedString.append(characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char* and a size_t
	appendedString = originalString;
	appendedString.append(characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Now test the append functionality with UTF-16 string containing characters with two code units
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	characterString = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UTF-16 string that will be appended to
	originalString = L"\x1EAB\x2211\xD800\xDF46";
	//Create the UTF-16 string that results from an append operation
	finalString = L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Create a wstring version of the UTF-16 string to be appended
	wideString.clear();
	codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the append() function that accepts a Utf16String
	appendedString = originalString;
	appendedString.append(utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a basic_string<UInt16>
	appendedString = originalString;
	appendedString.append((basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UInt16*
	appendedString = originalString;
	appendedString.append(utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a UInt16* and a size_t
	appendedString = originalString;
	appendedString.append(utf16String.c_str(), utf16String.size());

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

	//Test the append() function that accepts a Utf8String
	appendedString = originalString;
	appendedString.append(utf8String);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a string
	appendedString = originalString;
	appendedString.append(characterString);

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char*
	appendedString = originalString;
	appendedString.append(characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a char* and a size_t
	appendedString = originalString;
	appendedString.append(characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(finalString, appendedString);

	//Test the append() function that accepts a Utf16Char

	//Create a UTF-16 string that will be the result of appending a one-code-unit character
	Utf16String oneCodeUnitFinalString = L"\x1EAB\x2211\xD800\xDF46\x0053";
	//Create a UTF-16 string that will be the result of appending a two-code-unit character
	Utf16String twoCodeUnitFinalString = L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68";

	//Append a one-code-unit character
	appendedString = originalString;
	appendedString.append(utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, appendedString);

	//Append a two-code-unit character
	appendedString = originalString;
	appendedString.append(utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, appendedString);
}

void Utf16StringTest::TestAssign()
{
	//Test the assign functionality with a string composed of only single-code-unit characters
	//Create a standard string class containing a 1-, 2-, and 3-byte UTF-8 characters
	string characterString = "Sẫböß3ẫ∑д";
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create a UTF-16 string that will be assigned to
	Utf16String originalString = L"\x2211\x0053\x0062\x00F6";

	//Create a wstring version of the UTF-16 string to be assigned
	wstring wideString;

	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the assign() function that accepts a Utf16String
	Utf16String assignedString = originalString;
	assignedString.assign(utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a basic_string<UInt16>
	assignedString = originalString;
	assignedString.assign((basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a UInt16*
	assignedString = originalString;
	assignedString.assign(utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a UInt16* and a size_t
	assignedString = originalString;
	assignedString.assign(utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a wchar_t*
	assignedString = originalString;
	assignedString.assign(wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a wchar_t* and a size_t
	assignedString = originalString;
	assignedString.assign(wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a wstring
	assignedString = originalString;
	assignedString.assign(wideString);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a string
	assignedString = originalString;
	assignedString.assign(characterString);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a char*
	assignedString = originalString;
	assignedString.assign(characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a char* and a size_t
	assignedString = originalString;
	assignedString.assign(characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Now test the assign functionality with UTF-16 string containing characters with two code units
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	characterString = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UTF-16 string that will be assigned to
	originalString = L"\x1EAB\x2211\xD800\xDF46";

	//Create a wstring version of the UTF-16 string to be assigned
	wideString.clear();
	codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the assign() function that accepts a Utf16String
	assignedString = originalString;
	assignedString.assign(utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a basic_string<UInt16>
	assignedString = originalString;
	assignedString.assign((basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a UInt16*
	assignedString = originalString;
	assignedString.assign(utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a UInt16* and a size_t
	assignedString = originalString;
	assignedString.assign(utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a wchar_t*
	assignedString = originalString;
	assignedString.assign(wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a wchar_t* and a size_t
	assignedString = originalString;
	assignedString.assign(wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a wstring
	assignedString = originalString;
	assignedString.assign(wideString);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a Utf8String
	assignedString = originalString;
	assignedString.assign(utf8String);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a string
	assignedString = originalString;
	assignedString.assign(characterString);

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a char*
	assignedString = originalString;
	assignedString.assign(characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a char* and a size_t
	assignedString = originalString;
	assignedString.assign(characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, assignedString);

	//Test the assign() function that accepts a Utf16Char

	//Create a UTF-16 string that will be the result of assigning a one-code-unit character
	Utf16String oneCodeUnitFinalString = L"\x0053";
	//Create a UTF-16 string that will be the result of assigning a two-code-unit character
	Utf16String twoCodeUnitFinalString = L"\xD808\xDC68";

	//Append a one-code-unit character
	assignedString = originalString;
	assignedString.assign(utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, assignedString);

	//Append a two-code-unit character
	assignedString = originalString;
	assignedString.assign(utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, assignedString);

}

void Utf16StringTest::TestAt()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Get the character at the beginning of the string
	Utf16Char character = utf16String.at(0);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', character[0]);

	//Get the character at the end of the string
	character = utf16String.at(utf16String.length() - 1);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);

	//Get a one-code-unit character in the middle of the string
	character = utf16String.at(5);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', character[0]);

	//Get a two-code-unit character in the middle of the string
	character = utf16String.at(3);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a character just past the end of the string
	CPPUNIT_ASSERT_THROW(utf16String.at(utf16String.length()), std::out_of_range);

	//Attempt to get a character way past the end of the string
	CPPUNIT_ASSERT_THROW(utf16String.at(utf16String.length() + 23), std::out_of_range);

	#pragma warning (pop)

	//Repeat the same tests with a constant string
	const Utf16String constUtf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Get the character at the beginning of the string
	character = constUtf16String.at(0);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', character[0]);

	//Get the character at the end of the string
	character = constUtf16String.at(constUtf16String.length() - 1);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);

	//Get a one-code-unit character in the middle of the string
	character = constUtf16String.at(5);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', character[0]);

	//Get a two-code-unit character in the middle of the string
	character = constUtf16String.at(3);

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);

	//This warning always appears in Visual Studio when we use CPPUNIT_ASSERT_THROW.  
	//It doesn't pose a problem, so we'll suppress it
	#pragma warning (push)
	#pragma warning(disable: 4127)

	//Attempt to get a character just past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf16String.at(constUtf16String.length()), std::out_of_range);

	//Attempt to get a character way past the end of the string
	CPPUNIT_ASSERT_THROW(constUtf16String.at(constUtf16String.length() + 23), std::out_of_range);

	#pragma warning (pop)
}

void Utf16StringTest::TestBegin()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::iterator stringIterator = utf16String.begin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', (*stringIterator)[0]);

	utf16String = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	stringIterator = utf16String.begin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*stringIterator)[1]);

	//Run the test again with a constant string
	const Utf16String constUtf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::const_iterator constStringIterator = constUtf16String.begin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', (*constStringIterator)[0]);

	const Utf16String constUtf16StringTwo = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	constStringIterator = constUtf16StringTwo.begin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constStringIterator)[1]);
}

void Utf16StringTest::TestCapacity()
{
	Utf16String utf16String;

	CPPUNIT_ASSERT(utf16String.size() <= utf16String.capacity());

	utf16String.append("Bob");

	CPPUNIT_ASSERT(utf16String.size() <= utf16String.capacity());

	utf16String.append(L"\xD808\xDC68");

	CPPUNIT_ASSERT(utf16String.size() <= utf16String.capacity());

	Utf16String appendString = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	utf16String.append(appendString);

	CPPUNIT_ASSERT(utf16String.size() <= utf16String.capacity());
}

void Utf16StringTest::TestCharacterCodeUnitCount()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Create a wstring version of the UTF-16 string
	wstring wideString;
	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Test the CharacterCodeUnitCount() function that accepts a wstring::iterator
	//Test with one-code-unit characters
	wstring::iterator wstringIterator = wideString.begin() + 1;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(wstringIterator));

	wstringIterator = wideString.begin() + 5;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(wstringIterator));

	//Test with two-code-unit characters
	wstringIterator = wideString.begin() + 3;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(wstringIterator));

	wstringIterator = wideString.begin() + 10;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(wstringIterator));

	//Test with the iterator pointing to the second code unit of a two-code-unit character
	wstringIterator = wideString.begin() + 4;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf16String::CharacterCodeUnitCount(wstringIterator));

	//Test the CharacterCodeUnitCount() function that accepts a Utf16String::const_iterator
	//Test with one-code-unit characters
	Utf16String::const_iterator utf16StringIterator = utf16String.begin() + 1;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(utf16StringIterator));

	utf16StringIterator = utf16String.begin() + 4;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(utf16StringIterator));

	//Test with two-code-unit characters
	utf16StringIterator = utf16String.begin() + 3;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(utf16StringIterator));

	utf16StringIterator = utf16String.begin() + 9;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(utf16StringIterator));

	//Test the CharacterCodeUnitCount() function that accepts a basic_string<UInt16>::const_iterator
	//Test with one-code-unit characters
	codeUnitString = utf16String;

	basic_string<UInt16>::const_iterator codeUnitIterator = codeUnitString.begin() + 1;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(codeUnitIterator));

	codeUnitIterator = codeUnitString.begin() + 6;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with two-code-unit characters
	codeUnitIterator = codeUnitString.begin() + 3;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(codeUnitIterator));

	codeUnitIterator = codeUnitString.begin() + 10;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(codeUnitIterator));

	//Test with the iterator pointing to the second code unit of a two-code-unit character
	codeUnitIterator = codeUnitString.begin() + 4;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf16String::CharacterCodeUnitCount(codeUnitIterator));

	//Test the CharacterCodeUnitCount() function that accepts a basic_string<UInt16>::const_reverse_iterator
	basic_string<UInt16>::const_reverse_iterator reverseCodeUnitIterator = codeUnitString.rbegin() + 5;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	reverseCodeUnitIterator = codeUnitString.rbegin() + 13;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with two-code-unit characters
	reverseCodeUnitIterator = codeUnitString.rbegin() + 3;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	reverseCodeUnitIterator = codeUnitString.rbegin() + 10;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test with the iterator pointing to the first code unit of a two-code-unit character
	reverseCodeUnitIterator = codeUnitString.rbegin() + 4;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf16String::CharacterCodeUnitCount(reverseCodeUnitIterator));

	//Test the CharacterCodeUnitCount() function that accepts a UInt16*
	codeUnitString = utf16String;

	basic_string<UInt16>::iterator codeUnitNonConstIterator = codeUnitString.begin() + 1;
	UInt16 character = *codeUnitNonConstIterator;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(&character));

	codeUnitNonConstIterator = codeUnitString.begin() + 6;
	character = *codeUnitNonConstIterator;
	CPPUNIT_ASSERT_EQUAL((size_t)1, Utf16String::CharacterCodeUnitCount(&character));

	//Test with two-code-unit characters
	codeUnitNonConstIterator = codeUnitString.begin() + 3;
	character = *codeUnitNonConstIterator;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(&character));

	codeUnitNonConstIterator = codeUnitString.begin() + 10;
	character = *codeUnitNonConstIterator;
	CPPUNIT_ASSERT_EQUAL((size_t)2, Utf16String::CharacterCodeUnitCount(&character));

	//Test with the iterator pointing to the second code unit of a two-code-unit character
	codeUnitNonConstIterator = codeUnitString.begin() + 4;
	character = *codeUnitNonConstIterator;
	CPPUNIT_ASSERT_EQUAL((size_t)0, Utf16String::CharacterCodeUnitCount(&character));

}

void Utf16StringTest::TestClear()
{
	Utf16String utf16String;

	CPPUNIT_ASSERT(utf16String.size() == 0);
	CPPUNIT_ASSERT(utf16String.length() == 0);

	utf16String.clear();

	CPPUNIT_ASSERT(utf16String.size() == 0);
	CPPUNIT_ASSERT(utf16String.length() == 0);

	utf16String = L"\xD808\xDC68";

	CPPUNIT_ASSERT(utf16String.size() == 2);
	CPPUNIT_ASSERT(utf16String.length() == 1);

	utf16String.clear();

	CPPUNIT_ASSERT(utf16String.size() == 0);
	CPPUNIT_ASSERT(utf16String.length() == 0);

	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	CPPUNIT_ASSERT(utf16String.size() == 15);
	CPPUNIT_ASSERT(utf16String.length() == 12);

	utf16String.clear();

	CPPUNIT_ASSERT(utf16String.size() == 0);
	CPPUNIT_ASSERT(utf16String.length() == 0);
}

void Utf16StringTest::TestCodePointIndex()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Test using the first code unit
	CPPUNIT_ASSERT_EQUAL((size_t)0, utf16String.code_point_index(0));

	//Test using the code unit of a one-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)7, utf16String.code_point_index(8));

	//Test using the first code unit of a two-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)9, utf16String.code_point_index(10));

	//Test using the second code unit of a two-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)9, utf16String.code_point_index(11));

	//Test using the last code unit
	CPPUNIT_ASSERT_EQUAL((size_t)11, utf16String.code_point_index(14));

}

void Utf16StringTest::TestCodeUnitIndex()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Test using the first code point
	CPPUNIT_ASSERT_EQUAL((size_t)0, utf16String.code_unit_index(0));

	//Test using a one-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)9, utf16String.code_unit_index(8));

	//Test using a two-code-unit code point
	CPPUNIT_ASSERT_EQUAL((size_t)10, utf16String.code_unit_index(9));

	//Test using the last code point
	CPPUNIT_ASSERT_EQUAL((size_t)13, utf16String.code_unit_index(11));
}

void Utf16StringTest::TestCompare()
{
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	std::string characterString = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	Utf8String utf8String = "\xF0\x92\x81\xA8" "Sẫ\xF0\x92\x81\xA8" "bö\xEF\xBF\x9F" "3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create an empty string
	Utf16String emptyString;
	Utf8String emptyUtf8String;
	std::wstring emptyWideString;
	std::string emptyCharacterString;

	//Create a wstring version of the UTF-16 string
	wstring wideString;

	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

	//Create a string to do the comparison with
	Utf16String compareString;


	//Test the compare() function that accepts a Utf16String
	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyString) == 0);

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(utf16String) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(utf16String) > 0);


	//Test the compare() function that accepts a basic_string<UInt16>
	compareString.clear();

	//Compare empty strings
	basic_string<UInt16> basicString = emptyString;
	CPPUNIT_ASSERT(compareString.compare(basicString) == 0);

	basicString = utf16String;

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xEF42\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(basicString) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(basicString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(basicString) > 0);


	//Test the compare() function that accepts a UInt16*
	compareString.clear();

	//Compare empty strings
	const UInt16* utf16StringBuffer = emptyString.c_str();
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) == 0);

	utf16StringBuffer = utf16String.c_str();

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer) > 0);


	//Test the compare() function that accepts a UInt16* and a size_t
	compareString.clear();

	//Compare empty strings
	utf16StringBuffer = emptyString.c_str();
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, emptyString.size()) == 0);

	utf16StringBuffer = utf16String.c_str();

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, utf16String.size()) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 8) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 10) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 11) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 10) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, utf16String.size()) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 12) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 11) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 8) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 10) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 11) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, utf16String.size()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, utf16String.size()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, 12) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(utf16StringBuffer, utf16String.size()) > 0);


	//Test the compare() function that accepts a wchar_t*
	compareString.clear();

	//Compare empty strings
	const wchar_t* wideStringBuffer = emptyWideString.c_str();
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) == 0);

	wideStringBuffer = wideString.c_str();

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer) > 0);


	//Test the compare() function that accepts a wchar_t* and a size_t
	compareString.clear();

	//Compare empty strings
	wideStringBuffer = emptyWideString.c_str();
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, emptyWideString.size()) == 0);

	wideStringBuffer = wideString.c_str();

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, wideString.size()) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 8) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 10) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 11) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 10) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 10) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 12) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, wideString.size()) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 8) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 10) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 11) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, wideString.size()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, wideString.size()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, 12) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(wideStringBuffer, wideString.size()) > 0);


	//Test the compare() function that accepts a wstring
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyWideString) == 0);

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(wideString) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(wideString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(wideString) > 0);


	//Test the compare() function that accepts a Utf8String
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyUtf8String) == 0);

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(utf8String) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(utf8String) > 0);


	//Test the compare() function that accepts a std::string
	compareString.clear();

	//Compare empty strings
	CPPUNIT_ASSERT(compareString.compare(emptyCharacterString) == 0);

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(characterString) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(characterString) > 0);


	//Test the compare() function that accepts a char*
	compareString.clear();

	//Compare empty strings
	const char* characterStringBuffer = emptyCharacterString.c_str();
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) == 0);

	characterStringBuffer = characterString.c_str();

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer) > 0);



	//Test the compare() function that accepts a char* and a size_t
	compareString.clear();

	//Compare empty strings
	characterStringBuffer = emptyCharacterString.c_str();
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, emptyCharacterString.size()) == 0);

	characterStringBuffer = characterString.c_str();

	//Compare strings that are equal
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) == 0);

	//Compare a string that is less than the parameter string where the first code unit differs
	compareString = L"\xD803\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 8) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD802\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 12) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC38\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 13) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\x1122\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 12) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a two-code-unit code
	//point in the parameter string, where the value of the code unit in the one-code-unit code
	//point is greater than that of the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xEF42\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 12) < 0);

	//Compare a string that is less than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 13) < 0);

	//Compare a string that is less than the parameter string where the compare string is longer
	//that the parameter string
	compareString = L"\xD808\xDC68\x0053\x0E3B\xD803\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x83A2\x0065\x5E32\x01AB";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) < 0);

	//Compare a string that is greater than the parameter string where the first code unit differs
	compareString = L"\xD81E\xDCA1\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 8) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the first code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD8A0\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 12) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are both two-code-unit code points where the second code unit differs
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDDD8\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 13) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\xD808\xDC68\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.length()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a two-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string, with the one-code-unit code unit having a value greater than
	//the surrogate code units
	compareString = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xD808\xDC68\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.length()) > 0);

	//Compare a string that is greater than the parameter string where the first differing pair of
	//code points are a one-code-unit code point in the compare string and a one-code-unit code
	//point in the parameter string
	compareString = L"\xD808\xDC68\x0053\xAE3B\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, 12) > 0);

	//Compare a string that is greater than the parameter string where the compare string is shorter
	//that the parameter string
	compareString = L"\xD808\xDC68\x0B53\x0E3B\xD803\xDC68\x0062\x00F6";
	CPPUNIT_ASSERT(compareString.compare(characterStringBuffer, characterString.size()) > 0);
}

void Utf16StringTest::TestConstIterator()
{
	TestConstIteratorWithStringOne();
	TestConstIteratorWithStringTwo();
	TestConstIteratorWithStringThree();
	TestConstIteratorWithStringFour();
}

void Utf16StringTest::TestConstIteratorReversal()
{
	//Create a constant UTF-16 string composed of one- and two-code-unit characters
	const Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Create an iterator and put it in the middle of the string
	Utf16String::const_iterator stringIterator = utf16String.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\x00DF');

	//Now convert to a reverse iterator
	Utf16String::const_reverse_iterator reverseStringIterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == L'\x00DF');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == L'\xDC68');

	//Move the iterator to a two-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*stringIterator)[1] == L'\xDC68');

	//Now convert to a reverse iterator
	reverseStringIterator = Utf16String::const_reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == L'\xDC68');

	//Now convert back to a normal iterator
	stringIterator = Utf16String::const_iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*stringIterator)[1] == L'\xDC68');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\x0062');
}

void Utf16StringTest::TestConstReverseIterator()
{
	TestConstReverseIteratorWithStringOne();
	TestConstReverseIteratorWithStringTwo();
	TestConstReverseIteratorWithStringThree();
	TestConstReverseIteratorWithStringFour();
}

void Utf16StringTest::TestConstructors()
{
	//Create a Utf16String using the default constructor
	Utf16String* constructedString = new Utf16String();

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

void Utf16StringTest::TestCopy()
{
	//Create a UTF-16 string with one- and two-code-unit code points
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\xD808\xDC68\x0062\x00F6\xFFDF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	UInt16* codeUnitArray = NULL;
	size_t copiedCodeUnits;

	//Copy a string to a 0-length array
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[0];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 0, 10);

	CPPUNIT_ASSERT_EQUAL((size_t)0, copiedCodeUnits);

	//Copy a two-code-unit code point to an array of size 1
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[1];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 1, 1);

	CPPUNIT_ASSERT_EQUAL((size_t)0, copiedCodeUnits);

	//Copy a large section of a string into an array that is too small
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[5];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 5, 7);

	CPPUNIT_ASSERT_EQUAL((size_t)4, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0053', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', codeUnitArray[3]);

	//Copy part of a string using an offset
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[100];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 100, 3, 2);

	CPPUNIT_ASSERT_EQUAL((size_t)4, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', codeUnitArray[3]);

	//Copy part of a string with the number of code points that would be past the end of the string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[100];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 100, 10, 9);

	CPPUNIT_ASSERT_EQUAL((size_t)4, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', codeUnitArray[3]);

	//Copy the last character of a string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[100];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 100, 1, utf16String.length() - 1);

	CPPUNIT_ASSERT_EQUAL((size_t)1, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', codeUnitArray[0]);

	//Copy a middle section of a string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[100];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 100, 5, 3);

	CPPUNIT_ASSERT_EQUAL((size_t)6, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', codeUnitArray[3]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xFFDF', codeUnitArray[4]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', codeUnitArray[5]);

	//Copy an entire string
	if(codeUnitArray != NULL)
	{
		delete codeUnitArray;
		codeUnitArray = NULL;
	}

	codeUnitArray = new UInt16[100];
	copiedCodeUnits = utf16String.copy(codeUnitArray, 100, utf16String.length());

	CPPUNIT_ASSERT_EQUAL((size_t)15, copiedCodeUnits);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', codeUnitArray[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', codeUnitArray[1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0053', codeUnitArray[2]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', codeUnitArray[3]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', codeUnitArray[4]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', codeUnitArray[5]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', codeUnitArray[6]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', codeUnitArray[7]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xFFDF', codeUnitArray[8]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', codeUnitArray[9]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', codeUnitArray[10]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', codeUnitArray[11]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', codeUnitArray[12]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', codeUnitArray[13]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', codeUnitArray[14]);
}

void Utf16StringTest::TestCStr()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	const UInt16* codeUnitString = utf16String.c_str();
	basic_string<UInt16> baseString = utf16String;

	int codeUnitIndex = 0;

	//Iterate through the string, making sure all the code units are the same as the contents
	//of the null-terminated UInt16 code unit string
	for(basic_string<UInt16>::const_iterator stringIterator = baseString.begin(); 
		stringIterator != baseString.end(); ++stringIterator)
	{
		CPPUNIT_ASSERT_EQUAL(*stringIterator, codeUnitString[codeUnitIndex]);

		++codeUnitIndex;
	}

	//Make sure that the code unit string is indeed null-terminated
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0000', codeUnitString[codeUnitIndex]);
}

void Utf16StringTest::TestData()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	const UInt16* codeUnitString = utf16String.data();
	basic_string<UInt16> baseString = utf16String;

	int codeUnitIndex = 0;

	//Iterate through the string, making sure all the code units are the same as the contents
	//of the null-terminated UInt16 code unit string
	for(basic_string<UInt16>::const_iterator stringIterator = baseString.begin(); 
		stringIterator != baseString.end(); ++stringIterator)
	{
		CPPUNIT_ASSERT_EQUAL(*stringIterator, codeUnitString[codeUnitIndex]);

		++codeUnitIndex;
	}
}

void Utf16StringTest::TestDecodeCharacter()
{
	//Test the DecodeCharacter() that accepts a UInt16* and a size_t
	//Decode some one-code-unit characters
	UInt16* characterBuffer = new UInt16[1];

	characterBuffer[0] = L'\x1EAB';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, Utf16String::DecodeCharacter(characterBuffer, 1));

	characterBuffer[0] = L'\x2211';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, Utf16String::DecodeCharacter(characterBuffer, 1));

	characterBuffer[0] = L'\x0062';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000062, Utf16String::DecodeCharacter(characterBuffer, 1));

	//Decode some two-code-unit characters
	if(characterBuffer != NULL)
	{
		delete[] characterBuffer;
		characterBuffer = NULL;
	}

	characterBuffer = new UInt16[2];

	characterBuffer[0] = L'\xD808';
	characterBuffer[1] = L'\xDC68';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, Utf16String::DecodeCharacter(characterBuffer, 2));

	characterBuffer[0] = L'\xD800';
	characterBuffer[1] = L'\xDF46';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, Utf16String::DecodeCharacter(characterBuffer, 2));

	if(characterBuffer != NULL)
	{
		delete[] characterBuffer;
		characterBuffer = NULL;
	}

	//Test the DecodeCharacter() that accepts a Utf16Char
	//Decode some one-code-unit characters
	Utf16Char character;

	character.clear();
	character[0] = L'\x1EAB';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00001EAB, Utf16String::DecodeCharacter(character));

	character.clear();
	character[0] = L'\x2211';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00002211, Utf16String::DecodeCharacter(character));

	character.clear();
	character[0] = L'\x0062';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00000062, Utf16String::DecodeCharacter(character));

	//Decode some two-code-unit characters
	character.clear();
	character[0] = L'\xD808';
	character[1] = L'\xDC68';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00012068, Utf16String::DecodeCharacter(character));

	character.clear();
	character[0] = L'\xD800';
	character[1] = L'\xDF46';
	CPPUNIT_ASSERT_EQUAL((UInt32)0x00010346, Utf16String::DecodeCharacter(character));
}

void Utf16StringTest::TestEmpty()
{
	//Test the default string
	Utf16String utf16String;
	CPPUNIT_ASSERT(utf16String.empty());

	//Test a string with a single one-code-unit character
	utf16String = L"\x1EAB";
	CPPUNIT_ASSERT(!utf16String.empty());

	//Test a string with a single two-code-unit character
	utf16String = L"\xD808\xDC68";
	CPPUNIT_ASSERT(!utf16String.empty());

	//Test a string with a single invalid code unit
	utf16String = L"\xDC68";
	CPPUNIT_ASSERT(!utf16String.empty());

	//Test a string that's set to an empty string
	utf16String = L"";
	CPPUNIT_ASSERT(utf16String.empty());

	//Test a string with a lot of different characters
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	CPPUNIT_ASSERT(!utf16String.empty());
}

void Utf16StringTest::TestEncodeCharacter()
{
	//Encode some one-code-unit characters
	Utf16Char encodedCharacter;

	encodedCharacter = Utf16String::EncodeCharacter((UInt32)0x00001EAB);
	CPPUNIT_ASSERT_EQUAL((size_t)1, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', encodedCharacter[0]);

	encodedCharacter = Utf16String::EncodeCharacter((UInt32)0x00002211);
	CPPUNIT_ASSERT_EQUAL((size_t)1, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', encodedCharacter[0]);

	encodedCharacter = Utf16String::EncodeCharacter((UInt32)0x00000062);
	CPPUNIT_ASSERT_EQUAL((size_t)1, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', encodedCharacter[0]);

	//Encode some two-code-unit characters
	encodedCharacter = Utf16String::EncodeCharacter((UInt32)0x00012068);
	CPPUNIT_ASSERT_EQUAL((size_t)2, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', encodedCharacter[1]);

	encodedCharacter = Utf16String::EncodeCharacter((UInt32)0x00010346);
	CPPUNIT_ASSERT_EQUAL((size_t)2, encodedCharacter.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', encodedCharacter[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', encodedCharacter[1]);
}

void Utf16StringTest::TestEnd()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::iterator stringIterator = utf16String.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*stringIterator)[1]);

	utf16String = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	stringIterator = utf16String.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', (*stringIterator)[0]);

	//Run the test again with a constant string
	const Utf16String constUtf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::const_iterator constStringIterator = constUtf16String.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constStringIterator)[1]);

	const Utf16String constUtf16StringTwo = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	constStringIterator = constUtf16StringTwo.end() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', (*constStringIterator)[0]);
}

void Utf16StringTest::TestErase()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	Utf16String eraseString;
	Utf16String resultString;
	Utf16String::iterator resultIterator = utf16String.begin();

	//Test the erase() function that accepts two iterators
	//Try to remove characters from an empty string
	eraseString.clear();
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)0, eraseString.length());
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Remove characters at the beginning of a string
	eraseString = utf16String;
	resultIterator = eraseString.erase(eraseString.begin(), eraseString.begin() + 5);

	CPPUNIT_ASSERT_EQUAL((size_t)7, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x00DF');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(utf16String.begin() + 5));

	//Remove characters in the middle of a string
	eraseString = utf16String;
	resultIterator = eraseString.erase(eraseString.begin() + 3, eraseString.begin() + 10);

	CPPUNIT_ASSERT_EQUAL((size_t)5, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x0033');
	CPPUNIT_ASSERT(eraseString[1][0] == L'\x1EAB');
	CPPUNIT_ASSERT(eraseString[2][0] == L'\x0062');
	CPPUNIT_ASSERT(eraseString[3][0] == L'\x0434');
	CPPUNIT_ASSERT(eraseString[4][0] == L'\xD808');
	CPPUNIT_ASSERT(eraseString[4][1] == L'\xDC68');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(utf16String.begin() + 10));

	//Remove characters at the end of a string
	eraseString = utf16String;
	resultIterator = eraseString.erase(eraseString.begin() + 8, eraseString.end());

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x0033');
	CPPUNIT_ASSERT(eraseString[7][0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts a single iterator
	//Remove a character from the beginning of the string
	eraseString = utf16String;
	resultIterator = eraseString.erase(eraseString.begin());

	CPPUNIT_ASSERT_EQUAL(utf16String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin());
	CPPUNIT_ASSERT(*resultIterator == *(utf16String.begin() + 1));

	//Remove a one-code-unit character from the middle of the string
	eraseString = utf16String;
	resultIterator = eraseString.erase(eraseString.begin() + 6);

	CPPUNIT_ASSERT_EQUAL(utf16String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[6][0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 6);
	CPPUNIT_ASSERT(*resultIterator == *(utf16String.begin() + 7));

	//Remove a two-code-unit character from the middle of the string
	eraseString = utf16String;
	resultIterator = eraseString.erase(eraseString.begin() + 3);

	CPPUNIT_ASSERT_EQUAL(utf16String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[3][0] == L'\x00F6');
	CPPUNIT_ASSERT(resultIterator == eraseString.begin() + 3);
	CPPUNIT_ASSERT(*resultIterator == *(utf16String.begin() + 4));

	//Remove a character from the end of a string
	eraseString = utf16String;
	resultIterator = eraseString.erase(eraseString.end() - 1);

	CPPUNIT_ASSERT_EQUAL(utf16String.length() - 1, eraseString.length());
	CPPUNIT_ASSERT(eraseString[eraseString.length() - 1][0] == L'\x0434');
	CPPUNIT_ASSERT(resultIterator == eraseString.end());

	//Test the erase() function that accepts two size_t parameters
	//Remove characters at the beginning of a string
	eraseString = utf16String;
	resultString = eraseString.erase(0, 5);

	CPPUNIT_ASSERT_EQUAL((size_t)7, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x00DF');
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters in the middle of a string
	eraseString = utf16String;
	resultString = eraseString.erase(3, 7);

	CPPUNIT_ASSERT_EQUAL((size_t)5, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x0033');
	CPPUNIT_ASSERT(eraseString[1][0] == L'\x1EAB');
	CPPUNIT_ASSERT(eraseString[2][0] == L'\x0062');
	CPPUNIT_ASSERT(eraseString[3][0] == L'\x0434');
	CPPUNIT_ASSERT(eraseString[4][0] == L'\xD808');
	CPPUNIT_ASSERT(eraseString[4][1] == L'\xDC68');
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string
	eraseString = utf16String;
	resultString = eraseString.erase(8, 4);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x0033');
	CPPUNIT_ASSERT(eraseString[7][0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultString == eraseString);

	//Remove characters at the end of a string where the count parameter causes the range to
	//go beyond the end of the string
	eraseString = utf16String;
	resultString = eraseString.erase(8, 12);

	CPPUNIT_ASSERT_EQUAL((size_t)8, eraseString.length());
	CPPUNIT_ASSERT(eraseString[0][0] == L'\x0033');
	CPPUNIT_ASSERT(eraseString[7][0] == L'\x1EAB');
	CPPUNIT_ASSERT(resultString == eraseString);
}

void Utf16StringTest::TestFind()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	size_t foundIndex;

	//Find a single character at the beginning of the string
	foundIndex = utf16String.find(L"\x0033");

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = utf16String.find(L"\x2211");

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = utf16String.find(L"\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = utf16String.find(L"\x0033\x1EAB\x0062");

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = utf16String.find(L"\x1EAB\x2211\xD800\xDF46\x0434");

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = utf16String.find(L"\xD800\xDF46\x0434\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = utf16String.find(L"\xA483");

	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = utf16String.find(L"\x0434\xD800\xDF46\x0062");

	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf16String.find(L"\xD808\xDC68", 5);

	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);
}

void Utf16StringTest::TestFindFirstNotOf()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	Utf16String shortString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = shortString.find_first_not_of(L"\x0062\x1EAB");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = L"\xD808\xDC68";

	//Find the first code point that doesn't contain the second code unit of a surrogate pair
	foundIndex = shortString.find_first_not_of(L"\xDC68");

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find the first code point that doesn't contain the first code unit of a surrogate pair
	foundIndex = shortString.find_first_not_of(L"\xD808");

	//This should fail and we should be given the first code point because it contains a code unit
	//that is not in the search string.
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Now call find_first_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_first_not_of(L"\xD808\xDC68");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Now call find_first_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = utf16String.find_first_not_of(utf16String);
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Now call find_first_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = utf16String.find_first_not_of(L"\x0033\x1EAB\x0062");
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = utf16String.find_first_not_of(L"\xD808\xDC68\x0033\x0062\x1EAB");
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	//Call find_first_not_of() containing some code points not found in the string
	foundIndex = utf16String.find_first_not_of(L"\xD809\xDC22\x0054\x236B");
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Call find_first_not_of() using an offset
	foundIndex = utf16String.find_first_not_of(L"\x0033", 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, foundIndex);

	foundIndex = utf16String.find_first_not_of(L"\x00DF\x0033", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);
}

void Utf16StringTest::TestFindFirstOf()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	Utf16String emptyString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = emptyString.find_first_of(L"\x0033");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = utf16String.find_first_of(L"\x0033");
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	foundIndex = utf16String.find_first_of(L"\xD800\xDF46\x0434\xD808\xDC68");
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = utf16String.find_first_of(L"\x00DF\xD808\xDC68\x1EAB");
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	foundIndex = utf16String.find_first_of(L"\x2211\x0043\x0434");
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = utf16String.find_first_of(L"\x0043\xD8A0\xDCD2\x8E4C");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf16String.find_first_of(L"\xD808\xDC68\x1EAB", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	foundIndex = utf16String.find_first_of(L"\xD808\xDC68\xE320", 4);
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Attempt to find soemthing past the end of the string
	foundIndex = utf16String.find_first_of(L"\x0033\x1EAB", 14);
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);
}

void Utf16StringTest::TestFindLastNotOf()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	Utf16String shortString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = shortString.find_last_not_of(L"\x0062\x1EAB");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Create a string with just a single two-code-unit code point in it
	shortString = L"\xD808\xDC68";

	//Call find_last_not_of() using the entire code point, and we should come back with an npos result
	foundIndex = shortString.find_last_not_of(L"\xD808\xDC68");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Call find_last_not_of() on a string using the search string that also contains the contents of
	//the string. We should get npos as a result
	foundIndex = utf16String.find_last_not_of(utf16String);
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Call find_last_not_of() where the search string contains several code points found throughout the
	//string being searched
	foundIndex = utf16String.find_last_not_of(L"\x0033\x1EAB\x0062");
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = utf16String.find_last_not_of(L"\xD808\xDC68\x0033\x0062\x1EAB\xD800\xDF46\x0434");
	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Call find_last_not_of() containing some code points not found in the string
	foundIndex = utf16String.find_last_not_of(L"\xD809\xDC22\x0054\x236B");
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Call find_last_not_of() using an offset
	foundIndex = utf16String.find_last_not_of(L"\x0033", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, foundIndex);

	foundIndex = utf16String.find_last_not_of(L"\x0033", 0);
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	foundIndex = utf16String.find_last_not_of(L"\xD808\xDC68", 3);
	CPPUNIT_ASSERT_EQUAL((size_t)2, foundIndex);
}

void Utf16StringTest::TestFindLastOf()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	Utf16String emptyString;

	size_t foundIndex;

	//Attempt to find something in an empty string
	foundIndex = emptyString.find_last_of(L"\x0033");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find some one- and two-code-unit characters in the string
	foundIndex = utf16String.find_last_of(L"\x0033");
	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	foundIndex = utf16String.find_last_of(L"\x0434\xD800\xDF46");
	CPPUNIT_ASSERT_EQUAL((size_t)10, foundIndex);

	foundIndex = utf16String.find_last_of(L"\x00DF\xD808\xDC68\x1EAB");
	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	foundIndex = utf16String.find_last_of(L"\x0062\x1EAB");
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Attempt to find some one- and two-code-unit characters that aren't in the string
	foundIndex = utf16String.find_last_of(L"\x0043\xD8A0\xDCD2\x8E4C");
	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf16String.find_last_of(L"\xD808\xDC68\x1EAB", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

	foundIndex = utf16String.find_last_of(L"\x1EAB\xE320", 5);
	CPPUNIT_ASSERT_EQUAL((size_t)1, foundIndex);

	//Attempt to find something at the beginning of the string
	foundIndex = utf16String.find_last_of(L"\x0033\x1EAB", 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Attempt to find something where the offset goes past the end of the string
	foundIndex = utf16String.find_last_of(L"\x0033\x1EAB", 20);
	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);
}

void Utf16StringTest::TestIndexer()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Get the character at the beginning of the string
	Utf16Char character = utf16String[0];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', character[0]);

	//Get the character at the end of the string
	character = utf16String[utf16String.length() - 1];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);

	//Get a one-code-unit character in the middle of the string
	character = utf16String[5];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', character[0]);

	//Get a two-code-unit character in the middle of the string
	character = utf16String[3];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);

	//Repeat the same tests with a constant string
	const Utf16String constUtf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Get the character at the beginning of the string
	character = constUtf16String[0];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', character[0]);

	//Get the character at the end of the string
	character = constUtf16String[constUtf16String.length() - 1];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);

	//Get a one-code-unit character in the middle of the string
	character = constUtf16String[5];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', character[0]);

	//Get a two-code-unit character in the middle of the string
	character = constUtf16String[3];

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', character[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', character[1]);
}

void Utf16StringTest::TestInsert()
{
	//Test the append functionality with a string composed of only single-code-unit characters
	//Create a standard string class containing a 1-, 2-, and 3-byte UTF-8 characters
	string characterString = "Sẫböß3ẫ∑д";
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	Utf8String utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create a UTF-16 string that will get another string inserted into it
	Utf16String originalString = L"\x2211\x0053\x0062\x00F6";
	//Create the UTF-16 string that results from an insert operation at the beginning of the string
	Utf16String finalBeginString = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434\x2211\x0053\x0062\x00F6";
	//Create the UTF-16 string that results from an insert operation in the middle of the string
	Utf16String finalMiddleString = L"\x2211\x0053\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434\x0062\x00F6";
	//Create the UTF-16 string that results from an insert operation at the end of the string
	Utf16String finalEndString = L"\x2211\x0053\x0062\x00F6\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	//Create the string on which the insert operations will be conducted
	Utf16String insertedString;

	//Create a wstring version of the UTF-16 string to be inserted
	wstring wideString;

	basic_string<UInt16> codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}


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

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a basic_string<UInt16>
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a UInt16*
	insertedString = originalString;
	insertedString.insert(0, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a UInt16* and a size_t
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a wchar_t*
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a wchar_t* and a size_t
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a wstring
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, wideString);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, wideString);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(4, wideString);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, wideString);

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


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

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a string
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
	insertedString.insert(4, characterString);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString);

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


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
	insertedString.insert(4, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


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
	insertedString.insert(4, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Now test the insert functionality with UTF-16 string containing characters with two code units
	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	characterString = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "\xF0\x92\x81\xA8Sẫböß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UTF-16 string that will be appended to
	originalString = L"\x1EAB\x2211\xD800\xDF46";
	//Create the UTF-16 string that results from an insert operation at the beginning of the string
	finalBeginString = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\x1EAB\x2211\xD800\xDF46";
	//Create the UTF-16 string that results from an insert operation in the middle of the string
	finalMiddleString = L"\x1EAB\x2211\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD800\xDF46";
	//Create the UTF-16 string that results from an insert operation at the end of the string
	finalEndString = L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";


	//Create a wstring version of the UTF-16 string to be appended
	wideString.clear();
	codeUnitString = utf16String;

	for(basic_string<UInt16>::const_iterator stringIterator = codeUnitString.begin(); 
		stringIterator != codeUnitString.end(); ++stringIterator)
	{
		wchar_t wideCharacter = (wchar_t)(*stringIterator);
		wideString.append(&wideCharacter, 1);
	}

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

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a basic_string<UInt16>
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, (basic_string<UInt16>)utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a UInt16*
	insertedString = originalString;
	insertedString.insert(0, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a UInt16* and a size_t
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String.c_str(), utf16String.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a wchar_t*
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, wideString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a wchar_t* and a size_t
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, wideString.c_str(), wideString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a wstring
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, wideString);

	CPPUNIT_ASSERT_EQUAL(finalBeginString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, wideString);

	CPPUNIT_ASSERT_EQUAL(finalMiddleString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, wideString);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, wideString);

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


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

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


	//Test the insert() function that accepts a string
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
	insertedString.insert(3, characterString);

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString);

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


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
	insertedString.insert(3, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString.c_str());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);


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
	insertedString.insert(3, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(finalEndString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, characterString.c_str(), characterString.size());

	CPPUNIT_ASSERT_EQUAL(utf16String, insertedString);

	//Test the insert() function that accepts a Utf16Char

	//Create a UTF-16 string that will be the result when inserting a one-code-unit character
	//at the beginning
	Utf16String oneCodeUnitBeginFinalString = L"\x0053\x1EAB\x2211\xD800\xDF46";
	//Create a UTF-16 string that will be the result when inserting a one-code-unit character
	//in the middle
	Utf16String oneCodeUnitMiddleFinalString = L"\x1EAB\x2211\x0053\xD800\xDF46";
	//Create a UTF-16 string that will be the result when inserting a one-code-unit character
	//at the end
	Utf16String oneCodeUnitEndFinalString = L"\x1EAB\x2211\xD800\xDF46\x0053";
	//Create a UTF-16 string that will be the result inserting a two-code-unit character
	//at the beginning
	Utf16String twoCodeUnitBeginFinalString = L"\xD808\xDC68\x1EAB\x2211\xD800\xDF46";
	//Create a UTF-16 string that will be the result inserting a two-code-unit character
	//at the beginning
	Utf16String twoCodeUnitMiddleFinalString = L"\x1EAB\x2211\xD808\xDC68\xD800\xDF46";
	//Create a UTF-16 string that will be the result inserting a two-code-unit character
	//at the beginning
	Utf16String twoCodeUnitEndFinalString = L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68";

	//Insert a one-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(utf16String.substr(1, 1), insertedString);


	//Insert a two-code-unit character
	//Insert the string at the beginning
	insertedString = originalString;
	insertedString.insert(0, utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitBeginFinalString, insertedString);

	//Insert the string in the middle
	insertedString = originalString;
	insertedString.insert(2, utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitMiddleFinalString, insertedString);

	//Insert the string at the end
	insertedString = originalString;
	insertedString.insert(3, utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitEndFinalString, insertedString);

	//Insert the string into an empty string
	insertedString.clear();
	insertedString.insert(0, utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(utf16String.substr(0, 1), insertedString);
}

void Utf16StringTest::TestIsValid()
{
	//Test a valid UTF-16 string
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	CPPUNIT_ASSERT(utf16String.is_valid());

	//Test an empty string
	utf16String.clear();
	CPPUNIT_ASSERT(utf16String.is_valid());

	//Test a string where a surrogate pair is missing the second code unit
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\x0434\xD808\xDC68";
	CPPUNIT_ASSERT(!utf16String.is_valid());

	//Test a string where a surrogate pair at the end of the string is missing the second code unit
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\x0434\xD808";
	CPPUNIT_ASSERT(!utf16String.is_valid());

	//Test a string where a surrogate pair is missing the first code unit
	utf16String = L"\x0033\x1EAB\x0062\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	CPPUNIT_ASSERT(!utf16String.is_valid());

	//Test a string where a surrogate pair at the end of the string is missing the first code unit
	utf16String = L"\x0033\x1EAB\x0062\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xDC68";
	CPPUNIT_ASSERT(!utf16String.is_valid());

	//Test a string containing the BOM code point 0xFFFE
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\xFFFE\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	CPPUNIT_ASSERT(!utf16String.is_valid());

	//Test a string containing the BOM code point 0xFFFF
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68\xFFFF";
	CPPUNIT_ASSERT(!utf16String.is_valid());

	//Test a string containing some of the one-code-unit code points that are non-characters(0xFDD0 - 0xFDEF)
	utf16String = L"\x0033\x1EAB\xFDE2\xD808\xDC68\x00DF\x0033\x1EAB\xFDD8\xD800\xDF46\x0434\xD808\xDC68";
	CPPUNIT_ASSERT(!utf16String.is_valid());

	//Test a string containing some of the two-code-unit code points that are non-characters(0xFDD0 - 0xFDEF)
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDFFE\x00DF\x0033\x1EAB\x2211\xD800\xDFFF\x0434\xD808\xDC68";
	CPPUNIT_ASSERT(!utf16String.is_valid());
}

void Utf16StringTest::TestIsValidCharacter()
{
	//Test the IsValidCharacter() that accepts a Utf16Char
	Utf16Char character;

	//Validate an empty character
	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Validate valid one-code-unit characters
	character[0] = L'\x0033';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(character));

	character[0] = L'\x1EAB';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(character));

	//Validate invalid one-code-unit characters
	//Test the character on the lower boundary of the invalid range
	character[0] = L'\xD800';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a character in the middle of the invalid range
	character[0] = L'\xDA92';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a character at the end of the invalid range
	character[0] = L'\xDFFF';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Validate one-code-unit characters on the other side of the invalid range
	//Test a boundary character
	character[0] = L'\xE000';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(character));

	//Test a character in the middle of the second valid range
	character[0] = L'\xEFFF';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(character));

	//Test some valid two-code-unit characters
	character[0] = L'\xD808';
	character[1] = L'\xDC68';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(character));

	character[0] = L'\xD800';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(character));

	//Test some invalid two-code-unit characters, where the first code unit is outside the range D800-DBFF
	//Test a character with the first code unit way outside the valid range
	character[0] = L'\x0045';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a character with the first code unit just below the valid range
	character[0] = L'\xD7FF';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a character with the first code unit just above the valid range
	character[0] = L'\xDC00';
	character[1] = L'\xDF46';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test some invalid two-code-unit characters, where the second code unit is outside the range DC00-DFFF
	//Test a character with the second code unit way outside the valid range
	character[0] = L'\xD809';
	character[1] = L'\x0045';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a character with the second code unit just below the valid range
	character[0] = L'\xD809';
	character[1] = L'\xDB99';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a character with the second code unit just above the valid range
	character[0] = L'\xD809';
	character[1] = L'\xE000';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a two-code-unit character with both code units outside the allowed ranges
	character[0] = L'\x1ABC';
	character[1] = L'\xF42A';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test a character that is one of the 32 non-character code points
	character[0] = L'\xD97F';
	character[1] = L'\xDFFE';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(character));

	//Test the IsValidCharacter() that accepts a UInt16* and a size_t
	UInt16 characterBuffer[2];

	//Validate an empty character
	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 0));

	//Validate valid one-code-unit characters
	characterBuffer[0] = L'\x0033';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(characterBuffer, 1));

	characterBuffer[0] = L'\x1EAB';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(characterBuffer, 1));

	//Validate invalid one-code-unit characters
	//Test the character on the lower boundary of the invalid range
	characterBuffer[0] = L'\xD800';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 1));

	//Test a character in the middle of the invalid range
	characterBuffer[0] = L'\xDA92';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 1));

	//Test a character at the end of the invalid range
	characterBuffer[0] = L'\xDFFF';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 1));

	//Validate one-code-unit characters on the other side of the invalid range
	//Test a boundary character
	characterBuffer[0] = L'\xE000';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(characterBuffer, 1));

	//Test a character in the middle of the second valid range
	characterBuffer[0] = L'\xEFFF';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(characterBuffer, 1));

	//Test some valid two-code-unit characters
	characterBuffer[0] = L'\xD808';
	characterBuffer[1] = L'\xDC68';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(characterBuffer, 2));

	characterBuffer[0] = L'\xD800';
	characterBuffer[1] = L'\xDF46';

	CPPUNIT_ASSERT(Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test some invalid two-code-unit characters, where the first code unit is outside the range D800-DBFF
	//Test a character with the first code unit way outside the valid range
	characterBuffer[0] = L'\x0045';
	characterBuffer[1] = L'\xDF46';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test a character with the first code unit just below the valid range
	characterBuffer[0] = L'\xD7FF';
	characterBuffer[1] = L'\xDF46';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test a character with the first code unit just above the valid range
	characterBuffer[0] = L'\xDC00';
	characterBuffer[1] = L'\xDF46';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test some invalid two-code-unit characters, where the second code unit is outside the range DC00-DFFF
	//Test a character with the second code unit way outside the valid range
	characterBuffer[0] = L'\xD809';
	characterBuffer[1] = L'\x0045';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test a character with the second code unit just below the valid range
	characterBuffer[0] = L'\xD809';
	characterBuffer[1] = L'\xDB99';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test a character with the second code unit just above the valid range
	characterBuffer[0] = L'\xD809';
	characterBuffer[1] = L'\xE000';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test a two-code-unit character with both code units outside the allowed ranges
	characterBuffer[0] = L'\x1ABC';
	characterBuffer[1] = L'\xF42A';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));

	//Test a character that is one of the 32 non-character code points
	characterBuffer[0] = L'\xD97F';
	characterBuffer[1] = L'\xDFFE';

	CPPUNIT_ASSERT(!Utf16String::IsValidCharacter(characterBuffer, 2));
}

void Utf16StringTest::TestIsWhitespace()
{
	//Test characters in Unicode considered to be whitespace characters
	UInt16 whitespaceCharacter;

	//Test the function that accepts a UInt16
	whitespaceCharacter = L'\x0020';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x0009';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x000D';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x000A';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x00A0';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x1680';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x180E';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x2000';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x2006';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x2009';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x200A';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x202F';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x205F';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x3000';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x2028';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x2029';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(whitespaceCharacter));

	//Test characters that shouldn't be considered whitespace
	whitespaceCharacter = L'\x0000';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x0068';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\x1EAB';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(whitespaceCharacter));

	whitespaceCharacter = L'\xD809';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(whitespaceCharacter));


	//Test the function that accepts a Utf16Char
	Utf16Char utf16Character;

	utf16Character = L'\x0020';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x0009';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x000D';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x000A';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x00A0';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x1680';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x180E';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x2000';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x2006';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x2009';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x200A';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x202F';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x205F';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x3000';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x2028';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x2029';
	CPPUNIT_ASSERT(Utf16String::IsWhitespace(utf16Character));

	//Test characters that shouldn't be considered whitespace
	utf16Character = L'\x0000';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x0068';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\x1EAB';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(utf16Character));

	utf16Character = L'\xD809';
	CPPUNIT_ASSERT(!Utf16String::IsWhitespace(utf16Character));
}

void Utf16StringTest::TestIterator()
{
	TestIteratorWithStringOne();
	TestIteratorWithStringTwo();
	TestIteratorWithStringThree();
	TestIteratorWithStringFour();
}

void Utf16StringTest::TestIteratorReversal()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Create an iterator and put it in the middle of the string
	Utf16String::iterator stringIterator = utf16String.begin() + 5;

	//Made sure we're at the correct position
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\x00DF');

	//Now convert to a reverse iterator
	Utf16String::reverse_iterator reverseStringIterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == L'\x00DF');

	//Increment the reverse iterator
	reverseStringIterator += 2;

	//Verify that it is actually going in reverse order
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == L'\xDC68');

	//Move the iterator to a two-code-unit code point
	stringIterator -= 2;
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*stringIterator)[1] == L'\xDC68');

	//Now convert to a reverse iterator
	reverseStringIterator = Utf16String::reverse_iterator(stringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*reverseStringIterator).size());
	CPPUNIT_ASSERT((*reverseStringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*reverseStringIterator)[1] == L'\xDC68');

	//Now convert back to a normal iterator
	stringIterator = Utf16String::iterator(reverseStringIterator);

	//Make sure that we're still at the same position
	CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\xD808');
	CPPUNIT_ASSERT((*stringIterator)[1] == L'\xDC68');

	//Verify that we can move in the normal order again
	--stringIterator;
	CPPUNIT_ASSERT((*stringIterator)[0] == L'\x0062');
}

void Utf16StringTest::TestLength()
{
	//Get the length of the default string
	Utf16String utf16String;

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf16String.length());

	//Get the length of a 0-length string
	utf16String = L"";

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf16String.length());

	//Get the length of a single character (one code unit) string
	utf16String = L"\x2211";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf16String.length());

	//Get the length of a single character (two code units) string
	utf16String = L"\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf16String.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	CPPUNIT_ASSERT_EQUAL((size_t)9, utf16String.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)12, utf16String.length());

	//Now run the tests again with constant string
	//Get the length of the default string
	const Utf16String constUtf16String1;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16String1.length());

	//Get the length of a 0-length string
	const Utf16String constUtf16String2 = L"";

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16String2.length());

	//Get the length of a single character (one code unit) string
	const Utf16String constUtf16String3 = L"\x2211";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf16String3.length());

	//Get the length of a single character (two code units) string
	const Utf16String constUtf16String4 = L"\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf16String4.length());

	//Get the length of a multi-character string containing only one-code-unit characters
	const Utf16String constUtf16String5 = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	CPPUNIT_ASSERT_EQUAL((size_t)9, constUtf16String5.length());

	//Get the length of a multi-character string containing both one- and two-code-unit characters
	const Utf16String constUtf16String6 = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)12, constUtf16String6.length());
}

void Utf16StringTest::TestPushBack()
{
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Create a UTF-16 string that will be appended to
	Utf16String originalString = L"\x1EAB\x2211\xD800\xDF46";
	//Create a UTF-16 string that will be the result appending a one-code-unit character
	Utf16String oneCodeUnitFinalString = L"\x1EAB\x2211\xD800\xDF46\x0053";
	//Create a UTF-16 string that will be the result appending a two-code-unit character
	Utf16String twoCodeUnitFinalString = L"\x1EAB\x2211\xD800\xDF46\xD808\xDC68";
	//Create a string upon which the push_back() function will be called
	Utf16String appendedString;

	//Append a one-code-unit character
	appendedString = originalString;
	appendedString.push_back(utf16String[1]);

	CPPUNIT_ASSERT_EQUAL(oneCodeUnitFinalString, appendedString);

	//Append a two-code-unit character
	appendedString = originalString;
	appendedString.push_back(utf16String[0]);

	CPPUNIT_ASSERT_EQUAL(twoCodeUnitFinalString, appendedString);
}

void Utf16StringTest::TestRbegin()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::reverse_iterator stringIterator = utf16String.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*stringIterator)[1]);

	utf16String = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	stringIterator = utf16String.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', (*stringIterator)[0]);

	//Run the test again with a constant string
	const Utf16String constUtf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::const_reverse_iterator constStringIterator = constUtf16String.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constStringIterator)[1]);

	const Utf16String constUtf16StringTwo = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	constStringIterator = constUtf16StringTwo.rbegin();

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', (*constStringIterator)[0]);
}

void Utf16StringTest::TestRend()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::reverse_iterator stringIterator = utf16String.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', (*stringIterator)[0]);

	utf16String = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	stringIterator = utf16String.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*stringIterator)[1]);

	//Run the test again with a constant string
	const Utf16String constUtf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	Utf16String::const_reverse_iterator constStringIterator = constUtf16String.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', (*constStringIterator)[0]);

	Utf16String constUtf16StringTwo = L"\xD808\xDC68\x00F6\x00DF\x0033\x1EAB";

	constStringIterator = constUtf16StringTwo.rend() - 1;

	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', (*constStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', (*constStringIterator)[1]);
}

void Utf16StringTest::TestReplace()
{
	//Create a UTF-16 string, parts of which will be used to replace parts of other strings
	Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a UTF-16 string that will be the string before replacement
	Utf16String originalString = L"\x1EAB\x2211\xD800\xDF46";
	//Create a string on which the replace() function is to be called
	Utf16String replaceString;

	//Create the string that results from a replace at the beginning of the string
	Utf16String finalBeginReplaceString = L"\xD808\xDC68\x0053\x1EAB\x2211\xD800\xDF46";
	//Create the string that results from a replace in the middle of the string
	Utf16String finalMiddleReplaceString = L"\x1EAB\xD808\xDC68\x0053\x1EAB\xD800\xDF46";
	//Create the string that results from a replace at the end of the string
	Utf16String finalEndReplaceString = L"\x1EAB\x2211\x2211\xD800\xDF46\x0434";
	//Create the string that results from a replace where the replacement string is actually appended
	Utf16String finalAppendReplaceString = L"\x1EAB\x2211\xD800\xDF46\x2211\xD800\xDF46\x0434";
	//Create the string that results when the section begin iterator is at the same position as the
	//section end iterator
	Utf16String finalSamePositionReplaceString = L"\x1EAB\x2211\xD800\xDF46\x0434\x2211\xD800\xDF46";
	//Create the string that results when the section begin iterator is pointing to a position
	//past that of the section end iterator
	Utf16String finalEarlierPositionReplaceString = L"\x1EAB\x2211\xD800\xDF46\x0434";
	//Create a character to be used as a replacement character
	Utf16Char replacementCharacter = L'X';
	//Create a string to use in storing the final result of a single character replacement
	Utf16String singleCharacterReplaceString;

	//Test the replace() function that accepts size_t, size_t, Utf16String
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(0, 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(1, 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalMiddleReplaceString, replaceString);

	//Replace the end of a string
	replaceString = originalString;
	replaceString.replace(2, 1, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEndReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(3, 1, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalAppendReplaceString, replaceString);

	//Test the replace() function that accepts size_t, size_t, size_t, Utf16Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(0, 10, 5, replacementCharacter);

	singleCharacterReplaceString = L"XXXXX";
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(0, 1, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(1, 1, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(1, 1).insert(1, L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(2, 10, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).append(L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(3, 4, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Test the replace() function that accepts Utf16String::iterator, Utf16String::iterator, Utf16String
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), utf16String);

	CPPUNIT_ASSERT_EQUAL(utf16String, replaceString);

	//Replace the beginning of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, utf16String.substr(0, 3));

	CPPUNIT_ASSERT_EQUAL(finalBeginReplaceString, replaceString);

	//Replace the middle of a string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 1, replaceString.begin() + 2, utf16String.substr(0, 3));

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
	replaceString.replace(replaceString.begin() + 1, replaceString.begin() + 1, utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalSamePositionReplaceString, replaceString);

	//Call replace() where the end iterator is before the begin iterator
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 1, replaceString.begin(), utf16String.substr(8));

	CPPUNIT_ASSERT_EQUAL(finalEarlierPositionReplaceString, replaceString);


	//Test the replace() function that accepts Utf16String::iterator, Utf16String::iterator, size_t, Utf16Char
	//Call replace() on an empty string
	replaceString.clear();
	replaceString.replace(replaceString.begin(), replaceString.end(), 5, replacementCharacter);

	singleCharacterReplaceString = L"XXXXX";
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the beginning of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin(), replaceString.begin() + 1, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr(1).insert(0, L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the middle of the string
	replaceString = originalString;
	replaceString.replace(replaceString.begin() + 1, replaceString.begin() + 2, 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(1, 1).insert(1, L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Replace the end of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end() - 1, replaceString.end(), 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().erase(2, 1).append(L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);

	//Call replace() where the replace position is the same as the length of the string
	replaceString = originalString;
	replaceString.replace(replaceString.end(), replaceString.end(), 5, replacementCharacter);

	singleCharacterReplaceString = originalString.substr().append(L"XXXXX");
	CPPUNIT_ASSERT_EQUAL(singleCharacterReplaceString, replaceString);
}

void Utf16StringTest::TestReverseIterator()
{
	TestReverseIteratorWithStringOne();
	TestReverseIteratorWithStringTwo();
	TestReverseIteratorWithStringThree();
	TestReverseIteratorWithStringFour();
}

void Utf16StringTest::TestRFind()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters to be searched
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	size_t foundIndex;

	//Find a single character at the beginning of the string
	foundIndex = utf16String.rfind(L"\x0033");

	CPPUNIT_ASSERT_EQUAL((size_t)6, foundIndex);

	//Find a single-code-unit character in the middle of the string
	foundIndex = utf16String.rfind(L"\x2211");

	CPPUNIT_ASSERT_EQUAL((size_t)8, foundIndex);

	//Find a two-code-unit character in the middle of the string
	foundIndex = utf16String.rfind(L"\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)11, foundIndex);

	//Find multiple characters at the beginning of the string
	foundIndex = utf16String.rfind(L"\x0033\x1EAB\x0062");

	CPPUNIT_ASSERT_EQUAL((size_t)0, foundIndex);

	//Find multiple characters in the middle of the string
	foundIndex = utf16String.rfind(L"\x1EAB\x2211\xD800\xDF46\x0434");

	CPPUNIT_ASSERT_EQUAL((size_t)7, foundIndex);

	//Find multiple characters at the end of the string
	foundIndex = utf16String.rfind(L"\xD800\xDF46\x0434\xD808\xDC68");

	CPPUNIT_ASSERT_EQUAL((size_t)9, foundIndex);

	//Try to find a single character that isn't there
	foundIndex = utf16String.rfind(L"\xA483");

	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Try to find multiple characters that aren't there
	foundIndex = utf16String.rfind(L"\x0434\xD800\xDF46\x0062");

	CPPUNIT_ASSERT_EQUAL(Utf16String::npos, foundIndex);

	//Find a character using an offset
	foundIndex = utf16String.rfind(L"\xD808\xDC68", 9);

	CPPUNIT_ASSERT_EQUAL((size_t)3, foundIndex);

}

void Utf16StringTest::TestSize()
{
	//Get the size of the default string
	Utf16String utf16String;

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf16String.size());

	//Get the size of a 0-length string
	utf16String = L"";

	CPPUNIT_ASSERT_EQUAL((size_t)0, utf16String.size());

	//Get the size of a single character (one code unit) string
	utf16String = L"\x2211";

	CPPUNIT_ASSERT_EQUAL((size_t)1, utf16String.size());

	//Get the size of a single character (two code units) string
	utf16String = L"\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)2, utf16String.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	CPPUNIT_ASSERT_EQUAL((size_t)9, utf16String.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)15, utf16String.size());

	//Now run the tests again with constant string
	//Get the size of the default string
	const Utf16String constUtf16String1;

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16String1.size());

	//Get the size of a 0-length string
	const Utf16String constUtf16String2 = L"";

	CPPUNIT_ASSERT_EQUAL((size_t)0, constUtf16String2.size());

	//Get the size of a single character (one code unit) string
	const Utf16String constUtf16String3 = L"\x2211";

	CPPUNIT_ASSERT_EQUAL((size_t)1, constUtf16String3.size());

	//Get the size of a single character (two code units) string
	const Utf16String constUtf16String4 = L"\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)2, constUtf16String4.size());

	//Get the size of a multi-character string containing only one-code-unit characters
	const Utf16String constUtf16String5 = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	CPPUNIT_ASSERT_EQUAL((size_t)9, constUtf16String5.size());

	//Get the size of a multi-character string containing both one- and two-code-unit characters
	const Utf16String constUtf16String6 = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	CPPUNIT_ASSERT_EQUAL((size_t)15, constUtf16String6.size());
}

void Utf16StringTest::TestStreamOperators()
{
	stringstream stringStream;

	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB \x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB \x2211\xD800\xDF46\x0434\xD808\xDC68";
	Utf16String deserializedString;

	//Write the string to a stream
	stringStream << utf16String;

	//Reset the stream position to the beginning
	stringStream.seekg(0, ios::beg);

	//Now read in a string from the stream.  Every time the >> operator is called, we should retrieve
	//the parts of the string up until a space, with the space character not included
	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', deserializedString[1][0]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)7, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', deserializedString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', deserializedString[1][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', deserializedString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', deserializedString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', deserializedString[4][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', deserializedString[5][0]);

	stringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', deserializedString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', deserializedString[1][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', deserializedString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', deserializedString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', deserializedString[3][1]);

	//Now repeat the tests for the wide stream operators
	wstringstream wideStringStream;

	//Write the string to a stream
	wideStringStream << utf16String;

	//Reset the stream position to the beginning
	wideStringStream.seekg(0, ios::beg);

	//Now read in a string from the stream.  Every time the >> operator is called, we should retrieve
	//the parts of the string up until a space, with the space character not included
	wideStringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)2, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', deserializedString[1][0]);

	wideStringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)7, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', deserializedString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', deserializedString[1][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', deserializedString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', deserializedString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', deserializedString[4][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', deserializedString[5][0]);

	wideStringStream >> deserializedString;

	CPPUNIT_ASSERT_EQUAL((size_t)4, deserializedString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)6, deserializedString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', deserializedString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', deserializedString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', deserializedString[1][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', deserializedString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', deserializedString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', deserializedString[3][1]);
}

void Utf16StringTest::TestSubstr()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";

	//Get a substring starting at index 0 of only one-code-unit characters
	Utf16String subString = utf16String.substr(0, 3);

	CPPUNIT_ASSERT_EQUAL((size_t)3, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)3, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', subString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', subString[2][0]);

	//Get a substring starting at index 0 of one- and two-code-unit characters
	subString = utf16String.substr(0, 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)6, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', subString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0062', subString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', subString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', subString[3][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00F6', subString[4][0]);

	//Get a substring from the middle of the string composing of only one-code-unit characters
	subString = utf16String.substr(5, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x00DF', subString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', subString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', subString[3][0]);

	//Get a substring from the middle of the string composing of one- and two-code-unit characters
	subString = utf16String.substr(7, 4);
	CPPUNIT_ASSERT_EQUAL((size_t)4, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', subString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', subString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', subString[2][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', subString[3][0]);

	//Get a substring that ends on the last character of the string
	subString = utf16String.substr(7, 5);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)7, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', subString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', subString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', subString[2][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', subString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', subString[4][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', subString[4][1]);

	//Get a substring where the count extends past the end of the string
	subString = utf16String.substr(7, 10);
	CPPUNIT_ASSERT_EQUAL((size_t)5, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)7, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', subString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', subString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', subString[2][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', subString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', subString[4][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', subString[4][1]);

	//Get a substring of length 0
	subString = utf16String.substr(7, 0);
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)0, subString.size());
	
	//Get a substring of length 1
	subString = utf16String.substr(7, 1);
	CPPUNIT_ASSERT_EQUAL((size_t)1, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)1, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[0][0]);

	//Get a substring using only the first parameter
	subString = utf16String.substr(6);
	CPPUNIT_ASSERT_EQUAL((size_t)6, subString.length());
	CPPUNIT_ASSERT_EQUAL((size_t)8, subString.size());
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0033', subString[0][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x1EAB', subString[1][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x2211', subString[2][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD800', subString[3][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDF46', subString[3][1]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\x0434', subString[4][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xD808', subString[5][0]);
	CPPUNIT_ASSERT_EQUAL((UInt16)L'\xDC68', subString[5][1]);

	//Get a substring using no parameters
	subString = utf16String.substr();

	CPPUNIT_ASSERT(utf16String == subString);
}

void Utf16StringTest::TestSwap()
{
	//Create a UTF-16 string composed of one- and two-code-unit characters
	Utf16String utf16String = L"\x0033\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434\xD808\xDC68";
	Utf16String secondString = L"\xD8A0\xDC79\x803C\x0085";
	Utf16String emptyString;

	Utf16String firstSwapString;
	Utf16String secondSwapString;

	//Swap two strings
	firstSwapString = utf16String;
	secondSwapString = secondString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(secondString, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(utf16String, secondSwapString);

	//Swap the two string back
	secondSwapString.swap(firstSwapString);

	CPPUNIT_ASSERT_EQUAL(utf16String, firstSwapString);
	CPPUNIT_ASSERT_EQUAL(secondString, secondSwapString);

	//Swap a populated string with an empty string
	firstSwapString = utf16String;
	secondSwapString = emptyString;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, emptyString);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, utf16String);

	//Swap an empty string with a populated string
	firstSwapString = emptyString;
	secondSwapString = utf16String;

	firstSwapString.swap(secondSwapString);

	CPPUNIT_ASSERT_EQUAL(firstSwapString, utf16String);
	CPPUNIT_ASSERT_EQUAL(secondSwapString, emptyString);
}

/*Private Helper Functions*/

void Utf16StringTest::TestConstructorsWithStrings(const std::string& characterString,
	const UtfString::Utf8String& utf8String, const UtfString::Utf16String& utf16String)
{

	//Create a Utf16String using the constructor that accepts another Utf16String
	Utf16String* constructedString = new Utf16String(utf16String);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a basic_string<UInt16>
	constructedString = new Utf16String((basic_string<UInt16>)utf16String);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a UInt16*
	constructedString = new Utf16String(utf16String.c_str());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a UInt16* and a size_t
	constructedString = new Utf16String(utf16String.c_str() + 1, utf16String.size() - 2);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT((basic_string<UInt16>)*constructedString == ((basic_string<UInt16>)utf16String).substr(1, utf16String.size() - 2));

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

	constructedString = new Utf16String(wideString.c_str());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a wchar_t* and a size_t
	constructedString = new Utf16String(wideString.c_str() + 1, wideString.size() - 2);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT((basic_string<UInt16>)*constructedString == ((basic_string<UInt16>)utf16String).substr(1, wideString.size() - 2));

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a wstring
	constructedString = new Utf16String(wideString);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a Utf8String
	constructedString = new Utf16String(utf8String);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a string
	constructedString = new Utf16String(characterString);

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a char*
	constructedString = new Utf16String(characterString.c_str());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;

	//Create a Utf16String using the constructor that accepts a char* and a size_t
	constructedString = new Utf16String(characterString.c_str(), characterString.size());

	//Verify that the string was constructed correctly
	CPPUNIT_ASSERT_EQUAL(utf16String, *constructedString);

	delete constructedString;
	constructedString = NULL;
}

void Utf16StringTest::TestConstIteratorWithStringOne()
{
	//Create a UTF-16 string containing only ASCII characters
	const Utf16String utf16String = L"Simple String";
	
	//Get an iterator to the beginning of the string
	Utf16String::const_iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "p"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "g"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::const_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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

void Utf16StringTest::TestConstIteratorWithStringTwo()
{
	//Create a UTF-16 string containing characters that correspond to 1- or 2-code-unit characters in UTF-8
	const Utf16String utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";

	//Get an iterator to the beginning of the string
	Utf16String::const_iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "\x06BD"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a "\x044A"
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::const_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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

void Utf16StringTest::TestConstIteratorWithStringThree()
{
	//Create a UTF-16 string containing characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	const Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::const_iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The third character should be a "\x0062"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\x2211"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::const_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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

void Utf16StringTest::TestConstIteratorWithStringFour()
{
	//Create a UTF-16 string containing 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	const Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::const_iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == (*stringIterator).size() || (size_t)2 == (*stringIterator).size());

		//The fourth character should be a "\xD808\xDC68"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 2);
		}

		//The sixth character should be a "\x00DF"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The tenth character should be a "\xD800\xDF46"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), (*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::const_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);

	stringIterator -= 8;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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


void Utf16StringTest::TestConstReverseIteratorWithStringOne()
{
	//Create a UTF-16 string containing only ASCII characters
	const Utf16String utf16String = L"Simple String";
	
	//Get an reverse iterator to the end of the string
	Utf16String::const_reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "r"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::const_reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

void Utf16StringTest::TestConstReverseIteratorWithStringTwo()
{
	//Create a UTF-16 string containing characters that correspond to 1- or 2-code-unit characters in UTF-8
	const Utf16String utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";

	//Get an iterator to the beginning of the string
	Utf16String::const_reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "x0034"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The fifth character should be a "\x03C9"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::const_reverse_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

void Utf16StringTest::TestConstReverseIteratorWithStringThree()
{
	//Create a UTF-16 string containing characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	const Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::const_reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The third character should be a "\x1EAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::const_reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

void Utf16StringTest::TestConstReverseIteratorWithStringFour()
{
	//Create a UTF-16 string containing 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	const Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::const_reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == (*stringIterator).size() || (size_t)2 == (*stringIterator).size());

		//The second character should be a "\xD800\xDF46"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 2);
		}

		//The fourth character should be a "\x1EAB"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\xD808\xDC68"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::const_reverse_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

void Utf16StringTest::TestIteratorWithStringOne()
{
	//Create a UTF-16 string containing only ASCII characters
	Utf16String utf16String = L"Simple String";
	
	//Get an iterator to the beginning of the string
	Utf16String::iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "p"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"e"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "g"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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

void Utf16StringTest::TestIteratorWithStringTwo()
{
	//Create a UTF-16 string containing characters that correspond to 1- or 2-code-unit characters in UTF-8
	Utf16String utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";

	//Get an iterator to the beginning of the string
	Utf16String::iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "\x06BD"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a "\x044A"
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x06BD"), (*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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

void Utf16StringTest::TestIteratorWithStringThree()
{
	//Create a UTF-16 string containing characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The third character should be a "\x0062"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\x2211"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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

void Utf16StringTest::TestIteratorWithStringFour()
{
	//Create a UTF-16 string containing 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::iterator stringIterator = utf16String.begin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0053"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.end())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == (*stringIterator).size() || (size_t)2 == (*stringIterator).size());

		//The fourth character should be a "\xD808\xDC68"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 2);
		}

		//The sixth character should be a "\x00DF"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The tenth character should be a "\xD800\xDF46"
		if(characterCount == 9)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), (*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.begin();
	CPPUNIT_ASSERT(stringIterator != utf16String.end());

	stringIterator = utf16String.end();
	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the += operator
	stringIterator = utf16String.begin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16String.end());

	//Test the + operator
	stringIterator = utf16String.begin();
	Utf16String::iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*newStringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*newStringIterator)[1]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16String.end());

	//Test the -= operator
	stringIterator = utf16String.end();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x2211"), (*stringIterator)[0]);

	stringIterator -= 8;

	CPPUNIT_ASSERT(stringIterator == utf16String.begin());

	//Test the - operator
	stringIterator = utf16String.end();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.begin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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
	stringIterator = utf16String.begin();
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

void Utf16StringTest::TestReverseIteratorWithStringOne()
{
	//Create a UTF-16 string containing only ASCII characters
	Utf16String utf16String = L"Simple String";
	
	//Get an reverse iterator to the end of the string
	Utf16String::reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the last character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"g"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "r"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The seventh character should be a space
		if(characterCount == 6)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L" "), (*stringIterator)[0]);
		}

		//The thirteenth character (the last character) should be a "S"
		if(characterCount == 12)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"S"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"t"), (*stringIterator)[0]);

	stringIterator += 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"r"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 10;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"p"), (*stringIterator)[0]);

	stringIterator -= 9;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"l"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 8;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

void Utf16StringTest::TestReverseIteratorWithStringTwo()
{
	//Create a UTF-16 string containing characters that correspond to 1- or 2-code-unit characters in UTF-8
	Utf16String utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";

	//Get an iterator to the beginning of the string
	Utf16String::reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x044A"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The fourth character should be a "x0034"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The fifth character should be a "\x03C9"
		if(characterCount == 5)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x03C9"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0034"), (*stringIterator)[0]);

	stringIterator += 3;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::reverse_iterator newStringIterator = stringIterator + 1;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 5;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 2;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0045"), (*stringIterator)[0]);

	stringIterator -= 4;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0068"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 1;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

void Utf16StringTest::TestReverseIteratorWithStringThree()
{
	//Create a UTF-16 string containing characters that correspond to 1-, 2, or 3-code-unit characters in UTF-8
	Utf16String utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should have no more than one code unit
		CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());

		//The third character should be a "\x1EAB"
		if(characterCount == 2)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\x1EAB"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	stringIterator += 5;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::reverse_iterator newStringIterator = stringIterator + 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0033"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

	stringIterator -= 6;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 4;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

void Utf16StringTest::TestReverseIteratorWithStringFour()
{
	//Create a UTF-16 string containing 1- or 2-code-unit characters characters that correspond to 
	//1-, 2, 3-, or 4-code-unit characters in UTF-8
	Utf16String utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
	
	//Get an iterator to the beginning of the string
	Utf16String::reverse_iterator stringIterator = utf16String.rbegin();

	//Verify that we can retrieve the first character
	CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0434"), (*stringIterator)[0]);

	//Iterate through the string, keeping track of the number of characters we've iterated over
	size_t characterCount = 0;
	size_t stringLength = utf16String.length();

	while(stringIterator != utf16String.rend())
	{
		//At this point we should still be within the bounds of the string
		CPPUNIT_ASSERT(characterCount < stringLength);	

		//Every character should be either one or two code units
		CPPUNIT_ASSERT((size_t)1 == (*stringIterator).size() || (size_t)2 == (*stringIterator).size());

		//The second character should be a "\xD800\xDF46"
		if(characterCount == 1)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD800"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDF46"), (*stringIterator)[1]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 2);
		}

		//The fourth character should be a "\x1EAB"
		if(characterCount == 3)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

			//Test the -> operator
			CPPUNIT_ASSERT(stringIterator->size() == 1);
		}

		//The eighth character should be a "\xD808\xDC68"
		if(characterCount == 7)
		{
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

			//Increment to the next position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)1, (*++stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x0062"), (*stringIterator)[0]);

			//Decrement to the previous position and verify that the character is correct
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*--stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

			//Now jump back two characters (testing both prefix and postfix decrementers) 
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*--stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator--)[0]);

			CPPUNIT_ASSERT_EQUAL((size_t)1, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00DF"), (*stringIterator)[0]);


			//Jump forward two characters (testing both prefix and postfix incrementers) to restore 
			//the iterator's position
			//Make sure that the postfix decrementer is decrementing *before* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*++stringIterator)[0]);

			//Make sure that the postfix decrementer is decrementing *after* it is used
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator++)[0]);

			//Make sure that we are back where we were earlier
			CPPUNIT_ASSERT_EQUAL((size_t)2, (*stringIterator).size());
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
			CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);
		}

		++stringIterator;
		++characterCount;
	}

	//Test the equality operator
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the assignment, equality, and inequality operators one more time
	stringIterator = utf16String.rbegin();
	CPPUNIT_ASSERT(stringIterator != utf16String.rend());

	stringIterator = utf16String.rend();
	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the += operator
	stringIterator = utf16String.rbegin();
	stringIterator += 3;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator += 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	stringIterator += 8;

	CPPUNIT_ASSERT(stringIterator == utf16String.rend());

	//Test the + operator
	stringIterator = utf16String.rbegin();
	Utf16String::reverse_iterator newStringIterator = stringIterator + 9;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*newStringIterator)[0]);

	stringIterator = newStringIterator + 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x1EAB"), (*stringIterator)[0]);

	newStringIterator = stringIterator + 2;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rend());

	//Test the -= operator
	stringIterator = utf16String.rend();
	stringIterator -= 4;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator -= 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xD808"), (*stringIterator)[0]);
	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\xDC68"), (*stringIterator)[1]);

	stringIterator -= 7;

	CPPUNIT_ASSERT(stringIterator == utf16String.rbegin());

	//Test the - operator
	stringIterator = utf16String.rend();
	newStringIterator = stringIterator - 5;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*newStringIterator)[0]);

	stringIterator = newStringIterator - 0;

	CPPUNIT_ASSERT_EQUAL(*((UInt16*)L"\x00F6"), (*stringIterator)[0]);

	newStringIterator = stringIterator - 6;

	CPPUNIT_ASSERT(newStringIterator == utf16String.rbegin());

	//Test the < operator
	//Test the operator when one iterator is a ways before the other iterator
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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
	stringIterator = utf16String.rbegin();
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

