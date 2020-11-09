#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Real.h"

int main(){
  Real num1("81.0");
  Real num2("9.0");
  Real num3 = Real();
  num3 = num1 + num2;
  cout << "n1 + n2 = " << num3 << endl;
  num3 = num1 - num2;
  cout << "n1 - n2 = " << num3 << endl;
  num3 = num2 - num1;
  cout << "n2 - n1 = " << num3 << endl;
  num3 = num2 + num1;
  cout << "n2 + n1 = " << num3 << endl;
  num3 = num1 * num2;
  cout << num1 << " * " << num2 << " = " << num3 << endl;
  num3 *= num2;
  cout << "testing *= " << num3 << endl;
  num3 = num1 / num2;
  cout << "Testing num1 / num2: " << num3 << endl;


  return 0;
}
