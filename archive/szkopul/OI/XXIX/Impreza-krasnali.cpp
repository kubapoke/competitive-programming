//Jakub P¹czka
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, nwyk=0, ppos, kpos, d, a;
long long w=1;
pair<int,int> wys[100001]; //wyst¹pienia wartoœci
bool wyk[100001], imp; //niemo¿liwa kombinacja
vector<int> npar, par;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	d=n%2;
	
	for(int i=1; i<=n; i++)
	{
		cin>>a;
		
		if(i%2==1)
		npar.push_back(a);
		else
		par.push_back(a);
		
		if(wys[a].first==0)
		wys[a].first=i;
		else if(wys[a].second==0)
		{
			wys[a].second=i;
			if(wys[a].second!=wys[a].first+2)
			imp=true;
		}
		else
		imp=true;
		
		wyk[a]=true;
	}
	
	if(imp==true)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1; i<=n; i++)
	if(wyk[i]==false)
	nwyk++;
	//cout<<nwyk<<" ";
	
	if(nwyk==0)
	{
		if(d==0)
		cout<<1;
		else
		cout<<0;
		return 0;
	}
	
	long long f=1;
	
	for(int i=1; i<=nwyk; i++)
	f=((f%MOD)*(i%MOD))%MOD;
	
	for(int i=1; i<npar.size(); i++)
	{
		ppos=i;
		if(npar[i]==npar[i-1])
		break;
	}
	
	if(d==1)
	{
		for(int i=npar.size()-2; i>=0; i--)
		{
			kpos=i;
			if(npar[i]==npar[i+1])
			break;
		}
		if(kpos-ppos<-1)
		{
			cout<<0;
			return 0;
		}
	}
	else
	for(int i=par.size()-2; i>=0; i--)
	{
		kpos=i;
		if(par[i]==par[i+1])
		break;
	}
	
	//cout<<ppos<<" "<<kpos<<"\n";
	
	if(d==1)
	{
		int l=0;
		for(int i=ppos+1; i<kpos; i++)
		{
			if(npar[i]!=npar[i-1])
			l++;
			else
			{
				w=((w%MOD)*(l%MOD))%MOD;
				//cout<<l<<" ";
				l=0;
			}
		}
		w=((w%MOD)*((l+1)%MOD))%MOD;
		//cout<<l<<" ";
		l=0;
		for(int i=0; i<par.size(); i++)
		{
			if(par[i]!=par[i-1])
			l++;
			else
			{
				w=((w%MOD)*(l%MOD))%MOD;
				//cout<<l<<" ";
				l=0;
			}
		}
		w=((w%MOD)*((l+1)%MOD))%MOD;
		//cout<<l<<" ";
	}
	else
	{
		int l=0;
		for(int i=ppos+1; i<npar.size(); i++)
		{
			if(npar[i]!=npar[i-1])
			l++;
			else
			{
				w=((w%MOD)*(l%MOD))%MOD;
				//cout<<l<<" ";
				l=0;
			}	
		}
		w=((w%MOD)*((l+1)%MOD))%MOD;
		//cout<<l<<" ";
		l=0;
		for(int i=0; i<kpos; i++)
		{
			if(par[i]!=par[i-1])
			l++;
			else
			{
				w=((w%MOD)*(l%MOD))%MOD;
				//cout<<l<<" ";
				l=0;
			}
		}
		w=((w%MOD)*((l+1)%MOD))%MOD;
		//cout<<l<<" ";
	}
	
	
	//cout<<f<<"\n";
	w=((w%MOD)*(f%MOD))%MOD;
	cout<<w;
	
}
