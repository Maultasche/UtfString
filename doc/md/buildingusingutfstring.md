# Building and Using UtfString

The UtfString library is intended to be built and used on multiple platforms.  The primary 
platforms that this library targets are Windows, Linux, and Mac OS X.  Currently, UtfString
builds on Windows and Linux.  The Linux build could definitely be more robust, as I am still
relatively new to Linux development, but it definitely builds and runs on Ubuntu.  No build 
process has yet been created for Mac OS X, but since OS X is POSIX-compliant, the process 
for building it on Linux will likely work for Mac OS X as well. 

---

##### Note

This build process was established before I had discovered CMake. Nowadays, I would probably just 
use CMake and be done with it. If anyone wants to create a CMake build and submit a pull request,
please do so.

---

If you wish to help improve the UtfString library build process , please see the 
[Developer's Notes](developersnotes.md) for more 
information.

* [Building UtfString on Windows using Visual Studio](#Building-UtfString-on-Windows-using-Visual-Studio)
* [Using UtfString in Your Application on Windows using Visual Studio](#Using-UtfString-in-Your-Application-on-Windows-using-Visual-Studio)
* [Building and Using UtfString on Windows using Dev-C++](#Building-and-Using-UtfString-on-Windows-using-Dev-C++)
* [Building and Using UtfString on Linux on the Command Line](#Building-and-Using-UtfString-on-Linux-on-the-Command-Line)
* [Building and Using UtfString on Mac OS X on the Command Line](#Building-and-Using-UtfString-on-Mac-OS-X-on-the-Command-Line)

## Building UtfString on Windows using Visual Studio

The project and solution files for Visual Studio are located in the build\\win32\\VS* 
subdirectories. There are currently project and solution files for Visual Studio 2005,
2010, and 2012.

To build just the UtfString library, use the UtfString.sln solution.  If you
would like to build the unit tests to verify that UtfString is working for you (recommended),
use the UtfStringUnitTests.sln solution, which builds both the UtfString library and the unit
tests, and allows you to easily run the unit tests.  

---

##### Note To Advanced Users 

If you are already intimately familiar with building C++ libraries under
Visual Studio, you don't need to go through the rest of this section.  To compile the unit tests, 
you need CppUnit.  You should be able to handle the rest on your own.

---

When you have loaded the solution, there should be a be a solution configuration dropdown list
in the toolbar.  If in the unlikely event that it isn't there, you will have to add the toolbar that 
contains it or add it to an existing toolbar through customization.

![The solution configuration dropdown list](../images/vssolutionconfiguration.png)

There are four solution configurations for UtfString.

1. **Debug** - Builds a UtfString dll and export library with debug symbols and no optimization.
Use this configuration when you are using the library as a dll (recommended), and need a
debug-mode library to link against. 
2. **Release** - Builds a UtfString dll and export library with no debug symbols and optimization.
Use this configuration when you are using the library as a dll (recommended), and need a 
release-mode library to link against.
3. **Static Debug** - Builds a static library with debug symbols and no optimization to link against. 
This is not the recommended way of building UtfString, as it creates a huge file containing the 
entire runtime library, resulting in a great deal of unneeded code.
4. **Static Release** - Builds a static library with no debug symbols and optimization to link against. 
This is not the recommended way of building UtfString, as it creates a huge file containing the 
entire runtime library, resulting in a great deal of unneeded code.

When you load the solution, the solution configuration will probably be set to the Debug 
configuration.

Note you will probably want to build UtfString as a dll in Debug and Release mode. First of all,
dlls are nicer and more flexible than static libraries: they are much smaller, are loaded only when
first needed, preventing the executable file from getting too big and using up a bunch of memory 
all at once, and can easily be updated within an application without recompiling the entire 
applications.  Secondly, you will most likely need to use the debug dll when your application is in 
debug mode and the release dll when your application is in release mode. This is not necessary for
some dlls, but it is necessary when building UtfString with Visual Studio, because UtfString 
exports STL classes: when STL classes are exported from the dll, the application needs to use the 
same runtime as the dll.  We'll cover how to set up your application project to do this 
automatically in the following section on using the UtfString library in your application.

If you are building the unit tests (recommended), you must have the Cppunit library available.
Download the [CppUnit Library](https://sourceforge.net/project/showfiles.php?group_id=11795) and 
unzip it to the directory where you put your C++ libraries.  Now find
the Visual C++ 6 workspace, CppUnitLibrary.dsw, under the src directory and double-click on
it.  Allow Visual Studio to convert the Visual C++ 6 workspace to a solution, and build
Cppunit in Debug and Release mode.  After doing this, you should now have the folowing files 
in the CppUnit lib subdirectory: cppunitd_dll.lib, the debug import library, cppunitd_dll.dll,
the debug dynamic library, cppunit_dll.lib, the release import library, and cppunit_dll.dll,
the release dynamic library.

---
##### Note

As of 2017, the CppUnit library appears to have not been maintained in a very long time and
may not even build in Visual Studio anymore. This project could use a more up-to-date 
unit testing framework, such as [Catch](https://github.com/philsquared/Catch), 
[Boost.Test](http://www.boost.org/doc/libs/1_64_0/libs/test/doc/html/index.html), 
or [Doctest](https://github.com/onqtam/doctest). Doctest looks pretty good to me.

---

Now once you have CppUnit built, Visual Studio needs to know where to find the CppUnit
header and library files.  On the "Tools" menu in Visual Studio, select the "Options..."
menu item.  On the popup that appears select the "Projects and Solutions"->"VC++ Directories"
node in the tree on the left.  In the "Show directories for:" dropdown box, select the
"Include Files" option.  Then add the path to Cppunit's include directory to the list below where
the path is [CppUnit Directory]\\include.  This tells Visual Studio to look for include files in
CppUnit's include directory.  Once that is done, select the "Library Files" option in the dropdown
box.  Add the path to CppUnit's lib directory to the list below where the path is 
[CppUnit Directory]\\lib.  This tells Visual Studio that it should look for library files in the
CppUnit's lib directory.  Click the OK button.  This will allow Visual Studio to automatically
find CppUnit include and library files, so that the project does not have to know the exact
path of these files, allowing the project to be used on other machines where the paths will
probably be different.


![Setting the paths to the CppUnit library and header files](../images/vslibrarypaths.png)

The only thing left to do is to copy the CppUnit dlls, cppunitd_dll.dll and cppunit_dll.dll from
the CppUnit lib subdirectory to the UtfString test\\bin subdirectory.  Unless you wish to 
add the CppUnit lib directory to the system path or copy the CppUnit dlls to the system 
directory, this is necessary so that the UtfString unit tests can find the CppUnit dlls 
they need to run.

Now you can finally build the UtfString solution by pressing Ctrl+Shift+B or selecting 
the "Build Solution" menu item.

While building the library as a dll under Windows, it is normal to see a bunch of warnings that
relate to exporting templates.  These warnings relate to the fact that if you use a different
C++ runtime in an application than that of the dll, there could be problems.  However, as long as you
stick to using the debug version of UtfString with the debug builds of your application,
and the release version of UtfString with the release builds of your application,  you won't
have any such problems.

The build should complete, you should be able to find the built library files in the lib 
subdirectory.

The following list indicates the files that should be built for each solution configuration. There
may be some files built that are not listed (incremental linker files, etc.), but we don't 
consider those important in the context of this documentation.


**Debug**

* *UtfStringd.dll* - The debug version of the UtfString library
* *UtfStringd_dll.exp* - The export definitions file for the UtfString dll: this is used to 
resolve linking issues if the export library isn't used.  This file is usually ignored in favor 
of the export library.
* *UtfStringd_dll.lib* - The export library file: linking to this file resolves linking
issues when using the UtfString library as a dll.

**Release**
* *UtfString.dll* - The release version of the UtfString library
* *UtfString_dll.exp* - The export definitions file for the UtfString dll: this is used to 
resolve linking issues if the export library isn't used.  This file is usually ignored in favor 
of the export library.
* *UtfString_dll.lib* - The export library file: linking to this file resolves linking
issues when using the UtfString as a dll.

**Static Debug**
* *UtfStringd.lib* - The debug version of the the UtfString library.  Everything needed
is contained within this library, but it's a rather large file.

**Static Release**

* *UtfString.lib* - The debug version of the the UtfString library.  Everything needed
is contained within this library, but it's a rather large file.


## Using UtfString in Your Application on Windows using Visual Studio

Now that you've built the UtfString library, you can use it in your own application.  This 
section is going to guide you through creating a simple application.

-----
##### Note to Advanced Users

If you are already intimately familiar with using libraries in your
application using Visual Studio, you don't need to go through the rest of this section.  All you 
need to know is that you should define the UTFSTRING_DLL preprocessor symbol in your application 
project when using UtfString as a dll and that you should save your code files as UTF-8 when they 
contain Unicode literals.  You should be able to handle the rest on your own.

-----

In Visual Studio, create an empty C++ console application.  Create a single code file
containing the following code.

```Cpp
#include <iostream>
#include <utfstring/UtfString.h>

using namespace UtfString;

int main(void)
{
	Utf8String utf8String = "Söß3∑д";

	std::cout << "The contents of the string: " << utf8String << endl;

	Utf8Char utf8Char = utf8String[2];

	std::cout << "The third character of the string is: " << utf8Char << endl;

	return 0;
}
```

This code will create a small UTF-8 string, print out the contents of the string, and then retrieve
and print out the third character.  

Make sure that the code file is saved as a UTF-8 text file, by selecting the "File->Advanced Save
Options" menu item, selecting the "Unicode (UTF-8 without signature)" encoding, and clicking the
"OK" button.

Once we have the code, we need to tell Visual Studio where to find the include and library files 
for UtfString.  There are two ways of doing it.  You can put the path to the include and library 
files in the project file or you can add it to the lists of include and library directories.  
Putting the paths in the project has the advantage of not requiring programmers to specify the
paths every time the project is moved to another machine, but the disadvantage is that the 
programmer will probably be forced to change the paths in each project file, since files are 
usually located in different places on different machines.  We use this strategy in the UtfString
unit test project, since all the necessary files are bundled together in the UtfString library 
distribution, allowing us to specify the relative include and library paths with little chance of
them being incorrect.  Any projects external to the UtfString distribution, however, cannot count
on the paths always being the same.  We do not recommend this practice in of your projects.

Adding the include and library paths to the Visual Studio directory lists has the disadvantage of
not moving with the project, but has the advantage of applying to all project built under Visual
Studio.  The path only has to be specified once, and can be used by any project from then on.
We strongly recommend this approach to specifying the include and library paths for your projects.
You will only have to specify them once on a machine, and your projects won't have to worry about
files being in different directories every time someone else loads the project.

To specify the include and library paths in Visual Studio, select the "Tools->Options..." menu item.
In the window that appears, click on the "Project and Solutions->VC++ Directories" item in the
tree on the left.  Then in the "Show directories for" dropdown, select "Include files".  In the
list box below, add the path to the UtfString "include" subdirectory.  Switch to "Library files"
in the drop down, and add the path to the UtfString "lib" subdirectory.  Click the "OK" button.
Visual Studio now knows where to search for the UtfString library and header files.

![Setting the paths to the UtfString library and header files](../images/vslibrarypaths.png)

You have told Visual Studio where to search for the UtfString library and header files.  Visual
Studio will know which header files it needs to find from the \#include statements in the code,
but it does not yet know which library files it is supposed to link.  To indicate which library files
to link, right-click on the application project file and select the "Properties" menu item.  In the
properties window, click on the "Configuration Properties->Linker->Input" item in the tree on the
left.  Then on the right side, under "Additional Dependencies", type in the names of the libraries
to be linked, where the library file names are separated by a space.

![Setting the paths to the UtfString library and header files](../images/vsprojectlibraries.png)

At this point, you'll need to pay close attention to the "Configuration" dropdown in the 
upper-left.  Yours will most likely indicate that it's the debug configuration.  The configuration 
that is currently beung used by Visual Studio to build the solution will appear in the dropdown, 
and will appear as "Active(Configuration)". Setting a property in the property window will only 
set the property for the selected configuration.  This allows us to specify separate settings
for separate configurations.  

So in the Debug configuration in your application, add the UtfString debug library to the 
"Additional Dependencies".  If you are using UtfString as a dll, you will want to link to the
link library, UtfStringd_dll.lib.  If you are using the static library, you will want to link to
UtfStringd.lib.  Now in the configuration dropdown in the upper-left, switch the selected 
configuration to "Release" and add the library to the "Additional Dependencies" for that 
configuration.  If you are using UtfString as a dll, you will want to link to UtfString_dll.lib.
If you are using the static library, you will want to link to UtfString.lib.

If you are using the UtfString dll, you will need to add a preprocessor symbol.  Go to
"Configuration Properties->C/C++->Preprocessor".  In the "Preprocessor Definitions" setting
on the right add the "UTFSTRING_DLL" symbol, making sure that it is separated from the 
others by a semicolon.  Also make sure that WIN32 is defined as well.  This symbol is usually
added when Visual Studio creates the project.  Do this for the Debug and Release configurations.

Now that the properties have been set, click the "OK" button to have the settings take effect.
Build the application in the Debug and Release configurations.  You should be able to build
without errors.  At this point if you are using UtfString as a dll, you will need to make the 
dlls available to the application.  For now, it will probably be easiet to copy the dlls from the
UtfString lib subdirectory and place them in the same place as the application executable.
UtfStringd.dll should be placed alongside the debug executable and UtfString.dll should be
placed alongside the release executable.

Now run the application by pressing Ctrl+F5, which runs the application without debugging. Running
it in this manner pauses the console window, allowing you to see the output.  Running the 
application in debug mode by pressing F5 won't result in the console window pausing, causing it
to disappear before you can see the output.

The console window will most likely be using a language-specific code page instead of the entire 
Unicode character set, so it's likely that some of the characters in the string will be output as
nonsense characters.  You will, however, be able to see if it is running correctly.

## Building and Using UtfString on Windows using Dev-C++

You can build UtfString with Dev-C++ by opening the UtfString.dev project file in the 
build\\win32\\DevCpp subdirectory.  Compile the library and you should find the following files
in the lib subdirectory.

* *libUtfString.a* - This is the link library to use when linking an application that uses UtfString</li>
* *libUtfString.def* - The dll export definitions file</li>
* *UtfString.dll* - The dll containing the UtfString library</li>

That's all there is to it.  You shouldn't get any errors or warnings while building UtfString.  Once
UtfString has been built, you can use it in your application.  Add the include subdirectory to the 
application's include files path and add the lib subdirectory to the application's library files 
path. Include ```<utfstring/UtfString.h>``` in the source file and link to "libUtfString.a", and you 
should be able to use the UtfString classes in your appliation.

## Building and Using UtfString on Linux on the Command Line

The Linux build uses Autotools. Autotools was a pain to set up, but it's easy to use

1. Run ```./configure```
2. Run ```make```

Autotools should take care of building the library for you.

## Building and Using UtfString on Mac OS X on the Command Line

A Mac OS X-specific build process has not yet been created.
However, the library will most likely build if you open a terminal window and follow the Linux
build instructions.
