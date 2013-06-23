libutfstringtestbindir = $(top_builddir)/test/bin

libutfstringtestbin_PROGRAMS = utfstringtest
utfstringtest_SOURCES = StringConverterTest.cpp \
	TestRunner.cpp \
	UnicodeCharReferenceTest.cpp \
	UnicodeCharTest.cpp \
	UnicodeStringTest.cpp \
	Utf8CharReferenceTest.cpp \
	Utf8CharTest.cpp \
	Utf8StringTest.cpp \
	Utf16CharReferenceTest.cpp \
	Utf16CharTest.cpp \
	Utf16StringTest.cpp

utfstringtest_CPPFLAGS = -I$(srcdir)/../include -DPOSIX $(CPPUNIT_CFLAGS)
utfstringtest_LDADD = $(top_builddir)/src/libutfstring.la
utfstringtest_LDFLAGS = $(CPPUNIT_LIBS) -ldl  
