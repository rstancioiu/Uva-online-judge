// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/117/11727.html
#include <cstdio>


int main()
{
	int n,a,b,c;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d %d",&a,&b,&c);
		if((a<=b && b<=c)||(b<=a && c<=b))
			printf("Case %d: %d\n",i,b);
		else if((b<=a && a<=c)||(a>=c && b>=a))
			printf("Case %d: %d\n",i,a);
		else 
			printf("Case %d: %d\n",i,c);
	}
	return 0;
}