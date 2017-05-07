#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include <vector>

int main(){

  BinarySearchTree<int, std::string> t;

  t.insert(12, "hello");
  t.insert(1, "a");
  t.insert(5, "b");
  t.insert(51, "c");



  std::vector<std::string> vec = t.valuesInOrder();

  std::cout << "Hey" << std::endl;
  for (int i = 0; i < vec.size(); i++){

    std::cout << vec[i] << ", ";

  }

  std::cout << std::endl;

}
