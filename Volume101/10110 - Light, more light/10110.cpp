// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/101/10110.html
#include <cstdio>
#include <cmath>

using namespace std;



int main()
{
	long long int n;
	while(scanf("%lld",&n)==1)
	{
		if(n==0)
			break;
		long long int s=(long long int)sqrt(n);
		if(s*s==n)
		{
			printf("yes\n");
		}
		else printf("no\n");
	}
	return 0;
}