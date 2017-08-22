# The UtfString Library

This is a C++ UTF-8 and UTF-16 string library that uses a similar interface to std::string. 
A tutorial and documentation can be found in the doc/html directory. View index.html to see 
the main documentation page.

You'll need the CppUnit library to compile and run the unit tests.

## Introduction

The UtfString Library is a C++ library containing classes to manage Unicode strings, specifically 
UTF-8 and UTF-16 encoded strings. UtfString is intended to be a small, fast library containing 
functionality for storing, converting, and manipulating UTF-8 and UTF-16 strings. UtfString is 
also intended to be a cross-platform library; the library is primarily targeted at Windows, OS X, 
and Linux platforms, but is designed to make it easy to port to other platforms as well. 

The UtfString library came into being because it was very difficult to find a small, standalone, 
cross-platform, and easy-to-use C++ library that handled both UTF-8 and UTF-16 strings. There
were plenty of Unicode string libraries out there, some of them quite good, but they were 
either rather large ([ICU](http://www.icu-project.org/)), tightly coupled with another 
library ([GTKmm](http://www.gtkmm.org/docs/glibmm-2.4/docs/reference/html/classGlib_1_1ustring.html)), 
intended for a single platform (Win32 API), provided an incomplete implementation (UTF-8 only or 
fixed-width UTF-16), or were simply obtuse and difficult to figure out. UtfString was designed to 
solve these issues.

--------
##### Note

Ten years later (2017), the available libraries for manipulating UTF-encoded strings are 
probably a lot different than back in 2007, when I wrote this library. I haven't looked at what's available in a long time,
so look around. Nowadays, it seems that hardly anyone bothers with UTF-16. UTF-8 seems to be the
most common encoding by far. I recommend just using UTF-8; it's simpler that way.

-------

UtfString is not a catch-all solution. It is intended to store, convert, and manipulate UTF-8 and
UTF-16 strings, but it knows nothing about locales or languages. It is unaware of any language- or
locale-specific rules; rather, it is intended to be a language- and locale-neutral Unicode string 
library. When a complete locale- and language-aware solution is required, the [ICU](http://www.icu-project.org/) library would be the best library to use. The ICU
library and all its locale data, however, is comparatively large (around 20 MB), hence the need 
for something smaller for those projects that don't need all that extra functionality. 
UtfString is intended to be small and efficient, able to fulfill most Unicode needs on 
multiple platforms.

The interface for the classes in the UtfString library should be familiar, since it is very similar
to the STL string classes. Most of the functions in the STL string classes also exist in the UtfString
classes. The Utf8String and Utf16String classes allow the user to ignore code units and think in terms
of characters. However, both the Utf8String and Utf16String classes can be cast as STL strings (```std::string``` for
Utf8String and ```std::basic_string<UInt16>``` for Utf16String), so as to make their underlying code units 
easy to access, should the programmer desire that.

A UTF-32 string class has not been implemented by UtfString, since not only is there is currently 
little need for it, there are no existing code points requiring multiple UTF-32 code units, 
resulting in UTF-32 characters always being fixed width. A UTF-32 string class containing 
fixed-width characters would be easy to create, particularly using the C++ Standard 
Template Library's ```basic_string<>``` class.

You can either go from here to look at the [UtfString Class Reference](doc/html/annotated.html), 
or the [UtfString Tutorial](doc/md/tutorial/tutorial.md), which explains in more 
detail how to use this library and gives background information about Unicode and the UTF encodings. 
In addition, you can look at the [Design and Implementation Overview](doc/md/designimploverview.md) 
to read about some of the library design and implementation details.

## Contents

* [Class Reference](doc/html/annotated.html)
* [Tutorial](doc/md/tutorial/tutorial.md)
  1. [Unicode Overview](doc/md/tutorial/unicodeoverview.md) - Gives an overview of Unicode, important
	Unicode concepts, and how those concepts relate to the UtfString library
  2. [Initializing and Assigning Values to a UtfString](doc/md/tutorial/initializingassigningutfstring.md) - A guide on how initialize and assign values to a UtfString
  3. [Using Characters](doc/md/tutorial/usingutfchars.md) - A guide on how characters are represented in the UtfString library and how to use them
  4. [Manipulating Strings](doc/md/tutorial/manipulatingstrings.md) - A guide on how to manipulate strings in the UtfString library
  5. [Using Iterators](doc/md/tutorial/usingiterators.md) - A guide on how to use iterators to iterate through strings in the UtfString library
  6. [Using UnicodeString](doc/md/tutorial/unicodestring.md) - An introduction to the UnicodeString class and when to use it
* [Building and Using UtfString](doc/md/buildingusingutfstring.md)
* [Guidelines to Follow When Using UtfString](doc/md/usingutfstringguidelines.md)
* [Developer's Notes](doc/md/developersnotes.md)

## License

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.