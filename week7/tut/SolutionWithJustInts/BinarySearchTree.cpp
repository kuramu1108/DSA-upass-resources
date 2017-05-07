#include "BinarySearchTree.h"
#include <stack>
#include <iostream>

BinarySearchTree::BinaryTreeNode::BinaryTreeNode(int v){

  value = v;
  parent = 0;
  left = 0;
  right = 0;

}

/*
 * I've filled this one out as an example. If you wish to change
 * it, that's okay, but think about how this would mesh with the
 * BinarySearchTree destructor, and what is happening here.
 */
BinarySearchTree::BinaryTreeNode::~BinaryTreeNode(){

  delete left;
  left = 0;
  delete right;
  right = 0;
  parent = 0;
  
}

/*
 * Working constructors are very important in C++.
 * There's often no default initialisation of variables,
 * so lack of caution can cause serious problems.
 */
BinarySearchTree::BinarySearchTree(){

  root = 0;

}

/*
 * The other part of the destructor. What situation might this
 * approach cause problems with?
 */
BinarySearchTree::~BinarySearchTree(){

  delete root;
  
}

/*
 * Add a new value to the tree. Remember, less than
 * goes left.
 */
void BinarySearchTree::insert(int v){

  BinaryTreeNode * n = new BinaryTreeNode(v);

  if (root == 0) root = n;
  else{

    bool placed = false;
    BinaryTreeNode * current = root;

    while (!placed){

      if (v < current->value){
	
        if (current->left == 0){
          current->left = n;
          n->parent = current;
          placed = true;

        }
        else{

          current = current->left;

        }

      }
      else{

        if (current->right == 0){

          current->right = n;
          n->parent = current;
          placed = true;

        }
        else{

          current = current->right;
          
        }

      }

    }

  }
  
}

/*
 * Does the tree contain the value v?
 */
bool BinarySearchTree::contains(int v){

  BinaryTreeNode * current = root;

  while (current != 0){
    if (v == current->value) return true;
    else if (v < current->value) current = current->left;
    else current = current->right;

  }

  return false;
  
}

/*
 * This one is for one of the advanced tasks.
 * Detailed in the tutorial sheet.

string BinarySearchTree::find(int k){

}
*/

/*
 * Remove a value from the tree. Not the easiest one to do.
 * Think about what cases you have, what do you have to do with
 * a vertex in the middle somewhere?
 */
bool BinarySearchTree::erase(int v){

  // If the tree doesn't contain the value, we can't delete it.
  if (!contains(v)) return false;

  // Otherwise we need to reorganise the tree. There are three cases:
  // 1. The node we want to remove has no children, in which case we just remove it.
  // 2. The node has one child, we move that child up to replace it.
  // 3. The node has two children, we need to traverse the tree to find a descendent
  //    that can replace it.
  BinaryTreeNode * current = root;

  while (current->value != v){

    if (v < current->value) current = current->left;
    else current = current->right;

  }

  if (current->left == 0  && current->right == 0){
    BinaryTreeNode * p = current->parent;
    if (p != 0 && current == p->left) p->left = 0;
    else if (p != 0 && current == p->right) p->right = 0;
    else if (p == 0) root = 0;

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

/*
 * Return a vector which contains the values stored
 * in the tree in sorted order. You may want to sketch 
 * a few trees as a guide to how you might achieve this.
 * (Or ask your tutor if you're stuck of course).
 */

std::vector<int> BinarySearchTree::valuesInOrder(){

  std::vector<int> vec;

  std::stack<BinaryTreeNode *> s;

  BinaryTreeNode * current = root;

  while (current != 0 || !s.empty()){
    if (current != 0){
      s.push(current);
      current = current->left;
    }
    else{
      current = s.top();
      s.pop();
      vec.push_back(current->value);
      current = current->right;
    }

  }

  return vec;

}
