#include<bits/stdc++.h>
using namespace std;

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
	
int t;
cin>>t;

for(int it=0; it<t; it++)
{
	int n, beg, a;
	cin>>n;
	
	vector<int> V;
	beg=0;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		V.push_back(a);
		
		while(V[beg]<i+1-beg)
			beg++;
			
		cout<<i+1-beg<<" ";
	}
	cout<<"\n";
}


}
