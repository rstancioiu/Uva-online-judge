// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/114/11498.html
#include <cstdio>


int main()
{
	int n,a,b,x,y;
	while(scanf("%d",&n)==1 && n!=0)
	{
		scanf("%d %d",&x,&y);
		for(int i=0;i<n;++i)
		{
			scanf("%d %d",&a,&b);
			if(a==x || b==y)
				printf("divisa\n");
			if(a>x && b>y)
				printf("NE\n");
			if(a<x && b>y)
				printf("NO\n");
			if(a>x && b<y)
				printf("SE\n");
			if(a<x && b<y)
				printf("SO\n");
		}
	}
	return 0;
}