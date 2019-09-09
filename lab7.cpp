#include <bits/stdc++.h> 
using namespace std; 
int cnum(string X,string Y)
{
	string XY=X.append(Y);
	string YX=Y.append(X);
	return XY.compare(YX)>0 ? 1:0;
};
int main()
{
int t;
vector<string> n;
string s;
cin>>t;
	for(int i=0;i<t;i++)
 		{
  			int r;
  			cin>>r;
  			for(int j=0;j<r;j++)
			{
				cin>>s;
				n.push_back(s);
			}
			sort(n.begin(),n.end(),cnum);
			for(i=0;i<n.size();i++)
			{
				cout<<n[i];
			}
 		}


}

