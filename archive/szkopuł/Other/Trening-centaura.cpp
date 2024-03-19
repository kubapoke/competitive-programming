#include<bits/stdc++.h>
using namespace std;

int n;
long double x, y;
set<long double> S[5];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>x>>y;
		
		if(x>0&&y>0)
		S[1].insert(x/y);
		else if(x<0&&y>0)
		S[2].insert(x/y);
		else if(x<0&&y<0)
		S[3].insert(x/y);
		else if(x>0&&y<0)
		S[4].insert(x/y);
		else if(x>0)
		S[0].insert(1);
		else if(x<0)
		S[0].insert(2);
		else if(y>0)
		S[0].insert(3);
		else if(y<0)
		S[0].insert(4);
	}
	
	
	cout<<S[0].size()+S[1].size()+S[2].size()+S[3].size()+S[4].size();
}
