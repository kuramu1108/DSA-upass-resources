#include <cxxtest/TestSuite.h>

#include "BinarySearchTree.h"

class BSTTests : public CxxTest::TestSuite {

 public:
  
  void testInsertAndContains(void){

    BinarySearchTree t = BinarySearchTree();

    for (int i = 0; i < 100; i++){
      t.insert(i);
    }

    for (int i = 0; i < 100; i++){
      TS_ASSERT(t.contains(i));
    }
    
  }

  void testErase(void){

    BinarySearchTree t = BinarySearchTree();

    for (int i = 0; i < 100; i++){
      t.insert(i);
    }

    for (int i = 0; i < 100; i += 2){
      t.erase(i);
    }

    for (int i = 0; i < 100; i++){
      if (i % 2 == 1){
	TS_ASSERT(t.contains(i));
      }
      else {
	TS_ASSERT(!t.contains(i));
      }
      
    }

  }
  
};
