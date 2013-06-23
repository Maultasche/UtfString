/*!
\file Utf16CharReference.h

This file contains the declaration of the Utf16CharReference class
*/

#ifndef __UTFSTRING_UTF16CHARREFERENCE_H__
#define __UTFSTRING_UTF16CHARREFERENCE_H__

namespace UtfString
{
	//Forward Declarations
	class Utf16Char;
	class Utf16CharReference;

	/*!
	\brief Provides a reference to a UTF-16 character embedded in a UTF-16 string

	Since a Utf16String provides an interface that hides the individual code units, a character
	is not directly pulled out of the Utf16String, but is constructed from the underlying code
	units.  This makes it impossible for an string indexer to return a character reference
	that can be assigned to.

	So this class acts as a reference to a character inside a string, so that if this character 
	reference is altered, the contents of the string are altered as well.
	This allows us to have a read/write indexer in Utf16String instead of a read-only indexer.

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

	Utf16Char and Utf16CharReference objects can be assigned to each other or converted from one
	to the other.
	*/
	class UTFSTRING_DLLEXPORT Utf16CharReference
	{
	private:
		std::basic_string<UInt16>& codeUnitString;
		std::basic_string<UInt16>::iterator codeUnitIterator;
		size_t codeUnitCount;

	public:
		/*Constructors*/

		/*!
		\brief Initializes an instance of Utf16CharReference using an iterator pointing to some code units
			and a count of the code units that comprise the character

		This constructor assumes that codeUnitCount is less than the maximum number of code units allowed 
		by the UTF-16 encoding.

		@param[in]	codeUnitString	The string containing the code units being referenced by this character
			reference
		@param[in]	basicStringIterator	An iterator pointing to the code units to be stored in this character
			reference
		@param[in]	codeUnitCount	The number of code units that comprise this character
		*/
		Utf16CharReference(std::basic_string<UInt16>& codeUnitString, 
			std::basic_string<UInt16>::iterator& basicStringIterator, size_t codeUnitCount);

		/*!
		\brief This copy constructor initializes an instance of Utf16CharReference that is an exact copy
			of another Utf16CharReference object

		@param[in]	otherCharacterReference	The Utf16CharReference object that is to be exactly copied
		*/
		Utf16CharReference(const Utf16CharReference& otherCharacterReference);

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
		bool operator==(const Utf16CharReference& otherCharacterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of another character reference and 
			tests whether the two references contain different character values

		This type of equality checking checks to see whether the character values of the two references are not equal.  
		This does not check whether the references are different. To test for that 
		type of reference inequality, use the reference_not_equal() function.

		@param[in] otherCharacterReference	The character reference to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator!=(const Utf16CharReference& otherCharacterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a character and 
			tests whether both contain the same character values

		@param[in] character	The character to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const Utf16Char& character) const;

		/*!
		\brief Compares the value of this character reference to the value of a character and 
			tests whether both contain different character values

		@param[in] character	The character to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator!=(const Utf16Char& character) const;

		/*!
		\brief Assigns the contents of another Utf16CharReference object to this object

		The contents of the other reference are assigned to this reference.  This does not cause the
		this reference to refer to the same character as the other reference.  To have this reference
		refer to the exact same character as another reference, use the assign_reference() function.

		Note that when the contents of this object are changed, the change is propogated to the
		referenced Utf16String object.

		@param[in]	otherCharacterReference	The other Utf16CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		Utf16CharReference& operator=(const Utf16CharReference& otherCharacterReference);
		
		/*!
		\brief Assigns the contents of a Utf16Char object to this object

		Note that when the contents of this object are changed, the change is propogated to the
		referenced Utf16String object.

		@param[in]	utf16Char	The Utf16Char object whose contents	are to be assigned to this object

		\return A reference to this object
		*/
		Utf16CharReference& operator=(const Utf16Char& utf16Char);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-16 encoding, and that index < size().

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		UInt16& operator[](const size_t index);

		/*!
		\brief Returns the code unit found at the specified index

		This operator does not check for the validity of the index, so it assumes that index is less than
		the maximum number of code units allowed by the UTF-16 encoding, and that index < size().

		@param[in]	index	The index identifying the code unit to be retrieved

		\return The code unit found at the specified index
		*/
		const UInt16& operator[](const size_t index) const;

		/*!
		\brief This operator converts a stream of 16-bit values to a UTF-16 character,
			and assigns it to a character reference

		This function clears the contents of utf16CharReference before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled.

		@param[in]	inputStream	The input stream containing 16-bit values to be converted
			to a UTF-16 string
		@param[in]	utf16CharReference	The character reference object to which the converted 
			UTF-16 character will be assigned
		*/
		friend std::istream& operator >>(std::istream& inputStream, Utf16CharReference& utf16CharReference)
		{
			Utf16Char utf16Char;

			UInt16 utf16CodeUnit;

			while(!inputStream.eof())
			{
				inputStream.read((char*)&utf16CodeUnit, sizeof(UInt16));
				utf16Char[0] = utf16CodeUnit;

				//If the first code unit is within a certain range, it is part of a 
				//surrogate pair. In this case, we need to read the second code
				//unit as well (if one exists)
				if(!inputStream.eof())
				{
					inputStream.read((char*)&utf16CodeUnit, sizeof(UInt16));
					utf16Char[1] = utf16CodeUnit;
				}
			}

			utf16CharReference = utf16Char;

			return inputStream;
		}

		/*!
		\brief This operator converts the character referred to by a UTF-16 character reference
			to a stream of 16-bit values

		No checks for validity are done, so the resulting UTF-16 stream may or may contain a valid
		UTF-16 character.

		@param[in]	outputStream	The output stream to which the contents of the UTF-16 character
			are to be written
		@param[in]	utf16CharReference	A reference to the UTF-16 character to be written to the 
			output stream
		*/
		friend std::ostream& operator <<(std::ostream& outputStream, const Utf16CharReference& utf16CharReference)
		{
			outputStream.write((char*)((Utf16Char)utf16CharReference).c_str(), (std::streamsize)(utf16CharReference.size() * 2));

			return outputStream;
		}

		/*!
		\brief This operator converts a wide stream of 16-bit values to a UTF-16 character,
			and assigns it to a character reference

		This function clears the contents of utf16CharReference before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled.

		@param[in]	inputStream	The wide input stream containing 16-bit values to be converted
			to a UTF-16 string
		@param[in]	utf16CharReference	The character reference object to which the converted 
			UTF-16 character will be assigned
		*/
		friend std::wistream& operator >>(std::wistream& inputStream, Utf16CharReference& utf16CharReference)
		{
			Utf16Char utf16Char;

			wchar_t utf16CodeUnit;

			while(!inputStream.eof())
			{
				inputStream.read(&utf16CodeUnit, 1);
				utf16Char[0] = utf16CodeUnit;

				//If the first code unit is within a certain range, it is part of a 
				//surrogate pair. In this case, we need to read the second code
				//unit as well (if one exists)
				if(!inputStream.eof())
				{
					inputStream.read(&utf16CodeUnit, 1);

					//If this doesn't turn out to be a the low code unit of a surrogate pair,
					//we must have an invalid code unit. So back up one code unit and store
					//the single high code unit as an invalid character
					if(utf16CodeUnit >= LowCodeUnitRangeBegin && utf16CodeUnit <= LowCodeUnitRangeEnd)
					{
						utf16Char[1] = utf16CodeUnit;
					}
					else
					{
						inputStream.seekg(-1, std::ios_base::cur);
					}				
				}
			}

			utf16CharReference = utf16Char;

			return inputStream;
		}

		/*!
		\brief This operator converts the character referred to by a UTF-16 character reference
			to a wide stream of 16-bit values

		No checks for validity are done, so the resulting UTF-16 stream may or may contain a valid
		UTF-16 character.

		@param[in]	outputStream	The wide output stream to which the contents of the UTF-16 character
			are to be written
		@param[in]	utf16CharReference	A reference to the UTF-16 character to be written to the 
			output stream
		*/
		friend std::wostream& operator <<(std::wostream& outputStream, const Utf16CharReference& utf16CharReference)
		{
		#ifdef WCHAR_T_16BIT
			outputStream.write((wchar_t*)((Utf16Char)utf16CharReference).c_str(), (std::streamsize)utf16CharReference.size());
		#else
			//Copy the UTF-16 chararacter to a wstring
			std::wstring wideString;
			
			for(size_t index = 0; index < utf16CharReference.size(); ++index)
			{
				wideString.append(1, (wchar_t)utf16CharReference[index]);
			}

			outputStream.write(wideString.c_str(), (std::streamsize)wideString.size());
		#endif

			return outputStream;
		}

		/*!
		\brief Converts this object to a Utf16Char object
		*/
		operator Utf16Char() const;

		/*!
		\brief Converts this object to a Utf8Char object

		This operator assumes that this character is a valid UTF-16 character. 
		
		\sa Utf16CharReference::is_valid()
		*/
		operator Utf8Char() const;

		/*Functions*/

		/*!
		\brief Assigns another character reference to this character reference, causing this character
			reference to refer to the exact same character as the other reference

		Note that this function does not copy the value of the other character reference and assign it
		to the value of this character reference.  To do that, use the assignment operator.

		@param[in]	otherCharacterReference	The reference to be assigned to this reference.
		*/
		void assign_reference(const Utf16CharReference& otherCharacterReference);

		/*!
		\brief Indicates whether this character is a valid UTF-16 character

		\return true if the code points in this character represent a valid UTF-16 character,
			otherwise false
		*/
		bool is_valid() const;

		/*!
		\brief Compares this character reference to another character reference and tests whether the two
			references refer to the exact same character

		This type of equality checking checks to see whether the two references refer to the exact same
		character in the same Utf16String.  This does not check whether the character values are equal.
		To test for that type of equality, use the == operator.

		@param[in]	otherCharacterReference	The character reference to be compared with this character
			reference

		\return true if this character reference refers to the exact same character as the other reference
		*/
		bool reference_equal(const Utf16CharReference& otherCharacterReference);

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
		bool reference_not_equal(const Utf16CharReference& otherCharacterReference);

		/*!
		\brief Converts this character to a UTF-32 code unit

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
