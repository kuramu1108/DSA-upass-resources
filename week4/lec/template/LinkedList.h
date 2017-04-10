#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <cstddef>
#include <string>

#include "List.h"

using std::size_t;
using std::string;

template <typename T>
class LinkedList : public List<T> {

 private:

  class Node{

  private:

    Node * next;
    T data;

  public:

    Node();
    Node(Node * next, T data);
    ~Node();
    T getData();
    Node * getNext();
    void setNext(Node *);

  };

  Node * head;
  size_t length;

 public:

  LinkedList();
  ~LinkedList();
  bool isEmpty();
  void prepend(T c);
  void append(T c);
  T getHead();
  LinkedList<T> * tail();
  
};

#endif
