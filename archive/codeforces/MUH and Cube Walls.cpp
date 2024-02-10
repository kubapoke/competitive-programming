#include<bits/stdc++.h>
using namespace std;

int n,w,p,c,ans;
vector<int> V, G;

vector<int> kmp(vector<int> &v)
{
	int n=v.size();
	vector<int> pi(n);
	
	for(int i=1; i<n; i++)
	{
		int j=pi[i-1];
		
		while(v[i]!=v[j] && j>0)
		j=pi[j-1];
			
		if(v[i]==v[j])
		j++;
		
		pi[i]=j;
	}
	
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>w;
	
	for(int i=0; i<n; i++)
	{
		p=c;
		cin>>c;
		
		if(i)
		G.push_back(c-p);
	}
	
	for(int i=0; i<w; i++)
	{
		p=c;
		cin>>c;
		
		if(i)
		V.push_back(c-p);
	}
	
	V.push_back(2000000000);
	
	for(int i=0; i<G.size(); i++)
	V.push_back(G[i]);
	
	vector<int> pi=kmp(V);
	
	for(int i=0; i<pi.size(); i++)
	{
		//cout<<pi[i]<<" ";
		
		if(pi[i]==w-1)
		ans++;
	}
	
	cout<<ans;
}
