// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/100/10018.html
#include <cstdio>


using namespace std;


int main()
{
	int t;
	long long int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		bool found = false;
		long long int k;
		int cnt=0;
		while(!found)
		{
			long long int i=n;
			k=0;
			while(i!=0)
			{
				k = (k<<1) + (k<<3) +i%10;
				i/=10;
			}
			if(k==n)
			{
				found=true;
			}
			else 
			{
				n+=k;
				cnt++;
			}
		}
		printf("%d %lld\n",cnt,n);
	}
	return 0;
}