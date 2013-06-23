/*!
\file UnicodeCharReference.cpp

This file contains the definition of the UnicodeCharReference class.
*/

#include <assert.h>

#include <utfstring/UtfString.h>

using namespace UtfString;
using namespace std;

/*UnicodeCharReference Definition*/

/*Constructors*/

UnicodeCharReference::UnicodeCharReference(const UnicodeCharReference& unicodeCharReference) :
	m_utf16CharacterReference(NULL), m_utf8CharacterReference(NULL)
{
	if(unicodeCharReference.m_utf16CharacterReference != NULL)
	{
		m_utf16CharacterReference = new Utf16CharReference(*unicodeCharReference.m_utf16CharacterReference);
	}
	else
	{
		m_utf8CharacterReference = new Utf8CharReference(*unicodeCharReference.m_utf8CharacterReference);
	}
}

UnicodeCharReference::UnicodeCharReference(const Utf8CharReference& utf8CharReference) :
	m_utf16CharacterReference(NULL)
{
	m_utf8CharacterReference = new Utf8CharReference(utf8CharReference);
}

UnicodeCharReference::UnicodeCharReference(const Utf16CharReference& utf16CharReference) :
	m_utf8CharacterReference(NULL)
{
	m_utf16CharacterReference = new Utf16CharReference(utf16CharReference);
}

UnicodeCharReference::~UnicodeCharReference()
{
	if(m_utf8CharacterReference != NULL)
	{
		delete m_utf8CharacterReference;
		m_utf8CharacterReference = NULL;
	}
	else if(m_utf16CharacterReference != NULL)
	{
		delete m_utf16CharacterReference;
		m_utf16CharacterReference = NULL;
	}

	//If the UTF-8 or UTF-16 character references aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8CharacterReference == NULL);
	assert(m_utf16CharacterReference == NULL);
}

/*Operators*/

bool UnicodeCharReference::operator==(const UnicodeCharReference& otherCharacterReference) const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);
	assert(otherCharacterReference.m_utf8CharacterReference != NULL || 
		otherCharacterReference.m_utf16CharacterReference != NULL);

	bool equal = false;

	if(m_utf8CharacterReference != NULL)
	{
		if(otherCharacterReference.m_utf8CharacterReference != NULL)
		{
			equal = (*m_utf8CharacterReference == *otherCharacterReference.m_utf8CharacterReference);
		}

		//We can safely assume that otherCharacterReference.m_utf16CharacterReference != NULL because 
		//otherCharacterReference.is_empty() is false
		else
		{
			equal = (*m_utf8CharacterReference == *otherCharacterReference.m_utf16CharacterReference);
		}
	}

	//We can safely assume that m_utf16CharacterReference != NULL because this->is_empty() is false
	else
	{
		if(otherCharacterReference.m_utf16CharacterReference != NULL)
		{
			equal = (*m_utf16CharacterReference == *otherCharacterReference.m_utf16CharacterReference);
		}

		//We can safely assume that otherCharacterReference.m_utf8CharacterReference != NULL because 
		//otherCharacterReference.is_empty() is false
		else
		{
			equal = (*m_utf16CharacterReference == *otherCharacterReference.m_utf8CharacterReference);
		}
	}

	return equal;
}

bool UnicodeCharReference::operator==(const Utf8CharReference& characterReference) const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	bool equal = false;

	if(m_utf8CharacterReference != NULL)
	{
		equal = (*m_utf8CharacterReference == characterReference);
	}

	//We can safely assume that m_utf16CharacterReference != NULL because this->is_empty() is false
	else
	{
		equal = (*m_utf16CharacterReference == characterReference);
	}

	return equal;
}

bool UnicodeCharReference::operator==(const Utf16CharReference& characterReference) const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	bool equal = false;

	if(m_utf8CharacterReference != NULL)
	{
		equal = (*m_utf8CharacterReference == characterReference);
	}

	//We can safely assume that m_utf16CharacterReference != NULL because this->is_empty() is false
	else
	{
		equal = (*m_utf16CharacterReference == characterReference);
	}

	return equal;
}

bool UnicodeCharReference::operator==(const UnicodeChar& character) const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	bool equal = false;

	if(m_utf8CharacterReference != NULL)
	{
		if(character.internal_encoding() == ENCODING_UTF8)
		{
			equal = (*m_utf8CharacterReference == character);
		}
		else
		{
			equal = (*m_utf8CharacterReference == (Utf8Char)(character));
		}
	}

	//We can safely assume that m_utf16CharacterReference != NULL because this->is_empty() is false
	else
	{
		if(character.internal_encoding() == ENCODING_UTF16)
		{
			equal = (*m_utf16CharacterReference == character);
		}
		else
		{
			equal = (*m_utf16CharacterReference == (Utf16Char)(character));
		}
	}

	return equal;
}

bool UnicodeCharReference::operator==(const Utf8Char& character) const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	bool equal = false;

	if(m_utf8CharacterReference != NULL)
	{
		equal = (*m_utf8CharacterReference == character);
	}

	//We can safely assume that m_utf16CharacterReference != NULL because this->is_empty() is false
	else
	{
		equal = (*m_utf16CharacterReference == (Utf16Char)(character));
	}

	return equal;
}

bool UnicodeCharReference::operator==(const Utf16Char& character) const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	bool equal = false;

	if(m_utf8CharacterReference != NULL)
	{
		equal = (*m_utf8CharacterReference == (Utf8Char)character);
	}

	//We can safely assume that m_utf16CharacterReference != NULL because this->is_empty() is false
	else
	{
		equal = (*m_utf16CharacterReference == character);
	}

	return equal;
}

bool UnicodeCharReference::operator!=(const UnicodeCharReference& otherCharacterReference) const
{
	return !(*this == otherCharacterReference);
}

bool UnicodeCharReference::operator!=(const Utf8CharReference& characterReference) const
{
	return !(*this == characterReference);
}

bool UnicodeCharReference::operator!=(const Utf16CharReference& characterReference) const
{
	return !(*this == characterReference);
}

bool UnicodeCharReference::operator!=(const UnicodeChar& character) const
{
	return !(*this == character);
}

bool UnicodeCharReference::operator!=(const Utf8Char& character) const
{
	return !(*this == character);
}

bool UnicodeCharReference::operator!=(const Utf16Char& character) const
{
	return !(*this == character);
}

UnicodeCharReference& UnicodeCharReference::operator=(const UnicodeCharReference& characterReference)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);
	assert(characterReference.m_utf8CharacterReference != NULL || 
		characterReference.m_utf16CharacterReference != NULL);

	if(m_utf8CharacterReference != NULL)
	{
		if(characterReference.m_utf8CharacterReference != NULL)
		{
			*m_utf8CharacterReference = *characterReference.m_utf8CharacterReference;
		}
		else
		{
			*m_utf8CharacterReference = (Utf8Char)(*characterReference.m_utf16CharacterReference);
		}
	}
	else
	{
		if(characterReference.m_utf16CharacterReference != NULL)
		{
			*m_utf16CharacterReference = *characterReference.m_utf16CharacterReference;
		}
		else
		{
			*m_utf16CharacterReference = (Utf16Char)(*characterReference.m_utf8CharacterReference);
		}
	}

	return *this;
}

UnicodeCharReference& UnicodeCharReference::operator=(const Utf8CharReference& characterReference)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	if(m_utf8CharacterReference != NULL)
	{
		*m_utf8CharacterReference = characterReference;
	}
	else
	{
		*m_utf16CharacterReference = (Utf16Char)characterReference;
	}

	return *this;
}

UnicodeCharReference& UnicodeCharReference::operator=(const Utf16CharReference& characterReference)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	if(m_utf8CharacterReference != NULL)
	{
		*m_utf8CharacterReference = (Utf8Char)characterReference;
	}
	else
	{
		*m_utf16CharacterReference = characterReference;
	}

	return *this;
}

UnicodeCharReference& UnicodeCharReference::operator=(const UnicodeChar& character)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	if(m_utf8CharacterReference != NULL)
	{
		*m_utf8CharacterReference = (Utf8Char)character;
	}
	else if(m_utf16CharacterReference != NULL)
	{
		*m_utf16CharacterReference = (Utf16Char)character;
	}
	
	return *this;
}

UnicodeCharReference& UnicodeCharReference::operator=(const Utf8Char& character)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	if(m_utf8CharacterReference != NULL)
	{
		*m_utf8CharacterReference = character;
	}
	else if(m_utf16CharacterReference != NULL)
	{
		*m_utf16CharacterReference = (Utf16Char)character;
	}
	
	return *this;
}

UnicodeCharReference& UnicodeCharReference::operator=(const Utf16Char& character)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	if(m_utf8CharacterReference != NULL)
	{
		*m_utf8CharacterReference = (Utf8Char)character;
	}
	else if(m_utf16CharacterReference != NULL)
	{
		*m_utf16CharacterReference = character;
	}
	
	return *this;
}

UnicodeCharReference::operator UnicodeChar() const
{
	UnicodeChar character;

	if(m_utf8CharacterReference != NULL)
	{
		character = *m_utf8CharacterReference;
	}
	else if(m_utf16CharacterReference != NULL)
	{
		character = *m_utf16CharacterReference;
	}

	return character;
}

UnicodeCharReference::operator Utf8Char() const
{
	assert(is_valid());

	Utf8Char character;

	if(m_utf8CharacterReference != NULL)
	{
		character = (Utf8Char)(*m_utf8CharacterReference);
	}
	else
	{
		character = (Utf8Char)(*m_utf16CharacterReference);
	}

	return character;
}

UnicodeCharReference::operator Utf16Char() const
{
	assert(is_valid());

	Utf8Char character;

	if(m_utf8CharacterReference != NULL)
	{
		character = (Utf8Char)(*m_utf8CharacterReference);
	}
	else
	{
		character = (Utf8Char)(*m_utf16CharacterReference);
	}

	return character;
}

UnicodeCharReference::operator Utf8CharReference() const
{
	assert(internal_encoding() == ENCODING_UTF8);

	return *m_utf8CharacterReference;
}

UnicodeCharReference::operator Utf16CharReference() const
{
	assert(internal_encoding() == ENCODING_UTF16);

	return *m_utf16CharacterReference;
}

/*Functions*/

void UnicodeCharReference::assign_reference(const UnicodeCharReference& otherCharacterReference)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);
	assert(otherCharacterReference.m_utf8CharacterReference != NULL ||
		otherCharacterReference.m_utf16CharacterReference != NULL);

	if(m_utf8CharacterReference != NULL)
	{
		delete m_utf8CharacterReference;
		m_utf8CharacterReference = NULL;
	}
	else
	{
		delete m_utf16CharacterReference;
		m_utf16CharacterReference = NULL;
	}

	if(otherCharacterReference.m_utf8CharacterReference != NULL)
	{
		m_utf8CharacterReference = new Utf8CharReference(*otherCharacterReference.m_utf8CharacterReference);
	}
	else
	{
		m_utf16CharacterReference = new Utf16CharReference(*otherCharacterReference.m_utf16CharacterReference);
	}
}

bool UnicodeCharReference::is_valid() const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	bool isValid = true;

	if((m_utf8CharacterReference != NULL && !m_utf8CharacterReference->is_valid()) ||
		(m_utf16CharacterReference != NULL && !m_utf16CharacterReference->is_valid()))
	{
		isValid = false;
	}

	return isValid;
}

const UtfEncoding UnicodeCharReference::internal_encoding() const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	UtfEncoding encoding = ENCODING_NONE;

	if(m_utf8CharacterReference != NULL)
	{
		encoding = ENCODING_UTF8;
	}
	else
	{
		encoding = ENCODING_UTF16;
	}

	return encoding;
}

bool UnicodeCharReference::reference_equal(const UnicodeCharReference& otherCharacterReference)
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	bool equal = false;

	//References can only possibly refer to the same character in the same string when they
	//have the same encoding
	if(m_utf8CharacterReference != NULL && otherCharacterReference.m_utf8CharacterReference != NULL)
	{
		equal = m_utf8CharacterReference->reference_equal(*otherCharacterReference.m_utf8CharacterReference);
	}
	else if(m_utf16CharacterReference != NULL && otherCharacterReference.m_utf16CharacterReference != NULL)
	{
		equal = m_utf16CharacterReference->reference_equal(*otherCharacterReference.m_utf16CharacterReference);
	}

	return equal;
}

bool UnicodeCharReference::reference_not_equal(const UnicodeCharReference& otherCharacterReference)
{
	return !reference_equal(otherCharacterReference);
}

UInt32 UnicodeCharReference::to_utf_32() const
{
	//We should never have an empty reference
	assert(m_utf8CharacterReference != NULL || m_utf16CharacterReference != NULL);

	UInt32 codePoint = 0xFFFFFFFF;

	if(m_utf8CharacterReference != NULL)
	{
		codePoint = m_utf8CharacterReference->to_utf_32();
	}
	else
	{
		codePoint = m_utf16CharacterReference->to_utf_32();
	}

	return codePoint;
}
