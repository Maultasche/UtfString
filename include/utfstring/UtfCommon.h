/*!
\file UtfCommon.h

This file defines the data types and classes that will be used throughout the UtfString library
*/
#ifndef __UTFSTRING_UTFCOMMON_H__
#define __UTFSTRING_UTFCOMMON_H__

/*!
The UtfString namespace contains all the classes, enumerations, constants, etc. used in the
UtfString library
*/
namespace UtfString
{
	/*!
	This enumeration describes the different types of BOMS (Byte Order Markers) that precede
	the different types of UTF strings.
	*/
	enum UtfBOM 
	{
		/*! The BOM that indicates UTF-8 encoding */
		BOM_UTF8 = 0xEFBBBF,
		/*! The BOM that indicates UTF-16 big-endian encoding */
		BOM_UTF16BE = 0xFEFF,
		/*! The BOM that indicates UTF-16 little-endian encoding */
		BOM_UTF16LE = 0xFFFE,
		/*! The BOM that indicates UTF-32 big-endian encoding */
		BOM_UTF32BE = 0x0000FEFF,
		/*! The BOM that indicates UTF-32 little-endian encoding */
		BOM_UTF32LE = 0xFFFE0000,
	};

	/*!
	Enumerates the encodings that this library is capable of handling
	*/
	enum UtfEncoding
	{
		/*! No Encoding */
		ENCODING_NONE,

		/*! UTF-8 encoding */
		ENCODING_UTF8,

		/*! UTF-16 encoding */
		ENCODING_UTF16,
	};

	/*!
	Enumerates the numbers that form the base (the lowest possible number) of UTF-16 
	surrogate code units
	*/
	enum Utf16SurrogateBaseNumbers
	{
		/*! The number used as the base number for the high code unit of a UTF-16 surrogate pair */
		HighCodeUnitBaseNumber = 0xD800,
		/*! The number used as the base number for the low code unit of a UTF-16 surrogate pair */
		LowCodeUnitBaseNumber = 0xDC00,
	};

	/*!
	Enumerates the range of numbers that are reserved for UTF-16 surrogate code units. For example,
	if the lower end of a the range of high code units is 0xD800 and the upper end of the range
	is 0xDBFF, that means any code unit found in the range 0xD800 - 0xDBFF is a high code unit
	of a UTF-16 surrogate pair.
	*/
	enum Utf16SurrogateRange
	{
		/*! The lower end of the range of high code units of a UTF-16 surrogate pair */
		HighCodeUnitRangeBegin = 0xD800,
		/*! The upper end of the range of high code units of a UTF-16 surrogate pair */
		HighCodeUnitRangeEnd = 0xDBFF,
		/*! The lower end of the range of low code units of a UTF-16 surrogate pair */
		LowCodeUnitRangeBegin = 0xDC00,
		/*! The upper end of the range of low code units of a UTF-16 surrogate pair */
		LowCodeUnitRangeEnd = 0xDFFF,
	};

	/*!
	Describes maximum number of code units that can comprise a character in various different encodings
	*/
	enum CodeUnitMax
	{
		/*! The maximum number of code units that can encode a code point in UTF-8 */
		Utf8CodeUnitMax = 4,
		/*! The maximum number of code units that can encode a code ponit in UTF-16 */
		Utf16CodeUnitMax = 2,
	};

}

#endif
