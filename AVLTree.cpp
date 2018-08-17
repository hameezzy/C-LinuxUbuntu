//Hamza Ilyas
//hi3zk
//3/3/18
//AVLTree.cpp

#include <iostream>
#include "AVLTree.h"
#include <string>
using namespace std;

// Implement the following
AVLNode::AVLNode() {
  value = "";
  left = NULL;
  right = NULL;
  height = 0;
}

AVLTree::AVLTree() {
  root = NULL;
}

AVLTree::~AVLTree() {
  if (root != NULL) {
  delete root->right;
  delete root->left;
  delete root;
  }
}

void AVLTree::insert(const string& x) {
  insertHelper(x, root);
}

void AVLTree::insertHelper(string x, AVLNode *&current) {
  if (current == NULL) {
    current = new AVLNode();
    current->value = x;
    current->right = NULL;
    current->left = NULL;
    balance(current);
  }

  if (x.compare(current->value)>0) {
    insertHelper(x, current->right);
    balance(current);
  }

  if (x.compare(current->value)<0) {
    insertHelper(x, current->left);
    balance(current);
  }

  else {
    ;
  }

  current->height = 1 + (max(height(current->right), height(current->left)));
  //balance(current);
}

string AVLTree::pathTo(const string& x) const {
  return pathHelper(x,root);
}

string AVLTree::pathHelper(const string x, AVLNode * const &current) const {
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

bool AVLTree::find(const string& x) const {
  return findHelper(x, root);
}

bool AVLTree::findHelper (const string x, AVLNode *const &current) const {
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

int AVLTree::numNodes() const {
  return numHelper(root);
}

int AVLTree::numHelper (AVLNode *current) const {
  if (current == NULL) {
    return 0;
  }

  else {
    return 1 + numHelper(current->left) + numHelper(current->right);
  }
}

int AVLTree::balanceFactor (AVLNode *& n) {
  return (height(n->right) - height(n->left));
}

void AVLTree::balance(AVLNode*& n) {
  int b = balanceFactor(n);
  if (b == 2) {
    if (balanceFactor(n->right) == -1) {
      n->right = rotateRight(n->right);
    }
    n = rotateLeft(n);
  }

  else if (b == -2) {
    if (balanceFactor(n->left) == 1) {
      n->left = rotateLeft(n->left);
    }
    n = rotateRight(n);
  }
}

AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
  AVLNode *c = n->right;
  AVLNode *T2 = c->left;
  c->left = n;
  n->right = T2;
  n->height = max(height(n->left), height(n->right)+1);
  c->height = max(height(c->left), height(n->right)+1);
  return c;
}

AVLNode* AVLTree::rotateRight(AVLNode*& n) {
  AVLNode *c = n->left;
  AVLNode *T2 = c->right;
  c->right = n;
  n->left = T2;
  n->height = max(height(n->left), height(n->right)+1);
  c->height = max(height(c->left), height(c->right)+1);
  return c;
}

// The following are implemented for you
// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) { root = remove(root, x); }

// private helper for remove to allow recursion over different nodes. returns
// an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
  if (n == NULL) {
    return NULL;
  }
  // first look for x
  if (x == n->value) {
    // found
    // no children
    if (n->left == NULL && n->right == NULL) {
      delete n;
      return NULL;
    }
    // single child
    if (n->left == NULL) {
      return n->right;
    }
    if (n->right == NULL) {
      return n->left;
    }
    // two children -- tree may become unbalanced after deleting n
    string sr = min(n->right);
    n->value = sr;
    n->right = remove(n->right, sr);
  } else if (x < n->value) {
    n->left = remove(n->left, x);
  } else {
    n->right = remove(n->right, x);
  }
  n->height = 1 + max(height(n->left), height(n->right));
  balance(n);
  return n;
}

// max returns the greater of two integers.
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
  // go to bottom-left node
  if (node->left == NULL) {
    return node->value;
  }
  return min(node->left);
}

// height returns the value of the height field in a node. If the node is
// null, it returns -1.
int AVLTree::height(AVLNode* node) const {
  if (node == NULL) {
    return -1;
  }
  return node->height;
}
