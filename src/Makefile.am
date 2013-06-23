lib_LTLIBRARIES = libutfstring.la
libutfstring_la_SOURCES = Utf16Char.cpp Utf16CharReference.cpp \
	Utf16String.cpp Utf8Char.cpp Utf8CharReference.cpp \
	Utf8String.cpp UtfStringConverter.cpp
libutfstring_la_LDFLAGS = -no-undefined

libutfstring_la_CPPFLAGS = -I$(srcdir)/../include -DPOSIX @DEBUGFLAGS@
