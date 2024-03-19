#include<iostream>
#define N 100000
#define INF 1000000000
using namespace std;

long long p=31, mod=1e9+7, pN[N], hashe[N];

int n;
string s;

void init()
{
	pN[0]=1;
	
	for(int i=1; i<=n; i++)
	pN[i]=(pN[i-1]*p)%mod;
	
	for(int i=n; i>=1; i--)
	hashe[i]=(s[i-1]*p + hashe[i+1]*p)%mod;
}

long long gethash(int pos, int len)
{
	long long ans=(hashe[pos]-hashe[pos+len]*pN[len])%mod;
	if(ans<0) ans+=mod;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>s; //s: słowo, dla którego chcemy stworzyć hashe
	n=s.size();
	init();
	
	//od teraz hash(pos,len) zwraca hash fragmentu dlugosci len na pozycji pos
	
	return 0;
}

