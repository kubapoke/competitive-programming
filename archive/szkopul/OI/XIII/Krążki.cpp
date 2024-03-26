#include<bits/stdc++.h>
using namespace std;

stack<pair<int,int>> S; //para <szerokoœæ,g³êbokoœæ>
int n, m, a, ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1; i<=n; i++)
	{
		cin>>a;
		
		if(S.empty())
		S.push({a,i});
		else
		S.push({min(a,S.top().first),i});
	}
	
	for(int i=1; i<=m; i++)
	{
		cin>>a;
		
		if(S.empty())
		ans=0;
		else
		{
			while(!S.empty()&&S.top().first<a)
			S.pop();
			
			ans=S.size();
			
			S.pop();
		}	
	}
	
	cout<<ans;
}
