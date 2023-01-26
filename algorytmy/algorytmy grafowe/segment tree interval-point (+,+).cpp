#include<bits/stdc++.h>
using namespace std;

#define NTREE 1048576 //pierwsza potêga dwójki wiêksza ni¿ iloœæ elementów
int tree[NTREE*2];

void update(int val, int l, int r)
{
	l+=NTREE; r+=NTREE;
	
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
	while(pos)
	{
		sum+=tree[pos];
		pos/=2;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);	
	return 0;
}
