#include<bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> graf[300001];

int dp(int v, int p, int k)
{
	int sum=0;
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(graf[v][i]!=p)
		sum+=dp(graf[v][i],v,k)+1;
	}
	
	return max(0,sum-k);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	int p, k, m;
	p=0; k=n; m=(p+k)/2;
	
	while(p<=k)
	{
		if(dp(1,1,m)==0)
		k=m-1;
		else
		p=m+1;
		
		m=(p+k)/2;
	}
	
	cout<<k+1;
}
