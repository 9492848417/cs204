#include <bits/stdc++.h>
#include<math.h>
using namespace std;


bool isSmaller(string str1, string str2)
{
	int n1 = str1.length() ,n2 = str2.length();

	if (n1 < n2)
	return  true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (str1[i] < str2[i])
		return true;
	else if (str1[i] > str2[i])
		return false;

	return false;
}
bool small(string str1, string str2)
{
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
	return true;
	if (n2 < n1)
	return false;

	for (int i=0; i<n1; i++)
	if (str1[i] < str2[i])
		return true;
	else if (str1[i] > str2[i])
		return false;

	return true;
}
string add_one(string p){
	reverse(p.begin(),p.end());
	int n=p.size();
	int carry=0;
	int sum=(p[0]-'0')+1;
	carry=sum/10;
	p[0]=(sum%10+'0');
	for(int i=1;i<n;i++){
		if(carry==0)
		{reverse(p.begin(),p.end()); return p;}
		else{
			sum=(p[i]-'0')+carry;
			p[i]=(sum%10+'0');
			carry=sum/10;
		}
	}
	if(carry) p+=(carry+'0');
	reverse(p.begin(),p.end());
	return p;
}

string Diff(string str1, string str2)
{
	if (isSmaller(str1, str2))
		swap(str1, str2);
	string str = "";
	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int c = 0;

	for (int i=0; i<n2; i++)
	{

		int sub = ((str1[i]-'0')-(str2[i]-'0')-c);

		if (sub < 0)
		{
			sub = sub + 10;
			c = 1;
		}
		else
			c = 0;

		str.push_back(sub + '0');
	}

	for (int i=n2; i<n1; i++)
	{
		int sub = ((str1[i]-'0') - c);

		if (sub < 0)
		{
			sub = sub + 10;
			c = 1;
		}
		else
			c = 0;

		str.push_back(sub + '0');
	}

	reverse(str.begin(), str.end());

	return str;
}


string div(string p , string b){

	string ans="";
	string zero="0";
	if(isSmaller(p,b)) {return zero;}
	string r=p.substr(0,b.size());
	if(isSmaller(r,b)) {r+=p[b.size()];}
	int sz=r.size();
	while(small(b,r)){
		int i=0;
		while(small(b,r)){
			r=Diff(b,r);
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count < r.size()) {r=r.substr(count,r.size()-count);}
			else{ r="";}
			i++;
		}
		ans+=(i+'0');
		if(sz>=p.size()) break;
		r+=p[sz];
		sz++;
		int count=0;
    	for(int j=0;j<r.size();j++){
			if(r[j]!='0') break;
			else count++;
		}
		if(count<r.size()) r=r.substr(count,r.size()-count);
		else r="";
		while(isSmaller(r,b)&&sz<p.size()){
			r+=p[sz];
			sz++;
			ans+='0';
			int count=0;
			for(int j=0;j<r.size();j++){
				if(r[j]!='0') break;
				else count++;
			}
			if(count<r.size()) r=r.substr(count,r.size()-count);
			else r="";
		}
	}
	if(r.size()==0) r="0";
	return r;
}




bool prime(string p){
	int n=p.size();
        n=n/2+1;
	string b="2";
	while(b.size()<=n&&isSmaller(b,p)){
		string r=div(p,b);
		if(r=="0") return false;
		b=add_one(b);
	}
	return true;
}
int main(){
	int i,t;
	cin>>t;
	for(i=0;i<t;i++)
{
		string p;
		cin>>p;
		if(prime(p)) cout<<"Prime";
		else cout<<"Not a Prime";
	}
	return 0;
}

