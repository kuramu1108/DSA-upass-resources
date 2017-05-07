#include "BinarySearchTree.h"
#include <string>
#include <iostream>

template <typename K, typename V>  BinarySearchTree<K,V>::BinaryTreeNode::BinaryTreeNode(K k, V v){

  key = k;
  value = v;
  parent = 0;
  left = 0;
  right = 0;

}
template <typename K, typename V>  BinarySearchTree<K,V>::BinaryTreeNode::~BinaryTreeNode(){

  delete left;
  left = 0;
  delete right;
  right = 0;
  parent = 0;
  
}


template <typename K, typename V>  BinarySearchTree<K,V>::BinarySearchTree(){

  root = 0;
  
}

template <typename K, typename V>  BinarySearchTree<K,V>::~BinarySearchTree(){

  delete root;
  
}


template <typename K, typename V>  void BinarySearchTree<K,V>::insert(K k, V v){

  BinaryTreeNode * newNode = new BinaryTreeNode(k, v);
  
  if (root == 0){

    root = newNode;
    
  }
  else{

    BinaryTreeNode * current = root;
    bool placed = false;
    while (!placed){
      
      if (k <= current->key){

	if (current->left == 0){
	  current->left = newNode;
	  newNode->parent = current;
	  placed = true;
	}
	else {
	  current = current->left;
	}

      }
      else {

	if (current->right == 0){
	  current->right = newNode;
	  newNode->parent = current;
	  placed = true;
	}
	else {
	  current = current->right;
	}

      }

    }

  }

}


template <typename K, typename V>  bool BinarySearchTree<K,V>::contains(K k){

  BinaryTreeNode * current = root;

  while (current != 0){

    if (k == current->key) return true;

    if (k < current->key) current = current->left;
    else current = current->right;

  }

  return false;
  
}

template <typename K, typename V>  V BinarySearchTree<K,V>::find(K k){

  BinaryTreeNode * current = root;

  while (current != 0){

    if (k == current->key) return current->value;

    if (k < current->key) current = current->left;
    else current = current->right;

  }

  return V();
   

}

template <typename K, typename V>  bool BinarySearchTree<K,V>::erase(K k){

  if (!contains(k)) return false;

  BinaryTreeNode * current = root;

  while (current->key != k){

    if (k < current->key) current = current->left;
    else current = current->right;

  }

  if (current->left == 0  && current->right == 0){
    BinaryTreeNode * p = current->parent;
    if (p != 0 && current == p->left) p->left = 0;
    else if (p != 0 && current == p->right) p->right = 0;
    else root = 0;

    current->left = 0;
    current->right = 0;
    current->parent = 0;
    delete current;	
  }
  
  if (current->left != 0  && current->right == 0){
    BinaryTreeNode * p = current->parent;
    if (p != 0 && current == p->left) p->left = current->left;
    else if (p != 0 && current == p->right) p->right = current->left;
    else root = current->left;

    current->left = 0;
    current->right = 0;
    current->parent = 0;
    delete current;
    
  }
  
  if (current->left == 0  && current->right != 0){
    BinaryTreeNode * p = current->parent;
    if (p != 0 && current == p->left) p->left = current->right;
    else if (p != 0 && current == p->right) p->right = current->right;
    else root = current->right;

    current->left = 0;
    current->right = 0;
    current->parent = 0;
    delete current;
  }

  if (current->left != 0 && current->right !=0){

    BinaryTreeNode * replacement = current->right;
    while (replacement->left != 0) replacement = replacement->left;
    current->key = replacement->key;
    current->value = replacement->value;
    if (replacement->right != 0){
      BinaryTreeNode * reppar = replacement->parent;
      if (reppar == current){

	reppar->right = replacement->right;

      }
      else {

	reppar->left = replacement->right;

      }

    }

    replacement->left = 0;
    replacement->right = 0;
    replacement->parent = 0;
    delete replacement;
    
  }
 
}

template <typename K, typename V>  std::vector<V> BinarySearchTree<K,V>::inOrderRec(BinaryTreeNode * n){


  if (n == 0) return std::vector<V>();
  
  std::vector<V> vec;

  std::vector<V> left = inOrderRec(n->left);
  vec.insert(vec.end(), left.begin(), left.end());
  vec.push_back(n->value);
  std::vector<V> right = inOrderRec(n->right);
  vec.insert(vec.end(), right.begin(), right.end());

  return vec;

}

template <typename K, typename V>  std::vector<V> BinarySearchTree<K,V>::valuesInOrder(){

  return inOrderRec(root);

}

template class BinarySearchTree<int, std::string>;
