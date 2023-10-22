#include<iostream>
#include<list>
using namespace std;

list<int> L; //list<typ zmiennej> nazwa: deklaracja listy
list<int>::iterator it; //list<typ zmiennej>::iterator nazwa iteratora: deklaracja iteratora po li�cie

int main()
{
	int x=1;
	
	for(int i=0; i<5; i++)
	{
		L.push_front(x); //nazwa.push_front(warto��): rozszerza list� o 1 i dodaje na jej pocz�tek podany element
		x*=2;
		L.push_back(x); //nazwa.push_back(warto��): rozszerza list� o 1 i dodaje na jej koniec podany element
		x*=2;
	}
	
	cout<<"Zawartosc listy (1): ";
	for(it=L.begin(); it!=L.end(); it++) //przej�cie wcze�niej zadeklarowanym iteratorem po li�cie
	{
		cout<<*it<<" "; //wypisujemy *it, nie it, gdy� 'cout<<it' zwraca�oby adres w pami�ci iteratora a nie jego warto��
	}
	cout<<"\n\n";
	
	it=L.begin();
	advance(it, 5); //advance(nazwa iteratora, ilo�� element�w): przesuwa iterator o 5 element�w do przodu
	
	for(int i=0; i<5; i++)
	{
		L.insert(it,x); //nazwa.insert(nazwa iteratora, warto��): rozszerza list� o 1 i dodaje na pozycj� przed iteratorem podany element
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
