#include<bits/stdc++.h>
using namespace std;

long long n, h=100;
char tab[101][101];

void make_stripe(int x, int y)
{
	if(min(x,y)<1)
	return;
	
	for(int i=0; i<4; i++)
	{
		tab[max(x,0)][max(y,0)]='.';
		x--;
	}
	
	x+=4;
	y--;
	
	for(int i=0; i<4; i++)
	{
		tab[max(x,0)][max(y,0)]='.';
		x--;
	}
	
	make_stripe(x+1,y);
}

void make_line1()
{
	for(int i=2; i<=100; i++)
	{
		if(tab[h][i]=='.')
		break;
		
		tab[h][i]='.';
	}
}

void make_line2()
{
	for(int i=2; i<=100; i++)
	{
		if(tab[h-1][i]=='.')
		break;
		
		tab[h-1][i]='.';
	}
}

void make_line3()
{
	for(int i=2; i<=100; i++)
	{
		if(tab[h-1][i]=='.')
		{
			tab[h][i-1]='.';
			break;
		}
		
		tab[h-1][i]='.';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=1; i<=100; i++)
	for(int j=1; j<=100; j++)
	{
		if(j==1)
		tab[i][j]='.';
		else
		tab[i][j]='#';
	}
	
	make_stripe(100,100);	
	
	while(n)
	{
		if(n%4==1)
		make_line1();
		else if(n%4==2)
		make_line2();
		else if(n%4==3)
		make_line3();
		
		n/=4;
		h-=3;
	}
	
	cout<<100<<"\n";
	for(int i=1; i<=100; i++)
	{
		for(int j=1; j<=100; j++)
		cout<<tab[i][j];
		cout<<"\n";
	}
}
