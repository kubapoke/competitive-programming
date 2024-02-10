#include<bits/stdc++.h>
using namespace std;

int n, d, w, ans;
stack<int> S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>d>>w;
		
		while(!S.empty()&&w<S.top())
		S.pop();
		
		if(S.empty()||w>S.top())
		{
			S.push(w);
			ans++;
		}	
	}
	
	cout<<ans;
}
