/*!
\file Utf16String.h

This file contains the functionality for managing UTF-16 strings
*/

#ifndef __UTFSTRING_UTF16STRING_H__
#define __UTFSTRING_UTF16STRING_H__

#include "Utf16Char.h"
#include "Utf16CharReference.h"


namespace UtfString
{
	//Template Exports for iterator classes
	#ifndef POSIX
		UTFSTRING_EXPORTTEMPLATE template struct UTFSTRING_DLLEXPORT std::iterator<std::random_access_iterator_tag, Utf16Char>;
	#endif

	/*!
	\brief Contains and manages a UTF-16 string

	This class inherits the STL wstring class.  The wstring class can hold UTF-16 strings, but it becomes
	difficult to conduct any string operations on the UTF-16 string because UTF-16 has variable-length characters.
	The wstring class is best suited for fixed-length UCS-2 strings, hence why we need a separate class for
	UTF-16 strings.  When accessing individual characters in a Utf16String, wstring objects will be returned.
	In the vast majority of cases, the wstring will contain a character consisting of a single 16-bit code unit, but in
	some instances will contain two 16-bit code units.

	Using Utf16String is generally advised when dealing with UTF-16 files or when you know that you will be dealing
	with characters beyond the basic multilingual plane.  If you won't be using characters beyond the basic
	multilingual plane, which is mostly populated by code points for use by Asian languages, then the fixed-width
	wstring class will probably suffice.

	Endianness does not affect the UTF-16 string class. It stores the string as a sequence of 16-bit code units,
	and C++ abstracts the endianness of a particular code unit.  The endianness would become important only if
	this string was directly converted into a sequence of bytes, where C++ would no longer be able to abstract
	the byte order.
	*/
	class UTFSTRING_DLLEXPORT Utf16String
	{
	private:
		//The encapsulated string that stores the UTF-16 code units
		std::basic_string<UInt16> m_codeUnitString;

	public:
		/*Constructors*/

		/*!
		\brief The default constructor
		*/
		Utf16String();

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf16String	A string of 16-bit code units to be the initial value of the
			string that is being created.
		*/
		Utf16String(const Utf16String& utf16String);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf16String	A string of 16-bit code units to be the initial value of the
			string that is being created. The string is assumed to be a UTF-16 string.
		*/
		Utf16String(const std::basic_string<UInt16>& utf16String);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf16String	A string of 16-bit code units to be the initial value of the
			string that is being created. The string is assumed to be a UTF-16 string.
		*/
		Utf16String(const UInt16* utf16String);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf16String	A string of 16-bit code units to be the initial value of the
			string that is being created. The string is assumed to be a UTF-16 string.
		@param[in]	codeUnitCount The number of code units in utf16String to be used in initializing
			this string.
		*/
		Utf16String(const UInt16* utf16String, const size_t codeUnitCount);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	wideString A string of wchar_t to be the initial value of the string that
			is being created. The string is assumed to be a UTF-16 string.
		*/
		Utf16String(const wchar_t* wideString);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	wideString A string of wchar_t to be the initial value of the string that
			is being created. The string is assumed to be a UTF-16 string.
		@param[in]	characterCount The number of characters in wideString to be used in initializing
			this string.
		*/
		Utf16String(const wchar_t* wideString, const size_t characterCount);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	wideString	A string wchar_t to be the initial value of the string that
			is being created. The string is assumed to be a UTF-16 string.
		*/
		Utf16String(const std::wstring& wideString);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf8String A UTF-8 string to be made the initial value of the string that is
			being created. The string is assumed to be a valid UTF-8 string.
		*/
		Utf16String(const Utf8String& utf8String);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf8String A UTF-8 string to be made the initial value of the string that is
			being created. The string is assumed to be a valid UTF-8 string.
		*/
		Utf16String(const std::string utf8String);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf8String A UTF-8 string to be made the initial value of the string that is
			being created. The string is assumed to be a valid UTF-8 string.
		*/
		Utf16String(const char* utf8String);

		/*!
		\brief Initializes a string with the contents of another string as its initial value

		@param[in]	utf8String A UTF-8 string to be made the initial value of the string that is
			being created. The string is assumed to be a valid UTF-8 string.
		@param[in]	characterCount The number of characters in utfS8String to be used in initializing
			this string.
		*/
		Utf16String(const char* utf8String, const size_t characterCount);

        /*!
        \brief The class destructor
        */
        virtual ~Utf16String();

		/*Iterators*/

		/*Forward Declarations*/
		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;

		/*!
		\brief An iterator that iterates through the code points in a UTF-16 string

		This iterator assumes that the UTF-16 string being iterated over is a valid UTF-16 string.
		*/
		class UTFSTRING_DLLEXPORT iterator : public std::iterator<std::random_access_iterator_tag, Utf16Char>
		{
			friend class Utf16String::const_iterator;
			friend class Utf16String::reverse_iterator;
			friend class Utf16String;

		private:
			std::basic_string<UInt16>& codeUnitString;
			std::basic_string<UInt16>::iterator codeUnitPosition;
			Utf16CharReference* currentCharacterReference;

		public:
			/*!
			\brief Constructs an iterator for Utf16String using the base class iterator

			This function assumes that basicStringIterator is a valid iterator

			@param[in]	basicString	A reference to the string that baseStringIterator points to
			@param[in]	basicStringIterator	The base class iterator to use in constructing this
				iterator
			*/
			iterator(std::basic_string<UInt16>& basicString,
				const std::basic_string<UInt16>::iterator& basicStringIterator);

			/*!
			\brief Constructs an iterator for Utf16String using another iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to use in constructing this iterator
			*/
			iterator(const Utf16String::iterator& otherIterator);

			/*!
			\brief Constructs an iterator for Utf16String using a reverse iterator

			This iterator will take on the same position as the reverse iterator.

			@param[in]	reverseIterator	The reverse iterator to use in constructing this iterator
			*/
			iterator(const Utf16String::reverse_iterator& reverseIterator);

			/*!
			\brief Cleans up before the iterator is destroyed
			*/
			~iterator();

			/*!
			\brief Assigns the value of another iterator to this iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to be assigned to this iterator

			\return A reference to this object after the assignment has been completed
			*/
			iterator& operator=(const Utf16String::iterator& otherIterator);

			/*!
			\brief Compares this iterator with another iterator and tests for equality

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if otherIterator is pointing to the same position as this iterator,
				otherwise false
			*/
			bool operator==(const iterator& otherIterator) const;

			/*!
			\brief Compares this iterator with another iterator and tests for inequality

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return false if otherIterator is pointing to the same position as this iterator,
				otherwise true
			*/
			bool operator!=(const iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const iterator& otherIterator);

			/*!
			\brief Increments this iterator to the next position in the Utf16String

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			iterator& operator++();

			/*!
			\brief Increments this iterator to the next position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			iterator operator+(size_t offset);

			/*!
			\brief Decrements this iterator to the previous position in the Utf16String

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			iterator& operator--();

			/*!
			\brief Decrements this iterator to the previous position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was decremented
			*/
			iterator operator--(int);

			/*!
			\brief Decrements this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing this iterator

			\return A reference to this iterator
			*/
			iterator& operator-=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator decremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return An iterator that points to the offset position
			*/
			iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this iterator

			If this iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			\return A reference to the the character being pointed to by this iterator
			*/
			Utf16CharReference operator*();

			/*!
			\brief Gets a pointer to the character at the position of this iterator

			If this iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			\return A pointer to the character being pointed to by this iterator
			*/
			Utf16CharReference* operator->();
		};

		/*!
		\brief An iterator that iterates through the code points in a UTF-16 string, but allowing
			only access to constant code points

		This iterator assumes that the UTF-16 string being iterated over is a valid UTF-16 string.
		*/
		class UTFSTRING_DLLEXPORT const_iterator : public std::iterator<std::random_access_iterator_tag, Utf16Char>
		{
			friend class Utf16String::const_reverse_iterator;

		private:
			const std::basic_string<UInt16>& codeUnitString;
			std::basic_string<UInt16>::const_iterator codeUnitPosition;
			Utf16Char* currentCharacter;

		public:
			/*!
			\brief Constructs an iterator for Utf16String using the base class iterator

			This function assumes that basicStringIterator is a valid iterator

			@param[in]	basicString	A reference to the string that basicStringIterator points to
			@param[in]	basicStringIterator	The base class iterator to use in constructing this
				iterator
			*/
			const_iterator(const std::basic_string<UInt16>& basicString,
				const std::basic_string<UInt16>::const_iterator& basicStringIterator);

			/*!
			\brief Constructs an iterator for Utf16String using a non-constant iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to use in constructing this iterator
			*/
			const_iterator(const Utf16String::iterator& otherIterator);

			/*!
			\brief Constructs an iterator for Utf16String using another constant iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to use in constructing this iterator
			*/
			const_iterator(const Utf16String::const_iterator& otherIterator);

			/*!
			\brief Constructs an constant iterator for Utf16String using a constant reverse iterator

			This constant iterator will take on the same position as the constant reverse iterator.

			@param[in]	reverseIterator	The constant reverse iterator to use in constructing this
				constant iterator
			*/
			const_iterator(const Utf16String::const_reverse_iterator& reverseIterator);

			/*!
			\brief Cleans up before the iterator is destroyed
			*/
			~const_iterator();

			/*!
			\brief Assigns the value of another iterator to this iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to be assigned to this iterator

			\return A reference to this object after the assignment has been completed
			*/
			const_iterator& operator=(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator with another iterator and tests for equality

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if otherIterator is pointing to the same position as this iterator,
				otherwise false
			*/
			bool operator==(const const_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator with another iterator and tests for inequality

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return false if otherIterator is pointing to the same position as this iterator,
				otherwise true
			*/
			bool operator!=(const const_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const const_iterator& otherIterator);

			/*!
			\brief Increments this iterator to the next position in the Utf16String

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			const_iterator& operator++();

			/*!
			\brief Increments this iterator to the next position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			const_iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			const_iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			const_iterator operator+(size_t offset);

			/*!
			\brief Decrements this iterator to the previous position in the Utf16String

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			const_iterator& operator--();

			/*!
			\brief Decrements this iterator to the previous position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was decremented
			*/
			const_iterator operator--(int);

			/*!
			\brief Decrements this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing this iterator

			\return A reference to this iterator
			*/
			const_iterator& operator-=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator decremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return An iterator that points to the offset position
			*/
			const_iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this iterator

			If this iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			\return A reference to the the character being pointed to by this iterator
			*/
			const Utf16Char operator*();

			/*!
			\brief Gets a pointer to the character at the position of this iterator

			If this iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			\return A pointer to the character being pointed to by this iterator
			*/
			const Utf16Char* operator->();
		};

		/*!
		\brief An iterator that iterates through the code points in a UTF-16 string in reverse order

		This iterator assumes that the UTF-16 string being iterated over is a valid UTF-16 string.
		*/
		class UTFSTRING_DLLEXPORT reverse_iterator : public std::iterator<std::random_access_iterator_tag, Utf16Char>
		{
			friend class Utf16String::const_reverse_iterator;
			friend class Utf16String::iterator;

		private:
			std::basic_string<UInt16>& codeUnitString;
			std::basic_string<UInt16>::reverse_iterator codeUnitPosition;
			Utf16CharReference* currentCharacterReference;

		public:
			/*!
			\brief Constructs a reverse iterator for Utf16String using the base class iterator

			This function assumes that basicStringIterator is a valid reverse iterator

			@param[in]	basicString	A reference to the string that baseStringIterator points to
			@param[in]	basicStringIterator	The base class reverse iterator to use in
				constructing this iterator
			*/
			reverse_iterator(std::basic_string<UInt16>& basicString,
				const std::basic_string<UInt16>::reverse_iterator& basicStringIterator);

			/*!
			\brief Constructs a reverse iterator for Utf16String using another iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other reverse iterator to use in constructing
				this reverse iterator
			*/
			reverse_iterator(const Utf16String::reverse_iterator& otherIterator);

			/*!
			\brief Constructs a reverse iterator for Utf16String using an iterator

			This reverse iterator will take on the same position as the iterator.

			@param[in]	iterator	The iterator to use in constructing this reverse iterator
			*/
			reverse_iterator(const Utf16String::iterator& iterator);

			/*!
			\brief Assigns the value of another reverse iterator to this reverse iterator

			This reverse iterator will take on the same characteristics and position as the
			other reverse iterator

			@param[in]	otherIterator	The other reverse iterator to be assigned to this
				reverse iterator

			\return A reference to this object after the assignment has been completed
			*/
			reverse_iterator& operator=(const Utf16String::reverse_iterator& otherIterator);

			/*!
			\brief Cleans up before the iterator is destroyed
			*/
			~reverse_iterator();

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for equality

			@param[in]	otherIterator	The other reverse iterator to be compared with this
				reverse iterator

			\return true if otherIterator is pointing to the same position as this reverse
				iterator, otherwise false
			*/
			bool operator==(const reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for inequality

			@param[in]	otherIterator	The other reverse iterator to be compared with
				this reverse iterator

			\return false if otherIterator is pointing to the same position as this reverse
				iterator, otherwise true
			*/
			bool operator!=(const reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const reverse_iterator& otherIterator);

			/*!
			\brief Increments this reverse iterator to the previous position in the Utf16String

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			reverse_iterator& operator++();

			/*!
			\brief Increments this reverse iterator to the previous position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			reverse_iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			reverse_iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			reverse_iterator operator+(size_t offset);

			/*!
			\brief Decrements this reverse iterator to the next position in the Utf16String

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			reverse_iterator& operator--();

			/*!
			\brief Decrements this reverse iterator to the next position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was decremented
			*/
			reverse_iterator operator--(int);

			/*!
			\brief Decrements this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing this iterator

			\return A reference to this iterator
			*/
			reverse_iterator& operator-=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator decremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return An iterator that points to the offset position
			*/
			reverse_iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			\return A reference to the the character being pointed to by this reverse iterator
			*/
			Utf16CharReference operator*();

			/*!
			\brief Gets a pointer to the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			\return A pointer to the character being pointed to by this iterator
			*/
			Utf16CharReference* operator->();
		};

		/*!
		\brief An iterator that iterates through the code points in a UTF-16 string in reverse order,
			but allowing only access to constant code points

		This iterator assumes that the UTF-16 string being iterated over is a valid UTF-16 string.
		*/
		class UTFSTRING_DLLEXPORT const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, Utf16Char>
		{
			friend class Utf16String::const_iterator;

		private:
			const std::basic_string<UInt16>& codeUnitString;
			std::basic_string<UInt16>::const_reverse_iterator codeUnitPosition;
			Utf16Char* currentCharacter;

		public:
			/*!
			\brief Constructs a reverse iterator for Utf16String using the base class iterator

			This function assumes that basicStringIterator is a valid reverse iterator

			@param[in]	basicString	A reference to the string that basicStringIterator points to
			@param[in]	basicStringIterator	The base class reverse iterator to use in
				constructing this iterator
			*/
			const_reverse_iterator(const std::basic_string<UInt16>& basicString,
				const std::basic_string<UInt16>::const_reverse_iterator& basicStringIterator);

			/*!
			\brief Constructs a constant reverse iterator for Utf16String using a non-constant reverse iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other reverse iterator to use in constructing
				this reverse iterator
			*/
			const_reverse_iterator(const Utf16String::reverse_iterator& otherIterator);

			/*!
			\brief Constructs a reverse iterator for Utf16String using another iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other reverse iterator to use in constructing
				this reverse iterator
			*/
			const_reverse_iterator(const Utf16String::const_reverse_iterator& otherIterator);

			/*!
			\brief Constructs a constant reverse iterator for Utf16String using a constant iterator

			This constant reverse iterator will take on the same position as the constant iterator.

			@param[in]	iterator	The constant iterator to use in constructing this constant
				reverse iterator
			*/
			const_reverse_iterator(const Utf16String::const_iterator& iterator);

			/*!
			\brief Assigns the value of another reverse iterator to this reverse iterator

			This reverse iterator will take on the same characteristics and position as the
			other reverse iterator

			@param[in]	otherIterator	The other reverse iterator to be assigned to this
				reverse iterator

			\return A reference to this object after the assignment has been completed
			*/
			const_reverse_iterator& operator=(const const_reverse_iterator& otherIterator);

			/*!
			\brief Cleans up before the iterator is destroyed
			*/
			~const_reverse_iterator();

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for equality

			@param[in]	otherIterator	The other reverse iterator to be compared with this
				reverse iterator

			\return true if otherIterator is pointing to the same position as this reverse
				iterator, otherwise false
			*/
			bool operator==(const const_reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for inequality

			@param[in]	otherIterator	The other reverse iterator to be compared with
				this reverse iterator

			\return false if otherIterator is pointing to the same position as this reverse
				iterator, otherwise true
			*/
			bool operator!=(const const_reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const const_reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const const_reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const const_reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const const_reverse_iterator& otherIterator);

			/*!
			\brief Increments this reverse iterator to the previous position in the Utf16String

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			const_reverse_iterator& operator++();

			/*!
			\brief Increments this reverse iterator to the previous position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			const_reverse_iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			const_reverse_iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			const_reverse_iterator operator+(size_t offset);

			/*!
			\brief Decrements this reverse iterator to the next position in the Utf16String

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			const_reverse_iterator& operator--();

			/*!
			\brief Decrements this reverse iterator to the next position in the Utf16String

			This is a postfix operator.

			\return A copy of this object before the position was decremented
			*/
			const_reverse_iterator operator--(int);

			/*!
			\brief Decrements this iterator by a specific offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return A reference to this iterator
			*/
			const_reverse_iterator& operator-=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator decremented by a specific
				offset

			Note that since a UTF-16 string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing this iterator

			\return An iterator that points to the offset position
			*/
			const_reverse_iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			\return A reference to the the character being pointed to by this reverse iterator
			*/
			const Utf16Char operator*();

			/*!
			\brief Gets a pointer to the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a Utf16String, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			\return A pointer to the character being pointed to by this iterator
			*/
			const Utf16Char* operator->();
		};



		/*Member Functions*/

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf16String	A string of 16-bit code units to be appended

		\return	A reference to this string
		*/
		Utf16String& append(const Utf16String& utf16String);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf16String	A string of 16-bit code units to be appended.
			The string is assumed to be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& append(const std::basic_string<UInt16>& utf16String);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf16String	A string of 16-bit code units to be appended. The string is
			assumed to be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& append(const UInt16* utf16String);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf16String	A string of 16-bit code units to be appended. The string is
			assumed to be a valid UTF-16 string.
		@param[in]	codeUnitCount The number of code units in utf16String to be appended

		\return	A reference to this string
		*/
		Utf16String& append(const UInt16* utf16String, const size_t codeUnitCount);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	wideString A string of wchar_t to be appended. The string is assumed
			to be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& append(const wchar_t* wideString);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	wideString A string of wchar_t to be appended. The string is assumed
			to be a valid UTF-16 string.
		@param[in]	characterCount The number of characters in wideString to be appended

		\return	A reference to this string
		*/
		Utf16String& append(const wchar_t* wideString, const size_t characterCount);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	wideString	A string wchar_t to be appended. The string is assumed to
			be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& append(const std::wstring& wideString);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		Utf16String& append(const Utf8String& utf8String);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		Utf16String& append(const std::string& utf8String);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		Utf16String& append(const char* utf8String);

		/*!
		\brief Appends a UTF-16 character to this string

		@param[in]	utf16Character	A UTF-16 character to be appended. The character is assumed
			to be a valid UTF-16 character

		\return	A reference to this string
		*/
		Utf16String& append(const Utf16Char& utf16Character);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be a
			valid UTF-8 string.
		@param[in]	characterCount The number of characters in utfS8String to be appended

		\return	A reference to this string
		*/
		Utf16String& append(const char* utf8String, const size_t characterCount);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf16String	A string of 16-bit code units to be assigned

		\return	A reference to this string
		*/
		Utf16String& assign(const Utf16String& utf16String);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf16String	A string of 16-bit code units to be assigned.
			The string is assumed to be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& assign(const std::basic_string<UInt16>& utf16String);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf16String	A string of 16-bit code units to be assigned. The string is
			assumed to be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& assign(const UInt16* utf16String);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf16String	A string of 16-bit code units to be assigned. The string is
			assumed to be a valid UTF-16 string.
		@param[in]	codeUnitCount The number of code units in utf16String to be assigned

		\return	A reference to this string
		*/
		Utf16String& assign(const UInt16* utf16String, const size_t codeUnitCount);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	wideString A string of wchar_t to be assigned. The string is assumed
			to be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& assign(const wchar_t* wideString);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	wideString A string of wchar_t to be assigned. The string is assumed
			to be a valid UTF-16 string.
		@param[in]	characterCount The number of characters in wideString to be assigned

		\return	A reference to this string
		*/
		Utf16String& assign(const wchar_t* wideString, const size_t characterCount);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	wideString	A string of wchar_t to be assigned. The string is assumed to
			be a valid UTF-16 string.

		\return	A reference to this string
		*/
		Utf16String& assign(const std::wstring& wideString);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf8String A UTF-8 string to be assigned. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		Utf16String& assign(const Utf8String& utf8String);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf8String A UTF-8 string to be assigned. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		Utf16String& assign(const std::string& utf8String);

		/*!
		\brief Assigns the contents of another string to this string

		@param[in]	utf8String A UTF-8 string to be assigned. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		Utf16String& assign(const char* utf8String);

		/*!
		\brief Assigns the contents of another string to this string

		@param[in]	utf8String A UTF-8 string to be assigned. The string is assumed to be a
			valid UTF-8 string.
		@param[in]	characterCount The number of characters in utfS8String to be assigned

		\return	A reference to this string
		*/
		Utf16String& assign(const char* utf8String, const size_t characterCount);

		/*!
		\brief Assigns a UTF-16 character to this string

		@param[in]	utf16Character	A UTF-16 character to be assigned. The character is assumed
			to be a valid UTF-16 character

		\return	A reference to this string
		*/
		Utf16String& assign(const Utf16Char& utf16Character);

		/*!
		\brief Returns a reference to the character found at the specified character index

		This operator does for the validity of the index, and throws an out_of_range exception when
		the given index doesn't correspond to a character within a string.  Note that operator[] is
		a faster way to access a specific character, but doesn't check for index validity.

		Note that unlike standard ASCII or UCS-2, which are fixed-length encodings, UTF-16 is a variable length encoding.
		This means that whereas accessing a character at a particular index is O(1) for fixed-length encodings,
		accessing a character in UTF-16 strings is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index of a character in the string

		\return The character found at the specified index
		*/
		Utf16CharReference at(size_t index);

		/*!
		\brief Returns a reference to the character found at the specified character index

		This operator does for the validity of the index, and throws an out_of_range exception when
		the given index doesn't correspond to a character within a string.  Note that operator[] is
		a faster way to access a specific character, but doesn't check for index validity.

		Note that unlike standard ASCII or UCS-2, which are fixed-length encodings, UTF-16 is a variable length encoding.
		This means that whereas accessing a character at a particular index is O(1) for fixed-length encodings,
		accessing a character in UTF-16 strings is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index of a character in the string

		\return The character found at the specified index
		*/
		const Utf16Char at(size_t index) const;

		/*!
		\brief Returns an iterator pointing to the first character of a string

		\return A bidirectional iterator pointing to the first character in a string or just beyond
			the end of an empty string
		*/
		iterator begin();

		/*!
		\brief Returns a constant iterator pointing to the first character of a string

		\return A bidirectional constant iterator pointing to the first character in a string or just
			beyond the end of an empty string
		*/
		const_iterator begin() const;

		/*!
		\brief Returns c-style version of this string as an array of 16-bit code units

		The c-style array is owned by this object, and the pointer returned by this function is
		invalidated if any non-const functions are called on this object.

		\return A pointer to a null-terminated array of 16-bit code units
		*/
		const UInt16* c_str() const;

		/*!
		\brief Returns the largest number of code units that can be stored in this string
			without increasing the memory allocation of this string

		When characters are added to the string and there is no more memory available to the
		string, the string allocates a chunk of memory.  Memory is allocated in chunks significantly
		larger than necessary, so that performance doesn't suffer from lots of memory-allocation
		operations when many characters are added. The capicity indicates how many code units
		the string currently has memory for.  When size() == capacity(), adding any more characters
		will cause the string to allocate more memory.  Note that in all cases, size() <= capacity().

		\return The number of code units this string can hold before needing to allocation more
			memory
		*/
		size_t capacity() const;

		/*!
		\brief Clears out the string, leaving it an empty string
		*/
		void clear();

		/*!
		\brief Converts the index of a code point to the index of that code point's first code unit

		The code point index is the index used in this string to identify a particular code point.
		The code unit index is the index used in the underlying code unit string to identify a
		particular code unit.

		This function assumes is_valid() is true

		@param[in]	codePointIndex	The index of the code point whose code units are to be found

		\return The index of the first code unit of the code point
		*/
		size_t code_unit_index(const size_t codePointIndex);

		/*!
		\brief Converts the index of a code unit to the index of the corresponding code point

		The code point index is the index used in this string to identify a particular code point.
		The code unit index is the index used in the underlying code unit string to identify a
		particular code unit.

		It does not matter whether the code unit index is the first code unit in the code point or
		not.  As long as the string is valid, this function will be able to find the corresponding
		code point for any code unit.

		This function assumes is_valid() is true

		@param[in]	codeUnitIndex	The index of the code unit whose corresponding code point
			is to be found

		\return The index of the corresponding code point
		*/
		size_t code_point_index(const size_t codeUnitIndex);

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf16String	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const Utf16String& utf16String) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf16String	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const std::basic_string<UInt16>& utf16String) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf16String	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const UInt16* utf16String) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf16String	A string to be compared to this string
		@param[in]	codeUnitCount	The number of code units in the string to be
			compared

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const UInt16* utf16String, const size_t codeUnitCount) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	wideString	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const wchar_t* wideString) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	wideString	A string to be compared to this string
		@param[in]	codeUnitCount	The maximum number of code units in the string to be
			compared

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const wchar_t* wideString, const size_t codeUnitCount) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	wideString	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const std::wstring& wideString) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf8String	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const Utf8String& utf8String) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf8String	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const std::string& utf8String) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf8String	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const char* utf8String) const;

		/*!
		\brief Compares the code points in this string with a code points in another string
			to determine if both are equal or if one is less than the other

		If this string is the same as the parameter string, then the two strings are considered
		equal. If the strings are different, then one is considered to be less than the other.
		The strings are compared "alphabetically", and placed in "alphabetical" order.  The string
		that comes before the other string in that order is considered to be less than higher-ordered
		other string.

		Note that "alphabetical" order is used in quotations because it isn't truly alphabetical.
		Different languages have different symbols and may have complex rules for the ordering of
		characters.  This class does not attempt to address those issues, but instead compares
		code points based on their Unicode value.  So any particular Latin code point will be
		considered to be less than any particular Cyrillic code point, because the Cyrillic code
		points have higher Unicode values.  Within the English language, the code points are
		numbered so that they will be compared according to the rules of the language. This may
		or may not be the case for code points used by other languages.

		If language- or locale-specific comparison is necessary, it would be better to use
		the <a href="http://www.icu-project.org/">ICU</a> library.

		@param[in]	utf8String	A string to be compared to this string
		@param[in]	codeUnitCount	The maximum number of code units in the string to be
			compared

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const char* utf8String, const size_t codeUnitCount) const;

		/*!
		\brief Copies at most a specific number of code points in this string into an array of
			code units

		Although the array being copied to is an array of code units, the parameters that indicate
		which code points are to be copied in this string are the indexes of code points, not of
		code units.  This string is intended to abstract the individual code units.

		So if we copy three code points into the code unit array, as few as three or as many as
		six 16-bit code units will be copied to the code unit array, depending on how many code
		units comprise the three code points.

		If the number of code points to be copied is such so that there isn't enough room in the
		code unit array for the corresponding code units, the maximum possible number of code
		points will be copied without going over the boundaries of the array.

		Note that this function does not append a null terminator at the end of the array being
		copied to.

		This function assumes that codeUnitArray points to a valid array and that
		characterOffset < length().

		@param[in]	codeUnitArray	An array of 16-bit code units that will contain the copied
			code points
		@param[in]	codeUnitArraySize	The size of the code unit array to be copied to
		@param[in]	characterCount	The maximum number of code points to be copied to the code unit array
		@param[in]	characterOffset	The code point offset in this string where the copying to to begin

		\return The number of code units that were actually copied
		*/
		size_t copy(UInt16* codeUnitArray, const size_t codeUnitArraySize, const size_t characterCount,
			const size_t characterOffset = 0) const;

		/*!
		\brief Returns a pointer an array of 16-bit code units containing the contents of this string

		This array is owned by this object, and the pointer returned by this function is
		invalidated if any non-const functions are called on this object.

		This function is almost the same as the c_str() function: the only difference is that
		the array being returned by this function does not have a null terminator.

		\return A pointer to an array of 16-bit code units
		*/
		const UInt16* data() const;

		/*!
		\brief Indicates whether this string is empty

		If it should be the case that there are code units in the string but no valid code points,
		the string will be considered non-empty, and false will be returned.

		\return true if there are no characters in this string, otherwise false
		*/
		bool empty() const;

		/*!
		\brief Returns an iterator pointing to the location succeeding the last character in a string

		The iterator returned by this function is usually used to test whether an iterator has reached
		the end of a string.  The iterator returned by this function should never be dereferenced, as
		it doesn't not point to a part of the string.

		\return A bidirectional iterator pointing to the location succeeding the last character in a string
		*/
		iterator end();

		/*!
		\brief Returns an constant iterator pointing to the location succeeding the last character in a string

		The iterator returned by this function is usually used to test whether an iterator has reached
		the end of a string.  The iterator returned by this function should never be dereferenced, as
		it doesn't not point to a part of the string.

		\return A bidirectional constant iterator pointing to the location succeeding the last character in a string
		*/
		const_iterator end() const;

		/*!
		\brief Removes a range of characters from this string

		@param[in]	firstPosition	An iterator pointing to the first character of the range to be removed
		@param[in]	lastPosition	An iterator pointing to the position one past the last character
			of the range to be removed

		\return An iterator pointing to the first character after the range of characters that were removed
		*/
		Utf16String::iterator erase(const Utf16String::iterator& firstPosition,
			const Utf16String::iterator& lastPosition);

		/*!
		\brief Removes a character from this string

		@param[in]	position	An iterator pointing to the character to be removed

		\return An iterator pointing to the first character after character that was removed
		*/
		Utf16String::iterator erase(const Utf16String::iterator& position);

		/*!
		\brief Removes a range of characters from this string

		This function will only cause characters to be removed up to the end of the string, so an overly
		large count parameter value will not cause problems.

		This function assumes that offset <= length().

		@param[in]	offset	The offset describing the index location of the first character to be removed
		@param[in]	count	The maximum number of characters to be removed

		\return A reference to this string after the specified range of characters have been removed
		*/
		Utf16String& erase(const size_t offset = 0, const size_t count = npos);

		/*!
		\brief Searches this string for specific substring

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t find(const Utf16String& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for the first character that is not found in a given string

		Note that if searchString is not a valid UTF-16 string, this function will still work,
		but the result may turn up an unexpected code point.  For example, if the search string
		contains only the second code unit of a two-code-unit code point, that code point in the
		string being searched may still be the character identified by the search result, because
		even though the second code unit was in the search string, the first code unit of that code
		point was not.  This is because there are numerous code points that could have that second
		code unit, and there is no way to distinguish between them if we are only given one
		code unit.

		@param[in]	searchString	The string containing the characters that are to be excluded in
			the search.
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index of the first character in this string that is not a character in searchString,
			or npos if no such character was found
		*/
		size_t find_first_not_of(const Utf16String& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for the first character that is found in a given string

		This function differes from find() in that find() searches for the exact occurrance of the
		search string whereas this function searches for any one of the characters found in the
		search string.

		This function assumes is_valid() is true and searchString.is_valid() is true.

		@param[in] searchString	The string containing the characters that are to be searched for
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index of the first character in this string that is also in searchString,
			or npos if no such character was found
		*/
		size_t find_first_of(const Utf16String& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for the last character that is not found in a given string

		Note that if searchString is not a valid UTF-16 string, this function will still work,
		but the result may turn up an unexpected code point.  For example, if the search string
		contains only the second code unit of a two-code-unit code point, that code point in the
		string being searched may still be the character identified by the search result, because
		even though the second code unit was in the search string, the first code unit of that code
		point was not.  This is because there are numerous code points that could have that second
		code unit, and there is no way to distinguish between them if we are only given one
		code unit.

		Please note that the offset in this function controls the index where the search <i>ends</i>,
		and	not where it begins.

		@param[in]	searchString	The string containing the characters that are to be excluded in
			the search.
		@param[in]	offset	The index of the string at which the search is to finish

		\return The index of the last character in this string that is not a character in searchString,
			or npos if no such character was found
		*/
		size_t find_last_not_of(const Utf16String& searchString, size_t offset = npos);

		/*!
		\brief Searches this string for the last character that is found in a given string

		This function differes from find() in that find() searches for the exact occurrance of the
		search string whereas this function searches for any one of the characters found in the
		search string.

		Please note that the offset in this function controls the index where the search <i>ends</i>,
		and	not where it begins.

		This function assumes is_valid() is true and searchString.is_valid() is true.

		@param[in] searchString	The string containing the characters that are to be searched for
		@param[in]	offset	The index of the string at which the search is to finish

		\return The index of the last character in this string that is also in searchString,
			or npos if no such character was found
		*/
		size_t find_last_of(const Utf16String& searchString, size_t offset = npos);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf16String	A string of 16-bit code units to be appended

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const Utf16String& utf16String);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf16String	A string of 16-bit code units to be appended.
			The string is assumed to be a valid UTF-16 string.

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const std::basic_string<UInt16>& utf16String);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf16String	A string of 16-bit code units to be appended. The string is
			assumed to be a valid UTF-16 string.

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const UInt16* utf16String);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf16String	A string of 16-bit code units to be appended. The string is
			assumed to be a valid UTF-16 string.
		@param[in]	codeUnitCount The number of code units in utf16String to be appended

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const UInt16* utf16String, const size_t codeUnitCount);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	wideString A string of wchar_t to be appended. The string is assumed
			to be a valid UTF-16 string.

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const wchar_t* wideString);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	wideString A string of wchar_t to be appended. The string is assumed
			to be a valid UTF-16 string.
		@param[in]	codeUnitCount The number of code units in wideString to be appended

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const wchar_t* wideString, const size_t codeUnitCount);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	wideString	A string wchar_t to be appended. The string is assumed to
			be a valid UTF-16 string.

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const std::wstring& wideString);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be
			a valid UTF-8 string.

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const Utf8String& utf8String);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be
			a valid UTF-8 string.

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const std::string& utf8String);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be
			a valid UTF-8 string.

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const char* utf8String);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be a
			valid UTF-8 string.
		@param[in]	codeUnitCount The number of code units in utf8String to be appended

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const char* utf8String, const size_t codeUnitCount);

		/*!
		\brief Inserts a character into this string at a specified index

		@param[in]	index	The index in this string where the character is to be inserted
		@param[in]	utf16Character	A UTF-16 character to be appended. The character is assumed
			to be a valid UTF-16 character

		Note that the character can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes utf16Character is a valid character and that index <= length().

		\return	A reference to this string
		*/
		Utf16String& insert(const size_t index, const Utf16Char& utf16Character);

		/*!
		\brief Indicates whether the code units in this string comprise a valid UTF-16 string

		\return true if this string is a valid UTF-16 string, otherwise false
		*/
		bool is_valid() const;

		/*!
		\brief Returns the number of code points in this string

		Use this function if you're interested in how many characters are in a string. If you're interested
		in the number of code units (which may be different if any code points consist of multiple
		code units), then use the size() function.

		This function does not check for validity, so it may return an incorrect result if the code units
		comprising this string do not form a valid UTF-16 string.

		This function has a O(N) performance, since we need to iterate through the code units to figure
		out how many code points there are.  Counting each code point is an extremely quick operation, but
		due to the need to visit every code point in the string, it would be wise to be mindful of performance
		when making heavy use of this function on long strings in performance-sensitive code.

		\return The number of code points in this string
		*/
		size_t length() const;

		/*!
		\brief Appends a character to the end of this string

		This function is the equivalent of calling insert(length(), character) or append(character).

		@param[in]	character	The character to be appended to the end of this string
		*/
		void push_back(const Utf16Char& character);

		/*!
		\brief Returns an iterator pointing to the first character of a reversed string, which corresponds
			to the last character of the normal string

		\return A bidirectional iterator pointing to the first character in a reversed string or just beyond
			the end of an empty reversed string
		*/
		reverse_iterator rbegin();

		/*!
		\brief Returns a constant iterator pointing to the first character of a reversed string, which
			corresponds to the last character of a normal string

		\return A bidirectional constant iterator pointing to the first character in a reversed string or just
			beyond the end of an empty reversed string
		*/
		const_reverse_iterator rbegin() const;

		/*!
		\brief Returns an iterator pointing to the location succeeding the last character in a reversed string,
			 which corresponds to the location preceding the first character in a normal string

		The iterator returned by this function is usually used to test whether an iterator has reached
		the end of a string.  The iterator returned by this function should never be dereferenced, as
		it doesn't not point to a part of the string.

		\return A bidirectional iterator pointing to the location succeeding the last character in a
			reversed string
		*/
		reverse_iterator rend();

		/*!
		\brief Returns an constant iterator pointing to the location succeeding the last character in
			a reversed string, which corresponds to the location preceding the first character in a
			normal string

		The iterator returned by this function is usually used to test whether an iterator has reached
		the end of a string.  The iterator returned by this function should never be dereferenced, as
		it doesn't not point to a part of the string.

		\return A bidirectional constant iterator pointing to the location succeeding the last character
			in a reversed string
		*/
		const_reverse_iterator rend() const;

		/*!
		\brief Removes a section of this string and replaces it with the contents of another string

		Note that if position is one index past the end of the string, replacementString will simply
		be appended to the end of the string.

		This function assumes position <= length().

		@param[in]	position	The index in the string identifying the beginning of the string section
			to be removed
		@param[in]	count		The maximum number of characters to be removed from this string
		@param[in]	replacementString	The string whose contents are to replace the section being removed

		\return A reference to this string after the replacement has been completed
		*/
		Utf16String& replace(const size_t position, const size_t count, const Utf16String& replacementString);

		/*!
		\brief Replaces the characters in a section of this string with the given character

		This function assumes position <= length().

		@param[in]	position	The index in the string identifying the first character to be replaced
		@param[in]	count		The maximum number of characters to be replaced
		@param[in]	characterCount	The number of times the character is to be repeated in the replaced section
		@param[in]	character	The character to replace the characters in the identified section of this
			string

		\return A reference to this string after the replacement has been completed
		*/
		Utf16String& replace(const size_t position, const size_t count, const size_t characterCount,
			const Utf16Char& character);

		/*!
		\brief Removes a section of this string and replaces it with the contents of another string

		This function replaces the section of the string from beginIterator to endIterator - 1, where
		endIterator is pointing at a position one past the end of the section to be replaced.

		If endIterator points to a position before beginIterator, endIterator is ignored and the entire
		string from beginIterator to the end of the string is replaced.  If beginIterator points to the
		same position as endIterator, replacementString is simply inserted at that position and nothing
		in this string is removed.

		@param[in]	beginIterator	An iterator pointing to the first character of the string section
			to be replaced
		@param[in]	endIterator		An iterator pointing to the position one past the last character
			of the string section to be replaced
		@param[in]	replacementString	The string whose contents are to replace the section being removed

		\return A reference to this string after the replacement has been completed
		*/
		Utf16String& replace(Utf16String::iterator beginIterator, Utf16String::iterator endIterator,
			const Utf16String& replacementString);

		/*!
		\brief Replaces the characters in a section of this string with the given character

		This function replaces the section of the string from beginIterator to endIterator - 1, where
		endIterator is pointing at a position one past the end of the section to be replaced.

		If endIterator points to a position before beginIterator, endIterator is ignored and the entire
		string from beginIterator to the end of the string is replaced.  If beginIterator points to the
		same position as endIterator, the new characters are simply inserted at that position and nothing
		in this string is removed.

		@param[in]	beginIterator	An iterator pointing to the first character of the string section
			to be replaced
		@param[in]	endIterator		An iterator pointing to the position one past the last character
			of the string section to be replaced
		@param[in]	characterCount	The number of times the character is to be repeated in the replaced section
		@param[in]	character	The character to replace the characters in the identified section of this
			string

		\return A reference to this string after the replacement has been completed
		*/
		Utf16String& replace(Utf16String::iterator beginIterator, Utf16String::iterator endIterator,
			const size_t characterCount, const Utf16Char& character);

		/*!
		\brief Searches this string backward for specific substring

		Note this does not look at the characters in reverse order like iterating through a string with a
		reverse iterator.  It looks at the characters in forward order just like the find() function,
		but starts at the end of the string and works backward toward the beginning.

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t rfind(const Utf16String& searchString, size_t offset = npos);

		/*!
		\brief Returns the number of code units in this string

		If you are interested in how many characters are in this string, use the length() function instead.

		Most likely this function has a O(1) performance, since it is a simple count of the number of
		elements a string. However, this depends on the implementation of the underlying
		STL basic_string<>::size() function.

		\return The number of code units in this string
		*/
		size_t size() const;

		/*!
		\brief Returns a substring of this string

		The offset parameter indicates which character in the string will become the first character of
		the substring and the count parameter indicates how many characters will be copied into the substring.
		If the value of count would cause characters beyond the end of this string to be copied, only characters
		from the offset to the end of the string will be copied.

		This function assumes that offset < length().

		@param[in]	offset	The string offset indicating the first character of the substring
		@param[in]	count	The number of characters to be copied into the substring

		\return A substring as describe by the parameters
		*/
		Utf16String substr(const size_t offset = 0, const size_t count = npos);

		/*!
		\brief Swaps the contents of this string with those of another string

		@param[in]	utf16String	The string whose contents are to be swapped with the contents this string
		*/
		void swap(Utf16String& utf16String);

		/*Operators*/

		/*!
		\brief Returns the character found at the specified character index

		This operator does not check for the validity of the index, so it assumes that index is valid.
		What happens when the index is invalid is undefined. If you want the index parameter to be validated,
		use the at() function instead.

		Note that unlike standard ASCII or UCS-2, which are fixed-length encodings, UTF-16 is a variable length encoding.
		This means that whereas accessing a character at a particular index is O(1) for fixed-length encodings,
		accessing a character in UTF-16 strings is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index identifying the character to be retrieved

		\return The character found at the specified index
		*/
		Utf16CharReference operator[](const size_t index);

		/*!
		\brief Returns the character found at the specified character index

		This operator does not check for the validity of the index, so it assumes that index is valid.
		What happens when the index is invalid is undefined. If you want the index parameter to be validated,
		use the at() function instead.

		Note that unlike standard ASCII or UCS-2, which are fixed-length encodings, UTF-16 is a variable length encoding.
		This means that whereas accessing a character at a particular index is O(1) for fixed-length encodings,
		accessing a character in UTF-16 strings is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index identifying the character to be retrieved

		\return The character found at the specified index
		*/
		const Utf16Char operator[](const size_t index) const;

		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the two strings are the same

		@param[in]	otherString	The string to be compared with this string

		\return true if the two strings are the same, otherwise false
		*/
		bool operator==(const Utf16String& otherString) const;

		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the two strings are the different

		@param[in]	otherString	The string to be compared with this string

		\return true if the two strings are different, otherwise false
		*/
		bool operator!=(const Utf16String& otherString) const;
	
		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the value of this string is less than the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	otherString	The string to be compared with this string

		\return true if the the value of this string is less than the value
			of the other string, otherwise false
		*/
		bool operator<(const Utf16String& otherString) const;

		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the value of this string is less than or equal to the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	otherString	The string to be compared with this string

		\return true if the the value of this string is less than or equal to the value
			of the other string, otherwise false
		*/
		bool operator<=(const Utf16String& otherString) const;

		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the value of this string is greater than the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	otherString	The string to be compared with this string

		\return true if the the value of this string is greater than the value
			of the other string, otherwise false
		*/
		bool operator>(const Utf16String& otherString) const;

		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the value of this string is greater than or equal to the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	otherString	The string to be compared with this string

		\return true if the the value of this string is greater than or equal to the value
			of the other string, otherwise false
		*/
		bool operator>=(const Utf16String& otherString) const;

		/*!
		\brief Converts this object to a basic_string<UInt16> const instance
		*/
		operator const std::basic_string<UInt16>() const;

		/*!
		\brief Converts this object to a basic_string<UInt16> instance
		*/
		operator std::basic_string<UInt16>();

		/*!
		\brief This operator converts a stream of 16-bit values to a UTF-16 string

		This function clears the contents of utf16String before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled.

		@param[in]	inputStream	The input stream containing 16-bit values to be converted
			to a UTF-16 string
		@param[in]	utf16String	The string object into which the converted UTF-16 string
			will be stored
		*/
		friend std::istream& operator >>(std::istream& inputStream, Utf16String& utf16String)
		{
			utf16String.clear();

			UInt16 utf16CodeUnit;

			if(!inputStream.eof())
			{
				inputStream.read((char*)&utf16CodeUnit, sizeof(UInt16));

				//Read in 16-bit values until we find whitespace. Note that we don't have to worry
				//about characters with two code units here, because due to how surrogate pairs are
				//constructed in UTF-16, they will never be mistaken for whitespace.
				while(!IsWhitespace(utf16CodeUnit) && !inputStream.eof())
				{
					utf16String.append(&utf16CodeUnit, 1);
					inputStream.read((char*)&utf16CodeUnit, sizeof(UInt16));
				}

				//Eat up any remaining whitespace
				while(IsWhitespace(utf16CodeUnit) && !inputStream.eof())
				{
					inputStream.read((char*)&utf16CodeUnit, sizeof(UInt16));
				}

				//If we read a non-whitespace character, and it's not the EOF marker, then
				//reverse the current stream position by 2 bytes so that we don't lose the character
				inputStream.seekg(-2, std::ios_base::cur);
			}

			return inputStream;
		}

		/*!
		\brief This operator converts a UTF-16 string to a stream of 16-bit values

		No checks for validity are done, so the resulting UTF-16 stream may or may not contain a valid
		UTF-16 string.

		@param[in]	outputStream	The output stream to which the contents of the UTF-16 string
			are to be written
		@param[in]	utf16String	The UTF-16 string to be written to the output stream
		*/
		friend std::ostream& operator <<(std::ostream& outputStream, const Utf16String& utf16String)
		{
			outputStream.write((char*)utf16String.c_str(), (std::streamsize)(utf16String.size() * 2));

			return outputStream;
		}

		/*!
		\brief This operator converts a wide stream of 16-bit values to a UTF-16 string

		This function clears the contents of utf16String before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled.

		@param[in]	inputStream	The wide input stream containing 16-bit values to be converted
			to a UTF-16 string
		@param[in]	utf16String	The string object into which the converted UTF-16 string
			will be stored
		*/
		friend std::wistream& operator >>(std::wistream& inputStream, Utf16String& utf16String)
		{
			utf16String.clear();

			wchar_t utf16CodeUnit = 0;

			if(!inputStream.eof())
			{
				inputStream.read(&utf16CodeUnit, 1);
			}

			//Read in 16-bit values until we find whitespace. Note that we don't have to worry
			//about characters with two code units here, because due to how surrogate pairs are
			//constructed in UTF-16, they will never be mistaken for whitespace.
			while(!IsWhitespace(utf16CodeUnit) && !inputStream.eof())
			{
				utf16String.append(&utf16CodeUnit, 1);
				inputStream.read(&utf16CodeUnit, 1);
			}

			//Eat up any remaining whitespace
			while(IsWhitespace(utf16CodeUnit) && !inputStream.eof())
			{
				inputStream.read(&utf16CodeUnit, 1);
			}

			//If we read a non-whitespace character, and it's not the EOF marker, then
			//reverse the current stream position by 2 bytes so that we don't lose the character
			inputStream.seekg(-1, std::ios_base::cur);

			return inputStream;
		}

		/*!
		\brief This operator converts a UTF-16 string to a wide stream of 16-bit values

		No checks for validity are done, so the resulting UTF-16 stream may or may not contain a valid
		UTF-16 string.

		@param[in]	outputStream	The wide output stream to which the contents of the UTF-16 string
			are to be written
		@param[in]	utf16String	The UTF-16 string to be written to the output stream
		*/
		friend std::wostream& operator <<(std::wostream& outputStream, const Utf16String& utf16String)
		{
		#ifdef WCHAR_T_16BIT
			outputStream.write((wchar_t*)utf16String.c_str(), (std::streamsize)utf16String.size());
		#else
			//We need to convert the UInt16 characters to wchar_t characters
			std::wstring wideString;
			std::basic_string<UInt16> basicString = utf16String;

			for(std::basic_string<UInt16>::iterator stringIterator = basicString.begin(); 
				stringIterator != basicString.end(); ++stringIterator)
			{
				wchar_t codeUnit = (wchar_t)(*stringIterator); 
				outputStream.write(&codeUnit, 1);
			}
		#endif

			return outputStream;
		}


		/*Static Functions*/

		/*!
		\brief Counts the number of code units in the character that the string iterator is pointing to

		If the iterator is pointing to the second code unit in a surrogate pair, a 0 is returned.

		@param[in]	stringIterator	An iterator pointing to a character on a string

		\return The number of code units in the character that the string iterator is pointing to,
			or 0 if the iterator is pointing to the second surrogate code unit
		*/
		static size_t CharacterCodeUnitCount(const std::wstring::const_iterator& stringIterator);

		/*!
		\brief Counts the number of code units in the character that the string iterator is pointing to

		If the iterator is pointing to the second code unit in a surrogate pair, a 0 is returned.

		@param[in]	stringIterator	An iterator pointing to a character on a string

		\return The number of code units in the character that the string iterator is pointing to,
			or 0 if the iterator is pointing to the second surrogate code unit
		*/
		static size_t CharacterCodeUnitCount(Utf16String::const_iterator& stringIterator);

		/*!
		\brief Counts the number of code units in the character that the string iterator is pointing to

		If the iterator is pointing to the second code unit in a surrogate pair, a 0 is returned.

		@param[in]	stringIterator	An iterator pointing to a character on a string

		\return The number of code units in the character that the string iterator is pointing to,
			or 0 if the iterator is pointing to the second surrogate code unit
		*/
		static size_t CharacterCodeUnitCount(const std::basic_string<UInt16>::const_iterator& stringIterator);

		/*!
		\brief Counts the number of code units in the character that the string reverse iterator is pointing to

		If the reverse iterator is pointing to the first code unit in a surrogate pair, a 0 is returned.

		Note that since this function deals with a reverse iterator, it is expecting the code units to
		be in the reverse order, meaning that the second surrogate code unit is expected to come before
		the first surrogate code unit.  So when passing an iterator pointing to a two-code-unit character,
		make sure that the iterator is pointing at the very last code unit, and not the first as expected
		by the overload that accepts a forward iterator.

		@param[in]	stringIterator	A reverse iterator pointing to a character in a string

		\return The number of code units in the character that the string reverse iterator is pointing to,
			or 0 if the reverse iterator is pointing to the first surrogate code unit
		*/
		static size_t CharacterCodeUnitCount(const std::basic_string<UInt16>::const_reverse_iterator& stringIterator);

		/*!
		\brief Counts the number of code units in the character that a character pointer is pointing to

		If the iterator is pointing to the second code unit in a surrogate pair, a 0 is returned.

		@param[in]	characterPointer	A pointer pointing to the first code unit of a UTF-16 code point

		\return The number of code units in the character that the string iterator is pointing to,
			or 0 if the iterator is pointing to the second surrogate code unit
		*/
		static size_t CharacterCodeUnitCount(const UInt16* characterPointer);

		/*!
		\brief Decodes a UTF-16 character, returning the result as a 32-bit code point

		This function assumes that utf16Character contains a valid UTF-16 character.

		@param[in]	utf16Character	A series of code units representing a UTF-16 character

		\return A 32-bit code point
		*/
		static UInt32 DecodeCharacter(const Utf16Char& utf16Character);

		/*!
		\brief Decodes a UTF-16 character, returning the result as a 32-bit code point

		This function assumes that characterPointer points to a buffer containing a valid
		UTF-16 character.  The length of the buffer must be between 1 and 2.

		@param[in]	characterPointer A pointer to a buffer containing a series of UTF-16 code
			units representing a UTF-16 character
		@param[in]	codeUnitCount	The length of the buffer pointed to by characterPointer

		\return A 32-bit code point
		*/
		static UInt32 DecodeCharacter(const UInt16* characterPointer, const size_t codeUnitCount);

		/*!
		\brief Encodes a 32-bit code point as a UTF-16 character

		This function assumes that codePoint falls in the valid Unicode character range of 000000-10FFFF.

		@param[in]	codePoint	A 32-bit code point

		\return A UTF-16 character corresponding to the given code point
		*/
		static Utf16Char EncodeCharacter(const UInt32 codePoint);

		/*!
		\brief Indicates whether the code units in a UTF-16 character comprise a valid UTF-16 character

		A one-code-unit character is valid if it is outside the range D800-DFFF, outside the range
		FDD0-FDEF, and is not FFFE or FFFF.
		A two-code-unit character is valid if the first code unit is in the range D800-DBFF,
		and the second code unit is in the range DC00-DFFF, and the character is not one of the
		32 code points that are deemed to be non-characters.

		The 32 non-characters code points are 1FFF*, 2FFF*, ..., 10FFF*, where * is an E or an F.
		@param[in]	utf16Character	A Utf16Char object containing the code units to be validated

		\return true if the Utf16Char object represents a valid UTF-16 character, otherwise false
		*/
		static bool IsValidCharacter(const Utf16Char& utf16Character);

		/*!
		\brief Indicates whether a series of 16-bit code units is a valid UTF-16 character

		A one-code-unit character is valid if it is outside the range D800-DFFF, outside the range
		FDD0-FDEF, and is not FFFE or FFFF.
		A two-code-unit character is valid if the first code unit is in the range D800-DBFF,
		and the second code unit is in the range DC00-DFFF, and the character is not one of the
		32 code points that are deemed to be non-characters..

		The 32 non-character code points are 1FFF*, 2FFF*, ..., 10FFF*, where * is an E or an F.

		@param[in]	characterPointer	A pointer to the buffer containing the series of 16-bit code units
		@param[in]	codeUnitCount	The number of code units in the characterPointer buffer

		\return true if the series of code units represents a valid UTF-16 character, otherwise false
		*/
		static bool IsValidCharacter(const UInt16* characterPointer, const size_t codeUnitCount);

		/*!
		\brief Indicates whether a UTF-16 character is a whitespace character

		This function tests for the standard ASCII whitespace characters(tab, space, carriage return, line feed),
		and the characters that the Unicode standard defines as being separator characters.

		Note that all whitespace characters are single code-unit characters, and the code units that comprise
		multi-code-unit	UTF-16 characters are within their own range, so a single code unit of a multi-code-unit
		character will never be thought to be a whitespace character.  This makes it safe to pass in code
		units one at a time, no matter whether they are part of a multi-code-unit pair or not.

		@param[in]	utf16Character The character to be examined

		\return If utf16Character is a whitespace character, true, otherwise false
		*/
		static bool IsWhitespace(UInt16 utf16Character);

		/*!
		\brief Indicates whether a UTF-16 character is a whitespace character

		This function tests for the standard ASCII whitespace characters(tab, space, carriage return, line feed),
		and the characters that the Unicode standard defines as being separator characters.

		@param[in]	utf16Character The character to be examined

		\return If utf16Character is a whitespace character, true, otherwise false
		*/
		static bool IsWhitespace(const Utf16Char& utf16Character);

		/*Static Constants*/

		/*!
		\brief An unsigned integral value initialized to –1 that indicates either "not found" or
			"all remaining characters" when a search function fails.
		*/
		static const size_t npos;
	};
}

#endif
