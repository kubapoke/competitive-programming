#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n, a, b, c;
long long res=1;

long long factorial(long long a)
{
	long long ret=1;
	
	for(long long i=1; i<=a; i++)
	ret=((ret%MOD)*i)%MOD;
	
	return ret;
}

long long modularInverse(long long a, long long b)
{
	long long u=1, w=a, x=0, z=b, q;
	while(w)
    {
	    if(w<z)
	    {
	    	q=u; u=x; x=q;
	    	q=w; w=z; z=q;
	    }
	    q=w/z;
	    u-=q*x;
	    w-=q*z;
    }
  
    if(x<0) x+=b;
    return x;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	n/=3;
	
	for(int i=0; i<n; i++)
	{
		cin>>a>>b>>c;
		
		long long mini=min(a,min(b,c)), ctr=0;
		if(a==mini) ctr++;
		if(b==mini) ctr++;
		if(c==mini) ctr++;
		
		res=((res%MOD)*ctr)%MOD;
	}  
	
	res=((((((res%MOD)*(factorial(n)%MOD))%MOD)*((modularInverse(factorial(n/2),MOD))%MOD))%MOD)*((modularInverse(factorial(n/2),MOD))%MOD))%MOD;
	
	cout<<res;
}
