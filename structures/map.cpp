#include<iostream>
#include<map>
using namespace std;

map<char,int> M; //map<typ zmiennej klucza, typ zmiennej wartości> nazwa: deklaracja mapy o kluczach i wartościach o określonych typach

int main()
{
	M[1]=4;  M[2]=5;  M[3]=6;  M['1']=1;  M['2']=2;  M['3']=3;
	
	cout<<"Zawartosc komorek o wartosciach (liczbowych) od 0 do 3: ";
	for(int i=0; i<=3; i++)
	{
		cout<<M[i]<<" ";
	}
	cout<<"\n\nZauwazmy, ze wartosc dla zera istnieje i domyslnie jest rowna 0\n\n";
	
	cout<<"Zawartosc komorek o wartosciach (znakowych) od 0 do 3: ";
	for(char i='0'; i<='3'; i++)
	{
		cout<<M[i]<<" ";
	}
	cout<<"\n\n";
	
	M['a']=7; M['b']=8; M['c']=9;
	
	cout<<"Zawartosc komorek o wartosciach (znakowych) od a do c: ";
	for(char i='a'; i<='c'; i++)
	{
		cout<<M[i]<<" ";
	}
	cout<<"\n\n";
}
