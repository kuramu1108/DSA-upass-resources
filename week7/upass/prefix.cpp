string prefix(TreeNode* node) {
   string str = "";
   if (node != 0)
      str += node->toString() + " " + prefix(node->getLeftChild()) + prefix(node->getRightChild());
   return str;
}

string ExprTree::prefixOrder(const ExprTree & t){
   string str = prefix(t.getRoot());
   str.pop_back();
   return str;
}
