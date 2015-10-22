#include <bits/stdc++.h>
#define N 100000

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
vector<int> g[N];
int pre[N];
int low[N];
int n,a,b,cnt,ans;
string s;

void dfs(int u,int v)
{
	pre[v]=cnt++;
	low[v]=pre[v];
	for(int i=0;i<g[v].size();++i)
	{
		if(pre[g[v][i]]==-1)
		{
			dfs(v,g[v][i]);
			low[v]=MIN(low[v],low[g[v][i]]);
			if(low[g[v][i]]=pre[g[v][i]])
				ans++;
		}
		else if(g[v][i]!=u)
			low[v]=MIN(low[v],pre[g[v][i]]);
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(getline(cin,s))
	{
		istringstream iss(s);
		iss>>n;
		cnt=0;
		if(n==0)
			break;
		while(getline(cin,s))
		{
			istringstream iss(s);
			iss>>a;
			if(a==0)
				break;
			else
				while(iss>>b)
				{
					g[a].push_back(b);
					g[b].push_back(a);
				}
		}
		ans=0;
		for(int i=1;i<=n;++i)
			pre[i]=-1;
		for(int i=1;i<=n;++i)
			if(pre[i]==-1)
				dfs(i,i);
		cout<<ans<<"\n";
		for(int i=1;i<=n;++i)
			g[i].clear();
	}

	return 0;
}