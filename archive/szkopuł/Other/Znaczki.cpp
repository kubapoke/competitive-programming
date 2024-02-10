#include<bits/stdc++.h>
using namespace std;

int n, m, z[100005], a, w;

int main()
{
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	cin>>z[i];
	
	sort(z,z+n);
	
	for(int i=0; i<m; i++)
	{
		cin>>a;
		
		int p=0, k=n-1, s;
		
		while(p<k)
		{
			s=(p+k)/2;

			if(z[s]>=a)
			k=s;
			else
			p=s+1;
		}
		
		s=(p+k)/2;
		
		if(a!=z[s])
		w++;
	}
	
	cout<<w;
}
