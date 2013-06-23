/*!
\file UtfString.h

This file is the main include file for the UtfString library, and contains all the definitions and declarations
necessary to use the UtfString library.

//TODO: Explain about having to define VS2005 in program that is using this library (gets rid of many warnings)

/*
Notes:

Define UTFSTRING_DLL when linking to dll

*/

#pragma warning(disable: 4275)
#pragma warning(disable: 4251)

#ifndef __UTFSTRING_UTFSTRING_H__
#define __UTFSTRING_UTFSTRING_H__

#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>

#if HAVE_CONFIG_H
   #include <config.h>
#endif

//Platform-related definitions
#ifdef WIN32
	//typedef unsigned int UInt32;
	//typedef unsigned short UInt16;
	//typedef	unsigned char Byte;
	#define UInt32	unsigned int
	#define UInt16	unsigned short
	#define Byte	unsigned char


	#ifdef UTFSTRING_EXPORTS
		#define UTFSTRING_DLLEXPORT __declspec(dllexport)
		#define UTFSTRING_EXPORTTEMPLATE
	#endif

	#ifdef UTFSTRING_DLL
		#define UTFSTRING_DLLEXPORT __declspec(dllimport)
		//#define UTFSTRING_EXPORTTEMPLATE extern
	#endif

	#ifndef UTFSTRING_DLLEXPORT
		#define UTFSTRING_DLLEXPORT
		//#define UTFSTRING_EXPORTTEMPLATE extern
	#endif

	#ifndef UTFSTRING_EXPORTTEMPLATE
		#define UTFSTRING_EXPORTTEMPLATE
	#endif
#endif

#ifdef WIN64
	#define UInt32	unsigned int
	#define UInt16	unsigned short
	#define Byte	unsigned char

	#ifdef UTFSTRING_DLL
		#define UTFSTRING_DLLEXPORT __declspec(dllimport)
		//#define UTFSTRING_EXPORTTEMPLATE extern
	#endif

	#ifndef UTFSTRING_DLLEXPORT
		#define UTFSTRING_DLLEXPORT
	#endif

	#ifndef EXPORTEMPLATE
		#define UTFSTRING_EXPORTTEMPLATE
	#endif
#endif

#ifdef POSIX
	#if SIZEOF_WCHAR_T == 2
		#define WCHAR_T_16BIT
	#endif
#endif


//Compiler-related definitions
#ifdef VS2005
	#define WCHAR_T_16BIT

	#ifdef _DEBUG
		class UTFSTRING_DLLEXPORT std::_Iterator_base;
	#else
		struct UTFSTRING_DLLEXPORT std::_Iterator_base;
	#endif

	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::basic_string<UInt16>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::_String_iterator<UInt16, std::char_traits<UInt16>, std::allocator<UInt16> >;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::_String_iterator<char, std::char_traits<char>, std::allocator<char> >;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::string::iterator>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::string::const_iterator>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::basic_string<UInt16>::iterator>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::basic_string<UInt16>::const_iterator>;
#endif

#ifdef VS2010
	#define WCHAR_T_16BIT

	struct UTFSTRING_DLLEXPORT std::_Iterator_base12;
	
	//template class UTFSTRING_DLLEXPORT std::_Iterator_base;

	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::basic_string<UInt16>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::_String_iterator<UInt16, std::char_traits<UInt16>, std::allocator<UInt16> >;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::_String_iterator<char, std::char_traits<char>, std::allocator<char> >;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::string::iterator>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::string::const_iterator>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::basic_string<UInt16>::iterator>;
	UTFSTRING_EXPORTTEMPLATE template class UTFSTRING_DLLEXPORT std::reverse_iterator<std::basic_string<UInt16>::const_iterator>;
#endif

#ifdef GCC
	#define WCHAR_T_16BIT
#endif

#ifdef DEVCPP
	#define wchar_t unsigned int
	#define wstring basic_string<wchar_t>
	#define wistream basic_istream<wchar_t, std::char_traits<wchar_t> >
	#define wostream basic_ostream<wchar_t, std::char_traits<wchar_t> >
	#define wstringstream basic_stringstream<wchar_t>

	#include <utfstring/PlatformImplementations.h>
	#define wcslen GlobalFunctions::wcslen
#endif

#ifdef CODEBLOCKS
	#define wchar_t unsigned int
	#define wstring basic_string<wchar_t>
	#define wistream basic_istream<wchar_t, std::char_traits<wchar_t> >
	#define wostream basic_ostream<wchar_t, std::char_traits<wchar_t> >
	#define wstringstream basic_stringstream<wchar_t>

	#include <utfstring/PlatformImplementations.h>
	#define wcslen GlobalFunctions::wcslen
#endif

#ifndef UTFSTRING_DLLEXPORT
	#define UTFSTRING_DLLEXPORT
#endif

#ifndef UTFSTRING_EXPORTTEMPLATE
	#define UTFSTRING_EXPORTTEMPLATE
#endif

#include "UtfCommon.h"
#include "UtfStringConverter.h"
#include "Utf8String.h"
#include "Utf16String.h"
#include "UnicodeChar.h"
#include "UnicodeCharReference.h"
#include "UnicodeString.h"

#endif
