#include <windows.h>

#include <iostream>
#include <utfstring/UtfString.h>

using namespace UtfString;

int main(void)
{
	Utf8String utf8String = "Söß3∑д";

	//Note that the output of these cout statements will likely look like nonsense.
	//That's because the terminal/command-line that is handling the output isn't interpreting these
	//characters as UTF-8, but rather as ASCII.
	std::cout << "Söß3∑д" << std::endl;

	std::cout << "The contents of the string: " << utf8String << std::endl;

	Utf8Char utf8Char = utf8String[2];

	std::cout << "The third character of the string is: " << utf8Char << std::endl;

	return 0;
}