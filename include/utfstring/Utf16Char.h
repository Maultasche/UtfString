/*!
\file Utf16Char.h

This file contains the declaration of the Utf16Char class
*/

#ifndef __UTFSTRING_UTF16CHAR_H__
#define __UTFSTRING_UTF16CHAR_H__

namespace UtfString
{
	//Forward Declarations
	class Utf16Char;
	class Utf16CharReference;

	//TODO: Mention in the developer notes that since UtfString.dll is copied over into the
	//unit test directory as a post-build step , UtfString.dll will only be updated when the
	//UtfStringUnitTests project is built.  If source code in the UtfString project is updated, 
	//but nothing in the UtfStringUnitTests project is updated, a new UtfString.dll will be
	//built, but not copied over to the unit tests directory. This will result in the unit
	//tests running using an old version of UtfString.dll, so when running the unit tests, 
	//it won't appear that the source code change has had any effect. In order to work around
	//this copy the UtfString.dll in the the test/bin directory or rebuild the solution in
	//order to trigger the post-build copy. So far this is an issue for Visual Studio only.

	/*!
	\brief Provides a copy of a UTF-16 character embedded in a UTF-16 string

	Since a Utf16String provides an interface that hides the individual code units, a character
	is not directly pulled out of the Utf16String, but is constructed from the underlying code
	units.  This class holds a copy of those code units as a single character.  Changing the value
	of a Utf16Char will not cause anything to be changed anywhere else.

	Utf16Char and Utf16CharReference objects can be assigned to each other or converted from one
	to the other.
	*/
	class UTFSTRING_DLLEXPORT Utf16Char
	{
	private:
		std::basic_string<UInt16> characterData;

	public:
		/*Constructors*/

		/*!
		\brief Initializes an empty Utf16Char
		*/
		Utf16Char();

		/*!
		\brief Initializes an instance of Utf16Char using an iterator pointing to some code units
			and a count of the code units that comprise the character

		This constructor assumes that index is less than the maximum number of code units allowed by
		the UTF-16 encoding.  This constructor also assumes that there are at least codeUnitCount code
		units available in the string from the location of the iterator.  If the iterator is pointing
		to the last one-code-unit character, and a codeUnitCount of 2 is passed in, this constructor
		will read past the end of the string and a crash will result.

		@param[in]	basicStringIterator	An iterator pointing to the code units to be stored in this character
		@param[in]	codeUnitCount	The number of code units that comprise this character
		*/
		Utf16Char(const std::basic_string<UInt16>::iterator& basicStringIterator, size_t codeUnitCount);

		/*!
		\brief Initializes an instance of Utf16Char using an const_iterator pointing to some code units
			and a count of the code units that comprise the character

		This constructor assumes that index is less than the maximum number of code units allowed by
		the UTF-16 encoding. This constructor also assumes that there are at least codeUnitCount code
		units available in the string from the location of the iterator.  If the iterator is pointing
		to the last one-code-unit character, and a codeUnitCount of 2 is passed in, this constructor will
		read past the end of the string and a crash will result.

		@param[in]	basicStringIterator	An iterator pointing to the code units to be stored in this character
		@param[in]	codeUnitCount	The number of code units that comprise this character
		*/
		Utf16Char(const std::basic_string<UInt16>::const_iterator& basicStringIterator, size_t codeUnitCount);

		/*!
		\brief Initializes an instance of Utf16Char using a wide character

		The wide character passed into this constructor can contain only one code unit, so this constructor
		can only be used to initialize one-code-unit characters

		@param[in]	wideCharacter	The wide character to use in initializing this character
		*/
		Utf16Char(const wchar_t wideCharacter);

		/*!
		\brief Initializes an instance of Utf16Char using an 8-bit ASCII character

		The character passed into this constructor is assumed to be a complete 8-bit ASCII character,
		and not a code unit that comprises some UTF-8 character.  Note that this constructor only
		handles basic ASCII, the characters that match the first 128 code points in Unicode.
		Extended ASCII, which varies from platform to platform, will be converted to whatever code point
		happens to have the same value as the extended ASCII character.

		@param[in]	character The 8-bit ASCII character to use in initializing this character
		*/
		Utf16Char(const char character);

		/*!
		\brief Initializes an instance of Utf16Char using a variable-code-unit wide character

		The wide character passed into this constructor is in the form of a wide character string, which
		can contain one or more code units.  The wideCharacter parameter is assumed to be a valid pointer
		to a null-terminated wide character string.  If the length of wideCharacter is 0, this character
		will be initialized as an empty character.  If the length of wideCharacter is 1 or 2, the code
		units will be used to initialize this character, whether those code units represent a valid UTF-16
		character or not (validity can be checked using the is_valid() function). If the length of
		wideCharacter is more than 2, only the first two code units will be used, and the rest will be
		ignored.

		@param[in]	wideCharacter A wide character string containing code units to use in initializing this character
		*/
		Utf16Char(const wchar_t* wideCharacter);

        /*!
        \brief Initializes an instance of Utf16Char using another instance of Utf16Char

        This is a copy constructor, and sets the constructed instance to be the same as
        the Utf16Char instance passed in as a parameter

        @param[in]  character   A character to use in initializing this character
        */
        Utf16Char(const Utf16Char& character);

        /*!
        \brief The class destructor
        */
        virtual ~Utf16Char();

		/*Operators*/

		/*!
		\brief Compares the value of this character to the value of another character and
			tests whether the two character values are the same

		@param[in]	otherCharacter	The character to be compared with this character

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const Utf16Char& otherCharacter) const;

		/*!
		\brief Compares the value of this character to the value of another character and
			tests whether the two character values are the different

		@param[in]	otherCharacter	The character to be compared with this character

		\return true if the two character values are different, otherwise false
		*/
		bool operator!=(const Utf16Char& otherCharacter) const;

		/*!
		\brief Compares the value of this character to the value of a character reference and
			tests whether the two character values are the same

		@param[in]	characterReference	The character reference to be compared with this character

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const Utf16CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character to the value of another character reference and
			tests whether the two character values are the different

		@param[in]	characterReference	The character reference to be compared with this character

		\return true if the two character values are different, otherwise false
		*/
		bool operator!=(const Utf16CharReference& characterReference) const;

		/*!
		\brief Assigns the contents of another Utf16Char object to this object

		@param[in]	anotherCharacter	The other Utf16Char object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		Utf16Char& operator=(const Utf16Char& anotherCharacter);

		/*!
		\brief Assigns the contents of a Utf16CharReference object to this object

		@param[in]	characterReference	The Utf16CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		Utf16Char& operator=(const Utf16CharReference& characterReference);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-16 encoding.

		Note that if the given index isn't within the bounds of the character (whether the index is valid or
		not), the character will be	resized to allow that index to be read and written to.

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		UInt16& operator[](const size_t index);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-16 encoding.

		Note that if the given index isn't within the bounds of the character (whether the index is valid or
		not), the character will be	*not* be resized, as this function can only be called on a constant.

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		const UInt16& operator[](const size_t index) const;

		/*!
		\brief This operator converts a stream of 16-bit values to a UTF-16 character

		This function clears the contents of utf16Char before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled. 

		@param[in]	inputStream	The input stream containing 16-bit values to be converted
			to a UTF-16 character
		@param[in]	utf16Char	The character object into which the converted UTF-16 character
			will be stored
		*/
		friend std::istream& operator >>(std::istream& inputStream, Utf16Char& utf16Char)
		{
			utf16Char.clear();

			UInt16 utf16CodeUnit;

			if(!inputStream.eof())
			{
				inputStream.read((char*)&utf16CodeUnit, sizeof(UInt16));
				utf16Char.characterData.append(&utf16CodeUnit, 1);

				//If the first code unit is within a certain range, it is part of a 
				//surrogate pair. In this case, we need to read the second code
				//unit as well (if one exists). If for some reason we run into a low code unit
				//of a surrogate pair without a high code unit, we just read it in as an
				//invalid one-code-unit character
				if(!inputStream.eof() && utf16CodeUnit >= HighCodeUnitRangeBegin && 
					utf16CodeUnit <= HighCodeUnitRangeEnd)
				{
					inputStream.read((char*)&utf16CodeUnit, sizeof(UInt16));

					//If this doesn't turn out to be a the low code unit of a surrogate pair,
					//we must have an invalid code unit. So back up one code unit and store
					//the single high code unit as an invalid character
					if(utf16CodeUnit >= LowCodeUnitRangeBegin && utf16CodeUnit <= LowCodeUnitRangeEnd)
					{
						utf16Char.characterData.append(&utf16CodeUnit, 1);
					}
					else
					{
						inputStream.seekg(-(int)sizeof(UInt16), std::ios_base::cur);
					}				
				}
			}

			return inputStream;
		}

		/*!
		\brief This operator converts a UTF-16 character to a stream of 16-bit values

		No checks for validity are done, so the resulting UTF-16 stream may or may not contain a valid
		UTF-16 character. The endianness of the bytes in stream is the same as the endiannes of them
		machine on which this function is compiled.

		@param[in]	outputStream	The output stream to which the contents of the UTF-16 character
			are to be written
		@param[in]	utf16Char	The UTF-16 character to be written to the output stream
		*/
		friend std::ostream& operator <<(std::ostream& outputStream, const Utf16Char& utf16Char)
		{
			outputStream.write((char*)utf16Char.c_str(), (std::streamsize)(utf16Char.size() * 2));

			return outputStream;
		}

		/*!
		\brief This operator converts a wide stream of 16-bit values to a UTF-16 character

		This function clears the contents of utf16Char before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled. 

		@param[in]	inputStream	The wide input stream containing 16-bit values to be converted
			to a UTF-16 character
		@param[in]	utf16Char	The character object into which the converted UTF-16 character
			will be stored
		*/
		friend std::wistream& operator >>(std::wistream& inputStream, Utf16Char& utf16Char)
		{
			utf16Char.clear();

			wchar_t utf16CodeUnit;

			if(!inputStream.eof())
			{
				inputStream.read(&utf16CodeUnit, 1);
				utf16Char.characterData.append(1, (wchar_t)utf16CodeUnit);

				//If the first code unit is within a certain range, it is part of a 
				//surrogate pair. In this case, we need to read the second code
				//unit as well (if one exists). If for some reason we run into a low code unit
				//of a surrogate pair without a high code unit, we just read it in as an
				//invalid one-code-unit character
				if(!inputStream.eof() && utf16CodeUnit >= HighCodeUnitRangeBegin && 
					utf16CodeUnit <= HighCodeUnitRangeEnd)
				{
					inputStream.read(&utf16CodeUnit, 1);

					//If this doesn't turn out to be a the low code unit of a surrogate pair,
					//we must have an invalid code unit. So back up one code unit and store
					//the single high code unit as an invalid character
					if(utf16CodeUnit >= LowCodeUnitRangeBegin && utf16CodeUnit <= LowCodeUnitRangeEnd)
					{
						utf16Char.characterData.append(1, (UInt16)utf16CodeUnit);
					}
					else
					{
						inputStream.seekg(-1, std::ios_base::cur);
					}				
				}
			}

			return inputStream;
		}

		/*!
		\brief This operator converts a UTF-16 character to a wide stream of 16-bit values

		No checks for validity are done, so the resulting UTF-16 stream may or may not contain a valid
		UTF-16 character. The endianness of the bytes in stream is the same as the endiannes of them
		machine on which this function is compiled.

		@param[in]	outputStream	The wide output stream to which the contents of the UTF-16 character
			are to be written
		@param[in]	utf16Char	The UTF-16 character to be written to the wide output stream
		*/
		friend std::wostream& operator <<(std::wostream& outputStream, const Utf16Char& utf16Char)
		{
		#ifdef WCHAR_T_16BIT
			outputStream.write((wchar_t*)utf16Char.c_str(), (std::streamsize)utf16Char.size());
		#else
			//Copy the UTF-16 chararacter to a wstring
			std::wstring wideString;
			
			for(size_t index = 0; index < utf16Char.size(); ++index)
			{
				wideString.append(1, (wchar_t)utf16Char[index]);
			}

			outputStream.write(wideString.c_str(), (std::streamsize)wideString.size());
		#endif

			return outputStream;
		}

	
		/*!
		\brief Converts this object to a Utf8Char object

		This operator assumes that this character is a valid UTF-16 character.

		\sa Utf16Char::is_valid()
		*/
		operator Utf8Char() const;

		/*Functions*/

		/*!
		\brief Returns c-style version of this character as an array of 16-bit code units

		The c-style array is owned by this object, and the pointer returned by this function is
		invalidated if any non-const functions are called on this object.

		\return A pointer to a null-terminated array of 16-bit code units
		*/
		const UInt16* c_str() const;

		/*!
		\brief Clears the contents of the character, making it an empty character
		*/
		void clear();

		/*!
		\brief Indicates whether this character is a valid UTF-16 character

		This function assumes that size() is 1 or 2.

		\return true if the code points in this character represent a valid UTF-16 character,
			otherwise false
		*/
		bool is_valid() const;

		/*!
		\brief Converts this character to a UTF-32 code point

		This function assumes that size() is 1 or 2.

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
