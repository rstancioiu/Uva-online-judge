// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/1/294.html
// Description: maths
#include <cstdio>
#include <cmath>
#define N 100000

char v[N/8/2];
int primes[N/2];
int index=0;
int l,u,t;

void GeneratePrimes()
{
	primes[index++]=2;
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
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&u);
		int maximum=0;
		int number=l;
		for(int i=l;i<=u;++i)
		{
			int product=1;
			int root=sqrt(i);
			int p=i;	
			for(int j=0;j<index && primes[j]<=root;++j)
			{
				if(p%primes[j]==0)
				{
					int count=0;
					while(p%primes[j]==0)
					{
						count++;
						p/=primes[j];
					}
					product*=count+1;
					root=sqrt(p);
				}
			}
			if(p!=1)
				product*=2;
			if(product>maximum)
			{
				maximum=product;
				number=i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,u,number,maximum);
	}
	return 0;
}