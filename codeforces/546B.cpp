#include <cstdio>
#define N 6500

int n;
int a;
int cool[N]={0};

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a);
		cool[a]++;
	}
	int i;
	int sum=0;
	for(i=1;i<N;++i)
		if(cool[i]!=0)
			break;
	int j=i;
	for(;i<=n;++i)
	{
		if(cool[i]>1)
		{
			while(cool[i]>1)
			{
				j=i+1;
				for(;j<N;++j)
				{
					if(cool[j]==0)
					{
						sum+=(j-i);
						cool[j]=1;
						cool[i]--;
						break;
					}
				}
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}