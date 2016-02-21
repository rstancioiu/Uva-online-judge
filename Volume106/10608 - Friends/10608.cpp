#include <bits/stdc++.h>
#define N 30100

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
int t,n,m,a,b,ans;
vector<int> g[N];
int vis[N];

void read()
{
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
}

int DFSUtil(int i)
{
	vis[i]=1;
	int sum=1;
	for(int j=0;j<g[i].size();++j)
	{
		int p = g[i][j];
		if(!vis[p])
		{
			sum+=DFSUtil(p);
		}
	}
	return sum;
}


void compute()
{
	for(int i=1;i<=n;++i)
		vis[i]=0;
	ans=0;
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			int p = DFSUtil(i);
			ans = MAX(ans,p);
		}
	}
}

void write()
{
	cout<<ans<<endl;
}

void clean()
{
	for(int i=1;i<=n;++i)
		g[i].clear();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		read();
		compute();
		write();
		clean();
	}
	return 0;
}