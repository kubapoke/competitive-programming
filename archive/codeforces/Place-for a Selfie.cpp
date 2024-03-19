#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll res(ll a, ll b, ll c, ll k)
{
	return ((b-k) * (b-k)) - (4*a*c);
}

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
	
int t;
ll x, y, a, b, c;

cin>>t;

for(int iter=0; iter<t; iter++)
{
	cin>>x>>y;
	
	set<ll> S;
	
	for(int i=0; i<x; i++)
	{
		cin>>a;
		S.insert(a);
	}
	
	for(int i=0; i<y; i++)
	{
		cin>>a>>b>>c;
		
		auto it=S.lower_bound(b);
		if(it!=S.end() && res(a,b,c,*it)<0)
		{
			cout<<"YES\n"<<*it<<"\n";
			continue;
		}
		
		if(it!=S.begin())
		it--;
		
		if(it!=S.end() && res(a,b,c,*it)<0)
		{
			cout<<"YES\n"<<*it<<"\n";
			continue;
		}
		
		cout<<"NO\n";
	}
	
	cout<<"\n";
}
}
