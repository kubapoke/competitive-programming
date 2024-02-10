#include<bits/stdc++.h>
#define x 50001
using namespace std;
int n, m, a, b, licz, odw[x], wielscc[x], nrscc[x], odp[x], wej[x];
vector<int> graf[x], graf2[x], grafscc[x], kolej;
pair<int,int> kraw[x*2];
queue<int> Q;

void postorder(int p)
{
	odw[p]++;
	
	for(int i=0; i<graf[p].size(); i++)
	{
		if(odw[graf[p][i]]==0)
		postorder(graf[p][i]);
	}
	
	kolej.push_back(p);
}

void makescc(int p)
{
	odw[p]++;
	
	nrscc[p]=licz;
	wielscc[licz]++;
	
	for(int i=0; i<graf2[p].size(); i++)
	{
		if(odw[graf2[p][i]]==0)
		makescc(graf2[p][i]);
	}
}

int main()
{
	cin>>n>>m; //iloœæ krawêdzi, iloœæ ga³êzi
	for(int i=1; i<=m; i++)
	{
		cin>>a>>b; //wpisywanie po³¹czeñ a->b
		graf[a].push_back(b);
		graf2[b].push_back(a);
		kraw[i].first=a;
		kraw[i].second=b;
	}
	
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
			licz++;
			makescc(kolej[i]);
		}
	}
	
	kolej.clear();
	
	for(int i=1; i<=m; i++)
	{
		if(nrscc[kraw[i].first]!=nrscc[kraw[i].second])
		{
			grafscc[nrscc[kraw[i].first]].push_back(nrscc[kraw[i].second]);
			wej[nrscc[kraw[i].second]]++;
		}
	}
	
	for(int i=1; i<=licz; i++)
	{
		if(wej[i]==0)
		Q.push(i);
	}
	
	while(Q.size())
	{
		int p=Q.front();
		Q.pop();
		
		for(int i=0; i<grafscc[p].size(); i++)
		{
			wej[grafscc[p][i]]--;
			if(wej[grafscc[p][i]]==0)
			Q.push(grafscc[p][i]);
		}
		
		kolej.push_back(p);
	}
	
	for(int i=kolej.size()-1; i>=0; i--)
	{
		int p=kolej[i];
		odp[p]=wielscc[p]-1;
		for(int j=0; j<grafscc[p].size(); j++)
		{
			odp[p]+=odp[grafscc[p][j]]+1;
		}
	}
	
	for(int i=1; i<=n; i++)
	cout<<odp[nrscc[i]]<<"\n";
	
	
}
