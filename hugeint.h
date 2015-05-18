#ifdef HUGEINT_H
#define HUGEINT_H

#include<iostream>
#include<string>
using namespace std;

class HugeInt
{
 friend ostream &operator<<(ostream &,const HugeInt &)
 friend istream &operator>>(istream &,const HugeInt &)

public:
  static const int digits=45;

   HugeInt(long=0);
   HugeInt(string &);
   HugeInt(string);
   HugeInt operator+(const HugeInt &)const;
   HugeInt operator+(int)const;
   HugeInt operator+(const string &) const;
   HugeInt operator-(const HugeInt &)const;

private:
 short integer[digits];
};   
