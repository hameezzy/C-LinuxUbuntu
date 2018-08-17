//Hamza Ilyas
//hi3zk
//2/5/18
//postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;


class PostfixCalculator {
 public:
  PostfixCalculator();
  void pushNum(int a);
  int getTopValue();
  void addition();
  void subtraction();
  void multiplication();
  void division();
  void negation();
 private:
  stack <int> newStack;
};
#endif
