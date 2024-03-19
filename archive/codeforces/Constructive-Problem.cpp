#include<bits/stdc++.h>
using namespace std;

int checkMEX(vector<int>& V)
{
	set<int> S;
	for(auto u: V)
		S.insert(u);
	
	int it=0;
	for(auto u: S)
	{
		if(u!=it)
			return it;
		it++;
	}
	return it;
}

vector<int> V;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t, n, a, MEX, MAX, ind1, ind2;
	
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		V.clear();
		cin>>n;
		
		for(int j=0; j<n; j++)
		{
			cin>>a;
			V.push_back(a);
		}	
		
		MAX=-1;
		MEX=checkMEX(V);
			
		ind1=-1; ind2=-1;
			
		for(int k=0; k<V.size(); k++)
		{
			MAX=max(MAX,V[k]);
			if(V[k]==MEX+1)
			{
				if(ind1==-1)
					ind1=k;
				ind2=k;
			}
		}
		
		if(ind1==-1)
		{
			if(MAX>MEX+1)
			{
				cout<<"Yes\n";
				continue;
			}
			if(MAX==V.size()-1)
			{
				cout<<"No\n";
				continue;
			}
			else
			{
				cout<<"Yes\n";
				continue;
			}
		}
		
		for(int k=ind1; k<=ind2; k++)
		V[k]=MEX;
		
		if(MEX+1==checkMEX(V))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}
