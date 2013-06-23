/*!
\file UnicodeChar.h

This file contains the declaration of the UnicodeChar class
*/

#ifndef __UTFSTRING_UNICODECHAR_H__
#define __UTFSTRING_UNICODECHAR_H__

namespace UtfString
{
	//Forward Declarations
	class Utf8Char;
	class Utf16Char;
	class UnicodeCharReference;

	/*!
	\brief Represents a Unicode character in an encoding-neutral way

	The class acts as a thin wrapper that can contain a UTF-8 or UTF-16 character to facilitate an
	easier handling of characters when dealing with characters in an encoding-neutral fashion. 

	Since this is an encoding-neutral class, code units cannot be accessed directly.  In order to
	access the individual code units, an instance of this class must be cast to an encoding-
	specific class, such as Utf8Char or Utf16Char.  An instance of this class holds a copy of a character.  
	Changing the value of an instance of this class will not cause anything to be changed anywhere else.

	This object can be freely assigned and converted to or from a number of encoding-specific data types.
	Since a Unicode character must be encoded in some form or another in order to be stored.  We could
	always store the character one particular encoding, but in order avoid the inefficiency of multiple
	encoding conversions (original character is UTF-16 -> stored as UTF-8 -> converted back to UTF-16), 
	this class will store the character in its original encoding.  If you wish to avoid unnecessary
	encoding conversions, you get the internal encoding by calling GetInternalEncoding().

	*/
	class UTFSTRING_DLLEXPORT UnicodeChar
	{
	private:
		Utf8Char* m_utf8CharacterData;
		Utf16Char* m_utf16CharacterData;

	public:
		/*Constructors*/

		/*!
		\brief Initializes an empty UnicodeChar
		*/
		UnicodeChar();

        /*!
        \brief Initializes an instance of UnicodeChar using another instance of UnicodeChar

        This is a copy constructor, and sets the constructed instance to be the same as
        the UnicodeChar instance passed in as a parameter

        @param[in]  character   A character to use in initializing this character
        */
        UnicodeChar(const UnicodeChar& character);

        /*!
        \brief Initializes an instance of UnicodeChar using an instance of Utf16Char

        @param[in]  character   A character to use in initializing this character
        */
        UnicodeChar(const Utf16Char& character);

        /*!
        \brief Initializes an instance of UnicodeChar using an instance of Utf8Char

        @param[in]  character   A character to use in initializing this character
        */
        UnicodeChar(const Utf8Char& character);

        /*!
        \brief The destructor

		The destructor will clean up the encoding-specific string contained within
		this object
        */
        virtual ~UnicodeChar();

		/*Operators*/

		/*!
		\brief Compares the value of this character to the value of another character and
			tests whether the two character values are the same

		@param[in]	otherCharacter	The character to be compared with this character

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const UnicodeChar& otherCharacter) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-8 character and
			tests whether the two character Unicode values are the same

		@param[in]	character	The UTF-8 character to be compared with this character

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf8Char& character) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-16 character and
			tests whether the two character Unicode values are the same

		@param[in]	character	The UTF-16 character reference to be compared 
			with this character

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf16Char& character) const;

		/*!
		\brief Compares the value of this character to the value of a
			character reference and	tests whether the two character values are the same

		@param[in]	characterReference	The character reference to be compared with 
			this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const UnicodeCharReference& characterReference) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-8 character 
			reference and tests whether the two character Unicode values are the same

		@param[in]	characterReference	The UTF-8 character reference to be compared 
			with this character

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf8CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-16 character 
			reference and tests whether the two character Unicode values are the same

		@param[in]	characterReference	The UTF-16 character reference to be compared 
			with this character

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf16CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character to the value of another character and
			tests whether the two character values are the different

		@param[in]	otherCharacter	The character to be compared with this character

		\return true if the two character values are different, otherwise false
		*/
		bool operator!=(const UnicodeChar& otherCharacter) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-8 character and
			tests whether the two character Unicode values are the different

		@param[in]	character	The UTF-8 character to be compared with this character

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf8Char& character) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-16 character and
			tests whether the two character Unicode values are the different

		@param[in]	character	The UTF-16 character to be compared with this character

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf16Char& character) const;

		/*!
		\brief Compares the value of this character to the value of a
			character reference and	tests whether the two character values are the different

		@param[in]	characterReference	The character reference to be compared with 
			this character reference

		\return true if the two character values are the different, otherwise false
		*/
		bool operator!=(const UnicodeCharReference& characterReference) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-8 character 
			reference and tests whether the two character Unicode values are the different

		@param[in]	characterReference	The UTF-8 character reference to be compared with 
			this character

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf8CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character to the value of a UTF-16 character 
			reference and tests whether the two character Unicode values are the different

		@param[in]	characterReference	The UTF-16 character reference to be compared with 
			this character

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf16CharReference& characterReference) const;

		/*!
		\brief Assigns the contents of a UnicodeChar object to this object

		The contents of the other UnicodeChar object are copied to this object:
		they are not shared.

		@param[in]	character	The UnicodeChar object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeChar& operator=(const UnicodeChar& character);

		/*!
		\brief Assigns the contents of a Utf8Char object to this object

		@param[in]	character	The Utf8Char object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeChar& operator=(const Utf8Char& character);

		/*!
		\brief Assigns the contents of a Utf16Char object to this object

		@param[in]	character	The Utf16Char object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeChar& operator=(const Utf16Char& character);

		/*!
		\brief Assigns the contents of a Utf8CharReference object to this object

		@param[in]	characterReference	The Utf8CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeChar& operator=(const Utf8CharReference& characterReference);

		/*!
		\brief Assigns the contents of a Utf16CharReference object to this object

		@param[in]	characterReference	The Utf16CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeChar& operator=(const Utf16CharReference& characterReference);

		/*!
		\brief Converts this object to a Utf16Char object

		This operator assumes that if this character is non-empty, it is a valid 
		Unicode character.

		If this object does not contain a character, an empty Utf16Char
		will be returned

		\sa UnicodeChar::is_valid()
		\sa UnicodeChar::empty()
		*/
		operator Utf16Char() const;

		/*!
		\brief Converts this object to a Utf8Char object

		This operator assumes that if this character is non-empty, it is a valid 
		Unicode character.

		If this object does not contain a character, an empty Utf8Char
		will be returned

		\sa UnicodeChar::is_valid()
		\sa UnicodeChar::empty()
		*/
		operator Utf8Char() const;

		/*Functions*/

		/*!
		\brief Clears the contents of the character, making it an empty character
		*/
		void clear();

		/*!
		\brief Indicates whether this character is an empty character

		An empty character is one that doesn't contain any encoding-specific character
		data. This happens when an instance is not initialized with character data or
		clear() is called.
		*/
		bool empty() const;

		/*!
		\brief Indicates whether this character is a valid Unicode character

		If this object is able to convert the code units given to it during initialization
		to a Unicode character,	this character will be considered valid.

		If this character is an empty character, false will be returned.

		\return true if the code points in this character represent a valid Unicode character,
			otherwise false

		\sa UnicodeChar::empty()
		*/
		bool is_valid() const;

		/*!
		\brief Indicates the internal encoding used by this character

		The internal encoding of a UnicodeChar depends on what data is used to initialize the character
		or what data is assigned to the character when it is empty.  If a UnicodeChar is initialized
		with a UTF-8 character, the internal encoding will be UTF-8.  
		The opposite is the case when a UnicodeCharacter is initialized with a UTF-16 character. This is
		done to keep encoding conversions to a minimum.  If an application is dealing primarily with
		one encoding, and a character in that encoding is put in a UnicodeString, we avoid the conversion
		to a specific internal encoding and then the conversion back to the original encoding.

		\sa UnicodeChar::empty()
		*/
		const UtfEncoding internal_encoding() const;

		/*!
		\brief Converts this character to a UTF-32 code point

		This function assumes that is_valid() is true.
		If empty() is true, this function will return a value of 0xFFFFFFFF.

		\return This character as a UTF-32 code unit
		*/
		UInt32 to_utf_32() const;
	};
}

#endif
