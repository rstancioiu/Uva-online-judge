#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;
unsigned int l,u;
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
            {
                v[j>>3]|=(1<<(j&7));
            }

        }
    }
    for(;(i<<1)+1<N;++i)
        if((v[i>>3]&(1<<(i&7)))==0)
            primes[cnt++]=(i<<1)+1;
}

bool isPrime(int n)
{
    if(n==1)
        return false;
    int s=sqrt(n);
    for(int i=0;i<cnt && primes[i]<=s;++i)
        if(n%primes[i]==0)
            return false;
    return true;
}


unsigned int mnf,mnl,mxf,mxl;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt","r",stdin);
    cnt=0;
    GeneratePrimes();
    while(cin>>l>>u)
    {
        if(l>u)
            swap(l,u);
        unsigned int minimum=2147483647;
        unsigned int maximum=0;
        unsigned int f,prev,i;
        unsigned int count=0;
        for(i=l; i<=u; ++i)
        {
            if(isPrime(i))
            {
                prev=i;
                f=i;
                count++;
                break;
            }
        }
        for(++i; i<=u; ++i)
        {
            if(isPrime(i))
            {
                if(i-prev<minimum)
                {
                    minimum=i-prev;
                    mnf=prev;
                    mnl=i;
                }
                if(i-prev>maximum)
                {
                    maximum=i-prev;
                    mxf=prev;
                    mxl=i;
                }
                count++;
                prev=i;
            }
        }
        if(count<2 || maximum==0)
            cout<<"There are no adjacent primes."<<endl;
        else
            cout<<mnf<<","<<mnl<<" are closest, "<<mxf<<","<<mxl<<" are most distant."<<endl;
    }
    return 0;
}
