// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/108/10879.html
#include <cstdio>
#include <vector>
#define N 10002

using namespace std;
vector<int> primes;
char p[N/8];

void GeneratePrimes()
{
	int i;
	for(i=1;((i*i)<<1)+(i<<1)<N;++i)
	{
		if((p[i>>3]&(1<<(i&7)))==0)
		{
			primes.push_back((i<<1)+1);
			for(int j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<N;j+=k)
			{
				p[j>>3] |=(1<<(j&7));
			}
		}
	}
	for(;(i<<1)+1<N;++i)
	{
		if((p[i>>3]&(1<<(i&7)))==0)
		{
			primes.push_back((i<<1)+1);
		}
	}
}	


int main()
{
	vector<int>::iterator it;
	int t,k,a,b,c,d;
	primes.push_back(2);
	GeneratePrimes();
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d",&k);
		int cnt=0;
		int aux=k;
		for(it=primes.begin();it!=primes.end();++it)
		{
			if(aux%(*it)==0)
			{
				a=(*it);
				b=k/a;
				aux/=a;
				break;
			}
		}
		for(it=primes.begin();it!=primes.end();++it)
		{
			if(aux%(*it)==0)
			{
				c=(*it)*a;
				d=k/c;
				break;
			}
		}
		printf("Case #%d: %d = %d * %d = %d * %d\n",i,k,a,b,c,d);
	}
	return 0;
}