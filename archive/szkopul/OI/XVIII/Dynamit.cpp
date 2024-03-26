#include<bits/stdc++.h>
#define N 300001
using namespace std;

int n, m, s, w, dp[2][N];
bool czyd[N]; 
vector<int> graf[N];

void dfs(int v, int pop)
{
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i]!=pop)
	dfs(graf[v][i],v);
	
	dp[1][v]=1e9;
	if(czyd[v]) dp[0][v]=0;
	else dp[0][v]=-1;
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(graf[v][i]!=pop)
		{
			if(dp[0][graf[v][i]]!=-1)
			dp[0][v]=max(dp[0][v], dp[0][graf[v][i]]+1);
			
			dp[1][v]=min(dp[1][v], dp[1][graf[v][i]]+1);
		}	
	}	
	int d1=dp[0][v]; int d2=dp[1][v];
	
	if(d1==-1) return;
	
	if(v==1)
	{
		if(d1+d2>s)
		w++;
		return;
	}
	
	if(d1+d2<=s)
	{
		dp[0][v]=-1;
		return;
	}
	
	if(s==d1)
	{
		dp[1][v]=0;
		dp[0][v]=-1;
		w++;
	}
}

int main()
{
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
	{
		cin>>czyd[i];
	}	
	for(int i=1; i<=n-1; i++)
	{
		int a, b;
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	int l=0, r=n;
	
	while(l<=r)
	{
		s=(l+r)/2;
		w=0;
		dfs(1,1);
		if(w<=m)
		r=s-1;
		else
		l=s+1;
	}
	
	cout<<r+1;
	
}
