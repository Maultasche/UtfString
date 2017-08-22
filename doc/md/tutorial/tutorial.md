# Tutorial

## Introduction

This tutorial will give you a lesson in how to use the UtfString library as well as providing an
introduction to Unicode and the UTF encodings.

The string classes in the UtfString library are based on the string classes in the C++ Standard
Template Library (STL). This makes it a lot easier for those who are already familiar with those
string classes to use the UtfString library. This tutorial assumes that you are familiar with C++ 
and the STL string classes, so if you aren't already familiar with the STL, find yourself a good
STL book or tutorial.

The interfaces of ```UtfString::Utf8String``` and ```UtfString::Utf16String``` are very 
similar, so most of the tutorial will apply to both.  So When the tutorial mentions a "UtfString", 
it is talking about concepts that apply to both ```UtfString::Utf8String``` and 
```UtfString::Utf16String``` Subsequently, when the tutorial mentions "UtfChar", it is talking 
about concepts that apply to both ```UtfString::Utf8Char``` and 
```UtfString::Utf16Char```. If the tutorial specifically 
mentions a specific class name, the concept applies only to that specific class.

## Tutorial Topics

* [Unicode Overview](unicodeoverview.md) - Gives an overview of Unicode, important	Unicode concepts, and how those concepts relate to the UtfString library
* [Initializing and Assigning Values to a UtfString](initializingassigningutfstring.md) - A guide on how initialize and assign values to a UtfString
* [Using Characters](usingutfchars.md) - A guide on how characters are represented in the UtfString library and how to use them
* [Manipulating Strings](manipulatingstrings.md) - A guide on how to manipulate strings in the UtfString library
* [Using Iterators](usingiterators.md) - A guide on how to use iterators to iterate through strings in the UtfString library
* [Using UnicodeString](unicodestring.md) - An introduction to the UnicodeString class and when to use it
* [Building And Using UtfString](../buildingusingutfstring.md) - A guide on how to build the UtfString library and use it in your applications


[Go to Main Page](/README.md)