//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/3/357.html
#include <cstdio>
#define N 30004

using namespace std;
unsigned long long int ways[N]={0};

int main()
{
	int n;
	int coins[]={50,25,10,5,1};
	ways[0]=1;
	for(int i=0;i<5;++i)
	{
		for(int j=0;j<N;++j)
		{
			if(j>=coins[i])
			{
				ways[j]+=ways[j-coins[i]];
			}
		}
	}
	while(scanf("%d",&n)==1)
	{
		if(ways[n]==1)
		{
			printf("There is only %llu way to produce %d cents change.\n",ways[n],n);
		}
		else if(ways[n]>1)
		{
			printf("There are %llu ways to produce %d cents change.\n",ways[n],n);
		}
	}
	return 0;
}