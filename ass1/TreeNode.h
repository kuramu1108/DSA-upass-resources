#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <sstream>

/*
 * An enum is just a list of names or labels, so in this
 * program we can use the label "Plus" (and all the others).
 * This allows something like a finite set of values (the way
 * enums are implemented is actually a bit janky, but useful enough
 * for this case).
 * See the test files for examples of use.
 */
enum Operator {Value, Plus, Minus, Times, Divide, NoOp};

class TreeNode {

 private:

  Operator op; //If this node represents an operator, this is where it's stored.
               //It can take values from the Operator enum (i.e. Plus, Minus, etc.)
               //If it represents a value, use the Value value. :D
  int value; //If this node stores an actual number, this is it.

  TreeNode * parent; //Pointer to the parent.
  TreeNode * leftChild; //Pointer to the left child of this node.
  TreeNode * rightChild; //Pointer to the right child of this node.

 public:

  TreeNode(Operator); //Constructor to use for +, -, * and /.
                      //Example: TreeNode(Plus);
  TreeNode(int); //Constructor to use for actual numbers.
                 //Example: TreeNode(5);
  void setParent(TreeNode *); //Set the parent pointer.
  void setLeftChild(TreeNode *); //Set the left child pointer.
  void setRightChild(TreeNode *); //Set the right child pointer.
  TreeNode * getParent(); //Get the parent pointer.
  TreeNode * getLeftChild(); //Get the left child pointer.
  TreeNode * getRightChild(); //Get the right child pointer.
  int getValue(); //Returns the stored value;
  Operator getOperator(); //Returns the stored operator.
  bool isValue(); //Returns true if this node is a Value node.
  bool isOperator(); //Returns truee if this node is Plus, Minus, Times or Divide node.
  std::string toString(); //Returns a simple string representation of the node.
  
};

#endif
