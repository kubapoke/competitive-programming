#include<bits/stdc++.h>
#define N 1000001
using namespace std;

long long m, n, a, pocz[N], stan[N], klient, idx, k, maks;
vector<long long> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>a;
		stan[a]=1;
		maks=max(maks,a);
	}
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		
		k=1; idx=pocz[a]+a;
		
		while(k<=a && idx<=maks)
		{
			if(stan[idx]==1)
			{
				stan[idx]=-1;
				ans.push_back(klient+k);
				k++;
			}
			if(stan[idx]==0)
			{
				stan[idx]=-1;
				k++;
			}
			
			if(k<=a)
			idx+=a;
		}
		
		pocz[a]=idx;
		klient+=a;
	}
	
	cout<<ans.size()<<"\n";
	
	for(int i=0; i<ans.size(); i++) 
	cout<<ans[i]<<"\n";
}
