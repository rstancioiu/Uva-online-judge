#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>

#define X first
#define Y second
#define pb push_back
#define ii pair<int,int>
#define ll long long
#define N 128

inline int MIN(int a,int b){return (a>b)?b:a;}
inline int MAX(int a,int b){return (a<b)?b:a;}
inline int ABS(int a){return (a>0)?a:-a;}

using namespace std;
int tt,n;
int mat[N][N];
int row[N][N];
int col[N][N];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>tt;
	for(int t=0;t<tt;++t)
	{
		cin>>n;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				cin>>mat[i][j];
		for(int i=1;i<=n;++i)
			row[i][0]=col[0][i]=0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				row[i][j]=row[i][j-1]+mat[i][j];
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				col[i][j]=col[i-1][j]+mat[i][j];
		int ans=-0x7fffffff;
		int total = 0;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				total+=mat[i][j];
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				int sum3=0;
				for(int k=j;k<=n;++k)
				{
					sum3+=col[n][k]-col[0][k];
					int sum1=0;
					int sum2=0;
					for(int l=i;l<=n;++l)
					{
						sum1+=row[l][k]-row[l][j-1];
						sum2+=row[l][n]-row[l][0];
						ans = MAX(sum1,ans);
						if(n!=k || j!=1)
						{
							ans = MAX(sum2-sum1,ans);
						}
						if(n!=l || i!=1)
						{
							ans = MAX(sum3-sum1,ans);
						}
						if((n!=k || j!=1) && (n!=l || i!=1))
						{
							ans=MAX(total-sum3-sum2+sum1,ans);
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}