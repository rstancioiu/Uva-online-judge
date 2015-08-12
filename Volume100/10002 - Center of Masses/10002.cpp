#include <bits/stdc++.h>
#define N 128

using namespace std;

struct PT{
	double x,y;
	PT(){}
	PT(double x,double y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y)   {}
	PT operator + (const PT &p) const {return PT(x+p.x,y+p.y);}
	PT operator - (const PT &p) const {return PT(x-p.x,y-p.y);}
	PT operator * (double c)    const {return PT(x*c,y*c);}
	PT operator / (double c)    const {return PT(x/c,y/c);}
};

double dot(PT p,PT q) {return p.x*q.x + p.y*q.y;}
double dist2(PT p,PT q){return dot(p-q,p-q);}
double cross(PT o,PT a,PT b){return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);}
PT center;

vector<PT> p;
int m;

bool Compare(PT a,PT b)
{
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}


vector<PT> ConvexHull(vector<PT> p)
{
	int n=p.size();
	int k=0;
	vector<PT> H(2*n);

	sort(p.begin(),p.end(),Compare);

	//Build lower hull
	for(int i=0;i<n;++i)
	{
		while(k>=2 && cross(H[k-2],H[k-1],p[i])<=0) k--;
		H[k++]=p[i];
	}

	//Build upper hull
	for(int i=n-2, t=k+1;i>=0;--i)
	{
		while(k>=t && cross(H[k-2],H[k-1],p[i])<=0) k--;
		H[k++]=p[i];
	}
	H.resize(k);
	return H;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double x,y;
	while(cin>>m && m>2)
	{
		for(int i=0;i<m;++i)
		{
			cin>>x>>y;
			p.push_back(PT(x,y));
		}
        p=ConvexHull(p);
        double A=0;
		PT c(0,0);
		for(int i=0;i<m;++i)
		{
			int j=(i+1)%m;
			c=c+(p[i]+p[j])*(p[i].x*p[j].y-p[j].x*p[i].y);
			A+=(p[i].x*p[j].y-p[j].x*p[i].y);
		}
		A*=3;
		c=c/A;
		printf("%.3f %.3f\n",c.x,c.y);
		p.clear();
	}
	return 0;
}
