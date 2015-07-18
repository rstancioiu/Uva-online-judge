// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/109/10986.html
#include <iostream>
#include <vector>
#include <queue>
#define N 20010
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int,int> ii;

int t,n,m,s,e;
vector<ii> cables[N];
int distances[N];

int Dijkstra()
{
	vector<ii> :: iterator it;
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	distances[s]=0;
	pq.push(ii(distances[s],s));
	while(!pq.empty())
	{
		ii p = pq.top();
		pq.pop();
		int d=p.first;
		int a=p.second;
		for(it=cables[a].begin();it!=cables[a].end();++it)
		{
			if(distances[it->first]>distances[a]+it->second)
			{
				distances[it->first]=distances[a]+it->second;
				pq.push(ii(distances[it->first],it->first));
			}
		}
	}
	return distances[e];
}

int main()
{
	int a,b,d;
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n>>m>>s>>e;
		for(int j=0;j<n;++j)
			distances[j]=INF;
		for(int j=0;j<m;++j)
		{
			cin>>a>>b>>d;
			cables[a].push_back(ii(b,d));
			cables[b].push_back(ii(a,d));
		}
		int res = Dijkstra();
		cout<<"Case #"<<i<<": ";
		if(res==INF)
			cout<<"unreachable\n";
		else cout<<res<<"\n";
		for(int j=0;j<n;++j)
			cables[j].clear();
	}
	return 0;
}