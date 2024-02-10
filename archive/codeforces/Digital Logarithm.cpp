#include<bits/stdc++.h>
using namespace std;

int diglog(int n)
{
	int w=0;
	while(n)
	{
		w++;
		n/=10;
	}
	return w;
}

multiset<int> A, B;
int n, a, w;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
int tst;

cin>>tst;

for(int i=0; i<tst; i++)
{
	w=0;
	
	A.clear(); B.clear();
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>a;
		A.insert(a);
	}
	for(int i=0; i<n; i++)
	{
		cin>>a;
		B.insert(a);
	}
	
	while(A.size())
	{
//		cout<<*(prev(A.end()))<<" "<<*(prev(B.end()))<<"\n";
		
		if(*(prev(A.end()))==*(prev(B.end())))
		{
			A.erase(prev(A.end()));
			B.erase(prev(B.end()));
		}
		else
		{
			if(*(prev(A.end()))>=*(prev(B.end())))
			{
				A.insert(diglog(*(prev(A.end()))));
				A.erase(prev(A.end()));
			}
			else
			{
				B.insert(diglog(*(prev(B.end()))));
				B.erase(prev(B.end()));
			}
			
			w++;
		}
	}
	cout<<w<<"\n";
}
}
