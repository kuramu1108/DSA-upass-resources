#ifndef _BST_H
#define _BST_H

#include <vector>

template <typename K, typename V>
class BinarySearchTree {

private:
  
  class BinaryTreeNode{

  public:
    BinaryTreeNode(K k, V v);
    ~BinaryTreeNode();
    BinaryTreeNode * parent;
    BinaryTreeNode * left;
    BinaryTreeNode * right;
    K key;
    V value;
  };

  BinaryTreeNode * root;

  std::vector<V> inOrderRec(BinaryTreeNode *);

public:

  BinarySearchTree();
  ~BinarySearchTree();
  void insert(K, V);
  bool contains(K);
  V find(K);
  bool erase(K);
  std::vector<V> valuesInOrder();
  
};

#endif
