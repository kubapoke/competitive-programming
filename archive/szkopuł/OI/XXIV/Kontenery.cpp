#include<bits/stdc++.h>
using namespace std;

int n, k, a, l, d, kon[100501], zmi[100501], x;
vector< pair<int,int> > zap[100501];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n>>k;
	int p=sqrt(n);
	
	for(int i=0; i<k; i++)
	{
		cin>>a>>l>>d;
		if(d>=p)
		for(int j=a; l>0; l--, j+=d)
		kon[j]++;
		else
		zap[d].push_back({a,l});
	}
	
	for(int i=1; i<p; i++)//lecimy po kolejnych d
	{
		for(int j=1; j<=n; j++) zmi[j]=0;
		
		for(int j=0; j<zap[i].size(); j++)
		{
			a=zap[i][j].first; l=zap[i][j].second;
			zmi[a]++; zmi[a+i*l]--;
		}
		
		for(int j=1; j<=i; j++)
		{
			x=0;
			for(int v=j; v<=n; v+=i)
			{
				x+=zmi[v];
				kon[v]+=x;
			}
		}
	}
	
	for(int i=1; i<=n; i++)
	cout<<kon[i]<<" ";
}
