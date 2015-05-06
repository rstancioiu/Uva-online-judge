#include <cstdio>

using namespace std;
int n,m,t,res,beer;

void ComputeResult()
{
	res=0;
	beer=t;
	for(int i=0;i<=t;i+=n)
	{
		if((t-i)%m<beer)
		{
			beer=(t-i)%m;
			res=i/n+(t-i)/m;
		}
		else if((t-i)%m==beer)
		{
			if(res<(i/n)+(t-i)/m)
				res=i/n+(t-i)/m;
		}
	}
}

int main()
{
	while(scanf("%d %d %d",&n,&m,&t)==3)
	{
		ComputeResult();
		if(beer>0)
			printf("%d %d\n",res,beer);
		else printf("%d\n",res);
	}
	return 0;
}