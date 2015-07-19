// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/123/12372.html
#include <cstdio>

using namespace std;

int main()
{
	int t,l,w,h;
	scanf("%d",&t);
	int i=0;
	while(t--)
	{
		++i;
		scanf("%d %d %d",&l,&w,&h);
		if(l<=20 && w<=20 && h<=20)
			printf("Case %d: good\n",i);
		else printf("Case %d: bad\n",i);
	}
	return 0;
}