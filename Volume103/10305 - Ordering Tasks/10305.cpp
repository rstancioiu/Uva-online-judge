// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/103/10305.html
#include <cstdio>
#include <vector>
#include <stack>
#define N 101

using namespace std;

vector<int> order[N];
int n,m;
int visited[N];
stack<int> tasks;

void TopologicalSortUtil(int i)
{
	visited[i]=1;
	vector<int>::iterator it;
	for(it=order[i].begin();it!=order[i].end();++it)
	{
		if(!visited[*it])
			TopologicalSortUtil(*it);
	}
	tasks.push(i);
}


void TopologicalSort()
{
	for(int i=1;i<=n;++i)
		visited[i]=0;
	for(int i=1;i<=n;++i)
		if(!visited[i])
			TopologicalSortUtil(i);
	printf("%d",tasks.top());
	tasks.pop();
	while(!tasks.empty())
	{
		printf(" %d",tasks.top());
		tasks.pop();
	}
	printf("\n");
}

int main()
{
	int a,b;
	while(scanf("%d %d",&n,&m)==2 &&!(n==0 && m==0))
	{
		for(int i=0;i<m;++i)
		{
			scanf("%d %d",&a,&b);
			order[a].push_back(b);
		}
		TopologicalSort();
		for(int i=1;i<=n;++i)
			order[i].clear();
	}
	return 0;
}