#include <bits/stdc++.h>
#define M 128
#define N 16

using namespace std;
inline long long MIN(long long a,long long b){return (a>b)?b:a;}
int n,m;
long long mat[N][M];
long long sum[N][M];
vector<int> best[N][M];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>m)
	{
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				cin>>mat[i][j];
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				sum[i][j]=(1L<<40);
				best[i][j].clear();
			}
		}
		for(int i=0;i<n;++i)
		{
			sum[i][0]=mat[i][0];
			best[i][0].push_back(i);
		}
		for(int j=0;j<m-1;++j)
		{
			for(int i=0;i<n;++i)
			{
				for(int d=-1;d<=1;++d)
				{
					int a=(i+d+n)%n;
					if(sum[i][j]+mat[a][j+1]<=sum[a][j+1])
					{
						if(sum[i][j]+mat[a][j+1]==sum[a][j+1])
						{
							for(int k=0;k<best[i][j].size();++k)
							{
								if(best[a][j+1][k]>best[i][j][k])
								{
									best[a][j+1]=best[i][j];
									best[a][j+1].push_back(a);
									break;
								}
								else if(best[a][j+1][k]<best[i][j][k])
									break;
							}
						}
						else 
						{
							best[a][j+1]=best[i][j];
							best[a][j+1].push_back(a);
						}
						sum[a][j+1]=sum[i][j]+mat[a][j+1];
					}
				}
			}
		}
		long long minimum=(1l<<45);
		vector<int> ans;
		for(int i=0;i<n;++i)
		{
			if(minimum>=sum[i][m-1])
			{	
				if(minimum==sum[i][m-1])
				{
					if(ans.size()==0)
						ans=best[i][m-1];
					for(int k=0;k<ans.size();++k)
					{
						if(ans[k]>best[i][m-1][k])
						{
							ans=best[i][m-1];
							break;
						}
						else if(ans[k]<best[i][m-1][k])
							break;
					}
				}
				else
					ans=best[i][m-1];
				minimum=sum[i][m-1];
			}
		}
		for(int i=0;i<ans.size()-1;++i)
			cout<<ans[i]+1<<" ";
		if(ans.size()-1>=0)
			cout<<ans[ans.size()-1]+1;
		cout<<"\n"<<minimum<<"\n";
	}
	return 0;
}