//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/2/264.html
#include <cstdio>


int main()
{
	int n,a,b;
	while(scanf("%d",&n)==1)
	{
		int i;
		for(i=0;i*(i+1)/2<n;++i);
		if(i%2==0)
		{
			b=i*(i+1)/2-n+1;
			a=i-b+1;
		}
		else
		{
			a=i*(i+1)/2-n+1;
			b=i-a+1;
		}
		printf("TERM %d IS %d/%d\n",n,a,b);
	}
	return 0;
}