// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/1/104.html
// Description: dynamic programming
#include <bits/stdc++.h>
#define eps 1.01
#define N 32

using namespace std;

double mat[N][N][N];
int pre[N][N][N];
int n;

void write(int i,int j,int t)
{
	if(t==1)
		return;
	int k=pre[i][j][t];
	if(mat[i][j][t]==mat[i][k][t-1]*mat[k][j][1])
	{
		write(i,k,t-1);
		cout<<k<<" ";
	}
	else if(mat[i][j][t]==mat[i][k][1]*mat[k][j][t-1])
	{
		cout<<k<<" ";
		write(k,j,t-1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n)
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(i==j)
					mat[i][j][1]=1;
				else
					cin>>mat[i][j][1];
			}
		}
		for(int t=1;t<=n;++t)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
					pre[i][j][t]=i;
		for(int t=2;t<=n;++t)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=n;++j)
				{
					mat[i][j][t]=0;
					for(int k=1;k<=n;++k)
					{
						if(mat[i][j][t]<=mat[i][k][t-1]*mat[k][j][1])
						{
							mat[i][j][t]=mat[i][k][t-1]*mat[k][j][1];
							pre[i][j][t]=k;
						}
						if(mat[i][j][t]<=mat[i][k][t-1]*mat[k][j][1])
						{
							mat[i][j][t]=mat[i][k][t-1]*mat[k][j][1];
							pre[i][j][t]=k;
						}
					}
				}
			}
		}
		bool found=false;
		for(int t=1;t<=n && !found;++t)
		{
			for(int i=1;i<=n && !found;++i)
			{
				if(mat[i][i][t]>=eps)
				{
					found =true;
					cout<<i<<" ";
					write(i,i,t);
					cout<<i<<"\n";
				}
			}
		}
		if(!found)
			cout<<"no arbitrage sequence exists.\n";	
	}
	return 0;
}