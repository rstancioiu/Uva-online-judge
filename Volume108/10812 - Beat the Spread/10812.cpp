// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/108/10812.html
#include <cstdio>



int main()
{
	long long int a,b;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		if(a<b)
			printf("impossible\n");
		else
		{
			long long int res1=(a+b)/2;
			long long int res2=(a-b)/2;
			if(res1+res2==a && res1-res2==b)
				printf("%lld %lld\n",res1,res2);
			else
				printf("impossible\n");
		}

	}
	return 0;
}