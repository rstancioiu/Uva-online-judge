#include <queue>
#include <iostream>
#include <vector>
#define NM 1024
#define INF 0x3f3f3f3f

using namespace std;
vector<pair<int,int> > vertices[NM];
int distances[NM];
int nr[NM];
int visited[NM];
int n,m;

bool BellmanFord()
{
	queue<int> fifo;
	for(int i=0;i<n;++i)
	{
		distances[i]=INF;
		nr[i]=0;
		visited[i]=0;
	}
	distances[0]=0;
	vector<pair<int,int> >::iterator it;
	fifo.push(0);
	int t=0;
	int k=n*m;
	while(!fifo.empty())
	{
		int p=fifo.front();
		visited[p]=0;
		for(it=vertices[p].begin();it!=vertices[p].end();++it)
		{
			if(distances[p]+it->second < distances[it->first])
			{
				if(++nr[it->first]>=n)
					return true;
				if(visited[it->first]==0)
					fifo.push(it->first);
				distances[it->first]=distances[p]+it->second;
				visited[it->first]=1;
			}
		}
		fifo.pop();
	}
	return false;
}

int main()
{
	int wh1,wh2,d;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<m;++i)
		{
			cin>>wh1>>wh2>>d;
			vertices[wh1].push_back(make_pair(wh2,d));
		}
		bool result = BellmanFord();
		if(result)
			cout<<"possible"<<endl;
		else cout<<"not possible"<<endl;
		for(int i=0;i<n;++i)
			vertices[i].clear();
	}
	return 0;
}