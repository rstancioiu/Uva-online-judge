#include <bits/stdc++.h>
#define N 10100

using namespace std;
vector<int> g[N];
int r[N];
bool vis[N];
int n,m,a,b;

bool dfs(int v)
{
	if(vis[v]) return false;
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
	while(cin>>n>>m)
	{
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			g[a].push_back(b);
		}
		for(int i=0;i<n;++i)
			r[i]=-1;
		int ans=0;
		for(int i=0;i<n;++i)
		{
			fill(vis,vis+n,false);
			if(dfs(i))
				ans++;
		}
		if(ans==n)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		for(int i=0;i<n;++i)
			g[i].clear();
	}
	return 0;
}