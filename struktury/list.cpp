#include<bits/stdc++.h>
using namespace std;

list<int> L; //list<typ zmiennej> nazwa: deklaracja listy
list<int>::iterator it; //list<typ zmiennej>::iterator nazwa iteratora: deklaracja iteratora po liœcie

int main()
{
	int x=1;
	
	for(int i=0; i<5; i++)
	{
		L.push_front(x); //nazwa.push_front(wartoœæ): rozszerza listê o 1 i dodaje na jej pocz¹tek podany element
		x*=2;
		L.push_back(x); //nazwa.push_back(wartoœæ): rozszerza listê o 1 i dodaje na jej koniec podany element
		x*=2;
	}
	
	cout<<"Zawartosc listy (1): ";
	for(it=L.begin(); it!=L.end(); it++) //przejœcie wczeœniej zadeklarowanym iteratorem po liœcie
	{
		cout<<*it<<" "; //wypisujemy *it, nie it, gdy¿ 'cout<<it' zwraca³oby adres w pamiêci iteratora a nie jego wartoœæ
	}
	cout<<"\n\n";
	
	it=L.begin();
	advance(it, 5); //advance(nazwa iteratora, iloœæ elementów): przesuwa iterator o 5 elementów do przodu
	
	for(int i=0; i<5; i++)
	{
		L.insert(it,x); //nazwa.insert(nazwa iteratora, wartoœæ): rozszerza listê o 1 i dodaje na pozycjê przed iteratorem podany element
		x*=2;
	}
	
	cout<<"Zawartosc listy (2): ";
	for(it=L.begin(); it!=L.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n\n";
	
	for(int i=0; i<5; i++)
	{
		L.pop_front(); //nazwa.pop_front(): usuwa pierwszy element listy
		L.pop_back(); //nazwa.pop_back(): usuwa ostatni element listy
	}
	
	cout<<"Zawartosc listy (3): ";
	for(it=L.begin(); it!=L.end(); it++)
	{
		cout<<*it<<" ";
	}
	cout<<"\n\n";
	
	return 0;
}
