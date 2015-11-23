#include <bits/stdc++.h>
#define N 15024
#define ll long long int

using namespace std;
inline ll MAX(ll a,ll b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
int t,n,m,a,b;
vector<int> g[N];
int val[N];
ll sum[N];
int vis[N];

void DFSUtil(int i)
{
	vis[i]=1;
	for(unsigned int j=0;j<g[i].size();++j)
	{
		if(!vis[g[i][j]])
		{
			DFSUtil(g[i][j]);
		}
		sum[i]=MAX(sum[i],val[i]+sum[g[i][j]]);
	}
}

void DFS()
{
	for(int i=1;i<=n;++i)
	{
		sum[i]=val[i];
		vis[i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			DFSUtil(i);
		}
	}
}


int main()
{
	freopen("easygraph.in","r",stdin);
	freopen("easygraph.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			cin>>val[i];
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			g[a].push_back(b);
		}
		DFS();
		ll ans=sum[1];
		for(int i=1;i<=n;++i)
			ans=MAX(ans,sum[i]);
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)
			g[i].clear();
	}
	return 0;
}