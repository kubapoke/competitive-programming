#include<bits/stdc++.h>
using namespace std;

//ababbababbabababbabababbababbaba

vector<int> kmp(string &n)
{
	vector<int> pi(n.size());
	
	for(int i=1; i<n.size(); i++)
	{
		int j=pi[i-1];
		while(j>0&&n[i]!=n[j])
		j=pi[j-1];
		if(n[i]==n[j])
		j++;
		pi[i]=j;
	}
	
	return pi;
}

bool check(int dl, vector<int> &pi)
{
	int count=0;
	
	//cout<<"\n"<<dl<<": ";
	
	for(int i=dl+1; i<pi.size(); i++)
	{
		if(pi[i]>dl)
		count=0;
		else
		count++;
		
		//cout<<count;
		
		if(count>dl)
		return false;
	}
	
	
	return true;
}

string n;
vector<int> kan, kan2;

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	
	vector<int> pi=kmp(n);
	
	//cout<<"\n\n";
	//for(int i=0; i<n.size(); i++)
	//cout<<pi[i]<<" ";
	//cout<<"\n\n";
	
	int f=pi.size()-1;
	
	while(f>0)
	{
		kan.push_back(f);
		f=pi[f]-1;
	}
	
	if(n[0]==n[n.size()-1])
	kan.push_back(0);
	
	//for(int i=0; i<kan.size(); i++)
	//cout<<kan[i]+1<<" ";
	
	for(int i=1; i<kan.size(); i++)
	{
		if(kan[i]*2<kan[i-1])
		kan2.push_back(kan[i-1]);
	}
	kan2.push_back(kan[kan.size()-1]);
	
	//for(int i=0; i<kan2.size(); i++)
	//cout<<kan2[i]<<" ";
	
	for(int i=kan2.size()-1; i>=0; i--)
	{
		if(check(kan2[i],pi)==true)
		{
			cout<<kan2[i]+1;
			return 0;
		}
	}
	
}
