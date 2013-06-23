/*!
\file UnicodeCharReference.h

This file contains the declaration of the UnicodeCharReference class
*/

#ifndef __UTFSTRING_UNICODECHARREFERENCE_H__
#define __UTFSTRING_UNICODECHARREFERENCE_H__

namespace UtfString
{
	//Forward Declarations
	class UnicodeChar;

	/*!
	\brief Provides a reference to an encoding-neutral Unicode character embedded in an 
		encoding-neutral Unicode string

	Since a UnicodeString provides an interface that hides an encoding-specific string, a character
	is not directly pulled out of the UnicodeString, but is constructed from the underlying encoding-
	specific string.  This makes it impossible for an string indexer to return a character reference
	that can be assigned to.

	So this class acts as a reference to a character inside a string, so that if this character 
	reference is altered, the contents of the string are altered as well.
	This allows us to have a read/write indexer in UnicodeString instead of a read-only indexer.

	UnicodeCharReference encapsulates an encoding-specific character reference.  For example, if 
	UnicodeString encapsulates a Utf8String, UnicodeCharReference will encapsulate a 
	Utf8CharReference.  UnicodeCharReference can only be cast to the same type as the encapsulated
	character reference. To find the underlying encoding, use the GetInternalEncoding() member
	function.

	Character references may become invalid if the contents of the string being referred to is
	modified in any way.  If a string is modified by adding or removing characters, the associated 
	character reference may then refer to another character or to somewhere outside the string.
	Attempting to use a character reference that no longer refers to a valid character will most
	likely cause a runtime error.

	Since this is an encoding-neutral character reference, individual code units cannot be retrieved
	or set.	You can only set an entire character (using a UTF-8, UTF-16 character string, or the
	32-bit code point value) or retrieve the character's 32-bit code point value. You can, however,
	cast the UnicodeCharReference to its underlying encoding to retrieve and set the code units
	directly.  You <i>cannot</i> cast a UnicodeCharReference to another encoding-specific character
	reference. The reason for this that UnicodeCharReference encapsulates an encoding-specific
	reference to an encoding-specific string (which was encapsulated by the UnicodeString). 
	It would be complex and rather inefficent to handle translating code units to and from the
	code units referred to by an encoding-specific reference, and would require significant changes
	to Utf8CharReference and Utf16CharReference. It may be technically possible, but it's simply 
	not worth it. If you need to address code units at all in a character reference, it's far easier
	and efficient to use an encoding-specific string and encoding-specific character reference 
	instead of UnicodeString and UnicodeCharReference.

	Note that if you attempt to cast a UnicodeCharReference to a character reference of a different
	type than the encapsulated character reference, you will either get a crash or an assertion
	failure. Use the GetInternalEncoding() member function to prevent this.

	UnicodeChar and UnicodeCharReference objects can be assigned to each other or converted from one
	to the other.
	*/
	class UTFSTRING_DLLEXPORT UnicodeCharReference
	{
	private:
		Utf8CharReference* m_utf8CharacterReference;
		Utf16CharReference* m_utf16CharacterReference;

	public:
		/*Constructors*/

		/*!
		\brief Initializes an instance of UnicodeCharReference using another UnicodeCharReference instance

		@param[in]	unicodeCharReference	The Unicode character reference to use in initializing this object
		*/
		UnicodeCharReference(const UnicodeCharReference& unicodeCharReference);

		/*!
		\brief Initializes an instance of UnicodeCharReference using a Utf8CharReference instance

		@param[in]	utf8CharReference	The UTF-8 character reference to use in initializing this object
		*/
		UnicodeCharReference(const Utf8CharReference& utf8CharReference);

		/*!
		\brief Initializes an instance of UnicodeCharReference using a Utf16CharReference instance

		@param[in]	utf16CharReference	The UTF-16 character reference to use in initializing this object
		*/
		UnicodeCharReference(const Utf16CharReference& utf16CharReference);

        /*!
        \brief The destructor

		The destructor will clean up the encoding-specific string contained within
		this object
        */
        virtual ~UnicodeCharReference();

		/*Operators*/
		
		/*!
		\brief Compares the value of this character reference to the value of another character reference and
			tests whether the two character values are the same

		This type of equality checking checks to see whether the character values of the two references are equal.  
		This does not check whether the references refer to the same character in the same string. To test for
		that type of reference equality, use the reference_equal() function.

		@param[in]	otherCharacterReference	The character reference to be compared with this character reference

		\return true if the two character values are the same, otherwise false
		*/
		bool operator==(const UnicodeCharReference& otherCharacterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-8 character 
			reference and tests whether the two character Unicode values are the same

		This type of equality checking checks to see whether the character values of the two references are equal.  
		This does not check whether the references refer to the same character in the same string. To test for
		that type of reference equality, use the reference_equal() function.

		@param[in]	characterReference	The UTF-8 character reference to be compared with this 
			character reference

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf8CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-16 character 
			reference and tests whether the two character Unicode values are the same

		This type of equality checking checks to see whether the character values of the two references are equal.  
		This does not check whether the references refer to the same character in the same string. To test for
		that type of reference equality, use the reference_equal() function.

		@param[in]	characterReference	The UTF-16 character reference to be compared 
			with this character reference

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf16CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a Unicode character and
			tests whether the two character Unicode values are the same

		@param[in]	character	The Unicode character to be compared with this character

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const UnicodeChar& character) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-8 character and
			tests whether the two character Unicode values are the same

		@param[in]	character	The UTF-8 character to be compared with this character

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf8Char& character) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-16 character and
			tests whether the two character Unicode values are the same

		@param[in]	character	The UTF-16 character to be compared 
			with this character

		\return true if the two character Unicode values are the same, otherwise false
		*/
		bool operator==(const Utf16Char& character) const;

		/*!
		\brief Compares the value of this character reference to the value of another character reference and
			tests whether the two character values are different

		This type of equality checking checks to see whether the character values of the two references are not equal.  
		This does not check whether the references are different. To test for that 
		type of reference inequality, use the reference_not_equal() function.

		@param[in]	otherCharacterReference	The character reference to be compared with this character reference

		\return true if the two character values are different, otherwise false
		*/
		bool operator!=(const UnicodeCharReference& otherCharacterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-8 character 
			reference and tests whether the two character Unicode values are different

		This type of equality checking checks to see whether the character values of the two references are not equal.  
		This does not check whether the references are different. To test for that 
		type of reference inequality, use the reference_not_equal() function.

		@param[in]	characterReference	The UTF-8 character reference to be compared with this 
			character reference

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf8CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-16 character 
			reference and tests whether the two character Unicode values are different

		This type of equality checking checks to see whether the character values of the two references are not equal.  
		This does not check whether the references are different. To test for that 
		type of reference inequality, use the reference_not_equal() function.

		@param[in]	characterReference	The UTF-16 character reference to be compared 
			with this character reference

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf16CharReference& characterReference) const;

		/*!
		\brief Compares the value of this character reference to the value of a Unicode character and
			tests whether the two character Unicode values are different

		@param[in]	character	The Unicode character to be compared with this character

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const UnicodeChar& character) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-8 character and
			tests whether the two character Unicode values are different

		@param[in]	character	The UTF-8 character to be compared with this character reference

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf8Char& character) const;

		/*!
		\brief Compares the value of this character reference to the value of a UTF-16 character and
			tests whether the two character Unicode values are different

		@param[in]	character	The UTF-16 character to be compared 
			with this character

		\return true if the two character Unicode values are different, otherwise false
		*/
		bool operator!=(const Utf16Char& character) const;

		/*!
		\brief Assigns the contents of a UnicodeCharReference object to this object

		The contents of the other reference are assigned to this reference.  This does not cause the
		this reference to refer to the same character as the other reference.  To have this reference
		refer to the exact same character as another reference, use the assign_reference() function.
		
		\sa UnicodeCharReference::assign_reference()

		@param[in]	characterReference	The UnicodeCharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeCharReference& operator=(const UnicodeCharReference& characterReference);

		/*!
		\brief Assigns the contents of a Utf8CharReference object to this object

		The contents of the other reference are assigned to this reference.  This does not cause the
		this reference to refer to the same character as the other reference.  To have this reference
		refer to the exact same character as another reference, use the assign_reference() function.
		
		\sa UnicodeCharReference::assign_reference()

		@param[in]	characterReference	The Utf8CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeCharReference& operator=(const Utf8CharReference& characterReference);

		/*!
		\brief Assigns the contents of a Utf16CharReference object to this object

		The contents of the other reference are assigned to this reference.  This does not cause the
		this reference to refer to the same character as the other reference.  To have this reference
		refer to the exact same character as another reference, use the assign_reference() function.
		
		\sa UnicodeCharReference::assign_reference()

		@param[in]	characterReference	The Utf16CharReference object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeCharReference& operator=(const Utf16CharReference& characterReference);

		/*!
		\brief Assigns the contents of a UnicodeChar object to this object

		The contents of the UnicodeChar object are copied to this object:
		they are not shared.

		@param[in]	character	The UnicodeChar object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeCharReference& operator=(const UnicodeChar& character);

		/*!
		\brief Assigns the contents of a Utf8Char object to this object

		@param[in]	character	The Utf8Char object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeCharReference& operator=(const Utf8Char& character);

		/*!
		\brief Assigns the contents of a Utf16Char object to this object

		@param[in]	character	The Utf16Char object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeCharReference& operator=(const Utf16Char& character);

		/*!
		\brief Converts this object to a UnicodeChar object

		\sa UnicodeChar::is_valid()
		*/
		operator UnicodeChar() const;

		/*!
		\brief Converts this object to a Utf8Char object

		This operator assumes that this character is a valid Unicode character. 

		\sa UnicodeCharReference::is_valid()
		*/
		operator Utf8Char() const;

		/*!
		\brief Converts this object to a Utf16Char object

		This operator assumes that this character is a valid Unicode character. 
		
		\sa UnicodeCharReference::is_valid()
		*/
		operator Utf16Char() const;

		/*!
		\brief Converts this object to a Utf8CharReference object

		This conversion operator will only work if the underlying encoding is UTF-8;
		otherwise, an assertion failure or crash will result.  This operator assumes
		that this reference has an internal encoding of ENCODING_UTF8.

		\sa UnicodeCharReference::internal_encoding()
		*/
		operator Utf8CharReference() const;

		/*!
		\brief Converts this object to a Utf16CharReference object

		This conversion operator will only work if the underlying encoding is UTF-16;
		otherwise, an assertion failure or crash will result.  This operator assumes
		that this reference has an internal encoding of ENCODING_UTF16.

		\sa UnicodeCharReference::internal_encoding()
		*/
		operator Utf16CharReference() const;

		/*Functions*/

		/*!
		\brief Assigns another character reference to this character reference, causing this character
			reference to refer to the exact same character as the other reference

		Note that this function does not copy the value of the other character reference and assign it
		to the value of this character reference.  To do that, use the assignment operator.

		@param[in]	otherCharacterReference	The reference to be assigned to this reference.
		*/
		void assign_reference(const UnicodeCharReference& otherCharacterReference);

		/*!
		\brief Indicates the internal encoding used by this character reference

		The internal encoding of a UnicodeCharReference depends on what data is used to initialize the 
		character.  If a UnicodeCharReference is initialized with a UTF-8 character reference, the 
		internal encoding will be UTF-8.  
		The opposite is the case when a UnicodeCharReference is initialized with a UTF-16 character 
		reference. This is done to keep encoding conversions to a minimum.  If an application is 
		dealing primarily with one encoding, and a character in that encoding is put in a 
		UnicodeString, we avoid the conversion to a specific internal encoding and then the 
		conversion back to the original encoding.
		*/
		const UtfEncoding internal_encoding() const;

		/*!
		\brief Indicates whether the character value of this reference is a valid Unicode character

		If this object is able to convert the code units given to it during initialization
		to a Unicode character,	this character will be considered valid.

		\return true if the code points in this character represent a valid Unicode character,
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
		bool reference_equal(const UnicodeCharReference& otherCharacterReference);

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
		bool reference_not_equal(const UnicodeCharReference& otherCharacterReference);

		/*!
		\brief Converts the character value of this character reference to a UTF-32 code point

		This function assumes that is_valid() is true.
		If empty() is true, this function will return a value of 0xFFFFFFFF.

		\return This character as a UTF-32 code unit
		*/
		UInt32 to_utf_32() const;
	};
}

#endif
