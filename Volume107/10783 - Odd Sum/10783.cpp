// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/107/10783.html
#include <cstdio>

using namespace std;


int main()
{
	int t,a,b;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&a);
		scanf("%d",&b);
		if(a%2==0) a++;
		if(b%2==0) b--;
		printf("Case %d: %d\n",i,(b+1)*(b+1)/4-(a-1)*(a-1)/4);
	}
	return 0;
}