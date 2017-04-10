#ifndef LIST_H_
#define LIST_H_

template <typename T>
class List {
public:
  virtual ~List() {};
  virtual bool isEmpty() = 0;
  virtual void prepend(T c) = 0;
  virtual void append(T c) = 0;
  virtual T getHead() = 0;
  virtual List<T> * tail() = 0;
};

#endif
