#ifndef EXPRTREE_H
#define EXPRTREE_H

/*
 * std::queue and std::stack have been included for your
 * convenience, you don't have to build your own or anything.
 * With std::queue, the important methods are push(...), front(), pop() and empty().
 * With std::stack, the important methods are push(...), top(), pop() and empty().
 */
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib> //This is include for the atoi() function used in the to_number(string) helper function.

#include "TreeNode.h"

/*
 * The four included data types have been imported into the
 * local namespace so you don't have to write std:: all the time.
 */
using std::queue;
using std::stack;
using std::vector;
using std::string;

class ExprTree{

 private:

  TreeNode * root; //The root of the tree! What a surprise :0.
  int _size; //The number of nodes in the tree. To keep things simple,
             //it's just an int.

 public:

  /*
   * See the .cpp file for what these methods do. Note that
   * most are static, so you don't need to instantiate the class
   * to use them (same as Java).
   */
  ExprTree();
  ExprTree(TreeNode *);
  ~ExprTree();
  static vector<string> tokenise(string);
  static ExprTree buildTree(vector<string>);
  static int evaluate(TreeNode *);
  int evaluateWholeTree();

  /*
   * The parameters of the next three methods have been made
   * into const references. This is to stop the ExprTree parameter
   * being deleted when they finish. This shouldn't make a difference
   * from your perspective, you can just use the parameter as if it were
   * the object itself (just like a Java object).
   */
  static string prefixOrder(const ExprTree &);
  static string infixOrder(const ExprTree &);
  static string postfixOrder(const ExprTree &);
  int size();
  bool isEmpty();
  TreeNode * getRoot();

};

#endif
