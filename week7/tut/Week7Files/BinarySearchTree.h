#ifndef _BST_H
#define _BST_H

#include <vector>
#include <string>

class BinarySearchTree {

private:

  /*
   * The basic building block of a tree is a node!
   */
  class BinaryTreeNode{

  public:
    BinaryTreeNode(int);
    ~BinaryTreeNode();
    BinaryTreeNode * parent;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
    int value;
  };

  BinaryTreeNode * root;

public:

  BinarySearchTree();
  ~BinarySearchTree();
  void insert(int);
  bool contains(int);
  //string find(int); //This one is for the more advanced version.
  bool erase(int);
  std::vector<int> valuesInOrder();
  
};

#endif
