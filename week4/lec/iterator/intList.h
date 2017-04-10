#ifndef INTLIST_H_
#define INTLIST_H_

class intList {
public:
  virtual ~intList() {};
  virtual bool isEmpty() = 0;
  virtual void prepend(int c) = 0;
  virtual void append(int c) = 0;
  virtual int getHead() = 0;
  virtual intList * tail() = 0;
};

#endif
