// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/107/10791.html
#include <bits/stdc++.h>
#define M 65536

using namespace std;
long long int N;
char v[M];
int primes[M/2];
int cnt;

void GeneratePrimes()
{
    primes[cnt++]=2;
    int i,j,k;
    for(i=1;((i*i)<<1)+(i<<1)<M;++i)
    {
        if((v[i>>3]&(1<<(i&7)))==0)
        {
            primes[cnt++]=(i<<1)+1;
            for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<=M;j+=k)
            {
                v[j>>3]|=(1<<(j&7));
            }
        }
    }
    for(;(i<<1)+1<M;++i)
    {
        if((v[i>>3]&(1<<(i&7)))==0)
        {
            primes[cnt++]=(i<<1)+1;
        }
    }

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=0;
	cnt=0;
	GeneratePrimes();
	while(cin>>N && N!=0)
	{
	    long long int ans=0;
	    long long int number=N;
	    int p=0;
	    for(int i=0;i<cnt && primes[i]<=N;++i)
        {
            if(N%primes[i]==0)
            {
                int k=N;
                while(k%primes[i]==0)
                {
                    k/=primes[i];
                }
                ans+=N/k;
                N=k;
                p++;
            }
        }
        if(N!=1 && N!=number)
        {
            ans+=N;
            p++;
        }
        if(p<=1)
            ans=number+1;
        t++;
		cout<<"Case "<<t<<": "<<ans<<endl;
	}

	return 0;
}
