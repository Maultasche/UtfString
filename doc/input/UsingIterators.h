/*!
\page page_usingiterators Using Iterators In UtfString Classes

\section Introduction to Iterators

In C++, iterators are objects with a particular interface that allow the programmer to visit
each item in a collection.  Iterators behave a lot like pointers in that you can increment,
decrement, and dereference them.  Some iterators are actually implemented as pointers
while others are objects that behave like pointers.

Iterators are used in STL strings to iterator through the characters in that string.  For the
purposes of this tutorial, we are assuming that you are already familiar with STL s trings
and STL iterators.  If you want to learn more about iterators or refresh your memory, you
can read this <a href="http://www.cprogramming.com/tutorial/stl/iterators.html">tutorial</a> 
or search for one of the many other references and tutorials available on the Internet.

\section Using Iterators

%UtfString iterators are used just like std::string iterators.  The only significant difference
is that dereferencing a %UtfString iterator results in a UtfCharReference instance and 
dereferencing a constant %UtfString iterator results in a UtfChar instance.

\code
Utf8String utf8String = "Söß3∑д";

//Iterate through the string
for(Utf8String::iterator stringIterator = utf8String.begin(); stringIterator != utf8String.end();
	++stringIterator)
{
	cout << The current character is << *stringIterator;
}

//Get the third character
Utf8String::iterator stringIterator = utf8String.begin() + 2;
Utf8Char thirdCharacter = *stringIterator;
char codeUnit = (*stringIterator)[0];

//Get the fifth character
stringIterator += 2;
Utf8Char fifthCharacter = *stringIterator;
\endcode

Using the prefix increment and decrement operators (++variable, --variable) in C++ iterators are 
faster, or at the very least the same speed, as the postfix increment and decrement operators
(variable++, variable--).  So if it is irrelevant which one you use, always choose the prefix 
operators.  However, feel free to use the postfix operator when necessary.  It's at least as fast
as doing a prefix increment/decrement and a dereference.
*/