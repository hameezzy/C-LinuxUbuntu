
//Hamza Ilyas
//hi3zk
//2/5/18
//postfixCalculator.cpp

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std;



PostfixCalculator::PostfixCalculator() {
  stack <int> newStack;
}

void PostfixCalculator::pushNum(int a) {
  newStack.push(a);
}

int PostfixCalculator::getTopValue() {
  return newStack.top();
}

void PostfixCalculator::addition() {
  int current = newStack.top();
  newStack.pop();
  int next = newStack.top();
  newStack.pop();
  int sum = current + next;
  newStack.push(sum);
}

void PostfixCalculator::subtraction() {
  int current = newStack.top();
  newStack.pop();
  int next = newStack.top();
  newStack.pop();
  int diff = current - next;
  newStack.push(diff);
}

void PostfixCalculator::multiplication() {
  int current = newStack.top();
  newStack.pop();
  int next = newStack.top();
  newStack.pop();
  int mult = current * next;
  newStack.push(mult);
}

void PostfixCalculator::division() {
  int current = newStack.top();
  newStack.pop();
  int next = newStack.top();
  newStack.pop();
  int div = current/next;
  newStack.push(div);
}

void PostfixCalculator::negation() {
  int current = newStack.top();
  newStack.pop();
  newStack.push(current*-1);
}

 
  


  





  
