#include<bits/stdc++.h>
using namespace std;

int n, X, z, cv=1, k, platf[100001], d[2100001]/*, st[2100001]*/;
//int V, E;
vector<pair<int,int> > G[2100001]; //nast?pnik, koszt
//stack<int> PQ;
priority_queue<pair<int,int> > PQ;
queue<pair<int,int> > dz[100001]; //pozycja, platforma

/*
void postsort(int p)
{
	d[p]++;
	for(int i=0; i<G[p].size(); i++)
	{
		if(d[G[p][i].first]==0)
		postsort(G[p][i].first);
	}
	PQ.push(p);
}
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>X>>z;
	
	//PQ.push(make_pair(X+1,0));
	
	for(int cc=1; cc<=n; cc++)
	{
		cin>>k;
		platf[cc]=cv;
		for(int i=1; i<=k; i++)
		{
			int h;
			cin>>h;
			//PQ.push(make_pair(h,cv));
			dz[cc].push(make_pair(h,cv));
			if(platf[cc]!=cv)
			{
				G[cv].push_back(make_pair(cv-1,1));
				//cout<<cv<<" "<<cv-1<<" "<<1<<"\n";
				//E++;
				//st[cv-1]++;
			}
			while(!dz[cc-1].empty())
			{
				if(dz[cc-1].front().first<h)
				{
					G[cv].push_back(make_pair(dz[cc-1].front().second,0));
					//cout<<cv<<" "<<dz[cc-1].front().second<<" "<<0<<"\n";
					//E++;
					//st[dz[cc-1].front().second]++;
					G[dz[cc-1].front().second+1].push_back(make_pair(cv,1));
					//cout<<dz[cc-1].front().second+1<<" "<<cv<<" "<<1<<"\n";
					//E++;
					//st[cv]++;
					dz[cc-1].pop();
				}
				else
				break;
			}
			cv++;
		}
		//PQ.push(make_pair(X,cv));
		if(platf[cc]!=cv)
		{
			G[cv].push_back(make_pair(cv-1,1));
			//cout<<cv<<" "<<cv-1<<" "<<1<<"\n";
			//E++;
			//st[cv-1]++;
		}
		while(!dz[cc-1].empty())
		{
			G[cv].push_back(make_pair(dz[cc-1].front().second,0));
			//cout<<cv<<" "<<dz[cc-1].front().second<<" "<<0<<"\n";
			//E++;
			//st[dz[cc-1].front().second]++;
			G[dz[cc-1].front().second+1].push_back(make_pair(cv,1));
			//cout<<dz[cc-1].front().second+1<<" "<<cv<<" "<<1<<"\n";
			//E++;
			//st[cv]++;
			dz[cc-1].pop();
		}
		G[0].push_back(make_pair(cv,0));
		//cout<<0<<" "<<cv<<" "<<0<<"\n";
		//E++;
		//st[cv]++;
		cv++;
	}
	
	//postsort(0);
	
	//V=cv-1;
	//cout<<V<<" "<<E<<"\n";
	
	//for(int i=0; i<cv; i++)
	//for(int j=0; j<G[i].size(); j++)
	//cout<<i<<" "<<G[i][j].first<<" "<<G[i][j].second<<"\n";
	
	d[0]=0;
	for(int i=1; i<cv; i++)
	d[i]=4200000;
	
	PQ.push(make_pair(0,0));
	
	while(!PQ.empty())
	{
		int dis=PQ.top().first*(-1);
		int v=PQ.top().second;
		//cout<<v<<"\n";
		PQ.pop();
		if(dis>d[v]) continue;
		//cout<<dis<<" "<<v<<"\n";
		for(int i=0; i<G[v].size(); i++)
		{
			int U=G[v][i].first;
			int K=G[v][i].second;
			if(d[U]>d[v]+K)
			{
				d[U]=dis+K;
				PQ.push(make_pair(d[U]*(-1),U));
				//cout<<G[v][i].first<<" ";
			}
		}
		//cout<<v<<"\n";
		//if(v==12)
		//break;
	}

	
	
	/*
	for(int i=1; i<cv; i++)
	cout<<d[i]<<" ";
	cout<<"\n";
	for(int i=0; i<GR[14].size(); i++)
	cout<<GR[11][i].second<<" ";
	cout<<d[11];
	*/
	
	for(int i=0; i<z; i++)
	{
		int x;
		cin>>x;
		cout<<d[platf[x]]<<"\n";
	}
	
}
