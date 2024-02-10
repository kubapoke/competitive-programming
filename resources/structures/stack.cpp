#include<iostream>
#include<stack>
using namespace std;

stack<int> S; //stack<typ zmiennej> nazwa: deklaracja stosu

int main()
{
	int x=1;
	
	for(int i=0; i<10; i++)	
	{
		S.push(x); //nazwa.push(x): dodaje element o wartości x na górę stosu
		x*=2;
	}
	
	cout<<"Zawartosc stosu: ";
	while(!S.empty()) //dop�ki stos nie jest pusty
	{
		cout<<S.top()<<" "; //nazwa.front(): zwraca element na górze stosu
		S.pop(); //nazwa.pop(): usuwa element na górze stosu
	}
	cout<<"\n\n";

	return 0;
}
