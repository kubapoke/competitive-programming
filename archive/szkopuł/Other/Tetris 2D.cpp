#include<bits/stdc++.h>
#define NTREE 1048576
using namespace std;

int d, n, l, x, tree[NTREE*2], lazy[NTREE*2];

void update(int v, int start, int end, int l, int r, int value)
{
	if(lazy[v]!=0)
	{
		tree[v]=lazy[v];
		if(start!=end)
		{
			lazy[v*2]=lazy[v];
			lazy[v*2+1]=lazy[v];
		}
		lazy[v]=0;
	}
	
	if(start>r || end<l || start>end)
	return;
	
	if(start>=l&&end<=r)
	{
		tree[v]=value;
		if(start!=end)
		{
			lazy[v*2]=tree[v];
			lazy[v*2+1]=tree[v];
		}
		return;
	}
	
	int mid=(start+end)/2;
	update(v*2, start, mid, l, r, value);
	update(v*2+1, mid+1, end, l, r, value);
	tree[v]=max(tree[v*2],tree[v*2+1]);
}

int query(int v, int start, int end, int l, int r)
{
	if(start>r || end<l || start>end)
	return 0;
	
	if(lazy[v]!=0)
	{
		tree[v]=lazy[v];
		if(start!=end)
		{
			lazy[v*2]=lazy[v];
			lazy[v*2+1]=lazy[v];
		}
		lazy[v]=0;
	}
	
	if(start>=l&&end<=r)
	return tree[v];
	
	int mid=(start+end)/2;
	int q1=query(v*2, start, mid, l, r);
	int q2=query(v*2+1, mid+1, end, l, r);
	return max(q1,q2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>d>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>l>>x;
		
		int q=query(1, 0, NTREE-1, x, x+l-1)+1;
		
		update(1, 0, NTREE-1, x, x+l-1, q);
	}
	
	cout<<query(1, 0, NTREE-1, 0, NTREE-1);
}
