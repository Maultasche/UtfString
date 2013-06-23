/*!
\page page_unicodestring Using UnicodeString

\link UtfString::UnicodeString UnicodeString \endlink is an encoding-neutral class intended to be used when the
encoding of a string will be only be known at runtime.  Typical situations are developing an encoding-neutral API or
reading from a text file that may be formatted as either UTF-8 or UTF-16. In such situations, UnicodeString is
the class to use.

\link UtfString::UnicodeString UnicodeString \endlink, however, is not intended as a general-use string class to be 
used all throughout your application. \link UtfString::UnicodeString UnicodeString \endlink is really a wrapper class 
that contains an instance of \link UtfString::Utf8String Utf8String \endlink or
\link UtfString::Utf16String Utf16String \endlink, depending on the conditions at runtime.  
As such, it is not as efficient as \link UtfString::Utf8String Utf8String \endlink or 
\link UtfString::Utf16String Utf16String \endlink,
which contain more efficient encoding-specific logic.  \link UtfString::UnicodeString UnicodeString \endlink also 
doesn't offer quite as much functionality as \link UtfString::Utf8String Utf8String \endlink or 
\link UtfString::Utf16String Utf16String \endlink.  Code units, for example cannot cannot be directly retrieved from 
a \link UtfString::UnicodeString UnicodeString \endlink and \link UtfString::UnicodeString UnicodeString \endlink 
functions don't accept string constants.

\link UtfString::UnicodeString UnicodeString \endlink does has string encoding-neutral manipulation functions that 
can be used (appending, removing, substrings,
etc.), but its primary purpose is to enable easy conversion to an encoding-specific format.  As such, it can be
easily cast to a %UtfString encoding-specific class.

\code
//This will give us the same string in UTF-8 and UTF-16 encodings
UnicodeString unicodeString = Utf8String("I'm a string!");
Utf8String utf8String = (Utf8String)unicodeString;
Utf16String utf16String = (Utf16String)unicodeString;
\endcode

\link UtfString::UnicodeString UnicodeString \endlink was designed to work with encoding-specific %UtfString classes
such as \link UtfString::Utf8String Utf8String \endlink and \link UtfString::Utf16String Utf16String \endlink,
and will not work with string constants or classes like std::string or std::wstring.

\code
//Will compile
UnicodeString unicodeString;
unicodeString = Utf8String("I'm a string");
unicodeString = Utf16String(L"I'm a wide string");

//Won't compile
unicodeString = "I'm a string";
unicodeString = L"I'm a wide string";

\endcode

Due to \link UtfString::UnicodeString UnicodeString \endlink being less efficient and less flexible than the 
encoding-specific classes, it is best to use encoding-specific classes whenever practical. It would be wise to 
pick one particular encoding to be used internally in the application or library you are developing, and assign 
the UnicodeString instance to a Utf8String or Utf16String instance as soon as possible.  If you are mainly 
dealing with Latin characters with the occasional Arabic or Chinese characters, UTF-8 would likely be a 
better internal encoding to use.  If you are dealing with a great deal of non-Latin characters, particularly 
those from east-Asian languages, UTF-16 likely be the better internal encoding due to it being more 
memory-efficient with those characters.  When in doubt, go for UTF-8. It has the advantage of being very
memory-efficient with standard ASCII characters and is backward-compatible with code written for ASCII characters.
*/