#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, con[500001], req[500001], ans[500001], curr, indeg[500001], outdeg[500001];
bool vis[500001];
vector<int> graf[500001];
queue<int> Q;

int main()
{
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>a>>b;
		graf[a].push_back(b);
		graf[b].push_back(a);
		con[a]++; con[b]++;
	}
	
	if(m==0)
	{
		cout<<"TAK\n";
		for(int i=1; i<=n; i++)
		cout<<i<<" ";
		return 0;
	}
	
	req[2]=con[2];
	
	for(int i=3; i<=n; i++)
	{
		req[i]=con[i]/2;
	}
	
	Q.push(1);
	vis[1]=true;
	
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		ans[u]=++curr;
		
		for(int i=0; i<graf[u].size(); i++)
		{
			if(vis[graf[u][i]]==false)
			{
				outdeg[u]++;
				indeg[graf[u][i]]++;
			}
			if(--req[graf[u][i]]==0 && vis[graf[u][i]]==false)
			{
				Q.push(graf[u][i]);
				vis[graf[u][i]]=true;
			}
		}
	}
	
	for(int i=3; i<=n; i++)
	{
		if(indeg[i]!=outdeg[i])
		{
			cout<<"NIE";
			return 0;
		}
		if(graf[i].size()==0 && vis[i]==false)
		ans[i]=++curr;
		else if(vis[i]==false)
		{
			cout<<"NIE";
			return 0;
		}
	}
	
	cout<<"TAK\n";
	for(int i=1; i<=n; i++)
	cout<<ans[i]<<" ";
	
}
