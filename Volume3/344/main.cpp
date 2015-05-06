#include <cstdio>
#define N 5
#define M 10
#define MAX 101

int tab[MAX][N];
int n;
int units[M][N]={
	0,0,0,0,0,
	1,0,0,0,0,
	2,0,0,0,0,
	3,0,0,0,0,
	1,1,0,0,0,
	0,1,0,0,0,
	1,1,0,0,0,
	2,1,0,0,0,
	3,1,0,0,0,
	1,0,1,0,0
};
int decimals[M+1][N]={
	0,0,0,0,0,
	0,0,1,0,0,
	0,0,2,0,0,
	0,0,3,0,0,
	0,0,1,1,0,
	0,0,0,1,0,
	0,0,1,1,0,
	0,0,2,1,0,
	0,0,3,1,0,
	0,0,1,0,1,
	0,0,0,0,1
};


int main()
{
	for(int i=0;i<5;++i)
	{
		tab[0][i]=units[0][i];
	} 
	for(int i=1;i<MAX;++i)
	{
		for(int j=0;j<N;++j)
		{
			tab[i][j]=tab[i-1][j]+units[i%10][j]+decimals[i/10][j];
		}
	}
	while(scanf("%d",&n)==1 && n!=0)
	{
		printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,tab[n][0],
			tab[n][1],tab[n][2],tab[n][3],tab[n][4]);
	}
	return 0;
}