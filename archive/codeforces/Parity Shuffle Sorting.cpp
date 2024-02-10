#include<bits/stdc++.h>
using namespace std;

vector<int> V;
int n, a, p;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
int t;

cin>>t;

for(int i=0; i<t; i++)
{
	V.clear();
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		V.push_back(a);
	}
	
	if(n==1)
	{
		cout<<0<<"\n";
		continue;
	}
	
	cout<<n-1<<"\n";
	cout<<1<<" "<<n<<"\n";
	
	if((V[0]+V[n-1])%2==0)
		p=V[n-1];
	else
		p=V[0];
		
	for(int i=1; i<n-1; i++)
	{
		if((V[i]+p)%2==0)
			cout<<i+1<<" "<<n<<"\n";
		else
			cout<<1<<" "<<i+1<<"\n";
	}
}
}
