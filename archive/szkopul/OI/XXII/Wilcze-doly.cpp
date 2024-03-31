#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

long long d, n, p, w[2000007], pref[2000007], dech[2000007], ans;
deque<pair<long long,long long>> Q;

void sumpref()
{
    for(int i=1; i<=n; i++)
    pref[i]=pref[i-1]+w[i];
}

void dechy()
{
    for(int i=1; i<=n-d+1; i++)
    dech[i]=pref[i+d-1]-pref[i-1];
}

void addmax(long long val, int idx)
{
    while(!Q.empty() && Q.back().f<=val)
    Q.pop_back();
    Q.push_back({val,idx});
}

void delmax(int idx)
{
    if(Q.front().s==idx)
    Q.pop_front();
}

long long getmax()
{
    if(!Q.empty())
    return Q.front().f;
    return 0*1ll;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin>>n>>p>>d;

    for(int i=1; i<=n; i++)
    cin>>w[i];

    sumpref();
    dechy();

    ans=d;

    long long idx=1;
    Q.push_back({dech[1],1});

    for(long long i=d+1; i<=n; i++)
    {
        addmax(dech[i-d+1],i-d+1);

        while(pref[i]-pref[idx-1]>getmax()+p)
        {
            delmax(idx++);
        }

        ans=max(ans,i-idx+1ll);
    }
    
    //for(int i=1; i<=n-d+1; i++)
    //cout<<dech[i]<<" ";
    //cout<<"\n";

    cout<<ans;
}
