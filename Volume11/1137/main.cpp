#include <cstdio>
#include <cmath>
#define N 26756

char v[N];
int primes[N/2];
int index;

void GeneratePrimes()
{
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes[index++]=(i<<1)+1;
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<=N;j+=k)
			{
				v[j>>3]|=(1<<(j&7));
			}
		}
	}
	for(;(i<<1)+1<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
			primes[index++]=(i<<1)+1;
	}
}

int main()
{
	GeneratePrimes();
	unsigned int a,b;
	int c=0;
	while(scanf("%u%u",&a,&b)==2)
	{
		if(c++)
			printf("\n");
		int count=0;
		if(a%2==0)
			a++;
		if(b%2==0)
			b--;
		for(unsigned int i=a;i<=b;i+=2)
		{
				unsigned int n=i;
				int factors=0;
				int problem=0;
				int root = sqrt(n);
				for(int j=0;j<index && primes[j]<=root;++j)
				{
					if(n%primes[j]==0)
					{
						n/=primes[j];
						factors++;
						if(n%primes[j]==0 || (i-1)%(primes[j]-1)!=0)
						{
							problem=1;
							break;
						}
						root = sqrt(n);
					}
				}
				if(n!=1)
				{
					factors++;
					if((i-1)%(n-1)!=0)
						problem=1;
				}
				if(!problem && factors>=3)
				{
					printf("%u\n",i);
					count++;
				}
		}
		if(!count)
			printf("none\n");
	}
	return 0;
}