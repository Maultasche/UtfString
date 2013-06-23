/*!
\page page_initializingassigningutfstring Initializing a UtfString

The strings in the %UtfString library have been designed to be as similar as possible to the STL strings.  
As a result, UtfStrings are initialized much like the STL strings.

First of all, a %UtfString can be constructed but not initialized, which creates an empty string

\code
Utf8String utf8String;
Utf16String utf16String;
\endcode

%UtfString constructors accept a variety of commonly-used string data types, including const char*, 
std::string, const wchar_t*, etc.  UtfStrings can be initialized using these data types..  The exact 
data types can be determined by looking at the \link UtfString::Utf8String Utf8String \endlink and 
\link UtfString::Utf16String Utf16String \endlink constructors.  Note that both 
\link UtfString::Utf8String Utf8String \endlink and \link UtfString::Utf16String Utf16String 
\endlink constructors accept accept similar types of strings, but there are small differences 
between them.  \link UtfString::Utf16String Utf16String \endlink constructors, for example,  accept 
more 16-bit string types than \link UtfString::Utf8String Utf8String \endlink constructors, since it 
is much more likely that 16-bit string types will be passed to \link UtfString::Utf16String 
Utf16String \endlink.  Even if you wish to initialize a \link UtfString::Utf8String Utf8String 
\endlink with a more obscure 16-bit string data type, it can easily be done by passing it to a 
\link UtfString::Utf16String Utf16String \endlink constructor and then passing
the \link UtfString::Utf16String Utf16String \endlink instance to \link UtfString::Utf8String 
Utf8String \endlink.

Initialization and assigning are done in pretty much the same way.  The only significant difference
is that the string instance is declared during initialization.

\code
//Example of initialization
Utf8String utf8String = "A string";

//Example of assignment
utf8String = "Another string";
\endcode

Here are some examples of initialization and assignment.  Please read the commentary carefully,
as it may save you from some painful mistakes.

First off, let's start by initializing some strings with an ordinary ASCII string constant.

\code
//Initialize Utf8String using an ordinary ASCII string constant
Utf8String utf8String = "This is a simple string";

//Initialize Utf16String using an ordinary ASCII string constant
Utf16String utf16String = "This is a simple string";
\endcode

After the initialization, both strings will contain the same string, with utf8String storing the 
string as 8-bit UTF-8 code units, and utf16String storing the string as 16-bit UTF-16 code
units.  The encodings are different, but the two strings are equal to each other, since the
Unicode characters  (the code points) are the same.

Now we're going to assign a bunch of Unicode characters that are clearly not ASCII characters
The source file containing this code has to be saved in a format that will preserve the characters, 
such as UTF-8 or UTF-16. If saved in a format that just stores 8-bit ASCII or ANSI characters, 
these characters will be converted in the source file to some other characters that fit in the 
encoding, and the string will be transformed into something different.  So if you use characters
not found in ASCII, make sure that you save the source code file as UTF-8 or UTF-16.

\code
utf8String = "ωE4ڽhъ"
utf16String = "ωE4ڽhъ"
\endcode

The fourth character is some sort of Arabic character that may or may not display properly 
depending on which browser you are using to view this code and what sort of characters your
operating system and/or browser are capable of displaying.  It may be displayed properly
(looks a little like the character "Ü") or it may be displayed as question mark or rectangle.

Note that the string constants in quotations in the code above are 8-bit strings.  If the source 
file containing the code is saved as UTF-8, these strings will be encoded as 8-bit UTF-8 code 
units.  If the source code file is saved as UTF-16, the characters will be preserved in the file 
just fine, but at runtime the 16-bit UTF-16 code units will be shoved into an 8-bit string.  This 
means half of the code unit is going to get chopped off, and the string that results will be 
something very different.

Putting an "L" before the string will force the string constant to be a wide character string,
which is an array of wchar_t in C++.  This will give it enough space to hold an entire 16-bit
code unit. 

The following code works only if the source code file is saved in a UTF-16-encoded file.

\code
//Assign a wide string constant
utf8String = L"Sẫböß3ẫ∑д";
utf16String = L"Sẫböß3ẫ∑д";
\endcode

Some compilers make wchar_t 16-bit and some compilers make wchar_t 32-bit.
For UTF-16 and UTF-8 encodings, the width of wchar_t is irrelevant.  If the string is a
wide string, each 8-bit or 16-bit code unit will be placed in a wchar_t and will fit without
truncation.

\attention
<i>Please note that the source code file must be saved as UTF-8 or UTF-16 if the non-ASCII characters
are to be preserved. Otherwise the bytes that comprise your non-ASCII characters will be interpreted
as ASCII characters, which are sure to be different characters entirely.</i>

The %UtfString library makes the assumption that if it receives a wide character string
(wchar_t* or std::wstring), the wide character string is encoded as UTF-16, as there
is no sense in storing a UTF-8 string in a wide character string.  So if you saving a 
source code file as UTF-8, it is advisable to use an 8-bit character string, " ".  If you are 
saving a source code file as UTF-16, it is advisable to use a wide character string, L" ".

The %UtfString constructors can handle both standard strings and wide strings, so it 
doesn't matter to %UtfString whether the string constant used to initialize a %UtfString
instance is in UTF-8, UTF-16, or ASCII encoding.
<ul>
<li>
ASCII encoding is the most compact, but will only store ASCII characters
</li>
<li>
UTF-8 encoding will preserve all Unicode characters. It is more space-efficient for lower-
valued Unicode characters, such those in European languages.  It is less space-efficient for
higher-valued Unicode characters, such as those in Asian languages.
</li>
<li>
UTF-16 encoding will preserve all Unicode characters. It is less space-efficient for lower-
valued Unicode characters, such those in European languages.  It is more space-efficient for
higher-valued Unicode characters, such as those in Asian languages.
</li>
</ul>

Although the characters typed into a string constant are encoded however the file is encoded,
you can still specify UTF-8 string constants in a UTF-16-encoded source file or UTF-16 string
constants in a UTF-8-encoded files using escape sequences.  In some cases your system might
not be even capable of displaying or inputting more obscure characters at the upper end of
the Unicode character set, so escape sequences might be the only way of specifying the
character in a string.  An escape sequence specifying a code unit looks like '\\xhh'(an 8-bit
code unit) or '\\xhhhh (a 16-bit code unit), where 'h' represents a hexidecimal digit. Escape 
sequences and characters can be mixed together just as with the standard '\\t' or '\\n' escape 
sequences.  

In some cases, it may be necessary to separate the string constants on the same line in order 
to distinguish what is part of an escape sequence and what is not.  For example, if you want
to specify a code unit with the value of 0x34 followed by the string "56", you might type
"\x3456".  The C++ compiler, however, would interpret that as the 16-bit code unit, 0x3456.
In order to indicate what belongs to the escape sequence and what doesn't, you may have to
separate them into string constants separated by a space like so.

\code
Utf8String utf8String = "\x34" "56";
\endcode

The C++ compiler will take those two string constants and put them together like they were one
string constant. Separating characters from escape sequences isn't always required: it's just 
required where a character (usually A-F, 0-9) could be mistaken as part of the escape sequence.

Here's a much lengthier example of strings with escape sequences, which are found in the
%UtfString library unit tests.

\code
//Here is the string constant (UTF-8 assuming the source code file is saved as UTF-8) with 
//mixed characters and escape sequences.  So far, I haven't found any way to input or
//display the four-code-unit UTF-8 code points, which are more obscure characters like
//cuneiform characters,  so I have to specify them using escape sequences.
Utf8String utf8StringWithChars = "\xF0\x92\x81\xA8" "Sẫböß3ẫ∑" "\xF0\x90\x8D\x86д";

//Here is the same string with only UTF-8 code unit escape sequences.  This string can be 
//used to specify a UTF-8 string no matter how the source code file in encoded.
Utf8String utf8String = "\xF0\x92\x81\xA8\x53\xE1\xBA\xAB\x62\xC3\xB6\xC3\x9F\x33\xE1\xBA\xAB\xE2\x88\x91\xF0\x90\x8D\x86\xD0\xB4";

//Here is the same string converted to UTF-16 code unit escape sequences. This string can be 
//used to specify a UTF-16 string no matter how the source code file in encoded.
Utf16String utf16String = L"\xD808\xDC68\x0053\x1EAB\x0062\x00F6\x00DF\x0033\x1EAB\x2211\xD800\xDF46\x0434";
\endcode

Note that the UTF-16 string in the code above is stored using a wide character string constant. The 16-bit code 
units wouldn't fit into a standard string constant.  

In the code above, we didn't have to separate the first two string constants when initializing 
"utf8StringWithChars": the character 'S' could not possibly be mistaken as part of the escape 
sequence '\\xA8'; we just wrote it that way to illustrate how to separate escape sequences from 
characters.

Here are some more example of string assignments

\code
//Utf8String and Utf16String instances can be assigned to each other
Utf8String utf8String = "Sẫböß3ẫ∑д";
Utf16String utf16String = utf8String;
utf8String = utf16String;

//Utf8String and Utf16String instances can be assigned using std::string or std::wstring
std::wstring wideString = L"I am a wide string";
std::string narrowString = "I am a narrow string";

//The std::wstring is assumed to be a string of UTF-16 code units
Utf8String utf8String = wideString;
Utf16String utf16String = wideString;

//The std::string is assumed to be a string of UTF-8 code units
utf8String = narrowString;
utf16String = narrowString;
\endcode

*/