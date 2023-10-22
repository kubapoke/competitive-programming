#include<iostream>
#include<queue>
using namespace std;

deque<int> DQ; //deque<typ zmiennej> nazwa: deklaracja dwustronnej kolejki

int main()
{
	int x=1;
	
	for(int i=0; i<5; i++)	
	{
		DQ.push_front(x); //nazwa.push_front(x): dodaje element o warto�ci x na pocz�tek kolejki
		x*=2;
		DQ.push_back(x); //nazwa.push_back(x): dodaje element o warto�ci x na koniec kolejki
		x*=2;
	}
	
	cout<<"Zawartosc kolejki: ";
	while(!DQ.empty()) //dop�ki kolejka nie jest pusta
	{
		cout<<DQ.front()<<" "; //nazwa.front(): zwraca element na pocz�tku kolejki
		DQ.pop_front(); //nazwa.pop_front(): usuwa element na pocz�tku kolejki
	}
	cout<<"\n\n";

	return 0;
}
