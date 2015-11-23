#include <bits/stdc++.h>
#define N 100100
#define M 128

using namespace std;
int mat[M][M];
int row[M][M];
int col[M][M];
int r[N];
int t,n,m,a,b,p,w;
vector<int> g[N];
bool vis[N];


bool dfs(int v)
{
	if(vis[v]) 
		return false;
	vis[v]=true;
	for(int u=0;u<g[v].size();++u)
	{
		if(r[g[v][u]]==-1 || dfs(r[g[v][u]]))
		{
			r[g[v][u]]=v;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				mat[i][j]=0;
				row[i][j]=0;
				col[i][j]=0;
			}
		}
		cin>>p;
		for(int i=0;i<p;++i)
		{
			cin>>a>>b;
			mat[a][b]=1;
		}
		cin>>w;
		for(int i=0;i<w;++i)
		{
			cin>>a>>b;
			mat[a][b]=2;
		}
		int rows=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(mat[i][j]==2)
					rows++;
				else
					row[i][j]=rows;
			}
			rows++;
		}
		int cols=0;
		for(int j=1;j<=m;++j)
		{
			for(int i=1;i<=n;++i)
			{
				if(mat[i][j]==2)
					cols++;
				else
					col[i][j]=cols;
			}
			cols++;
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(mat[i][j]==1)
				{
					g[row[i][j]].push_back(col[i][j]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<cols;++i)
			r[i]=-1;
		for(int i=0;i<rows;++i)
		{
			fill(vis,vis+rows,false);
			if(dfs(i))
			{
				ans++;
			}
		}
		cout<<ans<<"\n";
		for(int i=0;i<rows;++i)
		{
			g[i].clear();
		}
	}
	return 0;
}