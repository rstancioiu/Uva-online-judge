#include <cstdio>

int main()
{
	int t;
	long n,j;
	scanf("%d",&t);
	for(int i=0;i<t;++i)
	{
		if(i) printf("\n");;
		scanf("%ld",&n);
		if(n==0)
			printf("3\n");
		else
		{
			if(n<0) n=-n;
			long sum=0;
			for(j=1;sum<n;++j)
			{
				sum+=j;
			}
			while((sum-n)%2!=0)
			{
				sum+=j;
				j++;
			}
			printf("%ld\n",j-1);
		}
	}
	return 0;
}