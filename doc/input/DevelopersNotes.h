/*!
\page page_developersnotes Developer's Notes

The developer's notes is a section where I discuss issues surrounding the %UtfString project and 
any issues you may encounter while making changes to the %UtfString library.

\section section_crossplatform Cross-Platform Functionality

The %UtfString library is intended to be a cross-platform library.  I'm only interested in 
developing for Windows, Linux, and Mac OS X, but %UtfString will likely be able to run
on other platforms as well.  If you would like submit any contributions so that %UtfString
will build and run on other platforms, or even test how well %UtfString works on a particular
platform, please do so.  See the section on \ref section_contributing "contributing to the
 %UtfString project".

 <b>Windows - Visual Studio 2005</b>
 
 The majority of my experience has been developing on Visual Studio under Windows, so that
 is the compiler and platform that has the most support.
 
 <b>Windows - Visual Studio 2003 and .NET</b>
 
 You should be able to build %UtfString under Visual Studio 2003 and .NET 
 ( using <a href="http://www.stlport.org/" STLPort</a>) in a similar manner as when building
 with Visual Studio 2005.  I have not, however, tried to do so.  If you care to try, I would
 appreciate any feedback on how it went, including \ref section_contributing "contributions"
 to the build and usage instructions in this documentation.

 <b>Windows - Dev-C++</b>
 
 Since I have little experience with Dev-C++ and I do not use it to develop, %UtfString has very
 little testing on this IDE.  Since Dev-C++ uses MinGW, which is based on the gcc compiler, and 
 I've been been able to successfully build and test %UtfString on Linux using gcc, it's quite 
 likely that %UtfString will work just fine when compiled with MinGW and any IDE that uses
 MinGW.
 
 I welcome any feedback about anyone who is using %UtfString and developing with Dev-C++
 as well as any \ref section_contributing "contributions" to the build and usage instructions in 
 this documentation.
 
 <b>Windows - MinGW</b>
 
 Although I have used gcc on Unix-type operating systems, I have no experience using MinGW under
 Windows.  If anyone would like to set up a MinGW build environment and \ref section_contributing 
 "contribute" to this project, I would appreciate it.
 
 <b>Linux - Autotools</b>
 
 I've written makefiles and developed smaller programs with gcc as the compiler on 
 Unix-type operating systems in the past, so I'm familiar with developing on non-Windows
 platforms. However, before I started this project, I had never developed on Linux, and I was not 
 at all familiar with the GNU autotools (autoconf and automake), which are used to build many of 
 the libraries and applications on Linux.  Once I had %UtfString building under Windows, I set 
 out to get %UtfString working on Linux using autoconf and automake.
 
 It took quite a lot of time to figure out enough to get %UtfString building with the autotools
 (good tutorials are hard to find), but I finally succeeded.  There is very little information 
 about standards for Linux development (if indeed there are any), so I'm not entirely sure that
 I'm doing it correctly.  Currently, the autotools will create a makefile that builds %UtfString
 with debug symbols (there appears to be no way around that).  Installing the built library using 
 the standard "make install" installs it with debug symbols.  The user has to explicitly install 
 using "make install-strip" to install the library without debug symbols.  Ideally, I would like 
 to have the default use no debug symbols and add an option to include debug symbols when 
 someone is using the library for  development.  I haven't been able to figure how to do this 
 and I don't if installing libraries with debug symbols is the standard way of installing or not.
 
 In addition, I still need to create some autoconf macros so that developers can easily add
 %UtfString to their projects.  I have a feeling that this is not going to be easy, since I am
 not at all familiar with M4 or the available environment variables.
 
 I would really appreciate it if any of you more experienced Linux developers gave me
 feedback on the Linux build process or made any \ref section_contributing "contributions"
 to the Linux build process.
 
 <b>Mac OS X - Autotools</b>
 
 Presumably, %UtfString will build just as well as under Mac OS X using the GNU autotools
as under Linux, but I haven't been able to test this to the lack of access to a Mac.

If anyone can test %UtfString  autotools build process on Mac OS X and let me know how
well it works, I would appreciated it.

 <b>Mac OS X - XCode</b>
 
 I plan to eventually get %UtfString working with XCode, but this has not yet been 
 done.

\section section_developmentissues Development Issues

In this section, we cover issues you may encounter when making changes or additions to the
%UtfString code.

When making changes to %UtfString, I strongly recommend that you use the %UtfString unit tests
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

If you are using the %UtfString unit test solution in Visual Studio (although this may possibly
apply to other build environments and platforms), you will need to be aware of behavior that
may cause confusion.  The UtfStringUnitTests project has a post-build step that copies the
%UtfString dll into the test/bin directory so that the unit tests can be run.  This build step,
however, only happens when the unit tests need to be built.  If you have made a code change 
to the %UtfString library, but you haven't made any changes to the unit test code, you will
not see the new changes when running the unit tests.  The unit test project will see that it 
hasn't been updated, so it won't build.  If the unit test project doesn't build, it won't run the
build step that copies the dll into the test/bin directory.  I solve this problem by rebuilding
both the library and unit tests project ("Rebuild Solution" in Visual Studio).  This forces the
post-build step to be run.  This is convenient for me because rebuilding both projects is fast.
If this is too slow for you, you may want to do something like creating a script to copy the
dll to the test/bin directory.

The code in %UtfString uses tabs instead of spaces, and I normally view the source files
with a tab spacing of 4.

\section section_fixesimprovements Future Fixes and Improvements

These are the things that I am considering fixing or improving in %UtfString

<ul>
<li>Improve the Linux build process (see Linux platform under \ref section_crossplatform 
"Cross-Platform Functionality" section)</li>
<li>Create autoconf macros so that developers can easily use the %UtfString library when
building applications with autotools.</li>
<li>Create packages for easy deployment of %UtfString on Linux</li>
<li>Get %UtfString to build and run with gcc and XCode on Mac OS X (see Mac OS X platform 
under \ref section_crossplatform "Cross-Platform Functionality" section)</li>
<li>If there is enough demand for it, I may implement a string class that is encoding-independent,
so that someone using %UtfString can freely manipulate both UTF-8 and UTF-16 string using the
same class.  This will be slightly less efficient than using the Utf8String or Utf16String classes
directly. I'm expecting that most programmers will use only one encoding on a regular basis in
their applications, but I can certainly imagine that some applications (or libraries that don't 
want to provide two different interfaces) may certainly want to be able to handle multiple 
encodings in an encoding-neutral way.</li>
</ul>

\section section_contributing Contributing to UtfString

I welcome contributions to this project.  Currently, I need people to use %UtfString for their
own projects and let me know how it is working for them. Bug reports and suggested improvements
are welcome.  What I especially need are contributions to the build system under Linux and
other platforms that I have not used extensively. Automake improvements are welcome as is
assistance on building an rpm or Debian package.

\section section_currentcontributors People Who Have Contributed To UtfString

<ul>
<li>
<b>Kevin Peter</b> - The original author and creator of %UtfString
</li>
</ul>
*/