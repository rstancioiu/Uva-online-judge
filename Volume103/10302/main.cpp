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