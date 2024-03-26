#include<bits/stdc++.h>
using namespace std;

long long m;

long long points(long long s)
{
	long long c=0, y=s;
	
	for(long long x=0; x<=s; x++)
	{
		while(x*x+y*y > s*s)
		y--;
		
		c+=y;
	}
	
	return (4*c+1);
}

int main()
{
	cin>>m;
	
	long long p=1, k=5000000, s;
	
	while(p<k)
	{
		s=(p+k)/2;
		
		if(points(s)>=m)
		k=s;
		else
		p=s+1;
	}
	
	cout<<k;
}
