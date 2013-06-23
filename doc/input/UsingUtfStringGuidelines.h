/*!
\page page_usingutfstringguidelines Guidelines to Follow When Using UtfString

<ol>
<li>
When using characters that aren't basic ASCII characters, you must save the source
code file as UTF-8 or UTF-16 to prevent character corruption.  The endianness of a
UTF-16 source code file is irrelevant.
</li>
<li>
When in a source code file saved as UTF-8, use the narrow string constant " " when dealing
with string or character literals.  That ensures that no code units get chopped off or 
misinterpreted as UTF-16.
</li>
<li>
When in a source code file saved as UTF-8, the only time you should use a wide string
constant L" " is when specifically creating a UTF-16 string literal using only 16-bit
escape codes (\\xhhhh).
</li>
<li>
When in a source code file saved as UTF-8, it is easier to simply assign a UTF-8
string constant to a \link UtfString::Utf16String Utf16String \endlink object than to 
create a UTF-16 string literal.  The  conversion to UTF-16 is done automatically.
</li>
<li>
When in a source code file saved as UTF-16, use the wide string constant L" " when dealing
with string or character literals. That ensures that no code units are cut in half and interpreted 
as UTF-8.
</li>
<li>
When in a source code file is saved as UTF-16, the only time you should use a narrow string
constant " " is when specifically creating a UTF-8 string literal using only 8-bit escape
codes (\\xhh).
</li>
<li>
When a source code file is saved as UTF-16, it is easier to simply assign a UTF-16 string 
constant to a \link UtfString::Utf8String Utf8String \endlink object rather than create a UTF-8 
string literal. The conversion to UTF-8 is done automatically.
</li>
</ol>
*/