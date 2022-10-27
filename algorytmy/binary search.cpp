#include<bits/stdc++.h>
using namespace std;

vector<int> V;

int main()
{
	srand(time(NULL)); //generacja losowego ci�gu 10 liczb z przedzia�u [1,1000]
	
	for(int i=0; i<10; i++) //polecam zmieni� warto��, do kt�rej d��y i - �atwo w ten spos�b zobaczy� jak szybko dzia�a
	{						//algorytm nawet dla ogromnych zbior�w
		int x=rand()%1000+1;
		V.push_back(x);
	}
	
	sort(V.begin(), V.end());
	
	for(auto u: V)
	cout<<u<<" "; //wypisanie ci�gu
	
	int x;
	cin>>x;
	
	int p=0, k=9, s; //wyszukiwanie binarne x'a w zbiorze V;  p-pocz�tek przedzia�u, k-koniec przedzia�u
	
	while(p<k) //powtarzamy dop�ki nasz koniec jest dalej ni� pocz�tek
	{
		s=(p+k)/2; //ustalamy obecny �rodek przedzia�u
		
		if(V[s]>=x) //skracamy przedzia�: usuwamy po�ow�, w kt�rej na pewno nie ma naszego szukanego x'a
		k=s;
		else
		p=s+1;
	}
	
	s=(p+k)/2;
	
	if(V[s]==x)
	cout<<"Wyraz "<<x<<" znajduje sie w ciagu na pozycji "<<s+1;
	else
	cout<<"Wyraz "<<x<<" nie znajduje sie w ciagu";
}
