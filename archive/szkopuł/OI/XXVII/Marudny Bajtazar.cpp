#include<bits/stdc++.h>
using namespace std;

int n, m, ile[18], a;
string s;
map<int,int> M[18]; //para<jaki ci¹g, ile razy siê pojawia>

void outans()
{
    for(int i=1; i<18; i++)
    {
        if(ile[i]!=pow(2,i))
        {
            cout<<i<<"\n";
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;

    cin>>s;

    for(int i=0; i<n; i++)
    {
        long long d=0;
        for(int j=i; j<i+17 && j<n; j++)
        {
            d*=2;
            if(s[j]=='1')
            d++;

            int x = ++M[j-i+1][d];

            if(x==1)
            ile[j-i+1]++;
        }
    }

    outans();

    for(int u=0; u<m; u++)
    {
        cin>>a;
        
        a-=1;

        for(int i=a; i>a-17 && i>=0; i--)
        {
            long long d=0;
            for(int j=i; j<a; j++)
            {
                d*=2;
                if(s[j]=='1')
                d++;
            }
            for(int j=a; j<i+17 && j<n; j++)
            {
                d*=2;
                if(s[j]=='1')
                d++;

                int x = --M[j-i+1][d];

                if(x==0)
                ile[j-i+1]--;
            }
        }

        if(s[a]=='0')
        s[a]='1';
        else
        s[a]='0';

        for(int i=a; i>a-17 && i>=0; i--)
        {
            long long d=0;
            for(int j=i; j<a; j++)
            {
                d*=2;
                if(s[j]=='1')
                d++;
            }
            for(int j=a; j<i+17 && j<n; j++)
            {
                d*=2;
                if(s[j]=='1')
                d++;

                int x = ++M[j-i+1][d];

                if(x==1)
                ile[j-i+1]++;
            }
        }

        outans();
    }
}
