#include <bits/stdc++.h>
#define N 10000000
using namespace std;

inline long long int MAX(long long int a,long long int b){return (a>b)?a:b;}

int prime[N/8];
char v[N/8/2];
int cnt;

void GeneratePrimes()
{
	cnt=0;
	prime[cnt++]=2;
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			prime[cnt++]=(i<<1)+1;
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<N;j+=k)
				v[j>>3]|=(1<<(j&7));
		}
	}
	for(;(i<<1)+1<N;++i)
		if((v[i>>3]&(1<<(i&7)))==0)
			prime[cnt++]=(i<<1)+1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	GeneratePrimes();
	long long int n;
	while(cin>>n && n!=0)
	{
		int p=0;
		if(n<0) n=-n;
		long long int maximum=1;
		int s=sqrt(n);
		for(int i=0;i<cnt && prime[i]<=s;++i)
		{
			if(n%prime[i]==0)
			{
				p++;
				maximum=prime[i];
				while(n%prime[i]==0)
					n/=prime[i];
				s=sqrt(n);
				if(n==1)
					break;
			}
		}
		if(n!=1)
		{
			p++;
			maximum=n;
		}
		if(p>1)
			cout<<maximum<<"\n";
		else
			cout<<-1<<"\n";
	}
	return 0;
}