#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

vector<int> V;

int main()
{
	srand(time(NULL)); //generacja losowego ciągu 10 liczb z przedziału [1,1000]
	
	for(int i=0; i<10; i++) //polecam zmienić wartość, do której dąży i - łatwo w ten sposób zobaczyć jak szybko działa
	{						//algorytm nawet dla ogromnych zbiorów
		int x=rand()%1000+1;
		V.push_back(x);
	}
	
	sort(V.begin(), V.end());
	
	for(auto u: V)
	cout<<u<<" "; //wypisanie ciągu
	
	int x;
	cin>>x;
	
	int p=0, k=9, s; //wyszukiwanie binarne x'a w zbiorze V;  p-początek przedziału, k-koniec przedziału
	
	while(p<k) //powtarzamy dopóki nasz koniec jest dalej niż początek
	{
		s=(p+k)/2; //ustalamy obecny środek przedziału
		
		if(V[s]>=x) //skracamy przedział: usuwamy połowę, w której na pewno nie ma naszego szukanego x'a
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
