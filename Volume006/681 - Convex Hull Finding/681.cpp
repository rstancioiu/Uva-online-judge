#include <bits/stdc++.h>

using namespace std;

struct PT{
	double x,y;
	PT (){}
	PT (double x,double y): x(x),y(y) {}
	PT (const PT &p) : x(p.x),y(p.y) {}
	PT operator + (const PT &p) {return PT(x+p.x,y+p.y);}
	PT operator - (const PT &p) {return PT(x-p.x,y-p.y);}
	PT operator * (double c) {return PT(x*c,y*c);}
	PT operator / (double c) {return PT(x/c,y/c);}
};

bool compare(PT a,PT b){
	return a.y<b.y || (a.y==b.y && a.x<b.x);
}

double cross(PT o,PT a, PT b){return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);}

vector<PT> ConvexHull(vector<PT> p)
{
	int n=p.size();
	int k=0;

	vector<PT> h(2*n);

	sort(p.begin(),p.end(),compare);

	//build lower hull
	for(int i=0;i<n;++i)
	{
		while(k>=2 && cross(h[k-2],h[k-1],p[i])<=0) k--;
		h[k++]=p[i];
	}

	//build top hull
	for(int i=n-2,t=k+1;i>=0;--i)
	{
		while(k>=t && cross(h[k-2],h[k-1],p[i])<=0) k--;
		h[k++]=p[i];
	}
	h.resize(k);
	return h;
}

int t,n,delimiter;
double x,y;
vector<PT> p;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("test.txt","r",stdin);
	cin>>t;
	cout<<t<<endl;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>x>>y;
			p.push_back(PT(x,y));
		}
		p=ConvexHull(p);
		cout<<p.size()<<endl;
		for(int i=0;i<p.size();++i)
			cout<<p[i].x<<" "<<p[i].y<<endl;
		if(t)
		{
			cin>>delimiter;
			cout<<delimiter<<endl;
		}
		p.clear();
	}

	return 0;
}
