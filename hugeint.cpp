#include<iostream>
#include<cstring>
#include<cctype>//for isdigit
#include"hugeint.h"
using namespace std;

 HugeInt::HugeInt(long value){//long type of integer
  for(int i=0;i<digits;++i)
  integer[i]=0;
//place digits
   for(j=digits-1;value!=0&&j>=0;j--)
  {
     integer[j]=value%10;
     value=value/10;
  }
}

 HugeInt::HugeInt(const string &variable){
  for(int i=0;i<digits;++i)
  integer[i]=0;//initialize
  int len=variable.size();

  for(j=digits-len,k=0;j<digits;j++,k++){
   if(isdigit(variable[k])//check digits
    integer[j]=variable[k]-'0';
  }
}

 HugeInt::HugeInt(string result){}

 HugeInt::ostream &operator <<(ostream&out,const HugeInt &answer)
 {
   for(int i=0;((i<=HugeInt::digits)&&(answer.integer[i]==0);++i);
    if(i==HugeInt::digits)
       out<<0;
    else
       for(;i<HugeInt::digits;i++)
        out<<answer.integer[i];
     return out;
}
   
 }

 HugeInt::istream &operator >>(istream &in,const HugeInt &n)
{
 
  for(int i=0;i<n.size();i++)
  { 
    in>>n.integer[i];
  }
  return in;
}

 HugeInt::HugeInt operator+(int ob2)const
{
   return *this+HugeInt(ob2);
}

HugeInt::HugeInt operator+(int &ob2)const
{
 return *this +HugeInt(ob2);
}

 HugeInt::HugeInt operator+(const HugeInt &ob2)const
{
  HugeInt temp1;
  int move=0;//進位
  
  for(int i=digits-1;i>=0;i--)
  {
   temp1.integer[i]=integer[i]+ob2.integer[i]+move;
   
       if(temp1.integer[i]>9)
    {
       temp1.integer[i]=temp1.integer[i]%10;
       move=1;
   } 
    else
     move=0;
  }
  return temp1;
}

 HugeInt::HugeInt operator-(const HugeInt &ob1)const
{
  HugeInt temp2;
  for(int i=digits-1;i>=0;i--)
  {
    temp2.integer[i]=ob1.integer[i]-integer[i];
      if(temp2.integer[i]<0)
   {
     temp2.integer[i]=10+temp2.integer[i];
     temp2.integer[i+1]=temp2.integer[i+1]-1;
    }
  return temp2;
}


