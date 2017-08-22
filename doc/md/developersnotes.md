# Developer's Notes

The developer's notes is a section where I discuss issues surrounding the UtfString project and 
any issues you may encounter while making changes to the UtfString library.

## Cross-Platform Functionality

The UtfString library is intended to be a cross-platform library.  I'm currently only interested in 
developing for Windows, Linux, and Mac OS X, but UtfString will likely be able to run
on other platforms as well.  If you would like submit any contributions so that UtfString
will build and run on other platforms, or even test how well UtfString works on a particular
platform, please do so.  See the section on [contributing](#Contributing-to-UtfString) to the 
UtfString project.

### Windows - Visual Studio
 
Although nowadays my main development machine is a Mac, back when I developed this library in 2007, 
I primarily developed on Windows with Visual Studio, so that is the compiler and platform that has 
the most support.

### Windows - Dev-C++
 
Since I have little experience with Dev-C++ and I do not use it to develop, UtfString has very
little testing on this IDE.  Since Dev-C++ uses MinGW, which is based on the gcc compiler, and 
I've been been able to successfully build and test UtfString on Linux using gcc, it's quite 
likely that UtfString will work just fine when compiled with MinGW and any IDE that uses
MinGW.
 
I welcome any feedback about anyone who is using UtfString and developing with Dev-C++
as well as [contributing](#Contributing-to-UtfString) to the build and usage instructions in 
this documentation.
 
### Windows - MinGW
 
Although I have used gcc on Unix-type operating systems, I have no experience using MinGW under
Windows.  If anyone would like to set up a MinGW build environment and [contributing](#Contributing-to-UtfString)
to this project, I would appreciate it.
 
### Linux - Autotools
 
I've written makefiles and developed smaller programs with gcc as the compiler on 
Unix-type operating systems in the past, so I'm familiar with developing on non-Windows
platforms. However, before I started this project, I had never developed on Linux, and I was not 
at all familiar with the GNU autotools (autoconf and automake), which are used to build many of 
the libraries and applications on Linux.  Once I had UtfString building under Windows, I set 
out to get UtfString working on Linux using autoconf and automake.
 
It took quite a lot of time to figure out enough to get UtfString building with the autotools
(good tutorials are hard to find), but I finally succeeded.  There is very little information 
about standards for Linux development (if indeed there are any), so I'm not entirely sure that
I'm doing it correctly.  Currently, the autotools will create a makefile that builds UtfString
with debug symbols (there appears to be no way around that).  Installing the built library using 
the standard "make install" installs it with debug symbols.  The user has to explicitly install 
using "make install-strip" to install the library without debug symbols.  Ideally, I would like 
to have the default use no debug symbols and add an option to include debug symbols when 
someone is using the library for  development.  I haven't been able to figure how to do this 
and I don't if installing libraries with debug symbols is the standard way of installing or not.
 
In addition, I still need to create some autoconf macros so that developers can easily add
UtfString to their projects.  I have a feeling that this is not going to be easy, since I am
not at all familiar with M4 or the available environment variables.
 
I would really appreciate it if any of you more experienced Linux developers gave me
feedback on the Linux build process or made any [contributing](#Contributing-to-UtfString)
to the Linux build process.
 
### Mac OS X - Autotools
 
Presumably, UtfString will build just as well as under Mac OS X using the GNU autotools
as under Linux, but I haven't tested it

## Mac OS X - XCode
 
I had planned to eventually get UtfString working with XCode, but this has not yet been 
done.

### CMake

I was unaware of CMake when originally developing this library. Nowadays this would probably
be my choice of build tools for C++. Anyone is welcome to [contribute](#Contributing-to-UtfString) 
CMake build files.

## Development Issues

In this section, we cover issues you may encounter when making changes or additions to the
UtfString code.

When making changes to UtfString, I strongly recommend that you use the UtfString unit tests
that are included with the library.  You can change the tests to test any changes or additions
you made, which is very useful for finding bugs in the code.  The unit tests, however, are only
as good as the effort you put into it.  Lazy test code will probably not catch as many errors as 
well-thought-out test code.  It's best to try to consider the different ways it may possibly fail
and test for those even though you know the tests will pass.  You should also be aware that you 
are not only testing for changes now, but changes in the future.  Your functionality may work
just fine now, but future changes may cause it to fail. So it may not be possible that the
functionality you implemented fails now in a particular way, but changes in the future may
cause it to fail, even changes in seemingly unrelated parts of the library.

Tests are only written once, and run many times.  This makes it very easy to not only test the
functionality you are working on, but to run regression tests on all the functionality that you
aren't working on.  You may find that a change makes your functionality work, but breaks 
something that was previously working just fine.

If you are using the UtfString unit test solution in Visual Studio (although this may possibly
apply to other build environments and platforms), you will need to be aware of behavior that
may cause confusion.  The UtfStringUnitTests project has a post-build step that copies the
UtfString dll into the test/bin directory so that the unit tests can be run.  This build step,
however, only happens when the unit tests need to be built.  If you have made a code change 
to the UtfString library, but you haven't made any changes to the unit test code, you will
not see the new changes when running the unit tests.  The unit test project will see that it 
hasn't been updated, so it won't build.  If the unit test project doesn't build, it won't run the
build step that copies the dll into the test/bin directory.  I solve this problem by rebuilding
both the library and unit tests project ("Rebuild Solution" in Visual Studio).  This forces the
post-build step to be run.  This is convenient for me because rebuilding both projects is fast.
If this is too slow for you, you may want to do something like creating a script to copy the
dll to the test/bin directory.

## Future Fixes and Improvements

These are the things that I am considering fixing or improving in UtfString

* Improve the Linux and Mac build process by implementing CMake
* Create packages for easy deployment of UtfString on Linux

## Contributing to UtfString

I welcome contributions to this project.  Currently, I need people to use UtfString for their
own projects and let me know how it is working for them. Bug reports and suggested improvements
are welcome.  Build system improvements (CMake anyone?) or especially welcome as is
assistance on building an rpm or Debian package.

[Go to Main Page](/README.md)