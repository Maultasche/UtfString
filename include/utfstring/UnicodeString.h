/*!
\file UnicodeString.h

This file contains the functionality for managing Unicode strings in an encoding-neutral way
*/

#ifndef __UTFSTRING_UNICODESTRING_H__
#define __UTFSTRING_UNICODESTRING_H__

#include "UnicodeChar.h"
#include "UnicodeCharReference.h"

/*
TODO: References can be assigned using the = operator when they are first initialized, but assigning
a reference (as opposed to assigning the value of another reference) after that pount must be done
using assign_reference().  If an invalid reference (usually a reference to a string that has been
changed) is assigned to using the = operator, you will get a crash.

TODO: What happens when iterators from two different strings are compared using ==, !=, <, <=, >, >=?
When both are from the same string type (Utf8String)?  When they are from two different string types?

TODO: Insert section into documentation talking about how postfix operators for iterators take a little longer
and use more memory (because a copy of the iterator is made) than prefix operators.  If you have a choice,
it's always better to use the "+=" operator rather than the "+" operator and the "-=" operator rather than
the "-" operator, because the "+" and "-" operators create copies of an iterator, which has an effect on
memory and speed.

However, unless memory is scarce or speed is critical, you shouldn't need worry about these differences,
because it's a usually a very small difference on modern computers.  It may make a difference on a 
normal PC if you are doing millions of increments/decrements a second, but if you're not, don't worry 
too much about it.

TODO: UnicodeString is a wrapper class, and wraps UTF-8 or UTF-16 strings.  As a result, other string
types (char*, std::string, wchar_t*, etc.) have to be encapsulated in a Utf8String or Utf16String
object before they can be assigned to a UnicodeString or used in many of UnicodeString's member functions.

TODO: Dereferencing a UnicodeString iterator will get you a UnicodeCharReference, or a UnicodeChar if the
iterator is a constant iterator. Since UnicodeCharReference and UnicodeChar are encoding-neutral, you can 
only get the code point (UTF-32) value.  If you want to access the code units, you will have to cast the
UnicodeCharReference or UnicodeChar to a its encoding equivalent (Utf8Char, Utf16Char)

TODO: A UnicodeCharReference cannot be cast to a Utf8CharReference or Utf16CharReference because
*/

namespace UtfString
{
	/*!
	\brief Contains and manages an encoding-neutral Unicode string

	This class is intended to be used in situations when the encoding of a Unicode string
	is unknown at compile time.  UnicodeString encapsulates and encoding-specific string,
	and abstracts away code units, concentrating on code points instead.

	UnicodeString is less efficient than the encoding-specific string classes (Utf8String 
	and Utf16String), and due to the need to be encoding-neutral, contains less functionality
	than the encoding-specific strings.  If you won't know the exact encoding until runtime,
	use UnicodeString; otherwise, use Utf8String or Utf16String.

	A UnicodeString can always be converted to a Utf8String or Utf16String. So if a string
	is coming from a source with an unknown encoding, such as a file, use UnicodeString at
	first and then convert to a Utf8String or Utf16String for use in the rest of the 
	application.  UnicodeString is most useful in library APIs or any other widely-used code,
	so functions can return a UnicodeString object instead of implementing separate functions
	for each encoding.
	*/
	class UTFSTRING_DLLEXPORT UnicodeString
	{
	private:
		Utf8String* m_utf8String;
		Utf16String* m_utf16String;

	public:
		/*Constructors*/

		/*!
		\brief The default constructor
		*/
		UnicodeString();

		/*!
		\brief Initialized this string with another UnicodeString object

		@param[in]	unicodeString	The UnicodeString object to use to initialize this object
		*/
		UnicodeString(const UnicodeString& unicodeString);

		/*!
		\brief Initializes this string with a UTF-16 string

		@param[in]	utf16String	A UTF-16 string used to initialize this object
		*/
		UnicodeString(const Utf16String& utf16String);

		/*!
		\brief Initializes this string with a UTF-8 string

		@param[in]	utf8String	A UTF-8 string used to initialize this object
		*/
		UnicodeString(const Utf8String& utf8String);

        /*!
        \brief The class destructor
        */
        virtual ~UnicodeString();

		/*Iterators*/

		/*Forward Declarations*/
		class iterator;
		class const_iterator;
		class reverse_iterator;
		class const_reverse_iterator;

		/*!
		\brief An iterator that iterates through the code points in a Unicode string

		This iterator assumes that the Unicode string being iterated over is a valid Unicode string.

		There is also the concept of an "empty" iterator.  An empty iterator is one that is created
		when begin() or end() is called on an empty UnicodeString.  Attempting to change the position
		of an empty iterator using unary operator (such as "+=") will only result in nothing happening. 
		Attempting to get an iterator for another position using a binary operator (such as "+") will
		result in another empty iterator being created.  Dereferencing an iterator via the "*" or "->"
		operators will result in an assertion failure in a debug build or undefined behavior in a 
		release build.  Empty iterators are always equal to each other.
		*/
		class UTFSTRING_DLLEXPORT iterator : public std::iterator<std::random_access_iterator_tag, UnicodeChar>
		{
			friend class UnicodeString::const_iterator;
			friend class UnicodeString::reverse_iterator;
			friend class UnicodeString;

		private:
			Utf8String::iterator* m_utf8StringIterator;
			Utf16String::iterator* m_utf16StringIterator;
			UnicodeCharReference* m_currentUnicodeCharReference;

		public:
			/*!
			\brief Creates an empty iterator

			For a description of an empty iterator, see the class description

			\sa UnicodeString::iterator
			*/
			iterator();
			
			/*!
			\brief Constructs an iterator for UnicodeString using a Utf8String iterator

			This function assumes that utf8StringIterator is a valid iterator

			@param[in]	utf8StringIterator	The Utf8String iterator to use in constructing this
				iterator
			*/
			iterator(const Utf8String::iterator& utf8StringIterator);

			/*!
			\brief Constructs an iterator for UnicodeString using a Utf16String iterator

			This function assumes that utf16StringIterator is a valid iterator

			@param[in]	utf16StringIterator	The Utf16String iterator to use in constructing this
				iterator
			*/
			iterator(const Utf16String::iterator& utf16StringIterator);

			/*!
			\brief Constructs an iterator for UnicodeString using another iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to use in constructing this iterator
			*/
			iterator(const UnicodeString::iterator& otherIterator);

			/*!
			\brief Constructs an iterator for UnicodeString using a reverse iterator

			This iterator will take on the same position as the reverse iterator.

			@param[in]	reverseIterator	The reverse iterator to use in constructing this iterator
			*/
			iterator(const UnicodeString::reverse_iterator& reverseIterator);

			/*!
			\brief Cleans up before the iterator is destroyed
			*/
			~iterator();

			/*!
			\brief Indicates whether this iterator is an empty iterator

			This is mainly for informational purposes. If you use iterators properly, comparing
			the begin iterator to the end iterator, you won't even need to know when an 
			empty iterator appears. In case want to know whether an iterator is empty (as opposed
			to an non-empty iterator that has been incremented/decremented beyond the boundaries of 
			a string), you can use this function.
			*/
			bool empty() const;

			/*!
			\brief Assigns the value of another iterator to this iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to be assigned to this iterator

			\return A reference to this object after the assignment has been completed
			*/
			iterator& operator=(const UnicodeString::iterator& otherIterator);

			/*!
			\brief Compares this iterator with another iterator and tests for equality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if otherIterator is pointing to the same position as this iterator,
				otherwise false
			*/
			bool operator==(const iterator& otherIterator) const;

			/*!
			\brief Compares this iterator with another iterator and tests for inequality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return false if otherIterator is pointing to the same position as this iterator,
				otherwise true
			*/
			bool operator!=(const iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators. If the two iterators
			are pointing

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const iterator& otherIterator);

			/*!
			\brief Increments this iterator to the next position in the UnicodeString

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			iterator& operator++();

			/*!
			\brief Increments this iterator to the next position in the UnicodeString

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			iterator operator+(size_t offset);

			/*!
			\brief Decrements this iterator to the previous position in the UnicodeString

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			iterator& operator--();

			/*!
			\brief Decrements this iterator to the previous position in the UnicodeString

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

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return An iterator that points to the offset position
			*/
			iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this iterator

			If this iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::iterator::empty()

			\return A reference to the the character being pointed to by this iterator
			*/
			UnicodeCharReference operator*();

			/*!
			\brief Gets a pointer to the character at the position of this iterator

			If this iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::iterator::empty()

			\return A pointer to the character being pointed to by this iterator
			*/
			UnicodeCharReference* operator->();
		};

		/*!
		\brief An iterator that iterates through the code points in a Unicode string, but allowing
			only access to constant code points

		This iterator assumes that the Unicode string being iterated over is a valid Unicode string.

		There is also the concept of an "empty" iterator.  An empty iterator is one that is created
		when begin() or end() is called on an empty UnicodeString.  Attempting to change the position
		of an empty iterator using unary operator (such as "+=") will only result in nothing happening. 
		Attempting to get an iterator for another position using a binary operator (such as "+") will
		result in another empty iterator being created.  Dereferencing an iterator via the "*" or "->"
		operators will result in an assertion failure in a debug build or undefined behavior in a 
		release build.  Empty iterators are always equal to each other.
		*/
		class UTFSTRING_DLLEXPORT const_iterator : public std::iterator<std::random_access_iterator_tag, UnicodeChar>
		{
			friend class UnicodeString::const_reverse_iterator;

		private:
			Utf8String::const_iterator* m_utf8StringIterator;
			Utf16String::const_iterator* m_utf16StringIterator;
			UnicodeChar* m_currentUnicodeChar;

		public:
			/*!
			\brief Creates an empty constant iterator

			For a description of an empty iterator, see the class description

			\sa UnicodeString::const_iterator
			*/
			const_iterator();

			/*!
			\brief Constructs a constant iterator for UnicodeString using a Utf8String iterator

			This function assumes that utf8StringIterator is a valid iterator

			@param[in]	utf8StringIterator	The Utf8String iterator to use in constructing this
				iterator
			*/
			const_iterator(const Utf8String::const_iterator& utf8StringIterator);

			/*!
			\brief Constructs a constant iterator for UnicodeString using a Utf16String iterator

			This function assumes that utf16StringIterator is a valid iterator

			@param[in]	utf16StringIterator	The Utf16String iterator to use in constructing this
				iterator
			*/
			const_iterator(const Utf16String::const_iterator& utf16StringIterator);

			/*!
			\brief Constructs a constant iterator for UnicodeString using a non-constant iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to use in constructing this iterator
			*/
			const_iterator(UnicodeString::iterator& otherIterator);

			/*!
			\brief Constructs a constant iterator for UnicodeString using another constant iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to use in constructing this iterator
			*/
			const_iterator(const UnicodeString::const_iterator& otherIterator);

			/*!
			\brief Constructs a constant iterator for UnicodeString using a constant reverse iterator

			This constant iterator will take on the same position as the constant reverse iterator.

			@param[in]	reverseIterator	The constant reverse iterator to use in constructing this
				constant iterator
			*/
			const_iterator(const UnicodeString::const_reverse_iterator& reverseIterator);

			/*!
			\brief Cleans up before the iterator is destroyed
			*/
			~const_iterator();

			/*!
			\brief Indicates whether this iterator is an empty iterator

			This is mainly for informational purposes. If you use iterators properly, comparing
			the begin iterator to the end iterator, you won't even need to know when an 
			empty iterator appears. In case want to know whether an iterator is empty (as opposed
			to an non-empty iterator that has been incremented/decremented beyond the boundaries of 
			a string), you can use this function.
			*/
			bool empty() const;

			/*!
			\brief Assigns the value of another iterator to this iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other iterator to be assigned to this iterator

			\return A reference to this object after the assignment has been completed
			*/
			const_iterator& operator=(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator with another iterator and tests for equality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if otherIterator is pointing to the same position as this iterator,
				otherwise false
			*/
			bool operator==(const const_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator with another iterator and tests for inequality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return false if otherIterator is pointing to the same position as this iterator,
				otherwise true
			*/
			bool operator!=(const const_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const const_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const const_iterator& otherIterator);

			/*!
			\brief Increments this iterator to the next position in the UnicodeString

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			const_iterator& operator++();

			/*!
			\brief Increments this iterator to the next position in the UnicodeString

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			const_iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			const_iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			const_iterator operator+(size_t offset);

			/*!
			\brief Decrements this iterator to the previous position in the UnicodeString

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			const_iterator& operator--();

			/*!
			\brief Decrements this iterator to the previous position in the UnicodeString

			This is a postfix operator.

			\return A copy of this object before the position was decremented
			*/
			const_iterator operator--(int);

			/*!
			\brief Decrements this iterator by a specific offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing this iterator

			\return A reference to this iterator
			*/
			const_iterator& operator-=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator decremented by a specific
				offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return An iterator that points to the offset position
			*/
			const_iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this iterator

			If this iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::const_iterator::empty()

			\return A reference to the the character being pointed to by this iterator
			*/
			const UnicodeChar operator*();

			/*!
			\brief Gets a pointer to the character at the position of this iterator

			If this iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::const_iterator::empty()

			\return A pointer to the character being pointed to by this iterator
			*/
			const UnicodeChar* operator->();
		};

		/*!
		\brief An iterator that iterates through the code points in a Unicode string in reverse order

		This iterator assumes that the Unicode string being iterated over is a valid Unicode string.

		There is also the concept of an "empty" iterator.  An empty iterator is one that is created
		when begin() or end() is called on an empty UnicodeString.  Attempting to change the position
		of an empty iterator using unary operator (such as "+=") will only result in nothing happening. 
		Attempting to get an iterator for another position using a binary operator (such as "+") will
		result in another empty iterator being created.  Dereferencing an iterator via the "*" or "->"
		operators will result in an assertion failure in a debug build or undefined behavior in a 
		release build.  Empty iterators are always equal to each other.
		*/
		class UTFSTRING_DLLEXPORT reverse_iterator : public std::iterator<std::random_access_iterator_tag, UnicodeChar>
		{
			friend class UnicodeString::const_reverse_iterator;
			friend class UnicodeString::iterator;

		private:
			Utf8String::reverse_iterator* m_utf8StringIterator;
			Utf16String::reverse_iterator* m_utf16StringIterator;
			UnicodeCharReference* m_currentUnicodeCharReference;

		public:
			/*!
			\brief Creates an empty reverse iterator

			For a description of an empty iterator, see the class description

			\sa UnicodeString::reverse_iterator
			*/
			reverse_iterator();

			/*!
			\brief Constructs a reverse iterator for UnicodeString using a Utf8String reverse iterator

			This function assumes that utf8StringReverseIterator is a valid iterator

			@param[in]	utf8StringReverseIterator	The Utf8String reverse iterator to use in constructing this
				iterator
			*/
			reverse_iterator(const Utf8String::reverse_iterator& utf8StringReverseIterator);

			/*!
			\brief Constructs a reverse iterator for UnicodeString using a Utf16String reverse iterator

			This function assumes that utf16StringReverseIterator is a valid iterator

			@param[in]	utf16StringReverseIterator	The Utf16String reverse iterator to use in constructing this
				iterator
			*/
			reverse_iterator(const Utf16String::reverse_iterator& utf16StringReverseIterator);

			/*!
			\brief Constructs a reverse iterator for UnicodeString using another iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other reverse iterator to use in constructing
				this reverse iterator
			*/
			reverse_iterator(const UnicodeString::reverse_iterator& otherIterator);

			/*!
			\brief Constructs a reverse iterator for UnicodeString using an iterator

			This reverse iterator will take on the same position as the iterator.

			@param[in]	iterator	The iterator to use in constructing this reverse iterator
			*/
			reverse_iterator(const UnicodeString::iterator& iterator);

			/*!
			\brief Assigns the value of another reverse iterator to this reverse iterator

			This reverse iterator will take on the same characteristics and position as the
			other reverse iterator

			@param[in]	otherIterator	The other reverse iterator to be assigned to this
				reverse iterator

			\return A reference to this object after the assignment has been completed
			*/
			reverse_iterator& operator=(const UnicodeString::reverse_iterator& otherIterator);

			/*!
			\brief Cleans up before the iterator is destroyed
			*/
			~reverse_iterator();

			/*!
			\brief Indicates whether this iterator is an empty iterator

			This is mainly for informational purposes. If you use iterators properly, comparing
			the begin iterator to the end iterator, you won't even need to know when an 
			empty iterator appears. In case want to know whether an iterator is empty (as opposed
			to an non-empty iterator that has been incremented/decremented beyond the boundaries of 
			a string), you can use this function.
			*/
			bool empty() const;

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for equality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other reverse iterator to be compared with this
				reverse iterator

			\return true if otherIterator is pointing to the same position as this reverse
				iterator, otherwise false
			*/
			bool operator==(const reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for inequality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other reverse iterator to be compared with
				this reverse iterator

			\return false if otherIterator is pointing to the same position as this reverse
				iterator, otherwise true
			*/
			bool operator!=(const reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const reverse_iterator& otherIterator);

			/*!
			\brief Increments this reverse iterator to the previous position in the UnicodeString

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			reverse_iterator& operator++();

			/*!
			\brief Increments this reverse iterator to the previous position in the UnicodeString

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			reverse_iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			reverse_iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			reverse_iterator operator+(size_t offset);

			/*!
			\brief Decrements this reverse iterator to the next position in the UnicodeString

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			reverse_iterator& operator--();

			/*!
			\brief Decrements this reverse iterator to the next position in the UnicodeString

			This is a postfix operator.

			\return A copy of this object before the position was decremented
			*/
			reverse_iterator operator--(int);

			/*!
			\brief Decrements this iterator by a specific offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing this iterator

			\return A reference to this iterator
			*/
			reverse_iterator& operator-=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator decremented by a specific
				offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return An iterator that points to the offset position
			*/
			reverse_iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::reverse_iterator::empty()

			\return A reference to the the character being pointed to by this reverse iterator
			*/
			UnicodeCharReference operator*();

			/*!
			\brief Gets a pointer to the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::reverse_iterator::empty()

			\return A pointer to the character being pointed to by this iterator
			*/
			UnicodeCharReference* operator->();
		};

		/*!
		\brief An iterator that iterates through the code points in a Unicode string in reverse order,
			but allowing only access to constant code points

		This iterator assumes that the Unicode string being iterated over is a valid Unicode string.

		There is also the concept of an "empty" iterator.  An empty iterator is one that is created
		when begin() or end() is called on an empty UnicodeString.  Attempting to change the position
		of an empty iterator using unary operator (such as "+=") will only result in nothing happening. 
		Attempting to get an iterator for another position using a binary operator (such as "+") will
		result in another empty iterator being created.  Dereferencing an iterator via the "*" or "->"
		operators will result in an assertion failure in a debug build or undefined behavior in a 
		release build.  Empty iterators are always equal to each other.
		*/
		class UTFSTRING_DLLEXPORT const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, UnicodeChar>
		{
			friend class UnicodeString::const_iterator;

		private:
			Utf8String::const_reverse_iterator* m_utf8StringIterator;
			Utf16String::const_reverse_iterator* m_utf16StringIterator;
			UnicodeChar* m_currentUnicodeChar;

		public:
			/*!
			\brief Creates an empty constant reverse iterator

			For a description of an empty iterator, see the class description

			\sa UnicodeString::const_reverse_iterator
			*/
			const_reverse_iterator();

			/*!
			\brief Constructs a constant reverse iterator for UnicodeString using a Utf8String reverse iterator

			This function assumes that utf8StringReverseIterator is a valid iterator

			@param[in]	utf8StringReverseIterator	The Utf8String reverse iterator to use in constructing this
				iterator
			*/
			const_reverse_iterator(const Utf8String::const_reverse_iterator& utf8StringReverseIterator);

			/*!
			\brief Constructs a constant reverse iterator for UnicodeString using a Utf16String reverse iterator

			This function assumes that utf16StringReverseIterator is a valid iterator

			@param[in]	utf16StringReverseIterator	The Utf16String reverse iterator to use in constructing this
				iterator
			*/
			const_reverse_iterator(const Utf16String::const_reverse_iterator& utf16StringReverseIterator);

			/*!
			\brief Constructs a constant reverse iterator for UnicodeString using a non-constant reverse iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other reverse iterator to use in constructing
				this reverse iterator
			*/
			const_reverse_iterator(const UnicodeString::reverse_iterator& otherIterator);

			/*!
			\brief Constructs a reverse iterator for UnicodeString using another iterator

			This iterator will take on the same characteristics and position as the other iterator

			@param[in]	otherIterator	The other reverse iterator to use in constructing
				this reverse iterator
			*/
			const_reverse_iterator(const UnicodeString::const_reverse_iterator& otherIterator);

			/*!
			\brief Constructs a constant reverse iterator for UnicodeString using a constant iterator

			This constant reverse iterator will take on the same position as the constant iterator.

			@param[in]	iterator	The constant iterator to use in constructing this constant
				reverse iterator
			*/
			const_reverse_iterator(const UnicodeString::const_iterator& iterator);

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
			\brief Indicates whether this iterator is an empty iterator

			This is mainly for informational purposes. If you use iterators properly, comparing
			the begin iterator to the end iterator, you won't even need to know when an 
			empty iterator appears. In case want to know whether an iterator is empty (as opposed
			to an non-empty iterator that has been incremented/decremented beyond the boundaries of 
			a string), you can use this function.
			*/
			bool empty() const;

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for equality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other reverse iterator to be compared with this
				reverse iterator

			\return true if otherIterator is pointing to the same position as this reverse
				iterator, otherwise false
			*/
			bool operator==(const const_reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this reverse iterator with another reverse iterator and tests
				for inequality

			Empty iterators are always equal to other empty iterators and are always unequal to
			non-empty iterators.

			@param[in]	otherIterator	The other reverse iterator to be compared with
				this reverse iterator

			\return false if otherIterator is pointing to the same position as this reverse
				iterator, otherwise true
			*/
			bool operator!=(const const_reverse_iterator& otherIterator) const;

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before the other iterator in a string, otherwise false
			*/
			bool operator<(const const_reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes before
				or is at the same position the other iterator in the string

			Empty iterators are considered to be less than non-empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes before or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator<=(const const_reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after the other iterator in a string, otherwise false
			*/
			bool operator>(const const_reverse_iterator& otherIterator);

			/*!
			\brief Compares this iterator to another iterator and tests whether this iterator comes after
				or is at the same position the other iterator in the string

			Non-Empty iterators are considered to be greater than than empty iterators.

			This operator has a performance of O(1).

			@param[in]	otherIterator	The other iterator to be compared with this iterator

			\return true if this iterator comes after or is at the same position the other iterator in a
				string, otherwise false
			*/
			bool operator>=(const const_reverse_iterator& otherIterator);

			/*!
			\brief Increments this reverse iterator to the previous position in the UnicodeString

			This is the prefix operator.

			\return A reference to this object after the position has been incremented
			*/
			const_reverse_iterator& operator++();

			/*!
			\brief Increments this reverse iterator to the previous position in the UnicodeString

			This is a postfix operator.

			\return A copy of this object before the position was incremented
			*/
			const_reverse_iterator operator++(int);

			/*!
			\brief Increments this iterator by a specific offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in incrementing this iterator

			\return A reference to this iterator
			*/
			const_reverse_iterator& operator+=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator incremented by a specific
				offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to be used when incrementing this position of this iterator

			\return An iterator that points to the offset position
			*/
			const_reverse_iterator operator+(size_t offset);

			/*!
			\brief Decrements this reverse iterator to the next position in the UnicodeString

			This is a prefix operator.

			\return A reference to this object after the position has been decremented
			*/
			const_reverse_iterator& operator--();

			/*!
			\brief Decrements this reverse iterator to the next position in the UnicodeString

			This is a postfix operator.

			\return A copy of this object before the position was decremented
			*/
			const_reverse_iterator operator--(int);

			/*!
			\brief Decrements this iterator by a specific offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing the position of this iterator

			\return A reference to this iterator
			*/
			const_reverse_iterator& operator-=(size_t offset);

			/*!
			\brief Creates an iterator that has the position of this iterator decremented by a specific
				offset

			Note that since a Unicode string contains variable-width characters, we have to iterate over
			the code units.  As a result, this operator has a performance of O(N).  Hence, this operator
			should be used with care.

			@param[in]	offset	The offset to use in decrementing this iterator

			\return An iterator that points to the offset position
			*/
			const_reverse_iterator operator-(size_t offset);

			/*!
			\brief Gets the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The reference returned by this function will be invalidated if the iterator is
			changed in any way.  Changing the value of the returned object will not
			change the string.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::const_reverse_iterator::empty()

			\return A reference to the the character being pointed to by this reverse iterator
			*/
			const UnicodeChar operator*();

			/*!
			\brief Gets a pointer to the character at the position of this reverse iterator

			If this reverse iterator is not pointing to a position in a UnicodeString, the result will
			be undefined.

			The pointer returned by this function will be invalidated if the iterator is
			changed in any way.

			If this iterator is an empty iterator, using this operator will result in an assertion
			failure in a debug build and undefined behavior (most likely a crash) in a release
			build.

			\sa UnicodeString::const_reverse_iterator::empty()

			\return A pointer to the character being pointed to by this iterator
			*/
			const UnicodeChar* operator->();
		};



		/*Member Functions*/

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	unicodeString	A Unicode string to be appended

		\return	A reference to this string
		*/
		UnicodeString& append(const UnicodeString& unicodeString);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf16String	A string of 16-bit code units to be appended

		\return	A reference to this string
		*/
		UnicodeString& append(const Utf16String& utf16String);

		/*!
		\brief Appends the contents of another string to this string

		@param[in]	utf8String A UTF-8 string to be appended. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		UnicodeString& append(const Utf8String& utf8String);

		/*!
		\brief Appends a Unicode character to this string

		@param[in]	unicodeCharacter	A Unicode character to be appended. The character is assumed
			to be a valid Unicode character

		\return	A reference to this string
		*/
		UnicodeString& append(const UnicodeChar& unicodeCharacter);

		/*!
		\brief Appends a Unicode character to this string

		@param[in]	unicodeCharacterReference	A reference to a Unicode character to be appended. 
			The character is assumed to be a valid Unicode character

		\return	A reference to this string
		*/
		UnicodeString& append(const UnicodeCharReference& unicodeCharacterReference);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	unicodeString	A Unicode string to be assigned

		\return	A reference to this string
		*/
		UnicodeString& assign(const UnicodeString& unicodeString);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf16String	A string of 16-bit code units to be assigned

		\return	A reference to this string
		*/
		UnicodeString& assign(const Utf16String& utf16String);

		/*!
		\brief Assigns the contents of another string to this string, replacing the current contents
			of this string

		@param[in]	utf8String A UTF-8 string to be assigned. The string is assumed to be
			a valid UTF-8 string.

		\return	A reference to this string
		*/
		UnicodeString& assign(const Utf8String& utf8String);

		/*!
		\brief Assigns a Unicode character to this string

		@param[in]	unicodeCharacter	A Unicode character to be assigned. The character is assumed
			to be a valid Unicode character

		\return	A reference to this string
		*/
		UnicodeString& assign(const UnicodeChar& unicodeCharacter);

		/*!
		\brief Assigns a Unicode character to this string

		@param[in]	unicodeCharacterReference	A reference to the Unicode character to be assigned. 
			The character is assumed to be a valid Unicode character

		\return	A reference to this string
		*/
		UnicodeString& assign(const UnicodeCharReference& unicodeCharacterReference);

		/*!
		\brief Returns a reference to the character found at the specified character index

		This operator does for the validity of the index, and throws an out_of_range exception when
		the given index doesn't correspond to a character within a string.  Note that operator[] is
		a faster way to access a specific character, but doesn't check for index validity.

		Unicode strings are of variable length encoding, meaning that whereas accessing a character at 
		a particular index is O(1) for fixed-length encodings,	accessing a character in Unicode strings 
		is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index of a character in the string

		\return The character found at the specified index
		*/
		UnicodeCharReference at(size_t index);

		/*!
		\brief Returns a reference to the character found at the specified character index

		This operator does for the validity of the index, and throws an out_of_range exception when
		the given index doesn't correspond to a character within a string.  Note that operator[] is
		a faster way to access a specific character, but doesn't check for index validity.

		Unicode strings are of variable length encoding, meaning that whereas accessing a character at 
		a particular index is O(1) for fixed-length encodings,	accessing a character in Unicode strings 
		is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index of a character in the string

		\return The character found at the specified index
		*/
		const UnicodeChar at(size_t index) const;

		/*!
		\brief Returns an iterator pointing to the first character of a string

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::iterator
		\sa UnicodeString::empty()

		\return A bidirectional iterator pointing to the first character in a string or just beyond
			the end of an empty string
		*/
		iterator begin();

		/*!
		\brief Returns a constant iterator pointing to the first character of a string

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::const_iterator
		\sa UnicodeString::empty()

		\return A bidirectional constant iterator pointing to the first character in a string or just
			beyond the end of an empty string
		*/
		const_iterator begin() const;

		/*!
		\brief Clears out the string, leaving it an empty string
		*/
		void clear();

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

		@param[in]	unicodeString	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const UnicodeString& unicodeString) const;

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

		@param[in]	utf8String	A string to be compared to this string

		\return A negative number if this string is less than the parameter string, a zero if
			this string is equal to the parameter string, and a positive number if this string
			is greater than the parameter string
		*/
		int compare(const Utf8String& utf8String) const;

		/*!
		\brief Indicates whether this is an empty string

		An empty UnicodeString is one that has no internal data: it is completely empty
		container, ready to be assigned an encoding-specific string.
		*/
		bool empty() const;

		/*!
		\brief Returns an iterator pointing to the location succeeding the last character in a string

		The iterator returned by this function is usually used to test whether an iterator has reached
		the end of a string.  The iterator returned by this function should never be dereferenced, as
		it doesn't not point to a part of the string.

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::iterator
		\sa UnicodeString::empty()

		\return A bidirectional iterator pointing to the location succeeding the last character in a string
		*/
		iterator end();

		/*!
		\brief Returns an constant iterator pointing to the location succeeding the last character in a string

		The iterator returned by this function is usually used to test whether an iterator has reached
		the end of a string.  The iterator returned by this function should never be dereferenced, as
		it doesn't not point to a part of the string.

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::const_iterator
		\sa UnicodeString::empty()

		\return A bidirectional constant iterator pointing to the location succeeding the last character in a string
		*/
		const_iterator end() const;

		/*!
		\brief Removes a range of characters from this string

		@param[in]	firstPosition	An iterator pointing to the first character of the range to be removed
		@param[in]	lastPosition	An iterator pointing to the position one past the last character
			of the range to be removed

		\return An iterator pointing to the first character after the range of characters that were removed,
			or an empty iterator if this string is empty

		\sa UnicodeString::empty()
		*/
		UnicodeString::iterator erase(const UnicodeString::iterator& firstPosition,
			const UnicodeString::iterator& lastPosition);

		/*!
		\brief Removes a character from this string

		@param[in]	position	An iterator pointing to the character to be removed

		\return An iterator pointing to the first character after character that was removed, or an empty
			iterator if this string is empty

		\sa UnicodeString::empty()
		*/
		UnicodeString::iterator erase(const UnicodeString::iterator& position);

		/*!
		\brief Removes a range of characters from this string

		This function will only cause characters to be removed up to the end of the string, so an overly
		large count parameter value will not cause problems.

		This function assumes that offset <= length().

		@param[in]	offset	The offset describing the index location of the first character to be removed
		@param[in]	count	The maximum number of characters to be removed

		\return A reference to this string after the specified range of characters have been removed
		*/
		UnicodeString& erase(const size_t offset = 0, const size_t count = npos);

		/*!
		\brief Searches this string for specific substring

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t find(const UnicodeString& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for specific substring

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t find(const Utf8String& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for specific substring

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t find(const Utf16String& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for the first character that is not found in a given string

		Note that if searchString is not a valid Unicode string, this function will still work,
		but the result may turn up an unexpected code point.  

		@param[in]	searchString	The string containing the characters that are to be excluded in
			the search.
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index of the first character in this string that is not a character in searchString,
			or npos if no such character was found
		*/
		size_t find_first_not_of(const UnicodeString& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for the first character that is not found in a given string

		Note that if searchString is not a valid UTF-8 string, this function will still work,
		but the result may turn up an unexpected code point.  

		@param[in]	searchString	The string containing the characters that are to be excluded in
			the search.
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index of the first character in this string that is not a character in searchString,
			or npos if no such character was found
		*/
		size_t find_first_not_of(const Utf8String& searchString, size_t offset = 0);

		/*!
		\brief Searches this string for the first character that is not found in a given string

		Note that if searchString is not a valid UTF-16 string, this function will still work,
		but the result may turn up an unexpected code point.  

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
		size_t find_first_of(const UnicodeString& searchString, size_t offset = 0);

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
		size_t find_first_of(const Utf8String& searchString, size_t offset = 0);

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

		Note that if searchString is not a valid Unicode string, this function will still work,
		but the result may turn up an unexpected code point.  

		Please note that the offset in this function controls the index where the search <i>ends</i>,
		and	not where it begins.

		@param[in]	searchString	The string containing the characters that are to be excluded in
			the search.
		@param[in]	offset	The index of the string at which the search is to finish

		\return The index of the last character in this string that is not a character in searchString,
			or npos if no such character was found
		*/
		size_t find_last_not_of(const UnicodeString& searchString, size_t offset = npos);

		/*!
		\brief Searches this string for the last character that is not found in a given string

		Note that if searchString is not a valid UTF-8 string, this function will still work,
		but the result may turn up an unexpected code point.  

		Please note that the offset in this function controls the index where the search <i>ends</i>,
		and	not where it begins.

		@param[in]	searchString	The string containing the characters that are to be excluded in
			the search.
		@param[in]	offset	The index of the string at which the search is to finish

		\return The index of the last character in this string that is not a character in searchString,
			or npos if no such character was found
		*/
		size_t find_last_not_of(const Utf8String& searchString, size_t offset = npos);

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
		size_t find_last_of(const UnicodeString& searchString, size_t offset = npos);

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
		size_t find_last_of(const Utf8String& searchString, size_t offset = npos);

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
		@param[in]	unicodeString	A Unicode string to be appended

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length(), is_valid() == true, 
		and unicodeString.is_valid() == true.

		\return	A reference to this string
		*/
		UnicodeString& insert(const size_t index, const UnicodeString& unicodeString);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf8String	A UTF-8 string to be appended

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length(), is_valid() == true, 
		and unicodeString.is_valid() == true.

		\return	A reference to this string
		*/
		UnicodeString& insert(const size_t index, const Utf8String& utf8String);

		/*!
		\brief Inserts the contents of another string into this string at a specified index

		@param[in]	index	The index in this string where the parameter string is to be inserted
		@param[in]	utf16String	A UTF-16 string to be appended

		Note that text can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes index <= length(), is_valid() == true, 
		and unicodeString.is_valid() == true.

		\return	A reference to this string
		*/
		UnicodeString& insert(const size_t index, const Utf16String& utf16String);

		/*!
		\brief Inserts a character into this string at a specified index

		@param[in]	index	The index in this string where the character is to be inserted
		@param[in]	unicodeCharacter	A Unicode character to be appended. The character is assumed
			to be a valid Unicode character

		Note that character can be inserted at the end of the string by specifying an index one past
		the end of the string.

		This function assumes unicodeCharacter is a valid character and that index <= length().

		\return	A reference to this string
		*/
		UnicodeString& insert(const size_t index, const UnicodeChar& unicodeCharacter);

		/*!
		\brief Indicates whether this string is a valid Unicode string

		A valid Unicode string is a string whose encapsulated encoding-specific string is comprised
		of valid code units.

		An empty string is considered to be a valid Unicode string

		\sa UnicodeString::empty()

		\return true if this string is a valid Unicode string, otherwise false
		*/
		bool is_valid() const;

		/*!
		\brief Indicates the internal encoding used by this string

		The internal encoding of a UnicodeString depends on what data is used to initialize the string
		or what data is assigned to the string when it is empty.  If a UnicodeString is initialized
		with a UTF-8 string, the internal encoding will be UTF-8.  In this case, any operations 
		involving a UTF-16 string will result in the UTF-16 string being converted to UTF-8 internally.
		The opposite is the case when a UnicodeString is initialized with a UTF-16 string. This is
		done to keep encoding conversions to a minimum.  If an application is dealing primarily with
		one encoding, and a string in that encoding is put in a UnicodeString, we avoid the conversion
		to a specific internal encoding and then the conversion back to the original encoding.

		\sa UnicodeString::empty()
		*/
		const UtfEncoding internal_encoding() const;

		/*!
		\brief Returns the number of code points in this string

		Use this function if you're interested in how many characters are in a string.

		This function does not check for validity, so it may return an incorrect result if 
		is_valid() is false.

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
		void push_back(const UnicodeChar& character);

		/*!
		\brief Returns an iterator pointing to the first character of a reversed string, which corresponds
			to the last character of the normal string

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::reverse_iterator
		\sa UnicodeString::empty()

		\return A bidirectional iterator pointing to the first character in a reversed string or just beyond
			the end of an empty reversed string
		*/
		reverse_iterator rbegin();

		/*!
		\brief Returns a constant iterator pointing to the first character of a reversed string, which
			corresponds to the last character of a normal string

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::const_reverse_iterator
		\sa UnicodeString::empty()

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

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::reverse_iterator
		\sa UnicodeString::empty()

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

		If the UnicodeString is empty, an empty iterator is created.  See the iterator class
		description for more information about empty iterators.

		\sa UnicodeString::const_reverse_iterator
		\sa UnicodeString::empty()

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
		UnicodeString& replace(const size_t position, const size_t count, const UnicodeString& replacementString);

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
		UnicodeString& replace(const size_t position, const size_t count, const Utf8String& replacementString);

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
		UnicodeString& replace(const size_t position, const size_t count, const Utf16String& replacementString);

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
		UnicodeString& replace(const size_t position, const size_t count, const size_t characterCount,
			const UnicodeChar& character);

		/*!
		\brief Removes a section of this string and replaces it with the contents of another string

		This function replaces the section of the string from beginIterator to endIterator - 1, where
		endIterator is pointing at a position one past the end of the section to be replaced.

		If endIterator points to a position before beginIterator, endIterator is ignored and the entire
		string from beginIterator to the end of the string is replaced.  If beginIterator points to the
		same position as endIterator, replacementString is simply inserted at that position and nothing
		in this string is removed.

		If this string is an empty string, then neither of the iterators passed in can be valid non-empty
		iterators. In this case, the empty string is replaced with the contents of replacementString.

		This function assumes that beginIterator and endIterator are iterators for this string. This 
		function also assumes that beginIterator and endIterator are both valid iterators when
		this string is non-empty or that beginIterator and endIterator are both empty iterators when
		this string is empty.

		@param[in]	beginIterator	An iterator pointing to the first character of the string section
			to be replaced
		@param[in]	endIterator		An iterator pointing to the position one past the last character
			of the string section to be replaced
		@param[in]	replacementString	The string whose contents are to replace the section being removed

		\return A reference to this string after the replacement has been completed
		*/
		UnicodeString& replace(UnicodeString::iterator beginIterator, UnicodeString::iterator endIterator,
			const UnicodeString& replacementString);

		/*!
		\brief Replaces the characters in a section of this string with the given character

		This function replaces the section of the string from beginIterator to endIterator - 1, where
		endIterator is pointing at a position one past the end of the section to be replaced.

		If endIterator points to a position before beginIterator, endIterator is ignored and the entire
		string from beginIterator to the end of the string is replaced.  If beginIterator points to the
		same position as endIterator, the new characters are simply inserted at that position and nothing
		in this string is removed.

		If this string is an empty string, then neither of the iterators passed in can be valid non-empty
		iterators. In this case, the empty string is replaced with the contents of replacementString.

		This function assumes that beginIterator and endIterator are iterators for this string. This 
		function also assumes that beginIterator and endIterator are both valid iterators when
		this string is non-empty or that beginIterator and endIterator are both empty iterators when
		this string is empty.

		@param[in]	beginIterator	An iterator pointing to the first character of the string section
			to be replaced
		@param[in]	endIterator		An iterator pointing to the position one past the last character
			of the string section to be replaced
		@param[in]	characterCount	The number of times the character is to be repeated in the replaced section
		@param[in]	character	The character to replace the characters in the identified section of this
			string

		\return A reference to this string after the replacement has been completed
		*/
		UnicodeString& replace(UnicodeString::iterator beginIterator, UnicodeString::iterator endIterator,
			const size_t characterCount, const UnicodeChar& character);

		/*!
		\brief Searches this string backward for specific substring

		Note this does not look at the characters in reverse order like iterating through a string with a
		reverse iterator.  It looks at the characters in forward order just like the find() function,
		but starts at the end of the string and works backward toward the beginning.

		This function assumes that searchString.is_valid() is true.

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t rfind(const UnicodeString& searchString, size_t offset = npos);

		/*!
		\brief Searches this string backward for specific substring

		Note this does not look at the characters in reverse order like iterating through a string with a
		reverse iterator.  It looks at the characters in forward order just like the find() function,
		but starts at the end of the string and works backward toward the beginning.

		This function assumes that searchString.is_valid() is true.

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t rfind(const Utf8String& searchString, size_t offset = npos);

		/*!
		\brief Searches this string backward for specific substring

		Note this does not look at the characters in reverse order like iterating through a string with a
		reverse iterator.  It looks at the characters in forward order just like the find() function,
		but starts at the end of the string and works backward toward the beginning.

		This function assumes that searchString.is_valid() is true.

		@param[in]	searchString	The substring to be found in this string
		@param[in]	offset	The index of the string at which the search is to begin

		\return The index at which the substring was found, or npos if the substring was not found
		*/
		size_t rfind(const Utf16String& searchString, size_t offset = npos);

		/*!
		\brief Returns the number of code points in this string

		This function is exactly the same as the length() function. We just include it here because
		it is a standard function in most string and STL classes.

		This function has a O(N) performance, since we need to iterate through the code units to figure
		out how many code points there are.  Counting each code point is an extremely quick operation, but
		due to the need to visit every code point in the string, it would be wise to be mindful of performance
		when making heavy use of this function on long strings in performance-sensitive code.

		\return The number of code points in this string
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
		UnicodeString substr(const size_t offset = 0, const size_t count = npos);

		/*!
		\brief Swaps the contents of this string with those of another string

		This function assumes that is_valid() is true and unicodeString.is_valid() is true.

		@param[in]	unicodeString	The string whose contents are to be swapped with the contents this string
		*/
		void swap(UnicodeString& unicodeString);

		/*!
		\brief Swaps the contents of this string with those of another string

		This function assumes that is_valid() is true and utf8String.is_valid() is true.

		@param[in]	utf8String	The string whose contents are to be swapped with the contents this string
		*/
		void swap(Utf8String& utf8String);

		/*!
		\brief Swaps the contents of this string with those of another string

		This function assumes that is_valid() is true and utf16String.is_valid() is true.

		@param[in]	utf16String	The string whose contents are to be swapped with the contents this string
		*/
		void swap(Utf16String& utf16String);

		/*Operators*/

		/*!
		\brief Returns the character found at the specified character index

		This operator does not check for the validity of the index, so it assumes that index is valid.
		What happens when the index is invalid is undefined. If you want the index parameter to be validated,
		use the at() function instead.

		Unicode strings are of variable length encoding, meaning that whereas accessing a character at 
		a particular index is O(1) for fixed-length encodings,	accessing a character in Unicode strings 
		is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index identifying the character to be retrieved

		\return The character found at the specified index
		*/
		UnicodeCharReference operator[](const size_t index);

		/*!
		\brief Returns the character found at the specified character index

		This operator does not check for the validity of the index, so it assumes that index is valid.
		What happens when the index is invalid is undefined. If you want the index parameter to be validated,
		use the at() function instead.

		Unicode strings are of variable length encoding, meaning that whereas accessing a character at 
		a particular index is O(1) for fixed-length encodings,	accessing a character in Unicode strings 
		is O(1) in the best case and O(n) in the worst case.

		So if you wish to iterate through the characters in this string, use the standard iterators instead
		of an indexer.  The standard iterators will be far more efficient.

		@param[in]	index	The index identifying the character to be retrieved

		\return The character found at the specified index
		*/
		const UnicodeChar operator[](const size_t index) const;

		/*!
		\brief Assigns the contents of a UnicodeString object to this object

		@param[in]	unicodeString	The UnicodeString object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeString& operator=(const UnicodeString& unicodeString);

		/*!
		\brief Assigns the contents of a Utf8String object to this object

		@param[in]	utf8String	The Utf8StringString object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeString& operator=(const Utf8String& utf8String);

		/*!
		\brief Assigns the contents of a Utf16String object to this object

		@param[in]	utf16String	The Utf16StringString object whose contents
			are to be assigned to this object

		\return A reference to this object
		*/
		UnicodeString& operator=(const Utf16String& utf16String);

		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the two strings are the same

		@param[in]	otherString	The string to be compared with this string

		\return true if the two strings are equal, otherwise false
		*/
		bool operator==(const UnicodeString& otherString) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-8 string and
			tests whether the two strings are the same

		@param[in]	utf8String	The UTF-8 string to be compared with this string

		\return true if the two strings are equal, otherwise false
		*/
		bool operator==(const Utf8String& utf8String) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-16 string and
			tests whether the two strings are the same

		@param[in]	utf16String	The UTF-16 string to be compared with this string

		\return true if the two strings are the equal, otherwise false
		*/
		bool operator==(const Utf16String& utf16String) const;

		/*!
		\brief Compares the value of this string to the value of another string and
			tests whether the two strings are the different

		@param[in]	otherString	The string to be compared with this string

		\return true if the two strings are different, otherwise false
		*/
		bool operator!=(const UnicodeString& otherString) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-8 string and
			tests whether the two strings are the different

		@param[in]	utf8String	The UTF-8 string to be compared with this string

		\return true if the two strings are different, otherwise false
		*/
		bool operator!=(const Utf8String& utf8String) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-16 string and
			tests whether the two strings are the different

		@param[in]	utf16String	The UTF-16 string to be compared with this string

		\return true if the two strings are different, otherwise false
		*/
		bool operator!=(const Utf16String& utf16String) const;

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
		bool operator<(const UnicodeString& otherString) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-8 string and
			tests whether the value of this string is less than the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf8String	The UTF-8 string to be compared with this string

		\return true if the the value of this string is less than the value
			of the other string, otherwise false
		*/
		bool operator<(const Utf8String& utf8String) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-16 string and
			tests whether the value of this string is less than the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf16String	The UTF-16 string to be compared with this string

		\return true if the the value of this string is less than the value
			of the other string, otherwise false
		*/
		bool operator<(const Utf16String& utf16String) const;

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
		bool operator<=(const UnicodeString& otherString) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-8 string and
			tests whether the value of this string is less than or equal to the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf8String	The UTF-8 string to be compared with this string

		\return true if the the value of this string is less than or equal to the value
			of the other string, otherwise false
		*/
		bool operator<=(const Utf8String& utf8String) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-16 string and
			tests whether the value of this string is less than or equal to the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf16String	The UTF-16 string to be compared with this string

		\return true if the the value of this string is less than or equal to the value
			of the other string, otherwise false
		*/
		bool operator<=(const Utf16String& utf16String) const;

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
		bool operator>(const UnicodeString& otherString) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-8 string and
			tests whether the value of this string is greater than the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf8String	The UTF-8 string to be compared with this string

		\return true if the the value of this string is greater than the value
			of the other string, otherwise false
		*/
		bool operator>(const Utf8String& utf8String) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-16 string and
			tests whether the value of this string is greater than the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf16String	The UTF-16 string to be compared with this string

		\return true if the the value of this string is greater than the value
			of the other string, otherwise false
		*/
		bool operator>(const Utf16String& utf16String) const;

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
		bool operator>=(const UnicodeString& otherString) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-8 string and
			tests whether the value of this string is greater than or equal to the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf8String	The string to be compared with this string

		\return true if the the value of this string is greater than or equal to the value
			of the other string, otherwise false
		*/
		bool operator>=(const Utf8String& utf8String) const;

		/*!
		\brief Compares the value of this string to the value of a UTF-16 string and
			tests whether the value of this string is greater than or equal to the
			value of the other string

		The values of each string are determined by the Unicode values of the characters.
		This is the similar comparing strings in alphabetical order, where the character
		order is determined by the Unicode values and not the ordering of any particular
		alphabet. 

		In practice, this works out to be the same as alphabetical ordering for English-
		language strings, but may not be for strings in other languages.

		@param[in]	utf16String	The UTF-16 string to be compared with this string

		\return true if the the value of this string is greater than or equal to the value
			of the other string, otherwise false
		*/
		bool operator>=(const Utf16String& utf16String) const;

		/*!
		\brief Converts this object to a Utf16String object

		This operator assumes that if this string is non-empty, it is a valid 
		Unicode string.

		If this object does not contain a string, an empty Utf16String
		will be returned

		\sa UnicodeString::is_valid()
		\sa UnicodeString::empty()
		*/
		operator Utf16String() const;

		/*!
		\brief Converts this object to a Utf8String object

		This operator assumes that if this string is non-empty, it is a valid 
		Unicode string.

		If this object does not contain a string, an empty Utf8String
		will be returned

		\sa UnicodeString::is_valid()
		\sa UnicodeString::empty()
		*/
		operator Utf8String() const;

		/*!
		\brief This operator reads a stream of bytes into a UnicodeString

		This function clears the contents of the string before anything is read.
		This function will read the stream depending on the internal encoding of 
		the UnicodeString object.  If the internal encoding is UTF-8, the stream will
		be read as a stream of UTF-8 characters, and if the internal incoding is UTF-16,
		the stream will be read as a stream of UTF-16 characters. If the string does not
		have an internal encoding(uninitialized), we will assume we are reading a stream
		of UTF-8 characters

		@param[in]	inputStream	The input stream bytes to be read
		@param[in]	unicodeString	The string object in which the stream contents will
			be stored

		\sa UnicodeString::internal_encoding()
		*/
		friend std::istream& operator >>(std::istream& inputStream, UnicodeString& unicodeString)
		{	
			if(unicodeString.m_utf16String != NULL)
			{
				inputStream >> *unicodeString.m_utf16String;
			}
			else
			{
				if(unicodeString.m_utf8String == NULL)
				{
					unicodeString = Utf8String();
				}

				inputStream >> *unicodeString.m_utf8String;
			}

			return inputStream;
		}

		/*!
		\brief This operator converts the contents of a UnicodeString to a stream of bytes

		This function will write to the stream depending on the internal encoding of 
		the UnicodeString object.  If the internal encoding is UTF-8, the stream will
		be written to as a stream of UTF-8 characters, and if the internal incoding is UTF-16,
		the stream will be written to a stream of UTF-16 characters. If the string does not
		have an internal encoding(uninitialized), nothing will be written to the stream.

		@param[in]	outputStream	The output stream to which the contents of the UTF-8 string
			are to be written
		@param[in]	unicodeString	The UnicodeString to be written to the output stream
		*/
		friend std::ostream& operator <<(std::ostream& outputStream, const UnicodeString& unicodeString)
		{
			if(unicodeString.m_utf8String != NULL)
			{
				outputStream << *unicodeString.m_utf8String;
			}
			else if(unicodeString.m_utf16String != NULL)
			{
				outputStream << *unicodeString.m_utf16String;
			}

			return outputStream;
		}

		/*!
		\brief This operator converts a wide stream of 16-bit values to a UTF-16 string and
		stores the UTF-16 string inside unicodeString

		This function clears the contents of unicodeString before the stream is converted.
		In addition this function assumes that the stream being converted is of the same
		endianness as the machine on which this function was compiled.

		This function always assumes that that a wide stream contains a UTF-16 string, and not
		a UTF-8 string.

		@param[in]	inputStream	The wide input stream containing 16-bit values to be converted
			to a UTF-16 string
		@param[in]	unicodeString	The string object into which the converted UTF-16 string
			will be stored
		*/
		friend std::wistream& operator >>(std::wistream& inputStream, UnicodeString& unicodeString)
		{
			unicodeString.clear();

			unicodeString = Utf16String();

			inputStream >> *unicodeString.m_utf16String;

			return inputStream;
		}

		/*!
		\brief This operator converts a Unicode string to a wide stream of 16-bit values

		No checks for validity are done, so the resulting UTF-16 stream may or may not contain a valid
		UTF-16 string.

		If the UnicodeString contains a UTF-8 string, the function converts it to a UTF-16 string first.
		What happens when the UTF-8 string is invalid is undefined, so you better make sure your UTF-8
		string is valid before doing this.

		@param[in]	outputStream	The wide output stream to which the contents of the UTF-16 string
			are to be written
		@param[in]	unicodeString	The Unicode string to be written to the output stream
		*/
		friend std::wostream& operator <<(std::wostream& outputStream, const UnicodeString& unicodeString)
		{
			Utf16String utf16String = (Utf16String)unicodeString;

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
		\brief Indicates whether a Unicode character is a whitespace character

		This function tests for the standard ASCII whitespace characters(tab, space, carriage return, line feed),
		and the characters that the Unicode standard defines as being separator characters.

		An empty character is not considered to be a whitespace character.

		\sa UnicodeString::empty()

		@param[in]	unicodeCharacter The character to be examined

		\return If unicodeCharacter is a whitespace character, true, otherwise false
		*/
		static bool IsWhitespace(const UnicodeChar& unicodeCharacter);

		/*Static Constants*/

		/*!
		\brief An unsigned integral value initialized to –1 that indicates either "not found" or
			"all remaining characters" when a search function fails.
		*/
		static const size_t npos;
	};
}

#endif
