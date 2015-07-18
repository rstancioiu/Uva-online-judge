// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/5/591.html
#include <cstdio>
#define N 128

int v[N];

int main()
{
	int n;
	int nb=0;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			break;
		int sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&v[i]);
			sum+=v[i];
		}
		int avg=sum/n;
		int dif=0;
		for(int i=0;i<n;++i)
		{
			if(v[i]>avg)
				dif+=v[i]-avg;
		}
		nb++;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", nb, dif);
	}
	return 0;
}