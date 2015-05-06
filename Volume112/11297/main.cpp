#include <cstdio>
#define N 503
#define INF 0x1f1f1f1f

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a>b)?a:b;}
int c[N][N];
int minimum[N][N][N]={INF};
int maximum[N][N][N]={0};
int n,m,q;

void Read()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&c[i][j]);
		}
	}
	scanf("%d",&q);
}

void Compute()
{
	int x,y,v,x1,x2,y1,y2;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			minimum[i][i][j]=c[i][j];
			maximum[i][i][j]=c[i][j];
			for(int k=i+1;k<=n;++k)
			{

				minimum[i][k][j]=MIN(minimum[i][k-1][j],c[k][j]);
				maximum[i][k][j]=MAX(maximum[i][k-1][j],c[k][j]);
			}
		}
	}
	char type;
	for(int k=0;k<q;++k)
	{
		scanf(" %c",&type);
		if(type=='c')
		{
			scanf("%d%d%d",&x,&y,&v);
			c[x][y]=v;
			minimum[x][x][y]=c[x][y];
			maximum[x][x][y]=c[x][y];
			for(int i=1;i<=x;++i)
			{
				for(int k=x;k<=n && k>i;++k)
				{
					minimum[i][k][y]=MIN(minimum[i][k-1][y],c[k][y]);
					maximum[i][k][y]=MAX(maximum[i][k-1][y],c[k][y]);
				}
			}
			for(int k=x+1;k<=n;++k)
			{
				minimum[x][k][y]=MIN(minimum[x][k-1][y],c[k][y]);
				maximum[x][k][y]=MAX(maximum[x][k-1][y],c[k][y]);
			}

		}
		else if(type=='q')
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			int maxnb=0;
			int minnb=INF;
			for(int i=y1;i<=y2;++i)
			{
				maxnb=MAX(maxnb,maximum[x1][x2][i]);
				minnb=MIN(minnb,minimum[x1][x2][i]);
			}
			printf("%d %d\n",maxnb,minnb);
		}
	}
}

int main()
{
	Read();
	Compute();
	return 0;
}