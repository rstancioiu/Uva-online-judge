#include <bits/stdc++.h>
#define N 50100

using namespace std;
vector<int> g[N];
bool vis[N];
int n,m,a,b;

void DFSUtil(int i)
{
	vis[i]=true;
	for(int j=0;j<g[i].size();++j)
	{
		if(!vis[g[i][j]])
		{
			DFSUtil(g[i][j]);
		}
	}
}

int dfs()
{
	int cnt=0;
	fill(vis,vis+n+1,false);
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			cnt++;
			DFSUtil(i);
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c=1;
	while(cin>>n>>m && !(n==0 && m==0))
	{
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		cout<<"Case "<<c++<<": "<<dfs()<<"\n";
		for(int i=1;i<=n;++i)
			g[i].clear();
	}
	return 0;
}