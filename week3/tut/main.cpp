#include <iostream>

#include "intLinkedList.h"

using std::cout;

int main(){

  intLinkedList * list = new intLinkedList();

  for (int i = 0; i < 10; i++){
    list->append(i);
  }

  cout << list->getHead() << "\n";

  intLinkedList * tailList = list->tail();
  while (!tailList->isEmpty()){
    cout << tailList->getHead() << "\n";
    intLinkedList * temp = tailList->tail();
    delete tailList;
    tailList = temp;
  }
  
}
