#include<bits/stdc++.h>
using namespace std;

queue<int> Q; //queue<typ zmiennej> nazwa: deklaracja kolejki

int main()
{
	int x=1;
	
	for(int i=0; i<10; i++)	
	{
		Q.push(x); //nazwa.push(x): dodaje element o wartoœci x na koniec kolejki
		x*=2;
	}
	
	cout<<"Zawartosc kolejki: ";
	while(!Q.empty()) //dopóki kolejka nie jest pusta
	{
		cout<<Q.front()<<" "; //nazwa.front(): zwraca element na pocz¹tku kolejki
		Q.pop(); //nazwa.pop(): usuwa element na pocz¹tku kolejki
	}
	cout<<"\n\n";

	return 0;
}
