#include<iostream>
#include<vector>
#include<queue>
#define N 100000
#define INF 1000000000
using namespace std;

vector<pair<int,int>> graf[1000];
priority_queue<pair<int,int>> PQ;
int dis[1000];

int main()
{
	int n, m;
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		
		graf[a].push_back({b,c});
		if(a!=b)
		graf[b].push_back({a,c});
	}
	
	for(int i=2; i<1000; i++)
	dis[i]=INF;
	
	PQ.push({0,6});
	
	while(!PQ.empty())
	{
		int d=(-1)*PQ.top().first;
		int v=PQ.top().second;
		PQ.pop();
		
		if(d!=dis[v])
		continue;
		
		for(int i=0; i<graf[v].size(); i++)
		{
			if(d+graf[v][i].second < dis[graf[v][i].first])
			{
				dis[graf[v][i].first]=d+graf[v][i].second;
				PQ.push({(-1)*dis[graf[v][i].first], graf[v][i].first});
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	cout<<i<<": "<<dis[i]<<"\n";
	
	return 0;
}
