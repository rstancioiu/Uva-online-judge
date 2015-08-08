#include <bits/stdc++.h>
#define ll long long
#define N 100000

using namespace std;
unsigned int l,u;

long long int exp(long long int base, long long int exponent, long long int mod)
{
    long long int x = 1;
    long long int y = base;
    while (exponent)
    {
        if (exponent%2==1)
            x=(x*y)%mod;
        y =(y*y)%mod;
        exponent>>=1;
    }
    return x % mod;
}

bool MillerRabin(long long int n,int it)
{
    if(n<2)
    {
        return false;
    }
    if(n==2)
        return true;
    else if(n%2==0)
    {
        return false;
    }
    long long int s=n-1;
    while(s%2==0)
    {
        s/=2;
    }
    for (int i=0;i<it; i++)
    {
        long long int a = rand()%(n-1)+1; 
        long long int temp = s;
        long long int mod = exp(a,temp,n);
        while (temp!=n-1 && mod!=1 && mod!=n-1)
        {
            mod=(mod*mod)%n;
            temp<<=1;
        }
        if (mod!=n-1 && temp%2==0)
        {
            return false;
        }
    }
    return true;
}



unsigned int mnf,mnl,mxf,mxl;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt","r",stdin);
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
            if(MillerRabin(i,5))
            {
                prev=i;
                f=i;
                count++;
                break;
            }
        }
        for(++i; i<=u; ++i)
        {
            if(MillerRabin(i,5))
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
