// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/121/12149.html
#include <cstdio>

using namespace std;


int main()
{
	int n;
	while(scanf("%d",&n)==1 && n!=0)
	{
		printf("%d\n",n*(n+1)*(2*n+1)/6);
	}
	return 0;
}