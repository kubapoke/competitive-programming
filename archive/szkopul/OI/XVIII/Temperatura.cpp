#include<bits/stdc++.h>
#define NTREE 1048576
using namespace std;

/*
7
9 10
5 10
6 8
8 11
6 7
6 8
4 5
*/

int n, a, b, ans=1, tempans=1, tree[NTREE*2], qs[NTREE];

int getmax(int x, int y)
{
	x+=NTREE; y+=NTREE;
	int w=max(tree[x],tree[y]);
	
	if(x==y)
	return tree[x];
	
	while(y-x>1)
	{
		if(x%2==0) w=max(w,tree[x+1]);
		if(y%2==1) w=max(w,tree[y-1]);
		x/=2;
		y/=2;
	}
	
	return w;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>tree[i+NTREE]>>qs[i];
	}
	
	for(int i=NTREE-1; i>0; i--)
	{
		tree[i]=max(tree[i*2], tree[i*2+1]);
	}
	
	int x=0, y=0;
	
	while(y<n-1)
	{
		if(getmax(x,y)<=qs[y+1])
		{
			tempans++;
			y++;
		}
		else
		{
			if(tempans!=1)
			tempans--;
			x++;
			if(x>y)
			y++;
			
		}	
		
		if(tempans>ans)
		ans=tempans;	
	}
	
	cout<<ans;
}
