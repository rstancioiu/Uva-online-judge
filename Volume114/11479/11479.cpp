// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/114/11479.html
#include <cstdio>

unsigned long long int a,b,c;
int t;

int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%llu%llu%llu",&a,&b,&c);
		if(a+b>c && b+c>a && c+a>b)
		{
			if(a==b && b==c)
			{
				printf("Case %d: Equilateral\n",i);
			}
			else if(a==b || b==c || c==a)
			{
				printf("Case %d: Isosceles\n",i);
			}
			else printf("Case %d: Scalene\n", i);
		}
		else
		{
			printf("Case %d: Invalid\n",i);
		}
	}
	return 0;
}