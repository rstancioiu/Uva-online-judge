#include <cstdio>
#define N 5000001

int v[N]={0};
int res[N]={0};
int a,b,t;


int main()
{
	v[1]=0;
	for(int i=2;i<N;++i)
	{
		if(!v[i])
		{
			v[i]++;
			for(int j=i+i;j<N;j+=i)
			{
				int k=j;
				while(k%i==0)
				{
					v[j]++;
					k/=i;
				}
			}
		}
	}
	res[1]=0;
	for(int i=2;i<N;++i)
		res[i]=res[i-1]+v[i];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&b,&a);
		printf("%d\n",res[b]-res[a]);
	}
	return 0;
}