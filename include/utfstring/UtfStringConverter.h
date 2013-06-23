/*!
\file UtfStringConverter.h

This file declares the string converter class that is used to perform string conversions throughout
the UtfString library
*/
#ifndef __UTFSTRING_UTFSTRINGCONVERTER_H__
#define __UTFSTRING_UTFSTRINGCONVERTER_H__

namespace UtfString
{
	//Forward Declarations
	class Utf8String;
	class Utf16String;

	/*!
	This class contains the functionality for converting strings to another encoding.
	*/
	class UTFSTRING_DLLEXPORT UtfStringConverter
	{
		friend class Utf16CharReference;
		friend class Utf16Char;
		friend class Utf8CharReference;
		friend class Utf8Char;

	public:
		/*!
		\brief Converts a UTF-8 string to a UTF-16 string

		This function assumes that utf8String is a valid UTF-8 string.

		@param[in]	utf8String	The UTF-8 string to be converted
		@param[out]	utf16String	The string in which the converted UTF-16 stored will be stored
		*/
		static void Utf8ToUtf16String(const Utf8String& utf8String, Utf16String& utf16String);

		/*!
		\brief Converts a UTF-8 string to a UTF-16 string

		This function assumes that utf8String is a valid UTF-8 string.

		@param[in]	utf8String	The UTF-8 string to be converted
		@param[out]	utf16String	The string in which the converted UTF-16 string will be stored
		*/
		static void Utf8ToUtf16String(const std::string& utf8String, Utf16String& utf16String);

		/*!
		\brief Converts a UTF-16 string to a UTF-8 string

		This function assumes that utf16String is a valid UTF-16 string.

		@param[in]	utf16String	The UTF-16 string to be converted
		@param[out]	utf8String	The string in which the converted UTF-8 string will be stored
		*/
		static void Utf16ToUtf8String(const Utf16String& utf16String, Utf8String& utf8String);

		/*!
		\brief Converts a UTF-16 string to a UTF-8 string

		This function assumes that utf16String is a valid UTF-16 string.

		@param[in]	utf16String	The UTF-16 string to be converted
		@param[out]	utf8String	The string in which the converted UTF-8 string will be stored
		*/
		static void Utf16ToUtf8String(const std::wstring& utf16String, Utf8String& utf8String);

	private:
		/*!
		\brief Converts a UTF-8 character to a UTF-16 character

		To convert a UTF-8 character to a UTF-16 character, pass a pointer to a buffer containing
		the UTF-8 code units and the size of the UTF-8 code unit buffer.  In addition, pass
		a UTF-16 code unit buffer in which the converted UTF-16 character will be written and
		the size of the UTF-16 buffer.  If the converted UTF-16 character will be composed of one
		code unit, the UTF-16 buffer can have the length of 1.  Otherwise, the UTF-16 buffer must
		have a length of 2.

		When the conversion is complete, the number of code units will be written to the 
		utf16BufferSize parameter.

		@param[in]		utf8CodePoint	A buffer containing the code units of the UTF-8 character to
			be converted
		@param[in]		utf8CodeUnitCount	The size of the buffer containing the UTF-8 code units
		@param[out]		utf16CodePoint	The buffer in which the converted UTF-16 character will 
			be stored
		@param[in, out]	utf16BufferSize	The size of the UTF-16 buffer being passed in. After this
			function returns, this parameter will contain the number of code units stored in
			the UTF-16 buffer.
		*/
		static void Utf8ToUtf16Char(const char utf8CodePoint[], const size_t utf8CodeUnitCount, 
			UInt16 utf16CodePoint[], size_t& utf16BufferSize);

		/*!
		\brief Converts a UTF-16 character to a UTF-8 character

		To convert a UTF-16 character to a UTF-8 character, pass a pointer to a buffer containing
		the UTF-16 code units and the size of the UTF-16 code unit buffer.  In addition, pass
		a UTF-8 code unit buffer in which the converted UTF-8 character will be written and
		the size of the UTF-8 buffer.  If the converted UTF-8 character will be composed of one
		code unit, the UTF-8 buffer can have the length of 1.  If the converted UTF-8 character
		will be composed of more code units, however, the UTF-8 buffer must have enough capacity
		to hold those code units.  Under the current Unicode standard, the maximum number of code
		units a UTF-8 character can be composed of is 4, so the number of UTF-8 code units is not
		known beforehand, it would be best to pass a buffer of length 4 or greater.

		When the conversion is complete, the number of code units will be written to the 
		utf8BufferSize parameter.

		@param[in]		utf16CodePoint	A buffer containing the code units of the UTF-16 character to
			be converted
		@param[in]		utf16CodeUnitCount	The size of the buffer containing the UTF-16 code units
		@param[out]		utf8CodePoint	The buffer in which the converted UTF-8 character will 
			be stored
		@param[in, out]	utf8BufferSize	The size of the UTF-8 buffer being passed in. After this
			function returns, this parameter will contain the number of code units stored in
			the UTF-8 buffer.
		*/
		static void Utf16ToUtf8Char(const UInt16 utf16CodePoint[], const size_t utf16CodeUnitCount, 
			char utf8CodePoint[], size_t& utf8BufferSize);

	};
}

#endif
