#include <utfstring/UtfString.h>

//These includes are only needed for this code file and don't need 
//to be located in the library header file
#include <assert.h>
#include <sstream>

using namespace UtfString;
using namespace std;

/*UnicodeString Definition*/

/*Static Constants*/
const size_t UnicodeString::npos = (size_t)-1;

/*Constructors*/

UnicodeString::UnicodeString() :
	m_utf8String(NULL), m_utf16String(NULL)
{

}

UnicodeString::UnicodeString(const UnicodeString& unicodeString)
{
	if(unicodeString.m_utf8String != NULL)
	{
		m_utf8String = new Utf8String(*unicodeString.m_utf8String);
		m_utf16String = NULL;
	}
	else if(unicodeString.m_utf16String != NULL)
	{
		m_utf16String = new Utf16String(*unicodeString.m_utf16String);
		m_utf8String = NULL;
	}
	else
	{
		m_utf8String = NULL;
		m_utf16String = NULL;
	}
}

UnicodeString::UnicodeString(const Utf16String& utf16String) :
	m_utf8String(NULL)
{
	m_utf16String = new Utf16String(utf16String);
}

UnicodeString::UnicodeString(const Utf8String& utf8String) :
	m_utf16String(NULL)
{
	m_utf8String = new Utf8String(utf8String);
}

UnicodeString::~UnicodeString()
{
	if(m_utf8String != NULL)
	{
		delete m_utf8String;
		m_utf8String = NULL;
	}
	else if(m_utf16String != NULL)
	{
		delete m_utf16String;
		m_utf16String = NULL;
	}

	//If one of the UTF-8 or UTF-16 strings aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8String == NULL);
	assert(m_utf16String == NULL);
}

/*Member Functions*/

UnicodeString& UnicodeString::append(const UnicodeString& unicodeString)
{
	if(m_utf8String != NULL)
	{
		if(unicodeString.m_utf8String != NULL)
		{
			m_utf8String->append(*unicodeString.m_utf8String);
		}
		else if(unicodeString.m_utf16String != NULL)
		{
			m_utf8String->append(*unicodeString.m_utf16String);
		}
	}
	else if(m_utf16String != NULL)
	{
		if(unicodeString.m_utf8String != NULL)
		{
			m_utf16String->append(*unicodeString.m_utf8String);
		}
		else if(unicodeString.m_utf16String != NULL)
		{
			m_utf16String->append(*unicodeString.m_utf16String);
		}
	}

	//If this is an empty string and the string being appended is not, we'll just 
	//assign the appended string
	else if(!unicodeString.empty())
	{
		this->assign(unicodeString);
	}

	return *this;
}

UnicodeString& UnicodeString::append(const Utf16String& utf16String)
{
	if(m_utf8String != NULL)
	{
		m_utf8String->append(utf16String);
	}
	else if(m_utf16String != NULL)
	{
		m_utf16String->append(utf16String);
	}

	//If this is an empty string and the string being appended is not, we'll just 
	//assign the appended string
	else
	{
		this->assign(utf16String);
	}

	return *this;
}

UnicodeString& UnicodeString::append(const Utf8String& utf8String)
{
	if(m_utf8String != NULL)
	{
		m_utf8String->append(utf8String);
	}
	else if(m_utf16String != NULL)
	{
		m_utf16String->append(utf8String);
	}

	//If this is an empty string and the string being appended is not, we'll just 
	//assign the appended string
	else
	{
		this->assign(utf8String);
	}

	return *this;
}

UnicodeString& UnicodeString::append(const UnicodeChar& unicodeCharacter)
{
	assert(unicodeCharacter.is_valid());

	if(m_utf8String != NULL)
	{
		m_utf8String->append((Utf8Char)unicodeCharacter);
	}
	else if(m_utf16String != NULL)
	{
		m_utf16String->append((Utf16Char)unicodeCharacter);
	}

	//If this is an empty string and the character being appended is not empty, we'll just 
	//assign the appended character
	else if(!unicodeCharacter.empty())
	{
		this->assign(unicodeCharacter);
	}

	return *this;
}

UnicodeString& UnicodeString::append(const UnicodeCharReference& unicodeCharacterReference)
{
	assert(unicodeCharacterReference.is_valid());

	if(m_utf8String != NULL)
	{
		m_utf8String->append((Utf8Char)unicodeCharacterReference);
	}
	else if(m_utf16String != NULL)
	{
		m_utf16String->append((Utf16Char)unicodeCharacterReference);
	}

	return *this;
}

UnicodeString& UnicodeString::assign(const UnicodeString& unicodeString)
{
	//Clean up the current string
	this->clear();

	//Create a new one using the assigned string
	if(unicodeString.m_utf8String != NULL)
	{
		m_utf8String = new Utf8String(*unicodeString.m_utf8String);
	}
	else if(unicodeString.m_utf16String != NULL)
	{
		m_utf16String = new Utf16String(*unicodeString.m_utf16String);
	}

	return *this;
}

UnicodeString& UnicodeString::assign(const Utf16String& utf16String)
{
	//Clean up the current string
	this->clear();

	//Create a new one using the assigned string
	m_utf16String = new Utf16String(utf16String);

	return *this;
}

UnicodeString& UnicodeString::assign(const Utf8String& utf8String)
{
	//Clean up the current string
	this->clear();

	//Create a new one using the assigned string
	m_utf8String = new Utf8String(utf8String);

	return *this;
}

UnicodeString& UnicodeString::assign(const UnicodeChar& unicodeCharacter)
{
	//Clean up the current string
	this->clear();

	//Create a new one using the assigned string
	if(unicodeCharacter.internal_encoding() == ENCODING_UTF8)
	{
		m_utf8String = new Utf8String(((Utf8Char)unicodeCharacter).c_str());
	}
	else if(unicodeCharacter.internal_encoding() == ENCODING_UTF16)
	{
		m_utf16String = new Utf16String(((Utf16Char)unicodeCharacter).c_str());
	}

	return *this;
}

UnicodeString& UnicodeString::assign(const UnicodeCharReference& unicodeCharacterReference)
{
	assert(unicodeCharacterReference.is_valid());

	//Clean up the current string
	this->clear();

	//Create a new one using the assigned string
	if(unicodeCharacterReference.internal_encoding() == ENCODING_UTF8)
	{
		m_utf8String = new Utf8String(((Utf8Char)unicodeCharacterReference).c_str());
	}
	else if(unicodeCharacterReference.internal_encoding() == ENCODING_UTF16)
	{
		m_utf16String = new Utf16String(((Utf16Char)unicodeCharacterReference).c_str());
	}

	return *this;
}

UnicodeCharReference UnicodeString::at(size_t index)
{
	//Since we can't create an empty reference, we'll have to allocate one dynamically
	//and delete it before the function returns
	UnicodeCharReference* characterReference = NULL;

	if(m_utf8String != NULL)
	{
		characterReference = new UnicodeCharReference(m_utf8String->at(index));
	}
	else if(m_utf16String != NULL)
	{
		characterReference = new UnicodeCharReference(m_utf16String->at(index));
	}
	else
	{
		std::stringstream errorMessageStream;
		errorMessageStream << "The index " << index << " does not exist in this empty string";

		throw out_of_range(errorMessageStream.str());	
	}

	//We know the dynamically-created reference has been created at this point, since we wouldn't
	//reach this point if one hadn't been created
	assert(characterReference != NULL);

	//Create a copy of the reference to be returned
	UnicodeCharReference returnReference(*characterReference);

	//Delete the original reference before the function returns
	delete characterReference;
	characterReference = NULL;

	return returnReference;
}

const UnicodeChar UnicodeString::at(size_t index) const
{
	UnicodeChar character;

	if(m_utf8String != NULL)
	{
		character = m_utf8String->at(index);
	}
	else if(m_utf16String != NULL)
	{
		character = m_utf16String->at(index);
	}
	else
	{
		std::stringstream errorMessageStream;
		errorMessageStream << "The index " << index << " does not exist in this empty string";

		throw out_of_range(errorMessageStream.str());	
	}

	return character;
}

UnicodeString::iterator UnicodeString::begin()
{
	if(m_utf8String != NULL)
	{
		return iterator(m_utf8String->begin());
	}
	else if(m_utf16String != NULL)
	{
		return iterator(m_utf16String->begin());
	}
	else
	{
		return iterator();
	}
}

UnicodeString::const_iterator UnicodeString::begin() const
{
	if(m_utf8String != NULL)
	{
		return const_iterator(m_utf8String->begin());
	}
	else if(m_utf16String != NULL)
	{
		return const_iterator(m_utf16String->begin());
	}
	else
	{
		return const_iterator();
	}
}

void UnicodeString::clear()
{
	if(m_utf8String != NULL)
	{
		delete m_utf8String;
		m_utf8String = NULL;
	}
	else if(m_utf16String != NULL)
	{
		delete m_utf16String;
		m_utf16String = NULL;
	}

	//If one of the UTF-8 or UTF-16 strings aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8String == NULL);
	assert(m_utf16String == NULL);
}

int UnicodeString::compare(const UnicodeString& unicodeString) const
{
	int compareValue;

	//Handle the case when the parameter string is empty
	if(unicodeString.empty())
	{
		if(this->empty())
		{
			compareValue = 0;
		}
		else
		{
			compareValue = 1;
		}
	}

	//Handle the case when this string is empty
	else if(this->empty())
	{
		//We already know that the parameter string is not empty
		compareValue = -1;
	}

	//Handle the case when neither strings are empty
	else
	{
		if(m_utf8String != NULL)
		{
			if(unicodeString.m_utf8String != NULL)
			{
				compareValue = m_utf8String->compare(*unicodeString.m_utf8String);
			}
			else
			{
				compareValue = m_utf8String->compare(*unicodeString.m_utf16String);
			}
		}
		else
		{
			if(unicodeString.m_utf16String != NULL)
			{
				compareValue = m_utf16String->compare(*unicodeString.m_utf16String);
			}
			else
			{
				compareValue = m_utf16String->compare(*unicodeString.m_utf8String);
			}
		}
	}

	return compareValue;
}

int UnicodeString::compare(const Utf16String& utf16String) const
{
	int compareValue;

	//Handle the case when this string is empty
	if(this->empty())
	{
		if(utf16String.empty())
		{
			compareValue = 0;
		}
		else
		{
			compareValue = -1;
		}
	}

	//Handle the case when this string isn't empty
	else
	{
		if(m_utf8String != NULL)
		{
			compareValue = m_utf8String->compare(utf16String);
		}
		else
		{
			compareValue = m_utf16String->compare(utf16String);		
		}
	}

	return compareValue;
}

int UnicodeString::compare(const Utf8String& utf8String) const
{
	int compareValue;

	//Handle the case when this string is empty
	if(this->empty())
	{
		if(utf8String.empty())
		{
			compareValue = 0;
		}
		else
		{
			compareValue = -1;
		}
	}

	//Handle the case when this string isn't empty
	else
	{
		if(m_utf8String != NULL)
		{
			compareValue = m_utf8String->compare(utf8String);
		}
		else
		{
			compareValue = m_utf16String->compare(utf8String);		
		}
	}

	return compareValue;
}

bool UnicodeString::empty() const
{
	bool isEmpty = true;

	if(m_utf8String != NULL || m_utf16String != NULL)
	{
		isEmpty = false;
	}

	return isEmpty;	
}

UnicodeString::iterator UnicodeString::end()
{
	if(m_utf8String != NULL)
	{
		return iterator(m_utf8String->end());
	}
	else if(m_utf16String != NULL)
	{
		return iterator(m_utf16String->end());
	}
	else
	{
		return iterator();
	}
}

UnicodeString::const_iterator UnicodeString::end() const
{
	if(m_utf8String != NULL)
	{
		return const_iterator(m_utf8String->end());
	}
	else if(m_utf16String != NULL)
	{
		return const_iterator(m_utf16String->end());
	}
	else
	{
		return const_iterator();
	}
}

UnicodeString::iterator UnicodeString::erase(const UnicodeString::iterator& firstPosition,
	const UnicodeString::iterator& lastPosition)
{
	if(m_utf8String != NULL)
	{
		//These had better be the correct type of iterators for this string
		assert(firstPosition.m_utf8StringIterator != NULL);
		assert(lastPosition.m_utf8StringIterator != NULL);

		return iterator(m_utf8String->erase(*firstPosition.m_utf8StringIterator, *lastPosition.m_utf8StringIterator));
	}
	else if(m_utf16String != NULL)
	{
		//These had better be the correct type of iterators for this string
		assert(firstPosition.m_utf16StringIterator != NULL);
		assert(lastPosition.m_utf16StringIterator != NULL);

		return iterator(m_utf16String->erase(*firstPosition.m_utf16StringIterator, *lastPosition.m_utf16StringIterator));
	}
	else
	{
		return iterator();
	}
}

UnicodeString::iterator UnicodeString::erase(const UnicodeString::iterator& position)
{
	if(m_utf8String != NULL)
	{
		//These had better be the correct type of iterators for this string
		assert(position.m_utf8StringIterator != NULL);

		return iterator(m_utf8String->erase(*position.m_utf8StringIterator));
	}
	else if(m_utf16String != NULL)
	{
		//These had better be the correct type of iterators for this string
		assert(position.m_utf16StringIterator != NULL);

		return iterator(m_utf16String->erase(*position.m_utf16StringIterator));
	}
	else
	{
		return iterator();
	}
}

UnicodeString& UnicodeString::erase(const size_t offset, const size_t count)
{
	if(m_utf8String != NULL)
	{
		m_utf8String->erase(offset, count);
	}
	else if (m_utf16String != NULL)
	{
		m_utf16String->erase(offset, count);
	}

	return *this;
}

size_t UnicodeString::find(const UnicodeString& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string and the search string are not empty
	if(!this->empty() && !searchString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(searchString.m_utf8String != NULL)
			{
				foundIndex = m_utf8String->find(*searchString.m_utf8String, offset);
			}
			else
			{
				foundIndex = m_utf8String->find((Utf16String)*searchString.m_utf16String, offset);
			}
		}
		else
		{
			if(searchString.m_utf8String != NULL)
			{
				foundIndex = m_utf16String->find((Utf8String)*searchString.m_utf8String, offset);
			}
			else
			{
				foundIndex = m_utf16String->find(*searchString.m_utf16String, offset);
			}
		}
	}

	return foundIndex;
}

size_t UnicodeString::find(const Utf8String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find(searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find(const Utf16String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find(searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_first_not_of(const UnicodeString& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string and the search string are not empty
	if(!this->empty() && !searchString.empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_first_not_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_first_not_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_first_not_of(const Utf8String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_first_not_of(searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_first_not_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_first_not_of(const Utf16String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_first_not_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_first_not_of(searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_first_of(const UnicodeString& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string and the search string are not empty
	if(!this->empty() && !searchString.empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_first_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_first_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_first_of(const Utf8String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_first_of(searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_first_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_first_of(const Utf16String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_first_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_first_of(searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_last_not_of(const UnicodeString& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string and the search string are not empty
	if(!this->empty() && !searchString.empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_last_not_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_last_not_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_last_not_of(const Utf8String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_last_not_of(searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_last_not_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_last_not_of(const Utf16String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_last_not_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_last_not_of(searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_last_of(const UnicodeString& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string and the search string are not empty
	if(!this->empty() && !searchString.empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_last_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_last_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_last_of(const Utf8String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_last_of(searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_last_of((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
}

size_t UnicodeString::find_last_of(const Utf16String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->find_last_of((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->find_last_of(searchString, offset);
		}
	}

	return foundIndex;
}

UnicodeString& UnicodeString::insert(const size_t index, const UnicodeString& unicodeString)
{
	assert(index <= length());

	//An insert at the end is the same as an append
	if(this->empty() || index == length())
	{
		this->append(unicodeString);
	}

	//Only insert something if there is a string to insert
	else if(!unicodeString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(unicodeString.m_utf8String != NULL)
			{
				m_utf8String->insert(index, *unicodeString.m_utf8String);
			}
			else
			{
				m_utf8String->insert(index, *unicodeString.m_utf16String);
			}
		}
		else
		{
			if(unicodeString.m_utf16String != NULL)
			{
				m_utf16String->insert(index, *unicodeString.m_utf16String);
			}
			else
			{
				m_utf16String->insert(index, *unicodeString.m_utf8String);
			}
		}
	}

	return *this;
}

UnicodeString& UnicodeString::insert(const size_t index, const Utf8String& utf8String)
{
	assert(index <= length());

	//An insert at the end is the same as an append
	if(this->empty() || index == length())
	{
		this->append(utf8String);
	}

	else
	{
		if(m_utf8String != NULL)
		{
			m_utf8String->insert(index, utf8String);
		}
		else
		{
			m_utf16String->insert(index, utf8String);
		}
	}

	return *this;
}

UnicodeString& UnicodeString::insert(const size_t index, const Utf16String& utf16String)
{
	assert(index <= length());

	//An insert at the end is the same as an append
	if(this->empty() || index == length())
	{
		this->append(utf16String);
	}

	else
	{
		if(m_utf16String != NULL)
		{
			m_utf16String->insert(index, utf16String);
		}
		else
		{
			m_utf8String->insert(index, utf16String);
		}
	}

	return *this;
}

UnicodeString& UnicodeString::insert(const size_t index, const UnicodeChar& unicodeCharacter)
{
	assert(index <= length());

	//An insert at the end is the same as an append
	if(this->empty() || index == length())
	{
		this->append(unicodeCharacter);
	}

	//Only insert something if there is a string to insert
	else if(!unicodeCharacter.empty())
	{
		if(m_utf8String != NULL)
		{
			if(unicodeCharacter.internal_encoding() == ENCODING_UTF8)
			{
				m_utf8String->insert(index, (Utf8Char)unicodeCharacter);
			}
			else
			{
				m_utf8String->insert(index, (Utf16Char)unicodeCharacter);
			}
		}
		else
		{
			if(unicodeCharacter.internal_encoding() == ENCODING_UTF16)
			{
				m_utf16String->insert(index, (Utf16Char)unicodeCharacter);
			}
			else
			{
				m_utf16String->insert(index, (Utf8Char)unicodeCharacter);
			}
		}
	}

	return *this;
}

bool UnicodeString::is_valid() const
{
	bool isValid = true;

	if(m_utf8String != NULL)
	{
		isValid = m_utf8String->is_valid();
	}
	else if(m_utf16String != NULL)
	{
		isValid = m_utf16String->is_valid();
	}

	return isValid;
}

const UtfEncoding UnicodeString::internal_encoding() const
{
	UtfEncoding encoding = ENCODING_NONE;

	if(m_utf8String != NULL)
	{
		encoding = ENCODING_UTF8;
	}
	else
	{
		encoding = ENCODING_UTF16;
	}

	return encoding;
}

size_t UnicodeString::length() const
{
	size_t codePointCount = 0;

	if(m_utf8String != NULL)
	{
		codePointCount = m_utf8String->length();
	}
	else if(m_utf16String != NULL)
	{
		codePointCount = m_utf16String->length();
	}

	return codePointCount;
}

void UnicodeString::push_back(const UnicodeChar& character)
{
	append(character);
}

UnicodeString::reverse_iterator UnicodeString::rbegin()
{
	if(m_utf8String != NULL)
	{
		return reverse_iterator(m_utf8String->rbegin());
	}
	else if(m_utf16String != NULL)
	{
		return reverse_iterator(m_utf16String->rbegin());
	}
	else
	{
		return reverse_iterator();
	}
}

UnicodeString::const_reverse_iterator UnicodeString::rbegin() const
{
	if(m_utf8String != NULL)
	{
		return const_reverse_iterator(reverse_iterator(m_utf8String->rbegin()));
	}
	else if(m_utf16String != NULL)
	{
		return const_reverse_iterator(reverse_iterator(m_utf16String->rbegin()));
	}
	else
	{
		return const_reverse_iterator();
	}
}

UnicodeString::reverse_iterator UnicodeString::rend()
{
	if(m_utf8String != NULL)
	{
		return reverse_iterator(m_utf8String->rend());
	}
	else if(m_utf16String != NULL)
	{
		return reverse_iterator(m_utf16String->rend());
	}
	else
	{
		return reverse_iterator();
	}
}

UnicodeString::const_reverse_iterator UnicodeString::rend() const
{
	if(m_utf8String != NULL)
	{
		return const_reverse_iterator(reverse_iterator(m_utf8String->rend()));
	}
	else if(m_utf16String != NULL)
	{
		return const_reverse_iterator(reverse_iterator(m_utf16String->rend()));
	}
	else
	{
		return const_reverse_iterator();
	}
}


UnicodeString& UnicodeString::replace(const size_t position, const size_t count, const UnicodeString& replacementString)
{
	assert(position <= length());

	//Doing a replace on an empty string is the same as an assign
	if(this->empty())
	{
		this->assign(replacementString);
	}

	else if(m_utf8String != NULL)
	{
		if(replacementString.m_utf8String != NULL)
		{
			m_utf8String->replace(position, count, *replacementString.m_utf8String);
		}
		else if(replacementString.m_utf16String != NULL)
		{
			m_utf8String->replace(position, count, *replacementString.m_utf16String);
		}
		else
		{
			m_utf8String->replace(position, count, Utf8String());
		}
	}

	else 
	{
		if(replacementString.m_utf8String != NULL)
		{
			m_utf16String->replace(position, count, *replacementString.m_utf8String);
		}
		else if(replacementString.m_utf16String != NULL)
		{
			m_utf16String->replace(position, count, *replacementString.m_utf16String);
		}
		else
		{
			m_utf16String->replace(position, count, Utf16String());
		}
	}

	return *this;
}

UnicodeString& UnicodeString::replace(const size_t position, const size_t count, const Utf8String& replacementString)
{
	assert(position <= length());

	//Doing a replace on an empty string is the same as an assign
	if(this->empty())
	{
		this->assign(replacementString);
	}

	else if(m_utf8String != NULL)
	{
		m_utf8String->replace(position, count, replacementString);
	}

	else 
	{
		m_utf16String->replace(position, count, (Utf16String)replacementString);
	}

	return *this;
}

UnicodeString& UnicodeString::replace(const size_t position, const size_t count, const Utf16String& replacementString)
{
	assert(position <= length());

	//Doing a replace on an empty string is the same as an assign
	if(this->empty())
	{
		this->assign(replacementString);
	}

	else if(m_utf8String != NULL)
	{
		m_utf8String->replace(position, count, (Utf8String)replacementString);
	}

	else 
	{
		m_utf16String->replace(position, count, replacementString);
	}

	return *this;
}

UnicodeString& UnicodeString::replace(const size_t position, const size_t count, const size_t characterCount,
	const UnicodeChar& character)
{
	assert(position <= length());

	if(this->empty())
	{
		//Create a new one using the assigned character
		if(character.internal_encoding() == ENCODING_UTF8)
		{
			m_utf8String = new Utf8String();
			m_utf8String->replace(position, count, characterCount, (Utf8Char)character);
		}
		else if(character.internal_encoding() == ENCODING_UTF16)
		{
			m_utf16String = new Utf16String();
			m_utf16String->replace(position, count, characterCount, (Utf16Char)character);
		}
	}

	else if(m_utf8String != NULL)
	{
		if(character.internal_encoding() == ENCODING_UTF8)
		{
			m_utf8String->replace(position, count, characterCount, (Utf8Char)character);
		}
		else if(character.internal_encoding() == ENCODING_UTF16)
		{
			m_utf8String->replace(position, count, characterCount, (Utf16Char)character);
		}
		else
		{
			m_utf8String->replace(position, count, characterCount, Utf8Char());
		}
	}

	else 
	{
		if(character.internal_encoding() == ENCODING_UTF8)
		{
			m_utf16String->replace(position, count, characterCount, (Utf8Char)character);
		}
		else if(character.internal_encoding() == ENCODING_UTF16)
		{
			m_utf16String->replace(position, count, characterCount, (Utf16Char)character);
		}
		else
		{
			m_utf16String->replace(position, count, characterCount, Utf16Char());
		}
	}

	return *this;
}

UnicodeString& UnicodeString::replace(UnicodeString::iterator beginIterator, UnicodeString::iterator endIterator,
	const UnicodeString& replacementString)
{
	if(this->empty())
	{
		//If this is an empty string, we are assuming both iterators are empty iterators, so we can do a simple assign
		if(replacementString.internal_encoding() == ENCODING_UTF8)
		{
			m_utf8String = new Utf8String((Utf8String)replacementString);
		}
		else if(replacementString.internal_encoding() == ENCODING_UTF16)
		{
			m_utf16String = new Utf16String((Utf16String)replacementString);
		}
	}

	else if(m_utf8String != NULL)
	{
		//If this is a non-empty string, we assume both iterators are also non-empty
		assert(!beginIterator.empty());
		assert(!endIterator.empty());

		if(replacementString.m_utf8String != NULL)
		{
			m_utf8String->replace(*beginIterator.m_utf8StringIterator, *endIterator.m_utf8StringIterator, 
				*replacementString.m_utf8String);
		}
		else if(replacementString.m_utf16String != NULL)
		{
			m_utf8String->replace(*beginIterator.m_utf8StringIterator, *endIterator.m_utf8StringIterator, 
				(Utf8String)*replacementString.m_utf16String);
		}
		else
		{
			m_utf8String->replace(*beginIterator.m_utf8StringIterator, *endIterator.m_utf8StringIterator, 
				Utf8String());
		}
	}

	else 
	{
		//If this is a non-empty string, we assume both iterators are also non-empty
		assert(!beginIterator.empty());
		assert(!endIterator.empty());

		if(replacementString.m_utf8String != NULL)
		{
			m_utf16String->replace(*beginIterator.m_utf16StringIterator, *endIterator.m_utf16StringIterator, 
				(Utf16String)*replacementString.m_utf8String);
		}
		else if(replacementString.m_utf16String != NULL)
		{
			m_utf16String->replace(*beginIterator.m_utf16StringIterator, *endIterator.m_utf16StringIterator, 
				*replacementString.m_utf16String);
		}
		else
		{
			m_utf16String->replace(*beginIterator.m_utf16StringIterator, *endIterator.m_utf16StringIterator, 
				Utf16String());
		}
	}

	return *this;
}

UnicodeString& UnicodeString::replace(UnicodeString::iterator beginIterator, UnicodeString::iterator endIterator,
	const size_t characterCount, const UnicodeChar& character)
{
	if(this->empty())
	{
		//If this is an empty string, we are assuming both iterators are empty iterators, so we can create a new instance
		//of a string and do a replace for the whole string
		if(character.internal_encoding() == ENCODING_UTF8)
		{
			m_utf8String = new Utf8String();
			m_utf8String->replace(m_utf8String->begin(), m_utf8String->end(), characterCount, (Utf8Char)character);
		}
		else if(character.internal_encoding() == ENCODING_UTF16)
		{
			m_utf16String = new Utf16String();
			m_utf16String->replace(m_utf16String->begin(), m_utf16String->end(), characterCount, (Utf16Char)character);
		}
	}

	else if(m_utf8String != NULL)
	{
		//If this is a non-empty string, we assume both iterators are also non-empty
		assert(!beginIterator.empty());
		assert(!endIterator.empty());

		if(character.internal_encoding() == ENCODING_UTF8)
		{
			m_utf8String->replace(*beginIterator.m_utf8StringIterator, *endIterator.m_utf8StringIterator, 
				characterCount, character);
		}
		else if(character.internal_encoding() == ENCODING_UTF16)
		{
			m_utf8String->replace(*beginIterator.m_utf8StringIterator, *endIterator.m_utf8StringIterator, 
				characterCount, (Utf8Char)character);
		}
		else
		{
			m_utf8String->replace(*beginIterator.m_utf8StringIterator, *endIterator.m_utf8StringIterator, 
				characterCount, Utf8Char());
		}
	}

	else 
	{
		//If this is a non-empty string, we assume both iterators are also non-empty
		assert(!beginIterator.empty());
		assert(!endIterator.empty());

		if(character.internal_encoding() == ENCODING_UTF8)
		{
			m_utf16String->replace(*beginIterator.m_utf16StringIterator, *endIterator.m_utf16StringIterator, 
				characterCount, (Utf16Char)character);
		}
		else if(character.internal_encoding() == ENCODING_UTF16)
		{
			m_utf16String->replace(*beginIterator.m_utf16StringIterator, *endIterator.m_utf16StringIterator, 
				characterCount, character);
		}
		else
		{
			m_utf16String->replace(*beginIterator.m_utf16StringIterator, *endIterator.m_utf16StringIterator, 
				characterCount, Utf16Char());
		}
	}

	return *this;
}


size_t UnicodeString::rfind(const UnicodeString& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string and the search string are not empty
	if(!this->empty() && !searchString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(searchString.m_utf8String != NULL)
			{
				foundIndex = m_utf8String->rfind(*searchString.m_utf8String, offset);
			}
			else
			{
				foundIndex = m_utf8String->rfind((Utf16String)*searchString.m_utf16String, offset);
			}
		}
		else
		{
			if(searchString.m_utf8String != NULL)
			{
				foundIndex = m_utf16String->rfind((Utf8String)*searchString.m_utf8String, offset);
			}
			else
			{
				foundIndex = m_utf16String->rfind(*searchString.m_utf16String, offset);
			}
		}
	}

	return foundIndex;
} 

size_t UnicodeString::rfind(const Utf8String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->rfind(searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->rfind((Utf16String)searchString, offset);
		}
	}

	return foundIndex;
} 

size_t UnicodeString::rfind(const Utf16String& searchString, size_t offset)
{
	size_t foundIndex = (size_t)-1;

	//We will only be able to find anything if this string is not empty
	if(!this->empty())
	{
		if(m_utf8String != NULL)
		{
			foundIndex = m_utf8String->rfind((Utf8String)searchString, offset);
		}
		else
		{
			foundIndex = m_utf16String->rfind(searchString, offset);
		}
	}

	return foundIndex;
} 

size_t UnicodeString::size() const
{
	size_t stringSize = 0;

	if(m_utf8String != NULL)
	{
		stringSize = m_utf8String->length();
	}
	else if(m_utf16String != NULL)
	{
		stringSize = m_utf16String->length();
	}

	return stringSize;
}

UnicodeString UnicodeString::substr(const size_t offset, const size_t count)
{
	assert(offset < length());

	UnicodeString subString;

	if(m_utf8String != NULL)
	{
		subString = m_utf8String->substr(offset, count);
	}
	else
	{
		subString = m_utf16String->substr(offset, count);
	}

	return subString;
}

void UnicodeString::swap(UnicodeString& unicodeString)
{
	//We only need to do any swapping if one of the strings is non-empty
	if(!(this->empty() && unicodeString.empty()))
	{
		//This string is empty and the parameter string is not
		if(this->empty())
		{
			if(unicodeString.m_utf8String != NULL)
			{
				m_utf8String = unicodeString.m_utf8String;
				unicodeString.m_utf8String = NULL;
			}
			else
			{
				m_utf16String = unicodeString.m_utf16String;
				unicodeString.m_utf16String = NULL;
			}
		}

		//The parameter string is empty and this string is not
		else if(unicodeString.empty())
		{
			if(m_utf8String != NULL)
			{
				unicodeString.m_utf8String = m_utf8String;
				m_utf8String = NULL;
			}
			else
			{
				unicodeString.m_utf16String = m_utf16String;
				m_utf16String = NULL;
			}
		}

		//Neither string is empty
		else
		{
			Utf8String* swapUtf8String = NULL;
			Utf16String * swapUtf16String = NULL;

			//Save the internal string from this string object
			if(m_utf8String != NULL)
			{
				swapUtf8String = m_utf8String;
				m_utf8String = NULL;
			}
			else
			{
				swapUtf16String = m_utf16String;
				m_utf16String = NULL;
			}

			//Move the internal string from the parameter string object to this string object
			if(unicodeString.m_utf8String != NULL)
			{
				m_utf8String = unicodeString.m_utf8String;
				unicodeString.m_utf8String = NULL;
			}
			else
			{
				m_utf16String = unicodeString.m_utf16String;
				unicodeString.m_utf16String = NULL;
			}

			//Finally, assign the swap string that used to belong to this string object to the
			//parameter string object
			if(swapUtf8String != NULL)
			{
				unicodeString.m_utf8String = swapUtf8String;
			}
			else
			{
				unicodeString.m_utf16String = swapUtf16String;
			}
		}
	}
}

void UnicodeString::swap(Utf8String& utf8String)
{
	//We only need to do any swapping if one of the strings is non-empty
	if(!(this->empty() && utf8String.empty()))
	{
		//This string is empty and the parameter string is not
		if(this->empty())
		{
			m_utf8String = new Utf8String(utf8String);
			utf8String.clear();
		}

		//The parameter string is empty and this string is not
		else if(utf8String.empty())
		{
			this->clear();

			if(m_utf8String != NULL)
			{
				utf8String = *m_utf8String;
			}
			else
			{
				utf8String = (Utf8String)*m_utf16String;
			}
		}

		//Neither string is empty
		else
		{
			Utf8String swapUtf8String;

			//Save the internal string from this string object
			if(m_utf8String != NULL)
			{
				swapUtf8String = *m_utf8String;
				m_utf8String = NULL;
			}
			else
			{
				swapUtf8String = (Utf8String)*m_utf16String;
				m_utf16String = NULL;
			}

			//Assign the parameter string object to this string object
			m_utf8String = new Utf8String(utf8String);

			//Finally, assign the swap string to the parameter string object
			utf8String = swapUtf8String;
		}
	}
}

void UnicodeString::swap(Utf16String& utf16String)
{
	//We only need to do any swapping if one of the strings is non-empty
	if(!(this->empty() && utf16String.empty()))
	{
		//This string is empty and the parameter string is not
		if(this->empty())
		{
			m_utf16String = new Utf16String(utf16String);
			utf16String.clear();
		}

		//The parameter string is empty and this string is not
		else if(utf16String.empty())
		{
			this->clear();

			if(m_utf16String != NULL)
			{
				utf16String = *m_utf16String;
			}
			else
			{
				utf16String = (Utf16String)*m_utf8String;
			}
		}

		//Neither string is empty
		else
		{
			Utf16String swapUtf16String;

			//Save the internal string from this string object
			if(m_utf16String != NULL)
			{
				swapUtf16String = *m_utf16String;
				m_utf16String = NULL;
			}
			else
			{
				swapUtf16String = (Utf16String)*m_utf8String;
				m_utf8String = NULL;
			}

			//Assign the parameter string object to this string object
			m_utf16String = new Utf16String(utf16String);

			//Finally, assign the swap string to the parameter string object
			utf16String = swapUtf16String;
		}
	}
}


/*Operators*/

UnicodeCharReference UnicodeString::operator[](const size_t index)
{
	assert(index < length());

	if(m_utf8String != NULL)
	{
		return UnicodeCharReference((*m_utf8String)[index]);
	}
	else
	{
		return UnicodeCharReference((*m_utf16String)[index]);
	}
}

const UnicodeChar UnicodeString::operator[](const size_t index) const
{
	assert(index < length());

	if(m_utf8String != NULL)
	{
		return UnicodeChar((Utf8Char)(*m_utf8String)[index]);
	}
	else
	{
		return UnicodeChar((Utf16Char)(*m_utf16String)[index]);
	}
}

UnicodeString& UnicodeString::operator=(const UnicodeString& unicodeString)
{
	//Clear the current contents
	this->clear();

	//Assign the new contents
	if(unicodeString.m_utf8String != NULL)
	{
		m_utf8String = new Utf8String(*unicodeString.m_utf8String);
	}
	else if(unicodeString.m_utf16String != NULL)
	{
		m_utf16String = new Utf16String(*unicodeString.m_utf16String);
	}

	return *this;
}

UnicodeString& UnicodeString::operator=(const Utf8String& utf8String)
{
	//Clear the current contents
	this->clear();

	//Assign the new contents
	m_utf8String = new Utf8String(utf8String);

	return *this;
}

UnicodeString& UnicodeString::operator=(const Utf16String& utf16String)
{
	//Clear the current contents
	this->clear();

	m_utf16String = new Utf16String(utf16String);

	return *this;
}

bool UnicodeString::operator==(const UnicodeString& otherString) const
{
	bool isEqual = false;

	//If both strings are empty, then they are equal
	if(this->empty() && otherString.empty())
	{
		isEqual = true;
	}

	//If both strings are non-empty, then they could be equal
	else if(!this->empty() && !otherString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(otherString.m_utf8String != NULL)
			{
				isEqual = (*m_utf8String == *otherString.m_utf8String);
			}
			else
			{
				isEqual = (*m_utf8String == *otherString.m_utf16String);
			}
		}
		else
		{
			if(otherString.m_utf16String != NULL)
			{
				isEqual = (*m_utf16String == *otherString.m_utf16String);
			}
			else
			{
				isEqual = (*m_utf16String == *otherString.m_utf8String);
			}
		}
	}

	//If one string is empty and the other not, then they are not equal

	return isEqual;
}

bool UnicodeString::operator==(const Utf8String& utf8String) const
{
	bool isEqual = false;

	//If both strings are empty, then they are equal
	if(this->empty() && utf8String.empty())
	{
		isEqual = true;
	}

	//If both strings are non-empty, then they could be equal
	else if(!this->empty() && !utf8String.empty())
	{
		if(m_utf8String != NULL)
		{
			isEqual = (*m_utf8String == utf8String);
		}
		else
		{
			isEqual = (*m_utf16String == utf8String);
		}
	}

	//If one string is empty and the other not, then they are not equal

	return isEqual;
}

bool UnicodeString::operator==(const Utf16String& utf16String) const
{
	bool isEqual = false;

	//If both strings are empty, then they are equal
	if(this->empty() && utf16String.empty())
	{
		isEqual = true;
	}

	//If both strings are non-empty, then they could be equal
	else if(!this->empty() && !utf16String.empty())
	{
		if(m_utf8String != NULL)
		{
			isEqual = (*m_utf8String == utf16String);
		}
		else
		{
			isEqual = (*m_utf16String == utf16String);
		}
	}

	//If one string is empty and the other not, then they are not equal

	return isEqual;
}

bool UnicodeString::operator!=(const UnicodeString& otherString) const
{
	return !(*this == otherString);
}

bool UnicodeString::operator!=(const Utf8String& utf8String) const
{
	return !(*this == utf8String);
}

bool UnicodeString::operator!=(const Utf16String& utf16String) const
{
	return !(*this == utf16String);
}

bool UnicodeString::operator<(const UnicodeString& otherString) const
{
	bool lessThan = false;

	//If this string is empty and the other not, then this string is 
	//less than the other string
	if(this->empty() && !otherString.empty())
	{
		lessThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(otherString.m_utf8String != NULL)
			{
				lessThan = (*m_utf8String < *otherString.m_utf8String);
			}
			else
			{
				lessThan = (*m_utf8String < *otherString.m_utf16String);
			}
		}
		else
		{
			if(otherString.m_utf16String != NULL)
			{
				lessThan = (*m_utf16String < *otherString.m_utf16String);
			}
			else
			{
				lessThan = (*m_utf16String < *otherString.m_utf8String);
			}
		}
	}

	//If both strings are empty, they are equal, so this function will
	//return false.
	//If the other string is empty and this is not, then the other string
	//is less than this string, so this function will return false

	return lessThan;
}

bool UnicodeString::operator<(const Utf8String& utf8String) const
{
	bool lessThan = false;

	//If this string is empty and the other not, then this string is 
	//less than the other string
	if(this->empty() && !utf8String.empty())
	{
		lessThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf8String.empty())
	{
		if(m_utf8String != NULL)
		{
			lessThan = (*m_utf8String < utf8String);
		}
		else
		{
			lessThan = (*m_utf16String < utf8String);
		}
	}

	//If both strings are empty, they are equal, so this function will
	//return false.
	//If the other string is empty and this is not, then the other string
	//is less than this string, so this function will return false

	return lessThan;
}

bool UnicodeString::operator<(const Utf16String& utf16String) const
{
	bool lessThan = false;

	//If this string is empty and the other not, then this string is 
	//less than the other string
	if(this->empty() && !utf16String.empty())
	{
		lessThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf16String.empty())
	{
		if(m_utf8String != NULL)
		{
			lessThan = (*m_utf8String < utf16String);
		}
		else
		{
			lessThan = (*m_utf16String < utf16String);
		}
	}

	//If both strings are empty, they are equal, so this function will
	//return false.
	//If the other string is empty and this is not, then the other string
	//is less than this string, so this function will return false

	return lessThan;
}

bool UnicodeString::operator<=(const UnicodeString& otherString) const
{
	bool lessThanOrEqual = false;

	//If both strings are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherString.empty())
	{
		lessThanOrEqual = true;
	}

	//If this string is empty and the other not, then this string is 
	//less than the other string
	else if(this->empty() && !otherString.empty())
	{
		lessThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(otherString.m_utf8String != NULL)
			{
				lessThanOrEqual = (*m_utf8String <= *otherString.m_utf8String);
			}
			else
			{
				lessThanOrEqual = (*m_utf8String <= *otherString.m_utf16String);
			}
		}
		else
		{
			if(otherString.m_utf16String != NULL)
			{
				lessThanOrEqual = (*m_utf16String <= *otherString.m_utf16String);
			}
			else
			{
				lessThanOrEqual = (*m_utf16String <= *otherString.m_utf8String);
			}
		}
	}

	//If the other string is empty and this is not, then the other string
	//is less than this string, so this function will return false

	return lessThanOrEqual;
}

bool UnicodeString::operator<=(const Utf8String& utf8String) const
{
	bool lessThanOrEqual = false;

	//If both strings are empty, they are equal, so this function will
	//return true.
	if(this->empty() && utf8String.empty())
	{
		lessThanOrEqual = true;
	}

	//If this string is empty and the other not, then this string is 
	//less than the other string
	else if(this->empty() && !utf8String.empty())
	{
		lessThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf8String.empty())
	{
		if(m_utf8String != NULL)
		{
			lessThanOrEqual = (*m_utf8String <= utf8String);
		}
		else
		{
			lessThanOrEqual = (*m_utf16String <= utf8String);
		}
	}

	//If the other string is empty and this is not, then the other string
	//is less than this string, so this function will return false

	return lessThanOrEqual;
}

bool UnicodeString::operator<=(const Utf16String& utf16String) const
{
	bool lessThanOrEqual = false;

	//If both strings are empty, they are equal, so this function will
	//return true.
	if(this->empty() && utf16String.empty())
	{
		lessThanOrEqual = true;
	}

	//If this string is empty and the other not, then this string is 
	//less than the other string
	else if(this->empty() && !utf16String.empty())
	{
		lessThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf16String.empty())
	{
		if(m_utf8String != NULL)
		{
			lessThanOrEqual = (*m_utf8String <= utf16String);
		}
		else
		{
			lessThanOrEqual = (*m_utf16String <= utf16String);
		}
	}

	//If the other string is empty and this is not, then the other string
	//is less than this string, so this function will return false

	return lessThanOrEqual;
}

bool UnicodeString::operator>(const UnicodeString& otherString) const
{
	bool greaterThan = false;

	//If the parameter string is empty and this string is not, then this string is 
	//greater than the parameter string
	if(!this->empty() && otherString.empty())
	{
		greaterThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(otherString.m_utf8String != NULL)
			{
				greaterThan = (*m_utf8String > *otherString.m_utf8String);
			}
			else
			{
				greaterThan = (*m_utf8String > *otherString.m_utf16String);
			}
		}
		else
		{
			if(otherString.m_utf16String != NULL)
			{
				greaterThan = (*m_utf16String > *otherString.m_utf16String);
			}
			else
			{
				greaterThan = (*m_utf16String > *otherString.m_utf8String);
			}
		}
	}

	//If both strings are empty, they are equal, so this function will
	//return false.
	//If the this string is empty and the parameter string is not, then the parameter string
	//is greater than this string, so this function will return false

	return greaterThan;
}

bool UnicodeString::operator>(const Utf8String& utf8String) const
{
	bool greaterThan = false;

	//If the parameter string is empty and this string is not, then this string is 
	//greater than the parameter string
	if(!this->empty() && utf8String.empty())
	{
		greaterThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf8String.empty())
	{
		if(m_utf8String != NULL)
		{
			greaterThan = (*m_utf8String > utf8String);
		}
		else
		{
			greaterThan = (*m_utf16String > utf8String);
		}
	}

	//If both strings are empty, they are equal, so this function will
	//return false.
	//If the this string is empty and the parameter string is not, then the parameter string
	//is greater than this string, so this function will return false

	return greaterThan;
}

bool UnicodeString::operator>(const Utf16String& utf16String) const
{
	bool greaterThan = false;

	//If the parameter string is empty and this string is not, then this string is 
	//greater than the parameter string
	if(!this->empty() && utf16String.empty())
	{
		greaterThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf16String.empty())
	{
		if(m_utf8String != NULL)
		{
			greaterThan = (*m_utf8String > utf16String);
		}
		else
		{
			greaterThan = (*m_utf16String > utf16String);
		}
	}

	//If both strings are empty, they are equal, so this function will
	//return false.
	//If the this string is empty and the parameter string is not, then the parameter string
	//is greater than this string, so this function will return false

	return greaterThan;
}

bool UnicodeString::operator>=(const UnicodeString& otherString) const
{
	bool greaterThanOrEqual = false;

	//If both strings are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherString.empty())
	{
		greaterThanOrEqual = true;
	}

	//If the parameter string is empty and this string is not, then this string is 
	//greater than the parameter string
	else if(this->empty() && !otherString.empty())
	{
		greaterThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherString.empty())
	{
		if(m_utf8String != NULL)
		{
			if(otherString.m_utf8String != NULL)
			{
				greaterThanOrEqual = (*m_utf8String >= *otherString.m_utf8String);
			}
			else
			{
				greaterThanOrEqual = (*m_utf8String >= *otherString.m_utf16String);
			}
		}
		else
		{
			if(otherString.m_utf16String != NULL)
			{
				greaterThanOrEqual = (*m_utf16String >= *otherString.m_utf16String);
			}
			else
			{
				greaterThanOrEqual = (*m_utf16String >= *otherString.m_utf8String);
			}
		}
	}

	//If the this string is empty and the parameter string is not, then the parameter string
	//is greater than this string, so this function will return false

	return greaterThanOrEqual;
}

bool UnicodeString::operator>=(const Utf8String& utf8String) const
{
	bool greaterThanOrEqual = false;

	//If both strings are empty, they are equal, so this function will
	//return true.
	if(this->empty() && utf8String.empty())
	{
		greaterThanOrEqual = true;
	}

	//If the parameter string is empty and this string is not, then this string is 
	//greater than the parameter string
	else if(this->empty() && !utf8String.empty())
	{
		greaterThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf8String.empty())
	{
		if(m_utf8String != NULL)
		{
			greaterThanOrEqual = (*m_utf8String >= utf8String);
		}
		else
		{
			greaterThanOrEqual = (*m_utf16String >= utf8String);
		}
	}

	//If the this string is empty and the parameter string is not, then the parameter string
	//is greater than this string, so this function will return false

	return greaterThanOrEqual;
}

bool UnicodeString::operator>=(const Utf16String& utf16String) const
{
	bool greaterThanOrEqual = false;

	//If both strings are empty, they are equal, so this function will
	//return true.
	if(this->empty() && utf16String.empty())
	{
		greaterThanOrEqual = true;
	}

	//If the parameter string is empty and this string is not, then this string is 
	//greater than the parameter string
	else if(this->empty() && !utf16String.empty())
	{
		greaterThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !utf16String.empty())
	{
		if(m_utf8String != NULL)
		{
			greaterThanOrEqual = (*m_utf8String >= utf16String);
		}
		else
		{
			greaterThanOrEqual = (*m_utf16String >= utf16String);
		}
	}

	//If the this string is empty and the parameter string is not, then the parameter string
	//is greater than this string, so this function will return false

	return greaterThanOrEqual;
}

UnicodeString::operator Utf16String() const
{
	if(m_utf16String != NULL)
	{
		return *m_utf16String;
	}
	else if(m_utf8String != NULL)
	{
		return (Utf16String)(*m_utf8String);
	}
	else
	{
		return Utf16String();
	}
}

UnicodeString::operator Utf8String() const
{
	if(m_utf8String != NULL)
	{
		return *m_utf8String;
	}
	else if(m_utf16String != NULL)
	{
		return (Utf8String)(*m_utf16String);
	}
	else
	{
		return Utf8String();
	}
}

/*Static Functions*/

bool UnicodeString::IsWhitespace(const UnicodeChar& unicodeCharacter)
{
	bool isWhiteSpace = false;

	if(unicodeCharacter.internal_encoding() == ENCODING_UTF8)
	{
		isWhiteSpace = Utf8String::IsWhitespace((Utf8Char)unicodeCharacter);
	}
	else if(unicodeCharacter.internal_encoding() == ENCODING_UTF16)
	{
		isWhiteSpace = Utf16String::IsWhitespace((Utf16Char)unicodeCharacter);
	}

	return isWhiteSpace;
}

/*Iterator Implementations*/

/*iterator Implementation*/

UnicodeString::iterator::iterator() :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{

}

UnicodeString::iterator::iterator(const Utf8String::iterator& utf8StringIterator) :
	m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{
	m_utf8StringIterator = new Utf8String::iterator(utf8StringIterator);
}

UnicodeString::iterator::iterator(const Utf16String::iterator& utf16StringIterator) :
	m_utf8StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{

	m_utf16StringIterator = new Utf16String::iterator(utf16StringIterator);
}

UnicodeString::iterator::iterator(const UnicodeString::iterator& otherIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::iterator(*otherIterator.m_utf16StringIterator);
	}
}

UnicodeString::iterator::iterator(const UnicodeString::reverse_iterator& reverseIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{
	if(reverseIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::iterator(*reverseIterator.m_utf8StringIterator);
	}
	else if(reverseIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::iterator(*reverseIterator.m_utf16StringIterator);
	}
}

UnicodeString::iterator::~iterator()
{
	if(m_currentUnicodeCharReference != NULL)
	{
		delete m_currentUnicodeCharReference;
	}

	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//If one of the UTF-8 or UTF-16 iterators aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8StringIterator == NULL);
	assert(m_utf16StringIterator == NULL);
}

bool UnicodeString::iterator::empty() const
{
	bool isEmpty = false;

	if(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL)
	{
		isEmpty = true;
	}

	return isEmpty;
}

UnicodeString::iterator& UnicodeString::iterator::operator=(const iterator& otherIterator)
{
	//First delete the current encoding-specific iterators
	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//Both iterator pointers should be NULL
	assert(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL);

	//Now assign the encoding-specific iterator from the other iterator
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::iterator(*otherIterator.m_utf16StringIterator);
	}

	return *this;
}

bool UnicodeString::iterator::operator==(const iterator& otherIterator) const
{
	bool isEqual = false;

	//If both iterators are empty, then they are the same
	if(this->empty() && otherIterator.empty())
	{
		isEqual = true;
	}

	//If both iterators are non-empty, we have to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the same if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			isEqual = (*m_utf8StringIterator == *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			isEqual = (*m_utf16StringIterator == *otherIterator.m_utf16StringIterator);
		}
	}

	return isEqual;
}

bool UnicodeString::iterator::operator!=(const UnicodeString::iterator& otherIterator) const
{
	return !(*this == otherIterator);
}

bool UnicodeString::iterator::operator<(const iterator& otherIterator)
{
	bool lessThan = false;

	//If this iterator is empty and the parameter iterator is not, then this iterator is 
	//less than the parameter iterator
	if(this->empty() && !otherIterator.empty())
	{
		lessThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThan = (*m_utf8StringIterator < *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThan = (*m_utf16StringIterator < *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the parameter iterator is empty and this is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThan;
}

bool UnicodeString::iterator::operator<=(const iterator& otherIterator)
{
	bool lessThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If this iterator is empty and the parameter iterator not, then this iterator is 
	//less than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf8StringIterator <= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf16StringIterator <= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the parameter iterator is empty and this iterator is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThanOrEqual;
}

bool UnicodeString::iterator::operator>(const iterator& otherIterator)
{
	bool greaterThan = false;

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	if(!this->empty() && otherIterator.empty())
	{
		greaterThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThan = (*m_utf8StringIterator > *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThan = (*m_utf16StringIterator > *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThan;
}

bool UnicodeString::iterator::operator>=(const iterator& otherIterator)
{
	bool greaterThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf8StringIterator >= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf16StringIterator >= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThanOrEqual;
}

UnicodeString::iterator& UnicodeString::iterator::operator++()
{
	if(m_utf8StringIterator != NULL)
	{
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::iterator UnicodeString::iterator::operator++(int)
{
	UnicodeString::iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::iterator& UnicodeString::iterator::operator+=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) += offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) += offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::iterator UnicodeString::iterator::operator+(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator += offset;

	return offsetIterator;
}

UnicodeString::iterator& UnicodeString::iterator::operator--()
{
	if(m_utf8StringIterator != NULL)
	{
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::iterator UnicodeString::iterator::operator--(int)
{
	UnicodeString::iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::iterator& UnicodeString::iterator::operator-=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) -= offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) -= offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::iterator UnicodeString::iterator::operator-(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator -= offset;

	return offsetIterator;
}

UnicodeCharReference UnicodeString::iterator::operator*()
{
	assert(!this->empty());

	if(m_utf8StringIterator != NULL)
	{
		return UnicodeCharReference(*(*m_utf8StringIterator));
	}
	else
	{
		return UnicodeCharReference(*(*m_utf16StringIterator));
	}
}

UnicodeCharReference* UnicodeString::iterator::operator->()
{
	assert(!this->empty());

	if(m_currentUnicodeCharReference != NULL)
	{
		delete m_currentUnicodeCharReference;
	}

	if(m_utf8StringIterator != NULL)
	{
		m_currentUnicodeCharReference = new UnicodeCharReference(*(*m_utf8StringIterator));
	}
	else
	{
		m_currentUnicodeCharReference = new UnicodeCharReference(*(*m_utf16StringIterator));
	}

	return m_currentUnicodeCharReference;
}


/*const_iterator Implementation*/

UnicodeString::const_iterator::const_iterator() :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{

}

UnicodeString::const_iterator::const_iterator(const Utf8String::const_iterator& utf8StringIterator) :
	m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	m_utf8StringIterator = new Utf8String::const_iterator(utf8StringIterator);
}

UnicodeString::const_iterator::const_iterator(const Utf16String::const_iterator& utf16StringIterator) :
	m_utf8StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	m_utf16StringIterator = new Utf16String::const_iterator(utf16StringIterator);
}

UnicodeString::const_iterator::const_iterator(UnicodeString::iterator& otherIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_iterator(*otherIterator.m_utf16StringIterator);
	}
}

UnicodeString::const_iterator::const_iterator(const UnicodeString::const_iterator& otherIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_iterator(*otherIterator.m_utf16StringIterator);
	}
}

UnicodeString::const_iterator::const_iterator(const UnicodeString::const_reverse_iterator& reverseIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	if(reverseIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_iterator(*reverseIterator.m_utf8StringIterator);
	}
	else if(reverseIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_iterator(*reverseIterator.m_utf16StringIterator);
	}
}

UnicodeString::const_iterator::~const_iterator()
{
	if(m_currentUnicodeChar != NULL)
	{
		delete m_currentUnicodeChar;
	}

	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//If one of the UTF-8 or UTF-16 iterators aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8StringIterator == NULL);
	assert(m_utf16StringIterator == NULL);
}

bool UnicodeString::const_iterator::empty() const
{
	bool isEmpty = false;

	if(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL)
	{
		isEmpty = true;
	}

	return isEmpty;
}

UnicodeString::const_iterator& UnicodeString::const_iterator::operator=(const const_iterator& otherIterator)
{
	//First delete the current encoding-specific iterators
	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//Both iterator pointers should be NULL
	assert(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL);

	//Now assign the encoding-specific iterator from the other iterator
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_iterator(*otherIterator.m_utf16StringIterator);
	}

	return *this;
}

bool UnicodeString::const_iterator::operator==(const const_iterator& otherIterator) const
{
	bool isEqual = false;

	//If both iterators are empty, then they are the same
	if(this->empty() && otherIterator.empty())
	{
		isEqual = true;
	}

	//If both iterators are non-empty, we have to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the same if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			isEqual = (*m_utf8StringIterator == *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			isEqual = (*m_utf16StringIterator == *otherIterator.m_utf16StringIterator);
		}
	}

	return isEqual;
}

bool UnicodeString::const_iterator::operator!=(const const_iterator& otherIterator) const
{
	return !(*this == otherIterator);
}


bool UnicodeString::const_iterator::operator<(const const_iterator& otherIterator)
{
	bool lessThan = false;

	//If this iterator is empty and the parameter iterator is not, then this iterator is 
	//less than the parameter iterator
	if(this->empty() && !otherIterator.empty())
	{
		lessThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThan = (*m_utf8StringIterator < *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThan = (*m_utf16StringIterator < *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the parameter iterator is empty and this is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThan;
}

bool UnicodeString::const_iterator::operator<=(const const_iterator& otherIterator)
{
	bool lessThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If this iterator is empty and the parameter iterator not, then this iterator is 
	//less than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf8StringIterator <= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf16StringIterator <= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the parameter iterator is empty and this iterator is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThanOrEqual;
}

bool UnicodeString::const_iterator::operator>(const const_iterator& otherIterator)
{
	bool greaterThan = false;

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	if(!this->empty() && otherIterator.empty())
	{
		greaterThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThan = (*m_utf8StringIterator > *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThan = (*m_utf16StringIterator > *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThan;
}

bool UnicodeString::const_iterator::operator>=(const const_iterator& otherIterator)
{
	bool greaterThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf8StringIterator >= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf16StringIterator >= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThanOrEqual;
}

UnicodeString::const_iterator& UnicodeString::const_iterator::operator++()
{
	if(m_utf8StringIterator != NULL)
	{
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_iterator UnicodeString::const_iterator::operator++(int)
{
	UnicodeString::const_iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::const_iterator& UnicodeString::const_iterator::operator+=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) += offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) += offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_iterator UnicodeString::const_iterator::operator+(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::const_iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator += offset;

	return offsetIterator;
}

UnicodeString::const_iterator& UnicodeString::const_iterator::operator--()
{
	if(m_utf8StringIterator != NULL)
	{
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_iterator UnicodeString::const_iterator::operator--(int)
{
	UnicodeString::const_iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::const_iterator& UnicodeString::const_iterator::operator-=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) -= offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) -= offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_iterator UnicodeString::const_iterator::operator-(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::const_iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator -= offset;

	return offsetIterator;
}

const UnicodeChar UnicodeString::const_iterator::operator*()
{
	assert(!this->empty());

	if(m_utf8StringIterator != NULL)
	{
		return (UnicodeChar)(*(*m_utf8StringIterator));
	}
	else
	{
		return (UnicodeChar)(*(*m_utf16StringIterator));
	}
}

const UnicodeChar* UnicodeString::const_iterator::operator->()
{
	assert(!this->empty());

	if(m_currentUnicodeChar != NULL)
	{
		delete m_currentUnicodeChar;
	}

	if(m_utf8StringIterator != NULL)
	{
		m_currentUnicodeChar = new UnicodeChar((UnicodeChar)*(*m_utf8StringIterator));
	}
	else
	{
		m_currentUnicodeChar = new UnicodeChar((UnicodeChar)*(*m_utf16StringIterator));
	}

	return m_currentUnicodeChar;
}

/*reverse_iterator Implementation*/

UnicodeString::reverse_iterator::reverse_iterator() :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{

}

UnicodeString::reverse_iterator::reverse_iterator(const Utf8String::reverse_iterator& utf8StringReverseIterator) :
	m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{
	m_utf8StringIterator = new Utf8String::reverse_iterator(utf8StringReverseIterator);
}

UnicodeString::reverse_iterator::reverse_iterator(const Utf16String::reverse_iterator& utf16StringReverseIterator) :
	m_utf8StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{

	m_utf16StringIterator = new Utf16String::reverse_iterator(utf16StringReverseIterator);
}

UnicodeString::reverse_iterator::reverse_iterator(const UnicodeString::reverse_iterator& otherIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::reverse_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::reverse_iterator(*otherIterator.m_utf16StringIterator);
	}
}

UnicodeString::reverse_iterator::reverse_iterator(const UnicodeString::iterator& iterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeCharReference(NULL)
{
	if(iterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::reverse_iterator(*iterator.m_utf8StringIterator);
	}
	else if(iterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::reverse_iterator(*iterator.m_utf16StringIterator);
	}
}

UnicodeString::reverse_iterator::~reverse_iterator()
{
	if(m_currentUnicodeCharReference != NULL)
	{
		delete m_currentUnicodeCharReference;
	}

	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//If one of the UTF-8 or UTF-16 iterators aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8StringIterator == NULL);
	assert(m_utf16StringIterator == NULL);
}

bool UnicodeString::reverse_iterator::empty() const
{
	bool isEmpty = false;

	if(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL)
	{
		isEmpty = true;
	}

	return isEmpty;
}

UnicodeString::reverse_iterator& UnicodeString::reverse_iterator::operator=(const reverse_iterator& otherIterator)
{
	//First delete the current encoding-specific iterators
	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//Both iterator pointers should be NULL
	assert(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL);

	//Now assign the encoding-specific iterator from the other iterator
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::reverse_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::reverse_iterator(*otherIterator.m_utf16StringIterator);
	}

	return *this;
}

bool UnicodeString::reverse_iterator::operator==(const reverse_iterator& otherIterator) const
{
	bool isEqual = false;

	//If both iterators are empty, then they are the same
	if(this->empty() && otherIterator.empty())
	{
		isEqual = true;
	}

	//If both iterators are non-empty, we have to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the same if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			isEqual = (*m_utf8StringIterator == *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			isEqual = (*m_utf16StringIterator == *otherIterator.m_utf16StringIterator);
		}
	}

	return isEqual;
}

bool UnicodeString::reverse_iterator::operator!=(const UnicodeString::reverse_iterator& otherIterator) const
{
	return !(*this == otherIterator);
}

bool UnicodeString::reverse_iterator::operator<(const reverse_iterator& otherIterator)
{
	bool lessThan = false;

	//If this iterator is empty and the parameter iterator is not, then this iterator is 
	//less than the parameter iterator
	if(this->empty() && !otherIterator.empty())
	{
		lessThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThan = (*m_utf8StringIterator < *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThan = (*m_utf16StringIterator < *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the parameter iterator is empty and this is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThan;
}

bool UnicodeString::reverse_iterator::operator<=(const reverse_iterator& otherIterator)
{
	bool lessThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If this iterator is empty and the parameter iterator not, then this iterator is 
	//less than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf8StringIterator <= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf16StringIterator <= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the parameter iterator is empty and this iterator is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThanOrEqual;
}

bool UnicodeString::reverse_iterator::operator>(const reverse_iterator& otherIterator)
{
	bool greaterThan = false;

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	if(!this->empty() && otherIterator.empty())
	{
		greaterThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThan = (*m_utf8StringIterator > *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThan = (*m_utf16StringIterator > *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThan;
}

bool UnicodeString::reverse_iterator::operator>=(const reverse_iterator& otherIterator)
{
	bool greaterThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf8StringIterator >= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf16StringIterator >= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThanOrEqual;
}

UnicodeString::reverse_iterator& UnicodeString::reverse_iterator::operator++()
{
	if(m_utf8StringIterator != NULL)
	{
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::reverse_iterator UnicodeString::reverse_iterator::operator++(int)
{
	UnicodeString::reverse_iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::reverse_iterator& UnicodeString::reverse_iterator::operator+=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) += offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) += offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::reverse_iterator UnicodeString::reverse_iterator::operator+(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::reverse_iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator += offset;

	return offsetIterator;
}

UnicodeString::reverse_iterator& UnicodeString::reverse_iterator::operator--()
{
	if(m_utf8StringIterator != NULL)
	{
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::reverse_iterator UnicodeString::reverse_iterator::operator--(int)
{
	UnicodeString::reverse_iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::reverse_iterator& UnicodeString::reverse_iterator::operator-=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) -= offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) -= offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::reverse_iterator UnicodeString::reverse_iterator::operator-(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::reverse_iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator -= offset;

	return offsetIterator;
}

UnicodeCharReference UnicodeString::reverse_iterator::operator*()
{
	assert(!this->empty());

	if(m_utf8StringIterator != NULL)
	{
		return UnicodeCharReference(*(*m_utf8StringIterator));
	}
	else
	{
		return UnicodeCharReference(*(*m_utf16StringIterator));
	}
}

UnicodeCharReference* UnicodeString::reverse_iterator::operator->()
{
	assert(!this->empty());

	if(m_currentUnicodeCharReference != NULL)
	{
		delete m_currentUnicodeCharReference;
	}

	if(m_utf8StringIterator != NULL)
	{
		m_currentUnicodeCharReference = new UnicodeCharReference(*(*m_utf8StringIterator));
	}
	else
	{
		m_currentUnicodeCharReference = new UnicodeCharReference(*(*m_utf16StringIterator));
	}

	return m_currentUnicodeCharReference;
}


/*const_reverse_iterator Implementation*/

UnicodeString::const_reverse_iterator::const_reverse_iterator() :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{

}

UnicodeString::const_reverse_iterator::const_reverse_iterator(const Utf8String::const_reverse_iterator& utf8StringReverseIterator) :
	m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	m_utf8StringIterator = new Utf8String::const_reverse_iterator(utf8StringReverseIterator);
}

UnicodeString::const_reverse_iterator::const_reverse_iterator(const Utf16String::const_reverse_iterator& utf16StringReverseIterator) :
	m_utf8StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	m_utf16StringIterator = new Utf16String::const_reverse_iterator(utf16StringReverseIterator);
}

UnicodeString::const_reverse_iterator::const_reverse_iterator(const UnicodeString::reverse_iterator& otherIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_reverse_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_reverse_iterator(*otherIterator.m_utf16StringIterator);
	}
}

UnicodeString::const_reverse_iterator::const_reverse_iterator(const UnicodeString::const_iterator& otherIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_reverse_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_reverse_iterator(*otherIterator.m_utf16StringIterator);
	}
}

UnicodeString::const_reverse_iterator::const_reverse_iterator(const UnicodeString::const_reverse_iterator& reverseIterator) :
	m_utf8StringIterator(NULL), m_utf16StringIterator(NULL), m_currentUnicodeChar(NULL)
{
	if(reverseIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_reverse_iterator(*reverseIterator.m_utf8StringIterator);
	}
	else if(reverseIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_reverse_iterator(*reverseIterator.m_utf16StringIterator);
	}
}

UnicodeString::const_reverse_iterator::~const_reverse_iterator()
{
	if(m_currentUnicodeChar != NULL)
	{
		delete m_currentUnicodeChar;
	}

	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//If one of the UTF-8 or UTF-16 iterators aren't null, that means that both were non-null before
	//the destructor was called.  That shouldn't ever happen.
	assert(m_utf8StringIterator == NULL);
	assert(m_utf16StringIterator == NULL);
}

bool UnicodeString::const_reverse_iterator::empty() const
{
	bool isEmpty = false;

	if(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL)
	{
		isEmpty = true;
	}

	return isEmpty;
}

UnicodeString::const_reverse_iterator& UnicodeString::const_reverse_iterator::operator=(const const_reverse_iterator& otherIterator)
{
	//First delete the current encoding-specific iterators
	if(m_utf8StringIterator != NULL)
	{
		delete m_utf8StringIterator;
		m_utf8StringIterator = NULL;
	}
	else if(m_utf16StringIterator != NULL)
	{
		delete m_utf16StringIterator;
		m_utf16StringIterator = NULL;
	}

	//Both iterator pointers should be NULL
	assert(m_utf8StringIterator == NULL && m_utf16StringIterator == NULL);

	//Now assign the encoding-specific iterator from the other iterator
	if(otherIterator.m_utf8StringIterator != NULL)
	{
		m_utf8StringIterator = new Utf8String::const_reverse_iterator(*otherIterator.m_utf8StringIterator);
	}
	else if(otherIterator.m_utf16StringIterator != NULL)
	{
		m_utf16StringIterator = new Utf16String::const_reverse_iterator(*otherIterator.m_utf16StringIterator);
	}

	return *this;
}

bool UnicodeString::const_reverse_iterator::operator==(const const_reverse_iterator& otherIterator) const
{
	bool isEqual = false;

	//If both iterators are empty, then they are the same
	if(this->empty() && otherIterator.empty())
	{
		isEqual = true;
	}

	//If both iterators are non-empty, we have to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the same if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			isEqual = (*m_utf8StringIterator == *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			isEqual = (*m_utf16StringIterator == *otherIterator.m_utf16StringIterator);
		}
	}

	return isEqual;
}

bool UnicodeString::const_reverse_iterator::operator!=(const const_reverse_iterator& otherIterator) const
{
	return !(*this == otherIterator);
}


bool UnicodeString::const_reverse_iterator::operator<(const const_reverse_iterator& otherIterator)
{
	bool lessThan = false;

	//If this iterator is empty and the parameter iterator is not, then this iterator is 
	//less than the parameter iterator
	if(this->empty() && !otherIterator.empty())
	{
		lessThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThan = (*m_utf8StringIterator < *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThan = (*m_utf16StringIterator < *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the parameter iterator is empty and this is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThan;
}

bool UnicodeString::const_reverse_iterator::operator<=(const const_reverse_iterator& otherIterator)
{
	bool lessThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If this iterator is empty and the parameter iterator not, then this iterator is 
	//less than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		lessThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf8StringIterator <= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			lessThanOrEqual = (*m_utf16StringIterator <= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the parameter iterator is empty and this iterator is not, then the parameter iterator
	//is less than this iterator, so this function will return false

	return lessThanOrEqual;
}

bool UnicodeString::const_reverse_iterator::operator>(const const_reverse_iterator& otherIterator)
{
	bool greaterThan = false;

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	if(!this->empty() && otherIterator.empty())
	{
		greaterThan = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThan = (*m_utf8StringIterator > *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThan = (*m_utf16StringIterator > *otherIterator.m_utf16StringIterator);
		}
	}

	//If both iterators are empty, they are equal, so this function will
	//return false.
	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThan;
}

bool UnicodeString::const_reverse_iterator::operator>=(const const_reverse_iterator& otherIterator)
{
	bool greaterThanOrEqual = false;

	//If both iterators are empty, they are equal, so this function will
	//return true.
	if(this->empty() && otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If the parameter iterator is empty and this iterator is not, then this iterator is 
	//greater than the parameter iterator
	else if(this->empty() && !otherIterator.empty())
	{
		greaterThanOrEqual = true;
	}

	//If both strings are non-empty, we need to compare them
	else if(!this->empty() && !otherIterator.empty())
	{
		//Iterators can only be the compared if they have the same type of encoding-specific iterator
		if(m_utf8StringIterator != NULL && otherIterator.m_utf8StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf8StringIterator >= *otherIterator.m_utf8StringIterator);
		}
		else if(m_utf16StringIterator != NULL && otherIterator.m_utf16StringIterator != NULL)
		{
			greaterThanOrEqual = (*m_utf16StringIterator >= *otherIterator.m_utf16StringIterator);
		}
	}

	//If the this iterator is empty and the parameter iterator is not, then the parameter iterator
	//is greater than this iterator, so this function will return false

	return greaterThanOrEqual;
}

UnicodeString::const_reverse_iterator& UnicodeString::const_reverse_iterator::operator++()
{
	if(m_utf8StringIterator != NULL)
	{
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_reverse_iterator UnicodeString::const_reverse_iterator::operator++(int)
{
	UnicodeString::const_reverse_iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		++(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::const_reverse_iterator& UnicodeString::const_reverse_iterator::operator+=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) += offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) += offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_reverse_iterator UnicodeString::const_reverse_iterator::operator+(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::const_reverse_iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator += offset;

	return offsetIterator;
}

UnicodeString::const_reverse_iterator& UnicodeString::const_reverse_iterator::operator--()
{
	if(m_utf8StringIterator != NULL)
	{
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_reverse_iterator UnicodeString::const_reverse_iterator::operator--(int)
{
	UnicodeString::const_reverse_iterator iteratorCopy(*this);

	if(m_utf8StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf8StringIterator);
	}
	else if(m_utf16StringIterator != NULL)
	{
		//Why use the postfix operator here when the prefix operator is
		//more efficient and achieves the same result!
		--(*m_utf16StringIterator);
	}

	//If this iterator is empty, then we do nothing

	return iteratorCopy;
}

UnicodeString::const_reverse_iterator& UnicodeString::const_reverse_iterator::operator-=(size_t offset)
{
	if(m_utf8StringIterator != NULL)
	{
		(*m_utf8StringIterator) -= offset;
	}
	else if(m_utf16StringIterator != NULL)
	{
		(*m_utf16StringIterator) -= offset;
	}

	//If this iterator is empty, then we do nothing

	return *this;
}

UnicodeString::const_reverse_iterator UnicodeString::const_reverse_iterator::operator-(size_t offset)
{
	//Make a copy of the iterator
	UnicodeString::const_reverse_iterator offsetIterator = *this;

	//Increment it using the offset
	offsetIterator -= offset;

	return offsetIterator;
}

const UnicodeChar UnicodeString::const_reverse_iterator::operator*()
{
	assert(!this->empty());

	if(m_utf8StringIterator != NULL)
	{
		return (UnicodeChar)(*(*m_utf8StringIterator));
	}
	else
	{
		return (UnicodeChar)(*(*m_utf16StringIterator));
	}
}

const UnicodeChar* UnicodeString::const_reverse_iterator::operator->()
{
	assert(!this->empty());

	if(m_currentUnicodeChar != NULL)
	{
		delete m_currentUnicodeChar;
	}

	if(m_utf8StringIterator != NULL)
	{
		m_currentUnicodeChar = new UnicodeChar((UnicodeChar)*(*m_utf8StringIterator));
	}
	else
	{
		m_currentUnicodeChar = new UnicodeChar((UnicodeChar)*(*m_utf16StringIterator));
	}

	return m_currentUnicodeChar;
}
