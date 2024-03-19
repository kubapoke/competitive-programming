#include<bits/stdc++.h>
using namespace std;

long long n, p, pas[100000], ans[100000], ex;
map<long long, vector<pair<int,int>>> wyd;
map<long long, vector<pair<int,int>>>::iterator it;
set<int> inq; //kto jest w kolejce
priority_queue<int, vector<int>, greater<int>> pq; //chc� wej�� do kolejki

//typ 0 -> sprawdza, czy mo�e wej�� do kolejki
//typ 1 -> wychodzi z kolejki 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>p;
	
	for(int i=0; i<n; i++)
	{
		cin>>pas[i];
		wyd[pas[i]].push_back({0,i});
	}
	
	for(it=wyd.begin(); it!=wyd.end(); it++)
	{
		for(int i=0; i<it->second.size(); i++)
		{
			if(it->second[i].first==0)
			{
				int mm;
				if(inq.empty()) mm=1e9;
				else mm=*inq.begin();
				
				if(mm>it->second[i].second)
				{
					inq.insert(it->second[i].second);
					wyd[max(ex,pas[it->second[i].second])+p].push_back({1,it->second[i].second});
					ex=max(ex,pas[it->second[i].second])+p;
				}
				else
				pq.push(it->second[i].second);
			}
			else
			{
				ans[it->second[i].second]=it->first;
				inq.erase(it->second[i].second);
			}
			
			int mm;
			if(inq.empty()) mm=1e9;
			else mm=*inq.begin();
			
			if(pq.size())
			if(mm>pq.top())
			{
				inq.insert(pq.top());
				wyd[max(ex,pas[pq.top()])+p].push_back({1,pq.top()});
				ex=max(ex,pas[pq.top()])+p;
				pq.pop();
			}
		}
	}
	
	for(int i=0; i<n; i++)
	cout<<ans[i]<<" ";
}
