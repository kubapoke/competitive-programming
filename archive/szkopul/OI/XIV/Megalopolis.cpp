#include<bits/stdc++.h>
#define NTREE 262144
using namespace std;

/*
10
1 2
2 3
2 4
1 5
5 6
1 7
7 9
7 8
8 10
*/

vector<int> graf[NTREE];
int n, a, b, m, idx, tree[NTREE*2], preorder[NTREE], postorder[NTREE], len[NTREE];
char c;

void dfs(int l,int s)
{
	idx++;
	preorder[l]=idx;
	len[l]=s;
	
	for(int i=0; i<graf[l].size(); i++)
	{
		dfs(graf[l][i], s+1);
	}
	
	postorder[l]=idx;
}

int getsum(int p)
{
	p=preorder[p];
	p+=NTREE-1;
	int s=0;
	
	while(p)
	{
		s+=tree[p];
		p/=2;
	}
	
	return s;
}

void changesum(int p)
{
	int x=preorder[p], y=postorder[p];
	
	x+=NTREE-1; y+=NTREE-1;
	
	if(x==y)
	{
		tree[x]++;
		return;
	}
	
	tree[x]++;
	tree[y]++;
	
	while(y-x>1)
	{
		if(x%2==0) tree[x+1]++;
		if(y%2==1) tree[y-1]++;
		x/=2; y/=2;
	}		
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	for(int i=1; i<n; i++)
	{
		cin>>a>>b;
		graf[a].push_back(b);
	}
	
	n--;
	
	dfs(1,0);

	cin>>m;
	
	while(n>0||m>0)
	{
		cin>>c;
		
		if(c=='W')
		{
			m--;
			
			cin>>a;
			
			cout<<len[a]-getsum(a)<<"\n";
		}
		else
		{
			n--;
			
			cin>>a>>b;
			
			changesum(b);
		}
	}
}
