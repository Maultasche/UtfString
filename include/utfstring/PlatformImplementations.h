/*!
\file PlatformImplementations.h

This file contains any platform-specific implementations of functions or classes that may
need to be defined or changed for platforms that have non-standard or incomplete C++
standard library implementations.
*/

#ifndef __UTFSTRING_PLATFORMIMPLEMENTATIONS_H__
#define __UTFSTRING_PLATFORMIMPLEMENTATIONS_H__

/*!
The UtfString namespace contains all the classes, enumerations, constants, etc. used in the
UtfString library
*/
namespace UtfString
{
	/*!
	This class contains global function implementations necessary for UtfString to function
	on platforms containing non-standard or incomplete implementations of the C++
	standard library.
	*/
	class GlobalFunctions
	{
	public:

	#ifdef DEVCPP
		static size_t wcslen(const wchar_t* wideCharacterString)
		{
			return 0;
		}
	#endif

	#ifdef DEVCPP
		static size_t wcslen(const wchar_t* wideCharacterString)
		{
			return 0;
		}
	#endif

	};

}

#endif
