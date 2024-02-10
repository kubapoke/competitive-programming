#include<bits/stdc++.h>
#define NTREE 131072
using namespace std;

struct skrz{
	int x, y, w;
}s[100001];

bool comp(const skrz &a, const skrz &b)
{
	if(a.y==b.y) return a.x < b.x;
	return a.y<b.y;
}

int n, m, k, tree[NTREE*2], idx;
map<int,int> mapa;
map<int,int>::iterator it;

void update(int pos, int val)
{
	pos+=NTREE;
	tree[pos]=max(tree[pos], val);
	pos/=2;
	while(pos)
	{
		tree[pos]=max(tree[pos*2], tree[pos*2+1]);
		pos/=2;
	}
}

int query(int l, int r)
{
	l+=NTREE; r+=NTREE;
	int ans=tree[l];
	
	if(r>1)
	ans=max(ans, tree[r]);
	
	while(r-l>1)
	{
		if(l%2==0) ans=max(ans, tree[l+1]);
		if(r%2==1) ans=max(ans, tree[r-1]);
		l/=2; r/=2;
	}
	
	return ans;
}

int main()
{
	cin>>n>>m>>k;
	
	for(int i=1; i<=k; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		mapa[a]=1;
		s[i].x=a;
		s[i].y=b;
		s[i].w=c;
	}
	
	for(it=mapa.begin(); it!=mapa.end(); ++it)
	{
		it->second=++idx;
	}
	
	sort(s+1, s+1+k, comp);
	
	for(int i=1; i<=k; i++)
	{
		int ans=query(1, mapa[s[i].x]);
		update(mapa[s[i].x], ans+s[i].w);
	}
	
	cout<<query(1,k);
	
}
