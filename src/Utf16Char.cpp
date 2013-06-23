#include <assert.h>

#include <utfstring/UtfString.h>

using namespace UtfString;
using namespace std;

/*Utf16Char Definition*/

Utf16Char::Utf16Char()
{

}

Utf16Char::Utf16Char(const std::basic_string<UInt16>::iterator& basicStringIterator, size_t codeUnitCount)
{
	switch(codeUnitCount)
	{
	case 0:
		break;
	case 1:
		characterData.append(&*basicStringIterator, 1);
		break;
	case 2:
		characterData.append(&*basicStringIterator, 1);
		characterData.append(&*(basicStringIterator + 1), 1);
		break;
	default:
		//If a UTF-16 character has more than two code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}
}

Utf16Char::Utf16Char(const std::basic_string<UInt16>::const_iterator& basicStringIterator, size_t codeUnitCount)
{
	switch(codeUnitCount)
	{
	case 0:
		break;
	case 1:
		characterData.append(&*basicStringIterator, 1);
		break;
	case 2:
		characterData.append(&*basicStringIterator, 1);
		characterData.append(&*(basicStringIterator + 1), 1);
		break;
	default:
		//If a UTF-16 character has more than two code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}
}

Utf16Char::Utf16Char(const wchar_t wideCharacter)
{
	characterData.append(1, wideCharacter);
}

Utf16Char::Utf16Char(const char character)
{
	characterData.append(1, character);
}

Utf16Char::Utf16Char(const wchar_t* wideCharacter)
{
	assert(wideCharacter != NULL);

	size_t length = wcslen(wideCharacter);
	UInt16 codeUnit;

	if(length == 1)
	{
		codeUnit = wideCharacter[0];
		characterData.append(1, codeUnit);
	}
	else if(length >= 2)
	{
		codeUnit = wideCharacter[0];
		characterData.append(1, codeUnit);
		codeUnit = wideCharacter[1];
		characterData.append(1, codeUnit);
	}
}

Utf16Char::Utf16Char(const Utf16Char& character)
{
    *this = character;
}

Utf16Char::~Utf16Char()
{

}

bool Utf16Char::operator==(const Utf16Char& otherCharacter) const
{
	return characterData == otherCharacter.characterData;
}

bool Utf16Char::operator!=(const Utf16Char& otherCharacter) const
{
	return !(characterData == otherCharacter.characterData);
}

bool Utf16Char::operator==(const Utf16CharReference& characterReference) const
{
	bool valueEquality = false;
	size_t characterSize = characterData.size();

	if(characterReference.size() == characterSize)
	{
		switch(characterSize)
		{
		case 0:
			break;
		case 1:
			valueEquality = ((*this)[0] == characterReference[0]);
			break;
		case 2:
			valueEquality = ((*this)[0] == characterReference[0]) &&
				((*this)[1] == characterReference[1]);
			break;
		default:
			//If we've reached this point, something has gone wrong. So trigger an assertion failure
			assert(false);
			break;
		}
	}

	return valueEquality;
}

bool Utf16Char::operator!=(const Utf16CharReference& characterReference) const
{
	return !(operator==(characterReference));
}


Utf16Char& Utf16Char::operator=(const Utf16Char& anotherCharacter)
{
	characterData = anotherCharacter.characterData;

	return *this;
}

Utf16Char& Utf16Char::operator=(const Utf16CharReference& characterReference)
{
	switch(characterReference.size())
	{
	case 2:
		characterData.clear();
		characterData.append(&characterReference[0], 1);
		characterData.append(&characterReference[1], 1);
		break;
	case 1:
		characterData.clear();
		characterData.append(&characterReference[0], 1);
		break;
	case 0:
		break;
	default:
		//If a UTF-16 character has more than two code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}

	return *this;
}

UInt16& Utf16Char::operator[](const size_t index)
{
	//The index should be less than the max number of possible code units
	assert(index < Utf16CodeUnitMax);

	//If the index is outside the bounds of the character data string, the character data string
	//needs to be expanded.
	if(index >= characterData.size())
	{
		characterData.resize(index + 1, L' ');
	}

	return characterData[index];
}

const UInt16& Utf16Char::operator[](const size_t index) const
{
	//The index should be less than the max number of possible code units
	assert(index < Utf16CodeUnitMax);

	return characterData[index];
}

Utf16Char::operator Utf8Char() const
{
	assert(is_valid());

	//Create the buffers to hold the code units for the UTF-16 character and its UTF-8
	//equivalent
	UInt16 utf16CodeUnits[2];
	char utf8CodeUnits[4];
	size_t utf8CodeUnitCount = 4;

	//Copy the UTF-16 code units to the buffer
	utf16CodeUnits[0] = characterData[0];

	if(characterData.size() > 1)
	{
		utf16CodeUnits[1] = characterData[1];
	}

	//Convert to UTF-8
	UtfStringConverter::Utf16ToUtf8Char(utf16CodeUnits, characterData.size(), utf8CodeUnits, utf8CodeUnitCount);

	//Put the UTF-8 code units in a Utf8Char object and return it
	Utf8Char utf8Char;

	for(size_t codeUnitIndex = 0; codeUnitIndex < utf8CodeUnitCount; ++codeUnitIndex)
	{
		utf8Char[codeUnitIndex] = utf8CodeUnits[codeUnitIndex];
	}

	return utf8Char;
}

const UInt16* Utf16Char::c_str() const
{
	return characterData.c_str();
}

void Utf16Char::clear()
{
	characterData.clear();
}

bool Utf16Char::is_valid() const
{
	return Utf16String::IsValidCharacter(*this);
}

UInt32 Utf16Char::to_utf_32() const
{
	assert(size() == 1 || size() == 2);

	return Utf16String::DecodeCharacter(*this);
}

size_t Utf16Char::size() const
{
	return characterData.size();
}

