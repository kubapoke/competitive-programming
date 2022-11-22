#include<bits/stdc++.h>
using namespace std;

vector<int> kmp(string &s)
{
	int n=s.size();
	vector<int> pi(n);
	for(int i=1; i<n; i++)
	{
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i]=j;
	}
	return pi;
}

int main()
{
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s; //s: s³owo, dla którego chcemy stworzyæ tablicê pi
	vector<int> pi=kmp(s);
	
	return 0;
}
