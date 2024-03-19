#include<bits/stdc++.h>
using namespace std;

int t, n, m, c;
char lastUsed;
string a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>n>>m>>a>>b;
		c=0;
		
		lastUsed=a[0];
		
		for(int i=1; i<a.size(); i++)
		{
			if(a[i]==lastUsed)
			c++;
			
			lastUsed=a[i];
		}
		
		for(int i=b.size()-1; i>=0; i--)
		{
			if(b[i]==lastUsed)
			c++;
			
			lastUsed=b[i];
		}
		
		if(c>1)
		cout<<"NO\n";
		else
		cout<<"YES\n";
	}
}
