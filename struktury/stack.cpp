#include<bits/stdc++.h>
using namespace std;

stack<int> S; //stack<typ zmiennej> nazwa: deklaracja stosu

int main()
{
	int x=1;
	
	for(int i=0; i<10; i++)	
	{
		S.push(x); //nazwa.push(x): dodaje element o warto�ci x na g�r� stosu
		x*=2;
	}
	
	cout<<"Zawartosc stosu: ";
	while(!S.empty()) //dop�ki stos nie jest pusty
	{
		cout<<S.top()<<" "; //nazwa.front(): zwraca element na g�rze stosu
		S.pop(); //nazwa.pop(): usuwa element na g�rze stosu
	}
	cout<<"\n\n";

	return 0;
}
