#include<iostream>
#include<vector>
using namespace std;

vector<int> V; //vector<typ zmiennej> nazwa: deklaracja vectora

int main()
{
	int x=1;
	
	for(int i=0; i<10; i++)
	{
		V.push_back(x); //nazwa.push_back(wartość): rozszerza vector o 1 i dodaje na jego koniec podany element
		x*=2;
	}
	
	cout<<"Zawartosc vectora (1): ";
	for(int i=0; i<V.size(); i++) //nazwa.size(): zwraca obecny rozmiar vectora
	{
		cout<<V[i]<<" ";
	}
	cout<<"\n\n";
	
	for(int i=0; i<5; i++)
	{
		V.pop_back(); //nazwa.pop_back(): usuwa ostatni element vectora
	}
	
	cout<<"Zawartosc vectora (2): ";
	for(int i=0; i<V.size(); i++)
	{
		cout<<V[i]<<" ";
	}
	cout<<"\n\n";
	
	return 0;
}
