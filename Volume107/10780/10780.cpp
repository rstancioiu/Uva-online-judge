// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/107/10780.html
#include <bits/stdc++.h>
#define N 10000

using namespace std;
int t;
int n,m;
int primes[N/2];
int tab1[N/2];
int tab2[N/2];
char v[N];
int cnt;

void GeneratePrimes()
{
    primes[cnt++]=2;
    int i,j,k;
	for(i=1;((i*i)<<1)+(i<<1)<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
		{
			primes[cnt++]=(i<<1)+1;
			for(j=((i*i)<<1)+(i<<1),k=(i<<1)+1;(j<<1)+1<=N;j+=k)
			{
				v[j>>3]|=(1<<(j&7));
			}
		}
	}
	for(;(i<<1)+1<=N;++i)
	{
		if((v[i>>3]&(1<<(i&7)))==0)
			primes[cnt++]=(i<<1)+1;
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cnt=0;
    GeneratePrimes();
    cin>>t;
    for(int p=1;p<=t;++p)
    {
        cin>>m>>n;
        for(int i=0;i<cnt;++i)
        {
            tab1[i]=0;
            int l=primes[i];
            while(l<=n)
            {
                tab1[i]+=n/l;
                l*=primes[i];
            }
        }
        for(int i=0;i<cnt;++i)
        {
            tab2[i]=0;
            while(m%primes[i]==0)
            {
                tab2[i]++;
                m/=primes[i];
            }
        }
        int ans=0x1fffffff;
        for(int i=0;i<cnt;++i)
        {
            if(tab2[i]!=0)
            {
                int k=tab1[i]/tab2[i];
                if(ans>k)
                    ans=k;
            }
        }
        cout<<"Case "<<p<<":"<<endl;
        if(ans==0)
        {
            cout<<"Impossible to divide"<<endl;
        }
        else
            cout<<ans<<endl;
    }


    return 0;
}
