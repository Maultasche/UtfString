# Manipulating Strings

If you are already familiar with using ```std::string```, you will be very familiar with the member 
functions in a UtfString class.  The member functions in a UtfString class are based on the 
member functions in the std::string class.  They have the same names and do the same things.
The main difference is that the member functions accept a wider variety of data types as 
parameters.

If you aren't already familiar with the ```std::string``` class, the UtfString classes should still
be easy to learn.  Take a look at the ```Utf8String``` and ```Utf16String``` 
[class documentation](../../html/annotated.html).  
Many of the names of themember functions will clearly indicate what they do, and they are all 
well-documented if there you want to know exactly what they do.

In this tutorial, we won't cover each individual function in depth, but we will go over the more
commonly-used functions and functions that don't exist in Utf8String, and discuss how to use them.

The append() function appends a character or another string to the end of a string.

```Cpp
Utf8String utf8String = "Bananas are ";
Utf8String appendString = "delicious!";

utf8String.append(appendString);

assert(utf8String == "Bananas are delicious!");
```

The clear() function completely erases the contents of a string and turns it into an empty string.

```Cpp
Utf8String utf8String = "This is a string that isn't empty";
assert(utf8String.length() > 0);

utf8String.clear();
assert(utf8String.length() == 0);
```

The empty() function indicates whether the string is an empty string or not

```Cpp
Utf8String utf8String = "Bla bla bla";
assert(!utf8String.empty());

utf8String.clear();
assert(utf8String.empty());
```

The erase() function allows you to remove characters within a string

```Cpp
Utf8String utf8String = "I have no money";
utf8String.erase(6, 3);
assert(utf8String == "I have money");
```

The find() function searches within a string for a substring and returns the index where it is 
first found. There also variants of find() that will find the last occurence or search the string 
from the end instead of the beginning.

```Cpp
Utf8String utf8String = "This is a very long string in which we are to search for a substring";

//Search for something that isn't in the string
size_t foundIndex = utf8String.find("monkey");
assert(foundIndex == -1);

//Search for something that is in the string
foundIndex = utf8String.find("long string");
assert(foundIndex == 15);

utf8String = "Söß3∑д"
foundIndex = utf8String.find("∑");
assert(foundIndex == 4);
```

This is_valid() function indicates whether the code units in the string make up a valid Unicode 
string.  Due to the way UTF-8 and UTF-16 are encoded, there are certain sequences of code
units that aren't valid UTF-8 or UTF-16.  This is_valid() function looks for these cases.
If the code units in the string aren't valid, the functions in the string will behave in some
undefined manner, since the functions assume that the string they are looking at is comprised
of valid code units.

```Cpp
//Initialize the string using normal characters
Utf8String utf8String = "Söß3∑д";
assert(utf8String.is_valid());

//Initialize the string using an invalid sequence of code units, as specified by escape sequences
utf8String = "\x88\x22\xF3";
assert(!utf8String.is_valid());
```

If you initialize a string using normal, printable characters and save it as a UTF encoding, the
string will always be valid, because the file encoding will encode it properly.  If you initialize 
a string using a sequence of code units specified by escape sequences, or if you initialize a 
string using a sequence of 8-bit or 16-bit code units obtained from elsewhere (binary file, 
network, memory, etc.), there is a possibility that the code units won't be valid.  We recommend
that you call is_valid() in such cases.  Unless you're validating code units from outside sources,
where validity is always an issue, we recommend that you enclose is_valid() calls in assert() 
statements (see above example), so that they are executed by the debug build, but not in the
release build, resulting in better performance in the release build.

The replace() function allows you to replace part of a string with another string.

```Cpp
Utf8String utf8String = "Söß3∑д";
size_t foundIndex = utf8String.find("∑");
utf8String.replace(foundIndex, 1, "Wow!");

assert(utf8String == "Söß3Wow!д";
```

The substr() functions allow you get retrieve a substring

```Cpp
Utf8String utf8String = "Söß3∑д";
Utf8String subString = utf8String.substr(4, 2);
assert(subString == "∑д");
```

You should be aware that many of the functions expect certain preconditions when they
are called.  The replace() function, for example, is expecting the index of the first character
to be the index of an actual character (index < length()). Most of the functions expect the string
to be valid (is_valid == true).  These expectations are documented 
in the function documentation in the UtfString [Class Reference](../../html/annotated.html). 
The UtfString library expects the programmer to be aware of these.
The UtfString library was designed with performance in mind, so does not check to make sure
these expectations have been met in release builds: it is the programmer's job to make sure
of that it works before release.  To help the programmer catch any mistakes, however, the
UtfString library uses assert() statements to check that these expectations
have been met in the debug build.  Assuming the debug build is thoroughly tested, such programmer 
mistakes should not occur in the release build.  This is a safety vs. performance tradeoff: safety checks are 
emphasized in the debug build where finding errors is more important, but are turned off for the
release build, where performance is more important.

## Operators

The UtfString classes have a number of operators that you will find useful.  First of all,
there are the equality (==) and inequality (!=) operators, which checks whether two strings
have the same code points or not.  It doesn't matter how the string is encoded; a UTF-16
string can have completely different code units than a UTF-8 string, yet both can have the
same code points.

The comparison operators (<, <=, >, >=) compare the code point values of two strings. Each code
point in the Unicode character set has its own value, and the comparison operators will use
those values when comparing strings.  In the English language, this code point value comparison
works out to be the same as alphabetical comparison because of how the letters are arranged
in the Unicode character set.  However, this may or may not be the case in other languages.
For the purposes of being small, the UtfString library contains no locale information.
Note that if locale information is important, you can use the open-source
[ICU](http://www.icu-project.org/) library from IBM, which contains all sorts of
locale information at the cost of being rather large.

The indexing operator ([]) gets or sets characters in the string.  The indexing operators
returns a UtfCharReference, which can be automatically converted into a UtfChar.

The stream operators (<<, >>) allow a UtfString to be read from and output to an STL
stream.  When a UtfString interacts with a stream, it expects to read or write a sequence of
code units.  ```Utf8String``` and ```Utf8Char``` instances can be written to and read from a 
standard stream.  ```Utf16String``` and ```Utf16Char``` instances, on the other hand, 
can be written to and read from both standard streams and wide streams.

The code units string conversion operator (```std::string``` for ```Utf8String``` 
and ```std::basic_string<UInt16>``` for ```Utf16String```) 
converts a UtfString into a string of code units.

## Manipulating Code Units

The underlying code units are hidden by the UtfString classes so that you don't have to worry 
about them.  It is far easier to think about strings of atomic characters than it is to think about
strings of code units where it is much difficult to figure where one character ends and another
character begins.

In most cases you probably won't have to pay attention to code units, since that would defeat the
purpose of the UtfString library.  There may, however, be a reason to look at or manipulate
the code units.  Perhaps you wish to manipulate the code units yourself in a certain circumstance,
or perhaps you need the code units to pass to a function that accepts an array of code units. In 
that case, you can get a string of code units by casting or assigning it to an STL string.

An instance ```Utf8String``` can be cast or assigned to an ```std::string``` and an instance 
of ```Utf16String``` can be cast or assigned to an instance of ```std::basic_string<UInt16>```.

```Cpp
Utf8String utf8String = "Söß3∑д"; 
std::string codeUnitString = utf8String;

assert(utf8String.length() == 6);
assert(utf8String.size() == 11);
assert(codeUnitString == 11);

char* stringPointer = codeUnitString.c_str();
assert(strlen(stringPointer) == 11);
```

Even though you may not be at all interested in manipulating code units, you'll probably find the 
conversion to a code unit string useful for passing the string to non-Unicode aware code that
accepts an array of bytes.  There is a lot of code out there that is intended to deal with 8-bit
ASCII strings that will work just fine with strings of UTF-8 code units.  As long as the code
does not attempt to reorder the code units, a UTF-8 code unit string will most likely do just fine.
Examples of such code include code that stores strings in a file or a hash table, or code that
sends text over the network.  UTF-16 code units strings will likely prove less useful, as there
isn't nearly as much code that deals with 16-bit code unit strings.

Note that changing the code unit string will not change the instance of UtfString from
which it was derived.  The code unit string is merely a copy. A code unit string can of course 
always be assigned to a UtfString by simply assigning the code unit string or passing it as a 
parameter to the constructor.

The code_unit_index() and code_point_index() functions are useful if you are dealing with
code unit strings.  If you have a string of code units that comprise a UtfString you can
map code units to code points.  The code_unit_index() function takes the index of a code point
(character) in the UtfString and returns the index in the code unit string where the first code 
unit of that code point is located.  The code_point_index() takes the index of a code unit in the
code unit string and returns the index of the corresponding code point. These functions make
it much easier to work with a string of code units, providing you have the corresponding 
UtfString.
