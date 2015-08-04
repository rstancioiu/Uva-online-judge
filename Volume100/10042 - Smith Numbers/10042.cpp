#include <bits/stdc++.h>
#define N 70000

using namespace std;
int v[N/2];
int primes[N/2];
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
				v[j>>3]|=(1<<(j&7));
			}
		}
	}
	for(;(i<<1)+1<N;++i)
		if((v[i>>3]&(1<<(i&7)))==0)
			primes[cnt++]=(i<<1)+1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("test.txt","r",stdin);
	cnt=0;
	GeneratePrimes();
	int t;
    int n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=n+1;;++i)
		{
			int sumd=0;
			int j=i;
			while(j!=0)
			{
				sumd+=j%10;
				j/=10;
			}
			int sumpd=0;
			int s=sqrt(i);
			int p=i;
			for(int k=0;primes[k]<=s;++k)
			{
				if(p%primes[k]==0)
				{
					int suma=0;
					int j=primes[k];
					while(j!=0)
					{
						suma+=j%10;
						j/=10;
					}
					while(p%primes[k]==0)
					{
						sumpd+=suma;
						p/=primes[k];
					}
					s=sqrt(p);
				}
			}
			if(p!=1)
			{
				int j=p;
				while(j!=0)
				{
					sumpd+=j%10;
					j/=10;
				}
			}
			if(sumpd==sumd && i!=p)
			{
				cout<<i<<endl;
				break;
			}
		}
	}

	return 0;
}
