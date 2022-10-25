#include<bits/stdc++.h>
using namespace std;

priority_queue<int> PQ1; //priority_queue<typ zmiennej> nazwa: deklaracja kolejki prioretytowej (domyœlnie zwraca najpierw najwiêkszy element)
priority_queue<int, vector<int>, greater<int>> PQ2; //kolejka prioretytowa zwracaj¹ca najpierw najmniejsze elementy, mo¿na do niej wstawiæ te¿ w³asne komparatory, co wkrótce omówimy

int main()
{
	srand(time(NULL)); //komenda konieczna do tworzenia losowych liczb
	
	cout<<"Nieposorotwane elementy zbioru: ";
	for(int i=0; i<10; i++)
	{
		int x=rand()%100+1; //losowa liczba z przedzia³u [1,100]
		cout<<x<<" ";
		
		PQ1.push(x); //nazwa.push(x): dodaje element o wartoœci x na odpowiednie miejsce kolejki
		PQ2.push(x);
	}
	cout<<"\n\n";
	
	cout<<"PQ1: ";
	while(!PQ1.empty()) //dopóki kolejka nie jest pusta
	{
		cout<<PQ1.top()<<" "; //zwraca element kolejki o najwy¿szym priorytecie
		PQ1.pop();
	}
	cout<<"\n\n";
	
	cout<<"PQ2: ";
	while(!PQ2.empty())
	{
		cout<<PQ2.top()<<" ";
		PQ2.pop();
	}
	cout<<"\n\n";
	
	return 0;
}
