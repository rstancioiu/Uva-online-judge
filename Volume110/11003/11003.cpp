// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/110/11003.html
#include <cstdio>
#define N 1024
#define M 6144

using namespace std;
inline int MAX(int a,int b){return (a>b)?a:b;}

typedef struct Box{
	int weight;
	int maxLoad;
}Box;
Box boxes[N];
int stack[M];
int n,w,l;

int main()
{
	while(scanf("%d",&n)==1 && n!=0)
	{
		for(int i=0;i<M;++i)
		{
			stack[i]=-1;
		}
		for(int i=n-1;i>=0;--i)
		{
			scanf("%d %d",&boxes[i].weight,&boxes[i].maxLoad);
		}
		stack[0]=0;
		for(int i=0;i<n;++i)
		{
			for(int j=boxes[i].maxLoad;j>=0;--j)
			{
				if(stack[j]!=-1)
				{
					if(stack[j+boxes[i].weight]<stack[j]+1)
						stack[j+boxes[i].weight]=stack[j]+1;
				}
			}
		}
		int maximum=0;
		for(int i=0;i<M;++i)
		{
			maximum=MAX(maximum,stack[i]);
		}
		printf("%d\n",maximum);
	}	
	return 0;
}