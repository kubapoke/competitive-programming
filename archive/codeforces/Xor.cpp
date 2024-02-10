#include<bits/stdc++.h>
using namespace std;

int n, u, r, a[31], b[31], k[31], p[31], rp[31], x[31];
long long ans=-1e18;

long long current()
{
	long long w=0;
	
	for(int i=1; i<=n; i++)
	w+=(1ll*a[i]*k[i]);
	
	return w;
}

void op1()
{
	for(int i=1; i<=n; i++)
	a[i]^=b[i];
}

void op2()
{
	for(int i=1; i<=n; i++)
	x[i]=a[i];
	
	for(int i=1; i<=n; i++)
	a[i]=x[p[i]]+r;
}

void op2rev()
{
	for(int i=1; i<=n; i++)
	x[i]=a[i]-r;
	
	for(int i=1; i<=n; i++)
	a[i]=x[rp[i]];
}

void dfs(int currop, int popop)
{
	if(currop>u)
	return;
	
	if((u-currop)%2==0)
	ans=max(ans, current());
	
	//operacja 2, robimy najpierw, bo robimy j� zawsze
	op2();
	dfs(currop+1,2);
	op2rev();
	
	//operacja 1
	if(popop==2)
	{
		op1();
		dfs(currop+1,1);
		op1();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>u>>r;
	
	for(int i=1; i<=n; i++)
	cin>>a[i];
	
	for(int i=1; i<=n; i++)
	cin>>b[i];
	
	for(int i=1; i<=n; i++)
	cin>>k[i];
	
	for(int i=1; i<=n; i++)
	{
		cin>>p[i];
		rp[p[i]]=i;
	}
	
	dfs(0,2);
	
	cout<<ans;
}
