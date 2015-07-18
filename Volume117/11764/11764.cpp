// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/117/11764.html
#include <cstdio>
#define N 64

using namespace std;
int wall[N];
int t,n,highj,lowj;

int main()
{	
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&n);
		highj=0;
		lowj=0;
		for(int j=0;j<n;++j)
			scanf("%d",&wall[j]);
		for(int j=1;j<n;++j)
		{
			if(wall[j]>wall[j-1])
				highj++;
			else if(wall[j]<wall[j-1]) lowj++;
		}
		printf("Case %d: %d %d\n",i,highj,lowj);
	}
	return 0;
}