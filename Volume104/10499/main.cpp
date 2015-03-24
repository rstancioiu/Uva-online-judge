#include <cstdio>

using namespace std;

int main()
{
	long long int n;
	while(scanf("%lld",&n)==1 && n>=0)
	{
		if(n!=1)
		{
			printf("%lld%%\n",n*25);
		}
		else printf("0%%\n");
	}
	return 0;
}