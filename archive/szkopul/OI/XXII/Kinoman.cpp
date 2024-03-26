#include<bits/stdc++.h>
#define NTREE 1048576
#define INF 1e9
using namespace std;

int n, m, film[NTREE], wart[NTREE], pocz[NTREE];
long long w;
pair<long long,long long> tree[NTREE*2];
vector<int> pos[NTREE];

void update(int v, int p) //value+pos
{
	p+=NTREE;
	tree[p]={v,v};
	p/=2;
	
	while(p)
	{
		tree[p].second=tree[p*2].second+tree[p*2+1].second;
		tree[p].first=max(tree[2*p].first, tree[2*p].second);
		tree[p].first=max(tree[2*p].second+tree[2*p+1].first, tree[p].first);
		tree[p].first=max(tree[p].second, tree[p].first);
		
		p/=2;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
	{
		cin>>film[i];
		pos[film[i]].push_back(i);
	}
	
	for(int i=1; i<=m; i++)
	{
		cin>>wart[i];
		
		pos[i].push_back(INF); pos[i].push_back(INF); pos[i].push_back(INF); 
		
		if(pos[i][0]!=INF) update(wart[i],pos[i][0]);
		if(pos[i][1]!=INF) update(-wart[i],pos[i][1]);
	}	
	w=tree[1].first;
	
	for(int i=1; i<=n; i++)
	{
		update(0,i);
		if(pos[film[i]][pocz[film[i]]+1]!=INF) update(wart[film[i]],pos[film[i]][pocz[film[i]]+1]);
		if(pos[film[i]][pocz[film[i]]+2]!=INF) update(-wart[film[i]],pos[film[i]][pocz[film[i]]+2]);
		pocz[film[i]]++;
		
		w=max(w,tree[1].first);
	}
	cout<<w;
}

