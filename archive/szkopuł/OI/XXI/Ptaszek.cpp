#include<bits/stdc++.h>
#define N 1000010
using namespace std;

int n, q, a, b, tab[N], dp[N];
list <int> l1, l2;
list<int>::iterator it;

void add1(int i)
{
	while(l1.size()&&tab[i]>=tab[l1.back()]) l1.pop_back();
	l1.push_back(i);
}

void sub1(int i)
{
	if(l1.size()&&l1.front()==i) 
	l1.pop_front();
}

int best1()
{
	if(l1.size()) return l1.front();
	return -1;
}

void add2(int i)
{
	while(l2.size()&&tab[i]>=tab[l2.back()]) l2.pop_back();
	l2.push_back(i);	
}

void sub2(int i)
{
	if(l2.size()&&l2.front()==i) 
	l2.pop_front();	
}

int best2()
{
	if(l2.size()) return l2.front();
	return -1;
}

void adjust()
{
	if(l1.size()) return;
	for(it=l2.begin();it!=l2.end();++it)
	l1.push_back(*it);
	l2.clear();	
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	cin>>tab[i];
	
	cin>>q;
	
	for(int i=1; i<=q; i++)
	{
		cin>>a;
		
		if(a==1)
		{
			for(int j=2; j<=n; j++)
			if(tab[j]<tab[j-1]) dp[j]=dp[j-1];
			else dp[j]=dp[j-1]+1;
			cout<<dp[n]<<"\n";
		}
		else
		{
			l1.clear();
			l2.clear();
			dp[1]=0;
			l1.push_back(1);
			for(int j=2; j<=n; j++)
			{
				adjust();
				b=best1();
				if(tab[j]<tab[b]) 
				{
					dp[j]=dp[b];
					add1(j);
				}
				else 
				{
					dp[j]=dp[b]+1;
					add2(j);
				}
				if(j>=a+1) 
				{
					sub1(j-a);
					sub2(j-a);
				}
			}
			cout<<dp[n]<<"\n";
		}
	}
}
