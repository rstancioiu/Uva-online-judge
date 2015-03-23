#include <cstdio>

using namespace std;

int main()
{
	int n,m,res;
	while(scanf("%d %d",&n,&m)==2 && !(n==0 && m==0))
	{
		if(n==1)
			printf("%d knights may be placed on a %d row %d column board.\n",m,n,m);
		else if(m==1)
			printf("%d knights may be placed on a %d row %d column board.\n",n,n,m);
		else if(n==2)
		{
			res=4*(int)(m/4);
			if(m%4>=2)
				res+=4;
			else if(m%4==1)
				res+=2;
			printf("%d knights may be placed on a %d row %d column board.\n",res,n,m);
		}
		else if(m==2)
		{
			res=4*(int)(n/4);
			if(n%4>=2)
				res+=4;
			else if(n%4==1)
				res+=2;			
			printf("%d knights may be placed on a %d row %d column board.\n",res,n,m);
		}
		else
		{
			if(n%2==0 || m%2==0)
			{
				res=n*m/2;
				printf("%d knights may be placed on a %d row %d column board.\n",res,n,m);
			}
			else
			{
				res=n*(m-1)/2+(n+1)/2;
				printf("%d knights may be placed on a %d row %d column board.\n",res,n,m);
			}
		}
	}
	return 0;
}