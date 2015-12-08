#include <bits/stdc++.h>
#define N 1000100

using namespace std;
int tab[N]={0};
char v[N/8];
int prime[N]={0};

void generatePrimes()
{
	prime[2]=1;;
	int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			prime[(i<<1)+1]=1;
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<N;j+=k)
			{
				v[j>>3]|=(1<<(j&7));
			}
		}
	}
	for(;(i<<1)+1<N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
			prime[(i<<1)+1]=1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	generatePrimes();
	for(int i=1;i<N;++i)
	{
		tab[i]=tab[i-1];
		if(prime[i])
		{
			int p=i;
			int cnt=0;
			while(p>0)
			{
				cnt+=p%10;
				p/=10;
			}
			if(prime[cnt])
			{
				tab[i]++;
			}
		}
	}
	int n,a,b;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a>>b;
		cout<<tab[b]-tab[a-1]<<"\n";
	}
	return 0;
}