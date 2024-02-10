#include<iostream>
using namespace std;

int main()
{
	
	int n, wyn1=0, wyn2=0, wyn3=0, d, p, r, dmin=2000000000, pmin=2000000000, rmin=2000000000, dmin2=2000000000, pmin2=2000000000, rmin2=2000000000, idd=-1, idp=-1, idr=-1, idd2=-2, idp2=-2, idr2=-2, czyd=0, czyp=0, czyr=0;
	bool pld=false, plp=false, plr=false;
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		cin>>d>>p>>r;
		if(d>0)
		pld=true;
		if(p>0)
		plp=true;
		if(r>0)
		plr=true;
		if(d>=p&&d>=r)
		{
			czyd++;
			wyn3+=p+r;
			idd2=i;
			
			if(d-p<=pmin)
			{
				pmin2=pmin;
				pmin=d-p;
				idp=i;
			}
			else if(d-p<=pmin2)	
			pmin2=d-p;
			
			if(d-r<=rmin)
			{
				rmin2=rmin;
				rmin=d-r;
				idr=i;
			}	
			else if(d-r<=rmin2)	
			rmin2=d-r;
			
		}
		
		else if(p>=d&&p>=r)
		{
			czyp++;
			wyn3+=d+r;
			idp2=i;
			
			if(p-d<=dmin)
			{
				dmin2=dmin;
				dmin=p-d;
				idd=i;
			}
			else if(p-d<=dmin2)	
			dmin2=p-d;	
			
			if(p-r<=rmin)
			{
				rmin2=rmin;
				rmin=p-r;
				idr=i;
			}	
			else if(p-r<=rmin2)	
			rmin2=p-r;
			
		}
		
		else if(r>=p&&r>=d)
		{
			czyr++;
			wyn3+=p+d;
			idr2=i;
			
			if(r-p<=pmin)
			{
				pmin2=pmin;
				pmin=r-p;
				idp=i;
			}
			else if(r-p<=pmin2)	
			pmin2=r-p;	
			
			if(r-d<=dmin)
			{
				dmin2=dmin;
				dmin=r-d;
				idd=i;
			}
			else if(r-d<=dmin2)	
			dmin2=r-d;	
			
		}
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	
	if((idd==idp&&czyp==0&&plp==true&&czyd==0&&pld==true)||(idd==idr&&czyd==0&&pld==true&&czyr==0&&plr==true)||(idp==idr&&czyp==0&&plp==true&&czyr==0&&plr==true))
	{
		if((idd==idp&&czyp>0&&plp==true&&czyd>0&&pld==true))
		{
			if(dmin+pmin2<=dmin2+pmin)
			{
				wyn3+=(dmin+pmin2);
			}
			else
			{
				wyn3+=(dmin2+pmin);
			}
		}
		else if((idd==idr&&czyd==0&&pld==true&&czyr==0&&plr==true))
		{
			if(dmin+rmin2<=dmin2+rmin)
			{
				wyn3+=(dmin+rmin2);
			}
			else
			{
				wyn3+=(dmin2+rmin);
			}
		}
		else if((idp==idr&&czyp==0&&plp==true&&czyr==0&&plr==true))
		{
			if(pmin+rmin2<=pmin2+rmin)
			{
				wyn3+=(pmin+rmin2);
			}
			else
			{
				wyn3+=(pmin2+rmin);
			}
		}
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	else if(idd2==idp&&pld==true&&plp==true&&czyd==1&&czyp==0)
	{
		if(pmin+dmin<=pmin2)
		wyn3+=(pmin+dmin);
		else
		wyn3+=pmin2;
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	else if(idd==idp2&&pld==true&&plp==true&&czyd==0&&czyp==1)
	{
		if(dmin+pmin<=dmin2)
		wyn3+=(dmin+pmin);
		else
		wyn3+=dmin2;
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	else if(idd2==idr&&pld==true&&plr==true&&czyd==1&&czyr==0)
	{
		if(rmin+dmin<=rmin2)
		wyn3+=(rmin+dmin);
		else
		wyn3+=rmin2;
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	else if(idd==idr2&&pld==true&&plr==true&&czyd==0&&czyr==1)
	{
		if(rmin+dmin<=dmin2)
		wyn3+=(rmin+dmin);
		else
		wyn3+=dmin2;
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	else if(idp2==idr&&plp==true&&plr==true&&czyp==1&&czyr==0)
	{
		if(rmin+pmin<=rmin2)
		wyn3+=(rmin+pmin);
		else
		wyn3+=rmin2;
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	else if(idp==idr2&&plp==true&&plr==true&&czyp==0&&czyr==1)
	{
		if(rmin+pmin<=pmin2)
		wyn3+=(rmin+pmin);
		else
		wyn3+=pmin2;
		
		if(wyn3>=100000000)
		{
			wyn2+=(wyn3/100000000);
			wyn3%=100000000;
		}
		if(wyn2>=100000000)
		{
			wyn1+=(wyn3/100000000);
			wyn2%=100000000;
		}
	}
	else
	{
		if(czyd==0&&pld==true)
		{
			wyn3+=dmin;
			
			if(wyn3>=100000000)
			{
				wyn2+=(wyn3/100000000);
				wyn3%=100000000;
			}
			if(wyn2>=100000000)
			{
				wyn1+=(wyn3/100000000);
				wyn2%=100000000;
			}
		}
		
		
		if(czyp==0&&plp==true)
		{
			wyn3+=pmin;
		
			if(wyn3>=100000000)
			{
				wyn2+=(wyn3/100000000);
				wyn3%=100000000;
			}
			if(wyn2>=100000000)
			{
				wyn1+=(wyn3/100000000);
				wyn2%=100000000;
			}
		}
		
		
		if(czyr==0&&plr==true)
		{
			wyn3+=rmin;

			if(wyn3>=100000000)
			{
				wyn2+=(wyn3/100000000);
				wyn3%=100000000;
			}
			if(wyn2>=100000000)
			{
				wyn1+=(wyn3/100000000);
				wyn2%=100000000;
			}
		}	
	}
	
	
	
	
	
	//wypisywanie wyniku
	
	int x=wyn2, y=wyn3;
	
	if(wyn1>0&&wyn2>0)
	{
		cout<<wyn1;
		while(x<10000000)
		{
			cout<<"0";
			x*=10;
		}
	}	
	else if(wyn1>0)
	cout<<wyn1<<"00000000";
	if(wyn2>0&&wyn3>0)
	{
		cout<<wyn2;
		while(y<10000000)
		{
			cout<<"0";
			y*=10;
		}
	}
	else if(wyn2>0)
	cout<<wyn2<<"00000000";
	if(wyn3>0)
	cout<<wyn3;
	if(wyn1==0&&wyn2==0&&wyn3==0)
	cout<<"0";
	
	//cout<<endl<<idd<<" "<<idp<<" "<<idr;
	//cout<<endl<<idd2<<" "<<idp2<<" "<<idr2;
	//cout<<endl<<czyd<<" "<<czyp<<" "<<czyr;
	
		
}
