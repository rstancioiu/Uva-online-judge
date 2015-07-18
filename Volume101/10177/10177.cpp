// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10177.html
#include <cstdio>

using namespace std;
typedef unsigned long long int ulli;
ulli n,sum,p,total;


int main()
{
	while(scanf("%llu",&n)==1)
	{
		sum=n*(n+1)*(2*n+1)/6;
		p=n*(n+1)/2;
		total=p*p;
		printf("%llu %llu",sum,total-sum);
		sum=p*p;
		total*=p;
		printf(" %llu %llu",sum,total-sum);
		sum=0;
		for(int i=1;i<=n;++i)
		{
			sum+=i*i*i*i;
		}
		total*=p;
		printf(" %llu %llu\n",sum,total-sum);
	}
	return 0;
}