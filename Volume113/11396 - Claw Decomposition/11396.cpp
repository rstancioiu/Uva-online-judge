#include <bits/stdc++.h>
#define N 310

using namespace std;
typedef pair<int,int> ii; 
int n;
vector<int> gn[N];
int a,b;
int vis[N];

int bfs(int s,int t)
{
	queue<ii> Q;
	Q.push(ii(s,t));
	vis[s]=t;
	while(!Q.empty())
	{
		ii p=Q.front();
		Q.pop();
		int u=p.first;
		int t=p.second;
		for(int v=0;v<gn[u].size();++v)
		{
			if(vis[gn[u][v]]==-1)
			{
				Q.push(ii(gn[u][v],t+1));
				vis[gn[u][v]]=(t+1)%2;
			}
			else if(vis[gn[u][v]]==t%2)
				return 0;
		}
	}
	return 1;
}

int compute()
{
	for(int i=1;i<=n;++i)
		vis[i]=-1;
	for(int i=1;i<=n;++i)
	{
		if(vis[i]==-1)
		{
			if(!bfs(i,0))
				return 0;
		}
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n && n!=0)
	{
		while(cin>>a>>b && !(a==0 && b==0))
		{
			gn[a].push_back(b);
			gn[b].push_back(a);
		}
		if(compute())
			cout<<"YES\n";
		else cout<<"NO\n";
		for(int i=1;i<=n;++i)
			gn[i].clear();
	}
	return 0;
}