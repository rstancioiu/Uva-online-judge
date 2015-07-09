// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10066.html
#include <cstdio>
#define N 128

inline int MAX(int a,int b){return (a>b)?a:b;}
int tab[N][N];
int n,m;
int tower1[N];
int tower2[N];

int main()
{
	int c=0;
	while(scanf("%d%d",&n,&m)==2 && !(n==0 && m==0))
	{		
		for(int i=0;i<n;++i)
			scanf("%d",&tower1[i]);
		for(int i=0;i<m;++i)
			scanf("%d",&tower2[i]);
		if(n!=0 && m!=0)
		{
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
					tab[i][j]=0;
			if(tower1[0]==tower2[0])
				tab[0][0]=1;
			else tab[0][0]=0;
			for(int j=1;j<m;++j)
				if(tower1[0]==tower2[j])
					tab[0][j]=1;
				else tab[0][j]=tab[0][j-1];
			for(int i=1;i<n;++i)
				if(tower1[i]==tower2[0])
					tab[i][0]=1;
				else tab[i][0]=tab[i-1][0];
			for(int i=1;i<n;++i)
				for(int j=1;j<m;++j)
				{
					if(tower1[i]==tower2[j])
						tab[i][j]=tab[i-1][j-1]+1;
					tab[i][j]=MAX(tab[i][j],tab[i-1][j]);
					tab[i][j]=MAX(tab[i][j],tab[i][j-1]);
				}
			printf("Twin Towers #%d\n",++c);
			printf("Number of Tiles : %d\n",tab[n-1][m-1]);
			printf("\n");
		}
		else
		{
			printf("Twin Towers #%d\n",++c);
			printf("Number of Tiles : 0\n");
			printf("\n");
		}
	}
	return 0;
} 