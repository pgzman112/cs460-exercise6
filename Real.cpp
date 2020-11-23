#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Real.h"

using namespace std;

struct tempStrings {
  string temp1 = "";
  string temp2 = "";
  int x = 0;
  int y = 0;
};
tempStrings padZeros(string & v1, int & x, bool front);
tempStrings splitString(string & v1 );
int validDecimalPlaces(string & v1);

Real::Real(){
  value = "0.0";
  neg = false;
}

Real::Real(const Real & R){
  value = R.value;
  neg = R.neg;
}

Real::Real(const string & S){
  if(S[0] == '-'){
    neg = true;
    value = S;
    reverse(value.begin(), value.end());
    value.pop_back();
    reverse(value.begin(), value.end());
    if(value.find(".") == std::string::npos){
      value += ".0";
    }
    if(S[0] == '.'){
      reverse(value.begin(), value.end());
      value.push_back('0');
      reverse(value.begin(), value.end());
    }
  }
  else{
    neg = false;
    value = S;
    if(value.find(".") == std::string::npos){
      value += ".0";
    }
    if(S[0] == '.'){
      reverse(value.begin(), value.end());
      value.push_back('0');
      reverse(value.begin(), value.end());
    }
  }
}

Real::Real(long long W, long long D){
  string t1 = to_string(W);
  string t2 = to_string(D);
  value = t1 + "." + t2;
  if(W < 0){
    neg = true;
  }
}

Real::Real(double D){
  value = to_string(D);
  neg = false;
}

Real::~Real(){

}

Real & Real::operator = (const Real & R){
  this->value = R.value;
  this->neg = R.neg;
  return *this;
}

ostream & operator << (ostream & outs, const Real & R){
 if(R.neg == true)
  outs << "-";
 outs << R.value;
 return outs;
}

istream & operator >> (istream & ins, Real & R){
  ins >> R.value;
  if(R.value[0] == '-'){
    R.neg = true;
    reverse(R.value.begin(), R.value.end());
    R.value.pop_back();
    reverse(R.value.begin(), R.value.end());
  }
  return ins;
}

bool Real::operator == (const Real & R) const {
  if(this->value == R.value && this->neg == R.neg)
    return true;
  else
    return false;
}

bool Real::operator != (const Real & R) const {
  if(this->value == R.value && this->neg == R.neg)
    return false;
  else
    return true;
}

bool Real::operator > (const Real & R) const{
  // Check if One is negative and the other is not because it would save a lot of time.
  if(this->neg == true && R.neg != true )
    return false;
  else if(this->neg == false && R.neg == true)
    return true;
  else{
    string tempThis = this->value;
    string tempR = R.value;
    tempStrings t1 = tempStrings();
    t1 = splitString(tempThis);
    string v1Int = t1.temp1;
    string v1Dec = t1.temp2;
    t1 = splitString(tempR);
    string v2Int = t1.temp1;
    string v2Dec = t1.temp2;
    if(v1Int.length() < v2Int.length()){
      int diff = v2Int.length() - v1Int.length();
      t1 = padZeros(v1Int, diff, true);
      v1Int = t1.temp1;
    }
    else if(v2Int.length() < v1Int.length()){
      int diff = v1Int.length() - v2Int.length();
      t1 = padZeros(v2Int, diff, true);
      v2Int = t1.temp1;
    }
    if(v1Dec.length() < v2Dec.length()){
      int diff = v2Dec.length() - v1Dec.length();
      t1 = padZeros(v1Dec, diff, false);
      v1Dec = t1.temp1;
    }
    else if(v2Dec.length() < v1Dec.length()){
      int diff = v1Dec.length() - v2Dec.length();
      t1 = padZeros(v2Dec, diff, false);
      v2Dec = t1.temp1;
    }
    tempThis = v1Int + "." + v1Dec;
    tempR = v2Int + "." + v2Dec;
    for(int i = 0; i < this->value.length(); i++){
      if(tempThis[i] > tempR[i])
        return true;
      else if(tempThis[i] < tempR[i])
        return false;
    }
  }
  //if it gets to hear it means that they are the exactly the same until one of them
  // reaches its last decimal place so just return which has has a longer length than the
  // other.
  return false; // RETURN FALSE by default is they are equal, since strictly less than op.
} // END GREATER THAN OP

bool Real::operator >= (const  Real & R) const {
  // Check if One is negative and the other is not because it would save a lot of time.
  if(this->neg == true && R.neg != true )
    return false;
  else if(this->neg == false && R.neg == true)
    return true;
  else{
    string tempThis = this->value;
    string tempR = R.value;
    tempStrings t1 = tempStrings();
    t1 = splitString(tempThis);
    string v1Int = t1.temp1;
    string v1Dec = t1.temp2;
    t1 = splitString(tempR);
    string v2Int = t1.temp1;
    string v2Dec = t1.temp2;
    if(v1Int.length() < v2Int.length()){
      int diff = v2Int.length() - v1Int.length();
      t1 = padZeros(v1Int, diff, true);
      v1Int = t1.temp1;
    }
    else if(v2Int.length() < v1Int.length()){
      int diff = v1Int.length() - v2Int.length();
      t1 = padZeros(v2Int, diff, true);
      v2Int = t1.temp1;
    }
    if(v1Dec.length() < v2Dec.length()){
      int diff = v2Dec.length() - v1Dec.length();
      t1 = padZeros(v1Dec, diff, false);
      v1Dec = t1.temp1;
    }
    else if(v2Dec.length() < v1Dec.length()){
      int diff = v1Dec.length() - v2Dec.length();
      t1 = padZeros(v2Dec, diff, false);
      v2Dec = t1.temp1;
    }
    tempThis = v1Int + "." + v1Dec;
    tempR = v2Int + "." + v2Dec;
    //cout << "tempThis and tempR: " << tempThis << " " << tempR << endl;
    for(int i = 0; i < this->value.length(); i++){
      if(tempThis[i] > tempR[i])
        return true;
      else if(tempThis[i] < tempR[i])
        return false;
    }
  } // end Else
  return true;
} // End greater than or equal

bool Real::operator < (const Real & R) const{
  if(this->neg == true && R.neg != true)
    return true;
  else if(this->neg == false && R.neg == true)
    return true;
  else{
    string tempThis = this->value;
    string tempR = R.value;
    tempStrings t1 = tempStrings();
    t1 = splitString(tempThis);
    string v1Int = t1.temp1;
    string v1Dec = t1.temp2;
    t1 = splitString(tempR);
    string v2Int = t1.temp1;
    string v2Dec = t1.temp2;
    if(v1Int.length() < v2Int.length()){
      int diff = v2Int.length() - v1Int.length();
      t1 = padZeros(v1Int, diff, true);
      v1Int = t1.temp1;
    }
    else if(v2Int.length() < v1Int.length()){
      int diff = v1Int.length() - v2Int.length();
      t1 = padZeros(v2Int, diff, true);
      v2Int = t1.temp1;
    }
    if(v1Dec.length() < v2Dec.length()){
      int diff = v2Dec.length() - v1Dec.length();
      t1 = padZeros(v1Dec, diff, false);
      v1Dec = t1.temp1;
    }
    else if(v2Dec.length() < v1Dec.length()){
      int diff = v1Dec.length() - v2Dec.length();
      t1 = padZeros(v2Dec, diff, false);
      v2Dec = t1.temp1;
    }
    tempThis = v1Int + "." + v1Dec;
    tempR = v2Int + "." + v2Dec;
    for(int i = 0; i < this->value.length(); i++){
      if(tempThis[i] < tempR[i])
        return true;
      else if(tempR[i] > tempThis[i])
        return false;
    }
  } // END else
  return false; // ret false by default if they equal since strictly less than
} //END less than op

bool Real::operator <= (const Real & R) const{
  if(this->neg == true && R.neg != true)
    return true;
  else if(this->neg == false && R.neg == true)
    return true;
  else{
    string tempThis = this->value;
    string tempR = R.value;
    tempStrings t1 = tempStrings();
    t1 = splitString(tempThis);
    string v1Int = t1.temp1;
    string v1Dec = t1.temp2;
    t1 = splitString(tempR);
    string v2Int = t1.temp1;
    string v2Dec = t1.temp2;
    if(v1Int.length() < v2Int.length()){
      int diff = v2Int.length() - v1Int.length();
      t1 = padZeros(v1Int, diff, true);
      v1Int = t1.temp1;
    }
    else if(v2Int.length() < v1Int.length()){
      int diff = v1Int.length() - v2Int.length();
      t1 = padZeros(v2Int, diff, true);
      v2Int = t1.temp1;
    }
    if(v1Dec.length() < v2Dec.length()){
      int diff = v2Dec.length() - v1Dec.length();
      t1 = padZeros(v1Dec, diff, false);
      v1Dec = t1.temp1;
    }
    else if(v2Dec.length() < v1Dec.length()){
      int diff = v1Dec.length() - v2Dec.length();
      t1 = padZeros(v2Dec, diff, false);
      v2Dec = t1.temp1;
    }
    tempThis = v1Int + "." + v1Dec;
    tempR = v2Int + "." + v2Dec;
    for(int i = 0; i < this->value.length(); i++){
      if(tempThis[i] < tempR[i])
        return true;
      else if(tempThis[i] > tempR[i])
        return false;
    }
  } // END else
  return true; // If it gets here it means that they are equal therefor ret true
} // END less than or equal

Real Real::operator + (const Real & R) const{
  Real ret = Real();
  if(this->neg == true && R.neg == false){
    if(valueCompare(this->value, R.value)){
      //In this case answer will be negative and we can just return this minus that as a negative
      ret.neg = false;
      ret.value = subtraction(R.value, this->value);
      return ret;
    }
    else if(valueCompare(R.value, this->value)){
      //In this case answer will be poisitive and we can return that minus this as positive
      ret.neg = true;
      ret.value = subtraction(this->value, R.value);
      return ret;
    }
    else{
      // They are equal and since one is pos and one is neg answer will be 0
      ret.neg = false;
      ret.value = "0.0";
      return ret;
    }
  }
  else if(this->neg == false && R.neg == true){
    if(valueCompare(this->value, R.value)){
      //cout << "here 1" << endl;
      //Ans will be pos and return this - that
      ret.neg = true;
      ret.value = subtraction(R.value, this->value);
      return ret;
    }
    else if(valueCompare(R.value, this->value)){
      //Answer will be negative and return that minus this
      ret.neg = false;
      ret.value = subtraction(this->value, R.value);
      return ret;
    }
    else{
      // They are equal and since one is os and one is neg answer will be 0'
      ret.neg = false;
      ret.value = "0.0";
      return ret;
    }
  }
  else if(this->neg == true && R.neg == true){
    ret.neg = true;
    ret.value = addition(this->value, R.value);
    return ret;
  }
  else{
    ret.neg = false;
    ret.value = addition(this->value, R.value);
    return ret;
  }
  return ret;
}

Real Real::operator += (const Real & R) {
  Real ret = *this + R;
  return ret;
}

Real Real::operator ++ (){
  Real temp = Real("1");
  temp = *this + temp;
  this->value = temp.value;
  this->neg = temp.neg;
  return temp;
}

Real Real::operator ++(int){
  Real temp = Real("1");
  Real r = *this;
  temp = *this + temp;
  this->value = temp.value;
  this->neg = temp.neg;
  return r;
}

Real Real::operator - (const Real & R) const{
  Real temp = Real();
  string tempThis, tempR = "";
  tempThis = this->value;
  tempR = R.value;
  // Case 1 this is pos, that is neg
  if(this->neg == true && R.neg == false){
    temp.neg = true;
    temp.value = addition(tempThis, tempR);
  }
  else if(this->neg == false && R.neg == true){
    //return this + that (add oppsite)
    temp.neg = false;
    temp.value = addition(tempThis, tempR);
    return temp;
  }
  else if(this->neg == true && R.neg == true){
    if(valueCompare(this->value, R.value)){
      temp.neg = false;
      temp.value = subtraction(tempR, tempThis);
      return temp;
    }
    else if(valueCompare(R.value, this->value)){
      temp.neg = true;
      temp.value = subtraction(this->value, R.value);
      return temp;
    }
    else{
      temp.neg = false;
      temp.value = "0.0";
      return temp;
    }
  }
  else if(this->neg == false && R.neg == false){
    if(valueCompare(this->value, R.value)){
      temp.neg = true;
      temp.value = subtraction(R.value, this->value);
      return temp;
    }
    else if(valueCompare(R.value, this->value)){
      temp.neg = false;
      temp.value = subtraction(this->value, R.value);
      return temp;
    }
    else{
      temp.neg = false;
      temp.value = "0.0";
      return temp;
    }
  }
  return temp;
}

Real Real::operator -= (const Real & R){
  Real ret = *this - R;
  return ret;
}

Real Real::operator -- (){
  Real temp("1.0");
  *this = *this - temp;
  return *this;
}

Real Real::operator -- (int){
  Real temp("1.0");
  Real copy = *this;
  *this = *this - temp;
  return copy;
}

Real Real::operator * (const Real & R) const{
//string total = "";
Real ret = Real();
if(this->neg == true && R.neg == false){
  ret.neg = true;
}
else if(this->neg == false && R.neg == true){
  ret.neg = true;
}
else{
  ret.neg = false;
}
string v1 = this->value;
string v2 = R.value;
// CREATING STRUCT TO HOLD 2 STRINGS FOR RETURN
// TEMP1 WILL HOLD INT portion when split, and temp2 will hold DEC
tempStrings t1 = tempStrings();
t1 = splitString(v1);
string v1Int = t1.temp1;
string v1Dec = t1.temp2;
t1 = splitString(v2);
string v2Int = t1.temp1;
string v2Dec = t1.temp2;
if(v1Int.length() < v2Int.length()){
  int diff = v2Int.length() - v1Int.length();
  t1 = padZeros(v1Int, diff, true);
  v1Int = t1.temp1;
}
else if(v2Int.length() < v1Int.length()){
  int diff = v1Int.length() - v2Int.length();
  t1 = padZeros(v2Int, diff, true);
  v2Int = t1.temp1;
}
if(v1Dec.length() < v2Dec.length()){
  int diff = v2Dec.length() - v1Dec.length();
  t1 = padZeros(v1Dec, diff, false);
  v1Dec = t1.temp1;
}
else if(v2Dec.length() < v1Dec.length()){
  int diff = v1Dec.length() - v2Dec.length();
  t1 = padZeros(v2Dec, diff, false);
  v2Dec = t1.temp1;
}
int decLength = v1Dec.length() + v2Dec.length();
v1 = v1Int + v1Dec;
v2 = v2Int + v2Dec;
string total = "";
for(int i = v2.length()-1; i >= 0; i--){
  string tally = "";
  int carry = 0;
  for(int k=v2.length()-1; k>i; k--){
    tally.push_back('0');
  }
  for(int j = v1.length()-1; j >= 0; j--){
    int one = ((int)(v1[j]-48));
    int two = (int)(v2[i]-48);
    int x = (one * two) + carry;
    if(x > 9){
      string t = to_string(x);
      carry = (int)t[0]-48;
      tally.push_back(t[1]);
    }
    else{
      carry = 0;
      tally += to_string(x);
    }
  } // END inner forloop
  if(carry > 0){
    tally += to_string(carry);
  }
  if(total.length() < tally.length()){
    for(int n = 0; n < total.length() - tally.length(); n++){
      total.push_back('0');
    }
  }
  int tempLength = total.length();
  total = add2(tally, total);
} // END main forloop

reverse(total.begin(), total.end());

string decPart = "";
int counter = 0;
for(int i = total.length()-1; counter < decLength; i--){
  decPart.push_back(total[i]);
  total.pop_back();
  counter++;
}
reverse(decPart.begin(), decPart.end());
//reverse(total.begin(), total.end());
ret.value = total + "." + decPart;
while(ret.value[ret.value.length()-1] == '0' && ret.value[ret.value.length()-2] != '.'){
  ret.value.pop_back();
}
reverse(ret.value.begin(), ret.value.end());
while(ret.value[ret.value.length()-1] == '0'){
  ret.value.pop_back();
}
reverse(ret.value.begin(), ret.value.end());
if(decPart.length() == 0){
  ret.value.push_back('0');
}
if(ret.value[0] == '.'){
  ret.value = "0" + ret.value;
}
return ret;
}

Real Real::operator *= (const Real & R){
  *this = *this * R;
  return *this;
}

Real Real::operator / (const Real & R) const{
  Real tempThis = *this;
  Real tempR = R;
  Real ret = Real();
  if(this->neg == true && R.neg == false){
    ret.neg = true;
  }
  else if(this->neg == false && R.neg == true){
    ret.neg = true;
  }
  else{
    ret.neg = false;
  }
  // WE have already set ret's neg so convert to absolute value (make both pos)
  tempThis.neg = false;
  tempR.neg = false;
  Real quotient = Real();
  while(tempThis >= tempR){
    //cout << "tempThis - tempR " << tempThis << " " << tempR << endl;
    tempThis = tempThis - tempR;
    //cout << "tempThis after: " << tempThis << endl;
    quotient++;
    //cout << "Quo: " << quotient << endl;
  }
  cout << "Remainder is: " << tempThis << endl;
  ret.value = quotient.value;
  return ret;


} // END DIV OP

// Real Real::operator /= (const Real & R) {
//
// }

// This private function is meant to compare v1 and v2 based on size
// it does the same as the less than op but it ignores the negative sign
bool Real::valueCompare(const string & v1, const string & v2)const{
  string v1Temp;
  string v2Temp;
  string tempThis = v1;
  string tempR = v2;
  string ret = "";

  string tempThisInt, tempThisDec, tempRInt, tempRDec = "";
  bool f = false;
  for(int i = 0; i < tempThis.length(); i++){
    if(tempThis[i] == '.'){
      f = true;
    }
    else if(!f){
      tempThisInt.push_back(tempThis[i]);
    }
    else{
      tempThisDec.push_back(tempThis[i]);
    }
  }
  f = false;
  for(int i = 0; i < tempR.length(); i++){
    if(tempR[i] == '.'){
      f = true;
    }
    else if(!f){
      tempRInt.push_back(tempR[i]);
    }
    else{
      tempRDec.push_back(tempR[i]);
    }
  }
  string tt = "";
  if(tempThisInt.length() > tempRInt.length()){
    int diff = tempThisInt.length() - tempRInt.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempRInt = tt + tempRInt;
  }
  else{
    int diff = tempRInt.length() - tempThisInt.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempThisInt = tt + tempThisInt;
  }
  tt = "";
  if(tempThisDec.length() > tempRDec.length()){
    int diff = tempThisDec.length() - tempRDec.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempRDec = tempRDec + tt;
  }
  else{
    int diff = tempRDec.length() - tempThisDec.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempThisDec = tempThisDec + tt;
  }
  v1Temp = tempThisInt + "." + tempThisDec;
  v2Temp = tempRInt + "." + tempRDec;
  //cout << "v1 and v2: " << v1Temp << " " << v2Temp << endl;
  for(int i = 0; i < v1.length(); i++){
    if(v1Temp[i] < v2Temp[i]){
      return true;
    }
    else if(v1Temp[i] > v2Temp[i]){
      return false;
    }
  }
  //cout << "RETURNING FALSE" << endl;
  return false;
} // End valueCompare

//String addition returns string
string Real::addition(const string & v1, const string & v2) const {
  string tempThis = v1;
  string tempR = v2;
  string ret = "";

  if(tempThis.find(".") == std::string::npos){
    tempThis += ".0";
  }
  if(tempR.find(".") == std::string::npos){
    tempR += ".0";
  }
  string tempThisInt, tempThisDec, tempRInt, tempRDec = "";
  bool f = false;
  for(int i = 0; i < tempThis.length(); i++){
    if(tempThis[i] == '.'){
      f = true;
    }
    else if(!f){
      tempThisInt.push_back(tempThis[i]);
    }
    else{
      tempThisDec.push_back(tempThis[i]);
    }
  }
  f = false;
  for(int i = 0; i < tempR.length(); i++){
    if(tempR[i] == '.'){
      f = true;
    }
    else if(!f){
      tempRInt.push_back(tempR[i]);
    }
    else{
      tempRDec.push_back(tempR[i]);
    }
  }
  int numIntZerosPadded = 0;
  string tt = "";
  if(tempThisInt.length() > tempRInt.length()){
    int diff = tempThisInt.length() - tempRInt.length();
    numIntZerosPadded = diff;
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempRInt = tt + tempRInt;
  }
  else{
    int diff = tempRInt.length() - tempThisInt.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempThisInt = tt + tempThisInt;
  }
  tt = "";
  int numDecZerosPadded = 0;
  if(tempThisDec.length() > tempRDec.length()){
    int diff = tempThisDec.length() - tempRDec.length();
    numDecZerosPadded = diff;
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempRDec = tempRDec + tt;
  }
  else{
    int diff = tempRDec.length() - tempThisDec.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempThisDec = tempThisDec + tt;
  }
  tempThis = tempThisInt + "." + tempThisDec;
  tempR = tempRInt + "." + tempRDec;
  //cout << "tempThis and tempR: " << tempThis << " " << tempR << endl;
  reverse(tempThis.begin(), tempThis.end());
  reverse(tempR.begin(), tempR.end());
  int carry = 0;
  for(int i = 0; i < tempThis.length(); i++){
    if(tempThis[i] == '.' && tempR[i] == '.'){
      ret.push_back('.');
    }
    else{
      int t = 0;
      t = tempThis[i] + tempR[i] + carry;
      if(t != 48){
      t = t - 48;
      }
      if(t > 57){
        carry = 1;
        t = t - 10;
        //cout << "Pushing: " <<  t << endl;
        ret.push_back((char) t);
      }
      else{
        carry = 0;
        //cout << "Pushing: " << t << endl;
        ret.push_back((char) t);
      }
    }
  }
  if(carry > 0){
    //cout << "carry is: " << carry << endl;
    int t = carry;
    ret = ret + to_string(t);
  }
  if(ret[ret.length()-1] == '0' && ret[ret.length()-2] != '.'){
    while(ret[ret.length()-1] == '0' && ret[ret.length()-2] != '.' && numDecZerosPadded > 0){
      ret.pop_back();
      numDecZerosPadded--;
    }
  }
  reverse(ret.begin(), ret.end());
  if(ret.find(".") != std::string::npos && ret[ret.length()-1] == '0'){
    while(ret[ret.length()-1] == '0' && ret[ret.length()-2] != '.' && numIntZerosPadded > 0){
      ret.pop_back();
      numIntZerosPadded--;
    }
  }
  return ret;
}// End addition

// String substraction returns string
string Real::subtraction(const string & v1, const string & v2) const{
  string tempThis = v1;
  string tempR = v2;
  if(tempThis.find(".") == std::string::npos){
    tempThis += ".0";
  }
  if(tempR.find(".") == std::string::npos){
    tempR += ".0";
  }
  //cout << "Tthis: " << tempThis << " TR: " << tempR << endl;
  string ret = "";
  string tempThisInt, tempThisDec, tempRInt, tempRDec = "";
  bool f = false;
  for(int i = 0; i < tempThis.length(); i++){
    if(tempThis[i] == '.'){
      f = true;
    }
    else if(!f){
      tempThisInt.push_back(tempThis[i]);
    }
    else{
      tempThisDec.push_back(tempThis[i]);
    }
  }
  f = false;
  for(int i = 0; i < tempR.length(); i++){
    if(tempR[i] == '.'){
      f = true;
    }
    else if(!f){
      tempRInt.push_back(tempR[i]);
    }
    else{
      tempRDec.push_back(tempR[i]);
    }
  }
  //cout << "tempIntThis: " << tempThisInt << " TthisDec: " << tempThisDec<< endl;
  //cout << "TRInt: " << tempRInt << " TRdec: " << tempRDec << endl;
  string tt = "";
  if(tempThisInt.length() > tempRInt.length()){
    int diff = tempThisInt.length() - tempRInt.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempRInt = tt + tempRInt;
  }
  else{
    int diff = tempRInt.length() - tempThisInt.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempThisInt = tt + tempThisInt;
  }
  tt = "";
  if(tempThisDec.length() > tempRDec.length()){
    int diff = tempThisDec.length() - tempRDec.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempRDec = tempRDec + tt;
  }
  else{
    int diff = tempRDec.length() - tempThisDec.length();
    for(int i = 0; i < diff; i++){
      tt.push_back('0');
    }
    tempThisDec = tempThisDec + tt;
  }
  tempThis = tempThisInt + "." + tempThisDec;
  tempR = tempRInt + "." + tempRDec;
  reverse(tempThis.begin(), tempThis.end());
  reverse(tempR.begin(), tempR.end());
  //cout << tempThis << endl;
  //cout << tempR << endl;
  int i = 0;
  while(i < tempThis.length()){
    if(tempThis[i] == '.'  && tempR[i] == '.'){
      ret.push_back('.');
      i++;
    }
    else if(tempThis[i] < tempR[i]){
      // need to borrow
      int j = i+1;
      while(tempThis[j] == 48 || tempThis[j] == '.'){
        j++;
      }
      while(j != i){
        if(tempThis[j] != 46){
          //cout << "Borrowing at: " << (char)(tempThis[j]-1) << endl;
          tempThis[j] = tempThis[j]-1;
          j--;
          if(tempThis[j] == '.'){
            tempThis[j-1] = tempThis[j-1] + 10;
          }
          else{
            tempThis[j] = tempThis[j] + 10;
          }
        }
        else{
          //cout << "in here?" << endl;
          j--;
        }
        //cout << tempThis << " <---- TempThis " << endl;
      }
      int t = (tempThis[i] - tempR[i]);
      t = t+48;
      //cout << "Pushing: " << (int) t << endl;
      ret.push_back((char) t);
      i++;
    } // end if
    else{
      int t = (tempThis[i] - tempR[i]);
      //cout << "Pushing2: " << (int) t << endl;
      t = t + 48;
      ret.push_back((char) t);
      i++;
    }
  } // end while
  //cout << ret << endl;
  if(ret[ret.length()-1] == '0' && ret[ret.length()-2] != '.'){
    while(ret[ret.length()-1] == '0' && ret[ret.length()-2] != '.'){
      ret.pop_back();
    }
  }
  reverse(ret.begin(), ret.end());
  if(ret.find(".") != std::string::npos && ret[ret.length()-1] == '0' && ret[ret.length()-2] != '.'){
    while(ret[ret.length()-1] == '0' && ret[ret.length()-2] != '.'){
      ret.pop_back();
    }
  }
  return ret;
}// End sub

// PADS ZEROS. PLACES IN FRONT IF FRONT IS TRUE, ELSE THEY GO BEHIND
tempStrings padZeros(string & v1, int & x, bool front){
  tempStrings t1 = tempStrings();
  string zeros = "";
  for(int i = 0; i < x; i++){
    zeros.push_back('0');
  }
  if(front){
    t1.temp1 = zeros + v1;
  }
  else{
    t1.temp1 = v1 + zeros;
  }
  return t1;
}

tempStrings splitString(string & v1){
  tempStrings t1 = tempStrings();
  bool f = false;
  string tempThisInt, tempThisDec = "";
  for(int i = 0; i < v1.length(); i++){
    if(v1[i] == '.'){
      f = true;
    }
    else if(!f){
      tempThisInt.push_back(v1[i]);
    }
    else{
      tempThisDec.push_back(v1[i]);
    }
  }
  t1.temp1 = tempThisInt;
  t1.temp2 = tempThisDec;
  return t1;
}

string Real::add2(const string & v1, const string & v2) const{
  string ret = "";
  int carry = 0;
  for(int i = 0; i < v1.length(); i++){
    int t = 0;
    t = v1[i] + v2[i] + carry;
    if(t != 48){
      t = t - 48;
    }
    if(t > 57){
      carry = 1;
      t = t - 10;
      //cout << "Pushing: " <<  t << endl;
      ret.push_back((char) t);
    }
    else{
      carry = 0;
      //cout << "Pushing: " << t << endl;
      ret.push_back((char) t);
    }
  }
  if(carry > 0){
    ret = ret + to_string(carry);
  }
  return ret;
}

// TAKES IN A SPLIT STRING (NO DICIMAL POINT) AND RETURNS NUMBER IF VALID Dec
// PLACES (ESSENTIALLY RETURNS 0 IF STRING IS ALL 0S)
int validDecimalPlaces(string & v1){
  int ret = 0;
  for(int i = 0; i < v1.length(); i++){
    ret++;
  }
  return ret;
}
