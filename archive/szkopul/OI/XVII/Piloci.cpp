#include<bits/stdc++.h>
using namespace std;

int t, n, a;
list< pair<int,int> > qmax, qmin;

void addmax(int v, int pos)
{
	while(!qmax.empty()&&qmax.back().first<=v)
	qmax.pop_back();
	qmax.push_back({v,pos});
}

void addmin(int v, int pos)
{
	while(!qmin.empty()&&qmin.back().first>=v)
	qmin.pop_back();
	qmin.push_back({v,pos});
}

void submax(int pos)
{
	if(qmax.front().second==pos)
	qmax.pop_front();
}

void submin(int pos)
{
	if(qmin.front().second==pos)
	qmin.pop_front();
}

int maxval()
{
	if(!qmax.empty())
	return qmax.front().first;
	return 0;
}

int minval()
{
	if(!qmin.empty())
	return qmin.front().first;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>t>>n;
	
	//for(int i=1; i<=n; i++)
	//cin>>tab[i];
	
	int w=1, idx=1;
	for(int i=1; i<=n; i++)
	{
		cin>>a;
		addmax(a, i); addmin(a, i);
		while(maxval()-minval()>t)
		{
			submax(idx);
			submin(idx++);
		}
		w=max(w, i-idx+1);
	}
	
	cout<<w;
}
