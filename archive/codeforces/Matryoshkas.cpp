#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
	
int t;
cin>>t;

for(int it=0; it<t; it++)
{
	int n, a, res=0, prevSize=0, prevNum=0;
	map<int,int> M;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		M[a]++;
	}
	
	for(auto u: M)
	{
		if(u.first!=prevSize+1)
		{
			res+=prevNum;
			prevNum=0;
		}
		prevSize=u.first;
		
		if(u.second>prevNum)
			prevNum=u.second;
			
		if(u.second<prevNum)
		{
			res+=prevNum-u.second;
			prevNum=u.second;
		}
	}
	
	res+=prevNum;
	
	cout<<res<<"\n";
}


}
