#include<bits/stdc++.h>
using namespace std;

int n, m, k, liz[1000001], sum;
pair<int,int> odp[2000001];
string s;

void rozw(pair<int,int> para, int w)
{
	int l=para.first, r=para.second;
	odp[w]={l,r};
	
	if(l<r)
	{
		if(liz[l]==2)
		rozw({l+1,r}, w-2);
		else if(liz[r]==2)
		rozw({l,r-1}, w-2);
		else
		rozw({l+1,r-1}, w-2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m>>s;
	
	for(int i=1; i<=n; i++)
	{
		if(s[i-1]=='T')
		liz[i]=2;
		else
		liz[i]=1;
		
		sum+=liz[i];
	}
	
	rozw({1,n},sum);
	
	int lpos, rpos;
	
	for(int i=1; i<=n; i++)
	{
		if(liz[i]==1)
		{
			lpos=i;
			break;
		}
	}
	
	for(int i=n; i>=1; i--)
	{
		if(liz[i]==1)
		{
			rpos=i;
			break;
		}
	}
	
	if(lpos)
	{
		if(lpos-1<n-rpos)
		rozw({lpos+1,n},sum-2*(lpos-1)-1);
		else
		rozw({1,rpos-1},sum-2*(n-rpos)-1);
	}
		
	for(int i=0; i<m; i++)
	{
		cin>>k;
		
		if(odp[k].first==0)
		cout<<"NIE\n";
		else
		cout<<odp[k].first<<" "<<odp[k].second<<"\n";
	}
}
