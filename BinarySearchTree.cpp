//Hamza Ilyas
//hi3zk
//3/3/18
//BinarySearchTree.cpp

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
using namespace std;

BinaryNode::BinaryNode() {
  value = "";
  left = NULL;
  right = NULL;
}  

BinarySearchTree::BinarySearchTree() {
  root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
  if (root!= NULL) {
  delete root->left;
  delete root->right;
  delete root;
  }
}

void BinarySearchTree::insert(const string& x) {
  insertHelper(x, root);
}

void BinarySearchTree::remove(const string& x) {
  root = removeHelper(x, root);
}

string BinarySearchTree::pathTo(const string& x) const {
  return pathHelper(x, root);
}

bool BinarySearchTree::find(const string& x) const {
  return findHelper(x, root);
}

int BinarySearchTree::numNodes() const {
  return numHelper(root);
}

void BinarySearchTree::insertHelper(string x, BinaryNode *&current) {
  
  if (current == NULL) {
    current = new BinaryNode();
    current->value = x;
    current->right = NULL;
    current->left = NULL;
  }

  else if (x.compare(current->value)>0) {
    insertHelper(x, current->right);
  }

  else if (x.compare(current->value)<0) {
    insertHelper(x, current->left);
  }

  else {
    ;
  }
}

string BinarySearchTree::min(BinaryNode* node) const {
  if (node->left == NULL) {
    return node->value;
  }

  return min(node->left);
}

BinaryNode* BinarySearchTree::removeHelper(const string& x, BinaryNode *&current) {
  if (current == NULL) {
    return NULL;
  }

  if (x == current->value) {
    if (current->left == NULL && current->right == NULL) {
      delete current;
      return NULL;
    }

    if (current->left == NULL) {
      return current->right;
    }

    if (current->right == NULL) {
      return current->left;
    }

    string s = min(current->right);
    current->value = s;
    current->right = removeHelper(s, current->right);
  }

  else if (x < current->value) {
    current->left = removeHelper(x, current->left);
  }

  else {
    current->right = removeHelper(x, current->right);
  }
  return current;
}

bool BinarySearchTree::findHelper(const string x, BinaryNode *const & current) const {
  if (current==NULL) {
    return false;
  }

  else if (x.compare(current->value)==0) {
    return true;
  }

  else if (x.compare(current->value)>0) {
    return findHelper(x, current->right);
  }

  else if (x.compare(current->value)<0) {
    return findHelper(x, current->left);
  }

  else {
    return false;
  }
}

string BinarySearchTree::pathHelper(const string x, BinaryNode *const & current) const {
  string direction = "";

  if (findHelper(x,current)) {
    if (x.compare(current->value)==0) {
      return current->value;
    }

    if (x.compare(current->value)!=0) {
      direction += current->value + " ";
    }

    if (x.compare(current->value)<0) {
      direction += pathHelper(x, current->left);
    }

    else {
      direction += pathHelper(x, current->right);
    }
  }
  return direction;
}

int BinarySearchTree::numHelper(BinaryNode* node) const {
  if (node == NULL) {
    return 0;
  }

  else {
    return 1 + numHelper(node->left) + numHelper(node->right);
  }
}

    


      
  


  
