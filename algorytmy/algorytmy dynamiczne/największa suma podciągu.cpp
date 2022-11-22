#include<bits/stdc++.h>
#define N 100000
#define INF 1000000000
using namespace std;

int main()
{
	int n, tab[N], dp[N], suma;
	
	cin>>n; //n: d³ugoœæ ci¹gu
	
	for(int i=0; i<n; i++)
	cin>>tab[i]; //tab[i]: kolejne elementy ci¹gu
	
	dp[0]=tab[0];
	suma=dp[0];
	
	for(int i=1; i<n; i++)
	{
		dp[i]=max(tab[i],dp[i-1]+tab[i]);
		suma=max(suma,dp[i]);
	}
	
	cout<<"Najwieksza suma spojnego podciagu podanego ciagu wynosi "<<suma;
}
