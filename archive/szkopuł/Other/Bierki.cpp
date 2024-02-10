#include<bits/stdc++.h>
using namespace std;

int n, b[30005], w;

int main()
{
	cin>>n;
	
	for(int i=0; i<n; i++)
	cin>>b[i];
	
	sort(b,b+n);
	
	for(int i=0; i<n-2; i++)
	{
		int p=i, k=n-1, s, a=b[i]+b[i+1];
		
		while(p<k)
		{
			s=(p+k)/2;
			
			if(b[s]>=a)
			k=s;
			else
			p=s+1;
		}
		
		s=(p+k)/2;
		
		while(b[s]>=a)
		s--;
		
		w=max(w, s-i+1);
	}
	
	cout<<w;
}
