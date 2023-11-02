#include<iostream>
using namespace std;

#define NTREE 1048576 //pierwsza potęga dwójki większa niż ilość elementów
int tree[NTREE*2];

void update(int pos, int val)
{
	pos+=NTREE;
	while(pos)
	{
		tree[pos]+=val;
		pos/=2;
	}
}

int query(int l, int r)
{
	l+=NTREE; r+=NTREE;
	int sum=0;
	
	if(l==r)
	{
		return tree[l];
	}
	
	sum+=tree[l]+tree[r];
	
	while(r-l>1)
	{
		if(l%2==0) sum+=tree[l+1];
		if(r%2==1) sum+=tree[r-1];
		l/=2;
		r/=2;
	}	
	
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0);	
	return 0;
}
