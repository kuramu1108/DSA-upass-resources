#include "TreeNode.h"

TreeNode::TreeNode(Operator o){
  op = o;
  parent = 0;
  leftChild = 0;
  rightChild = 0;
}

TreeNode::TreeNode(int val){
  op = Value;
  value = val;
  parent = 0;
  leftChild = 0;
  rightChild = 0;
}

void TreeNode::setParent(TreeNode * p){ parent = p; }

void TreeNode::setLeftChild(TreeNode * l){

  if (op != Value){
    leftChild = l;
  }

}

void TreeNode::setRightChild(TreeNode * r){

  if (op != Value){
    rightChild = r;
  }

}

TreeNode * TreeNode::getParent(){ return parent; }
  
TreeNode * TreeNode::getLeftChild(){ return leftChild; }

TreeNode * TreeNode::getRightChild(){ return rightChild; }

int TreeNode::getValue(){ return value; }

Operator TreeNode::getOperator(){ return op; }

bool TreeNode::isValue(){ return op == Value; }

bool TreeNode::isOperator(){ return op != Value && op != NoOp; }

std::string TreeNode::toString(){

  if (isValue()){

    std::stringstream stream;
    stream << getValue();
    return stream.str();
    
  }

  switch (op){

  case Value : return "val";
  case Plus : return "+";
  case Minus : return "-";
  case Times : return "*";
  case Divide : return "/";
  case NoOp : return "";
  }

}
