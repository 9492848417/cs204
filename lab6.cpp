#include<bits/stdc++.h>
#include<vector>
using namespace std;
	int main()
	{
	int n,l;
	vector <int> v;
	cin >> n;
	cin >> l;
	int i,j;
	int o,u,r;
	for(i=0;i<n;i++)
	{
	v.push_back(0);
	}
	for(j=0;j<l;j++)
	{
	cin >> o;
	if(o==1)
	{
		cin >> u >> r;
		v[u-1]=v[u-1]+r;
	}
	else if(o==2)
	{
		int highest,k,p;
		p=1;
		highest=v[0];
		if(n>1)
		{	
			for(k=0;k<(n-1);k++)	
			{
				if(highest<v[k+1]) { highest=v[k+1]; p=k+2; }
			}
			if(highest==0) {cout << "no data" << "\n";}
			else { cout << p << "\n"; }
		}
	}
	}
	}

	
