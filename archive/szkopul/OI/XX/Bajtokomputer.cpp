#include<bits/stdc++.h>
#define ujemny 0
#define zero 1
#define dodatni 2
#define MAX 10000000
#define X 1000001
using namespace std;

int n, dp[3][X], c[X];

int main()
{
	cin>>n;
	
	for(int i=1; i<=n; i++)
	{
		cin>>c[i];
	}
	
	dp[0][1]=dp[1][1]=dp[2][1]=MAX;
	dp[c[1]+1][1]=0;
	
	for(int i=2; i<=n; i++)
	{
		if(c[i]==-1)
		{
			dp[ujemny][i]=dp[ujemny][i-1];
			dp[zero][i]=MAX;
			dp[dodatni][i]=dp[dodatni][i-1]+2;
		}
		else if(c[i]==0)
		{
			dp[ujemny][i]=dp[ujemny][i-1]+1;
			dp[zero][i]=min(dp[ujemny][i-1], dp[zero][i-1]);
			dp[dodatni][i]=dp[dodatni][i-1]+1;
		}
		else if(c[i]==1)
		{
			dp[ujemny][i]=dp[ujemny][i-1]+2;
			dp[zero][i]=dp[ujemny][i-1]+1;
			dp[dodatni][i]=min(dp[ujemny][i-1], min(dp[zero][i-1], dp[dodatni][i-1]));
		}
	}
	
	if(min(dp[ujemny][n], min(dp[zero][n], dp[dodatni][n]))<MAX)
	cout<<min(dp[ujemny][n], min(dp[zero][n], dp[dodatni][n]));
	else
	cout<<"BRAK";
}
