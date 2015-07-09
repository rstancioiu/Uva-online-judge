// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/4/438.html
#include <cstdio>
#include <cmath>
#define EPS 1e-7

using namespace std;

double Distance(double x1,double y1, double x2, double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
	double x1,y1,x2,y2,x3,y3,a,b,c,R,S,p;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
	{
		a = Distance(x2,y2,x3,y3);
		b = Distance(x1,y1,x3,y3);
		c = Distance(x1,y1,x2,y2);
		p = (a+b+c)/2;
		S=sqrt(p*(p-a)*(p-b)*(p-c));
		R= a*b*c/(4*S);
		printf("%.2f\n",2*M_PI*R+EPS);
	}
	return 0;
}
