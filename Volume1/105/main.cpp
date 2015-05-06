#include <cstdio>
#define N 10002

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}
inline int MIN(int a,int b){return (a>b)?b:a;}
int v[N]={0};
int l,h,r,maxr,minl;

int main()
{
	maxr = 0;
	minl = N;
	while(scanf("%d%d%d",&l,&h,&r)==3)
	{	
		maxr = MAX(maxr,r);
		minl = MIN(minl,l);
		for(int i=l+1;i<=r;++i)
		{
			v[i] = MAX(v[i],h);
		}
	}
		printf("%d %d",minl,v[minl+1]);
	for(int i=minl+2;i<=maxr+1;++i)
	{
		if(v[i]!=v[i-1])
		{
			printf(" %d %d",i-1,v[i]);
		}
	}
	printf("\n");
	return 0;
}