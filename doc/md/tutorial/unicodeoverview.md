# Unicode Overview

Originally, computers were only capable of displaying basic characters from Western European languages.
The most popular character set was the ASCII character set, where each character had a corresponding number.
There are 128 characters defined by basic ASCII. Not all of these characters are printable: some are 
control characters for a teletype such as a line feed or null terminator, or are characters intended to 
produce a sound, like the bell character.

In addition, there are several different types of extended ASCII character sets, which include some other
Western European characters, symbols, and line/box characters, allowing there to be 256 different ASCII 
characters.  ASCII characters take up 8-bits (7-bits for basic ASCII), which was very nice for the computers
at the time, which had limited memory and storage capacity.

Eventually, however, the need developed for displaying characters found in other languages as well. 
This led to the development of multi-byte character encodings and code pages. Characters would be 
represented by one or two bytes, where the meaning of those bytes depended on the current code page. 
The number 0xA2 might represent one particular character on an English code page, but a completely 
different character when using a Russian code page. This type of arrangement might be fine if the user 
only used one language and exchanged documents with other people who used the same language, but 
combining multiple languages or sending a document in one language to someone who used another language 
and a different code page would result in a completely unreadable document.

To solve this problem, the Unicode Consortium was founded, which worked for many years to come up with a
standard character set including all the characters that would ever possibly be needed all around the world.
So today we have the Unicode standard, which includes a character set containing all commonly-used characters
used in the world.  The first 128 Unicode characters are exactly the same as ASCII.  For example, the letter
'g' is 0x67 and the number '8' is 0x38.  From there, we find characters from other languages and scripts,
going all the way up to 0x10FFFF.  The characters in the Cyrillic alphabet, used in some Eastern European
languages, range from 0x401 to 0x4E9.  Most characters from Eastern Asian languages are found in the upper
range of the character set. This standardized encoding system allows documents to be created using a 
tremendous variety of characters and read by any application that supports Unicode, no matter which 
language the operating system is set to.

At this point, we should introduce a number of important concepts that are important to understanding
Unicode and the UtfString library.

* **Character** - A character is somewhat of an abstract concept. It's a symbol that is used to
    visually represent information. In western European languages, a character represents a sound, whereas
    in many eastern Asian languages, a character represents a thing or idea. Characters can appear in
    multiple languages.  An 'ö' character is represented in a common version of
    extended ASCII by the number "0x94", but is represented in the Unicode by the number "0xF6".

    In UtfString, only the Unicode character set is used. Since a particular character is always represented
    by the same number in Unicode, the number representing a character is often referred to the 
    UtfString documentation as a "character" or a "code point" interchangeably.

* **Code Point** - Whereas a character is a more abstract concept, the code point is name for the specific
    number representing a character.  The 'A' character for example is represented by the 0x41 code point.

    In UtfString, only the Unicode character set is used. Since a particular character is always represented
    by the same number in Unicode, the number representing a character is often referred to the 
    UtfString documentation as a "character" or a "code point" interchangeably.

* **Glyph** - A glyph is the visual representation of a character as drawn on a screen or printed on 
    paper. In many languages, a character is always represented by the same glyph. An 'A' character is always
    represented (unless the font is really wierd) by two slanted lines with a horizontal line in the middle.
    In some languages, such as Arabic, it is common to have two characters merge into one glyph when placed
    next to each other.  They might appear as two glyphs when separated, but are represented by one glyph
    when next to each other. It's good to keep in mind when displaying text on a screen that characters 
    aren't always the same as glyphs.

    Since UtfString does not concern itself with displaying characters, glyphs are absolutely irrelavant
    the context of the library. The string classes in UtfString deal with characters the same way, no matter 
    how they appear on the screen or on paper.

* **Encoding** - Each code point in the Unicode character set can be stored in many different ways
    when storing a Unicode string in memory.  The scheme that is used to store a Unicode string is known
    as an encoding. The easiest way to encode a Unicode string is to store the value of each code point
    into a 32-bit character and store the 32-bit characters in a string. This encoding (known as UCS-4 or
    UTF-32) results in a large amound of memory being wasted, since no code point will ever make use of
    all 32 bits, and many Latin characters only require 8 bits.  As a result of this obvious inefficiency,
    the UTF-8 and UTF-16 encodings were invented to make more efficient use of memory.

    UtfString provides classes that encode Unicode strings as UTF-8 and UTF-16, with functionality for
    converting between the two encodings.

* **Code Unit** - A code unit is the smallest individual piece of data used in an encoding. The UTF-8 
    encoding, for example, uses a sequence of 8-bit code units to encode a code point.  One code point 
    might be encoded as only one code unit (1 byte) whereas another code point might be encoded as 3 code 
    units (3 bytes). The UTF-16 encoding uses 16-bit code units to encode Unicode code points.

    In UtfString, each string class stores code units representing the code points internally, but abstracts
    them so that the programmer using UtfString mainly deals with code points instead of having to manipulate
    code units. ```UtfString::Utf8String``` contains a series of 8-bit code units, 
    and does all the work of turning those code units into code points.  
    ```UtfString::Utf16String``` has the same interface, but stores the code points 
    internally as 16-bit code units.

* **UTF-16** - This encoding uses 16-bit code units, and is the most efficient use of memory if 
    a Unicode string contains mostly characters from toward the upper end of the Unicode range. 
    Code points 0x0000 - 0xFFFF are encoded using one 16-bit code unit, and code points 0x10000 - 0x10FFFF 
    are encoded are encoded using two 16-bit code units. Code points that are encoded as two code units in 
    UTF-16 are uncommon, as code points in that range represent primarily Asian characters,
    obscure scripts such as cuneiform, really code points that represent things like emojis.

    UtfString provides the ```UtfString::Utf16String`` class for storing and 
    manipulating UTF-16 strings.

    For more detail, see the Wikipedia article on UTF-16.

* **UTF-8** - This encoding uses 8-bit code units, and is the most efficient use of memory if
    a Unicode string contains mostly characters from the Latin script. Code points 0x00 - 0x7F are encoded
    using one 8-bit code unit, code points 0x80 - 0x7FF are encoded using two 8-bit code units, 
    code points 0x800 - 0xFFFF are encoded as three 8-bit code units, and code points 0x100000 - 0x10FFFF
    are encoded as four 8-bit code units.  

    The disadvantage of this encoding scheme is code points take up more space on average than with the 
    UTF-16 encoding, that that's assuming the code points being used are evenly distributed. In practice,
    the code points being used tend to be mostly from the lower-end of the code point spectrum.

    The advantages of UTF-8, however, usually outweigh the disadvantages. One advantage of the UTF-8 encoding 
    is that low-numbered code points,  especially basic Latin script characters, only use a single code unit. 
    If most of the characters in a string are expected to be A-Z letters and numbers, then UTF-8 is definitely the way
    to go. 

    Another strong advantage is that UTF-8 provides backward compatibility with a great deal of code.
    A lot of code written to deal with strings was either written before Unicode was standardized or was written
    to only handle 8-bit ASCII characters. Such code usually expects an array of bytes.  UTF-8 strings can 
    safely used by some of this code, as UTF-8 strings are also just a series of bytes. If the code attempts 
    to manipulate the string, then it is possible (depending on what exactly the code is doing) that a 
    UTF-8 string may get messed up, but if the string is just 
    being passed along, output somewhere, or isn't altered in any way, then the UTF-8 string will 
    survive untouched.  UTF-16 strings on the other hand may run into byte-order issues, and are 
    much more unlikely to survive being converted into an array of bytes and used by code intended
    for ASCII characters.  

    Another advantage regarding the backward compatibility of UTF-8 strings is that the first 128 code points 
    (0x00 - 0x7F) are the same code points that are in the basic ASCII character set, and are also encoded 
    as 1-byte code units.  This means that a UTF-8 string including only basic-Latin characters is
    indistinguishable from an ASCII string, so UTF-8 strings consisting entirely of one-code-unit characters
    can safely be passed to any code that accepts an ASCII string, even if that code alters the string.
    The opposite is also true: ASCII strings containing only basic ASCII characters can also safely be passed 
    to code that is expecting a UTF-8 string.  This makes it a lot easier to internationalize applications
    that only deal with ASCII strings and allows ASCII and UTF-8 functionality to be more easily integrated.

    As of 2017, ten years after this library was originally written, UTF-8 has become the most widely 
    used encoding by far. Most software that deals with strings now standardizes on the UTF-8 encoding.

    UtfString provides the ```UtfString::Utf8String``` class for storing and manipulating
    UTF-8 strings.

* **Byte Order Marker** - Byte order is the order that a processor puts the bytes in when it is dealing
    with a multi-byte data type, such as a 16- or 32-bit data type. Some processors put the high bits of
    the data type into the first byte and other processors put the low bits of the data type into the first
    byte. These two byte orders are known as little endian and big endian.

    When transmitting encoded Unicode text, the text may end up on a machine using a different byte order
    than the machine that created it.  This creates a need to insert a byte order marker (BOM) at the beginning
    of text encoded as UTF-16 or UTF-32 (but not necessarily UTF-8, since that uses a 1-byte data type).

    UtfString is written in C++, which abstracts byte order for data types (unless you're doing something
    funky like getting a char* pointer to an int and examining each byte individually).  This means that anyone who uses
    UtfString won't have to worry about byte order while storing and manipulating strings in memory. Byte
    order, however, may become an issue if a UTF-16 string is transferred to another machine, either directly
    over the network or by saving it to a file and transferring the file to another machine. So when
    transferring a UTF-16 string over the network or saving it to a file, it is best to prepend a BOM to the
    beginning of the file or the byte transfer over the network.  Byte order markers tend to range from 2 to 
    4 bytes, depending on the encoding, and are usually placed at the beginning of files to make it clear the 
    encoding the file uses.

    Another use for a BOM is not only identifying a byte order, but also identifying the encoding, even if
    byte order doesn't matter for the encoding. Although UTF-8 doesn't require a BOM, because there are no byte order 
    issues involved, there is a UTF-8 BOM that can be placed at the beginning of a UTF-8 file. The reason
    for this is that if an application reads a file, it might not automatically know that the file contains
    UTF-8 encoded text. The text might be interpreted as ASCII text, which would make it look very strange
    when displayed if there are any encoded code points above 0x7F. In order to make it clear that the text 
    is encoded as UTF-8, the BOM is placed at the beginning of the file. Note that if an application is not
    aware of the UTF-8 encoding (or wasn't coded to handle a BOM), it will probably attempt to interpret the
    BOM as text.

    UtfString will never insert byte order markers automatically, since it can't know when it is 
    appropriate to do so. However, it provides BOM constants for you to use when it is necessary.  The BOMs for
    UTF-8, UTF-16, and UTF-32 are defined by the ```UtfString::UtfBOM``` enumeration.

    Before inserting a BOM that depends on endianness (UTF-16, UTF-32), make sure you know the endianness
    of the machine the code is compiled on.  If the code is intended to be compiled on different types
    of machines, it is best to use preprocessor definitions to determine the machine type. Intel, AMD, 
    and compatible processors are all big-endian, and are used by Windows machines, most Linux machines, 
    and modern Mac OS X machines.  
    Motorola PPC processors, used by older Macs and a few Linux machines, are little-endian.

* **Language** - This is a particular language that is spoken or written. Some languages share all their
    characters with other languages (English), some languages use characters only in that language (Thai), and 
    many languages have mix of shared characters and some characters only found in that language (Turkish).
    UtfString does not know or care about languages, so you will not need to worry about languages when 
    passing data to UtfString.

* **Script** - This is a set of characters used by one or more languages.  Examples include Latin script,
    Cyrillic script, and Tamil script. UtfString does not care about particular scripts: any Unicode character
    can be used in a UtfString string class.

* **Locale** - This is a combination of language and geographical location.  Geographical locations can
    contain multiple languages (Belgium, Switzerland, Ireland, United States, etc.) and languages can be found in
    multiple geographic locations (Russian, English, Spanish, etc.). The locale affects which language is used,
    the spelling standards of that language, punctuation, script, date/time formatting, currency formatting, etc.
    For example, the "United States - English" and "United States - Spanish" locales have the same geographic 
    location, which affects things like currency formatting, but different languages, which affect things like
    spelling and punctuation.  The "United States - English" and "UK - English" locales are just the opposite:
    they share similar language characteristics with more subtle spelling differences, but completely 
    different geographical locations.  With some languages, such as Serbo-Croatian, the language may be written
    using one script in one country, but a completely different script in another country.

    UtfString is not locale-aware. It does everything according to the 
    Unicode character set. Comparing and sorting strings are done by the Unicode character values, and not 
    by any locale-specific rules. This works just fine in all English-speaking locales, but may not work 
    properly for other locales such as Danish-speaking locales. If locale-specific rules are important to you, 
    then the more extensive (and much larger) [ICU](http://www.icu-project.org/) library 
    would be more suitable.


Since UtfString only deals with the character set defined by Unicode, the UtfString documentation uses
the terms "character" and "code point" interchangeably. From UtfString's perspective, they are the same 
thing.

Further information about Unicode can be found at the official [Unicode website](http://www.unicode.org).

[Go to Tutorial](tutorial.md)

[Go to Main Page](/README.md)