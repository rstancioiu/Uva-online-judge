#include <bits/stdc++.h>
#define N 1001000
#define MOD 1000000007

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a<b)?a:b;}
inline int ABS(int a){return (a>0)?a:-a;}
typedef long long ll;
int n;
int primes[N]={0};

bool isPrime(int n)
{
	int s=sqrt(n);
	for(int i=2;i<=s;++i)
		if(n%i==0)
			return 0;
    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    if(isPrime(n))
    {
    	cout<<1<<endl<<n<<endl;
    }
    else if(isPrime(n-2))
    {
    	cout<<2<<endl<<2<<" "<<n-2<<endl;
    }
    else
    {
    	for(int i=3;i<=N;i+=2)
    	{
    		if(isPrime(i))
    		{
    			if(isPrime(n-i-i))
    			{
    				cout<<3<<endl<<i<<" "<<i<<" "<<n-i-i<<endl;
    				return 0;
    			}
    		}
    	}
    }
    return 0;
}