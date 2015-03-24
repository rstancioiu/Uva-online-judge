#include <cmath>
#include <cstdio>
#define EPS 1e-6

using namespace std;
double L,W,minimum,maximum;


int main()
{
	while(scanf("%lf %lf",&L,&W)==2)
	{
		maximum = (L+W-sqrt(L*L+W*W-L*W))/6.0;
		minimum = (W<L)?W/2.0:L/2.0;
		printf("%.3f 0.000 %.3f\n",maximum+EPS,minimum+EPS);

	}
	return 0;
}