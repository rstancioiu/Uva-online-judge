// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/116/11689.html
#include <cstdio>

using namespace std;
int t,e,f,c,total,drink;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&e,&f,&c);
		total=e+f;
		drink=0;
		while(total>=c)
		{
			drink+=total/c;
			total=total/c + total%c;
		}
		printf("%d\n",drink);
	}
	return 0;
}