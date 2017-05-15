/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#define _CXXTEST_ABORT_TEST_ON_FAIL
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
bool suite_Assignment1Tests_init = false;
#include "Assignment1Tests.h"

static Assignment1Tests suite_Assignment1Tests;

static CxxTest::List Tests_Assignment1Tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Assignment1Tests( "Assignment1Tests.h", 32, "Assignment1Tests", suite_Assignment1Tests, Tests_Assignment1Tests );

static class TestDescription_suite_Assignment1Tests_testBasicConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testBasicConstructor() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 36, "testBasicConstructor" ) {}
 void runTest() { suite_Assignment1Tests.testBasicConstructor(); }
} testDescription_suite_Assignment1Tests_testBasicConstructor;

static class TestDescription_suite_Assignment1Tests_testTreeConstructorWithNode : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testTreeConstructorWithNode() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 44, "testTreeConstructorWithNode" ) {}
 void runTest() { suite_Assignment1Tests.testTreeConstructorWithNode(); }
} testDescription_suite_Assignment1Tests_testTreeConstructorWithNode;

static class TestDescription_suite_Assignment1Tests_testTokenise : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testTokenise() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 70, "testTokenise" ) {}
 void runTest() { suite_Assignment1Tests.testTokenise(); }
} testDescription_suite_Assignment1Tests_testTokenise;

static class TestDescription_suite_Assignment1Tests_testBuildTreeSingleValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testBuildTreeSingleValue() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 152, "testBuildTreeSingleValue" ) {}
 void runTest() { suite_Assignment1Tests.testBuildTreeSingleValue(); }
} testDescription_suite_Assignment1Tests_testBuildTreeSingleValue;

static class TestDescription_suite_Assignment1Tests_testBuildTreeSingleAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testBuildTreeSingleAddition() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 169, "testBuildTreeSingleAddition" ) {}
 void runTest() { suite_Assignment1Tests.testBuildTreeSingleAddition(); }
} testDescription_suite_Assignment1Tests_testBuildTreeSingleAddition;

static class TestDescription_suite_Assignment1Tests_testBuildTreeMultipleAdditionLeftAssociative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testBuildTreeMultipleAdditionLeftAssociative() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 197, "testBuildTreeMultipleAdditionLeftAssociative" ) {}
 void runTest() { suite_Assignment1Tests.testBuildTreeMultipleAdditionLeftAssociative(); }
} testDescription_suite_Assignment1Tests_testBuildTreeMultipleAdditionLeftAssociative;

static class TestDescription_suite_Assignment1Tests_testBuildTreeMultipleAdditionRightAssociative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testBuildTreeMultipleAdditionRightAssociative() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 249, "testBuildTreeMultipleAdditionRightAssociative" ) {}
 void runTest() { suite_Assignment1Tests.testBuildTreeMultipleAdditionRightAssociative(); }
} testDescription_suite_Assignment1Tests_testBuildTreeMultipleAdditionRightAssociative;

static class TestDescription_suite_Assignment1Tests_testBuildTreeAdditionMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testBuildTreeAdditionMultiplication() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 301, "testBuildTreeAdditionMultiplication" ) {}
 void runTest() { suite_Assignment1Tests.testBuildTreeAdditionMultiplication(); }
} testDescription_suite_Assignment1Tests_testBuildTreeAdditionMultiplication;

static class TestDescription_suite_Assignment1Tests_testBuildTreeParentheses : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testBuildTreeParentheses() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 340, "testBuildTreeParentheses" ) {}
 void runTest() { suite_Assignment1Tests.testBuildTreeParentheses(); }
} testDescription_suite_Assignment1Tests_testBuildTreeParentheses;

static class TestDescription_suite_Assignment1Tests_testEvaluateValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateValue() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 383, "testEvaluateValue" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateValue(); }
} testDescription_suite_Assignment1Tests_testEvaluateValue;

static class TestDescription_suite_Assignment1Tests_testEvaluateSimpleAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateSimpleAddition() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 397, "testEvaluateSimpleAddition" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateSimpleAddition(); }
} testDescription_suite_Assignment1Tests_testEvaluateSimpleAddition;

static class TestDescription_suite_Assignment1Tests_testEvaluateAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateAddition() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 422, "testEvaluateAddition" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateAddition(); }
} testDescription_suite_Assignment1Tests_testEvaluateAddition;

static class TestDescription_suite_Assignment1Tests_testEvaluateSimpleSubtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateSimpleSubtraction() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 501, "testEvaluateSimpleSubtraction" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateSimpleSubtraction(); }
} testDescription_suite_Assignment1Tests_testEvaluateSimpleSubtraction;

static class TestDescription_suite_Assignment1Tests_testEvaluateSimpleMultiplication : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateSimpleMultiplication() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 526, "testEvaluateSimpleMultiplication" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateSimpleMultiplication(); }
} testDescription_suite_Assignment1Tests_testEvaluateSimpleMultiplication;

static class TestDescription_suite_Assignment1Tests_testEvaluateSimpleDivision : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateSimpleDivision() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 552, "testEvaluateSimpleDivision" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateSimpleDivision(); }
} testDescription_suite_Assignment1Tests_testEvaluateSimpleDivision;

static class TestDescription_suite_Assignment1Tests_testEvaluateFullExpression : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateFullExpression() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 577, "testEvaluateFullExpression" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateFullExpression(); }
} testDescription_suite_Assignment1Tests_testEvaluateFullExpression;

static class TestDescription_suite_Assignment1Tests_testEvaluateWholeTree : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testEvaluateWholeTree() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 650, "testEvaluateWholeTree" ) {}
 void runTest() { suite_Assignment1Tests.testEvaluateWholeTree(); }
} testDescription_suite_Assignment1Tests_testEvaluateWholeTree;

static class TestDescription_suite_Assignment1Tests_testPrefixOrder : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testPrefixOrder() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 683, "testPrefixOrder" ) {}
 void runTest() { suite_Assignment1Tests.testPrefixOrder(); }
} testDescription_suite_Assignment1Tests_testPrefixOrder;

static class TestDescription_suite_Assignment1Tests_testInfixOrder : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testInfixOrder() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 727, "testInfixOrder" ) {}
 void runTest() { suite_Assignment1Tests.testInfixOrder(); }
} testDescription_suite_Assignment1Tests_testInfixOrder;

static class TestDescription_suite_Assignment1Tests_testPostfixOrder : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment1Tests_testPostfixOrder() : CxxTest::RealTestDescription( Tests_Assignment1Tests, suiteDescription_Assignment1Tests, 770, "testPostfixOrder" ) {}
 void runTest() { suite_Assignment1Tests.testPostfixOrder(); }
} testDescription_suite_Assignment1Tests_testPostfixOrder;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
