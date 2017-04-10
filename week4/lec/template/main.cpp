#include <iostream>

#include "LinkedList.h"

using std::cout;


int main(){

//   LinkedList<int> * list = new LinkedList<int>();

//   for (int i = 0; i < 10; i++){
//     list->append(i);
//   }

//   cout << list->getHead() << "\n";

//   LinkedList<int> * tailList = list->tail();
//   while (!tailList->isEmpty()){
//     cout << tailList->getHead() << "\n";
//     LinkedList<int> * temp = tailList->tail();
//     delete tailList;
//     tailList = temp;
//   }
  

  LinkedList<char> * list = new LinkedList<char>();

  for (char i = 'a'; i <= 'z'; i++){
    list->append(i);
  }

  cout << list->getHead() << "\n";

  LinkedList<char> * tailList = list->tail();
  while (!tailList->isEmpty()){
    cout << tailList->getHead() << "\n";
    LinkedList<char> * temp = tailList->tail();
    delete tailList;
    tailList = temp;
  }
}
