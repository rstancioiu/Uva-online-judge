#include <cstdio>


int gcd(int i,int j)
{
	int t=0,aux;
	while(i!=0)
	{
		if(i>j)
		{
			i=i-j;
		}
		else
		{
			aux=i;
			i=j-i;
			j=aux;
		}
	}
	return j;
}

int main()
{
	int n,cnt;
	while(scanf("%d",&n)==1 && n!=0)
	{
		cnt=0;
		for(int i=1;i<n;++i)
		{
			for(int j=i+1;j<=n;++j)
				cnt+=gcd(i,j);
		}
		printf("%d\n",cnt);
	}
	return 0;
}