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
bool suite_Assignment2Tests_init = false;
#include "Assignment2Test.h"

static Assignment2Tests suite_Assignment2Tests;

static CxxTest::List Tests_Assignment2Tests = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Assignment2Tests( "Assignment2Test.h", 33, "Assignment2Tests", suite_Assignment2Tests, Tests_Assignment2Tests );

static class TestDescription_suite_Assignment2Tests_testSetUp : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testSetUp() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 124, "testSetUp" ) {}
 void runTest() { suite_Assignment2Tests.testSetUp(); }
} testDescription_suite_Assignment2Tests_testSetUp;

static class TestDescription_suite_Assignment2Tests_testInsertionAddsOneThing : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testInsertionAddsOneThing() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 135, "testInsertionAddsOneThing" ) {}
 void runTest() { suite_Assignment2Tests.testInsertionAddsOneThing(); }
} testDescription_suite_Assignment2Tests_testInsertionAddsOneThing;

static class TestDescription_suite_Assignment2Tests_testInsertionAddsSeveralThings : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testInsertionAddsSeveralThings() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 148, "testInsertionAddsSeveralThings" ) {}
 void runTest() { suite_Assignment2Tests.testInsertionAddsSeveralThings(); }
} testDescription_suite_Assignment2Tests_testInsertionAddsSeveralThings;

static class TestDescription_suite_Assignment2Tests_testInsertionBadPriority : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testInsertionBadPriority() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 167, "testInsertionBadPriority" ) {}
 void runTest() { suite_Assignment2Tests.testInsertionBadPriority(); }
} testDescription_suite_Assignment2Tests_testInsertionBadPriority;

static class TestDescription_suite_Assignment2Tests_testInsertionBadAfterSeveral : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testInsertionBadAfterSeveral() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 180, "testInsertionBadAfterSeveral" ) {}
 void runTest() { suite_Assignment2Tests.testInsertionBadAfterSeveral(); }
} testDescription_suite_Assignment2Tests_testInsertionBadAfterSeveral;

static class TestDescription_suite_Assignment2Tests_testPeek : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testPeek() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 204, "testPeek" ) {}
 void runTest() { suite_Assignment2Tests.testPeek(); }
} testDescription_suite_Assignment2Tests_testPeek;

static class TestDescription_suite_Assignment2Tests_testPeekPlusSeveral : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testPeekPlusSeveral() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 218, "testPeekPlusSeveral" ) {}
 void runTest() { suite_Assignment2Tests.testPeekPlusSeveral(); }
} testDescription_suite_Assignment2Tests_testPeekPlusSeveral;

static class TestDescription_suite_Assignment2Tests_TestPeekAfterSeveral : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_TestPeekAfterSeveral() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 239, "TestPeekAfterSeveral" ) {}
 void runTest() { suite_Assignment2Tests.TestPeekAfterSeveral(); }
} testDescription_suite_Assignment2Tests_TestPeekAfterSeveral;

static class TestDescription_suite_Assignment2Tests_testContainsEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testContainsEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 260, "testContainsEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testContainsEmpty(); }
} testDescription_suite_Assignment2Tests_testContainsEmpty;

static class TestDescription_suite_Assignment2Tests_testContainsOneElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testContainsOneElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 270, "testContainsOneElement" ) {}
 void runTest() { suite_Assignment2Tests.testContainsOneElement(); }
} testDescription_suite_Assignment2Tests_testContainsOneElement;

static class TestDescription_suite_Assignment2Tests_testContainsSeveralElements : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testContainsSeveralElements() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 282, "testContainsSeveralElements" ) {}
 void runTest() { suite_Assignment2Tests.testContainsSeveralElements(); }
} testDescription_suite_Assignment2Tests_testContainsSeveralElements;

static class TestDescription_suite_Assignment2Tests_testContainsNoFalsePositiveEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testContainsNoFalsePositiveEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 310, "testContainsNoFalsePositiveEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testContainsNoFalsePositiveEmpty(); }
} testDescription_suite_Assignment2Tests_testContainsNoFalsePositiveEmpty;

static class TestDescription_suite_Assignment2Tests_testContainsNoFalsePositivesNotEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testContainsNoFalsePositivesNotEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 320, "testContainsNoFalsePositivesNotEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testContainsNoFalsePositivesNotEmpty(); }
} testDescription_suite_Assignment2Tests_testContainsNoFalsePositivesNotEmpty;

static class TestDescription_suite_Assignment2Tests_testGetPriorityEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetPriorityEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 344, "testGetPriorityEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testGetPriorityEmpty(); }
} testDescription_suite_Assignment2Tests_testGetPriorityEmpty;

static class TestDescription_suite_Assignment2Tests_testGetPriorityOneElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetPriorityOneElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 354, "testGetPriorityOneElement" ) {}
 void runTest() { suite_Assignment2Tests.testGetPriorityOneElement(); }
} testDescription_suite_Assignment2Tests_testGetPriorityOneElement;

static class TestDescription_suite_Assignment2Tests_testGetPrioritySeveralElements : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetPrioritySeveralElements() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 369, "testGetPrioritySeveralElements" ) {}
 void runTest() { suite_Assignment2Tests.testGetPrioritySeveralElements(); }
} testDescription_suite_Assignment2Tests_testGetPrioritySeveralElements;

static class TestDescription_suite_Assignment2Tests_testInsertAllEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testInsertAllEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 394, "testInsertAllEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testInsertAllEmpty(); }
} testDescription_suite_Assignment2Tests_testInsertAllEmpty;

static class TestDescription_suite_Assignment2Tests_testInsertAllOneElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testInsertAllOneElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 408, "testInsertAllOneElement" ) {}
 void runTest() { suite_Assignment2Tests.testInsertAllOneElement(); }
} testDescription_suite_Assignment2Tests_testInsertAllOneElement;

static class TestDescription_suite_Assignment2Tests_testInsertAllSeveralElements : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testInsertAllSeveralElements() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 423, "testInsertAllSeveralElements" ) {}
 void runTest() { suite_Assignment2Tests.testInsertAllSeveralElements(); }
} testDescription_suite_Assignment2Tests_testInsertAllSeveralElements;

static class TestDescription_suite_Assignment2Tests_testGetAllElementsEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetAllElementsEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 444, "testGetAllElementsEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testGetAllElementsEmpty(); }
} testDescription_suite_Assignment2Tests_testGetAllElementsEmpty;

static class TestDescription_suite_Assignment2Tests_testGetAllElementsOneElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetAllElementsOneElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 456, "testGetAllElementsOneElement" ) {}
 void runTest() { suite_Assignment2Tests.testGetAllElementsOneElement(); }
} testDescription_suite_Assignment2Tests_testGetAllElementsOneElement;

static class TestDescription_suite_Assignment2Tests_testGetAllElementsSeveralElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetAllElementsSeveralElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 473, "testGetAllElementsSeveralElement" ) {}
 void runTest() { suite_Assignment2Tests.testGetAllElementsSeveralElement(); }
} testDescription_suite_Assignment2Tests_testGetAllElementsSeveralElement;

static class TestDescription_suite_Assignment2Tests_testGetAllPrioritiesEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetAllPrioritiesEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 499, "testGetAllPrioritiesEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testGetAllPrioritiesEmpty(); }
} testDescription_suite_Assignment2Tests_testGetAllPrioritiesEmpty;

static class TestDescription_suite_Assignment2Tests_testGetAllPrioritiesOneElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetAllPrioritiesOneElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 509, "testGetAllPrioritiesOneElement" ) {}
 void runTest() { suite_Assignment2Tests.testGetAllPrioritiesOneElement(); }
} testDescription_suite_Assignment2Tests_testGetAllPrioritiesOneElement;

static class TestDescription_suite_Assignment2Tests_testGetAllPrioritiesSeveralElements : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testGetAllPrioritiesSeveralElements() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 526, "testGetAllPrioritiesSeveralElements" ) {}
 void runTest() { suite_Assignment2Tests.testGetAllPrioritiesSeveralElements(); }
} testDescription_suite_Assignment2Tests_testGetAllPrioritiesSeveralElements;

static class TestDescription_suite_Assignment2Tests_testRemoveFrontEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testRemoveFrontEmpty() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 562, "testRemoveFrontEmpty" ) {}
 void runTest() { suite_Assignment2Tests.testRemoveFrontEmpty(); }
} testDescription_suite_Assignment2Tests_testRemoveFrontEmpty;

static class TestDescription_suite_Assignment2Tests_testRemoveFrontOneElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testRemoveFrontOneElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 572, "testRemoveFrontOneElement" ) {}
 void runTest() { suite_Assignment2Tests.testRemoveFrontOneElement(); }
} testDescription_suite_Assignment2Tests_testRemoveFrontOneElement;

static class TestDescription_suite_Assignment2Tests_testRemoveFrontSeveralElements : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testRemoveFrontSeveralElements() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 587, "testRemoveFrontSeveralElements" ) {}
 void runTest() { suite_Assignment2Tests.testRemoveFrontSeveralElements(); }
} testDescription_suite_Assignment2Tests_testRemoveFrontSeveralElements;

static class TestDescription_suite_Assignment2Tests_testChangePriorityOneElement : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testChangePriorityOneElement() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 612, "testChangePriorityOneElement" ) {}
 void runTest() { suite_Assignment2Tests.testChangePriorityOneElement(); }
} testDescription_suite_Assignment2Tests_testChangePriorityOneElement;

static class TestDescription_suite_Assignment2Tests_testChangePriorityInMiddle : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testChangePriorityInMiddle() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 630, "testChangePriorityInMiddle" ) {}
 void runTest() { suite_Assignment2Tests.testChangePriorityInMiddle(); }
} testDescription_suite_Assignment2Tests_testChangePriorityInMiddle;

static class TestDescription_suite_Assignment2Tests_testIsMinHeap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testIsMinHeap() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 671, "testIsMinHeap" ) {}
 void runTest() { suite_Assignment2Tests.testIsMinHeap(); }
} testDescription_suite_Assignment2Tests_testIsMinHeap;

static class TestDescription_suite_Assignment2Tests_testIsCorrectMinHeap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testIsCorrectMinHeap() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 694, "testIsCorrectMinHeap" ) {}
 void runTest() { suite_Assignment2Tests.testIsCorrectMinHeap(); }
} testDescription_suite_Assignment2Tests_testIsCorrectMinHeap;

static class TestDescription_suite_Assignment2Tests_testIsCorrectMinHeapWithSwap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testIsCorrectMinHeapWithSwap() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 713, "testIsCorrectMinHeapWithSwap" ) {}
 void runTest() { suite_Assignment2Tests.testIsCorrectMinHeapWithSwap(); }
} testDescription_suite_Assignment2Tests_testIsCorrectMinHeapWithSwap;

static class TestDescription_suite_Assignment2Tests_testIsCorrectMinHeapWithRemoval : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Assignment2Tests_testIsCorrectMinHeapWithRemoval() : CxxTest::RealTestDescription( Tests_Assignment2Tests, suiteDescription_Assignment2Tests, 736, "testIsCorrectMinHeapWithRemoval" ) {}
 void runTest() { suite_Assignment2Tests.testIsCorrectMinHeapWithRemoval(); }
} testDescription_suite_Assignment2Tests_testIsCorrectMinHeapWithRemoval;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
