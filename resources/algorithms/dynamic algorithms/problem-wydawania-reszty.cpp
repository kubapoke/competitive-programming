#include<iostream>
#define N 100000
#define INF 1000000000
using namespace std;

int main()
{
	int n, a, tab[N], dp[N];
	
	cin>>n>>a; //n: ilość nominałów, a: wartość, którą chcemy wydać
	
	for(int i=0; i<n; i++)
	cin>>tab[i]; //tab[i]: i-ty nominał
	
	dp[0]=0;
	
	for(int i=1; i<=a; i++)
	dp[i]=INF;
	
	for(int i=0; i<n; i++)
	for(int j=tab[i]; j<=a; j++)
	dp[j]=min(dp[j],dp[j-tab[i]]+1);
		
	if(dp[a]==INF)
	{
		cout<<"Wartosc niemozliwa do wydania przy uzyciu podanych nominalow";
		return 0;
	}
	
	cout<<"Wartosc moze byc wydana uzywajac do tego minimalnie "<<dp[a]<<" monet";
}
