// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/103/10300.html
#include <cstdio>


using namespace std;


int main()
{
	int t,n,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int sum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			sum+=a*c;
		}
		printf("%d\n",sum);
	}

	return 0;
}