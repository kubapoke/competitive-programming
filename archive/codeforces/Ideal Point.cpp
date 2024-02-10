#include<bits/stdc++.h>
using namespace std;

int t, n, k, l, r;
bool ifBegin, ifEnd;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		ifBegin=false; ifEnd=false;
		cin>>n>>k;
		
		for(int j=0; j<n; j++)
		{
			cin>>l>>r;
			
			if(l==k)
			ifBegin=true;
			
			if(r==k)
			ifEnd=true;
		}
		
		if(ifBegin==true&&ifEnd==true)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	
}
