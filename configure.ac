#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.61)
AC_INIT(libutfstring, 1.0, bugs@utfstring.net)
AC_CONFIG_AUX_DIR([config-aux])
AM_INIT_AUTOMAKE(libutfstring, 1.0)
AM_PATH_CPPUNIT(1.9.14)
AC_CONFIG_SRCDIR([include/utfstring/UtfString.h])
AM_CONFIG_HEADER(config.h)
AC_CONFIG_FILES([Makefile src/Makefile include/Makefile test/Makefile])
AC_PROG_LIBTOOL
AC_PROG_INSTALL

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for arguments.
AC_ARG_ENABLE(
	[debug],
	AS_HELP_STRING([--enable-debug],[Set compiler flags for debug symbols, default is no debugging.]),
	[case "$enableval" in
		no)
			AC_DEFINE(NDEBUG,,[Define to indicate no debugging])
			DEBUGFLAGS=""
			;;
		yes)
			AC_DEFINE(DEBUG,,[Define to indicate debugging])
			DEBUGFLAGS="-g"
			;;
		*)
			DEBUGFLAGS="$enableval"
			;;
	esac],
	[DEBUGFLAGS=""
	AC_DEFINE(NDEBUG,,[Define to indicate no debugging])]
)
AC_SUBST(DEBUGFLAGS)

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_SIZE_T

# Finds the 8-bit unsigned integer type and defines it as uint8_t
AC_TYPE_UINT8_T

# Finds the 16-bit unsigned integer type and defines it as uint16_t
AC_TYPE_UINT16_T

# Finds the 32-bit unsigned integer type and defines it as uint32_t
AC_TYPE_UINT32_T

# Checks for wchar_t, and if it doesn't exist, defines it as a 16-bit
# unsigned integer type
AC_CHECK_TYPE([wchar_t], , 
	[AC_DEFINE([wchar_t], uint16_t, [A wide character type])])

# Checks for wstring, and if it doesn't exist, defines it as a
# a string of 16-bit characters
AC_CHECK_TYPE([wstring], ,
	[AC_DEFINE([wstring], [basic_string<wchar_t>], 
	[A wide character string type])], [#include <string>])

# Checks for wistream, and if it doesn't exist, defines it as a
# a stream of wchar_t characters
AC_CHECK_TYPE([wistream], ,
	[AC_DEFINE([wistream], [basic_istream<wchar_t, std::char_traits<wchar_t> >], 
	[A wide character string type])], [#include <iostream>])

# Checks for wistream, and if it doesn't exist, defines it as a
# a stream of wchar_t characters
AC_CHECK_TYPE([wostream], ,
	[AC_DEFINE([wostream], [basic_ostream<wchar_t, std::char_traits<wchar_t> >], 
	[A wide character string type])], [#include <iostream>])
	
# Checks for wstringstream, and if it doesn't exist, defines it as a
# a stream of wchar_t characters
AC_CHECK_TYPE([wstringstream], ,
	[AC_DEFINE([wstringstream], [basic_stringstream<wchar_t>], 
	[A wide character string type])], [#include <sstream>])	

# Define UInt32 as a 32-bit unsigned integer type so that the code
# will compile on POSIX platforms
AC_DEFINE([UInt32], uint32_t, [A 32-bit unsigned integer type])

# Define UInt16 as a 16-bit unsigned integer type so that the code
# will compile on POSIX platforms
AC_DEFINE([UInt16], uint16_t, [A 16-bit unsigned integer type])

# Define Byte as a 8-bit unsigned integer type so that the code
# will compile on POSIX platforms
AC_DEFINE([Byte], uint8_t, [An 8-bit unsigned integer type])

# Check the size of wchar_t
AC_CHECK_SIZEOF([wchar_t])

# Checks for library functions.

AC_OUTPUT
