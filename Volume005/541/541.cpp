// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/5/541.html
#include <cstdio>
#define N 128

using namespace std;

int v[N][N];


int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			break;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				scanf("%d",&v[i][j]);
			}
		}
		int t1,t2;
		int row=0;
		int column=0;
		int sum=0;
		for(int i=0;i<n;++i)
		{
			sum=0;
			for(int j=0;j<n;++j)
			{
				sum+=v[i][j];
			}
			if(sum%2==1)
			{
				row++;
				t1=i;
			}
		}
		for(int i=0;i<n;++i)
		{
			sum=0;
			for(int j=0;j<n;++j)
			{
				sum+=v[j][i];
			}
			if(sum%2==1)
			{
				column++;
				t2=i;
			}
		}
		if(row==0 && column==0)
		{
			printf("OK\n");
		}
		else if(row==1 && column ==1)
		{
			printf("Change bit (%d,%d)\n",t1+1,t2+1);
		}
		else
		{
			printf("Corrupt\n");
		}
	}
	return 0;
}