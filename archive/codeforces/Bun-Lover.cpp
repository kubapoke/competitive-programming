#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long t, a;
	
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>a;
		cout<<(4*a + (a*(a-1))/2 + ((a-1)*(a-2))/2 +1)<<"\n";
	}
}
