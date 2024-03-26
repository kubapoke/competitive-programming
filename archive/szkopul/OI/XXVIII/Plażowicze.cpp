#include<bits/stdc++.h>
using namespace std;

struct pla{
	long long p, n; //iloœæ osób
	long double l; //pozycja pocz¹tkowa, d³ugoœæ pojedynczego fragmentu
};

struct query{
	int q, idx;
	long double ans;
};

bool Qcomp(pla &a, pla &b)
{
	if(a.l!=b.l)
	return (a.l<b.l);
	
	return(a.p>b.p);
}

bool scomp(query &a, query &b)
{
	return (a.q<b.q);
}

bool icomp(query &a, query &b)
{
	return (a.idx<b.idx);
}

void wypisz(long double l)
{
	long long m=1;
	
	while(l!=floor(l))
	{
		l*=2;
		m*=2;
	}
	
	cout<<fixed<<setprecision(0)<<l<<"/"<<m<<"\n";
}

int n, X, z, x, k;
vector<query> zap;
queue<pla> Q;
priority_queue<pla, vector<pla>, decltype(&Qcomp)> init(Qcomp);

int main()
{
	cin>>n>>X>>z;
	
	for(int i=0; i<n; i++)
	{
		int y=x;
		cin>>x;
		
		if(i)
		{
			pla p;
			p.p=y;
			p.n=1;
			p.l=(long double)(x-y);
			init.push(p);
		}
	}
	
	for(int i=0; i<z; i++)
	{
		cin>>k;
		
		query q;
		q.q=k;
		q.idx=i;
		q.ans=0;
		
		zap.push_back(q);
	}
	
	sort(zap.begin(), zap.end(), scomp);
	
	int p=0;
	long long c=0, d;
	
	while(p<zap.size())
	{
		bool czypq=false;
		
		if(!Q.size())
		czypq=true;
		else if(Q.size() && init.size())
		{
			if(init.top().l > Q.front().l || (init.top().l==Q.front().l && init.top().p<Q.front().p))
			czypq=true;
		}
		
		if(czypq==true)
		{
			pla pl=init.top();
			init.pop();
			
			d=c;
			c+=pl.n;
			long double j=pl.p+(pl.l/2);
			
			while(c>=zap[p].q)
			{
				long double odp=j+(zap[p].q-d-1)*pl.l;
				zap[p].ans=odp;
				p++;
				
				if(p>=zap.size())
				break;
			}
			
			pl.l/=2;
			pl.n*=2;
			
			Q.push(pl);
		}
		else
		{
			pla pl=Q.front();
			Q.pop();
			
			d=c;
			c+=pl.n;
			long double j=pl.p+(pl.l/2);
			
			while(c>=zap[p].q)
			{
				long double odp=j+(zap[p].q-d-1)*pl.l;
				zap[p].ans=odp;
				p++;
				
				if(p>=zap.size())
				break;
			}
			
			pl.l/=2;
			pl.n*=2;
			
			Q.push(pl);
		}
	}
	
	sort(zap.begin(), zap.end(), icomp);
	
	for(int i=0; i<zap.size(); i++)
	wypisz(zap[i].ans);
}
