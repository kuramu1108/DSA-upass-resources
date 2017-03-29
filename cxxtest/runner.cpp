/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTest_init = false;
#include "/Users/garysnmb/Downloads/test.h"

static MyTest suite_MyTest;

static CxxTest::List Tests_MyTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTest( "test.h", 3, "MyTest", suite_MyTest, Tests_MyTest );

static class TestDescription_suite_MyTest_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_testAddition() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 5, "testAddition" ) {}
 void runTest() { suite_MyTest.testAddition(); }
} testDescription_suite_MyTest_testAddition;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
