#include<bits/stdc++.h>
#define NTREE 65536
using namespace std;

int n, m, z, p, k, x, tree[NTREE*2], lazy[NTREE*2];

void update(int v, int start, int end, int l, int r, int value)
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
	
	if(start>r || end<l || start>end)
	return;
	
	if(start>=l&&end<=r)
	{
		tree[v]+=value;
		if(start!=end)
		{
			lazy[v*2]+=value;
			lazy[v*2+1]+=value;
		}
		return;
	}
	
	int mid=(start+end)/2;
	update(v*2, start, mid, l, r ,value);
	update(v*2+1, mid+1, end, l, r, value);
	tree[v]=max(tree[v], tree[v*2]);
	tree[v]=max(tree[v], tree[v*2+1]);
}

int query(int v, int start, int end, int l, int r)
{
	if(start>r || end<l || start>end)
	return 0;
	
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
	
	if(start>=l && end<=r)
	return tree[v];
	
	int mid=(start+end)/2;
	long long q1=query(v*2, start, mid, l, r);
	long long q2=query(v*2+1, mid+1, end, l, r);
	return max(q1,q2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m>>z;
	
	for(int i=0; i<z; i++)
	{
		cin>>p>>k>>x;
		if(query(1, 1, NTREE, p, k-1)+x<=m)
		{
			cout<<"T\n";
			update(1, 1, NTREE, p, k-1, x);
		}
		else cout<<"N\n";
	}
}

