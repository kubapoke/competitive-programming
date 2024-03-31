#include<bits/stdc++.h>
using namespace std;

int n, w, x[1000005];

bool check_ans(int s)
{
	int z=w-1, c=s;
	
	for(int i=0; i<n; i++)
	{
		c-=x[i];
		if(c<=0)
		{
			z--;
			c=s;
			
			if(z==0)
			return true;
		}
	}
	
	return false;
}

int main()
{
	cin>>n>>w;
	
	for(int i=0; i<n; i++)
	cin>>x[i];
	
	for(int i=0; i<n-1; i++)
	x[i]=x[i+1]-x[i];
	
	n--;
	
	int p=1, k=1000000001, s;
	while(p<k)
	{
		s=(p+k+1)/2;
		
		if(check_ans(s)==false)
		k=s-1;
		else
		p=s;
	}
	
	cout<<p;
}
