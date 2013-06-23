#include <utfstring/UtfString.h>

void std::char_traits<UInt16>::assign(UInt16& characterTo, const UInt16& characterFrom)
{
	characterTo = characterFrom;
}

UInt16* std::char_traits<UInt16>::assign(UInt16* stringTo, size_t num, UInt16 charFrom)
{
	//Store the of the beginning of the string being assigned to
	UInt16* stringBegin = stringTo;

	//Do the assignment
	for(size_t count = 0; count < num; ++count)
	{
		*stringTo++ = charFrom;
	}

	//Return the original address of the string being assigned to
	return stringBegin;
}

int std::char_traits<UInt16>::compare(const UInt16* string1, const UInt16* string2, size_t num)
{
	int comparisonValue = 0;

	//Look for the first character that is different, and return that difference as the string
	//difference
	for(size_t count = 0; comparisonValue == 0 && count < num; ++ count)
	{
		comparisonValue = *string1++ - *string2++;
	}

	return comparisonValue;
}

std::char_traits<UInt16>::int_type std::char_traits<UInt16>::eof()
{
	return EOF;
}

bool std::char_traits<UInt16>::eq(const UInt16& character1, const UInt16& character2)
{
	return character1 == character2;
}

bool std::char_traits<UInt16>::eq_int_type(const std::char_traits<UInt16>::int_type& character1,
										   const std::char_traits<UInt16>::int_type& character2)
{
	return character1 == character2;
}

const UInt16* std::char_traits<UInt16>::find(const UInt16* stringPtr, size_t num, const UInt16& character)
{
	const UInt16* foundCharacter = NULL;

	for(size_t count = 0; count < num && foundCharacter == NULL; ++count)
	{
		if(*stringPtr == character)
		{
			foundCharacter = stringPtr;
		}

		++stringPtr;
	}

	return foundCharacter;
}

size_t std::char_traits<UInt16>::length(const UInt16* stringPtr)
{
	size_t count = 0;

	while(*stringPtr++ != '\0')
	{
		++count;
	}

	return count;
}

bool std::char_traits<UInt16>::lt(const UInt16& character1, const UInt16& character2)
{
	return character1 < character2;
}

UInt16* std::char_traits<UInt16>::move(UInt16* toString, const UInt16* fromString, size_t num)
{
	size_t count = 0;

	//If the "to" string is ahead of the "from" string, then we need to copy the characters
	//in reverse order, so that in case of overlap, the end characters of the "from" string
	//aren't overwritten before they can be copied
	if(toString > fromString)
	{
		fromString += num;
		toString += num;

		while(count < num)
		{
			*toString-- = *fromString--;
		}
	}

	//If the "from" string is ahead of the "to" string (or they are at the same position),
	//then we need to copy the characters is forward order, so that incase of overlap, the
	//beginning characters of the "from" string aren't overwritten before they can be
	//copied
	else
	{
		while(count < num)
		{
			*toString++ = *fromString++;
			++count;
		}
	}
}

std::char_traits<UInt16>::int_type not_eof(const std::char_traits<UInt16>::int_type& character)
{
	return character != EOF;
}

UInt16 std::char_traits<UInt16>::to_char_type(const std::char_traits<UInt16>::int_type& character)
{
	return (UInt16)character;
}

std::char_traits<UInt16>::int_type std::char_traits<UInt16>::to_int_type(const UInt16& character)
{
	return(std::char_traits<UInt16>::int_type)character;
}
