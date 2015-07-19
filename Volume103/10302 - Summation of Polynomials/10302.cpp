// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/103/10302.html
#include <cstdio>

unsigned long long int n,res;

int main()
{
	while(scanf("%llu",&n)==1)
	{
		res=(n*n)*(n+1)/2*(n+1)/2;
		printf("%llu\n",res);
	}
	return 0;
}