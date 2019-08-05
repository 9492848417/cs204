#include <bits/stdc++.h>
using namespace std;
string
add (string str1, string str2)
{
  string p;
  int j, len1 = str1.length ();
  int len2 = str2.length ();
  if (len1 < len2)
    {
      str1.swap (str2);
      len1 = str1.length ();
      len2 = str2.length ();}
  
  string str3="";
  int a, b = 0;
  for (j = len1 - 1; j >= len1 - len2; j--)
    {
      a = (str1[j] - '0') + (str2[j - len1 + len2] - '0') + b;
      if (a >= 10)
	{
	  a = a - 10;
	  b = 1;}
      else
	{
	  b = 0;}
      str3 = to_string(a) +str3;}
  for (j = len1 - len2 - 1; j >= 0; j--)
    {
      a = (str1[j] - '0') + b;
      if (a >= 10)
	{
	  a = a - 10;
	  b = 1;
	}
      else
	{
	  b = 0;}
      str3 = to_string(a) +str3;}
  if (b == 1)
    {
      str3 = to_string(1) +str3;}

  return str3;
}
string product_single_digit(string str1,char str2)
{   int i,a;
    int len1=str1.length();
    int str2_int=str2 -'0';
    string str3="";
    int carry=0;
    for(i=len1-1;i>=0;i--)
    {
        a=str1[i]-'0';
        a=a*str2_int+carry;
        carry=a/10;
        str3=to_string(a%10)+str3;
    }
    str3=to_string(carry)+str3;
    return str3;
}

int main()
{   string str1,str2,str3,str4;
    cin>>str1;
    cin>>str2;
    int str2_len=str2.length();
    int j;
    str3="";
    for(j=str2_len-1;j>=0;j--)
    {
        str4=product_single_digit(str1,str2[j]);
        for(int k=2;k<=str2_len-j;k++)
        {
            str4=str4+"0";
        }
        str3=add(str3,str4);
    }
    cout<<str3;
    
    
    return 0;
}
