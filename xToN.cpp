//Hamza Ilyas
//1-29-18
//hi3zk
//xToN.cpp

#include <iostream>
using namespace std;

int xton (int a, int b) {
  if (b == 0) {
    return 1;
  }

  if (b == 1) {
    return a;
  }

  else {
    return a * (xton(a,b-1));
  }
}


int main() {
  int x,y,value;
  cout << "Please enter the base followed by the exponent: ";
  cin >> x;
  cin >> y;
  value = xton(x,y);
  cout << x << " raised to the power of " << y << " equals " << value;
  return 0;
}
