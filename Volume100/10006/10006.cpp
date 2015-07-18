// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10006.html
#include <bits/stdc++.h>
#define N 65001

using namespace std;

int primes[N];
int carmichael[N];

void GeneratePrimes()
{
    for(int i=2;i<N;++i)
        primes[i]=1;
	for(int i=3;i<N;i+=2)
	{
		if(primes[i])
		{
			for(int j=(i<<1);j<N;j+=i)
			{
				primes[j]=0;
			}
		}
	}
}

void GenerateCarmNumbers()
{
    for(int n=2;n<N;++n)
    {
        if(primes[n])
		{
			carmichael[n]=0;
		}
		else
		{
			int i;
			for(i=2;i<n;++i)
			{
				unsigned int a=i;
				unsigned int res=1;
				for(int j=0;(1<<j)<=n;++j)
				{
					if((1<<j)&n)
					{
						res=(res*a)%n;
					}
					a=(a*a)%n;
				}
				if(res!=i)
					break;
			}
			if(i==n)
			{
				carmichael[n]=1;
			}
			else carmichael[n]=0;
		}

    }

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	GeneratePrimes();
	GenerateCarmNumbers();
	unsigned int n;
	while(cin>>n && n!=0)
	{
		if(carmichael[n])
        {
            cout<<"The number "<<n<<" is a Carmichael number.\n";
        }
        else cout<<n<<" is normal.\n";
	}
	return 0;
}
