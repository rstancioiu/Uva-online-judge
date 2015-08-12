#include <bits/stdc++.h>

using namespace std;

struct PT{
	double x,y;
	PT (){}
	PT (double x,double y) : x(x), y(y) {}
	PT (const PT &p) : x(p.x), y(p.y) {}
};

double dist2(PT a,PT b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a;
	while(cin>>n>>a && n!=0)
	{
		int m=0;
		PT p1(0,0);
		PT p2(0,a);
		PT p3(a,0);
		PT p4(a,a);
		double s=a*a;
		for(int i=0;i<n;++i)
		{
			double x,y;
			cin>>x>>y;
			PT p(x,y);
			if(dist2(p,p1)<=s && dist2(p,p2)<=s &&
				dist2(p,p4)<=s && dist2(p,p3)<=s)
				m++;
		}
		printf("%.5f\n",s*m/n);
	}
	return 0;
}
