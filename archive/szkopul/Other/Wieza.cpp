#include<bits/stdc++.h>
using namespace std;

int n, m, a[500005], b;

int main()
{
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	{
		cin>>b;
		
		if(i!=0)
		a[i]=a[i-1];
		
		a[i]=max(a[i],b);
	}
	
	a[n]=1000000007;
	
	for(int i=0; i<m; i++)
	{
		cin>>b;
		
		int p=0, k=n, s;
		
		while(p<k)
		{
			s=(p+k)/2;
			
			if(a[s]>=b)
			k=s;
			else
			p=s+1;
		}
		
		cout<<k<<" ";
	}
}
