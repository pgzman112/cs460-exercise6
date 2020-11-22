#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Real.h"

int main(){
  Real num1("81.0");
  Real num2("9.0");
  Real num3 = Real();
  cout << "Testing output operator: " << endl;
  cout << "num1: " << num1 << " num2: " << num2 << endl << endl;
  cout << "Testing addition and subtraction: " << endl;
  num3 = num1 + num2;
  cout << num1 << " + " << num2 << " = " << num3 << endl;
  num3 = num1 - num2;
  cout << num1 << " - " << num2 << " = " << num3 << endl;
  num3 = num2 - num1;
  cout << num2 << " - " << num1 << " = " << num3 << endl;
  num3 = num2 + num1;
  cout << num2 << " + " << num1 << " = " << num3 << endl << endl;
  cout << "Testing assignment op and adding different numbers" << endl;
  Real num4("-9.0");
  num1 = num4;
  cout << "num1 should now equal num4: " << num1 << " = " << num4 << endl;
  num3 = num1 + num2;
  cout << num1 << " + " << num2 << " = " << num3 << endl;
  num3 = num1 * num2;
  cout << num1 << " * " << num2 << " = " << num3 << endl;
  cout << "testing *= on: " << num3 << " and " << num2 << " = ";
  num3 *= num2;
  cout << num3 << endl;
  Real num5("81");
  num3 = num5 / num2;
  cout << "Testing " << num5 << " divided by " << num3 << " = " << num3 << endl << endl;

  cout << "Testing Less than" << endl;
  if(num2 < num5){
    cout << num2 << " is less than " << num5 << endl;
  }
  else{
    cout << num2 << " is not less than " << num5 << endl;
  }

  cout << "Testing less than or equal" << endl;
  if(num5 <= num5){
    cout << num5 << " is less than or equal too " << num5 << endl;
  }
  else{
    cout << num5 << " is not less than or equal too " << num5 << endl;
  }

  cout << "Testing Greater than" << endl;
  if(num5 > num2){
    cout << num5 << " is greater than " << num2 << endl;
  }
  else{
    cout << num5 << " is not greater than " << num2 << endl;
  }

  cout << "Testing Greater than or equal " << endl;
  if(num5 >= num5){
    cout << num5 << " is greater than or equal to " << num5 << endl;
  }
  else{
    cout << num5 << " is not greater than or equal to " << num5 << endl;
  }

  cout << endl;
  cout << "Testing input op with -3.3 and num9" << endl;
  stringstream ss;
  ss << -3.3;
  Real num9 = Real();
  ss >> num9;
  cout << "num9 after input op: " << num9 << endl;

  Real num10 = Real("0.0");
  Real num11 = Real("1.0");
  Real num12 = Real();
  cout << "num10 before: " << num10 << endl;
  cout << "Testing preDEC: " << --num10 << endl;
  cout << "Num10 before postDec: " << num10 << endl;
  cout << "num10-- " << num10-- << endl;
  cout << "num10 after the postDec " << num10 << endl;


  Real num20 = Real("0.05");
  Real num21 = Real("12.0");
  num20 = num20 * num21;
  cout << "NUM20 = " << num20 << endl;

  return 0;
}
