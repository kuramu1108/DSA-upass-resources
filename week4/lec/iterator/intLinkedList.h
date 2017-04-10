#ifndef INTLINKEDLIST_H_
#define INTLINKEDLIST_H_

#include <cstddef>
#include <iterator>

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

  class illiterator : public std::iterator<std::forward_iterator_tag, intNode> {
   
  private:
   
   intNode * current;
   
  public:
   
   illiterator(intNode * n) : current(n) {}
   illiterator(const illiterator & illi) : current(illi.current) {}
   illiterator & operator++() { current = current->getNext(); return *this;}
   illiterator & operator++(int) { illiterator tmp(*this); operator++(); return tmp;}
   bool operator==(const illiterator & rhs) {return current == rhs.current;}
   bool operator!=(const illiterator & rhs) {return current != rhs.current;}
   const int operator*() { return current->getData(); }
         
  };

  intLinkedList();
  ~intLinkedList();
  bool isEmpty();
  void prepend(int c);
  void append(int c);
  int getHead();
  intLinkedList * tail();

  illiterator begin() { return illiterator(head); }
  illiterator end() { return illiterator(0); }
  
};

#endif
