#include<bits/stdc++.h>
#define N 500001
using namespace std;

/*
11 11
1 2
2 5
1 3
3 6
3 7
7 10
1 4
4 8
4 9
8 11
*/

int n, m, a, b, c, wart[N], pop[N], czystr[N], w;
vector<int> graf[N];

void dfs(int v, int p)
{
	pop[v]=p;
	
	for(int i=0; i<graf[v].size(); i++)
	{
		if(graf[v][i]!=p)
		{
			wart[v]++;
			dfs(graf[v][i],v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=1; i<=n-1; i++)
	{
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	dfs(1,0);
	
	cin>>m;
	
	for(int i=1; i<=m; i++)
	{
		cin>>c;
		
		if(c>0)
		{
			czystr[c]=1;
			w+=wart[c];
			wart[pop[c]]--;
			if(czystr[pop[c]])
			w--;
		}
		else
		{
			c*=-1;
			czystr[c]=0;
			w-=wart[c];
			wart[pop[c]]++;
			if(czystr[pop[c]])
			w++;
		}
		
		if(czystr[1]==0)
		cout<<w+1<<"\n";
		else
		cout<<w<<"\n";
		
	}
}
