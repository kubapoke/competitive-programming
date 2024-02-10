#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; i++)
using namespace std;
typedef long long ll;

int t;
ll a, b, n, m;

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	rep(i,1,t)
	{
		cin>>a>>b>>n>>m;
		
		if(a<=b)
		{
			cout<<a*(n-(n/(m+1)))<<"\n";
			continue;
		}
		
		if(a*m<b*(m+1))
		{
			cout<<(n/(m+1))*a*m + (n%(m+1))*b<<"\n";
			continue;
		}
		
		cout<<b*n<<"\n";
	}
}
