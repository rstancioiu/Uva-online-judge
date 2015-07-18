// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/104/10469.html
#include <cstdio>

using namespace std;


int main()
{
	long long int a,b;
	while(scanf("%lld %lld",&a,&b)==2)
	{
		long long int res=0;
		for(int i=0;(1<<i)<=a || (1<<i)<=b;++i)
		{
			if(!((1<<i)&a) && ((1<<i)&b))
			{
				res+=(1<<i);
			}
			if(((1<<i)&a) && !((1<<i)&b))
			{
				res+=(1<<i);
			}
		}
		printf("%lld\n",res);

	}
	return 0;
}