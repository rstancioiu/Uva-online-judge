#include <bits/stdc++.h>
#define M 1000001
#define N 1024

using namespace std;

char v[N/2];
int primes[N/2];
int tab[M];
int c[M]={0};
int cnt;

void GeneratePrimes()
{
	primes[cnt++]=2;
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes[cnt++]=(i<<1)+1;
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<N;j+=k)
			{
				v[j>>3]|=1<<(j&7);
			}
		}
	}
	for(;(i<<1)+1<N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
			primes[cnt++]=((i<<1)+1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cnt=0;
	GeneratePrimes();
	for(int i=0;i<cnt;++i)
		c[primes[i]]=1;
	tab[1]=0;
	for(int i=2;i<M;++i)
	{
		tab[i]=tab[i-1];
		int s=sqrt(i);
		for(int k=0;primes[k]<=s && k<cnt;++k)
		{
			if(i%primes[k]==0)
			{
				c[i]=c[i/primes[k]]+1;
				break;
			}
		}
		if(c[i]==0)
		{
			tab[i]++;
			c[i]++;
		}
		else
		tab[i]+=c[i];
	}
	int n;
	while(cin>>n)
	{
		cout<<tab[n]<<endl;
	}

	return 0;
}