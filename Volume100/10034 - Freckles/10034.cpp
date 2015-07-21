#include <bits/stdc++.h>
#define N 128

using namespace std;
int t,n;
vector<pair<double,double> > v;
vector<pair<double,pair<int,int> > > e;
int tab[N];

double Distance(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	int k=0;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			double a,b;
			cin>>a>>b;
			v.push_back(make_pair(a,b));
		}
		for(int i=0;i<n;++i)
		{
			for(int j=i+1;j<n;++j)
			{
				double d= Distance(v[i].first,v[i].second,v[j].first,v[j].second);
				e.push_back(make_pair(d,make_pair(i,j)));
			}
		}
		sort(e.begin(),e.end());
		for(int i=0;i<n;++i)
			tab[i]=i;
		double ans=0;
		for(int i=0;i<e.size();++i)
		{
			if(tab[e[i].second.first]!=tab[e[i].second.second])
			{
				int p=tab[e[i].second.second];
				ans+=e[i].first;
				for(int j=0;j<n;++j)
				{
					if(tab[j]==p)
						tab[j]=tab[e[i].second.first];
				}
			}
		}
		if(k++)
			printf("\n");
		printf("%.2f\n",ans);
		v.clear();
		e.clear();
	}

	return 0;
}