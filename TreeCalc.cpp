// Insert your header information here
//Hamza Ilyas
//hi3zk
//2/26/18
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include "TreeNode.h"
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  cleanTree(mystack.top());
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if (mystack.top() != NULL) {
    if (ptr -> right) {
      delete ptr -> right;
    }

    if (ptr -> left) {
      delete ptr -> left;
    }
  }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  TreeNode *myNode = new TreeNode(val);
  string add = "+";
  string divide = "/";
  string subtract = "-";
  string multiply = "*";

  if (val == add || val == divide || val == subtract || val == multiply) {
    TreeNode *one = mystack.top();
    mystack.pop();
    TreeNode *two = mystack.top();
    mystack.pop();
    myNode -> left = two;
    myNode -> right = one;
    mystack.push(myNode);
  }
  else {
    mystack.push(myNode);
  }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    // print the tree in prefix format
  cout << ptr->value << " ";
  if (ptr -> left) {
    printPrefix (ptr -> left);
  }

  if (ptr -> right) {
    printPrefix (ptr-> right);
  }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    // print tree in infix format with appropriate parentheses
  if (ptr -> left) {
    cout << "(";
    printInfix (ptr -> left);
    cout << " ";
  }

  cout << ptr->value;

  if (ptr -> right) {
    cout << " ";
    printInfix(ptr -> right);
    cout << ")";
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    // print the tree in postfix form

  if (ptr -> left) {
    printPostfix (ptr->left);
  }
  if (ptr -> right) {
    printPostfix (ptr->right);
  }
  cout << ptr->value << " ";
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (mystack.size()!=0 && mystack.top()!=NULL) {
      TreeNode *top = mystack.top();
      
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
	printPostfix(top);
        cout << endl;
	
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
	printInfix(top);
        cout << endl;
	
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
	printPrefix(top);
        cout << endl;
	
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
  string add = "+";
  string subtract = "-";
  string divide = "/";
  string multiply = "*";
  string myVal = ptr->value;

  if (myVal == add) {
    return (calculate(ptr->left) + (calculate(ptr->right)));
  }
  else if (myVal == subtract) {
    return (calculate(ptr->left) - (calculate(ptr->right)));
  }
  else if (myVal == divide) {
    return (calculate(ptr->left) / (calculate(ptr->right)));
  }
  else if (myVal == multiply) {
    return (calculate(ptr->left) * (calculate(ptr->right)));
  }
  else {
    return atoi (myVal.c_str());
  }
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    while (!mystack.empty()) {
      i = i+calculate(mystack.top());
      mystack.pop();
    }
    // call private calculate method here
    return i;
}
