// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/113/11313.html
#include <cstdio>

using namespace std;
int t,n,m;

int main()
{	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		if((n-m)%(m-1)==0)
		{
			printf("%d\n",1+(n-m)/(m-1));
		}
		else
			printf("cannot do this\n");
	}
	return 0;
}
