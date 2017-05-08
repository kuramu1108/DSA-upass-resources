#define CXXTEST_HAVE_EH
#define CXXTEST_ABORT_TEST_ON_FAIL
#include <cxxtest/TestSuite.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

#include "ExprTree.h"

class Management : public CxxTest::GlobalFixture{

public:

  float score;

  bool setUpWorld(){
    score = 0;
    return true;
  }

  bool tearDownWorld(){
    std::cout << std::endl << "Final Score: " << score << std::endl;
    return true;
  }
  
};

static Management management;

class Assignment1Tests : public CxxTest::TestSuite{

public:

  void testBasicConstructor(void){
    ExprTree t;
    TS_ASSERT_EQUALS(t.size(), 0);
    TS_ASSERT(t.isEmpty());
    TS_ASSERT_EQUALS(t.getRoot(), (void *)0);
    management.score += 3;
  }

  void testTreeConstructorWithNode(){

    TreeNode * p = new TreeNode(Plus);
    TreeNode * o = new TreeNode(1);
    TreeNode * t = new TreeNode(2);

    o->setParent(p);
    t->setParent(p);
    p->setLeftChild(o);
    p->setRightChild(t);

    ExprTree tree(p);
    
    TS_ASSERT_EQUALS(tree.getRoot(), p);
    TS_ASSERT_EQUALS(tree.getRoot()->getLeftChild(), o);
    TS_ASSERT_EQUALS(tree.getRoot()->getRightChild(), t);
    TS_ASSERT_EQUALS(tree.size(), 3);
    TS_ASSERT(!tree.isEmpty());
    management.score += 3.5;

    //delete p;
    //delete o;
    //delete t;

  }

  void testTokenise(){

    std::string expr1 = "1 + 2";
    std::string expr2 = "1 * 2";
    std::string expr3 = "1 - 2";
    std::string expr4 = "1 / 2";
    std::string expr5 = "(1 + 2)";
    std::string expr6 = "1 + 2 * 3";

    std::stringstream stream;
    stream << std::rand() % 10000;
    std::string expr7 = stream.str();

    std::vector<std::string> output;

    output = ExprTree::tokenise(expr1);

    TS_ASSERT_EQUALS(output.size(), 3);
    TS_ASSERT_EQUALS(output[0], "1");
    TS_ASSERT_EQUALS(output[1], "+");
    TS_ASSERT_EQUALS(output[2], "2");

    management.score++;

    output = ExprTree::tokenise(expr2);

    TS_ASSERT_EQUALS(output.size(), 3);
    TS_ASSERT_EQUALS(output[0], "1");
    TS_ASSERT_EQUALS(output[1], "*");
    TS_ASSERT_EQUALS(output[2], "2");

    management.score++;

    output = ExprTree::tokenise(expr3);

    TS_ASSERT_EQUALS(output.size(), 3);
    TS_ASSERT_EQUALS(output[0], "1");
    TS_ASSERT_EQUALS(output[1], "-");
    TS_ASSERT_EQUALS(output[2], "2");

    management.score++;

    output = ExprTree::tokenise(expr4);

    TS_ASSERT_EQUALS(output.size(), 3);
    TS_ASSERT_EQUALS(output[0], "1");
    TS_ASSERT_EQUALS(output[1], "/");
    TS_ASSERT_EQUALS(output[2], "2");

    management.score++;

    output = ExprTree::tokenise(expr5);

    TS_ASSERT_EQUALS(output.size(), 5);
    TS_ASSERT_EQUALS(output[0], "(");
    TS_ASSERT_EQUALS(output[1], "1");
    TS_ASSERT_EQUALS(output[2], "+");
    TS_ASSERT_EQUALS(output[3], "2");
    TS_ASSERT_EQUALS(output[4], ")");

    management.score++;

    output = ExprTree::tokenise(expr6);

    TS_ASSERT_EQUALS(output.size(), 5);
    TS_ASSERT_EQUALS(output[0], "1");
    TS_ASSERT_EQUALS(output[1], "+");
    TS_ASSERT_EQUALS(output[2], "2");
    TS_ASSERT_EQUALS(output[3], "*");
    TS_ASSERT_EQUALS(output[4], "3");

    management.score += 1.5;

    output = ExprTree::tokenise(expr7);

    TS_ASSERT_EQUALS(output.size(), 1);
    TS_ASSERT_EQUALS(output[0], expr7);

    management.score++;

  }

  void testBuildTreeSingleValue(){

    std::vector<std::string> vec;
    int val = std::rand() % 10000;

    std::stringstream stream;
    stream << val;
    vec.push_back(stream.str());

    ExprTree t = ExprTree::buildTree(vec);
    TS_ASSERT(!t.isEmpty());
    TS_ASSERT_EQUALS(t.getRoot()->getValue(), val);

    management.score++;    

  }

  void testBuildTreeSingleAddition(){

    std::vector<std::string> vec;
    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;

    std::stringstream stream;
    stream << val1;
    vec.push_back(stream.str());
    stream.str(std::string());
    
    vec.push_back("+");

    stream << val2;
    vec.push_back(stream.str());

    ExprTree t = ExprTree::buildTree(vec);
    TS_ASSERT_DIFFERS(t.getRoot(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getValue(), val1);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getValue(), val2);

    management.score += 2;

  }

  void testBuildTreeMultipleAdditionLeftAssociative(){

    std::vector<std::string> vec;
    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    std::stringstream stream;
    stream << val1;
    vec.push_back(stream.str());
    stream.str(std::string());
    
    vec.push_back("+");

    stream << val2;
    vec.push_back(stream.str());
    stream.str(std::string());

    vec.push_back("+");

    stream << val3;
    vec.push_back(stream.str());
    stream.str(std::string());

    vec.push_back("+");

    stream << val4;
    vec.push_back(stream.str());
    stream.str(std::string());
    

    ExprTree t = ExprTree::buildTree(vec);
    TS_ASSERT(!t.isEmpty());
    TS_ASSERT_EQUALS(t.getRoot()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getValue(), val4);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild()->getRightChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getRightChild()->getValue(), val3);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild()->getLeftChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getLeftChild()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild()->getLeftChild()->getRightChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getLeftChild()->getRightChild()->getValue(), val2);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild()->getLeftChild()->getLeftChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getLeftChild()->getLeftChild()->getValue(), val1);

    management.score += 2;

  }

    void testBuildTreeMultipleAdditionRightAssociative(){

    std::vector<std::string> vec;
    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    std::stringstream stream;
    stream << val1;
    vec.push_back(stream.str());
    stream.str(std::string());
    
    vec.push_back("+");

    stream << val2;
    vec.push_back(stream.str());
    stream.str(std::string());

    vec.push_back("+");

    stream << val3;
    vec.push_back(stream.str());
    stream.str(std::string());

    vec.push_back("+");

    stream << val4;
    vec.push_back(stream.str());
    stream.str(std::string());
    

    ExprTree t = ExprTree::buildTree(vec);
    TS_ASSERT(!t.isEmpty());
    TS_ASSERT_EQUALS(t.getRoot()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getValue(), val1);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild()->getLeftChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getLeftChild()->getValue(), val2);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild()->getRightChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getRightChild()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild()->getRightChild()->getLeftChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getRightChild()->getLeftChild()->getValue(), val3);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild()->getRightChild()->getRightChild(), (void*)0);
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getRightChild()->getRightChild()->getValue(), val4);

    management.score += 2;

  }

  void testBuildTreeAdditionMultiplication(){

    std::vector<std::string> vec;
    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    
    std::stringstream stream;
    stream << val1;
    vec.push_back(stream.str());
    stream.str(std::string());
    
    vec.push_back("*");

    stream << val2;
    vec.push_back(stream.str());
    stream.str(std::string());

    vec.push_back("+");

    stream << val3;
    vec.push_back(stream.str());
    stream.str(std::string());

    ExprTree t = ExprTree::buildTree(vec);
    TS_ASSERT(!t.isEmpty());
    TS_ASSERT_EQUALS(t.getRoot()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getOperator(), Times);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild()->getLeftChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getLeftChild()->getValue(), val1);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild()->getRightChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getRightChild()->getValue(), val2);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getValue(), val3);

    management.score += 2;
  }

  void testBuildTreeParentheses(){

    std::vector<std::string> vec;
    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    
    std::stringstream stream;
    stream << val1;
    vec.push_back(stream.str());
    stream.str(std::string());
    
    vec.push_back("*");

    vec.push_back("(");

    stream << val2;
    vec.push_back(stream.str());
    stream.str(std::string());

    vec.push_back("+");

    stream << val3;
    vec.push_back(stream.str());
    stream.str(std::string());

    vec.push_back(")");

    ExprTree t = ExprTree::buildTree(vec);
    TS_ASSERT(!t.isEmpty());
    TS_ASSERT_EQUALS(t.getRoot()->getOperator(), Times);
    TS_ASSERT_DIFFERS(t.getRoot()->getLeftChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getLeftChild()->getValue(), val1);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getOperator(), Plus);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild()->getLeftChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getLeftChild()->getValue(), val2);
    TS_ASSERT_DIFFERS(t.getRoot()->getRightChild()->getRightChild(), (void*)0);    
    TS_ASSERT_EQUALS(t.getRoot()->getRightChild()->getRightChild()->getValue(), val3);

    management.score += 3;
  }

  void testEvaluateValue(){

    int val1 = std::rand() % 10000;

    TreeNode * nv1 = new TreeNode(val1);

    TS_ASSERT_EQUALS(ExprTree::evaluate(nv1), val1);

    management.score++;

    //delete nv1;

  }

  void testEvaluateSimpleAddition(){

    TreeNode * np1 = new TreeNode(Plus);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);

    np1->setLeftChild(nv1);
    np1->setRightChild(nv2);
    nv1->setParent(np1);
    nv2->setParent(np1);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), val1 + val2);

    management.score++;

    //delete np1;
    //delete nv1;
    //delete nv2;
    
  }

  void testEvaluateAddition(){

    TreeNode * np1 = new TreeNode(Plus);
    TreeNode * np2 = new TreeNode(Plus);
    TreeNode * np3 = new TreeNode(Plus);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    int sum = val1 + val2 + val3 + val4;
    
    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);
    TreeNode * nv3 = new TreeNode(val3);
    TreeNode * nv4 = new TreeNode(val4);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(np2);
    np2->setParent(np1);
    np2->setLeftChild(nv2);
    nv2->setParent(np2);
    np2->setRightChild(np3);
    np3->setParent(np2);
    np3->setLeftChild(nv3);
    nv3->setParent(np3);
    np3->setRightChild(nv4);
    nv4->setParent(np3);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), sum);

    management.score++;

    np1->setLeftChild(np2);
    np2->setParent(np1);
    np1->setRightChild(nv1);
    nv1->setParent(np1);
    np2->setLeftChild(nv2);
    nv2->setParent(np2);
    np2->setRightChild(np3);
    np3->setParent(np2);
    np3->setLeftChild(nv3);
    nv3->setParent(np3);
    np3->setRightChild(nv4);
    nv4->setParent(np3);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), sum);

    management.score++;

    np1->setLeftChild(np2);
    np2->setParent(np1);
    np1->setRightChild(np3);
    np3->setParent(np1);
    np2->setLeftChild(nv1);
    nv1->setParent(np2);
    np2->setRightChild(nv2);
    nv2->setParent(np2);
    np3->setLeftChild(nv3);
    nv3->setParent(np3);
    np3->setRightChild(nv4);
    nv4->setParent(np3);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), sum);

    management.score++;

    //delete np1;
    //delete np2;
    //delete np3;
    //delete nv1;
    //delete nv2;
    //delete nv3;
    //delete nv4;

  }

  void testEvaluateSimpleSubtraction(){

    TreeNode * np1 = new TreeNode(Minus);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % val1;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(nv2);
    nv2->setParent(np1);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), val1 - val2);

    management.score++;

    //delete np1;
    //delete nv1;
    //delete nv2;

  }

  void testEvaluateSimpleMultiplication(){

    TreeNode * np1 = new TreeNode(Times);

    int val1 = std::rand() % 10000 + 1;
    int val2 = std::rand() % 10000 + 1;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(nv2);
    nv2->setParent(np1);


    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), val1 * val2);

    management.score++;

    //delete np1;
    //delete nv1;
    //delete nv2;
    
  }

  void testEvaluateSimpleDivision(){

    TreeNode * np1 = new TreeNode(Divide);

    int val1 = std::rand() % 10000 + 1;
    int val2 = std::rand() % 10000 + 1;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(nv2);
    nv2->setParent(np1);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), val1 / val2);

    management.score++;

    //delete np1;
    //delete nv1;
    //delete nv2;    

  }

  void testEvaluateFullExpression(){

    TreeNode * np1 = new TreeNode(Plus);
    TreeNode * np2 = new TreeNode(Minus);
    TreeNode * np3 = new TreeNode(Times);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);
    TreeNode * nv3 = new TreeNode(val3);
    TreeNode * nv4 = new TreeNode(val4);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(np2);
    np2->setParent(np1);
    np2->setLeftChild(np3);
    np3->setParent(np2);
    np2->setRightChild(nv2);
    nv2->setParent(np2);
    np3->setLeftChild(nv3);
    nv3->setParent(np3);
    np3->setRightChild(nv4);
    nv4->setParent(np3);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np1), val1 + ((val3 * val4) - val2));

    np1->setLeftChild(nv3);
    nv3->setParent(np1);
    np1->setRightChild(nv4);
    nv4->setParent(np1);
    np2->setLeftChild(nv1);
    nv1->setParent(np2);
    np2->setRightChild(nv2);
    nv2->setParent(np2);
    np3->setLeftChild(np2);
    np2->setParent(np3);
    np3->setRightChild(np1);
    np1->setParent(np3);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np3), (val1 - val2) * (val3 + val4));

    np1->setLeftChild(nv3);
    nv3->setParent(np1);
    np1->setRightChild(nv4);
    nv4->setParent(np1);
    np2->setLeftChild(np3);
    np3->setParent(np2);
    np2->setRightChild(np1);
    np1->setParent(np2);
    np3->setLeftChild(nv1);
    nv1->setParent(np3);
    np3->setRightChild(nv2);
    nv2->setParent(np3);

    TS_ASSERT_EQUALS(ExprTree::evaluate(np2), (val1 * val2) - (val3 + val4));

    management.score += 2;

    //delete np1;
    //delete np2;
    //delete np3;
    //delete nv1;
    //delete nv2;
    //delete nv3;
    //delete nv4;    
    
  }

  void testEvaluateWholeTree(){

    TreeNode * np1 = new TreeNode(Plus);
    TreeNode * np2 = new TreeNode(Plus);
    TreeNode * np3 = new TreeNode(Plus);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    int sum = val1 + val2 + val3 + val4;
    
    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);
    TreeNode * nv3 = new TreeNode(val3);
    TreeNode * nv4 = new TreeNode(val4);

    np1->setLeftChild(nv1);
    np1->setRightChild(np2);
    np2->setLeftChild(nv2);
    np2->setRightChild(np3);
    np3->setLeftChild(nv3);
    np3->setRightChild(nv4);

    ExprTree t(np1);

    TS_ASSERT_EQUALS(t.evaluateWholeTree(), sum);

    management.score += 4;   
    
  }

  void testPrefixOrder(){

    Operator randOp1 = Operator(std::rand() % 4 + 1);
    Operator randOp2 = Operator(std::rand() % 4 + 1);
    Operator randOp3 = Operator(std::rand() % 4 + 1);

    TreeNode * np1 = new TreeNode(randOp1);
    TreeNode * np2 = new TreeNode(randOp2);
    TreeNode * np3 = new TreeNode(randOp3);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);
    TreeNode * nv3 = new TreeNode(val3);
    TreeNode * nv4 = new TreeNode(val4);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(np2);
    np2->setParent(np1);
    np2->setLeftChild(nv2);
    nv2->setParent(np2);
    np2->setRightChild(np3);
    np3->setParent(np2);
    np3->setLeftChild(nv3);
    nv3->setParent(np3);
    np3->setRightChild(nv4);
    nv4->setParent(np3);
    
    std::stringstream stream;
    stream << np1->toString() << " " << val1 << " " << np2->toString() << " " << val2 << " " << np3->toString() << " " << val3 << " " << val4;

    ExprTree t(np1);

    TS_ASSERT_EQUALS(ExprTree::prefixOrder(t), stream.str());

    management.score += 4; 

  }

  void testInfixOrder(){

    Operator randOp1 = Operator(std::rand() % 4 + 1);
    Operator randOp2 = Operator(std::rand() % 4 + 1);
    Operator randOp3 = Operator(std::rand() % 4 + 1);

    TreeNode * np1 = new TreeNode(randOp1);
    TreeNode * np2 = new TreeNode(randOp2);
    TreeNode * np3 = new TreeNode(randOp3);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);
    TreeNode * nv3 = new TreeNode(val3);
    TreeNode * nv4 = new TreeNode(val4);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(np2);
    np2->setParent(np1);
    np2->setLeftChild(nv2);
    nv2->setParent(np2);
    np2->setRightChild(np3);
    np3->setParent(np2);
    np3->setLeftChild(nv3);
    nv3->setParent(np3);
    np3->setRightChild(nv4);
    nv4->setParent(np3);

    std::stringstream stream;
    stream << val1 << " " << np1->toString() << " " << val2 << " " << np2->toString() << " " << val3 << " " << np3->toString() << " " << val4;

    ExprTree t(np1);

    TS_ASSERT_EQUALS(ExprTree::infixOrder(t), stream.str());

    management.score += 4; 
  }

  void testPostfixOrder(){

    Operator randOp1 = Operator(std::rand() % 4 + 1);
    Operator randOp2 = Operator(std::rand() % 4 + 1);
    Operator randOp3 = Operator(std::rand() % 4 + 1);

    TreeNode * np1 = new TreeNode(randOp1);
    TreeNode * np2 = new TreeNode(randOp2);
    TreeNode * np3 = new TreeNode(randOp3);

    int val1 = std::rand() % 10000;
    int val2 = std::rand() % 10000;
    int val3 = std::rand() % 10000;
    int val4 = std::rand() % 10000;

    TreeNode * nv1 = new TreeNode(val1);
    TreeNode * nv2 = new TreeNode(val2);
    TreeNode * nv3 = new TreeNode(val3);
    TreeNode * nv4 = new TreeNode(val4);

    np1->setLeftChild(nv1);
    nv1->setParent(np1);
    np1->setRightChild(np2);
    np2->setParent(np1);
    np2->setLeftChild(nv2);
    nv2->setParent(np2);
    np2->setRightChild(np3);
    np3->setParent(np2);
    np3->setLeftChild(nv3);
    nv3->setParent(np3);
    np3->setRightChild(nv4);
    nv4->setParent(np3);

    std::stringstream stream;
    stream << val1 << " " << val2 << " " << val3 << " " << val4 << " " << np3->toString() << " " << np2->toString() << " " << np1->toString();
    
    ExprTree t(np1);

    TS_ASSERT_EQUALS(ExprTree::postfixOrder(t), stream.str());

    management.score += 4;
    
  }
  
};
