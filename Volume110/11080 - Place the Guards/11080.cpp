#include <bits/stdc++.h>
#define N 256

using namespace std;
inline int MIN(int a,int b){return (a>b)?b:a;}
typedef pair<int,int> ii;
vector<int> g[N];
int vis[N];
int ans,a,b,n,m,t;

int bfs(int s)
{
	queue<ii> Q;
	int t=0;
	int a=1,b=0;
	vis[s]=t;
	Q.push(ii(s,t));
	while(!Q.empty())
	{
		ii p=Q.front();
		int j=p.first;
		int t=p.second;
		Q.pop();
		for(int i=0;i<g[j].size();++i)
		{
			if(vis[g[j][i]]==-1)
			{
				Q.push(ii(g[j][i],t+1));
				vis[g[j][i]]=(t+1)%2;
				if((t+1)%2==0)
					a++;
				else b++;
			}
			else if(vis[g[j][i]]==t%2)
				return 0;
		}
	}
	if(b==0)
		ans++;
	else
		ans+=MIN(a,b);
	return 1;
}

int compute()
{
	for(int i=0;i<n;++i)
		vis[i]=-1;
	for(int i=0;i<n;++i)
	{
		if(vis[i]==-1)
		{
			if(!bfs(i))
				return 0;
		}
	}
	return 1;
}



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<m;++i)
		{
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ans=0;
		if(compute())
			cout<<ans<<"\n";
		else cout<<-1<<"\n";
		for(int i=0;i<n;++i)
			g[i].clear();
	}
	return 0;
}