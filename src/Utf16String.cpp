#include <utfstring/UtfString.h>

//These includes are only needed for this code file and don't need 
//to be located in the library header file
#include <assert.h>
#include <sstream>

using namespace UtfString;
using namespace std;

/*Utf16String Definition*/

/*Static Constants*/
const size_t Utf16String::npos = (size_t)-1;

/*Constructors*/

Utf16String::Utf16String()
{

}

Utf16String::Utf16String(const Utf16String& utf16String)
{
	m_codeUnitString.assign(utf16String.m_codeUnitString);
}

Utf16String::Utf16String(const std::basic_string<UInt16>& utf16String)
{
	m_codeUnitString.assign(utf16String);
}


Utf16String::Utf16String(const UInt16* utf16String)
{
	m_codeUnitString.assign(utf16String);
}

Utf16String::Utf16String(const UInt16* utf16String, const size_t codeUnitCount)
{
	m_codeUnitString.assign(utf16String, codeUnitCount);
}

Utf16String::Utf16String(const wchar_t* wideString)
{
#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->assign((UInt16*)wideString);
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wcslen(wideString);

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->assign(characterBuffer);

	delete[] characterBuffer;
#endif
}

Utf16String::Utf16String(const wchar_t* wideString, const size_t characterCount)
{
#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->assign((UInt16*)wideString, characterCount);
#endif

#ifndef WCHAR_T_16BIT
	//If wchar_t is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->assign(characterBuffer);

	delete[] characterBuffer;
#endif
}

Utf16String::Utf16String(const std::wstring& wideString)
{
#ifdef WCHAR_T_16BIT
	//If a wchar_t is 16 bits, no problem
	this->assign((UInt16*)wideString.c_str());
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wideString.size();

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString.c_str();
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->assign(characterBuffer);

	delete[] characterBuffer;
#endif
}

Utf16String::Utf16String(const Utf8String& utf8String)
{
	//Convert the UTF-8 string to a UTF-16 string and assign it to this object
	UtfStringConverter::Utf8ToUtf16String(utf8String, *this);
}

Utf16String::Utf16String(std::string utf8String)
{
	//Convert the UTF-8 string to a UTF-16 string and assign it to this object
	UtfStringConverter::Utf8ToUtf16String(utf8String, *this);
}

Utf16String::Utf16String(const char* utf8String)
{
	//Convert the UTF-8 string to a UTF-16 string and assign it to this object
	UtfStringConverter::Utf8ToUtf16String(string(utf8String), *this);
}

Utf16String::Utf16String(const char* utf8String, const size_t characterCount)
{
	//Convert the UTF-8 string to a UTF-16 string and assign it to this object
	UtfStringConverter::Utf8ToUtf16String(string(utf8String, characterCount), *this);
}

Utf16String::~Utf16String()
{
}

/*Member Functions*/

Utf16String& Utf16String::append(const Utf16String& utf16String)
{
	m_codeUnitString.append(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::append(const std::basic_string<UInt16>& utf16String)
{
	m_codeUnitString.append(utf16String);

	return *this;
}

Utf16String& Utf16String::append(const UInt16* utf16String)
{
	m_codeUnitString.append(utf16String);

	return *this;
}

Utf16String& Utf16String::append(const UInt16* utf16String, const size_t codeUnitCount)
{
	m_codeUnitString.append(utf16String, codeUnitCount);

	return *this;
}

Utf16String& Utf16String::append(const wchar_t* wideString)
{
#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->append((UInt16*)wideString);
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wcslen(wideString);

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->append(characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::append(const wchar_t* wideString, const size_t characterCount)
{
#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->append((UInt16*)wideString, characterCount);
#endif

#ifndef WCHAR_T_16BIT
	//If wchar_t is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->append(characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::append(const std::wstring& wideString)
{
#ifdef WCHAR_T_16BIT
	//If a wchar_t is 16 bits, no problem
	this->append((UInt16*)wideString.c_str());
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wideString.size();

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString.c_str();
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->append(characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::append(const Utf8String& utf8String)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16String);

	m_codeUnitString.append(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::append(const std::string& utf8String)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16String);

	m_codeUnitString.append(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::append(const char* utf8String)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(string(utf8String), utf16String);

	m_codeUnitString.append(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::append(const char* utf8String, const size_t characterCount)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(string(utf8String, characterCount), utf16String);

	m_codeUnitString.append(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::append(const Utf16Char& utf16Character)
{
	assert(utf16Character.is_valid());

	m_codeUnitString.append(&utf16Character[0], 1);

	if(utf16Character.size() == 2)
	{
		m_codeUnitString.append(&utf16Character[1], 1);
	}

	return *this;
}

Utf16String& Utf16String::assign(const Utf16String& utf16String)
{
	m_codeUnitString.assign(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::assign(const std::basic_string<UInt16>& utf16String)
{
	m_codeUnitString.assign(utf16String);

	return *this;
}

Utf16String& Utf16String::assign(const UInt16* utf16String)
{
	m_codeUnitString.assign(utf16String);

	return *this;
}

Utf16String& Utf16String::assign(const UInt16* utf16String, const size_t codeUnitCount)
{
	m_codeUnitString.assign(utf16String, codeUnitCount);

	return *this;
}

Utf16String& Utf16String::assign(const wchar_t* wideString)
{
#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->assign((UInt16*)wideString);
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wcslen(wideString);

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->assign(characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::assign(const wchar_t* wideString, const size_t characterCount)
{
#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->assign((UInt16*)wideString, characterCount);
#endif

#ifndef WCHAR_T_16BIT
	//If wchar_t is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->assign(characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::assign(const std::wstring& wideString)
{
#ifdef WCHAR_T_16BIT
	//If a wchar_t is 16 bits, no problem
	this->assign((UInt16*)wideString.c_str());
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wideString.size();

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString.c_str();
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->assign(characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::assign(const Utf8String& utf8String)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and assign it
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16String);

	m_codeUnitString.assign(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::assign(const std::string& utf8String)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16String);

	m_codeUnitString.assign(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::assign(const char* utf8String)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(string(utf8String), utf16String);

	m_codeUnitString.assign(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::assign(const char* utf8String, const size_t characterCount)
{
	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(string(utf8String, characterCount), utf16String);

	m_codeUnitString.assign(utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::assign(const Utf16Char& utf16Character)
{
	assert(utf16Character.is_valid());

	m_codeUnitString.assign(&utf16Character[0], 1);

	if(utf16Character.size() == 2)
	{
		m_codeUnitString.append(&utf16Character[1], 1);
	}

	return *this;
}

Utf16CharReference Utf16String::at(size_t index)
{
	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	basic_string<UInt16>::iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		UInt16 currentCodeUnit = *stringIterator;
		UInt16 nextCodeUnit = L'\x0000';

		//Check to prevent us from reading beyond the end of the string
		if(stringIterator + 1 != m_codeUnitString.end())
		{
			nextCodeUnit = *(stringIterator + 1);
		}

		bool surrogatePair = currentCodeUnit >= HighCodeUnitRangeBegin && 
				currentCodeUnit <= HighCodeUnitRangeEnd && 
				nextCodeUnit >= LowCodeUnitRangeBegin &&
				nextCodeUnit <= LowCodeUnitRangeEnd;

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			//Check for a surrogate pair
			if(surrogatePair)
			{
				codeUnitCount = 2;
			}
			else
			{
				codeUnitCount = 1;
			}

			break;
		}

		//Check for a surrogate pair
		if(surrogatePair)
			stringIterator += 2;
		else
			++stringIterator;

		++codePointCount;
	}

	if(stringIterator == m_codeUnitString.end())
	{
		std::stringstream errorMessageStream;
		errorMessageStream << "The index " << index << " does not exist in this string of length "
			<< codePointCount;

		throw out_of_range(errorMessageStream.str());
	}

	return Utf16CharReference(m_codeUnitString, stringIterator, codeUnitCount);
}

const Utf16Char Utf16String::at(size_t index) const
{
	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	basic_string<UInt16>::const_iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		UInt16 currentCodeUnit = *stringIterator;
		UInt16 nextCodeUnit = L'\x0000';

		//Check to prevent us from reading beyond the end of the string
		if(stringIterator + 1 != m_codeUnitString.end())
		{
			nextCodeUnit = *(stringIterator + 1);
		}

		bool surrogatePair = currentCodeUnit >= HighCodeUnitRangeBegin && 
				currentCodeUnit <= HighCodeUnitRangeEnd && 
				nextCodeUnit >= LowCodeUnitRangeBegin &&
				nextCodeUnit <= LowCodeUnitRangeEnd;

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			//Check for a surrogate pair
			if(surrogatePair)
			{
				codeUnitCount = 2;
			}
			else
			{
				codeUnitCount = 1;
			}

			break;
		}

		//Check for a surrogate pair
		if(surrogatePair)
			stringIterator += 2;
		else
			++stringIterator;

		++codePointCount;
	}

	if(stringIterator == m_codeUnitString.end())
	{
		std::stringstream errorMessageStream;
		errorMessageStream << "The index " << index << " does not exist in this string of length "
			<< codePointCount;

		throw out_of_range(errorMessageStream.str());
	}

	return Utf16Char(stringIterator, codeUnitCount);
}

Utf16String::iterator Utf16String::begin()
{
	return Utf16String::iterator(m_codeUnitString, m_codeUnitString.begin());
}

Utf16String::const_iterator Utf16String::begin() const
{
	return Utf16String::const_iterator(m_codeUnitString, m_codeUnitString.begin());
}

const UInt16* Utf16String::c_str() const
{
	return m_codeUnitString.c_str();
}

size_t Utf16String::capacity() const
{
	return m_codeUnitString.capacity();
}

void Utf16String::clear()
{
	m_codeUnitString.clear();
}

size_t Utf16String::code_unit_index(const size_t codePointIndex)
{
	assert(is_valid());

	size_t codeUnitIndex = 0;

	if(codePointIndex >= length())
	{
		codeUnitIndex = Utf16String::npos;
	}
	else
	{
		basic_string<UInt16>::const_iterator stringIterator = m_codeUnitString.begin();

		//Iterate through the code unit string, counting the code points until we've found the correct code unit
		for(size_t index = 0; index < codePointIndex; ++index)
		{
			switch(Utf16String::CharacterCodeUnitCount(stringIterator))
			{
			case 1:
				++stringIterator;
				++codeUnitIndex;
				break;
			case 2:
				stringIterator += 2;
				codeUnitIndex += 2;
				break;
			default:
				//If we've reached this point something has gone wrong
				assert(false);
				break;
			}
		}
	}

	return codeUnitIndex;
}

size_t Utf16String::code_point_index(const size_t codeUnitIndex)
{
	assert(is_valid());

	size_t codePointIndex = 0;

	if(codeUnitIndex >= size())
	{
		codePointIndex = Utf16String::npos;
	}
	else
	{
		basic_string<UInt16>::const_iterator stringIterator = m_codeUnitString.begin() + 1;

		for(size_t index = 1; index <= codeUnitIndex; ++index)
		{
			//Since CharacterCodeUnitCount always returns 0 for code units that are not the first
			//code unit of a code point, we can simply add 1 to the code point count every time
			//CharacterCodeUnit count returns a non-zero value to get the correct code point count
			switch(Utf16String::CharacterCodeUnitCount(stringIterator))
			{
			case 2:
			case 1:
				++codePointIndex;
			case 0:
				++stringIterator;
				break;
			default:
				//If we've reached this point, something has gone wrong
				assert(false);
				break;
			}
		}
	}

	return codePointIndex;
}

int Utf16String::compare(const Utf16String& utf16String) const
{
	//A value of -2 indicates that we haven't figured out the comparison value yet
	int compareValue = -2;

	//Since surrogate code units range from 0xD800 - 0xDFFF, the code units in the range
	//0xE000 - 0xFFFF are greater in value than the surrogate code units, but have a lesser
	//code point value. This means that we can't rely on the basic_string compare implementation,
	//which compares code unit values.  So we will have to compare code point values instead.
	Utf16String::const_iterator thisStringIterator = this->begin();
	Utf16String::const_iterator parameterStringIterator = utf16String.begin();

	while(thisStringIterator != this->end() && parameterStringIterator != utf16String.end()
		&& compareValue == -2)
	{
		UInt32 thisCharValue = (*thisStringIterator).to_utf_32();
		UInt32 parameterCharValue = (*parameterStringIterator).to_utf_32();

		if(thisCharValue != parameterCharValue)
		{
			if(thisCharValue > parameterCharValue)
			{
				compareValue = 1;
			}
			else
			{
				compareValue = -1;
			}
		}

		++thisStringIterator;
		++parameterStringIterator;
	}

	//If the comparison value is still -2, that means all characters compared were the same.
	//However, we need to test the length of the strings. If the length of the two strings are
	//the same, they are equal.  Otherwise, the longer string is considered to be greater than
	//the shorter string
	if(compareValue == -2)
	{
		//Calculating the length only once will make this more efficient, since length calculations
		//are O(n) operations
		size_t thisStringLength = this->length();
		size_t parameterStringLength = utf16String.length();

		if(thisStringLength == parameterStringLength)
		{
			compareValue = 0;
		}
		else if(thisStringLength > parameterStringLength)
		{
			compareValue = 1;
		}
		else
		{
			compareValue = -1;
		}
	}

	//By this point, we should have the comparison value
	assert(compareValue != -2);

	return compareValue;
}

int Utf16String::compare(const std::basic_string<UInt16>& utf16String) const
{
	//The overhead of converting a basic_string of UInt16 to a Utf16String is minimal,
	//so we'll just convert the parameter string
	return this->compare(Utf16String(utf16String));
}

int Utf16String::compare(const UInt16* utf16String) const
{
	//The overhead of converting a UInt16 array to a Utf16String is minimal,
	//so we'll just convert the parameter string
	return this->compare(Utf16String(utf16String));
}

int Utf16String::compare(const UInt16* utf16String, const size_t codeUnitCount) const
{
	//The overhead of converting a UInt16 array to a Utf16String is minimal,
	//so we'll just convert the parameter string
	return this->compare(Utf16String(utf16String, codeUnitCount));
}

int Utf16String::compare(const wchar_t* wideString) const
{
	//We are only comparing code units until we find differing code units.
	//When we find differing code units, it doesn't not matter whether the code units are part
	//of one- or two-code-unit code points.  As far as I can tell, just looking at the first
	//unit (when the code units differ) is enough to determine the order of the code points
	//that the code units represent.  So the basic_string compare implementation should do
	//what we need.

	int compareResult = 0;

#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	compareResult = this->compare((UInt16*)wideString);
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wcslen(wideString);

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	compareResult = this->compare(characterBuffer);

	delete[] characterBuffer;
#endif

	return compareResult;
}

int Utf16String::compare(const wchar_t* wideString, const size_t codeUnitCount) const
{
	//We are only comparing code units until we find differing code units.
	//When we find differing code units, it doesn't not matter whether the code units are part
	//of one- or two-code-unit code points.  As far as I can tell, just looking at the first
	//unit (when the code units differ) is enough to determine the order of the code points
	//that the code units represent.  So the basic_string compare implementation should do
	//what we need.

	int compareResult = 0;

#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	compareResult = this->compare((UInt16*)wideString, codeUnitCount);
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = codeUnitCount;

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	compareResult = this->compare(characterBuffer);

	delete[] characterBuffer;
#endif

	return compareResult;
}

int Utf16String::compare(const std::wstring& wideString) const
{
	//We are only comparing code units until we find differing code units.
	//When we find differing code units, it doesn't not matter whether the code units are part
	//of one- or two-code-unit code points.  As far as I can tell, just looking at the first
	//unit (when the code units differ) is enough to determine the order of the code points
	//that the code units represent.  So the basic_string compare implementation should do
	//what we need.

	int compareResult = 0;

#ifdef WCHAR_T_16BIT
	//If a wchar_t is 16 bits, no problem
	compareResult = this->compare((UInt16*)wideString.c_str());
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wideString.size();

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit characters
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString.c_str();
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t index = 0; index < characterCount; index++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	compareResult = this->compare(characterBuffer);

	delete[] characterBuffer;
#endif

	return compareResult;
}

int Utf16String::compare(const Utf8String& utf8String) const
{
	//A value of -2 indicates that we haven't figured out the comparison value yet
	int compareValue = -2;

	//Instead of converting the entire UTF-8 string, it would be more efficient to
	//iterate through both strings, comparing the 32-bit code point values and stopping
	//when a difference is found. This will definitely be more efficient than converting 
	//the entire string when the strings are unequal and around the same efficiency
	//when the strings are equal.
	Utf8String::const_iterator utf8StringIterator = utf8String.begin();
	Utf16String::const_iterator utf16StringIterator = this->begin();

	while(utf8StringIterator != utf8String.end() && utf16StringIterator != this->end()
		&& compareValue == -2)
	{
		UInt32 utf16CharValue = (*utf16StringIterator).to_utf_32();
		UInt32 utf8CharValue = (*utf8StringIterator).to_utf_32();

		if(utf16CharValue != utf8CharValue)
		{
			if(utf16CharValue > utf8CharValue)
			{
				compareValue = 1;
			}
			else
			{
				compareValue = -1;
			}
		}

		++utf8StringIterator;
		++utf16StringIterator;
	}

	//If the comparison value is still -2, that means all characters compared were the same.
	//However, we need to test the length of the strings. If the length of the two strings are
	//the same, they are equal.  Otherwise, the longer string is considered to be greater than
	//the shorter string
	if(compareValue == -2)
	{
		//Calculating the length only once will make this more efficient, since length calculations
		//are O(n) operations
		size_t utf16StringLength = this->length();
		size_t utf8StringLength = utf8String.length();

		if(utf16StringLength == utf8StringLength)
		{
			compareValue = 0;
		}
		else if(utf16StringLength > utf8StringLength)
		{
			compareValue = 1;
		}
		else
		{
			compareValue = -1;
		}
	}

	//By this point, we should have the comparison value
	assert(compareValue != -2);

	return compareValue;
}

int Utf16String::compare(const std::string& utf8String) const
{
	//The overhead of converting a std::string to a Utf8String is minimal,
	//so we'll just convert the parameter string
	return this->compare(Utf8String(utf8String));
}

int Utf16String::compare(const char* utf8String) const
{
	//The overhead of converting a char array to a Utf8String is minimal,
	//so we'll just convert the parameter string
	return this->compare(Utf8String(utf8String));
}

int Utf16String::compare(const char* utf8String, const size_t codeUnitCount) const
{
	//The overhead of converting a char array to a Utf8String is minimal,
	//so we'll just convert the parameter string
	return this->compare(Utf8String(utf8String, codeUnitCount));
}

size_t Utf16String::copy(UInt16* codeUnitArray, const size_t codeUnitArraySize, const size_t characterCount,
	const size_t characterOffset) const
{
	assert(characterOffset < length());

	size_t copiedCodeUnits = 0;
	size_t copiedCharacters = 0;

	for(Utf16String::const_iterator stringIterator = this->begin() + characterOffset;
		stringIterator != this->end() && copiedCharacters < characterCount; ++stringIterator)
	{
		Utf16Char currentCharacter = *stringIterator;

		if(currentCharacter.size() == 1)
		{
			//If we can't copy any more code units, then stop the copying
			if(copiedCodeUnits + 1 >= codeUnitArraySize)
			{
				stringIterator = this->end() - 1;
			}

			//Otherwise, continue copying
			else
			{
				codeUnitArray[copiedCodeUnits] = currentCharacter[0];
				++copiedCodeUnits;
			}

			++copiedCharacters;
		}
		else if(currentCharacter.size() == 2)
		{
			//If we can't copy any more code units, then stop the copying
			if(copiedCodeUnits + 2 >= codeUnitArraySize)
			{
				stringIterator = this->end() - 1;
			}

			//Otherwise, continue copying
			else
			{
				codeUnitArray[copiedCodeUnits] = currentCharacter[0];
				++copiedCodeUnits;

				codeUnitArray[copiedCodeUnits] = currentCharacter[1];
				++copiedCodeUnits;
			}

			++copiedCharacters;
		}
	}

	return copiedCodeUnits;
}

const UInt16* Utf16String::data() const
{
	return m_codeUnitString.data();
}

bool Utf16String::empty() const
{
	return m_codeUnitString.empty();
}

Utf16String::iterator Utf16String::end()
{
	return Utf16String::iterator(m_codeUnitString, m_codeUnitString.end());
}

Utf16String::const_iterator Utf16String::end() const
{
	return Utf16String::const_iterator(m_codeUnitString, m_codeUnitString.end());
}

Utf16String::iterator Utf16String::erase(const Utf16String::iterator& firstPosition,
										 const Utf16String::iterator& lastPosition)
{
	return Utf16String::iterator(m_codeUnitString, m_codeUnitString.erase(firstPosition.codeUnitPosition,
		lastPosition.codeUnitPosition));
}

Utf16String::iterator Utf16String::erase(const Utf16String::iterator& position)
{
	//Since there is no default constructor for Utf16String::iterator, just initialize it using
	//the iterator that was passed in
	Utf16String::iterator postEraseIterator(position);

	//We might have to remove one or two code units, depending on what sort of code point this is
	switch(Utf16String::CharacterCodeUnitCount(position.codeUnitPosition))
	{
	case 1:
		//Erase the code unit currently being pointed to
		postEraseIterator = Utf16String::iterator(m_codeUnitString, m_codeUnitString.erase(position.codeUnitPosition));
		break;
	case 2:
		//Erase the first code unit using the position parameter, and then erase the second code unit
		//using the iterator returned as a result of erasing the first code unit
		postEraseIterator = Utf16String::iterator(m_codeUnitString, m_codeUnitString.erase(m_codeUnitString.erase(position.codeUnitPosition)));
		break;
	default:
		//If we've reached this point, something has gone wrong
		assert(false);
		break;
	}

	return postEraseIterator;
}

Utf16String& Utf16String::erase(const size_t offset, const size_t count)
{
	assert(offset <= length());

	//Get the iterator pointing to the beginning of the range
	Utf16String::iterator firstPosition = begin() + offset;

	//Get the iterator pointing to the beginning of the range
	//Initialize the iterator to the end of the string (since the iterator has to be initialized
	//to something)
	Utf16String::iterator lastPosition = end();

	//If the last character is not at or past the end of the string, then set it to the proper
	//position
	size_t rangeEnd = offset + count;

	if(rangeEnd < length())
	{
		lastPosition = begin() + rangeEnd;
	}

	//Now that we have the iterators, call the version of this function that accepts iterators
	erase(firstPosition, lastPosition);

	return *this;
}

size_t Utf16String::find(const Utf16String& searchString, size_t offset)
{
	//Search for the sequence of code units in this string
	size_t codeUnitIndex = m_codeUnitString.find(searchString.m_codeUnitString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex = code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf16String::find_first_not_of(const Utf16String& searchString, size_t offset)
{
	//Conduct the search in the code unit string
	size_t codeUnitIndex = m_codeUnitString.find_first_not_of(searchString.m_codeUnitString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex = code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf16String::find_first_of(const Utf16String& searchString, size_t offset)
{
	assert(is_valid());
	assert(searchString.is_valid());

	size_t codePointIndex = Utf16String::npos;
	size_t currentIndex = offset;

	//Only continue if the offset is a location within the string, otherwise we just return npos
	if(offset < length())
	{
		//Iterate through each code point in this string, looking for a match
		for(Utf16String::const_iterator stringIterator = this->begin() + offset; stringIterator != this->end() &&
			codePointIndex == Utf16String::npos; ++stringIterator)
		{
			//Iterate through each code point in the search string, comparing this code point
			//with each search string code point
			for(Utf16String::const_iterator searchStringIterator = searchString.begin();
				searchStringIterator != searchString.end() && codePointIndex == Utf16String::npos;
				++searchStringIterator)
			{
				if((*stringIterator) == (*searchStringIterator))
				{
					codePointIndex = currentIndex;
				}
			}

			++currentIndex;
		}
	}

	return codePointIndex;
}

size_t Utf16String::find_last_not_of(const Utf16String& searchString, size_t offset)
{
	//Conduct the search in the code unit string
	size_t codeUnitIndex = m_codeUnitString.find_last_not_of(searchString.m_codeUnitString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex = code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf16String::find_last_of(const Utf16String& searchString, size_t offset)
{
	assert(is_valid());
	assert(searchString.is_valid());

	size_t codePointIndex = Utf16String::npos;
	size_t currentIndex = 0;

	//If the offset is past the end of the string, trim it to the last character in the string
	if(offset >= length())
	{
		offset = length() - 1;
	}

	//Putting offset + 1 in parenthesis is important here, because sometimes offset is npos, and
	//adding npos to the begin() iterator will cause a crash in most cases
	Utf16String::const_iterator endPosition = this->begin() + (offset + 1);

	//Iterate through each code point in this string, looking for a match
	for(Utf16String::const_iterator stringIterator = this->begin();
		stringIterator != endPosition; ++stringIterator)
	{
		//Iterate through each code point in the search string, comparing this code point
		//with each search string code point
		for(Utf16String::const_iterator searchStringIterator = searchString.begin();
			searchStringIterator != searchString.end();	++searchStringIterator)
		{
			if((*stringIterator) == (*searchStringIterator))
			{
				codePointIndex = currentIndex;
				break;
			}
		}

		++currentIndex;
	}

	return codePointIndex;
}

Utf16String& Utf16String::insert(const size_t index, const Utf16String& utf16String)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	m_codeUnitString.insert(codeUnitIndex, utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const std::basic_string<UInt16>& utf16String)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	m_codeUnitString.insert(codeUnitIndex, utf16String);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const UInt16* utf16String)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	m_codeUnitString.insert(codeUnitIndex, utf16String);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const UInt16* utf16String, const size_t codeUnitCount)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	m_codeUnitString.insert(codeUnitIndex, utf16String, codeUnitCount);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const wchar_t* wideString)
{
	assert(index <= length());

#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->insert(index, (UInt16*)wideString);
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wcslen(wideString);

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit code units
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t charIndex = 0; charIndex < characterCount; charIndex++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->insert(index, characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const wchar_t* wideString, const size_t codeUnitCount)
{
	assert(index <= length());

#ifdef WCHAR_T_16BIT
	//If wchar_t is 16 bits, no problem
	this->insert(index, (UInt16*)wideString, codeUnitCount);
#endif

#ifndef WCHAR_T_16BIT
	//If wchar_t is some other size (most likely 32 bits), then we'll have to convert it to 16-bit code units
	UInt16* characterBuffer = new UInt16[codeUnitCount + 1];
	const wchar_t* wideStringPtr = wideString;
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t charIndex = 0; charIndex < codeUnitCount; charIndex++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->insert(index, characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const std::wstring& wideString)
{
	assert(index <= length());

#ifdef WCHAR_T_16BIT
	//If a wchar_t is 16 bits, no problem
	this->insert(index, (UInt16*)wideString.c_str());
#endif

#ifndef WCHAR_T_16BIT
	size_t characterCount = wideString.size();

	//If it is some other size (most likely 32 bits), then we'll have to convert it to 16-bit code units
	UInt16* characterBuffer = new UInt16[characterCount + 1];
	const wchar_t* wideStringPtr = wideString.c_str();
	UInt16* characterBufferPtr = characterBuffer;

	for(size_t charIndex = 0; charIndex < characterCount; charIndex++)
	{
		*characterBufferPtr++ = (*wideStringPtr++) & 0xFFFF;
	}

	//Add a terminating 0
	*characterBufferPtr = L'\0';

	this->insert(index, characterBuffer);

	delete[] characterBuffer;
#endif

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const Utf8String& utf8String)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16String);

	m_codeUnitString.insert(codeUnitIndex, utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const std::string& utf8String)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(utf8String, utf16String);

	m_codeUnitString.insert(codeUnitIndex, utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const char* utf8String)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(string(utf8String), utf16String);

	m_codeUnitString.insert(codeUnitIndex, utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const char* utf8String, const size_t codeUnitCount)
{
	assert(index <= length());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	Utf16String utf16String;

	//Convert the UTF-8 string to a UTF-16 string and append it
	UtfStringConverter::Utf8ToUtf16String(string(utf8String, codeUnitCount), utf16String);

	m_codeUnitString.insert(codeUnitIndex, utf16String.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::insert(const size_t index, const Utf16Char& utf16Character)
{
	assert(index <= length());
	assert(utf16Character.is_valid());

	size_t codeUnitIndex = npos;

	//code_unit_index() expects an index within the bounds of the string, so if we get an
	//index that is one past the bounds of the string, we need to set the code unit index
	//to the end of the string
	if(index == length())
	{
		codeUnitIndex = size();
	}
	else
	{
		codeUnitIndex = code_unit_index(index);
	}

	if(utf16Character.size() == 2)
	{
		m_codeUnitString.insert(codeUnitIndex, &utf16Character[1], 1);
	}

	m_codeUnitString.insert(codeUnitIndex, &utf16Character[0], 1);

	return *this;
}


bool Utf16String::is_valid() const
{
	bool isValid = true;

	//Iterate through the code units, validating each code point
	basic_string<UInt16>::const_iterator stringIterator = m_codeUnitString.begin();

	while(stringIterator != m_codeUnitString.end() && isValid)
	{
		//Figure out the number of code units in the code point we are pointing to
		size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(stringIterator);

		//If this is the end of the string and the code unit count is 2, there are obviously not two
		//code units in this code point, which indicates that we have the only the first code unit
		//of a surrogate pair.  So we need to check for this so that Utf16Char doesn't attempt to
		//read past the end of the string when constructing itself
		if(codeUnitCount == 2 && stringIterator == m_codeUnitString.end() - 1)
		{
			isValid = false;
		}
		else
		{
			isValid = IsValidCharacter(Utf16Char(stringIterator, codeUnitCount));

			if(codeUnitCount != 0)
			{
				stringIterator += codeUnitCount;
			}
			else
			{
				++stringIterator;
			}
		}
	}

	return isValid;
}

size_t Utf16String::length() const
{
	size_t codePointCount = 0;
	const UInt16* bufferPointer = m_codeUnitString.c_str();

	while(*bufferPointer != 0)
	{
		//Check for a surrogate pair
		if(*bufferPointer >= HighCodeUnitBaseNumber && *(bufferPointer + 1) >= LowCodeUnitBaseNumber)
			bufferPointer += 2;
		else
			bufferPointer++;

		codePointCount++;
	}

	return codePointCount;
}

void Utf16String::push_back(const Utf16Char& character)
{
	append(character);
}

Utf16String::reverse_iterator Utf16String::rbegin()
{
	return Utf16String::reverse_iterator(m_codeUnitString, m_codeUnitString.rbegin());
}

Utf16String::const_reverse_iterator Utf16String::rbegin() const
{
	return Utf16String::const_reverse_iterator(m_codeUnitString, m_codeUnitString.rbegin());
}

Utf16String::reverse_iterator Utf16String::rend()
{
	return Utf16String::reverse_iterator(m_codeUnitString, m_codeUnitString.rend());
}

Utf16String::const_reverse_iterator Utf16String::rend() const
{
	return Utf16String::const_reverse_iterator(m_codeUnitString, m_codeUnitString.rend());
}

Utf16String& Utf16String::replace(const size_t position, const size_t count, const Utf16String& replacementString)
{
	assert(position <= length());

	this->erase(position, count);
	this->insert(position, replacementString);

	return *this;
}

Utf16String& Utf16String::replace(const size_t position, const size_t count, const size_t characterCount,
								  const Utf16Char& character)
{
	assert(position <= length());

	//Remove the string section
	this->erase(position, count);

	//Insert the new character as many times as called for
	for(size_t count = 0; count < characterCount; ++count)
	{
		this->insert(position, character);
	}

	return *this;
}

Utf16String& Utf16String::replace(Utf16String::iterator beginIterator, Utf16String::iterator endIterator,
	const Utf16String& replacementString)
{
	m_codeUnitString.replace(beginIterator.codeUnitPosition, endIterator.codeUnitPosition,
		replacementString.m_codeUnitString);

	return *this;
}

Utf16String& Utf16String::replace(Utf16String::iterator beginIterator, Utf16String::iterator endIterator,
	const size_t characterCount, const Utf16Char& character)
{
	//Construct a basic_string consisting of the code units to be inserted
	basic_string<UInt16> insertString;

	for(size_t count = 0; count < characterCount; ++count)
	{
		assert(character.size() == 1 || character.size() == 2);

		insertString.append(1, character[0]);

		if(character.size() == 2)
		{
			insertString.append(1, character[1]);
		}
	}

	m_codeUnitString.replace(beginIterator.codeUnitPosition, endIterator.codeUnitPosition,
		insertString);

	return *this;
}

size_t Utf16String::rfind(const Utf16String& searchString, size_t offset)
{
	//Search for the sequence of code units in this string
	size_t codeUnitIndex = m_codeUnitString.rfind(searchString.m_codeUnitString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex = code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf16String::size() const
{
	return m_codeUnitString.size();
}

Utf16String Utf16String::substr(const size_t offset, const size_t count)
{
	assert(offset < length());

	Utf16String subString;

	size_t codePointCount = 0;
	const UInt16* bufferPointer = m_codeUnitString.c_str();

	//Calculate the maximum substring index using the offset and count, making sure not to
	//cause size_t to overflow
	size_t maxIndex = (offset + count) - 1;

	//If adding both the count and offset would cause an overflow, just set the max index to
	//the maximum possible value for size_t
	if((npos - count < offset) || (npos - offset < count))
	{
		maxIndex = npos - 1;
	}

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the offset
	while(*bufferPointer != 0 && codePointCount <= maxIndex)
	{
		//Check for a surrogate pair
		if(*bufferPointer >= HighCodeUnitBaseNumber && *(bufferPointer + 1) >= LowCodeUnitBaseNumber)
		{
			//If we are at the offset of the start of the substring, add the current code point to the substring
			if(codePointCount >= offset)
			{
				subString.append(bufferPointer, 1);
				subString.append(bufferPointer + 1, 1);
			}

			bufferPointer += 2;
		}
		else
		{
			//If we are at the offset of the start of the substring, add the current code point to the substring
			if(codePointCount >= offset)
			{
				subString.append(bufferPointer, 1);
			}

			bufferPointer++;
		}

		codePointCount++;
	}

	return subString;
}

void Utf16String::swap(Utf16String& utf16String)
{
	m_codeUnitString.swap(utf16String.m_codeUnitString);
}

/*Operators*/

Utf16CharReference Utf16String::operator[](size_t index)
{
	assert(index < length());

	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	basic_string<UInt16>::iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		UInt16 currentCodeUnit = *stringIterator;
		UInt16 nextCodeUnit = L'\x0000';

		//Check to prevent us from reading beyond the end of the string
		if(stringIterator + 1 != m_codeUnitString.end())
		{
			nextCodeUnit = *(stringIterator + 1);
		}

		bool surrogatePair = currentCodeUnit >= HighCodeUnitRangeBegin && 
				currentCodeUnit <= HighCodeUnitRangeEnd && 
				nextCodeUnit >= LowCodeUnitRangeBegin &&
				nextCodeUnit <= LowCodeUnitRangeEnd;

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			//Check for a surrogate pair
			if(surrogatePair)
			{
				codeUnitCount = 2;
			}
			else
			{
				codeUnitCount = 1;
			}

			break;
		}

		//Check for a surrogate pair
		if(surrogatePair)
			stringIterator += 2;
		else
			stringIterator++;

		codePointCount++;
	}

	return Utf16CharReference(m_codeUnitString, stringIterator, codeUnitCount);
}

const Utf16Char Utf16String::operator[](size_t index) const
{
	assert(index < length());

	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	basic_string<UInt16>::const_iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		UInt16 currentCodeUnit = *stringIterator;
		UInt16 nextCodeUnit = L'\x0000';

		//Check to prevent us from reading beyond the end of the string
		if(stringIterator + 1 != m_codeUnitString.end())
		{
			nextCodeUnit = *(stringIterator + 1);
		}

		bool surrogatePair = currentCodeUnit >= HighCodeUnitRangeBegin && 
				currentCodeUnit <= HighCodeUnitRangeEnd && 
				nextCodeUnit >= LowCodeUnitRangeBegin &&
				nextCodeUnit <= LowCodeUnitRangeEnd;

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			//Check for a surrogate pair
			if(surrogatePair)
			{
				codeUnitCount = 2;
			}
			else
			{
				codeUnitCount = 1;
			}

			break;
		}

		//Check for a surrogate pair
		if(surrogatePair)
			stringIterator += 2;
		else
			stringIterator++;

		codePointCount++;
	}

	return Utf16Char(stringIterator, codeUnitCount);
}

bool Utf16String::operator==(const Utf16String& otherString) const
{
	return m_codeUnitString == otherString.m_codeUnitString;
}

bool Utf16String::operator!=(const Utf16String& otherString) const
{
	return m_codeUnitString != otherString.m_codeUnitString;
}

bool Utf16String::operator<(const Utf16String& otherString) const
{
	//Since surrogate code units range from 0xD800 - 0xDFFF, the code units in the range
	//0xE000 - 0xFFFF are greater in value than the surrogate code units, but have a lesser
	//code point value. This means that we can't rely on the basic_string "<" operator implementation,
	//which compares code unit values.  So we will have to compare code point values instead.
	return (this->compare(otherString) < 0);
}

bool Utf16String::operator<=(const Utf16String& otherString) const
{
	//Since surrogate code units range from 0xD800 - 0xDFFF, the code units in the range
	//0xE000 - 0xFFFF are greater in value than the surrogate code units, but have a lesser
	//code point value. This means that we can't rely on the basic_string "<=" operator implementation,
	//which compares code unit values.  So we will have to compare code point values instead.
	return (this->compare(otherString) <= 0);
}

bool Utf16String::operator>(const Utf16String& otherString) const
{
	//Since surrogate code units range from 0xD800 - 0xDFFF, the code units in the range
	//0xE000 - 0xFFFF are greater in value than the surrogate code units, but have a lesser
	//code point value. This means that we can't rely on the basic_string ">" operator implementation,
	//which compares code unit values.  So we will have to compare code point values instead.
	return (this->compare(otherString) > 0);
}

bool Utf16String::operator>=(const Utf16String& otherString) const
{
	//Since surrogate code units range from 0xD800 - 0xDFFF, the code units in the range
	//0xE000 - 0xFFFF are greater in value than the surrogate code units, but have a lesser
	//code point value. This means that we can't rely on the basic_string ">=" operator implementation,
	//which compares code unit values.  So we will have to compare code point values instead.
	return (this->compare(otherString) >= 0);
}

Utf16String::operator const std::basic_string<UInt16>() const
{
	return m_codeUnitString;
}

Utf16String::operator std::basic_string<UInt16>()
{
	return m_codeUnitString;
}

/*Static Functions*/

size_t Utf16String::CharacterCodeUnitCount(const std::wstring::const_iterator& stringIterator)
{
	int codeUnitCount = 0;

	//Get the first code unit from the iterator
	wchar_t firstCodeUnit = *stringIterator;

	//High code units are in the range 0xD800 - 0xDBFF
	if(firstCodeUnit >= HighCodeUnitRangeBegin && 
		firstCodeUnit <= HighCodeUnitRangeEnd)
	{
		codeUnitCount = 2;
	}

	//Low code units are in the range 0xDC00 - 0xDFFF
	else if(firstCodeUnit >= LowCodeUnitRangeBegin && 
		firstCodeUnit <= LowCodeUnitRangeEnd)
	{
		codeUnitCount = 0;
	}
	else
	{
		codeUnitCount = 1;
	}

	return codeUnitCount;
}

size_t Utf16String::CharacterCodeUnitCount(Utf16String::const_iterator& stringIterator)
{
	int codeUnitCount = 0;

	//Get the first code unit from the iterator
	assert((*stringIterator).size() > 0);

	const UInt16 firstCodeUnit = (*stringIterator)[0];

	//High code units are in the range 0xD800 - 0xDBFF
	if(firstCodeUnit >= HighCodeUnitRangeBegin && 
		firstCodeUnit <= HighCodeUnitRangeEnd)
	{
		codeUnitCount = 2;
	}
	//Low code units are in the range 0xDC00 - 0xDFFF
	else if(firstCodeUnit >= LowCodeUnitRangeBegin && 
		firstCodeUnit <= LowCodeUnitRangeEnd)
	{
		codeUnitCount = 0;
	}
	else
	{
		codeUnitCount = 1;
	}

	return codeUnitCount;
}

size_t Utf16String::CharacterCodeUnitCount(const std::basic_string<UInt16>::const_iterator& stringIterator)
{
	int codeUnitCount = 0;

	//Get the first code unit from the iterator
	UInt16 firstCodeUnit = *stringIterator;

	//High code units are in the range 0xD800 - 0xDBFF
	if(firstCodeUnit >= HighCodeUnitRangeBegin && 
		firstCodeUnit <= HighCodeUnitRangeEnd)
	{
		codeUnitCount = 2;
	}
	//Low code units are in the range 0xDC00 - 0xDFFF
	else if(firstCodeUnit >= LowCodeUnitRangeBegin && 
		firstCodeUnit <= LowCodeUnitRangeEnd)
	{
		codeUnitCount = 0;
	}
	else
	{
		codeUnitCount = 1;
	}

	return codeUnitCount;
}

size_t Utf16String::CharacterCodeUnitCount(const std::basic_string<UInt16>::const_reverse_iterator& stringIterator)
{
	int codeUnitCount = 0;

	//Get the first code unit from the reverse iterator
	UInt16 firstCodeUnit = *stringIterator;

	//Since this is a reverse iterator, we have to check for the low code unit first and then for the
	//high code unit

	//Low code units are in the range 0xDC00 - 0xDFFF
	if(firstCodeUnit >= LowCodeUnitRangeBegin && 
		firstCodeUnit <= LowCodeUnitRangeEnd)
	{
		codeUnitCount = 2;
	}
	//High code units are in the range 0xD800 - 0xDBFF
	else if(firstCodeUnit >= HighCodeUnitRangeBegin && 
		firstCodeUnit <= HighCodeUnitRangeEnd)
	{
		codeUnitCount = 0;
	}
	else
	{
		codeUnitCount = 1;
	}

	return codeUnitCount;
}

size_t Utf16String::CharacterCodeUnitCount(const UInt16* characterPointer)
{
	int codeUnitCount = 0;

	//High code units are in the range 0xD800 - 0xDBFF
	if(*characterPointer >= HighCodeUnitRangeBegin && 
		*characterPointer <= HighCodeUnitRangeEnd)
	{
		codeUnitCount = 2;
	}
	//Low code units are in the range 0xDC00 - 0xDFFF
	else if(*characterPointer >= LowCodeUnitRangeBegin && 
		*characterPointer <= LowCodeUnitRangeEnd)
	{
		codeUnitCount = 0;
	}
	else
	{
		codeUnitCount = 1;
	}

	return codeUnitCount;
}

UInt32 Utf16String::DecodeCharacter(const Utf16Char& utf16Character)
{
	size_t characterSize = utf16Character.size();

	assert(characterSize > 0 && characterSize <= 2);

	UInt16 characterBuffer[2];
	characterBuffer[0] = utf16Character[0];

	if(characterSize == 2)
	{
		characterBuffer[1] = utf16Character[1];
	}

	return DecodeCharacter((UInt16*)&characterBuffer, characterSize);
}

UInt32 Utf16String::DecodeCharacter(const UInt16* characterPointer, const size_t codeUnitCount)
{
	//Assert that characterPointer is actually pointing at something
	assert(characterPointer != NULL);
	//Assert that we have 1 or 2 code units
	assert(codeUnitCount >= 1 && codeUnitCount <= 2);
	//Assert that the character is a valid UTF-16 character
	assert(IsValidCharacter(characterPointer, codeUnitCount));

	UInt32 codePoint;

	if(codeUnitCount == 1)
	{
		codePoint = *characterPointer;
	}

	else
	{
		codePoint = (((*characterPointer & ~HighCodeUnitBaseNumber) << 10) |
			(*(characterPointer + 1) & ~LowCodeUnitBaseNumber)) + 0x10000;
	}

	return codePoint;
}

Utf16Char Utf16String::EncodeCharacter(const UInt32 codePoint)
{
	//Assert that the code point is a valid Unicode code point (000000-10FFFF)
	assert(codePoint <= 0x10FFFF);

	Utf16Char /*basic_string<UInt16>*/ utf16Character;

	//Any code point greater than or equal to 0xD800 gets encoded as two code units
	if(codePoint >= 0xD800)
	{
		//Now we need to do the magic to convert the 32-bit code unit to two 16-bit code units
		//Get the offset of the code point from the code point 0x10000
		UInt32 codePointOffset = codePoint - 0x10000;

		//Assert that the offset is 20 bits or less; otherwise, the code point is not valid
		assert((codePointOffset & 0x000FFFFF) == codePointOffset);

		//Now split the offset into two 10-bit values, then bitwise OR the two values by the magical numbers
		//to form the final 16-bit code units
		UInt16 highCodeUnit = (UInt16)(((codePointOffset & 0x000FFC00) >> 10) | HighCodeUnitBaseNumber);
		UInt16 lowCodeUnit = (UInt16)((codePointOffset & 0x000003FF) | LowCodeUnitBaseNumber);

		utf16Character[0] = highCodeUnit;
		utf16Character[1] = lowCodeUnit;
	}

	//Otherwise, it's a single code unit and a simple assignment operation
	else
	{
		UInt16 codeUnit = (UInt16)codePoint;

		utf16Character[0] = codeUnit;
	}

	return utf16Character;
}

bool Utf16String::IsValidCharacter(const Utf16Char& utf16Character)
{
	size_t characterSize = utf16Character.size();

	UInt16 characterBuffer[2];

	if(characterSize > 0)
	{
		characterBuffer[0] = utf16Character[0];
	}

	if(characterSize == 2)
	{
		characterBuffer[1] = utf16Character[1];
	}

	return IsValidCharacter((UInt16*)&characterBuffer, characterSize);
}

bool Utf16String::IsValidCharacter(const UInt16* characterPointer, const size_t codeUnitCount)
{
	//Assert that characterPointer is actually pointing at something
	assert(characterPointer != NULL);

	bool isValid = false;

	//Validate a single code unit character
	if(codeUnitCount == 1)
	{
		//A single code unit is valid if it is outside the range D800-DFFF
		if(*characterPointer < 0xD800 || *characterPointer > 0xDFFF)
			isValid = true;

		//Check for 0xFFFE and 0xFFFF, which are BOM code points
		if(*characterPointer == 0xFFFE || *characterPointer == 0xFFFF)
		{
			isValid = false;
		}

		//There is a range of 32 code points (0xFDD0 - 0xFDEF) designated as non-characters that are
		//reserved for implementation-specific use. These are invalid in Unicode strings, so we need
		//to check for them
		if(*characterPointer >= 0xFDD0 && *characterPointer <= 0xFDEF)
		{
			isValid = false;
		}

	}

	//Validate a double code unit character
	else if(codeUnitCount == 2)
	{
		//A double code unit character is valid if the first code unit is in the range D800-DBFF,
		//and the second code unit is in the range DC00-DFFF.
		//There are 32 paired surrogates designated as non-characters that are
		//reserved for implementation-specific use. These are invalid in Unicode strings, so we need
		//to check for them.  The 32 code points all have second code unit of 0xDFFE or 0xDFFF.
		//Unfortunately, however, the first code units of these characters aren't in a nice range.
		//The first code units occur in a series starting at D83F and occur in increments of 40.
		//So, instead of testing for each individual code unit, we can to subtract D83F from the first
		//code unit, divide by 40, and if the code unit is the code unit we are looking for, the result
		//will be between 0 and F.

		//Check that the first and second code unit are within expected range
		if(*characterPointer >= 0xD800 && *characterPointer <= 0xDBFF &&
			*(characterPointer + 1) >= 0xDC00 && *(characterPointer + 1) <= 0xDFFF)
		{
			//Now check to see if the code point is one of the 32 invalid code points within the
			//expected range
			if(*(characterPointer + 1) < 0xDFFE || ((*characterPointer - 0xD83F) / 0x40) > 0x0F)
			{
				isValid = true;
			}
		}
	}

	return isValid;
}


bool Utf16String::IsWhitespace(UInt16 utf16Character)
{
	bool isWhitespace = false;

	//It seems to me that there should be a more efficient way of doing this, but I can't think of anything
	if(utf16Character == 0x0020 || utf16Character == 0x0009 || utf16Character == 0x000D ||
		utf16Character == 0x000A ||	utf16Character == 0x00A0 || utf16Character == 0x1680 ||
		utf16Character == 0x180E || (utf16Character >= 0x2000 && utf16Character <= 0x2009) ||
		utf16Character == 0x200A || utf16Character == 0x202F || utf16Character == 0x205F ||
		utf16Character == 0x3000 || utf16Character == 0x2028 || utf16Character == 0x2029)
	{
		isWhitespace = true;
	}

	return isWhitespace;
}

bool Utf16String::IsWhitespace(const Utf16Char& utf16Character)
{
	bool isWhitespace = false;

	//It seems to me that there should be a more efficient way of doing this, but I can't think of anything
	if(utf16Character[0] == 0x0020 || utf16Character[0] == 0x0009 || utf16Character[0] == 0x000D ||
		utf16Character[0] == 0x000A ||	utf16Character[0] == 0x00A0 || utf16Character[0] == 0x1680 ||
		utf16Character[0] == 0x180E || (utf16Character[0] >= 0x2000 && utf16Character[0] <= 0x2009) ||
		utf16Character[0] == 0x200A || utf16Character[0] == 0x202F || utf16Character[0] == 0x205F ||
		utf16Character[0] == 0x3000 || utf16Character[0] == 0x2028 || utf16Character[0] == 0x2029)
	{
		isWhitespace = true;
	}

	return isWhitespace;
}

/*Iterator Implementations*/

/*iterator Implementation*/
Utf16String::iterator::iterator(std::basic_string<UInt16>& basicString,
	const std::basic_string<UInt16>::iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacterReference(NULL)
{

}

Utf16String::iterator::iterator(const iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition),
	currentCharacterReference(NULL)
{

}

Utf16String::iterator::iterator(const Utf16String::reverse_iterator& reverseIterator) :
	codeUnitString(reverseIterator.codeUnitString), codeUnitPosition(reverseIterator.codeUnitPosition.base()),
	currentCharacterReference(NULL)
{
	//We have to move the position to the end of the code point due this being a reverse iterator
	switch(Utf16String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition))
	{
	case 1:
		codeUnitPosition -= 1;
		break;
	case 2:
		codeUnitPosition -= 2;
		break;
	default:
		//If we reach this point, something went wrong
		assert(false);
		break;
	}
}

Utf16String::iterator::~iterator()
{
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}
}

Utf16String::iterator& Utf16String::iterator::operator=(const iterator& otherIterator)
{
	codeUnitPosition = otherIterator.codeUnitPosition;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

bool Utf16String::iterator::operator==(const iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf16String::iterator::operator!=(const Utf16String::iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf16String::iterator::operator<(const iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf16String::iterator::operator<=(const iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf16String::iterator::operator>(const iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf16String::iterator::operator>=(const iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf16String::iterator& Utf16String::iterator::operator++()
{
	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::iterator Utf16String::iterator::operator++(int)
{
	Utf16String::iterator iteratorCopy(*this);

	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf16String::iterator& Utf16String::iterator::operator+=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator++();
	}

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::iterator Utf16String::iterator::operator+(size_t offset)
{
	Utf16String::iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf16String::iterator& Utf16String::iterator::operator--()
{
	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::iterator Utf16String::iterator::operator--(int)
{
	Utf16String::iterator iteratorCopy(*this);

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf16String::iterator& Utf16String::iterator::operator-=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator--();
	}

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::iterator Utf16String::iterator::operator-(size_t offset)
{
	Utf16String::iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

Utf16CharReference Utf16String::iterator::operator*()
{
	if(currentCharacterReference == NULL)
	{
		currentCharacterReference = new Utf16CharReference(codeUnitString, codeUnitPosition,
			Utf16String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return *currentCharacterReference;
}

Utf16CharReference* Utf16String::iterator::operator->()
{
	if(currentCharacterReference == NULL)
	{
		currentCharacterReference = new Utf16CharReference(codeUnitString, codeUnitPosition,
			Utf16String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return currentCharacterReference;
}


/*const_iterator Implementation*/
Utf16String::const_iterator::const_iterator(const std::basic_string<UInt16>& basicString,
	const std::basic_string<UInt16>::const_iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacter(NULL)
{
}

Utf16String::const_iterator::const_iterator(const Utf16String::iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)

{
	if(otherIterator.currentCharacterReference == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf16Char();
		*currentCharacter = *otherIterator.currentCharacterReference;
	}
}

Utf16String::const_iterator::const_iterator(const Utf16String::const_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)
{
	if(otherIterator.currentCharacter == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf16Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}
}

Utf16String::const_iterator::const_iterator(const Utf16String::const_reverse_iterator& reverseIterator) :
	codeUnitString(reverseIterator.codeUnitString), codeUnitPosition(reverseIterator.codeUnitPosition.base()),
	currentCharacter(NULL)
{
	//We have to move the position to the end of the code point due this being a reverse iterator
	switch(Utf16String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition))
	{
	case 1:
		codeUnitPosition -= 1;
		break;
	case 2:
		codeUnitPosition -= 2;
		break;
	default:
		//If we reach this point, something went wrong
		assert(false);
		break;
	}
}

Utf16String::const_iterator::~const_iterator()
{
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}
}

Utf16String::const_iterator& Utf16String::const_iterator::operator=(const const_iterator& otherIterator)
{
	codeUnitPosition = otherIterator.codeUnitPosition;

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	if(otherIterator.currentCharacter != NULL)
	{
		currentCharacter = new Utf16Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}

	return *this;
}

bool Utf16String::const_iterator::operator==(const const_iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf16String::const_iterator::operator!=(const const_iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf16String::const_iterator::operator<(const const_iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf16String::const_iterator::operator<=(const const_iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf16String::const_iterator::operator>(const const_iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf16String::const_iterator::operator>=(const const_iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf16String::const_iterator& Utf16String::const_iterator::operator++()
{
	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the rcurrent character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf16String::const_iterator Utf16String::const_iterator::operator++(int)
{
	Utf16String::const_iterator iteratorCopy(*this);

	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;

}

Utf16String::const_iterator& Utf16String::const_iterator::operator+=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator++();
	}

	//Destroy the reference to the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf16String::const_iterator Utf16String::const_iterator::operator+(size_t offset)
{
	Utf16String::const_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf16String::const_iterator& Utf16String::const_iterator::operator--()
{
	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the rcurrent character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf16String::const_iterator Utf16String::const_iterator::operator--(int)
{
	Utf16String::const_iterator iteratorCopy(*this);

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;
}

Utf16String::const_iterator& Utf16String::const_iterator::operator-=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator--();
	}

	//Destroy the reference to the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf16String::const_iterator Utf16String::const_iterator::operator-(size_t offset)
{
	Utf16String::const_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

const Utf16Char Utf16String::const_iterator::operator*()
{
	if(currentCharacter == NULL)
	{
		currentCharacter = new Utf16Char(codeUnitPosition,
			Utf16String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return *currentCharacter;
}

const Utf16Char* Utf16String::const_iterator::operator->()
{
	if(currentCharacter == NULL)
	{
		currentCharacter = new Utf16Char(codeUnitPosition,
			Utf16String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return currentCharacter;
}

/*reverse_iterator Implementation*/
Utf16String::reverse_iterator::reverse_iterator(std::basic_string<UInt16>& basicString,
	const std::basic_string<UInt16>::reverse_iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacterReference(NULL)
{
}

Utf16String::reverse_iterator::reverse_iterator(const Utf16String::reverse_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition),
	currentCharacterReference(NULL)

{
}

Utf16String::reverse_iterator::reverse_iterator(const Utf16String::iterator& iterator) :
	codeUnitString(iterator.codeUnitString), codeUnitPosition(iterator.codeUnitPosition),
	currentCharacterReference(NULL)
{
	//We have to move the position to the end of the code point due this being a reverse iterator
	switch(Utf16String::CharacterCodeUnitCount(iterator.codeUnitPosition))
	{
	case 1:
		codeUnitPosition -= 1;
		break;
	case 2:
		codeUnitPosition -= 2;
		break;
	default:
		//If we reach this point, something went wrong
		assert(false);
		break;
	}
}

Utf16String::reverse_iterator& Utf16String::reverse_iterator::operator=(const reverse_iterator& otherIterator)
{
	codeUnitString = otherIterator.codeUnitString;
	codeUnitPosition = otherIterator.codeUnitPosition;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::reverse_iterator::~reverse_iterator()
{
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}
}

bool Utf16String::reverse_iterator::operator==(const reverse_iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf16String::reverse_iterator::operator!=(const reverse_iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf16String::reverse_iterator::operator<(const reverse_iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf16String::reverse_iterator::operator<=(const reverse_iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf16String::reverse_iterator::operator>(const reverse_iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf16String::reverse_iterator::operator>=(const reverse_iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf16String::reverse_iterator& Utf16String::reverse_iterator::operator++()
{
	//Increment the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::reverse_iterator Utf16String::reverse_iterator::operator++(int)
{
	Utf16String::reverse_iterator iteratorCopy(*this);

	//Increment the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf16String::reverse_iterator& Utf16String::reverse_iterator::operator+=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator++();
	}

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::reverse_iterator Utf16String::reverse_iterator::operator+(size_t offset)
{
	Utf16String::reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf16String::reverse_iterator& Utf16String::reverse_iterator::operator--()
{
	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition - 1);

	//If the previous code unit was only a partial surrogate pair, then this character must be composed
	//of two code units
	if(codeUnitCount == 0)
	{
		codeUnitCount = 2;

		//Assert that we are making the correct assumption, which will be correct if the string is valid
		assert(Utf16String::CharacterCodeUnitCount(codeUnitPosition - 2) == (size_t)2);
	}

	codeUnitPosition -= codeUnitCount;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::reverse_iterator Utf16String::reverse_iterator::operator--(int)
{
	Utf16String::reverse_iterator iteratorCopy(*this);

	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition - 1);

	//If the previous code unit was only a partial surrogate pair, then this character must be composed
	//of two code units
	if(codeUnitCount == 0)
	{
		codeUnitCount = 2;

		//Assert that we are making the correct assumption, which will be correct if the string is valid
		assert(Utf16String::CharacterCodeUnitCount(codeUnitPosition - 2) == (size_t)2);
	}

	codeUnitPosition -= codeUnitCount;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf16String::reverse_iterator& Utf16String::reverse_iterator::operator-=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator--();
	}

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf16String::reverse_iterator Utf16String::reverse_iterator::operator-(size_t offset)
{
	Utf16String::reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

Utf16CharReference Utf16String::reverse_iterator::operator*()
{
	if(currentCharacterReference == NULL)
	{
		size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		basic_string<UInt16>::iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacterReference = new Utf16CharReference(codeUnitString, forwardIterator, codeUnitCount);
	}

	return *currentCharacterReference;
}

Utf16CharReference* Utf16String::reverse_iterator::operator->()
{
	if(currentCharacterReference == NULL)
	{
		size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		basic_string<UInt16>::iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacterReference = new Utf16CharReference(codeUnitString, forwardIterator, codeUnitCount);
	}

	return currentCharacterReference;
}

/*const_reverse_iterator Implementation*/
Utf16String::const_reverse_iterator::const_reverse_iterator(const std::basic_string<UInt16>& basicString,
	const std::basic_string<UInt16>::const_reverse_iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacter(NULL)
{

}

Utf16String::const_reverse_iterator::const_reverse_iterator(const Utf16String::reverse_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)
{
	if(otherIterator.currentCharacterReference == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf16Char();
		*currentCharacter = *otherIterator.currentCharacterReference;
	}
}

Utf16String::const_reverse_iterator::const_reverse_iterator(const Utf16String::const_reverse_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)
{
	if(otherIterator.currentCharacter == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf16Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}

}

Utf16String::const_reverse_iterator::const_reverse_iterator(const Utf16String::const_iterator& iterator) :
	codeUnitString(iterator.codeUnitString), codeUnitPosition(iterator.codeUnitPosition),
	currentCharacter(NULL)
{
	//We have to move the position to the end of the code point due this being a reverse iterator
	switch(Utf16String::CharacterCodeUnitCount(iterator.codeUnitPosition))
	{
	case 1:
		codeUnitPosition -= 1;
		break;
	case 2:
		codeUnitPosition -= 2;
		break;
	default:
		//If we reach this point, something went wrong
		assert(false);
		break;
	}
}

Utf16String::const_reverse_iterator::~const_reverse_iterator()
{
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}
}

Utf16String::const_reverse_iterator& Utf16String::const_reverse_iterator::operator=(const const_reverse_iterator& otherIterator)
{
	codeUnitPosition = otherIterator.codeUnitPosition;

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	if(otherIterator.currentCharacter != NULL)
	{
		currentCharacter = new Utf16Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}

	return *this;
}

bool Utf16String::const_reverse_iterator::operator==(const const_reverse_iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf16String::const_reverse_iterator::operator!=(const const_reverse_iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf16String::const_reverse_iterator::operator<(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf16String::const_reverse_iterator::operator<=(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf16String::const_reverse_iterator::operator>(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf16String::const_reverse_iterator::operator>=(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf16String::const_reverse_iterator& Utf16String::const_reverse_iterator::operator++()
{
	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;

}

Utf16String::const_reverse_iterator Utf16String::const_reverse_iterator::operator++(int)
{
	Utf16String::const_reverse_iterator iteratorCopy(*this);

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf16String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;
}

Utf16String::const_reverse_iterator& Utf16String::const_reverse_iterator::operator+=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator++();
	}

	//Destroy the reference to the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf16String::const_reverse_iterator Utf16String::const_reverse_iterator::operator+(size_t offset)
{
	Utf16String::const_reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf16String::const_reverse_iterator& Utf16String::const_reverse_iterator::operator--()
{
	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition - 1);

	//If the previous code unit was only a partial surrogate pair, then this character must be composed
	//of two code units
	if(codeUnitCount == 0)
	{
		codeUnitCount = 2;

		//Assert that we are making the correct assumption, which will be correct if the string is valid
		assert(Utf16String::CharacterCodeUnitCount(codeUnitPosition - 2) == (size_t)2);
	}

	codeUnitPosition -= codeUnitCount;

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf16String::const_reverse_iterator Utf16String::const_reverse_iterator::operator--(int)
{
	Utf16String::const_reverse_iterator iteratorCopy(*this);

	size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition - 1);

	//If the previous code unit was only a partial surrogate pair, then this character must be composed
	//of two code units
	if(codeUnitCount == 0)
	{
		codeUnitCount = 2;

		//Assert that we are making the correct assumption, which will be correct if the string is valid
		assert(Utf16String::CharacterCodeUnitCount(codeUnitPosition - 2) == (size_t)2);
	}

	codeUnitPosition -= codeUnitCount;

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;
}

Utf16String::const_reverse_iterator& Utf16String::const_reverse_iterator::operator-=(size_t offset)
{
	for(size_t count = 0; count < offset; ++count)
	{
		operator--();
	}

	//Destroy the reference to the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf16String::const_reverse_iterator Utf16String::const_reverse_iterator::operator-(size_t offset)
{
	Utf16String::const_reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

const Utf16Char Utf16String::const_reverse_iterator::operator*()
{
	if(currentCharacter == NULL)
	{
		size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		basic_string<UInt16>::const_iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacter = new Utf16Char(forwardIterator, codeUnitCount);
	}

	return *currentCharacter;
}

const Utf16Char* Utf16String::const_reverse_iterator::operator->()
{
	if(currentCharacter == NULL)
	{
		size_t codeUnitCount = Utf16String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		basic_string<UInt16>::const_iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacter = new Utf16Char(forwardIterator, codeUnitCount);
	}

	return currentCharacter;
}
