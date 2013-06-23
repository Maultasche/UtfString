#include <assert.h>

#include <utfstring/UtfString.h>

using namespace UtfString;
using namespace std;

void UtfStringConverter::Utf8ToUtf16String(const Utf8String& utf8String, Utf16String& utf16String)
{
	Utf8ToUtf16String((string)utf8String, utf16String);
}

void UtfStringConverter::Utf8ToUtf16String(const std::string& utf8String, Utf16String& utf16String)
{
	utf16String.clear();

	char utf8CodePoint[4];
	UInt16 utf16CodePoint[2];

	for(string::const_iterator stringIterator = utf8String.begin(); stringIterator != utf8String.end();)
	{
		size_t utf16CodePointSize = 2;
		size_t utf8CodePointSize = Utf8String::CharacterCodeUnitCount(stringIterator);

		//Fill the code point buffer with the code units reperesenting current code point
		switch(utf8CodePointSize)
		{
		case 1:
			utf8CodePoint[0] = *stringIterator++;
			break;
		case 2:
			utf8CodePoint[0] = *stringIterator++;
			utf8CodePoint[1] = *stringIterator++;
			break;
		case 3:
			utf8CodePoint[0] = *stringIterator++;
			utf8CodePoint[1] = *stringIterator++;
			utf8CodePoint[2] = *stringIterator++;
			break;
		case 4:
			utf8CodePoint[0] = *stringIterator++;
			utf8CodePoint[1] = *stringIterator++;
			utf8CodePoint[2] = *stringIterator++;
			utf8CodePoint[3] = *stringIterator++;
			break;
		default:
			//Something has gone wrong if we don't get a count between 1 and 4
			assert(false);
			break;
		}

		//Convert the code point to UTF-16
		Utf8ToUtf16Char(utf8CodePoint, utf8CodePointSize, utf16CodePoint, utf16CodePointSize);

		//Add the converted code point to the UTF-16 string
		utf16String.append(utf16CodePoint, utf16CodePointSize);
	}
}

void UtfStringConverter::Utf16ToUtf8String(const Utf16String& utf16String, Utf8String& utf8String)
{
	utf8String.clear();

	char utf8CodePoint[4];
	UInt16 utf16CodePoint[2];

	for(Utf16String::const_iterator stringIterator = utf16String.begin(); stringIterator != utf16String.end();
		++stringIterator)
	{
		size_t utf16CodePointSize = (*stringIterator).size();
		size_t utf8CodePointSize = 4;

		//Fill the code point buffer with the code units reperesenting current code point
		switch(utf16CodePointSize)
		{
		case 1:
			utf16CodePoint[0] = (*stringIterator)[0];
			break;
		case 2:
			utf16CodePoint[0] = (*stringIterator)[0];
			utf16CodePoint[1] = (*stringIterator)[1];
			break;
		default:
			//Something has gone wrong if we don't get a count between 1 and 2
			assert(false);
			break;
		}

		//Convert the code point to UTF-8
		Utf16ToUtf8Char(utf16CodePoint, utf16CodePointSize, utf8CodePoint, utf8CodePointSize);

		//Add the converted code point to the UTF-8 string
		utf8String.append(utf8CodePoint, utf8CodePointSize);
	}
}

void UtfStringConverter::Utf16ToUtf8String(const std::wstring& utf16String, Utf8String& utf8String)
{
	Utf16ToUtf8String(Utf16String(utf16String), utf8String);
}

void UtfStringConverter::Utf8ToUtf16Char(const char utf8Char[], const size_t utf8CodeUnitCount,
										 UInt16 utf16Char[], size_t& utf16BufferSize)
{
	//Assert that the code unit count is 4 or less, since no valid UTF-8 character is longer than 4 bytes
	assert(utf8CodeUnitCount <= 4);

	//Assert that the actual character code unit count is the same as the count we are given. It is entirely possible
	//that we are told the UTF-8 character is composed of 3 code units, but it is actually composed of 1 code unit.
	assert(Utf8String::CharacterCodeUnitCount(utf8Char) == utf8CodeUnitCount);

	//UTF-16 was designed so that any code point at 010000 or above is represented by two code units,
	//and UTF-8 was designed so that any code point at 010000 or above is represented by four code units.
	//So any UTF-8 code point of less than 4 code units can be converted to a single UTF-16 code unit, and
	//any UTF-8 code point of 4 code units can be converted to two UTF-16 code units. Very convenient!
	switch(utf8CodeUnitCount)
	{
	//One UTF-8 Code Unit: Code Range 000000-00007F
	case 1:
		//Assert that the size of the UTF-16 buffer is at least 1
		assert(utf16BufferSize >= 1);

		//0zzzzzzz -> 00000000 0zzzzzzz
		utf16Char[0] = utf8Char[0];

		//Since the UTF-16 character uses a single code point, set the buffer size to 1
		utf16BufferSize = 1;
		break;

	//Two UTF-8 Code Units: Code Range 000080-0007FF
	case 2:
		//Assert that the size of the UTF-16 buffer is at least 1
		assert(utf16BufferSize >= 1);

		//110yyyyy, 10zzzzzz -> 00000yyy yyzzzzzz
		utf16Char[0] = ((utf8Char[0] & 0x1F) << 6) | (utf8Char[1] & 0x3F);

		//Since the UTF-16 character uses a single code point, set the buffer size to 1
		utf16BufferSize = 1;
		break;

	//Three UTF-8 Code Units: Code Range 000800-00FFFF
	case 3:
		//Assert that the size of the UTF-16 buffer is at least 1
		assert(utf16BufferSize >= 1);

		//1110xxxx, 10yyyyyy, 10zzzzzz -> xxxxyyyy yyzzzzzz
		utf16Char[0] = ((utf8Char[0] & 0x0F) << 12) | ((utf8Char[1] & 0x3F) << 6) | (utf8Char[2] & 0x3F);

		//Since the UTF-16 character uses a single code point, set the buffer size to 1
		utf16BufferSize = 1;
		break;

	//Four UTF-8 Code Units: Code Range 010000-10FFFF
	case 4:
		//Assert that the size of the UTF-16 buffer is at least 2
		assert(utf16BufferSize >= 2);

		//Convert the UTF-8 code units to a single 32-bit code unit
		//11110www, 10xxxxxx, 10yyyyyy, 10zzzzzz -> 00000000 000wwwxx xxxxyyyy yyzzzzzz
		UInt32 codePoint = ((utf8Char[0] & 0x07) << 18) | ((utf8Char[1] & 0x3F) << 12)
			| ((utf8Char[2] & 0x3F) << 6) | (utf8Char[3] & 0x3F);

		//Now we need to do the magic to convert the 32-bit code unit to two 16-bit code units
		//Get the offset of the code point from the code point 0x10000
		UInt32 codePointOffset = codePoint - 0x10000;

		//Assert that the offset is 20 bits or less; otherwise, the code point is not valid
		assert((codePointOffset & 0x000FFFFF) == codePointOffset);

		//Now split the offset into two 10-bit values, then bitwise OR the two values by the magical numbers
		//to form the final 16-bit code units
		utf16Char[0] = (UInt16)(((codePointOffset & 0x000FFC00) >> 10) | HighCodeUnitBaseNumber);
		utf16Char[1] = (UInt16)((codePointOffset & 0x000003FF) | LowCodeUnitBaseNumber);

		//Since the UTF-16 character uses a single code point, set the buffer size to 2
		utf16BufferSize = 2;
		break;
	}
}

void UtfStringConverter::Utf16ToUtf8Char(const UInt16 utf16CodePoint[], const size_t utf16CodeUnitCount,
	char utf8CodePoint[], size_t& utf8BufferSize)
{
	//Assert that the code unit count is 4 or less, since no valid UTF-8 character is longer than 4 bytes
	assert(utf16CodeUnitCount <= 4);

	//Assert that the actual character code unit count is the same as the count we are given. It is entirely possible
	//that we are told the UTF-8 character is composed of 3 code units, but it is actually composed of 1 code unit.
	assert(Utf16String::CharacterCodeUnitCount(utf16CodePoint) == utf16CodeUnitCount);

	//Assert that the UTF-8 code unit buffer is actually pointing to something
	assert(utf8CodePoint != NULL);

	UInt32 codePoint;

	//UTF-16 was designed so that any code point at 010000 or above is represented by two code units,
	//and UTF-8 was designed so that any code point at 010000 or above is represented by four code units.
	//So any UTF-16 code point of 2 code units will be converted t a UTF-8 code point of four code units.
	//Very convenient!
	switch(utf16CodeUnitCount)
	{
	//One UTF-16 code unit: Code Range 000000-00FFFF
	case 1:
		//If the code point is in the 000000-00007F range, then we encode it as one UTF-8 code unit
		if(utf16CodePoint[0] < 0x80)
		{
			//Assert that the UTF-8 buffer has a length of at least 1
			assert(utf8BufferSize >= 1);

			utf8CodePoint[0] = (char)utf16CodePoint[0];

			//Set the number of code units stored in the UTF-8 buffer
			utf8BufferSize = 1;
		}

		//If the code point is in the 000080-0007FF range, then we encode it as two UTF-8 code units
		else if(utf16CodePoint[0] >= 0x80 && utf16CodePoint[0] <= 0x7FF)
		{
			//Assert that the UTF-8 buffer has a length of at least 2
			assert(utf8BufferSize >= 2);

			//00000yyy yyzzzzzz -> 110yyyyy, 10zzzzzz
			utf8CodePoint[0] = (char)(utf16CodePoint[0] >> 6) | 0xC0;
			utf8CodePoint[1] = (char)(utf16CodePoint[0] & 0x3F) | 0x80;

			//Set the number of code units stored in the UTF-8 buffer
			utf8BufferSize = 2;
		}

		//If the code point is in the 000800-00FFFF range, then we encode it as three UTF-8 code units
		else if(utf16CodePoint[0] >= 0x800)
		{
			//Assert that the UTF-8 buffer has a length of at least 3
			assert(utf8BufferSize >= 3);

			// xxxxyyyy yyzzzzzz -> 1110xxxx, 10yyyyyy, 10zzzzzz
			utf8CodePoint[0] = (char)(utf16CodePoint[0] >> 12) | 0xE0;
			utf8CodePoint[1] = (char)((utf16CodePoint[0] & 0xFC0) >> 6) | 0x80;
			utf8CodePoint[2] = (char)(utf16CodePoint[0] & 0x3F) | 0x80;

			//Set the number of code units stored in the UTF-8 buffer
			utf8BufferSize = 3;
		}

		break;
	//Two UTF-16 code units: Code Range 010000-10FFFF
	case 2:
		//Assert that the UTF-8 buffer has a length of at least 4
		assert(utf8BufferSize >= 4);

		//Decoding UTF-16 surrogate pairs involve extracting the code unit. So instead of duplicating that
		//functionality here, we can just call the function that already does it for us.
		codePoint = Utf16String::DecodeCharacter(utf16CodePoint, utf16CodeUnitCount);

		//Now encode it as four UTF-8 code units
		//00000000 000wwwxx xxxxyyyy yyzzzzzz -> 11110www, 10xxxxxx, 10yyyyyy, 10zzzzzz
		utf8CodePoint[0] = (char)(codePoint >> 18) | 0xF0;
		utf8CodePoint[1] = (char)((codePoint & 0x3F000) >> 12) | 0x80;
		utf8CodePoint[2] = (char)((codePoint & 0xFC0) >> 6) | 0x80;
		utf8CodePoint[3] = (char)(codePoint & 0x3F) | 0x80;

		//Set the number of code units stored in the UTF-8 buffer
		utf8BufferSize = 4;

		break;
	//If we get to this point, there was a code-related error, so trigger an assertion failure
	default:
		assert(false);
		break;
	}
}
