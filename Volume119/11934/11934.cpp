// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/119/11934.html
#include <cstdio>

using namespace std;
int a,b,c,d,L;

bool Divide(int k)
{
	int res=a*k*k+b*k+c;
	return (res%d==0) ? 1 : 0;
}

int main()
{
	while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&L)==5 &&
		 !(a==0 && b==0 && c==0 && d==0 && L==0))
	{
		int cnt=0;
		for(int k=0;k<=L;++k)
		{
			if(Divide(k))
				cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}