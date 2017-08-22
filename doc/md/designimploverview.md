# Design and Implementation Overview

UtfString is built on top of the Standard Template Library (STL) string classes.  This is to give
it an efficient, well-established base of code without having to reinvent the wheel. The ```std::string```
and ```std::wstring``` classes are already capable of handling 8-bit or 16-bit code units, but they have
no concept of code points consisting of a variable number of code units. This library provides
the ```Utf8String``` and ```Utf16String``` classes, which extend the functionality of the STL string classes. 
```Utf8String``` and ```Utf16String``` abstract the code units, allowing code points to be accessed 
and manipulated as if they were simple fixed-width characters. This allows the programmer to focus 
on the characters in the string, and not the individual code units.

The only time individual code units are of interest to the programmer when using the UtfString library
is when strings are being converted to and from a collection of code units. For example,
when passing a ```char[]``` array or a ```std::string``` containing code units to the 
constructor of ```Utf8String```, the programmer may have to consider the individual code units 
in that array or string.  Once a ```Utf8String``` or ```Utf16String``` instance has been created, 
however, code units rarely come into consideration. 

The ```Utf8String``` class encapsulates ```std::string```, which is a defined as 
```std::basic_string<char>```.  The encapsulated ```std::string``` class provides the functionality to store and 
manipulate the 8-bit code units, and ```Utf8String``` extends that functionality to allow the programmer to 
deal with code points instead of code units.  The ```Utf16String``` 
class is very similar to the Utf8String class, encapsulating ```std::basic_string<UInt16>```, where 
UInt16 is defined as a 16-bit data type. The reason ```Utf16String``` does not encapsulate 
```std::wstring``` is that ```std::wstring``` is defined as ```std::basic_string<wchar_t>```.  
The problem with ```wchar_t``` is that it may be a 16-bit data type on some platforms, but a 
32-bit data type on other platforms. We want to be sure that the data type we are using to hold a 
UTF-16 code unit is actually 16-bit, so we define the ```UInt16``` data type in the header files, 
with the actual C++ data type depending on which platform it is compiled for.
If the programmer desires, they can get access to a the encapsulated string of code units by casting
a ```Utf8String``` to ```std::string``` or ```Utf16String``` to ```std::basic_string<UInt16>```. 

Originally, ```Utf8String``` and ```Utf16String``` inherited ```std::string``` and 
```std::basic_string<UInt16>```.  That was changed to encapsulation, however, after it was 
discovered that the STL string classes lack virtual destructors. According to the C++ standard, 
the behavior when inheriting a class without a virtual destructor is undefined, which may cause 
apparently random undesirable things to happen.  

In practice, it is fairly common for programmers to inherit classes without virtual destructors, 
and most compilers probably are able to deal with it without resulting in any undesired behavior. 
However, since there are lots of warnings about inheriting STL string classes, and there is a 
small possibility of undesirable behavior, ```Utf8String``` and ```Utf16String``` have been 
redone to use encapsulation instead of inheritance.  

There is almost no difference from an interface perspective: almost all the changes involved internal 
code that is invisible to the users of the classes.  The only change to the interface was to add an 
operator that allowed the UTF string class to be cast to its underlying STL string class, so 
that the user of the class could access the code units.  This "change" wasn't even a noticable 
change, as it preserved the ability to cast to an STL string class that had been present when 
using inheritance.

The UtfString library also contains the ```UnicodeString``` class.
The users of this library may run into situations where it is necessary to pass an encoding-agostic string,
and the code will have no idea ahead of time whether the string it will be using is a UTF-8 or UTF-16 string.
The ```UnicodeString``` class will be very useful in such a situation, as it is an encoding-neutral class.
```UnicodeString``` is really a thin wrapper class that contains either a ```Utf8String``` or a 
```Utf16String``` class, depending what is assigned to it. This class is not intended as a 
general-use string class, but is intended as a class to be used when the programmer has no idea 
what encoding will be used at runtime. Due to the extra level of complexity in the UnicodeString 
class (it needs to call methods on the encapsulated encoding-specific object), the U
```tf8String``` and ```Utf16String``` classes are more efficient. 
