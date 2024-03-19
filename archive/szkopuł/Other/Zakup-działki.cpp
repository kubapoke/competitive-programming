#include<iostream>
using namespace std;

int n, q, x[200005], a;

int main()
{
	cin>>n>>q;
	
	for(int i=1; i<=n; i++)
	cin>>x[i];
	
	x[0]=1000000007;
	
	for(int i=1; i<=q; i++)
	{
		cin>>a;
		
		int p=1, k=n, s;
		
		while(p<k)
		{
			s=(p+k)/2;
			
			if(x[s]>=a)
			k=s;
			else
			p=s+1;
		}
		
		cout<<min(abs(x[k]-a),abs(x[k-1]-a))<<"\n";
	}
}

