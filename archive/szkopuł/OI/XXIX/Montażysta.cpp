//Jakub P¹czka
#include<bits/stdc++.h>
using namespace std;

struct film{
	int t, d, idx;
}f[500001];

bool cp(const film &a, const film &b)
{
	return a.d<b.d;
}

long long n, c=0, w=0, ct=1;
bool check[500001];
priority_queue<pair<long long,long long> > PQ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>f[i].t>>f[i].d;
		f[i].idx=i;
	}
	
	sort(f+1, f+n+1, cp);
	
	for(int i=1; i<=n; i++)
	{
		PQ.push(make_pair(f[i].t, f[i].idx));
		c+=f[i].t;
		w++;
		if(c>f[i].d)
		{
			check[PQ.top().second]=true;
			c-=PQ.top().first;
			PQ.pop();
			w--;
		}
	}
	
	cout<<w<<"\n";
	
	for(int i=1; i<=n; i++)
	{
		if(check[f[i].idx]==false)
		{
			cout<<f[i].idx<<" "<<ct<<"\n";
			ct+=f[i].t;
		}
	}
}
