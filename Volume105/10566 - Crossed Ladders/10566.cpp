#include <bits/stdc++.h>
#define EPS 1e-4

using namespace std;
inline double ABS(double a){return (a>0)?a:-a;}
inline double MIN(double a,double b){return (a>b)?b:a;}
double x,y,c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>x>>y>>c)
	{
		double t;
		double wmin=0;
		double wmax=MIN(x,y);
		while(ABS(wmax-wmin)>EPS)
		{
			t=(wmax-wmin)/2 + wmin;
			double sol=c*(1/sqrt(x*x-t*t)+1/sqrt(y*y-t*t));
			if(sol>1)
			{
				wmax=t;
			}
			else if(sol<1)
			{
				wmin=t;
			}
			else
				break;
		}
		cout<<fixed<<setprecision(3)<<t<<endl;
	}
	return 0;
}
