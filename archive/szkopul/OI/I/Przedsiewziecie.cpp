#include<bits/stdc++.h>
#define X 100001
using namespace std;

int n, t, k, x, q, m, d, wart[X], wej[X], minczas[X], maxwart[X], tempmax, maxmax, maxwych[X], ostwart[X];
vector<int> graf[X], graf2[X], kolej;
queue<int> Q;


int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>t>>k;
		
		wart[i]=t;
		
		for(int j=1; j<=k; j++)
		{
			cin>>x;
			
			graf[x].push_back(i);
			graf2[i].push_back(x);
			wej[i]++;
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		if(wej[i]==0)
		Q.push(i);
	}
	
	while(Q.size())
	{
		int z=Q.front();
		Q.pop();
		kolej.push_back(z);
		for(int i=0; i<graf[z].size(); i++)
		{
			wej[graf[z][i]]--;
			if(wej[graf[z][i]]==0)
			Q.push(graf[z][i]);
		}
	}
	
	if(kolej.size()!=n)
	{
		cout<<"CYKL"; return 0;
	}
	
	for(int i=0; i<n; i++)
	{
		int z=kolej[i];
		tempmax=0;
		
		maxwart[z]+=wart[z];
		for(int j=0; j<graf2[z].size(); j++)
		{
			if(maxwart[graf2[z][j]]>tempmax)
			tempmax=maxwart[graf2[z][j]];
		}
		maxwart[z]+=tempmax;
		maxwych[z]=tempmax;
		if(maxmax<maxwart[z])
		maxmax=maxwart[z];
	}
	
	for(int i=n-1; i>=0; i--)
	{
		int z=kolej[i];
		
		if(graf[z].size()==0)
		{
			ostwart[z]=maxwart[z];
			continue;
		}
		
		tempmax=0;
		
		for(int j=0; j<graf[z].size(); j++)
		{
			if(ostwart[graf[z][j]]-maxwych[graf[z][j]]+maxwart[z]>tempmax)
			tempmax=ostwart[graf[z][j]]-maxwych[graf[z][j]]+maxwart[z];
		}
		
		ostwart[z]=tempmax;
	}
	
	cout<<maxmax<<"\n";
	
	cin>>q;
	
	for(int i=0; i<q; i++)
	{
		cin>>m>>d;
		
		if(ostwart[m]+d>maxmax)
		cout<<"TAK\n";
		else
		cout<<"NIE\n";
	}
	
	/*
	cout<<"\n"<<maxmax<<"\n\n";
	for(int i=1; i<=n; i++)
	{
		cout<<maxwart[i]<<"\n";
	}
	cout<<"\n";
	for(int i=1; i<=n; i++)
	{
		cout<<maxwych[i]<<"\n";
	}
	cout<<"\n";
	for(int i=1; i<=n; i++)
	{
		cout<<ostwart[i]<<"\n";
	}
	*/
}
