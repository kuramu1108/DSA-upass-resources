#include "LinkedList.h"

template <typename T> LinkedList<T>::Node::Node() {
  data = 0;
  next = 0;
}

template <typename T> LinkedList<T>::Node::Node(Node * n, T d){
  data = d;
  next = n;
}

template <typename T> LinkedList<T>::Node::~Node() {
  //You don't have to do anything for this one.
}

template <typename T> T LinkedList<T>::Node::getData(){
  return data;
}

template <typename T> typename LinkedList<T>::Node * LinkedList<T>::Node::getNext(){
  return next;
}

template <typename T> void LinkedList<T>::Node::setNext(Node * n){
  next = n;
}

template <typename T> LinkedList<T>::LinkedList(){
  head = 0;
  length = 0;
}

template <typename T> LinkedList<T>::~LinkedList(){

  if (head != 0){

    Node * current = head;
    Node * next = current->getNext();
    while (next != 0){
      delete current;
      current = next;
      next = current->getNext();
    }
  }
}

template <typename T> bool LinkedList<T>::isEmpty(){
  return length == 0;
}

template <typename T> void LinkedList<T>::prepend(T c){
  Node * newNode = new Node(head, c);
  head = newNode;
  length++;
}

template <typename T> void LinkedList<T>::append(T c){

  if (head == 0){
    prepend(c);
  }
  else{
    Node * current = head;
    while (current->getNext() != 0){
      current = current->getNext();
    }
    current->setNext(new Node(0, c));
    length++;
  }
}

template <typename T> T LinkedList<T>::getHead(){
  return head->getData();
}

template <typename T> LinkedList<T> * LinkedList<T>::tail(){

  LinkedList<T> * newList = new LinkedList<T>();

  if (head != 0){
    Node * current = head->getNext();

    while (current != 0){
      newList->append(current->getData());
      current = current->getNext();
    }
  }

  return newList;
  
}

template class LinkedList<int>;
template class LinkedList<short>;
template class LinkedList<char>;
