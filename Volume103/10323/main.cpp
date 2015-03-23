#include <cstdio>
#define N 128

using namespace std;
unsigned long long int v[128];

int main()
{
	int minimum,maximum;
	unsigned long long int k=1;
	int i;
	for(i=1;k<10000;++i)
		k*=i;
	minimum=i;
	v[i-1]=k;
	for(;k<=6227020800;++i)
	{  
		k*=i;
		v[i]=k;
	}
	maximum=i-1;
	int n;
	while(scanf("%d",&n)==1)
	{
		if((n<8 && n>=0)||(n<0 && n%2==0))
			printf("Underflow!\n");
		else if(n<=13 && n>=8)
			printf("%llu\n",v[n]);
		else
			printf("Overflow!\n");
	}
	return 0;
}