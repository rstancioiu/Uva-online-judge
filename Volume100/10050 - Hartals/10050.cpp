// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10050.html
#include <cstdio>
#define N 3800

using namespace std;

int visited[N];


int main()
{
	int t,n,p,h;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			visited[i]=0;
		scanf("%d",&p);
		for(int i=0;i<p;++i)
		{
			scanf("%d",&h);
			int t=h;
			while(t<=n)
			{
				visited[t]++;
				t+=h;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			if(visited[i]>0 && (i%7!=0 && i%7!=6))
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}