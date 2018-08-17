//Hamza Ilyas
//hi3zk
//2/5/18
//testPostfixCalc.cpp

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std;

int main () {
  PostfixCalculator p;
  p.pushNum(1);
  p.pushNum(2);
  p.pushNum(3);
  p.pushNum(4);
  p.pushNum(5);
  p.addition();
  p.subtraction();
  p.addition();
  p.negation();

  cout<<"Result is: "<< p.getTopValue() << endl;
  return 0;
}
  

