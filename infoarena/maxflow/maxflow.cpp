#include <bits/stdc++.h>
#define N 1024

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
struct Edge{
	int v;
	int cap;
	int flow;
	int rev;
	Edge(){}
	Edge(int v,int cap,int flow,int rev):v(v),cap(cap),flow(flow),rev(rev){}
};
int n,m;
vector<Edge> g[N];
bool vis[N];

bool dfs(int v,int flow)
{
	if(v==n) return true;
	if(vis[v]) return false;
	vis[v]=true;
	for(int u=0;u<g[v].size();++u)
	{
		if(g[v][u].cap-g[v][u].flow>=flow && dfs(g[v][u].v,flow))
		{
			g[v][u].flow+=flow;
			g[g[v][u].v][g[v][u].rev].flow-=flow;
			return true;
		}
	}
	return false;
}

int a,b,d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("maxflow.in","r",stdin);
	freopen("maxflow.out","w",stdout);
	cin>>n>>m;
	int mf=0;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b>>d;
		Edge e1(b,d,0,g[b].size());
		Edge e2(a,0,0,g[a].size());
		g[a].push_back(e1);
		g[b].push_back(e2);
		mf=MAX(mf,d);
	}
	int flow=1;
	while(flow<=mf) flow<<=1;
	int ans=0;
	while(flow>0)
	{
		fill(vis,vis+n+1,false);
		if(dfs(1,flow))
			ans+=flow;
		else
			flow>>=1;
	}
	cout<<ans<<"\n";
	return 0;
}