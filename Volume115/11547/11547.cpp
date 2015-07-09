// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/115/11547.html
#include <cstdio>

using namespace std;

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		n=(n*63+7492)*5-498;
		n=(n>0)?n:-n;
		printf("%d\n",(n%100 - n%10)/10);
	}
	return 0;
}