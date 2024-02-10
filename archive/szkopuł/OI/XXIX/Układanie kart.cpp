//Jakub P¹czka
#include<bits/stdc++.h>
using namespace std;

long long n, m, a, b, c=1, x, y, z=1, w, mw, h, add1=1, add2=1, mn1, mn2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	h=n-1;
	
	x=y=n*h;
	mn1=mn2=h;
	
	for(int i=0; i<=2*n-3; i++)
	{
		//if(i==2)
		//c/=2;
		if(i<=1)
		{
			w=(w%m+(((a+b)*c)/2)%m)%m;
			
			if(i==0)
			{
				a+=add1;
				if(i<h-1)
				add1++;
				
				b+=h;
				
				c*=mn1;
				if(i<h-1)
				mn1--;
			}
			else
			{
				a=(a%m+add1%m)%m;
				if(i<h-1)
				add1++;
				
				b=(b%m+h%m)%m;
				
				if(c%2==0)
				{
					c=(((c/2)%m)*(mn1%m))%m;
					if(i<h-1)
					mn1--;
				}
				else
				{
					c=((c%m)*((mn1/2)%m))%m;
					if(i<h-1)
					mn1--;
				}
			}
		}
		else
		{
			w=(w%m+(((a+b)%m)*c%m)%m)%m;
			a=(a%m+add1%m)%m;
			if(i<h-1)
			add1++;
			
			b=(b%m+h%m)%m;
			
			c=((c%m)*(mn1%m))%m;
			if(i<h-1)
			mn1--;
		}
		
		if(i>=n)
		{
			//if(i==n+2)
			//z/=2;
			if(i<=n+1)
			{
				mw=(mw%m+(((x+y)*z)/2)%m)%m;
				
				if(i==n)
				{
					x+=add2;
					add2++;
					
					y+=h;
					
					z*=mn2;
					mn2--;
				}
				else
				{
					x=(x%m+add2%m)%m;
					add2++;
					
					y=(y%m+h%m)%m;
					
					if(z%2==0)
					{
						z=(((z/2)%m)*(mn2%m))%m;
						mn2--;
					}
					else
					{
						z=((z%m)*((mn2/2)%m))%m;
						mn2--;
					}
				}
			}
			else
			{
				mw=(mw%m+(((x+y)%m)*z%m)%m)%m;
			
				x=(x%m+add2%m)%m;
				add2++;
				
				y=(y%m+h%m)%m;
				
				z=((z%m)*(mn2%m))%m;
				mn2--;
			}
		}
	}
	
	cout<<(w%m-mw%m+m)%m;
}
