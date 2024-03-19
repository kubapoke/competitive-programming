#include<iostream>
#include<vector>
#include<utility>
#include<set>

using namespace std;

//testy do sprawdzania konkretnych rzeczy

//15 10
//85746634568734
//14261365412266

//9 10
//26473645
//11321138

//9 10
//26473665
//11321138

//16 20
//374859384735747
//129040204704112

int main()
{
	//ios_base::sync_with_stdio(NULL);
	//cin.tie(0);
	//cout.tie(0);
	
	int n, z, pocz=-1, kon=-1, w=0, p, x, y, m, l;
	set <int> nine;
	set<int>::iterator it;
	vector <int> wyniki;
	string a, b;
	char c;
	bool lewa=false, prawa=false;
	
	cin>>n>>z>>a>>b; //d³ugoœæ, zapytania, liczba pierwsza, liczba druga
	
	int l1[n];
	int l2[n];	
	
	l1[0]=0; l2[0]=0;
	
	for(int i=1; i<n; i++)
	{
		l1[i]=a[i-1]-48;
		l2[i]=b[i-1]-48;
	}
	
	for(int i=1; i<n; i++)
	{
		if(l1[i]+l2[i]==9&&l1[i-1]+l2[i-1]!=9)
		nine.insert(i);
		else if(l1[i]+l2[i]==9&&i==n-1)
		nine.insert(i);
		else if(l1[i]+l2[i]==9&&l1[i+1]+l2[i+1]!=9)
		nine.insert(i);
	}
	
	/*
	int lol=-1;
	for(int i=0; i<nine.size();i++)
	{
		it=nine.lower_bound(lol+1);
		cout<<*it<<"  ";
		lol=*it;	
	}
	cout<<endl;	
	*/
	
	for(int i=0; i<z; i++)
	{
		cin>>c;
		if(c=='S')//ZAPYTANIE
		{
			cin>>p;
			w+=(l1[n-p]+l2[n-p]);
			
			if(p==1)
			{
				w%=10;
				wyniki.push_back(w);
				//cout<<w<<endl;
				w=0;
				continue;
			}
			
			if(l1[n-p+1]+l2[n-p+1]>9)
			w++;///
			else if(l1[n-p+1]+l2[n-p+1]==9)
			{
				if(p==2)
				{
					w%=10;
					wyniki.push_back(w);
					//cout<<w<<endl;
					w=0;
					continue;
				}
				else if(l1[n-p+2]+l2[n-p+2]>9)
				w++;
				else if(l1[n-p+2]+l2[n-p+2]==9)
				{
					it=nine.lower_bound(n-p+2);
					if(*it!=n-1)
					if(l1[*it+1]+l2[*it+1]>9)
					w++;
				}
			}
			
			w%=10;
			//cout<<w<<endl;
			wyniki.push_back(w);
			w=0;
		}//KONIEC ZAPYTANIA
		
		
		else if(c=='W')
		{
			cin>>p>>l;
			
			lewa=false; prawa=false;
			
			if(l==l1[n-p])
			{
				continue;
			}
			if(l1[n-p]+l2[n-p]!=9&&l+l2[n-p]!=9)
			{
				l1[n-p]=l;
				continue;
			}
			
			if(l1[n-p-1]+l2[n-p-1]==9)
			lewa=true;
			
			if(p!=1)
			if(l1[n-p+1]+l2[n-p+1]==9)
			prawa=true;
			
			//cout<<lewa<<"   "<<prawa<<endl;
			
			if(l+l2[n-p]==9)
			{
				if(nine.size()==0)
				{
					l1[n-p]=l;
					nine.insert(n-p);	
				}
				else if(lewa==false&&prawa==false)
				{
					l1[n-p]=l;
					nine.insert(n-p);
				}
				else if(lewa==true&&prawa==false)
				{
					l1[n-p]=l;
					if(l1[n-p-2]+l2[n-p-2]==9)
					nine.erase(n-p-1);
					nine.insert(n-p);
				}
				else if(prawa==true&&lewa==false)
				{
					l1[n-p]=l;
					if(p!=2)
					if(l1[n-p+2]+l2[n-p+2]==9)
					nine.erase(n-p+1);
					nine.insert(n-p);
				}
				else if(lewa==true&&prawa==true)
				{
					l1[n-p]=l;
					if(l1[n-p-2]+l2[n-p-2]==9)
					nine.erase(n-p-1);
					if(p!=2)
					if(l1[n-p+2]+l2[n-p+2]==9)
					nine.erase(n-p+1);
				}
			}
			else
			{
				if(lewa==false&&prawa==false)
				{
					l1[n-p]=l;
					nine.erase(n-p);
				}
				else if(lewa==true&&prawa==false)
				{
					l1[n-p]=l;
					nine.erase(n-p);
					if(l1[n-p-2]+l2[n-p-2]==9)
					nine.insert(n-p-1);
				}
				else if(prawa==true&&lewa==false)
				{
					l1[n-p]=l;
					nine.erase(n-p);
					if(p!=2)
					if(l1[n-p+2]+l2[n-p+2]==9)
					nine.insert(n-p+1);
				}
				else if(lewa==true&&prawa==true)
				{
					l1[n-p]=l;
					if(l1[n-p-2]+l2[n-p-2]==9)
					nine.insert(n-p-1);
					if(p!=2)
					if(l1[n-p+2]+l2[n-p+2]==9)
					nine.insert(n-p+1);
				}
			}
			/*
			int lol=-1;
			for(int i=0; i<nine.size();i++)
			{
				it=nine.lower_bound(lol+1);
				cout<<*it<<"  ";
				lol=*it;	
			}
			cout<<endl;
			*/		 
		}
		else if(c=='Z')
		{
			cin>>p>>l;
			
			lewa=false; prawa=false;
			
			if(l==l2[n-p])
			{
				continue;
			}
			if(l2[n-p]+l1[n-p]!=9&&l+l1[n-p]!=9)
			{
				l2[n-p]=l;
				continue;
			}
			
			if(l2[n-p-1]+l1[n-p-1]==9)
			lewa=true;
			
			if(p!=1)
			if(l2[n-p+1]+l1[n-p+1]==9)
			prawa=true;
			
			//cout<<lewa<<"   "<<prawa<<endl;
			
			if(l+l1[n-p]==9)
			{
				if(nine.size()==0)
				{
					l2[n-p]=l;
					nine.insert(n-p);	
				}
				else if(lewa==false&&prawa==false)
				{
					l2[n-p]=l;
					nine.insert(n-p);
				}
				else if(lewa==true&&prawa==false)
				{
					l2[n-p]=l;
					if(l2[n-p-2]+l1[n-p-2]==9)
					nine.erase(n-p-1);
					nine.insert(n-p);
				}
				else if(prawa==true&&lewa==false)
				{
					l2[n-p]=l;
					if(p!=2)
					if(l2[n-p+2]+l1[n-p+2]==9)
					nine.erase(n-p+1);
					nine.insert(n-p);
				}
				else if(lewa==true&&prawa==true)
				{
					l2[n-p]=l;
					if(l2[n-p-2]+l1[n-p-2]==9)
					nine.erase(n-p-1);
					if(p!=2)
					if(l2[n-p+2]+l1[n-p+2]==9)
					nine.erase(n-p+1);
				}
			}
			else
			{
				if(lewa==false&&prawa==false)
				{
					l2[n-p]=l;
					nine.erase(n-p);
				}
				else if(lewa==true&&prawa==false)
				{
					l2[n-p]=l;
					nine.erase(n-p);
					if(l2[n-p-2]+l1[n-p-2]==9)
					nine.insert(n-p-1);
				}
				else if(prawa==true&&lewa==false)
				{
					l2[n-p]=l;
					nine.erase(n-p);
					if(p!=2)
					if(l2[n-p+2]+l1[n-p+2]==9)
					nine.insert(n-p+1);
				}
				else if(lewa==true&&prawa==true)
				{
					l2[n-p]=l;
					if(l2[n-p-2]+l1[n-p-2]==9)
					nine.insert(n-p-1);
					if(p!=2)
					if(l2[n-p+2]+l1[n-p+2]==9)
					nine.insert(n-p+1);
				}
			}
			/*
			int lol=-1;
			for(int i=0; i<nine.size();i++)
			{
				it=nine.lower_bound(lol+1);
				cout<<*it<<"  ";
				lol=*it;	
			}
			cout<<endl;
			*/		 
		}
		
	}
	
	for(int i=0; i<wyniki.size(); i++)
	cout<<wyniki[i]<<endl;
	
	
}
