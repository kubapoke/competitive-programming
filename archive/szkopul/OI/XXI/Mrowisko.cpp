#include<bits/stdc++.h>
using namespace std;
//7 5 3 3 4 1 9 11 1 2 1 4 4 3 4 5 4 6 6 7

const long long N=1000001, X=1e9+1;

long long n, g, k, m, a, b, st1, st2, stop[N], pocz[N], kon[N], poczodw[N], konodw[N];
long long w;
vector<long long> tree[N];
vector<long long> mro;


void dfs(long long v, long long p)
{
	if(v!=st1&&v!=st2)
	{
		pocz[v]=min(poczodw[p]*stop[v],X);
		kon[v]=min(konodw[p]*stop[v],X);
		poczodw[v]=min(poczodw[p]*(stop[v]-1),X);
		konodw[v]=min(konodw[p]*(stop[v]-1),X);
	}
	
	for(int i=0; i<tree[v].size(); i++)
	{
		if(tree[v][i]!=p)
		dfs(tree[v][i], v);
	}
}

long long wyn(long long v)
{
	return (long long)(upper_bound(mro.begin(),mro.end(),kon[v]-1)-lower_bound(mro.begin(),mro.end(),pocz[v]))*k;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>g>>k;
	
	for(int i=0; i<g; i++)
	{
		cin>>m;
		mro.push_back(m);
	}

	sort(mro.begin(),mro.end());
	
	for(int i=0; i<n-1; i++)
	{
		cin>>a>>b;
		
		if(i==0)
		{
			st1=a; st2=b;
		}
		
		tree[a].push_back(b);
		tree[b].push_back(a);
		stop[a]++; stop[b]++;
	}
	
	pocz[st1]=stop[st1]*k;
	kon[st1]=stop[st1]*(k+1);
	poczodw[st1]=(stop[st1]-1)*k;
	konodw[st1]=(stop[st1]-1)*(k+1);
	
	pocz[st2]=stop[st2]*k;
	kon[st2]=stop[st2]*(k+1);
	poczodw[st2]=(stop[st2]-1)*k;
	konodw[st2]=(stop[st2]-1)*(k+1);
	
	dfs(st1, st2); dfs(st2, st1);
	
	for(int i=1; i<=n; i++)
	{
		//cout<<pocz[i]<<" "<<kon[i]<<"  "<<poczodw[i]<<" "<<konodw[i]<<"\n";
		if(stop[i]==1)
		w+=wyn(i);
	}
	
	cout<<w;
}
