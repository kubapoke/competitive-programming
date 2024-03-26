#include<bits/stdc++.h>
#define N 200001
using namespace std;

int n, a, b, dp[N], w;
vector<int> E[N];

void dfs(int v, int p)
{
	int x=-1, y=-1, l=0;
	
	for(int i=0; i<E[v].size(); i++)
	{
		if(E[v][i]!=p)
		{
			dfs(E[v][i],v);
			
			l++;
			
			if(dp[E[v][i]]>x)
			{
				y=x;
				x=dp[E[v][i]];
			}
			else if(dp[E[v][i]]>y)
			y=dp[E[v][i]];
		}
	}
	
	if(x!=-1&&y==-1)
	{
		w=max(w, x+l-1+(v!=1));
		dp[v]=max(1,x);
	}
	if(x!=-1&&y!=-1)
	{
		w=max(w, x+l-1+(v!=1));
		w=max(w, x+y+l-2+(v!=1));
		dp[v]=max(x+l-1,l);
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	dfs(1,0);
	
	cout<<w;
}
