// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10000.html
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#define N 101
#define INF 0x3f3f3f3f

using namespace std;
int distances[N][N]; 
int n,s,nb;



int main()
{
	nb=0;
	int a,b;
	while(scanf("%d",&n)==1)
	{
		if(nb++) printf("\n");;
		if(n==0)
		{
			break;
		}
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;j++)
				distances[i][j]=-INF;
		}
		for(int i=0;i<=n;++i)
			distances[i][i]=0;
		scanf("%d",&s);
		while(scanf("%d %d",&a,&b)==2)
		{
			if(a==0 && b==0)
				break;
			distances[a][b]=1;
		}
		for(int k=0;k<=n;++k)
		{
			for(int i=0;i<=n;++i)
			{
				for(int j=0;j<=n;++j)
				{
					if(distances[i][j]<distances[i][k]+distances[k][j])
						distances[i][j]=distances[i][k]+distances[k][j];
				}
			}
		}
		int max=-INF;
		int pos=n;
		for(int i=n;i>=0;i--)
		{
			if(distances[s][i]>=max)
			{
				max=distances[s][i];
				pos=i;
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",nb,s,max,pos);
	}
	return 0;
}