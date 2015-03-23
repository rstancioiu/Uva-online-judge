#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	//freopen("test.txt","r",stdin);
	double a,b;
	while(scanf("%lf %lf",&a,&b)==2)
	{
		printf("%.0lf\n",pow(b,1/a));
	}
}