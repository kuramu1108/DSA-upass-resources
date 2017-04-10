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
bool suite_MyTestSuite1_init = false;
#include "fooTests.h"

static MyTestSuite1 suite_MyTestSuite1;

static CxxTest::List Tests_MyTestSuite1 = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite1( "fooTests.h", 17, "MyTestSuite1", suite_MyTestSuite1, Tests_MyTestSuite1 );

static class TestDescription_suite_MyTestSuite1_testAddOne : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testAddOne() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 21, "testAddOne" ) {}
 void runTest() { suite_MyTestSuite1.testAddOne(); }
} testDescription_suite_MyTestSuite1_testAddOne;

static class TestDescription_suite_MyTestSuite1_testCharToInt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testCharToInt() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 27, "testCharToInt" ) {}
 void runTest() { suite_MyTestSuite1.testCharToInt(); }
} testDescription_suite_MyTestSuite1_testCharToInt;

static class TestDescription_suite_MyTestSuite1_testAdd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testAdd() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 35, "testAdd" ) {}
 void runTest() { suite_MyTestSuite1.testAdd(); }
} testDescription_suite_MyTestSuite1_testAdd;

static class TestDescription_suite_MyTestSuite1_testPtrAdd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testPtrAdd() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 46, "testPtrAdd" ) {}
 void runTest() { suite_MyTestSuite1.testPtrAdd(); }
} testDescription_suite_MyTestSuite1_testPtrAdd;

static class TestDescription_suite_MyTestSuite1_testIntegerDiv : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testIntegerDiv() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 57, "testIntegerDiv" ) {}
 void runTest() { suite_MyTestSuite1.testIntegerDiv(); }
} testDescription_suite_MyTestSuite1_testIntegerDiv;

static class TestDescription_suite_MyTestSuite1_testDoubleDiv : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testDoubleDiv() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 70, "testDoubleDiv" ) {}
 void runTest() { suite_MyTestSuite1.testDoubleDiv(); }
} testDescription_suite_MyTestSuite1_testDoubleDiv;

static class TestDescription_suite_MyTestSuite1_testEven : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testEven() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 85, "testEven" ) {}
 void runTest() { suite_MyTestSuite1.testEven(); }
} testDescription_suite_MyTestSuite1_testEven;

static class TestDescription_suite_MyTestSuite1_testOdd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testOdd() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 96, "testOdd" ) {}
 void runTest() { suite_MyTestSuite1.testOdd(); }
} testDescription_suite_MyTestSuite1_testOdd;

static class TestDescription_suite_MyTestSuite1_testConcatenate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testConcatenate() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 106, "testConcatenate" ) {}
 void runTest() { suite_MyTestSuite1.testConcatenate(); }
} testDescription_suite_MyTestSuite1_testConcatenate;

static class TestDescription_suite_MyTestSuite1_testTwiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite1_testTwiddle() : CxxTest::RealTestDescription( Tests_MyTestSuite1, suiteDescription_MyTestSuite1, 114, "testTwiddle" ) {}
 void runTest() { suite_MyTestSuite1.testTwiddle(); }
} testDescription_suite_MyTestSuite1_testTwiddle;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
