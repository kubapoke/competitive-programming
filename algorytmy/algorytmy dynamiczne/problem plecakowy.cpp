#include<bits/stdc++.h>
#define N 100000
#define INF 1000000000
using namespace std;

int main()
{
	int n, g, tab[N], dp[N];
	
	cin>>g>>n; //g: g��boko�� plecaka, n: ilo�� umieszczanych w plecaku przedmiot�w

	for(int i=0; i<n; i++)
	cin>>tab[i]; //tab[i]: wielko�� kolejnych element�w wk�adanych do plecaka
	
	dp[0]=1;
	
	for(int i=1; i<=g; i++)
	dp[i]=0;
	
	for(int i=0; i<n; i++)
	for(int j=g-tab[i]; j>=0; j--)
	if(dp[j]==1)
	dp[j+tab[i]]=1;
	
	for(int j=g; j>=0; j--)
	{
		if(dp[j]==1)
		{
			cout<<"Jestesmy w stanie zapelnic plecak elementami o maksymalnej sumarycznej wielkosci rownej "<<j;
			return 0;
		}
	}
		
	return 0;
}
