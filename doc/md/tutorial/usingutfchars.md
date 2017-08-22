# Using Characters

## Introduction to Characters in UtfString

A character is simply a series of code units that encode a character, also known as a code point.
An character encoded in ASCII always consists of a single 8-bit code unit.  A character encoded
in UTF-16 consists of one or two 16-bit code units, whereas the same character encoded as UTF-8
consists of between one and four 8-bit code units.

The UtfString library does the hard work of dealing with characters encoded as a variable number
of code units, allowing you to deal with much simpler string ofcharacters.  UtfString hides
the code units when dealing with an entire string by encapsulating them in string classes.  
However, you will certainly most need to look at or change individual characters.  UtfString makes
it easier to deal with individual characters by encapsulating the code units that encode that 
character inside the UtfChar classes.

## UtfChar

Much like the ```Utf8String``` and ```Utf16String``` classes, there are two types of character classes,
```Utf8Char``` and ```Utf16Char```, which are very similar to each other.

Like a UtfString, a UtfChar can be created as an empty instance using the default constructor,
or can be initialized using a series of code units.  As with UtfString initialization, characters
can be initialized using string constants, " " and L" ", and with one-code-unit characters, can 
be initialized using character constants, ' ' and L' '.  

Be careful with using character constants!  They can only contain a single code unit.  If you
put a multi-code-unit character such as 'д' (assuming source code file is saved as UTF-8),
only the first code unit will be assigned an the second code unit will be chopped off.  Also, 
like with string constants, the code units inside the character constants depend on how the
source code file is saved. The character constant 'д' will have two code units if 
the source code file is saved as UTF-8, resulting in one code unit being left off.  That 
same constant will also result in problems if saved as UTF-16 because only the first
byte of the 16-bit code unit will be used, resulting in a completely different character.

The wide character constant L'д' will result in problems when the source code file
is saved as UTF-8 because although both UTF-8 code units will fit, the UtfString classes
will be expecting it to be a single UTF-16 code unit, resulting in an entirely different
character.  That same wide constant will work just fine when the source code file is
saved as UTF-16 because that character is encoded as a single code unit.

So as you can see, using character constants is complex because you have to pay 
attention to the nature of the character (one code unit or more?), the encoding of
the source code file (UTF-8 or UTF-16?), and the type of character constant
(narrow or wide?). To make your life easier, we recommend that you always use
string constants, even for characters, and that you follow the guidelines mentioned
in the [Guidelines to Follow When Using UtfString](../usingsutfstringguidelines.md).

```Cpp
//Create an empty UTF-8 character
Utf8Char utf8Character;

//Initialize a UTF-16 character with a character constant
//In this case we know that it is a one-code-unit character, but in all but the most
//obvious characters (basic ASCII), a string literal " " should be used instead.
Utf16Char utf16Character = 'A';

//Assign to a UTF-8 character using a character constant.  Note that this character is
//only represented as a single character on the screen, but assuming the source code
//file is saved as UTF-8, multiple code units will be assigned.
utf8Character = "д";

//Now assign the same thing to Utf16Char. 
utf16Character = "д";

//We can also specify the code units using escape sequences
utf8Character = "\x84\xD8";

//This particular assignment requires a wide character string constant since we are specifying 
//a 16-bit code unit
utf16Character = L"\x2A47";
```

If you should assign a character a string constant containing more than one character, 
the first character will be used and the rest ignored.

Character comparison works similarly, where a UtfChar can be compared to another UtfChar
or a string constant.  If a ```Utf8Char``` is compared to a 
```Utf16Char```, the comparison is done on the code point value 
of the characters and not on the individual code units.

```Cpp
Utf8Char utf8Character = "O";
utf16Char utf16Character = "O";

if(utf8Character == utf16Character)
{

}
```

Individual code units in a UtfChar can be retrieved and set using the indexing operator, "[]".
This allows you fine control over the individual code units in a character, should you choose
to do so.

```Cpp
//Initialize a UTF-8 string
Utf8Char utf8Character = "\x91\x88\xA8";

//Get the second code unit
char codeUnit = utf8Character[1];

//Set the second code unit. Since an individual code unit is a represented by a char data type,
//we use a character constant, ' '.
utf8Character[1] = '\x94';
```

The most useful thing about characters is that you can extract them from a string.  If you
want to find the second character in a UtfString, just use the UtfString indexing operator,
[], to get a particular character in the string.

```Cpp
//Get the second character in a string
Utf8String utf8String = "Monkey";
Utf8Char utf8Character = utf8String[1];

//You can also compare a character returned from the indexer with a string literal
if(utf8String[3] == "n")
{

}
```

## UtfCharReference

A UtfChar object is completely separate from everything else: changing the value of a UtfChar 
object will only change that object and have no effect anywhere else.  This is generally a good
thing, but it can cause problems in certain circumstances.

For example, the following code sets the value of a character in a string.

```Cpp
Utf8String utf8String = "Happy Times";
utf8String[3] = "T";
```

This is done through the use of the indexer operator [] in ```Utf8String```.  If the indexer 
operator returned a ```Utf8Char``` object, getting the character would be just fine, but 
setting the character would cause unexpected behavior.  The indexer would return a temporary 
```Utf8Char``` object, whose value would then be set.  The temporary object would then be 
subsequently destroyed.  It would appear to the programmer that the character inside the string 
was being set, but in reality the string would remain 
unchanged, as it was really the value of a temporary object that was being set.

The STL string classes solve this problem by returning a reference to a character.  Since
we encapsulate the code units inside a UtfChar and code units inside a UtfString are
stored in a STL string instance, we can't simply return a reference: encapsulation would
be broken, making it difficult to assign a UtfChar object, and would require detailed knowledge of 
how code units work, completely defeating the purpose of this library.  So what we do is
return an instance of a class called ```UtfCharReference``` instead of ```Utf8Char``` and 
```Utf16CharReference``` instead of ```Utf16Char```. These reference classes represent a reference 
to a character inside a string.  A UtfCharReference has a very similar interface and in most cases can be
used just like a UtfChar.  The difference is that changing the value of a UtfChar just changes
that object, but changing a UtfCharReference causes the code units inside the string to be
changed.

Since UtfCharReference has a very similar interface to UtfChar and has a conversion operator
for automatic conversion to UtfChar, it will often remain unnoticed that you are using a 
reference class.  The following code works without ever seeing an explicit reference to
the ``Utf8CharReference`` class. Since the Utf8String indexing operator returns
a temporary ```Utf8CharReference``` object, it is then
in turn converted automatically to a ```Utf8Char``` via the 
Utf8CharReference's Utf8Char conversion operator.

```Cpp
Utf8String utf8String = "Happy Times";
Utf8Char character = utf8String[3];
```

The code example earlier in this page where a character 
is being set in a string works because the temporary ```Utf8CharReference``` object returned 
by the indexing operator is assigned the new character value, causing the contents of the 
string to change.

The number of code units in a UtfChar can be retrieved via the size() function.
The individual code units in a UtfChar can be accessed through the [] indexing operator.

```Cpp
//Get a character from a string and look at the first code unit
Utf8String utf8String = "Pine Tree";
Utf8Char utf8Char = utf8String[4];
char codeUnit = '\0';

if(utf8Char.size() > 0)
{
    codeUnit = utf8Char[0];
}	

assert(codeUnit = ' ');

//Set the first code unit in the fifth character
utf8String[4][0] = 'A';

assert(utf8String == "PineATree");
```

[Go to Tutorial](tutorial.md)

[Go to Main Page](/README.md)