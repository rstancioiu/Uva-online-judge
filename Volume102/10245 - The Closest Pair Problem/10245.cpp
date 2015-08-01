#include <bits/stdc++.h>
#define MAX 10000

using namespace std;
int n;
pair<double,double> tab[MAX+1]; 

double Distance(pair<double,double> p1,pair<double,double> p2)
{
	return ((p1.first-p2.first)*(p1.first-p2.first)+(p1.second-p2.second)*(p1.second-p2.second));
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n && n!=0)
	{
		for(int i=0;i<n;++i)
		{
			cin>>tab[i].first>>tab[i].second;
		}
		double minimum=MAX*MAX;
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				double d=Distance(tab[i],tab[j]);
				if(d<minimum)
					minimum=d;
			}
		}
		if(minimum==MAX*MAX)
		{
			cout<<"INFINITY"<<endl;
		}
		else cout<<fixed<<setprecision(4)<<sqrt(minimum)<<endl;
	}
	return 0;
}