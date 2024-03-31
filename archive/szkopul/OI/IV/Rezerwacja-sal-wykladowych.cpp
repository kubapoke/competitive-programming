#include<bits/stdc++.h>
#define NTREE 32768
using namespace std;

int n, tree[2*NTREE]; //drzewo przedzia³owe przedzia³-punkt 
pair<int,int> rez[10001];

bool comp(pair<int,int> &a,pair<int,int> &b)
{
	return(a.second<b.second);
}

void update(int p, int k, int val)
{
	p+=NTREE; k+=NTREE;
	
	tree[p]=max(tree[p],val);
	tree[k]=max(tree[k],val);
	
	while(k-p>1)
	{
		if(p%2==0) tree[p+1]=max(tree[p+1],val);
		if(k%2==1) tree[k-1]=max(tree[k-1],val);
		p/=2;
		k/=2;
	}
}

int query(int v)
{
	int ans=0;
	v+=NTREE;
	
	while(v)
	{
		ans=max(ans,tree[v]);
		v/=2;
	}
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	cin>>rez[i].first>>rez[i].second;
	
	sort(rez+1,rez+n+1,comp);
	
	for(int i=1; i<=n; i++)
	{
		int p=rez[i].first, k=rez[i].second, val;
		
		val=query(p)+k-p;
		
		//cout<<p<<" "<<k<<" "<<val<<"\n";
		
		update(k,30005,val);
	}
	
	cout<<query(30005);
}
