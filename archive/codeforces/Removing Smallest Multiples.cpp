#include<bits/stdc++.h>
using namespace std;

int t, n, x;
string s;
long long ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>n>>s;
		
		ans=0;
		
		for(int j=0; j<n; j++)
		{
			if(s[j]=='0'||s[j]=='2')
			{
				x=j;
	
				while(x<n && (s[x]=='0'||s[x]=='2'))
				{
					if(s[x]=='0')
					{
						ans+=j+1;
						s[x]='2';
					}
					x+=(j+1);
				}
			}
		}
		
		cout<<ans<<"\n";
	}
}
