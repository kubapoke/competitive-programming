#include<bits/stdc++.h>
#include "cgdzlib.h"
using namespace std;

pair<int,int> find(vector<int> &w, int pow)
{
	if(w.size()==1)
	return{w[0],-1};
	if(w.size()==2)
	return{w[0],w[1]};
	
	int mn=pow*2;
	
	vector<int> w1, w2;
	for(int i=0; i<w.size(); i++)
	{
		if(f(w[0],w[i],mn))
		w1.push_back(w[i]);
		else
		w2.push_back(w[i]);
	}
	
	pair<int,int> p1=find(w1,mn), p2=find(w2,mn);
	
	int diff=(w.size()-1)*pow;
	
	if(p1.second!=-1 && f(p1.first,p1.second,diff))
		return{p1.first,p1.second};
	if(p1.second!=-1 && f(p2.first,p1.second,diff))
		return{p2.first,p1.second};
	if(p2.second!=-1 && f(p1.first,p2.second,diff))
		return{p1.first,p2.second};
	if(p2.second!=-1 && f(p2.first,p2.second,diff))
		return{p2.first,p2.second};
	if(f(p1.first,p2.first,diff))
		return{p1.first,p2.first};
	if(p1.second!=-1 && p2.second!=-1 && f(p1.second,p2.second,diff))
		return{p1.second,p2.second};
}

vector<int> v;

int main()
{
	int n=inicjuj();
	
	if(n==1)
	odpowiedz(1);
	
	for(int i=1; i<=n; i++)
	v.push_back(i);
	
	pair<int,int> wyn=find(v,1);
	
	if(g(wyn.first,wyn.second))
	odpowiedz(wyn.second);
	else
	odpowiedz(wyn.first);
}
