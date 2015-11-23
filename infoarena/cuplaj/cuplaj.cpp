#include <bits/stdc++.h>
#define N 10100

using namespace std;
vector<int> g[N];
int r[N];
int l[N];
bool vis[N];
int n,m,e,a,b;

bool dfs(int v)
{
	if(vis[v]) return false;
	vis[v]=true;
	for(int u=0;u<g[v].size();++u)
	{
		if(!r[g[v][u]])
		{
			l[v]=g[v][u];
			r[g[v][u]]=v;
			return true;
		}
	}
	for(int u=0;u<g[v].size();++u)
	{
		if(dfs(r[g[v][u]]))
		{
			l[v]=g[v][u];
			r[g[v][u]]=v;
			return true;
		}
	}
	return false;
}

int main()
{
	freopen("cuplaj.in","r",stdin);
	freopen("cuplaj.out","w",stdout);
	scanf("%d%d%d",&n,&m,&e);
	for(int i=0;i<e;++i)
	{
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
	}	
	for(int i=1;i<=n;++i)
		l[i]=0;
	for(int i=1;i<=m;++i)
		r[i]=0;
	bool change=true;
	while(change)
	{
		change=false;
		fill(vis,vis+n+1,false);
		for(int i=1;i<=n;++i)
			if(!l[i])
				change |=dfs(i);
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(l[i])
			cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i)
	{
		if(l[i])
			printf("%d %d\n",i,l[i]);
	}
	return 0;
}