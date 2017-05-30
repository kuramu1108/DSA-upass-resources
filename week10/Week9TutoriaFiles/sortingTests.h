#ifndef _SORTINGTESTS_H
#define _SORTINGTESTS_H

#include <cxxtest/TestSuite.h>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "sorting.h"

class sortingTests : public CxxTest::TestSuite {

private:

  template <typename E> void printVector(std::vector<E> v){

    std::cout << "\n[";
    for (int i = 0; i < v.size() - 1; i++){
      std::cout << v[i] << ", ";
    }
    std::cout << v[v.size()-1] << "]" << std::endl;
    
  }

public:
  
  void testSort(){

    std::vector<int> input;

    for (int i = 0; i < 10; i++){

      input.push_back(std::rand() % 100);
      
    }

    std::vector<int> output = sorting::sort(input);
    
    for (int i = 0; i < 9; i++){

      TS_ASSERT(output[i] <= output[i+1]);

    }

    for (int i = 0; i < 10; i++){

      bool foundElement = false;
      for (int j = 0; j < 10; j++){

	if (input[i] == output[j]) foundElement = true;

      }
      TS_ASSERT(foundElement);

    }

  }  
  
};

#endif
