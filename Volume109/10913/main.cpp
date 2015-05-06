#include <cstdio>
#define N 100
#define K 10
#define INF 0x3FFFFFFF

using namespace std;
inline long int MAX(long int a,long int b){return (a>b)?a:b;}
long int grid[N][N]={-INF};
long int res[N][N][K]={-INF};
long int left[N][K]={-INF};
long int right[N][K]={-INF};
int n,k;

int main()
{
	int c=0;
	while(scanf("%d%d",&n,&k)==2 && !(n==0 && k==0))
	{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					scanf("%ld",&grid[i][j]);
				}
			}
			for(int i=0;i<=n;++i)
			{
				for(int j=0;j<=n+1;++j)
				{
					for(int t=0;t<=k;++t)
					{
						res[i][j][t]=-INF;
					}
				}
			}
			int t=0;
			if(grid[1][1]<0 && t+1<=k)
			{
				res[1][1][t+1]=grid[1][1];
				t++;
			}
			else if(grid[1][1]>=0)
			{
				res[1][1][t]=grid[1][1];
			}
			for(int j=2;j<=n;++j)
			{
				if(grid[1][j]<0 && t+1<=k)
				{
					res[1][j][t+1]=res[1][j-1][t];
					if(res[1][j][t+1]!=-INF)
					{
						res[1][j][t+1]+=grid[1][j];
					}
					t++;
				}
				else if(t<=k && grid[1][j]>=0)
				{
					res[1][j][t]=res[1][j-1][t];
					if(res[1][j][t]!=-INF)
						res[1][j][t]+=grid[1][j];
				} 
			}
			for(int i=2;i<=n;++i)
			{
				for(int j=0;j<=n+2;++j)
				{
					for(int t=0;t<=k;++t)
					{
						left[j][t]=-INF;
						right[j][t]=-INF;
					}
				}
				for(int j=1;j<=n;++j)
				{
					for(int t=0;t<=k;++t)
					{
						if(grid[i][j]<0 && t+1<=k)
						{
							right[j][t+1]=MAX(right[j-1][t],res[i-1][j][t]);
							if(right[j][t+1]!=-INF)
								right[j][t+1]+=grid[i][j];
						}
						else if(grid[i][j]>=0)
						{
							right[j][t]=MAX(right[j-1][t],res[i-1][j][t]);
							if(right[j][t]!=-INF)
								right[j][t]+=grid[i][j];
						}
					}
				}
				for(int j=n;j>=1;--j)
				{
					for(int t=0;t<=k;++t)
					{
						if(grid[i][j]<0 && t+1<=k)
						{
							left[j][t+1]=MAX(left[j+1][t],res[i-1][j][t]);
							if(left[j][t+1]!=-INF)
								left[j][t+1]+=grid[i][j];
						}
						else if(grid[i][j]>=0)
						{
							left[j][t]=MAX(left[j+1][t],res[i-1][j][t]);
							if(left[j][t]!=-INF)
								left[j][t]+=grid[i][j];
						}
					}
				}
				for(int j=1;j<=n;++j)
				{
					for(int t=0;t<=k;++t)
					{
						res[i][j][t]=MAX(right[j][t],left[j][t]);
					}
				}
			}
			long int minimum=-INF;
			for(int t=0;t<=k;++t)
			{
				minimum=MAX(minimum,res[n][n][t]);
			}
			if(minimum!=-INF && n>0 && k>=0)
				printf("Case %d: %ld\n",++c,minimum);
			else printf("Case %d: impossible\n",++c);
	}
	return 0;
}