#include <cstdio>
#include <cmath>

using namespace std;
int n,T;
double r,t;
double PI=M_PI;

int main()
{
	double xsun=0,ysun=0;
	while(scanf("%d %d",&n,&T)==2)
	{
		double posx=0,posy=0;
		double angle=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf %lf",&r,&t);
			angle=2*T/t*PI;
			posx+=r*cos(angle);
			posy+=r*sin(angle);
			if(i==n-1)
				printf("%.4f\n",sqrt(posx*posx + posy*posy));
			else
				printf("%.4f ",sqrt(posx*posx + posy*posy));
		}
	}
	return 0;
}