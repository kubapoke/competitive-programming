#include<bits/stdc++.h>
using namespace std;

int n, s, l[500005], r[500005], d[500005], x=1, kpos;
long long w;
pair<int,int> t[500005];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>s;
	for(int i=1; i<n; i++)
	{
		cin>>l[i]>>r[i];
		d[i]=abs(l[i]-r[i]);
	}
	
	if(l[1]<r[1]) t[1]={1,0};
	else t[1]={1,1};
	w+=min(l[1],r[1]);
	
	for(int i=2; i<n; i++)
	{
		if(l[i]<r[i])
		{
			if(t[x].second==0)
			t[x].first++;
			else t[++x]={1,0};
		}
		else
		{
			if(t[x].second==1)
			t[x].first++;
			else t[++x]={1,1};
		}
		w+=min(l[i],r[i]);
	}
	
	if(t[1].second==0&&t[1].first>=s)
	{
		int p, k=1e9;
		for(int i=1; i<=s; i++)
		{
			if(k>d[i])
			{
				k=d[i];
				kpos=i;
			}	
		}
		w+=k;
		x+=2;
		p=t[1].first;
		for(int i=n-1; i>=2; i--)
		t[i+2]=t[i];
		t[1]={kpos-1,0};
		t[2]={1,1};
		t[3]={p-kpos,0};
		if(t[3].first==0)
		{
			t[2].first+=t[4].first;
			t[4].first=0;
		}
	}
	else if(t[1].second==1&&t[1].first>=n+1-s)
	{
		int p, k=1e9;
		for(int i=1; i<=n+1-s; i++)
		{	
			if(k>d[i])
			{
				k=d[i];
				kpos=i;
			}	
		}
		w+=k;
		x+=2;
		p=t[1].first;
		for(int i=n-1; i>=2; i--)
		t[i+2]=t[i];
		t[1]={kpos-1,1};
		t[2]={1,0};
		t[3]={p-kpos,1};
		if(t[3].first==0)
		{
			t[2].first+=t[4].first;
			t[4].first=0;
		}
	}
	
	cout<<w<<"\n";
	cout<<s<<" ";
	
	int lc=1, rc=n;
	for(int i=1; i<=x; i++)
	{
		if(t[i].first==0)
		continue;
		
		if(t[i].second==0)
		{
			int pocz=lc+t[i].first-1;
			if(s>=lc&&s<=pocz)
			pocz++;
			for(int j=pocz; j>=lc; j--)
			{
				if(j==s) continue;
				cout<<j<<" ";
			}
			lc=pocz+1;
		}
		if(t[i].second==1)
		{
			int pocz=rc-t[i].first+1;
			if(s>=pocz&&s<=rc)
			pocz--;
			for(int j=pocz; j<=rc; j++)
			{
				if(j==s) continue;
				cout<<j<<" ";
			}
			rc=pocz-1;
		}
	}
	
}
