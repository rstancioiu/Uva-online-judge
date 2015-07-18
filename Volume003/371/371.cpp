//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/371.html
#include <cstdio>

using namespace std;
long long int index;

long Ackermann(long long int a,long long int b)
{
	long maximum=0;
	index=a;
	for(long long int i=a;i<=b;++i)
	{
		long cnt=0;
		long long int t=i;
		if(t==1)
		{
			t=3*t+1;
			cnt++;
		}
		while(t!=1)
		{
			if(t%2==0)
			{
				t/=2;
				cnt++;
			}
			else
			{
				t=3*t+1;
				cnt++;
			}
		}
		if(cnt>maximum)
		{
			maximum=cnt;
			index=i;
		}
	}
	return maximum;
}


int main()
{
	long long int l,h;
	while(scanf("%lld %lld",&l,&h)==2 && !(l==0 && h==0))
	{
		if(l>h)
		{
			int aux=l;
			l=h;
			h=aux;
		}
		long nbValue=Ackermann(l,h);
		printf("Between %lld and %lld, %lld generates the longest sequence of %ld values.\n",l,h,index,nbValue);
	}

	return 0;
}