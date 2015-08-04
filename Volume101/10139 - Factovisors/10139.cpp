#include <bits/stdc++.h>
#define N 70000

using namespace std;
char v[N/2];
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
				v[j>>3]|=1<<(j&7);
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
	int n,m;
	while(cin>>n>>m)
	{
		if(m<=n)
		{
			cout<<m<<" divides "<<n<<"!\n";
		}
		else
		{
			int s=sqrt(m);
			bool nodiv=false;
			int j=m;
			for(int i=0;primes[i]<=s;++i)
			{
				if(j%primes[i]==0)
				{
					int cnt=0;
					while(j%primes[i]==0)
					{
						j/=primes[i];
						cnt++;
					}
					s=sqrt(j);
					for(int k=primes[i];k<=n;k*=primes[i])
						cnt-=n/k;
					if(cnt>0)
					{
						nodiv=true;
						break;
					}
				}
			}
			if(nodiv|| (j!=1 && n<j))
			{
				cout<<m<<" does not divide "<<n<<"!\n";
			}
			else
				cout<<m<<" divides "<<n<<"!\n";

		}
	}
	return 0;
}
