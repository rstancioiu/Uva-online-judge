#include <cstdio>
#include <cmath>
#define PI 3.14159265359
#define EPS 1e-6

using namespace std;
double a,x,y,z;

int main()
{
	while(scanf("%lf",&a)==1)
	{
		double Aria=PI*a*a/12 - sin(PI/6)*a*a/2;
		double b = a*sqrt(2)/(sqrt(3)+1);
		x=b*b+4*Aria;
		y=4*(Aria+b*b*sin(PI/3)/2);
		z=4*(b*b*sin(PI/6)/2-2*Aria);
		printf("%.3f %.3f %.3f\n",x+EPS,y+EPS,z+EPS);
	}
	return 0;
}