#ifndef INTLINKEDLIST_H_
#define INTLINKEDLIST_H_

#include <cstddef>
#include <string>

#include "intList.h"

using std::size_t;
using std::string;

class intLinkedList : public intList {

 private:

  class intNode{

  private:

    intNode * next;
    int data;

  public:

    intNode();
    intNode(intNode * next, int data);
    ~intNode();
    int getData();
    intNode * getNext();
    void setNext(intNode *);

  };

  intNode * head;
  size_t length;

 public:

  intLinkedList();
  ~intLinkedList();
  bool isEmpty();
  void prepend(int c);
  void append(int c);
  int getHead();
  intLinkedList * tail();
  
};

#endif
