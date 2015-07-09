//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/160.html
//Description: 
#include <cstdio>
#include <map>
#include <utility>
#define N 100

using namespace std;

map<int,int> primes;
char v[N];

void GeneratePrimes()
{
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes.insert(make_pair((i<<1)+1,0));
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<=N;j+=k)
			{
				v[j>>3]|=(1<<(j&7));
			}
		}
	}
	for(;(i<<1)+1<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes.insert(make_pair((i<<1)+1,0));
		}
	}
}

int main()
{
	primes.insert(make_pair(2,0));
	GeneratePrimes();
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			break;
		map<int,int>::iterator it;
		for(it=primes.begin();it!=primes.end();++it)
			it->second=0;
		for(int i=2;i<=n;++i)
		{
			int t=i;
			for(it=primes.begin();it!=primes.end() && t!=1;)
			{
				if(t%(it->first)==0)
				{
					t/=(it->first);
					it->second++;
				}
				else it++;
			}
		}
		printf("%3d! =",n);
		int k=0;
		for(it=primes.begin();it!=primes.end() && it->second!=0;++it)
		{
			if(k==15)
			{
				printf("\n      ");
			}
			k++;
			printf("%3d",it->second);
		}
		printf("\n");
	}
	return 0;
}