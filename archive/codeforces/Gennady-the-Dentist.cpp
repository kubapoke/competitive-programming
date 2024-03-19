#include<bits/stdc++.h>
#define N 4001
using namespace std;

int n, v[N], d[N], p[N], ans;
queue<int> Q, Qsub;

void sub(int st, int w)
{
	for(int i=st; i<=n; i++)
	{
		if(p[i]>=0)
		{
			p[i]-=w;
			if(p[i]<0)
			w+=d[i];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1; i<=n; i++)
	cin>>v[i]>>d[i]>>p[i];
	
	for(int i=1; i<=n; i++)
	{
		if(p[i]>=0)
		{
			ans++;
			Q.push(i);
			
			int a=v[i], j=i+1;
			while(j<=n && a>0)
			{
				if(p[j]>=0)
				{
					p[j]-=a;
					a--;
					
					if(p[j]<0)
					{
						Qsub.push(j);
					}
				}
				j++; 
			}
			
			while(Qsub.size())
			{
				sub(Qsub.front()+1,d[Qsub.front()]);
				Qsub.pop();
			}
		}	
	}
	
	cout<<ans<<"\n";
	while(Q.size())
	{
		cout<<Q.front()<<" ";
		Q.pop();
	}
}
