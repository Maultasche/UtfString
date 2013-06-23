/*!
\file StringConverterTest.cpp

This file contains the definition of the StringConverterTest class.

In order for the tests in this file to work correctly, this file must be saved in UTF-8 encoding.
*/

#include <string>

#include "StringConverterTest.h"

#include <utfstring/UtfString.h>

using namespace UtfStringTest;
using namespace UtfString;
using namespace std;

void StringConverterTest::TestUtf8ToUtf16String()
{
	//Create a standard string containing simple ASCII characters
	string characterString = "Simple String";
	//Create a UTF-8 string containing simple ASCII characters
	Utf8String utf8String = "Simple String";
	//Create the UTF-16 version
	Utf16String utf16String = L"Simple String";
	
	//Convert the simple ASCII string
	Utf16String utf16ConvertedString;
	UtfStringConverter::Utf8ToUtf16String(characterString, utf16ConvertedString);
	
	//Check the results
	CPPUNIT_ASSERT_EQUAL(characterString.length(), utf16ConvertedString.length());
	CPPUNIT_ASSERT_EQUAL(characterString.length(), utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);
	
	//Convert the UTF-8 ASCII string
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16ConvertedString);
	
	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf8String.length(), utf16ConvertedString.length());
	CPPUNIT_ASSERT_EQUAL(utf8String.size(), utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);
	
	//Create a standard string containing a mix of 1- and 2-byte UTF-8 characters
	characterString = "ωE4ڽhъ";
	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "ωE4ڽhъ";
	//Create the UTF-16 version
	utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";
	
	//Convert the simple string
	UtfStringConverter::Utf8ToUtf16String(characterString, utf16ConvertedString);
	
	//Check the results
	CPPUNIT_ASSERT(characterString.length() != utf16ConvertedString.length());
	CPPUNIT_ASSERT(characterString.length() != utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);
	
	//Convert the UTF-8 string
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16ConvertedString);
	
	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf8String.length(), utf16ConvertedString.length());
	CPPUNIT_ASSERT(utf8String.size() != utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);
	
	//Create a standard string class containing a 1-, 2-, and 3-byte UTF-8 characters
	characterString = "Sẫböß3ẫ∑д";
	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Convert the simple string
	UtfStringConverter::Utf8ToUtf16String(characterString, utf16ConvertedString);

	//Check the results
	CPPUNIT_ASSERT(characterString.length() != utf16ConvertedString.length());
	CPPUNIT_ASSERT(characterString.length() != utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);

	//Convert the UTF-8 string
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16ConvertedString);

	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf8String.length(), utf16ConvertedString.length());
	CPPUNIT_ASSERT(utf8String.size() != utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);

	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a standard string class containing a 1-, 2-, 3-, and 4-byte UTF-8 characters
	characterString = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Convert the simple string
	UtfStringConverter::Utf8ToUtf16String(characterString, utf16ConvertedString);

	//Check the results
	CPPUNIT_ASSERT(characterString.length() != utf16ConvertedString.length());
	CPPUNIT_ASSERT(characterString.length() != utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);

	//Convert the UTF-8 string
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16ConvertedString);

	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf8String.length(), utf16ConvertedString.length());
	CPPUNIT_ASSERT(utf8String.size() != utf16ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf16String, utf16ConvertedString);
}

void StringConverterTest::TestUtf16ToUtf8String()
{
	Utf8String utf8ConvertedString;

	//Create a UTF-8 string containing simple ASCII characters
	Utf8String utf8String = "Simple String";
	//Create the UTF-16 version
	Utf16String utf16String = L"Simple String";

	//Convert the UTF-16 string
	UtfStringConverter::Utf16ToUtf8String(utf16String, utf8ConvertedString);

	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf16String.length(), utf8ConvertedString.length());
	CPPUNIT_ASSERT_EQUAL(utf16String.size(), utf8ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf8String, utf8ConvertedString);

	//Create a UTF-8 string containing a mix of 1- and 2-byte UTF-8 characters
	utf8String = "ωE4ڽhъ";
	//Create the UTF-16 version
	utf16String = L"\x03C9\x0045\x0034\x06BD\x0068\x044A";

	//Convert the UTF-8 string
	UtfStringConverter::Utf16ToUtf8String(utf16String, utf8ConvertedString);

	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf16String.length(), utf8ConvertedString.length());
	CPPUNIT_ASSERT(utf16String.size() != utf8ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf8String, utf8ConvertedString);

	//Create a UTF-8 string containing a mix of 1-, 2-, and 3-byte UTF-8 characters
	utf8String = "Sẫböß3ẫ∑д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\x0434";

	//Convert the UTF-8 string
	UtfStringConverter::Utf16ToUtf8String(utf16String, utf8ConvertedString);

	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf16String.length(), utf8ConvertedString.length());
	CPPUNIT_ASSERT(utf16String.size() != utf8ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf8String, utf8ConvertedString);

	//We're using the following characters not found in the basic multilingual plane:
	//A cuneiform character, 0x12068, and a gothic character, 0x10346
	//Create a UTF-8 string containing a mix of 1-, 2-, 3-, and 4-byte UTF-8 characters
	utf8String = "Sẫb\xF0\x92\x81\xA8öß3ẫ∑\xF0\x90\x8D\x86д";
	//Create the UTF-16 version
	utf16String = L"\x0053\x1EAB\x0062\xD808\xDC68\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";

	//Convert the UTF-8 string
	UtfStringConverter::Utf16ToUtf8String(utf16String, utf8ConvertedString);

	//Check the results
	CPPUNIT_ASSERT_EQUAL(utf16String.length(), utf8ConvertedString.length());
	CPPUNIT_ASSERT(utf16String.size() != utf8ConvertedString.size());
	CPPUNIT_ASSERT_EQUAL(utf8String, utf8ConvertedString);
}
