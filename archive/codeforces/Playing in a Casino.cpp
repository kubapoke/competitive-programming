#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
	
ll t;
cin>>t;

for(int it=0; it<t; it++)
{
	ll n, m, a, s, cnt;
	cin>>n>>m;
	
	multiset<ll> U[m];
	
	for(int i=0; i<n; i++)
	for(int j=0; j<m; j++)
	{
		cin>>a;
		U[j].insert(a);
	}	
	a=0; 
	
	for(int i=0; i<m; i++)
	{
		s=0; cnt=0;
		for(auto u: U[i])
		{
			a+=cnt*u-s;
			s+=u;
			cnt++;
		}
	}
	
	cout<<a<<"\n";
}	

}
