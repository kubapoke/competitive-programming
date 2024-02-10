#include<bits/stdc++.h>
using namespace std;

#define NTREE 4098
//3 5 2 1 5 3 3 3 4 1 3 3 4 4 2 4 4 3

int n, m, k, maks, tab[3001][3001], tree[2*NTREE];
map<int,int> mapa[100001];
long long w;

void update(int val, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
	if(l>r)
	return;
	
	if(l==r)
	{
		tree[l]+=val;
		return;
	}
	
	tree[l]+=val;
	tree[r]+=val;
	
	while(r-l>1)
	{
		if(l%2==0) tree[l+1]+=val;
		if(r%2==1) tree[r-1]+=val;
		l/=2;
		r/=2;
	}	
}

int query(int pos)
{
	pos+=NTREE;
	int sum=0;
	while(pos>1)
	{
		sum+=tree[pos];
		pos/=2;
	}
	return sum;
}

void addcol(int c)
{
	for(int i=1; i<=n; i++)
	{
		int v=tab[i][c];
		
		map<int,int>::iterator it=mapa[v].find(i);
		
		if(it->second!=0&&it!=mapa[v].end())
		{
			it->second++;
		}
		else
		{
			mapa[v][i]=1;
			it=mapa[v].find(i);
			
			map<int,int>::iterator itup=it;
			map<int,int>::iterator itdown=it;
			itup++; itdown--;
			
			int up=itup->first;
			int down=itdown->first;
			
			int pocz=i-k+1;
			int kon=i;
			
			pocz=max(pocz,down+1);
			kon=min(kon,up-k);
			
			update(1,pocz,kon);
		}
	}
}

void remcol(int c)
{
	for(int i=1; i<=n; i++)
	{
		int v=tab[i][c];
		
		map<int,int>::iterator it=mapa[v].find(i);
		
		if(it->second!=1&&it!=mapa[v].end())
		{
			it->second--;
		}
		else
		{
			it=mapa[v].find(i);
			map<int,int>::iterator itup=it;
			map<int,int>::iterator itdown=it;
			itup++; itdown--;
			
			mapa[v].erase(it);
			
			int up=itup->first;
			int down=itdown->first;
			
			int pocz=i-k+1;
			int kon=i;
			
			pocz=max(pocz,down+1);
			kon=min(kon,up-k);
			
			update(-1,pocz,kon);
		}
	}
}

void wyn()
{
	for(int i=1; i<=n-k+1; i++)
	{
		int q=query(i);
		maks=max(maks,q);
		w+=q;
		//cout<<maks<<" "<<w<<"  "<<q<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>k;
	
	for(int i=n; i>=1; i--)
	for(int j=1; j<=m; j++)
	cin>>tab[i][j];
	
	
	for(int i=1; i<100001; i++)
	{
		mapa[i][0]=1;
		mapa[i][100001+k]=1;
	}
	
	for(int i=1; i<=k; i++)
	addcol(i);
	
	wyn();
	
	for(int i=k+1; i<=m; i++)
	{
		remcol(i-k);
		addcol(i);
		wyn();
	}
	
	cout<<maks<<" "<<w;
}
