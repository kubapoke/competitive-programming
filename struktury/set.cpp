#include<bits/stdc++.h>
using namespace std;

set<int> S; //set<typ zmiennej> nazwa: deklaracja seta // dane w secie automatycznie sortowane s¹ rosn¹co i usuwane s¹ wszelkie powtórzenia
multiset<int> MS; //dane w multisecie sortowane s¹ niemalej¹co
unordered_set<int> US; //dane w unordered secie sortowane s¹ w (pozornie) arbitralny sposób, jednak usuwane s¹ powtórzenia

set<int>::iterator s; //set<typ zmiennej>::iterator nazwa iteratora: deklaracja iteratora po secie
multiset<int>::iterator ms;
unordered_set<int>::iterator us;

int main()
{
	srand(time(NULL)); //komenda konieczna do tworzenia losowych liczb
	
	cout<<"Nieposorotwane elementy zbioru: ";
	for(int i=0; i<10; i++)
	{
		int x=rand()%100+1; //losowa liczba z przedzia³u [1,100]
		cout<<x<<" "<<x<<" ";
		
		for(int j=0; j<2; j++)
		{
			S.insert(x); //nazwa.insert(x): dodaje element o wartoœci x na odpowiedni¹ pozycjê w secie
			MS.insert(x);
			US.insert(x);
		}
	}
	cout<<"\n\n";
	
	cout<<"S: ";
	for(s=S.begin(); s!=S.end(); s++) //przejœcie wczeœniej zadeklarowanym iteratorem po secie
	{
		cout<<*s<<" "; //wypisujemy *s, nie s, gdy¿ 'cout<<s' zwraca³oby adres w pamiêci iteratora a nie jego wartoœæ
	}
	cout<<"\n\n";
	
	cout<<"MS: ";
	for(ms=MS.begin(); ms!=MS.end(); ms++)
	{
		cout<<*ms<<" ";
	}
	cout<<"\n\n";
	
	cout<<"US: ";
	for(us=US.begin(); us!=US.end(); us++)
	{
		cout<<*us<<" ";
	}
	cout<<"\n\n";
	
	return 0;
}
