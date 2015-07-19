// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/125/12571.html
#include <cstdio>
#define N 256

int v[N];
int tab[N];
int a,t,x,q,n;

inline int MAX(int a,int b){return (a>b)?a:b;}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<N;++i)
		{
			v[i]=0;
			tab[i]=0;
		}
		scanf("%d %d",&n,&q);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&x);
			v[x&255]=1;
		}
		for(int i=0;i<230;++i)
		{
			if(!v[i])
			{
				for(int j=0;j<N;++j)
				{
					if(v[j])
						tab[i]=MAX(tab[i],i&j);
				}
			}
			else tab[i]=i;
		}
		while(q--)
		{
			scanf("%d",&a);
			printf("%d\n",tab[a]);
		}
	}
	return 0;
}