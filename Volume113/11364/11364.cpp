// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/113/11364.html
#include <cstdio>
#define SIZE 100

using namespace std;

int main()
{	
	int t,n,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int minimum=SIZE;
		int maximum=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a);
			if(a<minimum)
				minimum=a;
			if(a>maximum)
				maximum=a;
		}
		printf("%d\n",(maximum-minimum)*2);
	}
	return 0;
}