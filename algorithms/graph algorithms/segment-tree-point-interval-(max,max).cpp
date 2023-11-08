#include<iostream>
using namespace std;

#define NTREE 1048576 //pierwsza potęga dwójki większa niż ilość elementów
int tree[NTREE*2];

void update(int pos, int val)
{
	pos+=NTREE;
	while(pos)
	{
		tree[pos]=max(tree[pos],val);
		pos/=2;
	}
}

int query(int l, int r)
{
	l+=NTREE; r+=NTREE;
	int ans=0;
	
	if(l==r)
	{
		return tree[l];
	}
	
	ans=max(tree[l],tree[r]);
	
	while(r-l>1)
	{
		if(l%2==0) ans=max(ans,tree[l+1]);
		if(r%2==1) ans=max(ans,tree[r-1]);
		l/=2;
		r/=2;
	}	
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);	
	return 0;
}
