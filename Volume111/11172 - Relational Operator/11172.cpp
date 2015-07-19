// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/111/11172.html
#include <cstdio>


using namespace std;


int main()
{
	int a,b;
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		scanf("%d %d",&a,&b);
		if(a>b)
			printf(">\n");
		else if(a==b)
			printf("=\n");
		else 
			printf("<\n");
	}
	return 0;
}