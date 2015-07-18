// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10014.html
#include <cstdio>

using namespace std;
int n;
double a0,an,c,a1,sum,sumc;

int main()
{
	int t;
	scanf("%d",&t);
	int nb=0;
	while(t--)
	{
		if(nb++)
			printf("\n");
		scanf("%d",&n);
		scanf("%lf",&a0);
		scanf("%lf",&an);
		sum=0;
		sumc=0;
		for(int i=0;i<n;++i)
		{
			scanf("%lf",&c);
			sumc+=c;
			sum+=sumc;
		}
		a1=(n*a0+an-2*sum)/(n+1);
		printf("%.2f\n",a1);
	}
	return 0;
}