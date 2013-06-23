/*!
\file Utf16CharReference.cpp

This file contains the definition of the Utf16CharReference class.
*/

#include <assert.h>

#include <utfstring/UtfString.h>

using namespace UtfString;
using namespace std;

/*Utf16CharReference Definition*/

Utf16CharReference::Utf16CharReference(std::basic_string<UInt16>& codeUnitString,
									   std::basic_string<UInt16>::iterator& basicStringIterator,
									   size_t characterCount) :
  codeUnitString(codeUnitString), codeUnitIterator(basicStringIterator), codeUnitCount(characterCount)
{
	//The code unit count should be greater than 0 and less than or equal to max number of possible code units
	assert(codeUnitCount > 0 && codeUnitCount <= Utf16CodeUnitMax);
}

Utf16CharReference::Utf16CharReference(const Utf16CharReference& otherCharacterReference) :
	codeUnitString(otherCharacterReference.codeUnitString), codeUnitIterator(otherCharacterReference.codeUnitIterator),
	codeUnitCount(otherCharacterReference.codeUnitCount)
{

}

bool Utf16CharReference::operator==(const Utf16CharReference& otherCharacterReference) const
{
	bool valueEquality = false;

	switch(codeUnitCount)
	{
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
		//If a UTF-16 character has more than two code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}

	return valueEquality;
}

bool Utf16CharReference::operator!=(const Utf16CharReference& otherCharacterReference) const
{
	return !(operator==(otherCharacterReference));
}

bool Utf16CharReference::operator==(const Utf16Char& character) const
{
	bool valueEquality = false;

	if(character.size() == codeUnitCount)
	{
		switch(codeUnitCount)
		{
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
			//If a UTF-16 character has more than two code units, something has gone wrong.
			//So trigger an assertion failure
			assert(false);
			break;
		}
	}

	return valueEquality;

}

bool Utf16CharReference::operator!=(const Utf16Char& character) const
{
	return !(operator==(character));
}

Utf16CharReference& Utf16CharReference::operator=(const Utf16CharReference& otherCharacterReference)
{
	return operator=((Utf16Char)otherCharacterReference);
}

Utf16CharReference& Utf16CharReference::operator=(const Utf16Char& utf16Char)
{
	//If the code unit count of the character being assigned is different than the character being
	//referenced, then we're going to have to move stuff around
	if(utf16Char.size() != codeUnitCount)
	{
		//The character being referenced is one code unit and the character being assigned is
		//two code units
		if(codeUnitCount == 1)
		{
			assert(utf16Char.size() == 2);

			//Package the character contents in a string so that we can pass it to the replace() function
			basic_string<UInt16> characterString;
			characterString.append(&utf16Char[0], 1);
			characterString.append(&utf16Char[1], 1);

			//Save the iterator offset so that we can recreate the iterator, which may become invalidated
			//due to the replace() function call
			size_t iteratorOffset = codeUnitIterator - codeUnitString.begin();

			//Replace the old code units with the new code units
			codeUnitString.replace(codeUnitIterator, codeUnitIterator + 1, characterString.begin(), characterString.end());

			//Now recreate the iterator at the same position
			codeUnitIterator = codeUnitString.begin() + iteratorOffset;
		}

		//The character being referenced is two code units and the character being assigned is one
		//code unit
		else
		{
			assert(codeUnitCount == 2 && utf16Char.size() == 1);

			//Package the character contents in a string so that we can pass it to the replace() function
			basic_string<UInt16> characterString;
			characterString.append(&utf16Char[0], 1);

			//Save the iterator offset so that we can recreate the iterator, which may become invalidated
			//due to the replace() function call
			size_t iteratorOffset = codeUnitIterator - codeUnitString.begin();

			//Replace the old code units with the new code units
			codeUnitString.replace(codeUnitIterator, codeUnitIterator + 2, characterString.begin(), characterString.end());

			//Now recreate the iterator at the same position
			codeUnitIterator = codeUnitString.begin() + iteratorOffset;
		}

		//Now that the assignment is complete, update the code unit count
		codeUnitCount = utf16Char.size();
	}
	else
	{
		switch(utf16Char.size())
		{
		case 2:
			*(codeUnitIterator + 1) = utf16Char[1];
		case 1:
			*codeUnitIterator = utf16Char[0];
			break;
		case 0:
			break;
		default:
			//If a UTF-16 character has more than two code units, something has gone wrong.
			//So trigger an assertion failure
			assert(false);
			break;
		}
	}

	return *this;
}

UInt16& Utf16CharReference::operator[](const size_t index)
{
	//The index should be less than the max number of possible code units
	assert(index < Utf16CodeUnitMax);
	//The index should not go beyond the size of the character
	assert(index < size());

	return *(codeUnitIterator + index);
}

const UInt16& Utf16CharReference::operator[](const size_t index) const
{
	//The index should be less than the max number of possible code units
	assert(index < Utf16CodeUnitMax);
	//The index should not go beyond the size of the character
	assert(index < size());

	return *(codeUnitIterator + index);
}

Utf16CharReference::operator Utf16Char() const
{
	return UtfString::Utf16Char(codeUnitIterator, codeUnitCount);
}

Utf16CharReference::operator Utf8Char() const
{
	assert(is_valid());

	//Create the buffers to hold the code units for the UTF-16 character and its UTF-8
	//equivalent
	UInt16 utf16CodeUnits[2];
	char utf8CodeUnits[4];
	size_t utf8CodeUnitCount = 4;

	//Copy the UTF-16 code units to the buffer
	utf16CodeUnits[0] = *codeUnitIterator;

	if(codeUnitCount > 1)
	{
		utf16CodeUnits[1] = *(codeUnitIterator + 1);
	}

	//Convert to UTF-8
	UtfStringConverter::Utf16ToUtf8Char(utf16CodeUnits, codeUnitCount, utf8CodeUnits, utf8CodeUnitCount);

	//Put the UTF-8 code units in a Utf8Char object and return it
	Utf8Char utf8Char;

	for(size_t codeUnitIndex = 0; codeUnitIndex < utf8CodeUnitCount; ++codeUnitIndex)
	{
		utf8Char[codeUnitIndex] = utf8CodeUnits[codeUnitIndex];
	}

	return utf8Char;
}

void Utf16CharReference::assign_reference(const Utf16CharReference& otherCharacterReference)
{
	codeUnitString = otherCharacterReference.codeUnitString;
	codeUnitIterator = otherCharacterReference.codeUnitIterator;
	codeUnitCount = otherCharacterReference.codeUnitCount;

	//The code unit count should be greater than 0 and less than or equal to max number of possible code units
	assert(codeUnitCount > 0 && codeUnitCount <= Utf16CodeUnitMax);
}

bool Utf16CharReference::is_valid() const
{
	return Utf16String::IsValidCharacter(*this);
}

bool Utf16CharReference::reference_equal(const Utf16CharReference& otherCharacterReference)
{
	return codeUnitIterator == otherCharacterReference.codeUnitIterator;
}

bool Utf16CharReference::reference_not_equal(const Utf16CharReference& otherCharacterReference)
{
	return codeUnitIterator != otherCharacterReference.codeUnitIterator;
}

UInt32 Utf16CharReference::to_utf_32() const
{
	assert(size() == 1 || size() == 2);

	return Utf16String::DecodeCharacter(*this);
}

size_t Utf16CharReference::size() const
{
	return codeUnitCount;
}

