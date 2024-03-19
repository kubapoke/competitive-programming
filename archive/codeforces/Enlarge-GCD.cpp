#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

long long erastotenes[15000001];
int n, num[300001], mn=1, ans, odp[15000001], x;

int GCD(int a,int b)
{
	while(b)
	swap(a%=b,b);	
	return a;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i=2; i<15000001; i++)
	{
		if(erastotenes[i]==0)
		{
			erastotenes[i]=i;
			for(int j=i+i; j<15000001; j+=i)
			if(erastotenes[j]==0)
			erastotenes[j]=i;
		}
	}
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	cin>>num[i];
	
	mn=GCD(num[1],num[2]);
	
	for(int i=3; i<=n; i++)
	mn=GCD(mn,num[i]);
	
	for(int i=1; i<=n; i++)
	num[i]/=mn;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=num[i]; j>1; )
		for(++odp[x=erastotenes[j]]; x==erastotenes[j]; )
		j/=erastotenes[j];
	}
	
	for(int i=1; i<15000001; i++)
	ans=max(ans,odp[i]);
	
	if(ans)
	cout<<n-ans;
	else
	cout<<"-1";
}
