// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/1/102.html
// Description: Brute force solution
// Complexity: O(n^4)
#include <cstdio>
#define N 103
#define INF 0x1f1f1f1f

using namespace std;

inline int MAX(int a,int b){return (a>b)?a:b;}

int n;
// the given rectangle
int rect[N][N]={0}; 
// 2d array that stores the sums of the elemets from each column j
// from 1 to i where i is from 1 to n
int colums[N][N]={0}; 

int main()
{
	scanf("%d",&n);
	// Reading the numbers of the rectangle
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&rect[i][j]);
		}
	}
	// Calculating the sum from 1 to i where i is between 1 and n 
	// and storing these sums in a 2d array 'column'.
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			colums[i][j]=colums[i-1][j]+rect[i][j];
		}
	}

	//Calculating the maximum sum
	int maximum=-INF;
	for(int i=1;i<=n;++i)
	{
		for(int k=i;k<=n;++k)
		{
			int currentmax=colums[k][1]-colums[i-1][1];

			for(int j=1;j<=n;++j)
			{
				int current=0;
				for(int t=j;t>=1;--t)
				{
					int p=colums[k][t]-colums[i-1][t];
					current+=p;
					if(current>currentmax)
						currentmax=current;
				}
				
			}

			if(currentmax>maximum)
				maximum=currentmax;
		}
	}
	printf("%d\n",maximum);
	return 0;
}