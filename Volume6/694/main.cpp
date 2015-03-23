#include <cstdio>

using namespace std;


int main()
{
	long long int a,limit;
	int cs=0;
	while(scanf("%lld %lld",&a,&limit)==2)
	{
		cs++;
		if(a==-1 && limit==-1)
			break;
		int cnt=1;
		long long int t=a;
		if(a!=0)
		{
			while(t!=1 && t<=limit)
			{
				if(t%2==0)
					t/=2;
				else
				{
					t=t*3+1;
				}
				if(t<=limit)
					cnt++;
			}
		}
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",cs,a,limit,cnt );
	}

	return 0;
}