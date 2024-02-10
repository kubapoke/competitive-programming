#include<bits/stdc++.h>
#define NTREE 524288
#define INF 1e18
using namespace std;

long long n, tab[500001], tree[2*NTREE], lazy[2*NTREE]; //drzewo przedzia³owe (+, pierwsza wartoœæ od lewej wiêksza od zera)
stack<long long> S;

int query(int v)
{
	if(v>=NTREE)
	return v-NTREE;
	
	if(lazy[v]!=0)
	{
		tree[v]+=lazy[v];
		lazy[v*2]+=lazy[v];
		lazy[v*2+1]+=lazy[v];
		lazy[v]=0;
	}
	
	if(tree[v*2]+lazy[v*2]>0)
	return query(v*2);
	
	return query(v*2+1);
}

void update(int v, int start, int end, int l, int r, long long val)
{
	if(lazy[v]!=0)
	{
		tree[v]+=lazy[v];
		if(start!=end)
		{
			lazy[v*2]+=lazy[v];
			lazy[v*2+1]+=lazy[v];
		}
		lazy[v]=0;
	}
	
	if(start>r||end<l||start>end)
	return;
	
	if(start>=l&&end<=r)
	{
		if(start!=end)
		{
			lazy[v*2]+=val;
			lazy[v*2+1]+=val;
		}
		
		tree[v]+=val;
		return;
	}
	
	int mid=(start+end)/2;
	update(v*2,start,mid,l,r,val);
	update(v*2+1,mid+1,end,l,r,val);
	tree[v]=max(tree[v*2],tree[v*2+1]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
		tree[i+NTREE]=tab[i];
	}
	
	for(int i=NTREE-1; i>0; i--)
	tree[i]=max(tree[i*2],tree[i*2+1]);
	
	for(int i=1; i<n; i++)
	update(1,0,NTREE-1,0,i-1,-tab[i]);
	
	for(int i=0; i<n; i++)
	{
		int q=query(1);
		
		S.push(q);
		
		update(1,0,NTREE-1,0,q-1,tab[q]);
		update(1,0,NTREE-1,q,q,-INF);
	}
	
	long long ans=0;
	
	while(!S.empty())
	{
		ans+=tab[S.top()];
		cout<<ans<<" ";
		S.pop();
	}
	
}
