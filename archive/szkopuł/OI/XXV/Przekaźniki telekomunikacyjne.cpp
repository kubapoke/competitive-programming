#include<bits/stdc++.h>
#define NTREE 524288
using namespace std;

int n, m;
long long tree[2*NTREE], lazyleft[2*NTREE], lazychange[2*NTREE];

struct ST{
	int s, a, l, r;
}maszt[300001];

long long ciagAr(long long a, long long b, int len)
{
	return(((a+b)*1ll*len)/2ll);
}

void update(int v, int start, int end, int l, int r, long long left, long long change)
{
	if(lazyleft[v]!=0||lazychange[v]!=0)
	{
		tree[v]+=ciagAr(lazyleft[v],lazyleft[v]+(end-start)*lazychange[v],end-start+1);
		
		if(start!=end)
		{
			lazychange[v*2]+=lazychange[v];
			lazychange[v*2+1]+=lazychange[v];
			lazyleft[v*2]+=lazyleft[v];
			lazyleft[v*2+1]+=lazyleft[v]+((end+start)/2+1-start)*lazychange[v];
		}
		
		lazyleft[v]=0; lazychange[v]=0;
	}
	
	if(start>r||end<l||start>end)
	return;
	
	if(start>=l&&end<=r)
	{
		left+=(start-l)*change;
		
		tree[v]+=ciagAr(left,left+(end-start)*change,end-start+1);
		
		if(start!=end)
		{
			lazychange[v*2]+=change;
			lazychange[v*2+1]+=change;
			lazyleft[v*2]+=left;
			lazyleft[v*2+1]+=left+((end+start)/2+1-start)*change;
		}
		
		return;
	}
	
	int mid=(start+end)/2;
	update(v*2, start, mid, l, r, left, change);
	update(v*2+1, mid+1, end, l, r, left, change);
	tree[v]=tree[v*2]+tree[v*2+1];
}

long long query(int v, int start, int end, int l, int r)
{
	if(start>r||end<l||start>end)
	return 0;
	
	if(lazyleft[v]!=0||lazychange[v]!=0)
	{
		tree[v]+=ciagAr(lazyleft[v],lazyleft[v]+(end-start)*lazychange[v],end-start+1);
		
		if(start!=end)
		{
			lazychange[v*2]+=lazychange[v];
			lazychange[v*2+1]+=lazychange[v];
			lazyleft[v*2]+=lazyleft[v];
			lazyleft[v*2+1]+=lazyleft[v]+((end+start)/2+1-start)*lazychange[v];
		}
		
		lazyleft[v]=0; lazychange[v]=0;
	}
	
	if(start>=l&&end<=r)
	return tree[v];
	
	int mid=(start+end)/2;
	long long q1=query(v*2,start,mid,l,r);
	long long q2=query(v*2+1,mid+1,end,l,r);
	return q1+q2;
}

char c;
int x, s, a, l, r, d;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>c;
		
		if(c=='P')
		{
			cin>>x>>s>>a;
			d=s/a;
			l=max(1,x-d);
			r=min(n,x+d);
			
			update(1,0,NTREE-1,l,x,s-((x-l)*a),a);
			update(1,0,NTREE-1,x+1,r,s-a,-a);
			
			maszt[x].s=s; maszt[x].a=a; maszt[x].l=l; maszt[x].r=r;
		}
		else if(c=='U')
		{
			cin>>x;
			s=maszt[x].s; a=maszt[x].a; l=maszt[x].l; r=maszt[x].r;
			
			update(1,0,NTREE-1,l,x,-s+((x-l)*a),-a);
			update(1,0,NTREE-1,x+1,r,-s+a,a);
			
			maszt[x].s=0; maszt[x].a=0; maszt[x].l=0; maszt[x].r=0;
		}
		else
		{
			cin>>x>>a;
			cout<<query(1,0,NTREE-1,x,a)/(a-x+1)<<"\n";
		}
	}
	
}
