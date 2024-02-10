#include<iostream>
#include<queue>
using namespace std;

deque<int> DQ; //deque<typ zmiennej> nazwa: deklaracja dwustronnej kolejki

int main()
{
	int x=1;
	
	for(int i=0; i<5; i++)	
	{
		DQ.push_front(x); //nazwa.push_front(x): dodaje element o wartości x na początek kolejki
		x*=2;
		DQ.push_back(x); //nazwa.push_back(x): dodaje element o wartości x na koniec kolejki
		x*=2;
	}
	
	cout<<"Zawartosc kolejki: ";
	while(!DQ.empty()) //dopóki kolejka nie jest pusta
	{
		cout<<DQ.front()<<" "; //nazwa.front(): zwraca element na początku kolejki
		DQ.pop_front(); //nazwa.pop_front(): usuwa element na początku kolejki
	}
	cout<<"\n\n";

	return 0;
}
