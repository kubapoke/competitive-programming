#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> graf[200001];
int con[200001], vis[200001], a, b;
char kto[200001];

void dfs(int v, char c)
{
	vis[v]=1;
	kto[v]=c;
	
	if(c=='S')
	{
		for(int i=0; i<graf[v].size(); i++)
		{
			if(vis[graf[v][i]]==0)
			dfs(graf[v][i], 'K');
		}
	}
	else
	{
		for(int i=0; i<graf[v].size(); i++)
		{
			if(vis[graf[v][i]]==0)
			dfs(graf[v][i], 'S');
		}
	}
}

int main()
{
	cin>>n>>m;
	
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b;
		con[a]++; con[b]++;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++)
	{
		if(con[i]==0)
		{
			cout<<"NIE";
			return 0;
		}
	}
	
	cout<<"TAK\n";
	
	for(int i=1; i<=n; i++)
	{
		if(vis[i]==0)
		dfs(i, 'S');
	}
	
	for(int i=1; i<=n; i++)
	cout<<kto[i]<<"\n";
}


