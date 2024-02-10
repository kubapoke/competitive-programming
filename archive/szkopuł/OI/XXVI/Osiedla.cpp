#include<bits/stdc++.h>
#define X 1000001
using namespace std;

int n, m, a, b, l, kier[X], odw[X];
vector<int> kolej, g1[X], g2[X];
vector< pair<int,int> > graf[X];
pair<int,int> kraw[X], tempp;

void jakikier(int p)
{
	odw[p]++;
	
	for(int i=0; i<graf[p].size(); i++)
	{
		if(kier[graf[p][i].second]==0)
		{
			if(p==kraw[graf[p][i].second].first)
			kier[graf[p][i].second]=1;
			else
			kier[graf[p][i].second]=2;
			if(odw[graf[p][i].first]==0)
			jakikier(graf[p][i].first);
		}
	}
}

void postorder(int p)
{
	odw[p]++;
	for(int i=0; i<g1[p].size(); i++)
	{
		if(odw[g1[p][i]]==0)
		postorder(g1[p][i]);
	}
	kolej.push_back(p);
}

void ilescc(int p)
{
	odw[p]++;
	for(int i=0; i<g2[p].size(); i++)
	{
		if(odw[g2[p][i]]==0)
		ilescc(g2[p][i]);
	}
}


int main()
{
	cin>>n>>m;
	
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b;
		
		tempp.first=b; tempp.second=i;
		graf[a].push_back(tempp);
		
		tempp.first=a; tempp.second=i;
		graf[b].push_back(tempp);
		
		kraw[i].first=a;
		kraw[i].second=b;
	}
	
	for(int i=1; i<=n; i++)
	{
		if(odw[i]==0)
		jakikier(i);
	}
	
	for(int i=1; i<=m; i++)
	{
		if(kier[i]==1)
		{
			g1[kraw[i].first].push_back(kraw[i].second);
			g2[kraw[i].second].push_back(kraw[i].first);
		}
		else
		{
			g1[kraw[i].second].push_back(kraw[i].first);
			g2[kraw[i].first].push_back(kraw[i].second);
		}
	}
	
	for(int i=1; i<=n; i++)
	odw[i]=0;
	
	for(int i=1; i<=n; i++)
	{
		if(odw[i]==0)
		postorder(i);
	}
	
	for(int i=1; i<=n; i++)
	odw[i]=0;
	
	for(int i=kolej.size()-1; i>=0; i--)
	{
		if(odw[kolej[i]]==0)
		{
			l++;
			ilescc(kolej[i]);
		}
	}
	
	cout<<l<<"\n";
	
	for(int i=1; i<=m; i++)
	{
		if(kier[i]==1)
		cout<<">";
		else
		cout<<"<";
	}
	
	/*
	for(int i=1; i<=m; i++)
	cout<<kier[i]<<"\n";
	*/
}
