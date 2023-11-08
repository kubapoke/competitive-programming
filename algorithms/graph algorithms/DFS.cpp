#include<iostream>
#include<vector>
#define N 100000
#define INF 1000000000
using namespace std;

vector<int> graf[1000];
int visited[1000];

void DFS(int v)
{
	cout<<v<<" ";
	visited[v]=1;

	for(int i=0; i<graf[v].size(); i++)
	{
		if(visited[graf[v][i]]==0)
		DFS(graf[v][i]);
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

		graf[a].push_back(b);
		if(a!=b)
		graf[b].push_back(a);
	}

	DFS(1);

	return 0;
}