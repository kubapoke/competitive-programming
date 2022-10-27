#include<bits/stdc++.h>
using namespace std;

vector<int> V;

int main()
{
	srand(time(NULL)); //generacja losowego ci¹gu 10 liczb z przedzia³u [1,1000]
	
	for(int i=0; i<10; i++) //polecam zmieniæ wartoœæ, do której d¹¿y i - ³atwo w ten sposób zobaczyæ jak szybko dzia³a
	{						//algorytm nawet dla ogromnych zbiorów
		int x=rand()%1000+1;
		V.push_back(x);
	}
	
	sort(V.begin(), V.end());
	
	for(auto u: V)
	cout<<u<<" "; //wypisanie ci¹gu
	
	int x;
	cin>>x;
	
	int p=0, k=9, s; //wyszukiwanie binarne x'a w zbiorze V;  p-pocz¹tek przedzia³u, k-koniec przedzia³u
	
	while(p<k) //powtarzamy dopóki nasz koniec jest dalej ni¿ pocz¹tek
	{
		s=(p+k)/2; //ustalamy obecny œrodek przedzia³u
		
		if(V[s]>=x) //skracamy przedzia³: usuwamy po³owê, w której na pewno nie ma naszego szukanego x'a
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
