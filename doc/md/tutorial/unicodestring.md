# Using UnicodeString

```UnicodeString``` is an encoding-neutral class intended to be used when the
encoding of a string will be only be known at runtime.  Typical situations are developing an encoding-neutral API or
reading from a text file that may be formatted as either UTF-8 or UTF-16. In such situations, UnicodeString is
the class to use.

```UnicodeString```, however, is not intended as a general-use string class to be 
used all throughout your application. ```UnicodeString``` is really a wrapper class 
that contains an instance of ```Utf8String``` or```Utf16String```, depending on the conditions at 
runtime.  As such, it is not as efficient as ```Utf8String``` or ```Utf16String```,
which contain more efficient encoding-specific logic.  ```UnicodeString``` also 
doesn't offer quite as much functionality as ```Utf8String``` or 
```Utf16String```.  Code units, for example cannot cannot be directly retrieved from 
a ```UnicodeString``` and ```UnicodeString``` functions do not accept string constants.

```UnicodeString``` does has string encoding-neutral manipulation functions that 
can be used (appending, removing, substrings, etc.), but its primary purpose is to enable easy 
conversion to an encoding-specific format.  As such, it can be easily cast to a UtfString 
encoding-specific class.

```Cpp
//This will give us the same string in UTF-8 and UTF-16 encodings
UnicodeString unicodeString = Utf8String("I'm a string!");
Utf8String utf8String = (Utf8String)unicodeString;
Utf16String utf16String = (Utf16String)unicodeString;
```

```UnicodeString``` was designed to work with encoding-specific UtfString classes
such as ```Utf8String``` and ```Utf16String```,
and will not work with string constants or classes like ```std::string``` or ```std::wstring```.

```Cpp
//Will compile
UnicodeString unicodeString;
unicodeString = Utf8String("I'm a string");
unicodeString = Utf16String(L"I'm a wide string");

//Won't compile
unicodeString = "I'm a string";
unicodeString = L"I'm a wide string";

```

Due to ```UnicodeString``` being less efficient and less flexible than the 
encoding-specific classes, it is best to use encoding-specific classes whenever practical. It would be wise to 
pick one particular encoding to be used internally in the application or library you are developing, and assign 
the UnicodeString instance to a Utf8String or Utf16String instance as soon as possible.  When in doubt, go for UTF-8. It has the advantage of being very
memory-efficient with standard ASCII characters and is backward-compatible with code written for ASCII characters.

Most software uses UTF-8 as the internal encoding.

[Go to Tutorial](tutorial.md)

[Go to Main Page](/README.md)