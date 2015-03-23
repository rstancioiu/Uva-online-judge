#include <cstdio>

using namespace std;


int main()
{
	int n,k;
	while(scanf("%d %d",&n,&k)==2 && !(n==0 && k==0))
	{
		unsigned long long int res=1;
		k=(k>(n-k)?(n-k):k);
		for(int i=1;i<=k;++i)
		{
			res=res*(n-k+i)/i;
		}
		printf("%llu\n",res);
	}
	return 0;
}