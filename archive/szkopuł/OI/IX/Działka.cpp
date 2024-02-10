#include<bits/stdc++.h>
#define X 2002
using namespace std;

stack< pair<int, int> > S; //wysokoœæ i miejsce
int fromtop[X][X], n, a, L[X], R[X], ans, wyn;
pair <int,int> temp;

int row(int i)
{
	wyn=0;
	
	while(S.size()) S.pop();
	
	temp.first=-1; temp.second=0;
	
	S.push(temp);
	
	for(int j=1; j<=n; j++)
	{
		while(S.top().first>=fromtop[i][j]) S.pop();
		
		L[j]=S.top().second;
		
		temp.first=fromtop[i][j]; temp.second=j;
		
		S.push(temp);
	}
	
	while(S.size()) S.pop();
	
	temp.first=-1; temp.second=n+1;
	
	S.push(temp);
	
	for(int j=n; j>=1; j--)
	{
		while(S.top().first>=fromtop[i][j]) S.pop();
		
		R[j]=S.top().second;
		
		temp.first=fromtop[i][j]; temp.second=j;
		
		S.push(temp);
	}
	
	for(int j=1; j<=n; j++)
	wyn=max(wyn, (R[j]-L[j]-1)*fromtop[i][j]);
	
	return wyn;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++)
	{
		cin>>a;
		if(a==0)
		fromtop[i][j]=fromtop[i-1][j]+1;
	}

	
	for(int i=1; i<=n; i++)
	ans=max(ans, row(i));
	cout<<ans;
	
}
