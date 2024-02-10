#include<bits/stdc++.h>
using namespace std;

int n, s[2001], depth[2001], wart[2001][2001], q, currid=1;
bool odpowiedz[2001];
vector<pair<int,char>> graf[2001], trie[2001];
set<string> ans;
string word;

int check_forward(int idx, char c) //(wierzcho³ek na drzewie trie, sprawdzany znak)
{
	for(int i=0; i<trie[idx].size(); i++)
	{
		if(trie[idx][i].second==c)
		return trie[idx][i].first;
	}
	
	return 0;
}

void create_trie(int v, int p, int idx) //(wierzcho³ek, poprzednik, wierzcho³ek na drzewie trie)
{
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i].first!=p)
	{
		int x=check_forward(idx, graf[v][i].second); //sprawdŸ, czy istnieje ju¿ odpowiednia krawêdŸ drzewa trie, aby unikn¹æ tworzenia duplikatów
		
		if(!x)
		{
			trie[idx].push_back({++currid,graf[v][i].second});
			create_trie(graf[v][i].first,v,currid);
		}
		else
		{
			create_trie(graf[v][i].first,v,x);
		}
	}
}

void initdfs(int v, int p, int d) //(wierzcho³ek, poprzednik, g³êbokoœæ)
{
	depth[v]=d;
	
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i].first!=p)
	initdfs(graf[v][i].first,v,d+1);
}

void addval(int v, int p, int idx, int st, int h) //(wierzcho³ek, poprzednik, wierzcho³ek na drzewie trie, wierzcho³ek startowy, najwy¿szy wierzcho³ek)
{
	if(depth[v]<depth[h])
	h=v;
	
	wart[idx][v]++;
	wart[idx][st]++;
	wart[idx][h]-=2;
	
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i].first!=p)
	{
		int x=check_forward(idx, graf[v][i].second);
		
		if(!x)
		continue;
		
		addval(graf[v][i].first,v,x,st,h);
	}
}

bool check_idx(int n, int v, int p) //(sprawdzany indeks drzewa trie, wierzcho³ek, poprzednik, obecna wartoœæ)
{
	for(int i=0; i<graf[v].size(); i++)
	if(graf[v][i].first!=p)
	{
		if(check_idx(n,graf[v][i].first,v)==false)
		return false;
		
		if(wart[n][graf[v][i].first]<=0)
		return false;
		
		wart[n][v]+=wart[n][graf[v][i].first];
	}
	
	return true;
}

void triedfs(int v, int p)
{
	if(odpowiedz[v])
	{
		ans.insert(word);
		reverse(word.begin(),word.end());
		ans.insert(word);
		reverse(word.begin(),word.end());
	}
	
	for(int i=0; i<trie[v].size(); i++)
	{
		word.push_back(trie[v][i].second);
		
		triedfs(trie[v][i].first, v);
		
		word.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n-1; i++) //wprowadzanie danych
	{
		int a, b; char c;
		cin>>a>>b>>c;
		
		graf[a].push_back({b,c});
		graf[b].push_back({a,c});
		
		s[a]++; s[b]++;
	}
	
	for(int i=1; i<=n; i++) //znajdujemy wierzcho³ek, bêd¹cy pocz¹tkiem drzewa trie (dowolny liœæ)
	if(s[i]==1)
	{
		q=i;
		break;
	}
	
	initdfs(1,1,1); //pocz¹tkowy dfs - przyporz¹dkowuje g³êbokoœæ wierzcho³kom drzewa
	
	create_trie(q,q,1); //utwórz drzewo trie
	
	for(int i=1; i<=n; i++) //dodajemy odpowiednie wartoœci do sum prefiksowych na drzewach (osobne drzewo dla ka¿dego kandydata na odpowiedŸ)
	addval(i,i,1,i,i);
	
	for(int i=1; i<=currid; i++) //sprawdzanie, czy odpowiedŸ do i-tego wierzcho³ka drzewa trie jest poprawna
	if(check_idx(i,1,1))
	odpowiedz[i]=true;
	
	triedfs(1,1); //dfs po drzewie trie
	
	cout<<ans.size()<<"\n"; //wypisanie odpowiedzi
	
	for(auto it=ans.begin(); it!=ans.end(); it++)
	cout<<*it<<"\n";
}
