/*! 
\mainpage The UtfString Library

\section section_introduction Introduction

The %UtfString Library is a C++ library containing classes to manage Unicode strings, specifically 
UTF-8 and UTF-16 encoded strings. %UtfString is intended to be a small, fast library containing 
functionality for storing, converting, and manipulating UTF-8 and UTF-16 strings. %UtfString is 
also intended to be a cross-platform library; the library is primarily targeted at Windows, OS X, 
and Linux platforms, but is designed to make it easy to port to other platforms as well. 

The %UtfString library came into being because it was very difficult to find a small, standalone, 
cross-platform, and easy-to-use C++ library that handled both UTF-8 and UTF-16 strings. There
were plenty of Unicode string libraries out there, some of them quite good, but they were 
either rather large (<a href="http://www.icu-project.org/">ICU</a>), tightly coupled with another 
library (<a href="http://www.ogre3d.org/docs/api/html/classOgre_1_1UTFString.html">OGRE</a>, 
<a href="http://www.gtkmm.org/docs/glibmm-2.4/docs/reference/html/classGlib_1_1ustring.html">GTKmm</a>), 
intended for a single platform (Win32 API), provided an incomplete implementation (UTF-8 only or 
fixed-width UTF-16), or were simply obtuse and difficult to figure out. %UtfString was designed to 
solve these issues.

%UtfString is not a catch-all solution. It is intended to store, convert, and manipulate UTF-8 and
UTF-16 strings, but it knows nothing about locales or languages. It is unaware of any language- or
locale-specific rules; rather, it is intended to be a language- and locale-neutral Unicode string 
library. When a complete locale- and language-aware solution is required, the 
<a href="http://www.icu-project.org/">ICU</a> library would be the best library to use. The ICU 
library and all its locale data, however, is comparatively large (around 20 MB), hence the need 
for something smaller for those projects that don't need all that extra functionality. 
%UtfString is intended to be small and efficient, able to fulfill most Unicode needs on 
multiple platforms.

The interface for the classes in the %UtfString library should be familiar, since it is very similar
to the STL string classes. Most of the functions in the STL string classes also exist in the %UtfString
classes. The \link UtfString::Utf8String Utf8String \endlink and \link UtfString::Utf16String 
Utf16String \endlink classes allow the user to ignore code units and think in terms
of characters. However, both the \link UtfString::Utf8String Utf8String \endlink and 
\link UtfString::Utf16String Utf16String \endlink classes can be cast as STL strings (std::string for
Utf8String and std::basic_string<UInt16> Utf16String), so as to make their underlying code units 
easy to access, should the programmer desire that.

A UTF-32 string class has not been implemented by %UtfString, since not only is there is currently 
little need for it, there are no existing code points requiring multiple UTF-32 code units, 
resulting in UTF-32 characters always being fixed width. A UTF-32 string class containing 
fixed-width characters would be easy to create, particularly using the C++ Standard 
Template Library's basic_string<> class.

You can either go from here to look at the %UtfString <a class="el" href="annotated.html">
Class Reference</a>, or the %UtfString \ref page_tutorial "Tutorial", which explains in more 
detail how to use this library and gives background information about Unicode and the UTF encodings. 
In addition, you can look at the \ref page_designimploverview "Design and Implementation Overview" 
to read about some of the library design and implementation details.

\section section_contents Contents

<ul>
<li><a class="el" href="annotated.html">Class Reference</a></li>
<li>
\ref page_tutorial "Tutorial"
	<ul>
	<li>\ref page_unicodeoverview "Unicode Overview" - Gives an overview of Unicode, important
	Unicode concepts, and how those concepts relate to the %UtfString library</li>
	<li>\ref page_initializingassigningutfstring "Initializing and Assigning Values to a UtfString" - A guide on how initialize and assign values to a %UtfString</li>
	<li>\ref page_usingutfchars "Using Characters" - A guide on how characters are represented in the %UtfString library and how to use them</li>
	<li>\ref page_manipulatingstrings "Manipulating Strings" - A guide on how to manipulate strings in the %UtfString library</li>
	<li>\ref page_usingiterators "Using Iterators" - A guide on how to use iterators to iterate through strings in the %UtfString library</li>
	<li>\ref page_unicodestring "Using UnicodeString" - An introduction to the UnicodeString class and when to use it</li>
	</ul>
</li>
<li>\ref page_buildingusingutfstring "Building and Using UtfString"</li>
<li>\ref page_developersnotes "Developer's Notes"</li>
</ul>

\section section_license License

Copyright © 2007 by Kevin Peter.

Permission to use, copy, modify, and distribute this software and its documentation under the terms 
of the GNU Lesser General Public License (LGPL) is hereby granted. No representations are made about 
the suitability of this software for any purpose. It is provided "as is" without express or implied 
warranty. See the <a href="http://www.gnu.org/copyleft/lesser.html">GNU Lesser General Public License</a> 
or the License.txt file accompanying this library for more details. 
*/
