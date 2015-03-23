#include <cstdio>



int main()
{
	int a,b,c;
	while(scanf("%d %d",&a,&b)==2)
	{
		int cnt=0;
		while(a>=b)
		{
			c=a/b;
			cnt+=c*b;
			a%=b;
			a+=c;
		}
		cnt+=a;
		printf("%d\n",cnt);
	}
	return 0;
}