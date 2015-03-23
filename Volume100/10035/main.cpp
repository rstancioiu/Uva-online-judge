#include <cstdio>

using namespace std;


int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a==0 && b==0)
			break;
		int t=0;
		int carry=0;
		for (;a!=0||b!=0; t/=10)
		{
			t+=(a%10)+(b%10);
			if(t>=10)
				carry++;
			a/=10;
			b/=10;
		}
		if(carry==0)
			printf("No carry operation.\n");
		else if(carry==1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n",carry);
	}
	return 0;
}