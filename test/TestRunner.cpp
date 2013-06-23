#include <cppunit/ui/text/TestRunner.h>

#include "StringConverterTest.h"
#include "Utf16StringTest.h"
#include "Utf16CharTest.h"
#include "Utf16CharReferenceTest.h"
#include "Utf8CharTest.h"
#include "Utf8CharReferenceTest.h"
#include "Utf8StringTest.h"
#include "UnicodeCharTest.h"
#include "UnicodeCharReferenceTest.h"
#include "UnicodeStringTest.h"

using namespace UtfStringTest;

int main(void)
{
	try
	{
		CppUnit::TextUi::TestRunner runner;

		runner.addTest(StringConverterTest::suite());
		runner.addTest(Utf16StringTest::suite());
		runner.addTest(Utf16CharTest::suite());
		runner.addTest(Utf16CharReferenceTest::suite());
		runner.addTest(Utf8CharTest::suite());
		runner.addTest(Utf8CharReferenceTest::suite());
		runner.addTest(Utf8StringTest::suite());
		runner.addTest(UnicodeCharTest::suite());
		runner.addTest(UnicodeCharReferenceTest::suite());
		runner.addTest(UnicodeStringTest::suite());

		runner.run();
	}
	catch(CppUnit::Exception& ex)
	{
		std::cerr << "Exception on Line " << ex.sourceLine().lineNumber() << ": " << ex.what() << std::endl;
	}

	return 0;
}
