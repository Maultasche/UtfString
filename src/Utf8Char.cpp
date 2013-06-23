#include <assert.h>

#include <utfstring/UtfString.h>

using namespace UtfString;
using namespace std;

/*Utf8Char Definition*/

Utf8Char::Utf8Char()
{

}

Utf8Char::Utf8Char(const std::string::iterator& basicStringIterator, size_t codeUnitCount)
{
	switch(codeUnitCount)
	{
	case 0:
		break;
	case 1:
		characterData.append(1, *basicStringIterator);
		break;
	case 2:
		characterData.append(1, *basicStringIterator);
		characterData.append(1, *(basicStringIterator + 1));
		break;
	case 3:
		characterData.append(1, *basicStringIterator);
		characterData.append(1, *(basicStringIterator + 1));
		characterData.append(1, *(basicStringIterator + 2));
		break;
	case 4:
		characterData.append(1, *basicStringIterator);
		characterData.append(1, *(basicStringIterator + 1));
		characterData.append(1, *(basicStringIterator + 2));
		characterData.append(1, *(basicStringIterator + 3));
		break;
	default:
		//If a UTF-8 character has more than four code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}
}

Utf8Char::Utf8Char(const std::string::const_iterator& basicStringIterator, size_t codeUnitCount)
{
	switch(codeUnitCount)
	{
	case 0:
		break;
	case 1:
		characterData.append(1, *basicStringIterator);
		break;
	case 2:
		characterData.append(1, *basicStringIterator);
		characterData.append(1, *(basicStringIterator + 1));
		break;
	case 3:
		characterData.append(1, *basicStringIterator);
		characterData.append(1, *(basicStringIterator + 1));
		characterData.append(1, *(basicStringIterator + 2));
		break;
	case 4:
		characterData.append(1, *basicStringIterator);
		characterData.append(1, *(basicStringIterator + 1));
		characterData.append(1, *(basicStringIterator + 2));
		characterData.append(1, *(basicStringIterator + 3));
		break;
	default:
		//If a UTF-8 character has more than four code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}
}

Utf8Char::Utf8Char(const char character)
{
	characterData.append(1, character);
}

Utf8Char::Utf8Char(const char* character)
{
	assert(character != NULL);

	size_t length = strlen(character);
	char codeUnit;

	if(length == 1)
	{
		codeUnit = character[0];
		characterData.append(1, codeUnit);
	}
	else if(length == 2)
	{
		codeUnit = character[0];
		characterData.append(1, codeUnit);
		codeUnit = character[1];
		characterData.append(1, codeUnit);
	}
	else if(length == 3)
	{
		codeUnit = character[0];
		characterData.append(1, codeUnit);
		codeUnit = character[1];
		characterData.append(1, codeUnit);
		codeUnit = character[2];
		characterData.append(1, codeUnit);
	}
	else if(length >= 4)
	{
		codeUnit = character[0];
		characterData.append(1, codeUnit);
		codeUnit = character[1];
		characterData.append(1, codeUnit);
		codeUnit = character[2];
		characterData.append(1, codeUnit);
		codeUnit = character[3];
		characterData.append(1, codeUnit);
	}
}

Utf8Char::Utf8Char(const Utf8Char& character)
{
    *this = character;
}

Utf8Char::~Utf8Char()
{

}

bool Utf8Char::operator==(const Utf8Char& otherCharacter) const
{
	return characterData == otherCharacter.characterData;
}

bool Utf8Char::operator!=(const Utf8Char& otherCharacter) const
{
	return !(characterData == otherCharacter.characterData);
}

bool Utf8Char::operator==(const Utf8CharReference& characterReference) const
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
		case 3:
			valueEquality = ((*this)[0] == characterReference[0]) &&
				((*this)[1] == characterReference[1]) && ((*this)[2] == characterReference[2]);
			break;
		case 4:
			valueEquality = ((*this)[0] == characterReference[0]) &&
				((*this)[1] == characterReference[1]) && ((*this)[2] == characterReference[2]) &&
				((*this)[3] == characterReference[3]);
			break;
		default:
			//If we've reached this point, something has gone wrong. So trigger an assertion failure
			assert(false);
			break;
		}
	}

	return valueEquality;
}

bool Utf8Char::operator!=(const Utf8CharReference& characterReference) const
{
	return !(operator==(characterReference));
}


Utf8Char& Utf8Char::operator=(const Utf8Char& anotherCharacter)
{
	characterData = anotherCharacter.characterData;

	return *this;
}

Utf8Char& Utf8Char::operator=(const Utf8CharReference& characterReference)
{
	switch(characterReference.size())
	{
	case 4:
		characterData.clear();
		characterData.append(1, characterReference[0]);
		characterData.append(1, characterReference[1]);
		characterData.append(1, characterReference[2]);
		characterData.append(1, characterReference[3]);
		break;
	case 3:
		characterData.clear();
		characterData.append(1, characterReference[0]);
		characterData.append(1, characterReference[1]);
		characterData.append(1, characterReference[2]);
		break;
	case 2:
		characterData.clear();
		characterData.append(1, characterReference[0]);
		characterData.append(1, characterReference[1]);
		break;
	case 1:
		characterData.clear();
		characterData.append(1, characterReference[0]);
		break;
	case 0:
		break;
	default:
		//If a UTF-8 character has more than four code units, something has gone wrong.
		//So trigger an assertion failure
		assert(false);
		break;
	}

	return *this;
}

char& Utf8Char::operator[](const size_t index)
{
	//The index should be less than the max number of possible code units
	assert(index < Utf8CodeUnitMax);

	//If the index is outside the bounds of the character data string, the character data string
	//needs to be expanded.
	if(index >= characterData.size())
	{
		characterData.resize(index + 1, ' ');
	}

	return characterData[index];
}

const char& Utf8Char::operator[](const size_t index) const
{
	//The index should be less than the max number of possible code units
	assert(index < Utf8CodeUnitMax);

	return characterData[index];
}

Utf8Char::operator Utf16Char() const
{
	assert(is_valid());

	//Create the buffers to hold the code units for the UTF-16 character and its UTF-8
	//equivalent
	UInt16 utf16CodeUnits[2];
	char utf8CodeUnits[4];
	size_t utf16CodeUnitCount = 2;

	//Copy the UTF-8 code units to the buffer
	for(size_t codeUnitIndex = 0; codeUnitIndex < characterData.size(); ++codeUnitIndex)
	{
		utf8CodeUnits[codeUnitIndex] = characterData[codeUnitIndex];
	}

	//Convert to UTF-16
	UtfStringConverter::Utf8ToUtf16Char(utf8CodeUnits, characterData.size(), utf16CodeUnits, utf16CodeUnitCount);

	//Put the UTF-16 code units in a Utf16Char object and return it
	Utf16Char utf16Char;

	utf16Char[0] = utf16CodeUnits[0];

	if(utf16CodeUnitCount > 1)
	{
		utf16Char[1] = utf16CodeUnits[1];
	}

	return utf16Char;
}

const char* Utf8Char::c_str() const
{
	return characterData.c_str();
}

void Utf8Char::clear()
{
	characterData.clear();
}

bool Utf8Char::is_valid() const
{
	return Utf8String::IsValidCharacter(*this);
}

UInt32 Utf8Char::to_utf_32() const
{
	assert(size() >= 1 || size() <= 4);

	return Utf8String::DecodeCharacter(*this);
}

size_t Utf8Char::size() const
{
	return characterData.size();
}

Utf8Char Utf8Char::GetNextCharacter(std::istream& inputStream)
{
	Utf8Char utf8Character;

	char utf8CodeUnit;

	//Read in the first code unit from the stream
	inputStream.read(&utf8CodeUnit, sizeof(char));

	if(!inputStream.eof())
	{
		//Look at the first code unit and use that to get the number of code units in
		//the current code point
		size_t characterCodeUnitCount = Utf8String::CharacterCodeUnitCount(&utf8CodeUnit);

		//This code unit count had better be 4 or less, or something went wrong
		assert(characterCodeUnitCount <= 4);

		//If the code unit count is 1-4, then we need to collect all the code units
		if(characterCodeUnitCount >= 1)
		{
			//Store the first code unit
			utf8Character[0] = utf8CodeUnit;

			//Now read in the rest of the code units
			for(size_t count = 1; count < characterCodeUnitCount && !inputStream.eof(); ++count)
			{
				inputStream.read((char*)&utf8CodeUnit, sizeof(char));

				if(!inputStream.eof())
				{
					//Get the code unit count of a code point starting with this code unit
					size_t codeUnitCount = Utf8String::CharacterCodeUnitCount(&utf8CodeUnit);

					//If the code unit is the beginning code unit of another code point,
					//then we need to stop reading any more code units and continue to the
					//next code point.
					if(codeUnitCount != 0)
					{
						//So that we start at the beginning of the next code point, we need
						//to back up one code unit
						inputStream.seekg(-1, std::ios_base::cur);

						break;
					}

					//Store the code unit
					utf8Character[count] = utf8CodeUnit;
				}
			}
		}

		//If the code unit count comes back as 0, then we are looking at an invalid
		//UTF-8 byte stream.  This function doesn't concern itself with validity,
		//so just append the code unit and move on to the next code point.
		else
		{
			utf8Character[0] = utf8CodeUnit;
		}
	}

	return utf8Character;
}

