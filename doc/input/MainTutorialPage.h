/*!
\page page_tutorial Tutorial

\section Introduction

This tutorial will give you a lesson in how to use the %UtfString library as well, and provides 
introduction to Unicode and the UTF encodings.

The string classes in the %UtfString library are based on the string classes in the C++ Standard
Template Library (STL). This makes it a lot easier for those who are already familiar with those
string classes to use the %UtfString library. This tutorial assumes that you are familiar with C++ 
and the STL string classes, so if you aren't already familiar with the STL, find yourself a good
STL book or tutorial.

The interfaces of \link UtfString::Utf8String Utf8String \endlink and 
\link UtfString::Utf16String Utf16String \endlink are very similar, so most of the tutorial will 
apply to both.  So When the tutorial mentions a "UtfString", it is talking about concepts that 
apply to both \link UtfString::Utf8String Utf8String \endlink and \link UtfString::Utf16String 
Utf16String \endlink.   Subsequently, when the tutorial mentions "UtfChar", it is talking about 
concepts that apply to both \link UtfString::Utf8Char Utf8Char \endlink and 
\link UtfString::Utf16Char Utf16Char \endlink. If the tutorial specifically 
mentions a specific class name, the concept applies only to that specific class.

\section Tutorial Topics

<ul>
	<li>\ref page_unicodeoverview "Unicode Overview" - Gives an overview of Unicode, important
	Unicode concepts, and how those concepts relate to the %UtfString library</li>
	<li>\ref page_initializingassigningutfstring "Initializing and Assigning Values to a UtfString" - A guide on how initialize and assign values to a %UtfString</li>
	<li>\ref page_usingutfchars "Using Characters" - A guide on how characters are represented in the %UtfString library and how to use them</li>
	<li>\ref page_manipulatingstrings "Manipulating Strings" - A guide on how to manipulate strings in the %UtfString library</li>
	<li>\ref page_usingiterators "Using Iterators" - A guide on how to use iterators to iterate through strings in the %UtfString library</li>
	<li>\ref page_unicodestring "Using UnicodeString" - An introduction to the UnicodeString class and when to use it</li>
	<li>\ref page_buildingusingutfstring "Building And Using UtfString" - A guide on how to build the UtfString library and use it in your applications</li>
</ul>
*/