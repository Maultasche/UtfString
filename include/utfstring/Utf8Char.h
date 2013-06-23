/*!
\file Utf8Char.h

This file contains the declaration of the Utf8Char class
*/

#ifndef __UTFSTRING_UTF8CHAR_H__
#define __UTFSTRING_UTF8CHAR_H__

namespace UtfString
{
	//Forward Declarations
	class Utf8Char;
	class Utf8CharReference;
	class Utf16Char;

	/*!
	\brief Provides a copy of a UTF-8 character embedded in a UTF-8 string

	Since a Utf8String provides an interface that hides the individual code units, a character
	is not directly pulled out of the Utf8String, but is constructed from the underlying code
	units.  This class holds a copy of those code units as a single character.  Changing the value
	of a Utf8Char will not cause anything to be changed anywhere else.

	Utf8Char and Utf8CharReference objects can be assigned to each other or converted from one
	to the other.
	*/
	class UTFSTRING_DLLEXPORT Utf8Char
	{
	private:
		std::string characterData;

	public:
		/*Constructors*/

		/*!
		\brief Initializes an empty Utf8Char
		*/
		Utf8Char();

		/*!
		\brief Initializes an instance of Utf8Char using an iterator pointing to some code units
			and a count of the code units that comprise the character

		This constructor assumes that index is less than the maximum number of code units allowed by
		the UTF-8 encoding.  This constructor also assumes that there are at least codeUnitCount code
		units available in the string from the location of the iterator.  If the iterator is pointing
		to the last one-code-unit character, and a codeUnitCount of 2 is passed in, this constructor
		will read past the end of the string and a crash will result.

		@param[in]	basicStringIterator	An iterator pointing to the code units to be stored in this character
		@param[in]	codeUnitCount	The number of code units that comprise this character
		*/
		Utf8Char(const std::string::iterator& basicStringIterator, size_t codeUnitCount);

		/*!
		\brief Initializes an instance of Utf8Char using an const_iterator pointing to some code units
			and a count of the code units that comprise the character

		This constructor assumes that index is less than the maximum number of code units allowed by
		the UTF-8 encoding. This constructor also assumes that there are at least codeUnitCount code
		units available in the string from the location of the iterator.  If the iterator is pointing
		to the last one-code-unit character, and a codeUnitCount of 2 is passed in, this constructor
		will read past the end of the string and a crash will result.

		@param[in]	basicStringIterator	An iterator pointing to the code units to be stored in this character
		@param[in]	codeUnitCount	The number of code units that comprise this character
		*/
		Utf8Char(const std::string::const_iterator& basicStringIterator, size_t codeUnitCount);

		/*!
		\brief Initializes an instance of Utf8Char using an 8-bit ASCII character

		The character passed into this constructor is assumed to be a complete 8-bit ASCII character,
		and not a code unit that comprises some UTF-8 character.  Note that this constructor only
		handles basic ASCII, the characters that match the first 128 code points in Unicode.
		Extended ASCII, which varies from platform to platform, will be converted to whatever code point
		happens to have the same value as the extended ASCII character.

		@param[in]	character	The 8-bit ASCII character to use in initializing this character
		*/
		Utf8Char(const char character);

		/*!
		\brief Initializes an instance of Utf8Char using a variable-code-unit character

		The character passed into this constructor is in the form of a character string, which
		can contain one or more code units.  The character parameter is assumed to be a valid pointer
		to a null-terminated character string.  If the length of character is 0, this character
		will be initialized as an empty character.  If the length of character is 1-4, the code
		units will be used to initialize this character, whether those code units represent a valid UTF-8
		character or not (validity can be checked using the is_valid() function). If the length of
		character is more than 4, only the first four code units will be used, and the rest will be
		ignored.

		@param[in]	character	A character string containing code units to use in initializing this character
		*/
		Utf8Char(const char* character);

        /*!
        \brief Initializes an instance of Utf8Char using another instance of Utf8Char

        This is a copy constructor, and sets the constructed instance to be the same as
        the Utf8Char instance passed in as a parameter

        @param[in]  character   A character to use in initializing this character
        */
        Utf8Char(const Utf8Char& character);

        /*!
        \brief The class destructor
        */
        virtual ~Utf8Char();

		/*Operators*/

		/*!
		\brief Compares the value of this character to the value of another character and
			tests whether the two character values are the same

		@param[in]	otherCharacter	The character to be compared with this character

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const Utf8Char& otherCharacter) const;

		/*!
		\brief Compares the value of this character to the value of another character and
			tests whether the two character values are the different

		@param[in]	otherCharacter	The character to be compared with this character

		\return true if the two character values are different, otherwise false
		*/
		bool operator!=(const Utf8Char& otherCharacter) const;

		/*!
		\brief Compares the value of this character to the value of a character reference and
			tests whether the two character values are the same

		@param[in]	characterReference	The character reference to be compared with this character

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const Utf8CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character to the value of another character reference and
			tests whether the two character values are different

		@param[in]	characterReference	The character reference to be compared with this character

		\return true if the two character values are the different, otherwise false
		*/
		bool operator!=(const Utf8CharReference& characterReference) const;

		/*!
		\brief Assigns the contents of another Utf8Char object to this object

		@param[in]	anotherCharacter	The other Utf8Char object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		Utf8Char& operator=(const Utf8Char& anotherCharacter);

		/*!
		\brief Assigns the contents of a Utf8CharReference object to this object

		@param[in]	characterReference	The Utf8CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		Utf8Char& operator=(const Utf8CharReference& characterReference);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-8 encoding.

		Note that if the given index isn't within the bounds of the character (whether the index is valid or
		not), the character will be	resized to allow that index to be read and written to.

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		char& operator[](const size_t index);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-8 encoding.

		Note that if the given index isn't within the bounds of the character (whether the index is valid or
		not), the character will be	*not* be resized, as this function can only be called on a constant.

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		const char& operator[](const size_t index) const;

		/*!
		\brief This operator converts a stream of 8-bit values to a UTF-8 character

		This function clears the contents of utf8Char before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled.

		@param[in]	inputStream	The input stream containing 8-bit values to be converted
			to a UTF-8 string
		@param[in]	utf8Char	The character object into which the converted UTF-8 character
			will be stored
		*/
		friend std::istream& operator >>(std::istream& inputStream, Utf8Char& utf8Char)
		{
			utf8Char.clear();

			//Read in the code points one by one
			if(!inputStream.eof() && inputStream.peek() != EOF)
			{
				utf8Char = Utf8Char::GetNextCharacter(inputStream);
			}

			//When we peek at the EOF, the error flag in the stream is tripped and stream functions
			//stop working. We need to clear the error flag.
			inputStream.clear();

			return inputStream;
		}

		/*!
		\brief This operator converts a UTF-8 character to a stream of 8-bit values

		No checks for validity are done, so the resulting UTF-8 stream may or may contain a valid
		UTF-8 character.

		@param[in]	outputStream	The output stream to which the contents of the UTF-8 character
			are to be written
		@param[in]	utf8Char	The UTF-8 character to be written to the output stream
		*/
		friend std::ostream& operator <<(std::ostream& outputStream, const Utf8Char& utf8Char)
		{
			outputStream.write(utf8Char.characterData.c_str(), (std::streamsize)(utf8Char.size()));

			return outputStream;
		}

		/*!
		\brief Converts this object to a Utf16Char object

		This operator assumes that this character is a valid UTF-8 character.

		\sa Utf8Char::is_valid()
		*/
		operator Utf16Char() const;

		/*Functions*/

		/*!
		\brief Returns c-style version of this character as an array of 8-bit code units

		The c-style array is owned by this object, and the pointer returned by this function is
		invalidated if any non-const functions are called on this object.

		\return A pointer to a null-terminated array of 8-bit code units
		*/
		const char* c_str() const;

		/*!
		\brief Clears the contents of the character, making it an empty character
		*/
		void clear();

		/*!
		\brief Indicates whether this character is a valid UTF-8 character

		This function assumes that size() is from 1 to 4.

		\return true if the code points in this character represent a valid UTF-8 character,
			otherwise false
		*/
		bool is_valid() const;

		/*!
		\brief Converts this character to a UTF-32 code point

		This function assumes that size() is from 1 to 4.

		\return This character as a UTF-32 code unit
		*/
		UInt32 to_utf_32() const;

		/*!
		\brief Returns the number of code units in this character
		*/
		size_t size() const;

		/*Static Functions*/

		/*!
		\brief Gets the next UTF-8 code point from a stream of 8-bit code units

		This functions assumes that inputStream is not at the end of the stream.  If only a partial
		code point is available, this function will return as many code units as it can find.  If
		the first code unit available is not a first code unit, we will have no idea how many code units
		are in the code point, so only a single code unit will be returned.

		@param[in]	inputStream	The input stream from which the next code point will be retrieved

		\return A UTF-8 character containing the next code point found in the input stream
		*/
		static Utf8Char GetNextCharacter(std::istream& inputStream);

	};
}

#endif
