#include<bits/stdc++.h>
#define N 100000
#define INF 1000000000
using namespace std;

vector<int> graf[1000];
int visited[1000];
queue<int> Q;

int main()
{
	int n, m;
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		
		graf[a].push_back(b);
		if(a!=b)
		graf[b].push_back(a);
	}
	
	Q.push(1);
	visited[1]=1;
	
	while(!Q.empty())
	{
		int v=Q.front();
		cout<<v<<" ";
		Q.pop();
		
		for(int i=0; i<graf[v].size(); i++)
		{
			if(visited[graf[v][i]]==0)
			{
				Q.push(graf[v][i]);
				visited[graf[v][i]]=1;
			}
		}
	}
	
	return 0;
}
