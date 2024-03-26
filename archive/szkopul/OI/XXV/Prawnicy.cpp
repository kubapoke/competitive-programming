#include<bits/stdc++.h>
#define X 1000001
using namespace std;
//6 3 3 8 4 12 2 6 1 10 5 9 11 12
struct pr{
	int a, b, idx;
}prawnicy[X];

bool compare1(const pr &x, const pr &y)
{
	return x.a<y.a;
}

bool compare2(const pr &x, const pr &y)
{
	return x.idx<y.idx;
}

priority_queue< int, vector<int>, greater<int> > PQ;

int n, k, ans, ansidx, tempans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin>>n>>k;
	
	if(k>1)
	{
		for(int i=1; i<=n; i++)
		{
			cin>>prawnicy[i].a>>prawnicy[i].b;
			prawnicy[i].idx=i;
		}
	
		sort(prawnicy+1, prawnicy+n+1, compare1);
		
		for(int i=1; i<=n; i++)
		{
			while(PQ.size()>k-1)
			PQ.pop();
			
			if(PQ.size()==k-1)
			{
				if(PQ.top()>prawnicy[i].a)
				{
					tempans=min(prawnicy[i].b-prawnicy[i].a, PQ.top()-prawnicy[i].a);
					
					if(tempans>ans)
					{
						ans=tempans;
						ansidx=prawnicy[i].a;
					}
					
					tempans=0;
				}
			}
			
			PQ.push(prawnicy[i].b);
		}
		
		sort(prawnicy+1, prawnicy+n+1, compare2);
		
		cout<<ans<<"\n";
		
		int c=0;
		
		for(int i=1; i<=n; i++)
		{
			if(prawnicy[i].a<=ansidx&&prawnicy[i].b>=ansidx+ans)
			{
				cout<<i<<" ";
				c++;
				if(c==k)
				break;
			}
		}
		return 0;
	}
	else
	{
		for(int i=1; i<=n; i++)
		{
			cin>>prawnicy[i].a>>prawnicy[i].b;
			if(prawnicy[i].b-prawnicy[i].a>ans)
			{
				ans=prawnicy[i].b-prawnicy[i].a;
				ansidx=i;
			}
		}
		cout<<ans<<"\n"<<ansidx;
	}
	
}
