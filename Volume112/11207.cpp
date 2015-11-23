#include <bits/stdc++.h>

using namespace std;
inline double MIN(double a,double b){return (a>b)?b:a;}
inline double MAX(double a,double b){return (a<b)?b:a;}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n && n!=0)
	{
		double a,b;
		int pos=0;
		double maximum=0;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			double d1=MIN(a/4,b);
			double d2=MIN(a,b/4);
			double d3=MIN(a/2,b/2);
			double d=MAX(d1,d2);
			d=MAX(d,d3);
			if(d>maximum)
			{
				maximum=d;
				pos=i;
			}
		}
		cout<<pos+1<<"\n";
	}

	return 0;
}