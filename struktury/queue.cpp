#include<iostream>
#include<queue>
using namespace std;

queue<int> Q; //queue<typ zmiennej> nazwa: deklaracja kolejki

int main()
{
	int x=1;
	
	for(int i=0; i<10; i++)	
	{
		Q.push(x); //nazwa.push(x): dodaje element o warto�ci x na koniec kolejki
		x*=2;
	}
	
	cout<<"Zawartosc kolejki: ";
	while(!Q.empty()) //dop�ki kolejka nie jest pusta
	{
		cout<<Q.front()<<" "; //nazwa.front(): zwraca element na pocz�tku kolejki
		Q.pop(); //nazwa.pop(): usuwa element na pocz�tku kolejki
	}
	cout<<"\n\n";

	return 0;
}
