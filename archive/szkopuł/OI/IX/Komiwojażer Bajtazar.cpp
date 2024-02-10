#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, lca[18][30001], odl[30001], preord[30001], postord[30001], idx, ans;
vector<int> graf[30001];

void dfs(int v, int p)
{
	lca[0][v]=p;
	odl[v]=odl[p]+1;
	preord[v]=++idx;
	
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i]!=p)
	dfs(graf[v][i],v);
	
	postord[v]=++idx;
}

bool anc(int v, int u)
{
	if(v==u)
	return true;
	
	if(preord[v]<preord[u] && postord[v]>postord[u])
	return true;
	
	return false;
}

int getlca(int v, int u)
{
	if(anc(v,u)) return v;
	if(anc(u,v)) return u;
	
	for(int i=17; i>=0; i--)
	{
		if(!anc(lca[i][v],u))
		v=lca[i][v];
	}
	
	return lca[0][v];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	
	dfs(1,1);
	
	for(int i=1; i<18; i++)
	for(int v=1; v<=n; v++)
	lca[i][v]=lca[i-1][lca[i-1][v]];
	
	cin>>m;
	b=1;
	
	for(int i=0; i<m; i++)
	{
		cin>>a;
		
		ans+=odl[a]+odl[b]-2*odl[getlca(a,b)];
		
		b=a;
	}
	
	cout<<ans;
}
