#include<iostream>
#include <cstdlib>
#include<vector>
using namespace std;

int tab[1001][1001];

int main()
{
	int m, n, q, w, x, y ,z, wyn=0;
	vector <int> wyniki;
	
	cin>>m>>n>>q;
	
	for(int i=0; i<=m; i++)
	for(int j=0; j<=n; j++)
	{
		tab[i][j]=0;
	}
	
	for(int i=0; i<q; i++)
	{
		cin>>w>>x>>y>>z;
		if(w!=1&&x!=1)
		{
			tab[w-1][x-1]=abs(tab[w-1][x-1]-1);
			if(tab[w-1][x-1]==1)
			wyn++;
			else
			wyn--;
		}
		if(w!=1)
		{
			tab[w-1][z]=abs(tab[w-1][z]-1);
			if(tab[w-1][z]==1)
			wyn++;
			else
			wyn--;
		}
		if(x!=1)
		{
			tab[y][x-1]=abs(tab[y][x-1]-1);
			if(tab[y][x-1]==1)
			wyn++;
			else
			wyn--;
		}
		tab[y][z]=abs(tab[y][z]-1);
		if(tab[y][z]==1)
		wyn++;
		else
		wyn--;
		
		wyniki.push_back(wyn);
	}
	
	for(int i=0; i<wyniki.size(); i++)
	cout<<wyniki[i]<<"\n";
}
