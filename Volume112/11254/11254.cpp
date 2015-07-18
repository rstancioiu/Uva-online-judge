// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/112/11254.html
#include <cstdio>
#include <cmath>

using namespace std;
int n,a,b,x,y;

int main()
{
	while(scanf("%d",&n)==1 && (n!=-1))
	{
		n<<=1;
		int square=sqrt(n);
		for(int i=square;i>=1;--i)
		{
			if(n%i==0)
			{
				x=i;
				y=n/i;
				if((y-x)%2==1)
				{
					a=(y-x+1)/2;
					b=(x+y-1)/2;
					printf("%d = %d + ... + %d\n",n>>1,a,b);
					break;
				}
			}
		}
	}
	return 0;
}