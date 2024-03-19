#include<bits/stdc++.h>
using namespace std;

bool good[26], ast;
string g, tp, tl, tr;
int n;

void checknast(string s)
{
	if(s.size()!=tp.size())
	{
		cout<<"NO\n";
		return;
	}
	
	for(int i=0; i<s.size(); i++)
	{
		if((tp[i]!=s[i] && tp[i]!='?') || (tp[i]=='?' && good[s[i]-'a']==false))
		{
			cout<<"NO\n";
			return;
		}
	}
	
	cout<<"YES\n";
}

void checkast(string s)
{
	if(s.size()<tp.size()-1)
	{
		cout<<"NO\n";
		return;
	}
	
	for(int i=0; i<tl.size(); i++)
	{
		if((tl[i]!=s[i] && tl[i]!='?') || (tl[i]=='?' && good[s[i]-'a']==false))
		{
			cout<<"NO\n";
			return;
		}
	}
	
	int x=s.size()-tr.size();
	for(int i=tr.size()-1; i>=0; i--)
	{
		if((tr[i]!=s[i+x] && tr[i]!='?') || (tr[i]=='?' && good[s[i+x]-'a']==false))
		{
			cout<<"NO\n";
			return;
		}
	}
	
	for(int i=tl.size(); i<s.size()-tr.size(); i++)
	if(good[s[i]-'a']==true)
	{
		cout<<"NO\n";
		return;
	}
	
	cout<<"YES\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>g>>tp;
	
	for(int i=0; i<g.size(); i++)
	good[g[i]-'a']=true;
	
	for(int i=0; i<tp.size(); i++)
	if(tp[i]=='*')
	ast=true;
	
	cin>>n;
	
	if(ast==false)
	{
		for(int i=0; i<n; i++)
		{
			string s;
			cin>>s;
			checknast(s);
		}
	}
	else
	{
		bool b=false;
		for(int i=0; i<tp.size(); i++)
		{
			if(tp[i]=='*')
			b=true;
			else if(b==false)
			tl.push_back(tp[i]);
			else
			tr.push_back(tp[i]);
		}
		
		for(int i=0; i<n; i++)
		{
			string s;
			cin>>s;
			checkast(s);
		}
	}
}
