#include <assert.h>

#include <utfstring/UtfString.h>

using namespace UtfString;
using namespace std;

/*UnicodeChar Definition*/

UnicodeChar::UnicodeChar() :
	m_utf8CharacterData(NULL), m_utf16CharacterData(NULL)
{

}

UnicodeChar::UnicodeChar(const UnicodeChar& character) :
	m_utf8CharacterData(NULL), m_utf16CharacterData(NULL)
{
	if(character.m_utf8CharacterData != NULL)
	{
		m_utf8CharacterData = new Utf8Char(*character.m_utf8CharacterData);
	}
	else if(character.m_utf16CharacterData != NULL)
	{
		m_utf16CharacterData = new Utf16Char(*character.m_utf16CharacterData);
	}
}

UnicodeChar::UnicodeChar(const Utf16Char& character) :
	m_utf8CharacterData(NULL)
{
	m_utf16CharacterData = new Utf16Char(character);
}

UnicodeChar::UnicodeChar(const Utf8Char& character) :
	m_utf16CharacterData(NULL)
{
	m_utf8CharacterData = new Utf8Char(character);
}

UnicodeChar::~UnicodeChar()
{
	if(m_utf8CharacterData != NULL)
	{
		delete m_utf8CharacterData;
		m_utf8CharacterData = NULL;
	}
	else if(m_utf16CharacterData != NULL)
	{
		delete m_utf16CharacterData;
		m_utf16CharacterData = NULL;
	}

	//If the UTF-8 or UTF-16 characters aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8CharacterData == NULL);
	assert(m_utf16CharacterData == NULL);
}

bool UnicodeChar::operator==(const UnicodeChar& otherCharacter) const
{
	bool equal = false;

	//If both characters are empty, then their values are equal
	if(this->empty() && otherCharacter.empty())
	{
		equal = true;
	}

	//If neither of the characters are empty, then we need to compare them
	else if(!this->empty() && !otherCharacter.empty())
	{
		if(m_utf8CharacterData != NULL)
		{
			if(otherCharacter.m_utf8CharacterData != NULL)
			{
				equal = (*m_utf8CharacterData == *otherCharacter.m_utf8CharacterData);
			}

			//We can safely assume that otherCharacter.m_utf16CharacterData != NULL because 
			//otherCharacter.is_empty() is false
			else
			{
				equal = (*m_utf8CharacterData == *otherCharacter.m_utf16CharacterData);
			}
		}

		//We can safely assume that m_utf16CharacterData != NULL because this->is_empty() is false
		else
		{
			if(otherCharacter.m_utf16CharacterData != NULL)
			{
				equal = (*m_utf16CharacterData == *otherCharacter.m_utf16CharacterData);
			}

			//We can safely assume that otherCharacter.m_utf8CharacterData != NULL because 
			//otherCharacter.is_empty() is false
			else
			{
				equal = (*m_utf16CharacterData == *otherCharacter.m_utf8CharacterData);
			}
		}
	}

	//If one character has data and the other doesn't, then they are unequal.
	//In this case, nothing further needs to be done

	return equal;
}

bool UnicodeChar::operator==(const Utf8Char& character) const
{
	bool equal = false;

	//If both characters are empty, then their values are equal
	if(this->empty() && character.size() == 0)
	{
		equal = true;
	}

	//If neither of the characters are empty, then we need to compare them
	else if(!this->empty() && character.size() != 0)
	{
		if(m_utf8CharacterData != NULL)
		{
			equal = (*m_utf8CharacterData == character);
		}

		//We can safely assume that m_utf16CharacterData != NULL because this->is_empty() is false
		else
		{
			equal = (*m_utf16CharacterData == character);
		}
	}

	return equal;
}

bool UnicodeChar::operator==(const Utf16Char& character) const
{
	bool equal = false;

	//If both characters are empty, then their values are equal
	if(this->empty() && character.size() == 0)
	{
		equal = true;
	}

	//If neither of the characters are empty, then we need to compare them
	else if(!this->empty() && character.size() != 0)
	{
		if(m_utf16CharacterData != NULL)
		{
			equal = (*m_utf16CharacterData == character);
		}

		//We can safely assume that m_utf8CharacterData != NULL because this->is_empty() is false
		else
		{
			equal = (*m_utf8CharacterData == character);
		}
	}

	return equal;
}

bool UnicodeChar::operator==(const UnicodeCharReference& characterReference) const
{
	bool equal = false;

	//We should never have an empty character reference
	assert(characterReference.internal_encoding() != ENCODING_NONE);

	equal = (*this == (UnicodeChar)characterReference);

	return equal;
}

bool UnicodeChar::operator==(const Utf8CharReference& characterReference) const
{
	return (*this == (Utf8Char)characterReference);
}

bool UnicodeChar::operator==(const Utf16CharReference& characterReference) const
{
	return (*this == (Utf16Char)characterReference);
}

bool UnicodeChar::operator!=(const UnicodeChar& otherCharacter) const
{
	return !(*this == otherCharacter);
}

bool UnicodeChar::operator!=(const Utf8Char& character) const
{
	return !(*this == character);
}

bool UnicodeChar::operator!=(const Utf16Char& character) const
{
	return !(*this == character);
}

bool UnicodeChar::operator!=(const UnicodeCharReference& characterReference) const
{
	return !(*this == characterReference);
}

bool UnicodeChar::operator!=(const Utf8CharReference& characterReference) const
{
	return !(*this == characterReference);
}

bool UnicodeChar::operator!=(const Utf16CharReference& characterReference) const
{
	return !(*this == characterReference);
}

UnicodeChar& UnicodeChar::operator=(const UnicodeChar& character)
{
	if(m_utf8CharacterData != NULL)
	{
		delete m_utf8CharacterData;
		m_utf8CharacterData = NULL;
	}
	else if(m_utf16CharacterData != NULL)
	{
		delete m_utf16CharacterData;
		m_utf16CharacterData = NULL;
	}

	if(character.m_utf8CharacterData != NULL)
	{
		m_utf8CharacterData = new Utf8Char(*character.m_utf8CharacterData);
	}
	else if(character.m_utf16CharacterData != NULL)
	{
		m_utf16CharacterData = new Utf16Char(*character.m_utf16CharacterData);
	}

	return *this;
}

UnicodeChar& UnicodeChar::operator=(const Utf8Char& character)
{
	if(m_utf8CharacterData != NULL)
	{
		delete m_utf8CharacterData;
	}
	else if(m_utf16CharacterData != NULL)
	{
		delete m_utf16CharacterData;
		m_utf16CharacterData = NULL;
	}

	m_utf8CharacterData = new Utf8Char(character);

	return *this;
}

UnicodeChar& UnicodeChar::operator=(const Utf16Char& character)
{
	if(m_utf16CharacterData != NULL)
	{
		delete m_utf16CharacterData;
	}
	else if(m_utf8CharacterData != NULL)
	{
		delete m_utf8CharacterData;
		m_utf8CharacterData = NULL;
	}

	m_utf16CharacterData = new Utf16Char(character);

	return *this;
}

UnicodeChar& UnicodeChar::operator=(const Utf8CharReference& characterReference)
{
	return (*this = (Utf8Char)characterReference);
}

UnicodeChar& UnicodeChar::operator=(const Utf16CharReference& characterReference)
{
	return (*this = (Utf8Char)characterReference);
}

UnicodeChar::operator Utf16Char() const
{
	if(m_utf16CharacterData != NULL)
	{
		return *m_utf16CharacterData;
	}

	else if(m_utf8CharacterData != NULL)
	{
		return (Utf16Char)*m_utf8CharacterData;
	}

	else
	{
		return Utf16Char();
	}
}

UnicodeChar::operator Utf8Char() const
{
	if(m_utf8CharacterData != NULL)
	{
		return *m_utf8CharacterData;
	}

	else if(m_utf16CharacterData != NULL)
	{
		return (Utf8Char)*m_utf16CharacterData;
	}

	else
	{
		return Utf8Char();
	}
}

void UnicodeChar::clear()
{
	if(m_utf8CharacterData != NULL)
	{
		delete m_utf8CharacterData;
		m_utf8CharacterData = NULL;
	}
	else if(m_utf16CharacterData != NULL)
	{
		delete m_utf16CharacterData;
		m_utf16CharacterData = NULL;
	}

	//If the UTF-8 or UTF-16 character aren't null, that means that both were non-null before
	//this function was called.  That shouldn't ever happen.
	assert(m_utf8CharacterData == NULL);
	assert(m_utf16CharacterData == NULL);
}

bool UnicodeChar::empty() const
{
	bool isEmpty = true;

	if(m_utf8CharacterData != NULL || m_utf16CharacterData != NULL)
	{
		isEmpty = false;
	}

	return isEmpty;
}

const UtfEncoding UnicodeChar::internal_encoding() const
{
	UtfEncoding encoding = ENCODING_NONE;

	if(m_utf8CharacterData != NULL)
	{
		encoding = ENCODING_UTF8;
	}
	else if(m_utf16CharacterData != NULL)
	{
		encoding = ENCODING_UTF16;
	}

	return encoding;
}

bool UnicodeChar::is_valid() const
{
	bool isValid = false;

	if((m_utf8CharacterData != NULL && m_utf8CharacterData->is_valid()) ||
		(m_utf16CharacterData != NULL && m_utf16CharacterData->is_valid()))
	{
		isValid = true;
	}

	return isValid;
}

UInt32 UnicodeChar::to_utf_32() const
{
	assert(is_valid());

	UInt32 characterValue = 0xFFFFFFFF;

	if(m_utf8CharacterData != NULL)
	{
		characterValue = m_utf8CharacterData->to_utf_32();
	}
	else if(m_utf16CharacterData != NULL)
	{
		characterValue = m_utf16CharacterData->to_utf_32();
	}

	return characterValue;
}
