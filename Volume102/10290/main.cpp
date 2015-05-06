#include <cstdio>
#include <vector>
#include <cmath>
#include <deque>
#define N 4782969

using namespace std;
long primes[N/8];
unsigned long long int n;
char p[N/8/2];
int index;


void GeneratePrimes()
{
	index=0;
	long long int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<=N;++i)
	{
		if((p[i>>3]&(1<<(i&7)))==0)
		{
			primes[index++]=(i<<1)+1;
			for(j=((i*i)<<1) + (i<<1),k=(i<<1)+1;(j<<1)+1<=N;j+=k)
			{
				p[j>>3]|=(1<<(j&7));
			}
		}
	}

	for(;(i<<1)+1<=N;++i)
	{
		if((p[i>>3]&(1<<(i&7)))==0)
		{
			primes[index++]=(i<<1)+1;
		}
	}
}

int main()
{
	GeneratePrimes();
	while(scanf("%llu",&n)==1)
	{
		if(n==0)
			printf("0\n");
		else
		{
			int count=0;
			while(n%2==0)
				n>>=1;
			int product=1;
			int sq=sqrt(n);
			for(int i=0;i<index && primes[i]<=sq;++i)
			{
				if(n%primes[i]==0)
				{
					int aux=0;
					while(n%primes[i]==0)
					{
						n/=primes[i];
						aux++;
					}
					sq=sqrt(n);
					product*=(aux+1);
				}
			}
			if(n!=1)
				product<<=1;
			printf("%d\n",product);
		}
	}
	return 0;
}