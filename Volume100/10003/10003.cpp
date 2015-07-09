// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10003.html
#include <cstdio>
#define N 64

inline int MIN(int a,int b){return (a>b)?b:a;}

int l,n;
int cuts[N];
int sum;
int m[N][N];

int main()
{	
	while(scanf("%d",&l)==1 && l!=0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d",&cuts[i]);
		cuts[n+1]=l;
		cuts[0]=0;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;++j)
				m[i][j]=0;
		for(int i=0;i<=n+1;++i)
		{
			for(int j=i-2;j>=0;--j)
			{
				for(int k=j+1;k<i;++k)
				{
					if(m[j][i]!=0)
						m[j][i]=MIN(m[j][i],m[j][k]+m[k][i]);
					else
						m[j][i]=m[j][k]+m[k][i];
				}
				m[j][i]+=cuts[i]-cuts[j];
			}
		}
		printf("The minimum cutting is %d.\n",m[0][n+1]);
	}
	return 0;
}