#include <cstdio>
#include <vector>
#include <stack>
#define N 128
#define INF 0x3f3f3f3f

using namespace std;
int n,nb,s;
vector<int> v[N];
int visited[N];
int d[N];
stack<int> lifo;

void TopologicalSortUtil(int t)
{
	visited[t]=1;
	vector<int>::iterator it;
	for(it=v[t].begin();it!=v[t].end();++it)
	{
		if(!visited[*it])
			TopologicalSortUtil(*it);
	}
	lifo.push(t);
}


void TopologicalSort()
{
	for(int i=1;i<=n;++i)
	{
		visited[i]=0;
	}
	for(int i=1;i<=n;++i)
	{
		if(!visited[i])
			TopologicalSortUtil(i);
	}

	for(int i=1;i<=n;++i)
	{
		d[i]=-1;
	}
	d[s]=0;
	while(!lifo.empty())
	{
		int k=lifo.top();
			lifo.pop();
		vector<int>::iterator it;
		if(d[k]!=-INF)
		{
			for(it=v[k].begin();it!=v[k].end();++it)
			{
				if(d[*it]<d[k]+1)
				{
					d[*it]=d[k]+1;
					printf("%d   %d\n",d[*it],*it);
				}
			}
		}
	}
	int max=-INF;
	int pos=n;
	for(int i=n;i>=1;--i)
	{
		if(d[i]>=max)
		{
			max=d[i];
			pos=i;
		}
	}
	printf("Case %d: The longest path from %d has length %d, finishing at %d.\n",nb,s,max,pos);
}


int main()
{
	int a,b;
	nb=0;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			break;
		if(nb++) printf("\n");
		scanf("%d",&s);
		while(scanf("%d %d",&a,&b)==2)
		{
			if(a==0 && b==0)
				break;
			v[a].push_back(b);
		}
		TopologicalSort();
	}

	return 0;
}