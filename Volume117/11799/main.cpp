#include <cstdio>

using namespace std;
int t,n,a,maximum;

int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&n);
		maximum=0;
		for(int j=0;j<n;++j)
		{
			scanf("%d",&a);
			if(a>maximum)
				maximum=a;
		}
		printf("Case %d: %d\n",i,maximum);
	}
	return 0;
}