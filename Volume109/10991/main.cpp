#include <iostream>
#include <cmath>
#include <cstdio>
#define eps 1e-10

using namespace std;

double r1,r2,r3;
double a,b,c;
double angle1,angle2,angle3;

int main()
{
	int t;
	cin>>t;
	double area;
	for(int i=0;i<t;++i)
	{
		cin>>r1>>r2>>r3;
		a=r2+r3;
		b=r1+r3;
		c=r1+r2;
		double p = (a+b+c)/2;
		area = sqrt(p*(p-a)*(p-b)*(p-c));
		angle1 = acos((b*b+c*c-a*a)/(2*b*c));
		angle2 = acos((a*a+c*c-b*b)/(2*a*c));
		angle3 = acos((b*b+a*a-c*c)/(2*b*a));
		double area1=angle1*r1*r1/2;
		double area2=angle2*r2*r2/2;
		double area3=angle3*r3*r3/2;
		double res = area-area1-area2-area3;
		printf("%.6lf\n",res+eps); 
	}
	return 0;
}