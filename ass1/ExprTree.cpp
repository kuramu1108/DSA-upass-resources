#include "ExprTree.h"
#include <sstream>
#include <iostream>

/*
 * Helper function that tests whether a string is a non-negative integer.
 */

bool isdigit(const char & c){

  switch (c) {
  case '0' :
  case '1' :
  case '2' :
  case '3' :
  case '4' :
  case '5' :
  case '6' :
  case '7' :
  case '8' :
  case '9' : return true;
  }

  return false;
   
}

bool is_number(const std::string & s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

/*
 * Helper function that converts a string to an int.
 */
int to_number(const std::string & s){
  return atoi(s.c_str());
}

/*
 * Helper function that converts a number to a string.
 */
string to_string(const int & n){
  std::stringstream stream;
  stream << n;
  return stream.str();
}

/*
 * Helper function that creates a TreeNode with the appropriate operator
 * when given a string that's "+", "-", "*" or "/". If the string is wrong
 * it gives a NoOp value.
 */
TreeNode * createOperatorNode(const string & op){

  if (op == "+") return new TreeNode(Plus);
  if (op == "-") return new TreeNode(Minus);
  if (op == "*") return new TreeNode(Times);
  if (op == "/") return new TreeNode(Divide);
  return new TreeNode(NoOp);

}

/*
 * Basic constructor that sets up an empty Expr Tree.
 */
ExprTree::ExprTree(){
  root = 0;
  _size = 0;
}

/*
 * Constructor that takes a TreeNode and sets up an ExprTree with that node at the root.
 */
int traversal(TreeNode* n) {
  if (n != 0)
    return 1 + traversal(n->getLeftChild()) + traversal(n->getRightChild());
  return 0;
}

ExprTree::ExprTree(TreeNode * r){
  root = r;
  _size = traversal(r);
}

/*
 * Destructor to clean up the tree.
 */

void deleteNode(TreeNode* n) {
  if(n != 0) {
    deleteNode(n->getLeftChild());
    deleteNode(n->getRightChild());
    delete n;
  } 
}

ExprTree::~ExprTree(){
  deleteNode(root);
}

/*
 * This function takes a string representing an arithmetic expression and breaks
 * it up into components (number, operators, parentheses).
 * It returns the broken up expression as a vector of strings.
 */
vector<string> ExprTree::tokenise(string expression){
  vector<string> vs;
  string buffer = "";

  for (string::iterator it = expression.begin(); it != expression.end(); it++) {
    char c = *it;
    if (isdigit(c)) {
      buffer += c;
    } else if (c == ' ') {
      if (buffer != "") {
        vs.push_back(buffer);
        buffer = "";
      }
      continue;
    } else {
      if (buffer != "") {
        vs.push_back(buffer);
        buffer = "";
      }
      buffer += c;
      vs.push_back(buffer);
      buffer = "";
    }
  }
  if (buffer != "")
    vs.push_back(buffer);
  return vs;
}

void rightParenthesis(stack<string>& opstack, vector<string>& postfix) {
  while (opstack.top() != "(") {
    postfix.push_back(opstack.top());
    opstack.pop();
  }
  opstack.pop();
}

void operators(stack<string>& opstack, vector<string>& postfix, string op) {
  if (op == "+" || op == "-") {
    if (!opstack.empty()) {
      while (opstack.top() != "(") {
        postfix.push_back(opstack.top());
        opstack.pop();
        if (opstack.empty()) break;
      }
    }
  } else {
    while (!opstack.empty()) {
      postfix.push_back(opstack.top());
      opstack.pop();
    }
  }
  opstack.push(op);
}

vector<string> inToPost(vector<string> infix){
  vector<string> postfix;
  stack<string> opstack;
  for (vector<string>::iterator it = infix.begin(); it != infix.end(); it++) {
    string str = *it;
    if (is_number(str)) {
      postfix.push_back(str);
    } else {
      if (str == "(") {
        opstack.push(str);
      } else if (str == ")") {
        rightParenthesis(opstack, postfix);
      } else {
        operators(opstack, postfix, str);
      }
    }
  }
  while (!opstack.empty()) {
    postfix.push_back(opstack.top());
    opstack.pop();
  }
  return postfix;
} 

/*
 * This function takes a vector of strings representing an expression (as produced
 * by tokenise(string), and builds an ExprTree representing the same expression.
 */
ExprTree ExprTree::buildTree(vector<string> tokens){
  vector<string> postfixToken = inToPost(tokens);
  stack<TreeNode*> s;
  for (vector<string>::iterator it = postfixToken.begin(); it != postfixToken.end(); it++) {
    string str = *it;
    if (is_number(str)) {
      TreeNode* num = new TreeNode(to_number(str));
      s.push(num);
    } else {
      TreeNode* right = s.top();
      s.pop();
      TreeNode* left = s.top();
      s.pop();
      TreeNode* op = createOperatorNode(str);
      op->setLeftChild(left);
      left->setParent(op);
      op->setRightChild(right);
      right->setParent(op);
      s.push(op);
    }
  }
  ExprTree tree(s.top());
  return tree;
}

/*
 * This function takes a TreeNode and does the maths to calculate
 * the value of the expression it represents.
 */
int ExprTree::evaluate(TreeNode * n){
  if (n != 0) {
    if (n->isValue()) {
      return n->getValue();
    } else {
      if (n->getOperator() == Plus) return evaluate(n->getLeftChild()) + evaluate(n->getRightChild());
      if (n->getOperator() == Minus) return evaluate(n->getLeftChild()) - evaluate(n->getRightChild());
      if (n->getOperator() == Times) return evaluate(n->getLeftChild()) * evaluate(n->getRightChild());
      if (n->getOperator() == Divide) return evaluate(n->getLeftChild()) / evaluate(n->getRightChild());
    }
  }
  return 0;
}

/*
 * When called on an ExprTree, this function calculates the value of the
 * expression represented by the whole tree.
 */
int ExprTree::evaluateWholeTree(){
  return evaluate(root);
}

/*
 * Given an ExprTree t, this function returns a string
 * that represents that same expression as the tree in
 * prefix notation.
 */
string prefix(TreeNode* node) {
  string str = "";
  if (node != 0)
    str += node->toString() + " " + prefix(node->getLeftChild()) + prefix(node->getRightChild());
  return str;
}

string ExprTree::prefixOrder(const ExprTree & t){
  string str = prefix(t.root);
  str.pop_back();
  return str;
}

/*
 * Given an ExprTree t, this function returns a string
 * that represents that same expression as the tree in
 * infix notation.
 */
string infix(TreeNode* node) {
  string str = "";
  if (node != 0)
    str += infix(node->getLeftChild()) + node->toString() + " " + infix(node->getRightChild());
  return str;
}

string ExprTree::infixOrder(const ExprTree & t){
  string str = infix(t.root);
  str.pop_back();
  return str;
}

/*
 * Given an ExprTree t, this function returns a string
 * that represents that same expression as the tree in
 * postfix notation.
 */
string postfix(TreeNode* node) {
  string str = "";
  if (node != 0)
    str += postfix(node->getLeftChild()) + postfix(node->getRightChild()) + node->toString() + " ";
  return str;
}

string ExprTree::postfixOrder(const ExprTree & t){
  string str = postfix(t.root);
  str.pop_back();
  return str;
}

/*
 * Returns the size of the tree. (i.e. the number of nodes in it)
 */
int ExprTree::size(){ return _size; }

/*
 * Returns true if the tree contains no nodes. False otherwise.
 */
bool ExprTree::isEmpty(){ return _size == 0; }

TreeNode * ExprTree::getRoot() { return root; }
