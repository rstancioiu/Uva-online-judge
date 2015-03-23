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