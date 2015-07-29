#include <bits/stdc++.h>
#define EPS 1e-7

using namespace std;

inline double ABS(double a){return (a>0)?a:-a;}

double ma,mb,mc;
double sa,sb,sc;
double a,b,c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(3);
	while(cin>>ma>>mb>>mc)
	{
		double s=(ma*ma+mb*mb+mc*mc)*4/3;
		sa=(-4*ma*ma+2*s)/3;
		sb=(-4*mb*mb+2*s)/3;
		sc=(-4*mc*mc+2*s)/3;
		if(sa<=0 || sb<=0 || sc<=0)
		{
			cout<<-1.000<<endl;
			continue;
		}
		a=sqrt(sa);
		b=sqrt(sb);
		c=sqrt(sc);
		if(a+b<=c+EPS || b+c<=a+EPS || c+a<=b+EPS)
		{
			cout<<-1.000<<endl;
			continue;
		}
		double p=(a+b+c)/2;
		cout<<sqrt(p*(p-a)*(p-b)*(p-c))+EPS<<endl;
	}
	return 0;
}
