#include <utfstring/UtfString.h>

//These includes are only needed for this code file and don't need 
//to be located in the library header file
#include <assert.h>
#include <sstream>

using namespace UtfString;
using namespace std;

/*Utf8String Definition*/

/*Static Constants*/
const size_t Utf8String::npos = (size_t)-1;

/*Constructors*/

Utf8String::Utf8String()
{

}

Utf8String::Utf8String(const Utf8String& utf8String)
{
	m_codeUnitString.assign(utf8String.m_codeUnitString);
}

Utf8String::Utf8String(std::string utf8String)
{
	m_codeUnitString.assign(utf8String);
}

Utf8String::Utf8String(const char* utf8String)
{
	m_codeUnitString.assign(utf8String);
}

Utf8String::Utf8String(const char* utf8String, size_t characterCount)
{
	m_codeUnitString.assign(utf8String, characterCount);
}

Utf8String::Utf8String(const Utf16String& utf16String)
{
	//Convert the UTF-16 string to a UTF-8 string and assign it to this object
	UtfStringConverter::Utf16ToUtf8String(utf16String, *this);
}

Utf8String::Utf8String(const wchar_t* wideString)
{
	//Convert the UTF-16 string to a UTF-8 string and assign it to this object
	UtfStringConverter::Utf16ToUtf8String(Utf16String(wideString), *this);
}

Utf8String::Utf8String(const wchar_t* wideString, const size_t characterCount)
{
	//Convert the UTF-16 string to a UTF-8 string and assign it to this object
	UtfStringConverter::Utf16ToUtf8String(Utf16String(wideString, characterCount), *this);
}

Utf8String::Utf8String(const std::wstring& wideString)
{
	//Convert the UTF-16 string to a UTF-8 string and assign it to this object
	UtfStringConverter::Utf16ToUtf8String(Utf16String(wideString), *this);
}

Utf8String::~Utf8String()
{
}

/*Member Functions*/

Utf8String& Utf8String::append(const Utf8String& utf8String)
{
	m_codeUnitString.append(utf8String.m_codeUnitString);

	return *this;
}

Utf8String& Utf8String::append(const std::string& utf8String)
{
	m_codeUnitString.append(utf8String);

	return *this;
}

Utf8String& Utf8String::append(const char* utf8String)
{
	m_codeUnitString.append(utf8String);

	return *this;
}

Utf8String& Utf8String::append(const char* utf8String, const size_t codeUnitCount)
{
	m_codeUnitString.append(utf8String, codeUnitCount);

	return *this;
}

Utf8String& Utf8String::append(const wchar_t* wideString)
{
	this->append(Utf16String(wideString));

	return *this;
}

Utf8String& Utf8String::append(const wchar_t* wideString, const size_t characterCount)
{
	this->append(Utf16String(wideString, characterCount));

	return *this;
}

Utf8String& Utf8String::append(const std::wstring& wideString)
{
	this->append(Utf16String(wideString));

	return *this;
}

Utf8String& Utf8String::append(const Utf16String& utf16String)
{
	Utf8String utf8String;

	//Convert the UTF-16 string to a UTF-8 string and append it
	UtfStringConverter::Utf16ToUtf8String(utf16String, utf8String);

	m_codeUnitString.append(utf8String);

	return *this;
}

Utf8String& Utf8String::append(const Utf8Char& utf8Character)
{
	switch(utf8Character.size())
	{
	case 1:
		m_codeUnitString.append(1, utf8Character[0]);
		break;
	case 2:
		m_codeUnitString.append(1, utf8Character[0]);
		m_codeUnitString.append(1, utf8Character[1]);
		break;
	case 3:
		m_codeUnitString.append(1, utf8Character[0]);
		m_codeUnitString.append(1, utf8Character[1]);
		m_codeUnitString.append(1, utf8Character[2]);
		break;
	case 4:
		m_codeUnitString.append(1, utf8Character[0]);
		m_codeUnitString.append(1, utf8Character[1]);
		m_codeUnitString.append(1, utf8Character[2]);
		m_codeUnitString.append(1, utf8Character[3]);
		break;
	default:
		//If we've reached this point, something has gone wrong
		assert(false);
		break;
	}

	return *this;
}

Utf8String& Utf8String::assign(const Utf8String& utf8String)
{
	m_codeUnitString.assign(utf8String);

	return *this;
}

Utf8String& Utf8String::assign(const std::string& utf8String)
{
	m_codeUnitString.assign(utf8String);

	return *this;
}

Utf8String& Utf8String::assign(const char* utf8String)
{
	m_codeUnitString.assign(utf8String);

	return *this;
}

Utf8String& Utf8String::assign(const char* utf8String, const size_t codeUnitCount)
{
	m_codeUnitString.assign(utf8String, codeUnitCount);

	return *this;
}

Utf8String& Utf8String::assign(const wchar_t* wideString)
{
	this->assign(Utf16String(wideString));

	return *this;
}

Utf8String& Utf8String::assign(const wchar_t* wideString, const size_t characterCount)
{
	this->assign(Utf16String(wideString, characterCount));

	return *this;
}

Utf8String& Utf8String::assign(const std::wstring& wideString)
{
	this->assign(Utf16String(wideString));

	return *this;
}

Utf8String& Utf8String::assign(const Utf16String& utf16String)
{
	Utf8String utf8String;

	//Convert the UTF-16 string to a UTF-8 string and assign it
	UtfStringConverter::Utf16ToUtf8String(utf16String, utf8String);

	m_codeUnitString.assign(utf8String);

	return *this;
}

Utf8String& Utf8String::assign(const Utf8Char& utf8Character)
{
	assert(utf8Character.is_valid());

	switch(utf8Character.size())
	{
	case 1:
		m_codeUnitString.assign(1, utf8Character[0]);
		break;
	case 2:
		m_codeUnitString.assign(1, utf8Character[0]);
		m_codeUnitString.append(1, utf8Character[1]);
		break;
	case 3:
		m_codeUnitString.assign(1, utf8Character[0]);
		m_codeUnitString.append(1, utf8Character[1]);
		m_codeUnitString.append(1, utf8Character[2]);
		break;
	case 4:
		m_codeUnitString.assign(1, utf8Character[0]);
		m_codeUnitString.append(1, utf8Character[1]);
		m_codeUnitString.append(1, utf8Character[2]);
		m_codeUnitString.append(1, utf8Character[3]);
		break;
	default:
		//If we've reached this point, something has gone wrong
		assert(false);
		break;
	}

	return *this;
}

Utf8CharReference Utf8String::at(size_t index)
{
	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	string::iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		//Figure out how many code units comprise the current code point
		codeUnitCount = Utf8String::CharacterCodeUnitCount(stringIterator);

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			break;
		}

		//Increment the iterator by the number of code units that comprise this code point to
		//reach the next code point
		stringIterator += codeUnitCount;

		codePointCount++;
	}

	if(stringIterator == m_codeUnitString.end())
	{
		std::stringstream errorMessageStream;
		errorMessageStream << "The index " << index << " does not exist in this string of length "
			<< codePointCount;

		throw out_of_range(errorMessageStream.str());
	}

	return Utf8CharReference(m_codeUnitString, stringIterator, codeUnitCount);
}

const Utf8Char Utf8String::at(size_t index) const
{
	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	string::const_iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		//Figure out how many code units comprise the current code point
		codeUnitCount = Utf8String::CharacterCodeUnitCount(stringIterator);

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			break;
		}

		//Increment the iterator by the number of code units that comprise this code point to
		//reach the next code point
		stringIterator += codeUnitCount;

		codePointCount++;
	}

	if(stringIterator == m_codeUnitString.end())
	{
		std::stringstream errorMessageStream;
		errorMessageStream << "The index " << index << " does not exist in this string of length "
			<< codePointCount;

		throw out_of_range(errorMessageStream.str());
	}

	return Utf8Char(stringIterator, codeUnitCount);
}

Utf8String::iterator Utf8String::begin()
{
	return Utf8String::iterator(m_codeUnitString, m_codeUnitString.begin());
}

Utf8String::const_iterator Utf8String::begin() const
{
	return Utf8String::const_iterator(m_codeUnitString, m_codeUnitString.begin());
}

const char* Utf8String::c_str() const
{
	return m_codeUnitString.c_str();
}

size_t Utf8String::capacity() const
{
	return m_codeUnitString.capacity();
}

void Utf8String::clear()
{
	m_codeUnitString.clear();
}

size_t Utf8String::code_unit_index(const size_t codePointIndex)
{
	assert(is_valid());

	size_t codeUnitIndex = 0;

	if(codePointIndex >= length())
	{
		codeUnitIndex = Utf8String::npos;
	}
	else
	{
		string::const_iterator stringIterator = m_codeUnitString.begin();

		//Iterate through the code unit string, counting the code points until we've found the correct code unit
		for(size_t index = 0; index < codePointIndex; ++index)
		{
			size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(stringIterator);

			stringIterator += codeUnitCount;
			codeUnitIndex += codeUnitCount;
		}
	}

	return codeUnitIndex;
}

size_t Utf8String::code_point_index(const size_t codeUnitIndex)
{
	assert(is_valid());

	size_t codePointIndex = 0;

	if(codeUnitIndex >= size())
	{
		codePointIndex = Utf8String::npos;
	}
	else
	{
		string::const_iterator stringIterator = m_codeUnitString.begin() + 1;

		for(size_t index = 1; index <= codeUnitIndex; ++index)
		{
			//Since CharacterCodeUnitCount always returns 0 for code units that are not the first
			//code unit of a code point, we can simply add 1 to the code point count every time
			//CharacterCodeUnit count returns a non-zero value to get the correct code point count
			switch(Utf8String::CharacterCodeUnitCount(stringIterator))
			{
			case 4:
			case 3:
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


int Utf8String::compare(const Utf16String& utf16String) const
{
	//A value of -2 indicates that we haven't figured out the comparison value yet
	int compareValue = -2;

	//Instead of converting the entire UTF-16 string, it would be more efficient to
	//iterate through both strings, comparing the 32-bit code point values and stopping
	//when a difference is found. This will definitely be more efficient than converting 
	//the entire string when the strings are unequal and around the same efficiency
	//when the strings are equal.
	Utf16String::const_iterator utf16StringIterator = utf16String.begin();
	Utf8String::const_iterator utf8StringIterator = this->begin();

	while(utf16StringIterator != utf16String.end() && utf8StringIterator != this->end()
		&& compareValue == -2)
	{
		UInt32 utf8CharValue = (*utf8StringIterator).to_utf_32();
		UInt32 utf16CharValue = (*utf16StringIterator).to_utf_32();

		if(utf8CharValue != utf16CharValue)
		{
			if(utf8CharValue > utf16CharValue)
			{
				compareValue = 1;
			}
			else
			{
				compareValue = -1;
			}
		}

		++utf16StringIterator;
		++utf8StringIterator;
	}

	//If the comparison value is still -2, that means all characters compared were the same.
	//However, we need to test the length of the strings. If the length of the two strings are
	//the same, they are equal.  Otherwise, the longer string is considered to be greater than
	//the shorter string
	if(compareValue == -2)
	{
		//Calculating the length only once will make this more efficient, since length calculations
		//are O(n) operations
		size_t utf8StringLength = this->length();
		size_t utf16StringLength = utf16String.length();

		if(utf8StringLength == utf16StringLength)
		{
			compareValue = 0;
		}
		else if(utf8StringLength > utf16StringLength)
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

int Utf8String::compare(const Utf8String& utf8String) const
{
	//We are only comparing code units until we find differing code units.
	//When we find differing code units, it doesn't not matter whether the code units are part
	//of one- or two-code-unit code points.  As far as I can tell, just looking at the first
	//unit (when the code units differ) is enough to determine the order of the code points
	//that the code units represent.  So the basic_string compare implementation should do
	//what we need.

	return m_codeUnitString.compare(utf8String);
}

int Utf8String::compare(const std::string& utf8String) const
{
	//We are only comparing code units until we find differing code units.
	//When we find differing code units, it doesn't not matter whether the code units are part
	//of one- or two-code-unit code points.  As far as I can tell, just looking at the first
	//unit (when the code units differ) is enough to determine the order of the code points
	//that the code units represent.  So the basic_string compare implementation should do
	//what we need.

	return m_codeUnitString.compare(utf8String);
}

int Utf8String::compare(const char* utf8String) const
{
	//We are only comparing code units until we find differing code units.
	//When we find differing code units, it doesn't not matter whether the code units are part
	//of one- or two-code-unit code points.  As far as I can tell, just looking at the first
	//unit (when the code units differ) is enough to determine the order of the code points
	//that the code units represent.  So the basic_string compare implementation should do
	//what we need.

	return m_codeUnitString.compare(utf8String);
}

int Utf8String::compare(const char* utf8String, const size_t codeUnitCount) const
{
	//We are only comparing code units until we find differing code units.
	//When we find differing code units, it doesn't not matter whether the code units are part
	//of one- or two-code-unit code points.  As far as I can tell, just looking at the first
	//unit (when the code units differ) is enough to determine the order of the code points
	//that the code units represent.  So the basic_string compare implementation should do
	//what we need.

	return m_codeUnitString.compare(0, codeUnitCount, utf8String);
}

size_t Utf8String::copy(char* codeUnitArray, const size_t codeUnitArraySize, const size_t characterCount,
	const size_t characterOffset) const
{
	assert(characterOffset < length());

	size_t copiedCodeUnits = 0;
	size_t copiedCharacters = 0;

	for(Utf8String::const_iterator stringIterator = this->begin() + characterOffset;
		stringIterator != this->end() && copiedCharacters < characterCount; ++stringIterator)
	{
		Utf8Char currentCharacter = *stringIterator;

		//If we can't copy any more code units, then stop the copying
		if(copiedCodeUnits + currentCharacter.size() >= codeUnitArraySize)
		{
			stringIterator = this->end() - 1;
		}

		//Otherwise, continue copying
		else
		{
			for(size_t codeUnitIndex = 0; codeUnitIndex < currentCharacter.size(); ++codeUnitIndex)
			{
				codeUnitArray[copiedCodeUnits] = currentCharacter[codeUnitIndex];
				++copiedCodeUnits;
			}
		}

		++copiedCharacters;
	}

	return copiedCodeUnits;
}

const char* Utf8String::data() const
{
	return m_codeUnitString.data();
}

bool Utf8String::empty() const
{
	return m_codeUnitString.empty();
}

Utf8String::iterator Utf8String::end()
{
	return Utf8String::iterator(m_codeUnitString, m_codeUnitString.end());
}

Utf8String::const_iterator Utf8String::end() const
{
	return Utf8String::const_iterator(m_codeUnitString, m_codeUnitString.end());
}

Utf8String::iterator Utf8String::erase(const Utf8String::iterator& firstPosition,
									   const Utf8String::iterator& lastPosition)
{
	return Utf8String::iterator(m_codeUnitString, m_codeUnitString.erase(firstPosition.codeUnitPosition,
		lastPosition.codeUnitPosition));
}

Utf8String::iterator Utf8String::erase(const Utf8String::iterator& position)
{
	//Since there is no default constructor for Utf8String::iterator, just initialize it using
	//the iterator that was passed in
	Utf8String::iterator postEraseIterator(position);

	size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(position.codeUnitPosition);

	for(size_t codeUnitNum = 0; codeUnitNum < codeUnitCount; ++codeUnitNum)
	{
		//postEraseIterator = Utf16String::iterator(*this, basic_string<UInt16>::erase(position.codeUnitPosition));
		postEraseIterator = Utf8String::iterator(m_codeUnitString, m_codeUnitString.erase(postEraseIterator.codeUnitPosition));
	}

	return postEraseIterator;
}

Utf8String& Utf8String::erase(const size_t offset, const size_t count)
{
	assert(offset <= length());

	//Get the iterator pointing to the beginning of the range
	Utf8String::iterator firstPosition = begin() + offset;

	//Get the iterator pointing to the beginning of the range
	//Initialize the iterator to the end of the string (since the iterator has to be initialized
	//to something)
	Utf8String::iterator lastPosition = end();

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

size_t Utf8String::find(const Utf8String& searchString, size_t offset)
{
	//Search for the sequence of code units in this string
	size_t codeUnitIndex = m_codeUnitString.find(searchString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex =  code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf8String::find_first_not_of(const Utf8String& searchString, size_t offset)
{
	//Conduct the search in the code unit string
	size_t codeUnitIndex = m_codeUnitString.find_first_not_of(searchString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex = code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf8String::find_first_of(const Utf8String& searchString, size_t offset)
{
	assert(is_valid());
	assert(searchString.is_valid());

	size_t codePointIndex = Utf8String::npos;
	size_t currentIndex = offset;

	//Only continue if the offset is a location within the string, otherwise we just return npos
	if(offset < length())
	{
		//Iterate through each code point in this string, looking for a match
		for(Utf8String::const_iterator stringIterator = this->begin() + offset; stringIterator != this->end() &&
			codePointIndex == Utf8String::npos; ++stringIterator)
		{
			//Iterate through each code point in the search string, comparing this code point
			//with each search string code point
			for(Utf8String::const_iterator searchStringIterator = searchString.begin();
				searchStringIterator != searchString.end() && codePointIndex == Utf8String::npos;
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

size_t Utf8String::find_last_not_of(const Utf8String& searchString, size_t offset)
{
	//Conduct the search in the code unit string
	size_t codeUnitIndex = m_codeUnitString.find_last_not_of(searchString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex = code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf8String::find_last_of(const Utf8String& searchString, size_t offset)
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
	Utf8String::const_iterator endPosition = this->begin() + (offset + 1);

	//Iterate through each code point in this string, looking for a match
	for(Utf8String::const_iterator stringIterator = this->begin();
		stringIterator != endPosition; ++stringIterator)
	{
		//Iterate through each code point in the search string, comparing this code point
		//with each search string code point
		for(Utf8String::const_iterator searchStringIterator = searchString.begin();
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

Utf8String& Utf8String::insert(const size_t index, const Utf16String& utf16String)
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

	Utf8String utf8String;

	//Convert the UTF-16 string to a UTF-8 string and append it
	UtfStringConverter::Utf16ToUtf8String(utf16String, utf8String);

	m_codeUnitString.insert(codeUnitIndex, utf8String);

	return *this;
}

Utf8String& Utf8String::insert(const size_t index, const Utf8String& utf8String)
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

	m_codeUnitString.insert(codeUnitIndex, utf8String);

	return *this;

}

Utf8String& Utf8String::insert(const size_t index, const std::string& utf8String)
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

	m_codeUnitString.insert(codeUnitIndex, utf8String);

	return *this;
}

Utf8String& Utf8String::insert(const size_t index, const char* utf8String)
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

	m_codeUnitString.insert(codeUnitIndex, utf8String);

	return *this;
}

Utf8String& Utf8String::insert(const size_t index, const char* utf8String, const size_t codeUnitCount)
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

	m_codeUnitString.insert(codeUnitIndex, utf8String, codeUnitCount);

	return *this;
}

Utf8String& Utf8String::insert(const size_t index, const Utf8Char& utf8Character)
{
	assert(index <= length());
	assert(utf8Character.is_valid());

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

	for(size_t codeUnitIterator = utf8Character.size() - 1; ((int)codeUnitIterator) >= 0; --codeUnitIterator)
	{
		m_codeUnitString.insert(codeUnitIndex, &utf8Character[codeUnitIterator], 1);
	}

	return *this;
}

bool Utf8String::is_valid() const
{
	bool isValid = true;

	//Iterate through the code units, validating each code point
	string::const_iterator stringIterator = m_codeUnitString.begin();

	while(stringIterator != m_codeUnitString.end() && isValid)
	{
		//Figure out the number of code units in the code point we are pointing to
		size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(stringIterator);

		//If the code unit count for this code unit would cause us to read code units beyond the end
		//of the string, we don't have all the code units for this code point, so this code point
		//is invalid.
		if(m_codeUnitString.length() < codeUnitCount || stringIterator > (m_codeUnitString.end() - codeUnitCount))
		{
			isValid = false;
		}
		else
		{
			isValid = IsValidCharacter(Utf8Char(stringIterator, codeUnitCount));

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

size_t Utf8String::length() const
{
	size_t codePointCount = 0;
	const char* bufferPointer = m_codeUnitString.c_str();

	while(*bufferPointer != 0)
	{
		//Increment the buffer pointer by the number of code units int he current code point
		bufferPointer += CharacterCodeUnitCount(bufferPointer);

		codePointCount++;
	}

	return codePointCount;
}

void Utf8String::push_back(const Utf8Char& character)
{
	append(character);
}

Utf8String::reverse_iterator Utf8String::rbegin()
{
	return Utf8String::reverse_iterator(m_codeUnitString, m_codeUnitString.rbegin());
}

Utf8String::const_reverse_iterator Utf8String::rbegin() const
{
	return Utf8String::const_reverse_iterator(m_codeUnitString, m_codeUnitString.rbegin());
}

Utf8String::reverse_iterator Utf8String::rend()
{
	return Utf8String::reverse_iterator(m_codeUnitString, m_codeUnitString.rend());
}

Utf8String::const_reverse_iterator Utf8String::rend() const
{
	return Utf8String::const_reverse_iterator(m_codeUnitString, m_codeUnitString.rend());
}

Utf8String& Utf8String::replace(const size_t position, const size_t count, const Utf8String& replacementString)
{
	assert(position <= length());

	this->erase(position, count);
	this->insert(position, replacementString);

	return *this;
}

Utf8String& Utf8String::replace(const size_t position, const size_t count, const size_t characterCount,
								  const Utf8Char& character)
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

Utf8String& Utf8String::replace(Utf8String::iterator beginIterator, Utf8String::iterator endIterator,
	const Utf8String& replacementString)
{
	m_codeUnitString.replace(beginIterator.codeUnitPosition, endIterator.codeUnitPosition,
		replacementString);

	return *this;
}

Utf8String& Utf8String::replace(Utf8String::iterator beginIterator, Utf8String::iterator endIterator,
	const size_t characterCount, const Utf8Char& character)
{
	//Construct a std::string consisting of the code units to be inserted
	string insertString;

	for(size_t count = 0; count < characterCount; ++count)
	{
		assert(character.size() >= 1 || character.size() <= 4);

		switch(character.size())
		{
		case 1:
			insertString.append(1, character[0]);
			break;
		case 2:
			insertString.append(1, character[0]);
			insertString.append(1, character[1]);
			break;
		case 3:
			insertString.append(1, character[0]);
			insertString.append(1, character[1]);
			insertString.append(1, character[2]);
			break;
		case 4:
			insertString.append(1, character[0]);
			insertString.append(1, character[1]);
			insertString.append(1, character[2]);
			insertString.append(1, character[3]);
			break;
		default:
			//If we get here, something has gone wrong
			assert(false);
			break;
		}
	}

	m_codeUnitString.replace(beginIterator.codeUnitPosition, endIterator.codeUnitPosition,
		insertString);

	return *this;
}

size_t Utf8String::rfind(const Utf8String& searchString, size_t offset)
{
	//Search for the sequence of code units in this string
	size_t codeUnitIndex = m_codeUnitString.rfind(searchString, code_unit_index(offset));

	//Convert the code unit index to a code point index
	size_t codePointIndex = npos;

	if(codeUnitIndex != npos)
	{
		codePointIndex = code_point_index(codeUnitIndex);
	}

	return codePointIndex;
}

size_t Utf8String::size() const
{
	return m_codeUnitString.size();
}

Utf8String Utf8String::substr(const size_t offset, const size_t count)
{
	assert(offset < length());

	Utf8String subString;

	size_t codePointCount = 0;
	const char* bufferPointer = m_codeUnitString.c_str();

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
		size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(bufferPointer);

		//If we're past the offset, append the code point to the sub-string.
		if(codePointCount >= offset)
		{
			subString.append(bufferPointer, codeUnitCount);
		}

		bufferPointer += codeUnitCount;

		codePointCount++;
	}

	return subString;
}

void Utf8String::swap(Utf8String& utf8String)
{
	m_codeUnitString.swap(utf8String.m_codeUnitString);
}

/*Operators*/

Utf8CharReference Utf8String::operator[](size_t index)
{
	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	string::iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		//Figure out how many code units comprise the current code point
		codeUnitCount = Utf8String::CharacterCodeUnitCount(stringIterator);

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			break;
		}

		//Increment the iterator by the number of code units that comprise this code point to
		//reach the next code point
		stringIterator += codeUnitCount;

		codePointCount++;
	}

	return Utf8CharReference(m_codeUnitString, stringIterator, codeUnitCount);
}

const Utf8Char Utf8String::operator[](size_t index) const
{
	size_t codePointCount = 0;
	size_t codeUnitCount = 0;

	string::const_iterator stringIterator = m_codeUnitString.begin();

	//Iterate through the code unit buffer, looking for the character corresponding
	//to the index
	while(stringIterator != m_codeUnitString.end())
	{
		//Figure out how many code units comprise the current code point
		codeUnitCount = Utf8String::CharacterCodeUnitCount(stringIterator);

		//If we are at the code point we are supposed to retrieve, copy it to codePoint and
		//break out of the loop
		if(codePointCount == index)
		{
			break;
		}

		//Increment the iterator by the number of code units that comprise this code point to
		//reach the next code point
		stringIterator += codeUnitCount;

		codePointCount++;
	}

	return Utf8Char(stringIterator, codeUnitCount);
}

bool Utf8String::operator==(const Utf8String& otherString) const
{
	return m_codeUnitString == otherString.m_codeUnitString;
}

bool Utf8String::operator!=(const Utf8String& otherString) const
{
	return m_codeUnitString != otherString.m_codeUnitString;
}

bool Utf8String::operator<(const Utf8String& otherString) const
{
	return m_codeUnitString < otherString.m_codeUnitString;
}

bool Utf8String::operator<=(const Utf8String& otherString) const
{
	return m_codeUnitString <= otherString.m_codeUnitString;
}

bool Utf8String::operator>(const Utf8String& otherString) const
{
	return m_codeUnitString > otherString.m_codeUnitString;
}

bool Utf8String::operator>=(const Utf8String& otherString) const
{
	return m_codeUnitString >= otherString.m_codeUnitString;
}

Utf8String::operator const std::string() const
{
	return m_codeUnitString;
}

Utf8String::operator std::string()
{
	return m_codeUnitString;
}

/*Static Functions*/

size_t Utf8String::CharacterCodeUnitCount(const std::string::const_iterator stringIterator)
{
	int codeUnitCount = 0;

	//Get the first code point from the iterator
	char firstCodePoint = *stringIterator;

	//If the most significant bit is 1, then this is a multi-code-unit character.
	if(firstCodePoint & 0x80)
	{
		//If the first byte is 11110, then the character is composed of 4 code units
		if((firstCodePoint & 0xF0) == 0xF0)
			codeUnitCount = 4;

		//If the first byte is 1110, then the character is composed of 3 code units
		else if((firstCodePoint & 0xE0) == 0xE0)
			codeUnitCount = 3;

		//If the first byte is 110, then the character is composed of 2 code units
		else if((firstCodePoint & 0xC0) == 0xC0)
			codeUnitCount = 2;
	}
	else
	{
		codeUnitCount = 1;
	}

	return codeUnitCount;
}

size_t Utf8String::CharacterCodeUnitCount(const std::string::const_reverse_iterator& stringIterator)
{
	size_t codeUnitCount = 0;
	size_t iteratedCodeUnits = 1;

	//Get the code unit from the reverse iterator
	char currentCodeUnit = *stringIterator;
	string::const_reverse_iterator reverseIterator = stringIterator;

	//Since this is a reverse iterator, work backward to the first code unit
	while((currentCodeUnit & 0xC0) == 0x80)
	{
		++reverseIterator;
		currentCodeUnit = *reverseIterator;
		++iteratedCodeUnits;
	}

	//Now that we've found the first code unit, check for length of the code point
	//If the most significant bit is 1, then this is a multi-code-unit character.
	if(currentCodeUnit & 0x80)
	{
		//If the first byte is 11110, then the character is composed of 4 code units
		if((currentCodeUnit & 0xF0) == 0xF0)
			codeUnitCount = 4;

		//If the first byte is 1110, then the character is composed of 3 code units
		else if((currentCodeUnit & 0xE0) == 0xE0)
			codeUnitCount = 3;

		//If the first byte is 110, then the character is composed of 2 code units
		else if((currentCodeUnit & 0xC0) == 0xC0)
			codeUnitCount = 2;
	}
	else
	{
		codeUnitCount = 1;
	}

	//If the number of code units we iterated over is different than the number of code units
	//indicated by the first code unit of the code point, then the iterator was originally pointing
	//to a code unit that was not the last code unit. In this case, return a code unit count of 0
	if(iteratedCodeUnits != codeUnitCount)
	{
		codeUnitCount = 0;
	}

	return codeUnitCount;
}

size_t Utf8String::CharacterCodeUnitCount(const char* characterPointer)
{
	//Assert that we are actually pointing to something
	assert(characterPointer != NULL);
	//Assert that we are looking at the first code unit; a first code unit never starts with the bits "10".
	assert((*characterPointer & 0xC000) != 0x8000);

	int codeUnitCount = 0;

	//Get the first code point
	char firstCodePoint = *characterPointer;

	//If the most significant bit is 1, then this is a multi-code-unit character.
	if(firstCodePoint & 0x80)
	{
		//If the first byte is 11110, then the character is composed of 4 code units
		if((firstCodePoint & 0xF0) == 0xF0)
			codeUnitCount = 4;

		//If the first byte is 1110, then the character is composed of 3 code units
		else if((firstCodePoint & 0xE0) == 0xE0)
			codeUnitCount = 3;

		//If the first byte is 110, then the character is composed of 2 code units
		else if((firstCodePoint & 0xC0) == 0xC0)
			codeUnitCount = 2;
	}
	else
	{
		codeUnitCount = 1;
	}

	return codeUnitCount;
}

UInt32 Utf8String::DecodeCharacter(const Utf8Char& utf8Character)
{
	size_t characterSize = utf8Character.size();

	char characterBuffer[4];

	switch(characterSize)
	{
	case 4:
		characterBuffer[3] = utf8Character[3];
	case 3:
		characterBuffer[2] = utf8Character[2];
	case 2:
		characterBuffer[1] = utf8Character[1];
	case 1:
		characterBuffer[0] = utf8Character[0];
		break;
	default:
		//If a UTF-8 character has more than four code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}

	return DecodeCharacter(characterBuffer, utf8Character.size());
}

UInt32 Utf8String::DecodeCharacter(const char* characterPointer, const size_t codeUnitCount)
{
	//Assert that characterPointer is actually pointing at something
	assert(characterPointer != NULL);
	//Assert that we have between 1 and 4 code units
	assert(codeUnitCount >= 1 && codeUnitCount <= 4);

	//We cannot assert that the character is valid, as that would cause a circular dependency
	//with the IsValidCharacter() function, which calls this function

	UInt32 codePoint = 0;

	switch(codeUnitCount)
	{
	case 1:
		//0zzzzzzz -> 00000000 00000000 00000000 0zzzzzzz
		codePoint = *characterPointer;
		break;
	case 2:
		//110yyyyy, 10zzzzzz -> 00000000 00000000 00000yyy yyzzzzzz
		codePoint = ((characterPointer[0] & 0x1F) << 6) | (characterPointer[1] & 0x3F);
		break;
	case 3:
		//1110xxxx, 10yyyyyy, 10zzzzzz -> 00000000 00000000 xxxxyyyy yyzzzzzz
		codePoint = ((characterPointer[0] & 0x0F) << 12) | ((characterPointer[1] & 0x3F) << 6) |
			(characterPointer[2] & 0x3F);
		break;
	case 4:
		//11110www, 10xxxxxx, 10yyyyyy, 10zzzzzz -> 00000000 000wwwxx xxxxyyyy yyzzzzzz
		codePoint = ((characterPointer[0] & 0x07) << 18) | ((characterPointer[1] & 0x3F) << 12)
			| ((characterPointer[2] & 0x3F) << 6) | (characterPointer[3] & 0x3F);
		break;
	default:
		//If we get to this point, there is a programming error somewhere. Trigger an assertion failure.
		assert(false);
		break;
	}

	return codePoint;
}

Utf8Char Utf8String::EncodeCharacter(const UInt32 codePoint)
{
	//Assert that the code point is a valid Unicode code point (000000-10FFFF)
	assert(codePoint <= 0x10FFFF);

	Utf8Char utf8Character;
	char codeUnit;

	//Encode code points 000000-00007F as a single code unit
	if(codePoint <= 0x7F)
	{
		//00000000 00000000 00000000 0zzzzzzz -> 0zzzzzzz
		codeUnit = (char)codePoint;
		utf8Character[0] = codeUnit;
	}

	//Encode code points 000080-0007FF as two code units
	else if(codePoint <= 0x7FF)
	{
		//00000000 00000000 00000yyy yyzzzzzz -> 110yyyyy, 10zzzzzz
		codeUnit = (char)(codePoint >> 6) | 0xC0;
		utf8Character[0] = codeUnit;
		codeUnit = (char)(codePoint & 0x3F) | 0x80;
		utf8Character[1] = codeUnit;
	}

	//Encode code points 000800-00FFFF as three code units
	else if(codePoint <= 0xFFFF)
	{
		//00000000 00000000 xxxxyyyy yyzzzzzz -> 1110xxxx, 10yyyyyy, 10zzzzzz
		codeUnit = (char)(codePoint >> 12) | 0xE0;
		utf8Character[0] = codeUnit;
		codeUnit = (char)((codePoint & 0xFC0) >> 6) | 0x80;
		utf8Character[1] = codeUnit;
		codeUnit = (char)(codePoint & 0x3F) | 0x80;
		utf8Character[2] = codeUnit;
	}

	//Encode code points 010000-10FFFF as four code units
	else
	{
		//00000000 000wwwxx xxxxyyyy yyzzzzzz -> 11110www, 10xxxxxx, 10yyyyyy, 10zzzzzz
		codeUnit = (char)(codePoint >> 18) | 0xF0;
		utf8Character[0] = codeUnit;
		codeUnit = (char)((codePoint & 0x3F000) >> 12) | 0x80;
		utf8Character[1] = codeUnit;
		codeUnit = (char)((codePoint & 0xFC0) >> 6) | 0x80;
		utf8Character[2] = codeUnit;
		codeUnit = (char)(codePoint & 0x3F) | 0x80;
		utf8Character[3] = codeUnit;
	}

	return utf8Character;
}

bool Utf8String::IsValidCharacter(const Utf8Char& utf8Character)
{
	size_t characterSize = utf8Character.size();

	char characterBuffer[4];

	switch(characterSize)
	{
	case 4:
		characterBuffer[3] = utf8Character[3];
	case 3:
		characterBuffer[2] = utf8Character[2];
	case 2:
		characterBuffer[1] = utf8Character[1];
	case 1:
		characterBuffer[0] = utf8Character[0];
	}

	return IsValidCharacter(characterBuffer, characterSize);
}

bool Utf8String::IsValidCharacter(const char* characterPointer, const size_t codeUnitCount)
{
	//Assert that characterPointer is actually pointing at something
	assert(characterPointer != NULL);

	bool isValid = false;

	switch(codeUnitCount)
	{
	case 1:
		//The most significant bit must be 0
		if((*characterPointer & 0x80) == 0x00)
		{
			isValid = true;
		}

		break;
	case 2:
		//The first code unit must start with 110, the second code unit must start with 10, and
		//the encoded code point must be in the range 000080-0007FF
		if((*characterPointer & 0xE0) == 0xC0 && (characterPointer[1] & 0xC0) == 0x80)
		{
			UInt32 codePoint = DecodeCharacter(characterPointer, codeUnitCount);

			if(codePoint >= 0x80 && codePoint <= 0x7FF)
			{
				isValid = true;
			}
		}

		break;
	case 3:
		//The first code unit must start with 1110, the second and third code units must start
		//with 10, and the encoded code point must be in the range 000800-00FFFF. There are
		//also 32 non-characters (0xFDD0 - 0xFDEF) that need to be checked for
		if((*characterPointer & 0xF0) == 0xE0 && (characterPointer[1] & 0xC0) == 0x80 &&
			(characterPointer[2] & 0xC0) == 0x80)
		{
			UInt32 codePoint = DecodeCharacter(characterPointer, codeUnitCount);

			if(codePoint >= 0x800 && codePoint <= 0xFFFD && (codePoint < 0xFDD0 || codePoint > 0xFDEF))
			{
				isValid = true;
			}
		}

		break;
	case 4:
		//The first code unit must start with 11110, the second, third, and fourth code units
		//must start with 10, and the encoded code point must be in the range 010000-10FFFF
		if((*characterPointer & 0xF8) == 0xF0 && (characterPointer[1] & 0xC0) == 0x80 &&
			(characterPointer[2] & 0xC0) == 0x80 && (characterPointer[3] & 0xC0) == 0x80)
		{
			UInt32 codePoint = DecodeCharacter(characterPointer, codeUnitCount);

			if(codePoint >= 0x10000 && codePoint <= 0x10FFFF)
			{
				//Check for the 32 non-character code points
				if((codePoint & 0xFFFF) != 0xFFFF && (codePoint & 0xFFFF) != 0xFFFE)
				{
					isValid = true;
				}
			}
		}

		break;
	}

	return isValid;
}

bool Utf8String::IsWhitespace(const char* utf8Character, const size_t codeUnitCount)
{
	assert(utf8Character != NULL);

	bool isWhitespace = false;

	switch(codeUnitCount)
	{
	case 1:
		if(utf8Character[0] == '\x20' || utf8Character[0] == '\x09' || utf8Character[0] == '\x0D' ||
			utf8Character[0] == '\x0A' || utf8Character[0] == '\xA0')
		{
			isWhitespace = true;
		}

		break;
	case 2:
		//There are no whitespace characters in this range (0x0080 - 0x07FF)
		break;
	case 3:
		if((utf8Character[0] == '\xE1' && utf8Character[1] == '\x9A' && utf8Character[2] == '\x80') ||
			(utf8Character[0] == '\xE1' && utf8Character[1] == '\xA0' && utf8Character[2] == '\x8E') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && ((unsigned char)utf8Character[2]) >= (unsigned char)'\x80' && ((unsigned char)utf8Character[2]) <= (unsigned char)'\x89') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\x8A') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\xBF') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x81' && utf8Character[2] == '\x9F') ||
			(utf8Character[0] == '\xE3' && utf8Character[1] == '\x80' && utf8Character[2] == '\x80') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\xB8') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\xB9'))
		{
			isWhitespace = true;
		}

		break;
	case 4:
		//There are no whitespace characters in this range (0x10000 - 0x10FFFF)
		break;
	default:
		//If we've reached this point, something has gone wrong. So trigger an assertion failure
		assert(false);
		break;
	}

	return isWhitespace;
}

bool Utf8String::IsWhitespace(const Utf8Char& utf8Character)
{
	bool isWhitespace = false;

	switch(utf8Character.size())
	{
	case 1:
		if(utf8Character[0] == '\x20' || utf8Character[0] == '\x09' || utf8Character[0] == '\x0D' ||
			utf8Character[0] == '\x0A' || utf8Character[0] == '\xA0')
		{
			isWhitespace = true;
		}

		break;
	case 2:
		//There are no whitespace characters in this range (0x0080 - 0x07FF)
		break;
	case 3:
		if((utf8Character[0] == '\xE1' && utf8Character[1] == '\x9A' && utf8Character[2] == '\x80') ||
			(utf8Character[0] == '\xE1' && utf8Character[1] == '\xA0' && utf8Character[2] == '\x8E') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && ((unsigned char)utf8Character[2]) >= (unsigned char)'\x80' && ((unsigned char)utf8Character[2]) <= (unsigned char)'\x89') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\x8A') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\xBF') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x81' && utf8Character[2] == '\x9F') ||
			(utf8Character[0] == '\xE3' && utf8Character[1] == '\x80' && utf8Character[2] == '\x80') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\xB8') ||
			(utf8Character[0] == '\xE2' && utf8Character[1] == '\x80' && utf8Character[2] == '\xB9'))
		{
			isWhitespace = true;
		}

		break;
	case 4:
		//There are no whitespace characters in this range (0x10000 - 0x10FFFF)
		break;
	default:
		//If we've reached this point, something has gone wrong. So trigger an assertion failure
		assert(false);
		break;
	}

	return isWhitespace;
}

/*Iterator Implementations*/

/*iterator Implementation*/
Utf8String::iterator::iterator(std::string& basicString,
	const std::string::iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacterReference(NULL)
{

}

Utf8String::iterator::iterator(const iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition),
	currentCharacterReference(NULL)
{

}

Utf8String::iterator::iterator(const Utf8String::reverse_iterator& reverseIterator) :
	codeUnitString(reverseIterator.codeUnitString), codeUnitPosition(reverseIterator.codeUnitPosition.base()),
	currentCharacterReference(NULL)
{
	assert(Utf8String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition) > 0);
	assert(Utf8String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition) <= 4);

	//We have to move the position to the end of the code point due this being a reverse iterator
	codeUnitPosition -= Utf8String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition);
}

Utf8String::iterator::~iterator()
{
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}
}

Utf8String::iterator& Utf8String::iterator::operator=(const iterator& otherIterator)
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

bool Utf8String::iterator::operator==(const iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf8String::iterator::operator!=(const Utf8String::iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf8String::iterator::operator<(const iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf8String::iterator::operator<=(const iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf8String::iterator::operator>(const iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf8String::iterator::operator>=(const iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf8String::iterator& Utf8String::iterator::operator++()
{
	size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf8String::iterator Utf8String::iterator::operator++(int)
{
	Utf8String::iterator iteratorCopy(*this);

	size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf8String::iterator& Utf8String::iterator::operator+=(size_t offset)
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

Utf8String::iterator Utf8String::iterator::operator+(size_t offset)
{
	Utf8String::iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf8String::iterator& Utf8String::iterator::operator--()
{
	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf8String::iterator Utf8String::iterator::operator--(int)
{
	Utf8String::iterator iteratorCopy(*this);

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf8String::iterator& Utf8String::iterator::operator-=(size_t offset)
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

Utf8String::iterator Utf8String::iterator::operator-(size_t offset)
{
	Utf8String::iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

Utf8CharReference Utf8String::iterator::operator*()
{
	if(currentCharacterReference == NULL)
	{
		currentCharacterReference = new Utf8CharReference(codeUnitString, codeUnitPosition,
			Utf8String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return *currentCharacterReference;
}

Utf8CharReference* Utf8String::iterator::operator->()
{
	if(currentCharacterReference == NULL)
	{
		currentCharacterReference = new Utf8CharReference(codeUnitString, codeUnitPosition,
			Utf8String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return currentCharacterReference;
}


/*const_iterator Implementation*/
Utf8String::const_iterator::const_iterator(const std::string& basicString,
	const std::string::const_iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacter(NULL)
{
}

Utf8String::const_iterator::const_iterator(const Utf8String::iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)

{
	if(otherIterator.currentCharacterReference == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf8Char();
		*currentCharacter = *otherIterator.currentCharacterReference;
	}
}

Utf8String::const_iterator::const_iterator(const Utf8String::const_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)
{
	if(otherIterator.currentCharacter == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf8Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}
}

Utf8String::const_iterator::const_iterator(const Utf8String::const_reverse_iterator& reverseIterator) :
	codeUnitString(reverseIterator.codeUnitString), codeUnitPosition(reverseIterator.codeUnitPosition.base()),
	currentCharacter(NULL)
{
	assert(Utf8String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition) > 0);
	assert(Utf8String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition) <= 4);

	//We have to move the position to the end of the code point due this being a reverse iterator
	codeUnitPosition -= Utf8String::CharacterCodeUnitCount(reverseIterator.codeUnitPosition);
}

Utf8String::const_iterator::~const_iterator()
{
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}
}

Utf8String::const_iterator& Utf8String::const_iterator::operator=(const const_iterator& otherIterator)
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
		currentCharacter = new Utf8Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}

	return *this;
}

bool Utf8String::const_iterator::operator==(const const_iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf8String::const_iterator::operator!=(const const_iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf8String::const_iterator::operator<(const const_iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf8String::const_iterator::operator<=(const const_iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf8String::const_iterator::operator>(const const_iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf8String::const_iterator::operator>=(const const_iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf8String::const_iterator& Utf8String::const_iterator::operator++()
{
	size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the rcurrent character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf8String::const_iterator Utf8String::const_iterator::operator++(int)
{
	Utf8String::const_iterator iteratorCopy(*this);

	size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

	codeUnitPosition += codeUnitCount;

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;

}

Utf8String::const_iterator& Utf8String::const_iterator::operator+=(size_t offset)
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

Utf8String::const_iterator Utf8String::const_iterator::operator+(size_t offset)
{
	Utf8String::const_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf8String::const_iterator& Utf8String::const_iterator::operator--()
{
	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the rcurrent character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf8String::const_iterator Utf8String::const_iterator::operator--(int)
{
	Utf8String::const_iterator iteratorCopy(*this);

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.begin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;
}

Utf8String::const_iterator& Utf8String::const_iterator::operator-=(size_t offset)
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

Utf8String::const_iterator Utf8String::const_iterator::operator-(size_t offset)
{
	Utf8String::const_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

const Utf8Char Utf8String::const_iterator::operator*()
{
	if(currentCharacter == NULL)
	{
		currentCharacter = new Utf8Char(codeUnitPosition,
			Utf8String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return *currentCharacter;
}

const Utf8Char* Utf8String::const_iterator::operator->()
{
	if(currentCharacter == NULL)
	{
		currentCharacter = new Utf8Char(codeUnitPosition,
			Utf8String::CharacterCodeUnitCount(codeUnitPosition));
	}

	return currentCharacter;
}

/*reverse_iterator Implementation*/
Utf8String::reverse_iterator::reverse_iterator(std::string& basicString,
	const std::string::reverse_iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacterReference(NULL)
{
}

Utf8String::reverse_iterator::reverse_iterator(const Utf8String::reverse_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition),
	currentCharacterReference(NULL)

{
}

Utf8String::reverse_iterator::reverse_iterator(const Utf8String::iterator& iterator) :
	codeUnitString(iterator.codeUnitString), codeUnitPosition(iterator.codeUnitPosition),
	currentCharacterReference(NULL)
{
	assert(Utf8String::CharacterCodeUnitCount(iterator.codeUnitPosition) > 0);
	assert(Utf8String::CharacterCodeUnitCount(iterator.codeUnitPosition) <= 4);

	//We have to move the position to the end of the code point due this being a reverse iterator
	codeUnitPosition -= Utf8String::CharacterCodeUnitCount(iterator.codeUnitPosition);
}

Utf8String::reverse_iterator& Utf8String::reverse_iterator::operator=(const reverse_iterator& otherIterator)
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

Utf8String::reverse_iterator::~reverse_iterator()
{
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}
}

bool Utf8String::reverse_iterator::operator==(const reverse_iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf8String::reverse_iterator::operator!=(const reverse_iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf8String::reverse_iterator::operator<(const reverse_iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf8String::reverse_iterator::operator<=(const reverse_iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf8String::reverse_iterator::operator>(const reverse_iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf8String::reverse_iterator::operator>=(const reverse_iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf8String::reverse_iterator& Utf8String::reverse_iterator::operator++()
{
	//Increment the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf8String::reverse_iterator Utf8String::reverse_iterator::operator++(int)
{
	Utf8String::reverse_iterator iteratorCopy(*this);

	//Increment the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf8String::reverse_iterator& Utf8String::reverse_iterator::operator+=(size_t offset)
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

Utf8String::reverse_iterator Utf8String::reverse_iterator::operator+(size_t offset)
{
	Utf8String::reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf8String::reverse_iterator& Utf8String::reverse_iterator::operator--()
{
	//size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition - 1);

	////If the previous code unit was only a partial code point, then check
	//if(codeUnitCount == 0)
	//{
	//	codeUnitCount = 2;

	//	//Assert that we are making the correct assumption, which will be correct if the string is valid
	//	assert(Utf8String::CharacterCodeUnitCount(codeUnitPosition - 2) == (size_t)2);
	//}

	//codeUnitPosition -= codeUnitCount;

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.rbegin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return *this;
}

Utf8String::reverse_iterator Utf8String::reverse_iterator::operator--(int)
{
	Utf8String::reverse_iterator iteratorCopy(*this);

	//size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition - 1);

	////If the previous code unit was only a partial surrogate pair, then this character must be composed
	////of two code units
	//if(codeUnitCount == 0)
	//{
	//	codeUnitCount = 2;

	//	//Assert that we are making the correct assumption, which will be correct if the string is valid
	//	assert(Utf8String::CharacterCodeUnitCount(codeUnitPosition - 2) == (size_t)2);
	//}

	//codeUnitPosition -= codeUnitCount;

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.rbegin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the reference to the current character
	if(currentCharacterReference != NULL)
	{
		delete currentCharacterReference;
		currentCharacterReference = NULL;
	}

	return iteratorCopy;
}

Utf8String::reverse_iterator& Utf8String::reverse_iterator::operator-=(size_t offset)
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

Utf8String::reverse_iterator Utf8String::reverse_iterator::operator-(size_t offset)
{
	Utf8String::reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

Utf8CharReference Utf8String::reverse_iterator::operator*()
{
	if(currentCharacterReference == NULL)
	{
		size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		string::iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacterReference = new Utf8CharReference(codeUnitString, forwardIterator, codeUnitCount);
	}

	return *currentCharacterReference;
}

Utf8CharReference* Utf8String::reverse_iterator::operator->()
{
	if(currentCharacterReference == NULL)
	{
		size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		string::iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacterReference = new Utf8CharReference(codeUnitString, forwardIterator, codeUnitCount);
	}

	return currentCharacterReference;
}

/*const_reverse_iterator Implementation*/
Utf8String::const_reverse_iterator::const_reverse_iterator(const std::string& basicString,
	const std::string::const_reverse_iterator& basicStringIterator) :
	codeUnitString(basicString), codeUnitPosition(basicStringIterator), currentCharacter(NULL)
{

}

Utf8String::const_reverse_iterator::const_reverse_iterator(const Utf8String::reverse_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)
{
	if(otherIterator.currentCharacterReference == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf8Char();
		*currentCharacter = *otherIterator.currentCharacterReference;
	}
}

Utf8String::const_reverse_iterator::const_reverse_iterator(const Utf8String::const_reverse_iterator& otherIterator) :
	codeUnitString(otherIterator.codeUnitString), codeUnitPosition(otherIterator.codeUnitPosition)
{
	if(otherIterator.currentCharacter == NULL)
	{
		currentCharacter = NULL;
	}
	else
	{
		currentCharacter = new Utf8Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}

}

Utf8String::const_reverse_iterator::const_reverse_iterator(const Utf8String::const_iterator& iterator) :
	codeUnitString(iterator.codeUnitString), codeUnitPosition(iterator.codeUnitPosition),
	currentCharacter(NULL)
{
	assert(Utf8String::CharacterCodeUnitCount(iterator.codeUnitPosition) > 0);
	assert(Utf8String::CharacterCodeUnitCount(iterator.codeUnitPosition) <= 4);

	//We have to move the position to the end of the code point due this being a reverse iterator
	codeUnitPosition -= Utf8String::CharacterCodeUnitCount(iterator.codeUnitPosition);
}

Utf8String::const_reverse_iterator::~const_reverse_iterator()
{
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}
}

Utf8String::const_reverse_iterator& Utf8String::const_reverse_iterator::operator=(const const_reverse_iterator& otherIterator)
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
		currentCharacter = new Utf8Char();
		*currentCharacter = *otherIterator.currentCharacter;
	}

	return *this;
}

bool Utf8String::const_reverse_iterator::operator==(const const_reverse_iterator& otherIterator) const
{
	return codeUnitPosition == otherIterator.codeUnitPosition;
}

bool Utf8String::const_reverse_iterator::operator!=(const const_reverse_iterator& otherIterator) const
{
	return codeUnitPosition != otherIterator.codeUnitPosition;
}

bool Utf8String::const_reverse_iterator::operator<(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition < otherIterator.codeUnitPosition;
}

bool Utf8String::const_reverse_iterator::operator<=(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition <= otherIterator.codeUnitPosition;
}

bool Utf8String::const_reverse_iterator::operator>(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition > otherIterator.codeUnitPosition;
}

bool Utf8String::const_reverse_iterator::operator>=(const const_reverse_iterator& otherIterator)
{
	return codeUnitPosition >= otherIterator.codeUnitPosition;
}

Utf8String::const_reverse_iterator& Utf8String::const_reverse_iterator::operator++()
{
	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;

}

Utf8String::const_reverse_iterator Utf8String::const_reverse_iterator::operator++(int)
{
	Utf8String::const_reverse_iterator iteratorCopy(*this);

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		++codeUnitPosition;
	}
	while(codeUnitPosition != codeUnitString.rend() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;
}

Utf8String::const_reverse_iterator& Utf8String::const_reverse_iterator::operator+=(size_t offset)
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

Utf8String::const_reverse_iterator Utf8String::const_reverse_iterator::operator+(size_t offset)
{
	Utf8String::const_reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		++offsetIterator;
	}

	return offsetIterator;
}

Utf8String::const_reverse_iterator& Utf8String::const_reverse_iterator::operator--()
{
	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.rbegin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return *this;
}

Utf8String::const_reverse_iterator Utf8String::const_reverse_iterator::operator--(int)
{
	Utf8String::const_reverse_iterator iteratorCopy(*this);

	//Decrement the iterator until we get a non-zero code unit count, meaning that we
	//have the first code unit of a code point
	do
	{
		--codeUnitPosition;
	}
	while(codeUnitPosition >= codeUnitString.rbegin() &&
		Utf8String::CharacterCodeUnitCount(codeUnitPosition) == 0);

	//Destroy the current character
	if(currentCharacter != NULL)
	{
		delete currentCharacter;
		currentCharacter = NULL;
	}

	return iteratorCopy;
}

Utf8String::const_reverse_iterator& Utf8String::const_reverse_iterator::operator-=(size_t offset)
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

Utf8String::const_reverse_iterator Utf8String::const_reverse_iterator::operator-(size_t offset)
{
	Utf8String::const_reverse_iterator offsetIterator = *this;

	for(size_t count = 0; count < offset; ++count)
	{
		--offsetIterator;
	}

	return offsetIterator;
}

const Utf8Char Utf8String::const_reverse_iterator::operator*()
{
	if(currentCharacter == NULL)
	{
		size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		string::const_iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacter = new Utf8Char(forwardIterator, codeUnitCount);
	}

	return *currentCharacter;
}

const Utf8Char* Utf8String::const_reverse_iterator::operator->()
{
	if(currentCharacter == NULL)
	{
		size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(codeUnitPosition);

		//We need to subtract from the forward iterator because converting from a reverse to
		//forward iterator will give us an iterator pointing to the *end* of the character,
		//not the beginning
		string::const_iterator forwardIterator = codeUnitPosition.base() - codeUnitCount;

		currentCharacter = new Utf8Char(forwardIterator, codeUnitCount);
	}

	return currentCharacter;
}
