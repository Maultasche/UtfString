/*!
\file Utf8CharReference.h

This file contains the declaration of the Utf8CharReference class
*/

#ifndef __UTFSTRING_UTF8CHARREFERENCE_H__
#define __UTFSTRING_UTF8CHARREFERENCE_H__

namespace UtfString
{
	//Forward Declarations
	class Utf8Char;
	class Utf8CharReference;
	class Utf16Char;

	//TODO: 
	//Document the difference between assigning using the = operator and assigning using the assign_reference()
	//function.  It is a common mistake to assign a new iterator using the "=" operator. That is assigning
	//a new character value to the place in the string that the iterator is pointing to.  Use assign_reference()
	//to do this instead.
	//Also cover reference_equal() and reference_not_equal()

	/*!
	\brief Provides a reference to a UTF-8 character embedded in a UTF-8 string

	Since a Utf8String provides an interface that hides the individual code units, a character
	is not directly pulled out of the Utf8String, but is constructed from the underlying code
	units.  This makes it impossible for an string indexer to return a character reference
	that can be assigned to.

	So this class acts as a reference to a character inside a string, so that if this character 
	reference is altered, the contents of the string are altered as well.
	This allows us to have a read/write indexer in Utf8String instead of a read-only indexer.

	Character references may become invalid if the contents of the string being referred to is
	modified in any way.  If a string is modified by adding or removing characters, the associated 
	character reference may then refer to another character or to somewhere outside the string.
	Attempting to use a character reference that no longer refers to a valid character will most
	likely cause a runtime error.

	The only way code units can be added/subtracted in a character reference is to assign it the
	value of another character reference (using the assignment operator) or assign it the value
	of a character.  The code units can be individually read and written to, but the number of
	code units cannot be changed through individual manipulation.  Attempting to access a 
	non-existant code unit will result in an assertion failure when a debug build and undefined
	behavior in a non-debug build.

	Utf8Char and Utf8CharReference objects can be assigned to each other or converted from one
	to the other.
	*/
	class UTFSTRING_DLLEXPORT Utf8CharReference
	{
	private:
		std::string& codeUnitString;
		std::string::iterator codeUnitIterator;
		size_t codeUnitCount;

	public:
		/*Constructors*/

		/*!
		\brief Initializes an instance of Utf8CharReference using an iterator pointing to some code units
			and a count of the code units that comprise the character

		This constructor assumes that codeUnitCount is less than the maximum number of code units allowed 
		by the UTF-8 encoding.

		@param[in]	codeUnitString	The string containing the code units being referenced by this character
			reference
		@param[in]	basicStringIterator	An iterator pointing to the code units to be stored in this character
			reference
		@param[in]	codeUnitCount	The number of code units that comprise this character
		*/
		Utf8CharReference(std::string& codeUnitString, 
			std::string::iterator& basicStringIterator, size_t codeUnitCount);

		/*!
		\brief This copy constructor initializes an instance of Utf8CharReference that is an exact copy
			of another Utf8CharReference object

		@param[in]	otherCharacterReference	The Utf8CharReference object that is to be exactly copied
		*/
		Utf8CharReference(const Utf8CharReference& otherCharacterReference);

		/*Operators*/
		
		/*!
		\brief Compares the value of this character reference to the value of another character reference and 
			tests whether the two references contain the same character values

		This type of equality checking checks to see whether the character values of the two references are equal.  
		This does not check whether the references refer to the same character in the same string. To test for
		that type of reference equality, use the reference_equal() function.

		@param[in] otherCharacterReference	The character reference to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const Utf8CharReference& otherCharacterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of another character reference and 
			tests whether the two references contain different character values

		This type of equality checking checks to see whether the character values of the two references are not equal.  
		This does not check whether the references are different. To test for that 
		type of reference inequality, use the reference_not_equal() function.

		@param[in] otherCharacterReference	The character reference to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator!=(const Utf8CharReference& otherCharacterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a character and 
			tests whether both contain the same character values

		@param[in] character	The character to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const Utf8Char& character) const;

		/*!
		\brief Compares the value of this character reference to the value of a character and 
			tests whether both contain different character values

		@param[in] character	The character to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator!=(const Utf8Char& character) const;

		/*!
		\brief Assigns the contents of another Utf8CharReference object to this object

		The contents of the other reference are assigned to this reference.  This does not cause the
		this reference to refer to the same character as the other reference.  To have this reference
		refer to the exact same character as another reference, use the assign_reference() function.

		Note that when the contents of this object are changed, the change is propogated to the
		referenced Utf8String object.

		@param[in]	otherCharacterReference	The other Utf8CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		Utf8CharReference& operator=(const Utf8CharReference& otherCharacterReference);
		
		/*!
		\brief Assigns the contents of a Utf8Char object to this object

		Note that when the contents of this object are changed, the change is propogated to the
		referenced Utf8String object.

		@param[in]	utf8Char	The Utf8Char object whose contents	are to be assigned to this object

		\return A reference to this object
		*/
		Utf8CharReference& operator=(const Utf8Char& utf8Char);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-8 encoding, and that index < size().

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		char& operator[](const size_t index);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-8 encoding, and that index < size().

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		const char& operator[](const size_t index) const;

		/*!
		\brief This operator converts a stream of 8-bit values to a UTF-8 character,
			and assigns it to a character reference

		This function clears the contents of utf8CharReference before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled.

		@param[in]	inputStream	The input stream containing 8-bit values to be converted
			to a UTF-8 string
		@param[in]	utf8CharReference	The character reference object to which the converted 
			UTF-8 character	will be assigned
		*/
		friend std::istream& operator >>(std::istream& inputStream, Utf8CharReference& utf8CharReference)
		{
			//Read in the code points one by one
			while(inputStream.peek() != EOF)
			{
				utf8CharReference = Utf8Char::GetNextCharacter(inputStream);
			}

			return inputStream;
		}

		/*!
		\brief This operator converts the character referred to by a UTF-8 character reference
			to a stream of 8-bit values

		No checks for validity are done, so the resulting UTF-8 stream may or may contain a valid
		UTF-8 character.

		@param[in]	outputStream	The output stream to which the contents of the UTF-8 character
			are to be written
		@param[in]	utf8CharReference	A reference to the UTF-8 character to be written to the 
			output stream
		*/
		friend std::ostream& operator <<(std::ostream& outputStream, const Utf8CharReference& utf8CharReference)
		{
			outputStream.write(((Utf8Char)utf8CharReference).c_str(), (std::streamsize)(utf8CharReference.size()));

			return outputStream;
		}

		/*!
		\brief Converts this object to a Utf8Char object
		*/
		operator Utf8Char() const;

		/*!
		\brief Converts this object to a Utf16Char object

		This operator assumes that this character is a valid UTF-8 character. 
		
		\sa Utf8CharReference::is_valid()
		*/
		operator Utf16Char() const;

		/*Functions*/

		/*!
		\brief Assigns another character reference to this character reference, causing this character
			reference to refer to the exact same character as the other reference

		Note that this function does not copy the value of the other character reference and assign it
		to the value of this character reference.  To do that, use the assignment operator.

		@param[in]	otherCharacterReference	The reference to be assigned to this reference.
		*/
		void assign_reference(const Utf8CharReference& otherCharacterReference);

		/*!
		\brief Indicates whether this character is a valid UTF-8 character

		\return true if the code points in this character represent a valid UTF-8 character,
			otherwise false
		*/
		bool is_valid() const;

		/*!
		\brief Compares this character reference to another character reference and tests whether the two
			references refer to the exact same character

		This type of equality checking checks to see whether the two references refer to the exact same
		character in the same Utf8String.  This does not check whether the character values are equal.
		To test for that type of equality, use the == operator.

		@param[in]	otherCharacterReference	The character reference to be compared with this character
			reference

		\return true if this character reference refers to the exact same character as the other reference
		*/
		bool reference_equal(const Utf8CharReference& otherCharacterReference);

		/*!
		\brief Compares this character reference to another character reference and tests whether the two
			references refer to different characters

		This type of equality checking checks to see whether the two references refer to different
		characters.  This does not check whether the character values are not equal, but rather their references.
		To test for value inequality, use the != operator.

		@param[in]	otherCharacterReference	The character reference to be compared with this character
			reference

		\return true if this character reference refers to a differemt character as the other reference
		*/
		bool reference_not_equal(const Utf8CharReference& otherCharacterReference);

		/*!
		\brief Converts this character to a UTF-32 code unit

		This function assumes that size() is from 1 to 4.

		\return This character as a UTF-32 code unit
		*/
		UInt32 to_utf_32() const;

		/*!
		\brief Returns the number of code units in this character
		*/
		size_t size() const;
	};
}

#endif
