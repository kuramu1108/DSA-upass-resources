#define CXXTEST_HAVE_EH
#define CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/TestSuite.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <utility>

#include "PriorityQueue.h"

class Management : public CxxTest::GlobalFixture{

public:

  float score;

  bool setUpWorld(){
    score = 0;
    return true;
  }

  bool tearDownWorld(){
    std::cout << std::endl << "Final Score: " << score << std::endl;
    return true;
  }
  
};

static Management management;

class Assignment2Tests : public CxxTest::TestSuite{
  
private:

  /*
   * Does what it says on the tin.
   */
  std::string randomString(int length){
    
    std::string source = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    std::string output = "";
    
    for (int i = 0; i < length; i++){

      output += source[std::rand() % source.size()];

    }

    return output;

  }

  /*
   * Tests whether two vectors contain the same elements. It does not test for
   * duplicates.
   */
  template <typename X> bool same_contents(std::vector<X> v1, std::vector<X> v2){

    for (typename std::vector<X>::iterator it1 = v1.begin(); it1 < v1.end(); ++it1){

      bool foundElement = false;
      for (typename std::vector<X>::iterator it2 = v2.begin(); it2 < v2.end(); ++it2){

	if (*it1 == *it2) foundElement = true;

      }

      if (!foundElement) return false;

    }

    for (typename std::vector<X>::iterator it1 = v2.begin(); it1 < v2.end(); ++it1){

      bool foundElement = false;
      for (typename std::vector<X>::iterator it2 = v1.begin(); it2 < v1.end(); ++it2){

	if (*it1 == *it2) foundElement = true;

      }

      if (!foundElement) return false;

    }

    return true;

  }

  /*
   * Prints a priority queue for debugging purposes, or just to look at it.
   */
  template <typename X> void print_priority_queue(PriorityQueue<X> pq){

    typename std::vector<X> elements = pq.get_all_elements();
    std::vector<int> priorities = pq.get_all_priorities();

    std::cout << "\n[";
    for (int i = 0; i < elements.size() - 1; i++){

      std::cout << "(" << priorities[i] << ", " << elements[i] << "), ";

    }
    std::cout << "(" << priorities[elements.size()-1] << ", " << elements[elements.size()-1] << ")]" << std::endl;

  }

  template <typename X> int get_index(std::vector<X> v, X element){

    for (int i = 0; i < v.size(); i++){

      if (v[i] == element) return i;

    }

    return -1;

  }

public:

  void testSetUp(){

    PriorityQueue<std::string> pq;

    TS_ASSERT(pq.empty());
    TS_ASSERT_EQUALS(pq.size(), 0);
    std::cout << "testSetUp\n";
    management.score += 1;

  }

  void testInsertionAddsOneThing(){

    PriorityQueue<std::string> pq;

    pq.insert(1,"test");

    TS_ASSERT(!pq.empty());
    TS_ASSERT_EQUALS(pq.size(), 1);
    std::cout << "testInsertionAddsOneThing\n";
    management.score += 2;

  }

  void testInsertionAddsSeveralThings(){

    int num = rand()%10 + 1;

    PriorityQueue<int> pq;

    for (int i = 0; i < num; i++){

      pq.insert(rand()%100, rand()%100);

    }

    TS_ASSERT(!pq.empty());
    TS_ASSERT_EQUALS(pq.size(), num);
    std::cout << "testInsertionAddsSeveralThings\n";
    management.score += 2.5;

  }

  void testInsertionBadPriority(){

    PriorityQueue<std::string> pq;

    pq.insert(-1 * (rand() % 100 + 1), randomString(5));

    TS_ASSERT(pq.empty());
    TS_ASSERT_EQUALS(pq.size(), 0);
    std::cout << "testInsertionBadPriority\n";
    management.score += 2;

  }

  void testInsertionBadAfterSeveral(){

    int num = rand()%10 + 1;

    PriorityQueue<std::string> pq;

    for (int i = 0; i < num; i++){

      pq.insert(rand()%100, randomString(5));

    }

    TS_ASSERT(!pq.empty());
    TS_ASSERT_EQUALS(pq.size(), num);

    pq.insert(-1 * (rand() % 100 + 1), randomString(5));

    TS_ASSERT(!pq.empty());
    TS_ASSERT_EQUALS(pq.size(), num);
    std::cout << "TestInsertionAfterSeveral\n";
    management.score +=  2;

  }

  void testPeek(){

    std::string testString = randomString(5);

    PriorityQueue<std::string> pq;

    pq.insert(1, testString);

    TS_ASSERT_EQUALS(pq.peek(), testString);
    std::cout << "TestPeek\n";
    management.score += 3;

  }

  void testPeekPlusSeveral(){

    std::string testString = randomString(5);
    int randomPriority = rand() % 10;

    PriorityQueue<std::string> pq;

    pq.insert(randomPriority, testString);

    for (int i = 0; i < rand() % 10 + 1; i++){

      pq.insert(rand()%10 + randomPriority + 1, randomString(6));

    }

    TS_ASSERT_EQUALS(pq.peek(), testString);
    std::cout << "TestPeekPlusSeveral\n";
    management.score += 3.5;

  }

  void TestPeekAfterSeveral(){

    std::string testString = randomString(5);
    int randomPriority = rand() % 10;

    PriorityQueue<std::string> pq;

    for (int i = 0; i < rand() % 10 + 1; i++){

      pq.insert(rand()%10 + randomPriority + 1, randomString(6));

    }

    pq.insert(randomPriority, testString);

    TS_ASSERT_EQUALS(pq.peek(), testString);
    std::cout << "TestPeekAfterSeveral\n";
    management.score += 4.5;

  }

  void testContainsEmpty(){

    PriorityQueue<std::string> pq;

    TS_ASSERT(!pq.contains(randomString(5)));
    std::cout << "testContainsEmpty\n";
    management.score += 2;

  }

  void testContainsOneElement(){

    PriorityQueue<std::string> pq;

    pq.insert(1,"test");

    TS_ASSERT(pq.contains("test"));
    std::cout << "testContainsOneElement\n";
    management.score += 2;

  }

  void testContainsSeveralElements(){

    std::vector<std::string> vec;

    for (int i = 0; i < rand()%10 + 1; i++){

      vec.push_back(randomString(5));

    }

    PriorityQueue<std::string> pq;

    for (std::vector<std::string>::iterator iter = vec.begin(); iter < vec.end(); ++iter){

      pq.insert(rand()%100, *iter);

    }

    for (std::vector<std::string>::iterator iter = vec.begin(); iter < vec.end(); ++iter){

      TS_ASSERT(pq.contains(*iter));

    }
    std::cout << "testContainsSeveralElements\n";
    management.score += 3;

  }

  void testContainsNoFalsePositiveEmpty(){
    
    PriorityQueue<std::string> pq;
      
    TS_ASSERT(!pq.contains("test"));
    std::cout << "testContainsNoFalsePositiveEmpty\n";
    management.score += 2;
      
  }
  
  void testContainsNoFalsePositivesNotEmpty(){
    
    std::vector<std::string> vec;
    
    for (int i = 0; i < rand()%10 + 1; i++){
	
      vec.push_back(randomString(5));
	
    }
      
    PriorityQueue<std::string> pq;
    
    for (std::vector<std::string>::iterator iter = vec.begin(); iter < vec.end() - 1; ++iter){
      
      pq.insert(rand()%100, *iter);
      
    }
    
    TS_ASSERT(!pq.contains(vec[vec.size()-1]));
    std::cout << "testContainsNoFalsePositivesNotEmpty\n";
    management.score += 2;
    
  }

  void testGetPriorityEmpty(){

    PriorityQueue<int> pq;

    TS_ASSERT_EQUALS(pq.get_priority(rand()%100), -1); 
    std::cout << "testGetPriorityEmpty\n";
    management.score += 1;
    
  }

  void testGetPriorityOneElement(){

    std::string s = randomString(10);
    int priority = rand()%100;

    PriorityQueue<std::string> pq;

    pq.insert(priority, s);

    TS_ASSERT_EQUALS(pq.get_priority(s), priority);
    std::cout << "testGetPriorityOneElement\n";
    management.score += 1;

  }

  void testGetPrioritySeveralElements(){

    PriorityQueue<std::string> pq;

    std::vector<int> priorities;
    std::vector<std::string> elements;

    for (int i = 0; i < rand() % 10 + 1; i++){

      priorities.push_back(rand()%100);
      elements.push_back(randomString(rand()%10 + 1));
      pq.insert(priorities[i], elements[i]);

    }

    for (int i = 0; i < elements.size(); i++){

      TS_ASSERT_EQUALS(pq.get_priority(elements[i]), priorities[i]);

    }
    std::cout << "testGetPrioritySeveralElements\n";
    management.score += 1;

  }

  void testInsertAllEmpty(){

    PriorityQueue<int> pq;
    std::vector<std::pair<int, int> > v;

    pq.insert_all(v);
    
    TS_ASSERT(pq.empty());
    TS_ASSERT_EQUALS(pq.size(), 0);
    std::cout << "testInsertAllEmpty\n";
    management.score += 1;

  }

  void testInsertAllOneElement(){

    PriorityQueue<int> pq;
    std::vector<std::pair<int, int> > v;

    v.push_back(std::pair<int, int>(rand()%10, rand()%10));
    pq.insert_all(v);
    
    TS_ASSERT(!pq.empty());
    TS_ASSERT_EQUALS(pq.size(), 1);
    std::cout << "testInsertAllOneElement\n";
    management.score += 2;
    
  }

  void testInsertAllSeveralElements(){

    PriorityQueue<std::string> pq;

    std::vector<std::pair<int, std::string> > pairs;

    for (int i = 0; i < rand() % 10 + 1; i++){

      pairs.push_back(std::pair<int, std::string>(rand()%100,randomString(rand()%10 + 1)));

    }

    pq.insert_all(pairs);

    TS_ASSERT(!pq.empty());
    TS_ASSERT_EQUALS(pq.size(), pairs.size());
    std::cout << "testInsertAllSeveralElements\n";
    management.score += 3;

  }

  void testGetAllElementsEmpty(){

    PriorityQueue<std::string> pq;

    std::vector<std::string> output = pq.get_all_elements();

    TS_ASSERT(output.empty());

    management.score += 1;

  }

  void testGetAllElementsOneElement(){

    PriorityQueue<std::string> pq;

    std::string element = randomString(rand()%10 + 1);

    pq.insert(rand()%100, element);

    std::vector<std::string> output = pq.get_all_elements();

    TS_ASSERT(!output.empty());
    TS_ASSERT_EQUALS(output[0], element);

    management.score += 2;

  }

  void testGetAllElementsSeveralElement(){

    PriorityQueue<std::string> pq;

    std::vector<std::string> vec;

    for (int i = 0; i < rand()%10 + 1; i++){
      
      vec.push_back(randomString(5));

    }

    for (std::vector<std::string>::iterator iter = vec.begin(); iter < vec.end(); ++iter){

      pq.insert(rand()%100, *iter);

    }

    std::vector<std::string> output = pq.get_all_elements();

    TS_ASSERT(same_contents(vec, output));

    management.score += 2;

  }

  void testGetAllPrioritiesEmpty(){

    PriorityQueue<std::string> pq;

    TS_ASSERT(pq.get_all_priorities().empty());

    management.score += 1;

  }

  void testGetAllPrioritiesOneElement(){

    int priority = rand()%10;

    PriorityQueue<int> pq;

    pq.insert(priority, rand()%10);

    std::vector<int> priorities = pq.get_all_priorities();

    TS_ASSERT_EQUALS(priorities.size(), 1);
    TS_ASSERT_EQUALS(priorities[0] , priority);

    management.score += 2;

  }

  void testGetAllPrioritiesSeveralElements(){

    PriorityQueue<std::string> pq;

    std::vector<std::string> elements;
    std::vector<int> priorities;

    for (int i = 0; i < rand() % 10 + 1; i++){

      elements.push_back(randomString(rand()%10 + i));
      priorities.push_back(rand()%100);

    }

    for (int i = 0; i < elements.size(); i++){

      pq.insert(priorities[i], elements[i]);
      
    }
    
    std::vector<std::string> outputElements = pq.get_all_elements();
    std::vector<int> outputPriorities = pq.get_all_priorities();

    TS_ASSERT(same_contents(priorities, outputPriorities));
    TS_ASSERT(same_contents(elements, outputElements));

    for (int i = 0; i < elements.size(); i++){

      TS_ASSERT_EQUALS(outputPriorities[get_index(outputElements, elements[i])], priorities[i]);

    }

    management.score += 4;

  }

  void testRemoveFrontEmpty(){

    PriorityQueue<std::string> pq;

    TS_ASSERT_EQUALS(pq.remove_front(), "");
    std::cout << "testRemoveFrontEmpty\n";
    management.score += 1;

  }

  void testRemoveFrontOneElement(){

    PriorityQueue<int> pq;

    int element = rand() % 100;

    pq.insert(rand()%100, element);

    TS_ASSERT_EQUALS(pq.remove_front(), element);
    TS_ASSERT(pq.empty());
    std::cout << "testRemoveFrontOneElement\n";
    management.score += 1;

  }

  void testRemoveFrontSeveralElements(){

    PriorityQueue<std::string> pq;

    int priority = rand() % 10;
    std::string element = randomString(rand() % 10 + 1);

    pq.insert(priority, element);

    int size = rand() % 10 + 1;

    for (int i = 0; i < size; i++){

      pq.insert(rand() % 10 + priority + 1, randomString(rand()%10 + 1));

    }

    TS_ASSERT_EQUALS(pq.size(), size + 1);
    TS_ASSERT_EQUALS(pq.remove_front(), element);
    TS_ASSERT_EQUALS(pq.size(), size);
    std::cout << "testRemoveFrontSeveralElements\n";
    management.score += 1;

  }

  void testChangePriorityOneElement(){

    int element = rand() % 100;

    PriorityQueue<int> pq;

    pq.insert(rand() % 100 + 5, element);

    int new_priority = rand() % 5;

    pq.change_priority(element, new_priority);

    TS_ASSERT_EQUALS(pq.get_priority(element), new_priority);

    management.score += 2;
    
  }

  void testChangePriorityInMiddle(){

    std::vector<int> priorities;
    std::vector<int> elements;

    for (int i = 0; i < rand() % 10 + 1; i++){

      priorities.push_back(rand()%10 + 5);
      elements.push_back(rand()%10 + i*10);

    }

    PriorityQueue<int> pq;

    for (int i = 0; i < elements.size(); i++){

      pq.insert(priorities[i], elements[i]);

    }

    int new_priority = rand() % 5;

    int pos = rand() % elements.size();

    pq.change_priority(elements[pos], new_priority);
    
    for (int i = 0; i < elements.size(); i++){

      if (i != pos){
	TS_ASSERT_EQUALS(pq.get_priority(elements[i]), priorities[i]);
      }
      else {
	TS_ASSERT_EQUALS(pq.get_priority(elements[i]), new_priority);
      }

    }

    management.score += 2;

  }

  void testIsMinHeap(){

    PriorityQueue<std::string> pq;
 
    for (int i = 0; i < rand()%10 + 1; i++){

      pq.insert(rand()%100, randomString(rand()%5 + i));

    }

    std::vector<int> outputPriorities = pq.get_all_priorities();

    for (int i = 0; i < outputPriorities.size()/2; i++){

      if (2*i + 1 < outputPriorities.size()) TS_ASSERT(outputPriorities[i] <= outputPriorities[2*i+1]);
      if (2*i + 2 < outputPriorities.size()) TS_ASSERT(outputPriorities[i] <= outputPriorities[2*i+2]);

    }

    management.score += 2;

  }

  void testIsCorrectMinHeap(){

    PriorityQueue<std::string> pq;

    std::vector<int> manualHeap;
    
    pq.insert(1, randomString(5));
    manualHeap.push_back(1);
    pq.insert(20, randomString(5));
    manualHeap.push_back(20);
    pq.insert(10, randomString(5));
    manualHeap.push_back(10);

    TS_ASSERT_EQUALS(pq.get_all_priorities(), manualHeap);

    management.score += 2;

  }

  void testIsCorrectMinHeapWithSwap(){

    PriorityQueue<std::string> pq;

    std::vector<int> manualHeap;
    
    pq.insert(1, randomString(5));
    pq.insert(20, randomString(5));
    pq.insert(10, randomString(5));
    pq.insert(15, randomString(5));
	      
    manualHeap.push_back(1);
    manualHeap.push_back(15);
    manualHeap.push_back(10);
    manualHeap.push_back(20);


    TS_ASSERT_EQUALS(pq.get_all_priorities(), manualHeap);

    management.score += 3;    

  }

  void testIsCorrectMinHeapWithRemoval(){

    PriorityQueue<std::string> pq;

    std::vector<int> manualHeap;
    
    pq.insert(1, randomString(5));
    pq.insert(10, randomString(5));
    pq.insert(20, randomString(5));
    pq.insert(15, randomString(5));
	  
    manualHeap.push_back(10);
    manualHeap.push_back(15);
    manualHeap.push_back(20);

    pq.remove_front();

    TS_ASSERT_EQUALS(pq.get_all_priorities(), manualHeap);

    management.score += 3.5;

  }
  
};
