#include<bits/stdc++.h>
using namespace std;

int vis[101], visT[101];
vector<int> G[101], GT[101];
stack<int> postorder;

void DFS_postorder(int v)
{
	vis[v]=1;
	
	for(int i=0; i<G[v].size(); i++)
	{
		if(vis[G[v][i]]==0)
		DFS_postorder(G[v][i]);
	}
	
	postorder.push(v);
}

void DFS(int v)
{
	cout<<v<<" ";
	visT[v]=1;
	
	for(int i=0; i<GT[v].size(); i++)
	{
		if(visT[GT[v][i]]==0)
		DFS(GT[v][i]);
	}
}

int main()
{
	int n, m;
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		
		G[a].push_back(b);
		GT[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++)
	{
		if(vis[i]==0)
		DFS_postorder(i);
	}
	
	int x=1;
	
	while(postorder.size())
	{
		if(visT[postorder.top()]==0)
		{
			cout<<"\nSilnie spojna skladowa nr "<<x++<<":  ";
			DFS(postorder.top());
		}
		
		postorder.pop();
	}
	
}
