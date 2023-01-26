#include<bits/stdc++.h>
using namespace std;

#define NTREE 1048576 //pierwsza potêga dwójki wiêksza ni¿ iloœæ elementów
int tree[NTREE*2];

void update(int val, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
	if(l==r)
	{
		tree[l]=max(tree[l],val);
		return;
	}
	
	tree[l]=max(tree[l],val);
	tree[r]=max(tree[r],val);
	
	while(r-l>1)
	{
		if(l%2==0) tree[l+1]+=max(tree[l+1],val);
		if(r%2==1) tree[r-1]+=max(tree[r-1],val);
		l/=2;
		r/=2;
	}	
}

int query(int pos)
{
	pos+=NTREE;
	int ans=0;
	while(pos)
	{
		ans=max(ans,tree[pos]);
		pos/=2;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);	
	return 0;
}
