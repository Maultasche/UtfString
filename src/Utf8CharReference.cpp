/*!
\file Utf8CharReference.cpp

This file contains the definition of the Utf8CharReference class.
*/

#include <assert.h>

#include <utfstring/UtfString.h>

using namespace UtfString;
using namespace std;

/*Utf8CharReference Definition*/

Utf8CharReference::Utf8CharReference(std::string& codeUnitString,
									 std::string::iterator& basicStringIterator,
									 size_t characterCount) :
  codeUnitString(codeUnitString), codeUnitIterator(basicStringIterator), codeUnitCount(characterCount)
{
	//The code unit count should be greater than 0 and less than or equal to max number of possible code units
	assert(codeUnitCount > 0 && codeUnitCount <= Utf8CodeUnitMax);
}

Utf8CharReference::Utf8CharReference(const Utf8CharReference& otherCharacterReference) :
	codeUnitString(otherCharacterReference.codeUnitString), codeUnitIterator(otherCharacterReference.codeUnitIterator),
	codeUnitCount(otherCharacterReference.codeUnitCount)
{

}

bool Utf8CharReference::operator==(const Utf8CharReference& otherCharacterReference) const
{
	bool valueEquality = false;

	switch(codeUnitCount)
	{
	case 4:
		valueEquality = ((*codeUnitIterator) == (*otherCharacterReference.codeUnitIterator)) &&
			((*(codeUnitIterator + 1)) == (*(otherCharacterReference.codeUnitIterator + 1))) &&
			((*(codeUnitIterator + 2)) == (*(otherCharacterReference.codeUnitIterator + 2))) &&
			((*(codeUnitIterator + 3)) == (*(otherCharacterReference.codeUnitIterator + 3)));
		break;
	case 3:
		valueEquality = ((*codeUnitIterator) == (*otherCharacterReference.codeUnitIterator)) &&
			((*(codeUnitIterator + 1)) == (*(otherCharacterReference.codeUnitIterator + 1))) &&
			((*(codeUnitIterator + 2)) == (*(otherCharacterReference.codeUnitIterator + 2)));
		break;
	case 2:
		valueEquality = ((*codeUnitIterator) == (*otherCharacterReference.codeUnitIterator)) &&
			((*(codeUnitIterator + 1)) == (*(otherCharacterReference.codeUnitIterator + 1)));
		break;
	case 1:
		valueEquality = (*codeUnitIterator) == (*otherCharacterReference.codeUnitIterator);
		break;
	case 0:
		valueEquality = true;
		break;
	default:
		//If a UTF-8 character has more than four code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}

	return valueEquality;
}

bool Utf8CharReference::operator!=(const Utf8CharReference& otherCharacterReference) const
{
	return !(operator==(otherCharacterReference));
}

bool Utf8CharReference::operator==(const Utf8Char& character) const
{
	bool valueEquality = false;

	if(character.size() == codeUnitCount)
	{
		switch(codeUnitCount)
		{
		case 4:
			valueEquality = ((*codeUnitIterator) == character[0]) &&
				((*(codeUnitIterator + 1)) == character[1]) &&
				((*(codeUnitIterator + 2)) == character[2]) &&
				((*(codeUnitIterator + 3)) == character[3]);
			break;
		case 3:
			valueEquality = ((*codeUnitIterator) == character[0]) &&
				((*(codeUnitIterator + 1)) == character[1]) &&
				((*(codeUnitIterator + 2)) == character[2]);
			break;
		case 2:
			valueEquality = ((*codeUnitIterator) == character[0]) &&
				((*(codeUnitIterator + 1)) == character[1]);
			break;
		case 1:
			valueEquality = (*codeUnitIterator) == character[0];
			break;
		case 0:
			valueEquality = true;
			break;
		default:
			//If a UTF-8 character has more than two code units, something has gone wrong.
			//So trigger an assertion failure
			assert(false);
			break;
		}
	}

	return valueEquality;

}

bool Utf8CharReference::operator!=(const Utf8Char& character) const
{
	return !(operator==(character));
}

Utf8CharReference& Utf8CharReference::operator=(const Utf8CharReference& otherCharacterReference)
{
	return operator=((Utf8Char)otherCharacterReference);
}

Utf8CharReference& Utf8CharReference::operator=(const Utf8Char& utf8Char)
{
	//If the code unit count of the character being assigned is different than the character being
	//referenced, then we're going to have to move stuff around
	if(utf8Char.size() != codeUnitCount)
	{
		std::string characterString;

		//Package the character contents in a string so that we can pass it to the replace() function
		switch(utf8Char.size())
		{
		case 4:
			characterString.append(1, utf8Char[0]);
			characterString.append(1, utf8Char[1]);
			characterString.append(1, utf8Char[2]);
			characterString.append(1, utf8Char[3]);
			break;
		case 3:
			characterString.append(1, utf8Char[0]);
			characterString.append(1, utf8Char[1]);
			characterString.append(1, utf8Char[2]);
			break;
		case 2:
			characterString.append(1, utf8Char[0]);
			characterString.append(1, utf8Char[1]);
			break;
		case 1:
			characterString.append(1, utf8Char[0]);
			break;
		default:
			//If a UTF-8 character has more than two code units, something has gone wrong.
			//So trigger an assertion failure
			assert(false);
			break;
		}

		//Save the iterator offset so that we can recreate the iterator, which may become invalidated
		//due to the replace() function call
		size_t iteratorOffset = codeUnitIterator - codeUnitString.begin();

		//Replace the old code units with the new code units
		codeUnitString.replace(codeUnitIterator, codeUnitIterator + codeUnitCount, characterString.begin(), characterString.end());

		//Since we are assigning a new character value of different code unit size to this iterator, 
		//we need to update the code unit count
		codeUnitCount = characterString.size();

		//Now recreate the iterator at the same position
		codeUnitIterator = codeUnitString.begin() + iteratorOffset;
	}
	else
	{
		switch(utf8Char.size())
		{
		case 4:
			*(codeUnitIterator + 3) = utf8Char[3];
		case 3:
			*(codeUnitIterator + 2) = utf8Char[2];
		case 2:
			*(codeUnitIterator + 1) = utf8Char[1];
		case 1:
			*codeUnitIterator = utf8Char[0];
			break;
		case 0:
			break;
		default:
			//If a UTF-8 character has more than two code units, something has gone wrong.
			//So trigger an assertion failure
			assert(false);
			break;
		}
	}

	return *this;
}

char& Utf8CharReference::operator[](const size_t index)
{
	//The index should be less than the max number of possible code units
	assert(index < Utf8CodeUnitMax);
	//The index should not go beyond the size of the character
	assert(index < size());

	return *(codeUnitIterator + index);
}

const char& Utf8CharReference::operator[](const size_t index) const
{
	//The index should be less than the max number of possible code units
	assert(index < Utf8CodeUnitMax);
	//The index should not go beyond the size of the character
	assert(index < size());

	return *(codeUnitIterator + index);
}

Utf8CharReference::operator Utf8Char() const
{
	return UtfString::Utf8Char(codeUnitIterator, codeUnitCount);
}

Utf8CharReference::operator Utf16Char() const
{
	assert(is_valid());

	//Create the buffers to hold the code units for the UTF-16 character and its UTF-8
	//equivalent
	UInt16 utf16CodeUnits[2];
	char utf8CodeUnits[4];
	size_t utf16CodeUnitCount;

	//Copy the UTF-8 code units to the buffer
	for(size_t codeUnitIndex = 0; codeUnitIndex < codeUnitCount; ++codeUnitIndex)
	{
		utf8CodeUnits[codeUnitIndex] = *(codeUnitIterator + codeUnitIndex);
	}

	//Convert to UTF-16
	UtfStringConverter::Utf8ToUtf16Char(utf8CodeUnits, codeUnitCount, utf16CodeUnits, utf16CodeUnitCount);

	//Put the UTF-16 code units in a Utf16Char object and return it
	Utf16Char utf16Char;

	utf16Char[0] = utf16CodeUnits[0];

	if(utf16CodeUnitCount > 1)
	{
		utf16Char[1] = utf16CodeUnits[1];
	}

	return utf16Char;
}

void Utf8CharReference::assign_reference(const Utf8CharReference& otherCharacterReference)
{
	codeUnitString = otherCharacterReference.codeUnitString;
	codeUnitIterator = otherCharacterReference.codeUnitIterator;
	codeUnitCount = otherCharacterReference.codeUnitCount;

	//The code unit count should be greater than 0 and less than or equal to max number of possible code units
	assert(codeUnitCount > 0 && codeUnitCount <= Utf8CodeUnitMax);
}

bool Utf8CharReference::is_valid() const
{
	return Utf8String::IsValidCharacter(*this);
}

bool Utf8CharReference::reference_equal(const Utf8CharReference& otherCharacterReference)
{
	return codeUnitIterator == otherCharacterReference.codeUnitIterator;
}

bool Utf8CharReference::reference_not_equal(const Utf8CharReference& otherCharacterReference)
{
	return codeUnitIterator != otherCharacterReference.codeUnitIterator;
}

UInt32 Utf8CharReference::to_utf_32() const
{
	assert(size() >+ 1 || size() <= 4);

	return Utf8String::DecodeCharacter(*this);
}

size_t Utf8CharReference::size() const
{
	return codeUnitCount;
}

