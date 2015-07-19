// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/5/583.html
#include <cstdio>
#include <cmath>
#define N 0x00010000

char v[N/8/2];
int primes[N/2];
int index=0;

void GeneratePrimes()
{
	primes[index++]=2;
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes[index++]=((i<<1)+1);
			for(j=(((i*i)<<1)+(i<<1)),k=((i<<1)+1);(j<<1)+1<=N;j+=k)
			{
				v[j>>3]|=(1<<(j&7));
			}
		}
	}
	for(;(i<<1)+1<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes[index++]=(i<<1)+1;
		}
	}
}

int n;

int main()
{
	GeneratePrimes();
	while(scanf("%d",&n)==1 && n!=0)
	{
		printf("%d =",n);
		bool firstFactor=true;
		if(n<0)
		{
			printf(" -1");
			firstFactor=false;
			n=-n;
		}
		int root=sqrt(n);
		for(int i=0;primes[i]<=root;++i)
		{
			if(n%primes[i]==0)
			{
				if(firstFactor)
				{
					printf(" %d",primes[i]);
					n/=primes[i];
					firstFactor=false;
				}
				else
				{
					printf(" x %d",primes[i]);
					n/=primes[i];
				}
				while(n%primes[i]==0)
				{
					printf(" x %d",primes[i]);
					n/=primes[i];
				}
				root=sqrt(n);
			}
		}
		if(n!=1)
		{
			if(firstFactor)
				printf(" %d",n);
			else
				printf(" x %d",n);
		}
		printf("\n");
	}
	return 0;
}
