#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
int t;

cin>>t;

for(int i=0; i<t; i++)
{
	int n, ct=1;
	string s;
	
	cin>>n>>s;
	
	cout<<1<<" ";
	
	for(int i=1; i<n-1; i++)
	{
		if(s[i]==s[i-1])
			ct++;
		else 
			ct=1;
		cout<<i+2-ct<<" ";
	}
	cout<<"\n";
}
}
