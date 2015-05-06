#include <cstdio>

int n,i;

int main()
{
	int c=1;
	while(scanf("%d",&n)==1 && n>=0)
	{
		for(i=0;(1<<i)<n;++i);
		printf("Case %d: %d\n",c++,i);
	}

	return 0;
}