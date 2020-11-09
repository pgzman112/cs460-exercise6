#pragma once
#include <iostream>

using namespace std;

class Real {
  public:
    Real();
    Real(const Real & R);
    Real(const string & S);
    Real (long long W, long long D);
    Real (double D);
    ~Real();
    Real & operator = (const Real & R);
    friend ostream & operator << (ostream & outs, const Real & R);
    friend istream & operator >> (istream & ins, Real & R);
    bool operator == (const Real & R) const;
    bool operator != (const Real & R) const;
    bool operator > (const Real & R) const;
    bool operator >= (const Real & R) const;
    bool operator < (const Real & R) const;
    bool operator <= (const Real & R) const;
    Real operator + (const Real & R) const;
    Real operator += (const Real & R);
    Real operator ++ ();
    Real operator ++ (int);
    Real operator - (const Real & R) const;
    Real operator -= (const Real & R);
    Real operator -- ();
    Real operator -- (int);
    Real operator * (const Real & R) const;
    Real operator *= (const Real & R);
    Real operator / (const Real & R) const; // Extra Credit
    Real operator /= (const Real & R); // Extra Credit

  private:
    string value;
    bool neg;
    bool valueCompare(const string & v1, const string & v2) const;
    string addition(const string & v1, const string & v2) const;
    string subtraction(const string & v1, const string & v2) const;
    string add2(const string & v1, const string & v2) const;
    //tempStrings padZeros(const string & v1, const string & v2) const;
    // bool neg;
    // double num;
    // double whole;
    // int carry;
    // int improperFracNum;
    // int leading;
    // int numerator;
    // int precision;
    // int real;
    // int whole;
    // long double prefix
    // long double suffix;
    // long long decimal;
    // long long DeciPart;
    // long long exp;
    // long long int fraction;
    // long long int Whole;
    // long long int front;
    // long long intPart;
    // long long mantissa;
    // long long nonDec;
    // long long w, d;
    // string decimal;
    // unsigned denominator;

};
