#include <cstdio>

using namespace std;

int main()
{
	int t;
	int n,k,p;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d %d %d",&n,&k,&p);
		int res=(k+p)%n;
		printf("Case %d: %d\n",i,(res==0)?n:res);
	}
	return 0;
}