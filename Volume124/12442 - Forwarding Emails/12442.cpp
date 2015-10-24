#include <bits/stdc++.h>
#define N 50100

using namespace std;
vector<int> g[N];
int vis[N]={0};
int t,n,a,b;
int p;

int DFSUtil(int i)
{
	int cnt=0;
	vis[i]=p;
	for(int j=0;j<g[i].size();++j)
	{
		if(vis[g[i][j]]!=p)
		{
			cnt++;
			cnt+=DFSUtil(g[i][j]);
			vis[g[i][j]]=1;
		}
	}
	return cnt;
}

int DFS()
{
	int ret=1;
	int maximum=0;
	for(int i=1;i<N;++i)
	{
		if(!vis[i])
		{
			p++;
			int t=DFSUtil(i);
			if(t>maximum)
			{
				ret=i;
				maximum=t;
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			g[a].push_back(b);
		}
		p=0;
		cout<<"Case "<<c<<": "<<DFS()<<"\n";
		for(int i=0;i<N;++i)
		{
			g[i].clear();
			vis[i]=0;
		}
	}
	return 0;
}