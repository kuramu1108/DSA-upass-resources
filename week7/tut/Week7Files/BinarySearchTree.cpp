#include "BinarySearchTree.h"

BinarySearchTree::BinaryTreeNode::BinaryTreeNode(int v){

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

}

/*
 * Does the tree contain the value v?
 */
bool BinarySearchTree::contains(int v){
  
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
 
}

/*
 * Return a vector which contains the values stored
 * in the tree in sorted order. You may want to sketch 
 * a few trees as a guide to how you might achieve this.
 * (Or ask your tutor if you're stuck of course).
 */
std::vector<int> BinarySearchTree::valuesInOrder(){

}
