#include <cxxtest/TestSuite.h>

#include "SimpleStringHashMap.h"

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

class SimpleStringHashMapTests : public CxxTest::TestSuite {

 private:

  std::string randomString(int length){

    std::string source = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::string output = "";

    for (int i = 0; i < length; i++){

      output += source[std::rand() % source.size()];

    }

    return output;

  }

 public:

  /*
   * Not really a test, just shows the basic idea of the hash function.
   */
  void testHash(void){

    SimpleStringHashMap h = SimpleStringHashMap(13);

    std::vector<std::string> input;

    std::cout << std::endl;

    for (int i = 0; i < 5; i++){

      input.push_back(randomString(5));
      std::cout << input[i] << " -> " << h.hash(input[i]) << std::endl;

    }

  }

  void testInsert(void){

    int size = 13;
    SimpleStringHashMap h = SimpleStringHashMap(size);

    for (int i = 0; i < size; i++){
      TS_ASSERT(h.insert(randomString(5)));
    }

    TS_ASSERT(!h.insert(randomString(5)));

  }

  void testContains(void){

    int size = 13;
    SimpleStringHashMap h = SimpleStringHashMap(size);
    std::vector<std::string> data;

    for (int i = 0; i < size; i++){
      std::string s = randomString(5);
      if (i % 2 == 0) TS_ASSERT(h.insert(s));
      data.push_back(s);
    }

    for (int i = 0; i < data.size(); i++){

      if (i % 2 == 0){ TS_ASSERT(h.contains(data[i])); }
      else { TS_ASSERT(!h.contains(data[i])); }

    }
    
  }

  void testRemove(void){

    int size = 13;
    SimpleStringHashMap h = SimpleStringHashMap(size);
    std::vector<std::string> data;

    for (int i = 0; i < size; i++){
      std::string s = randomString(5);
      TS_ASSERT(h.insert(s));
      data.push_back(s);
    }

    for (int i = 0; i < data.size(); i += 2){

      h.remove(data[i]);

    }

    for (int i = 0; i < data.size(); i++){

      if (i % 2 == 0){ TS_ASSERT(!h.contains(data[i])); }
      else { TS_ASSERT(h.contains(data[i])); }

    }

  }
  
};
