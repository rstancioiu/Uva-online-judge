// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/103/10364.html
#include <cstdio>
#include <vector>
#define M 32

using namespace std;
int sticks[M];
int visited[M]={0};
int m,n,a;
int sum;

bool BackTrack(int i,int partialSum,int p)
{
	if(partialSum==sum)
	{
		partialSum=0;
		p=0;
	}
	else if(partialSum>sum)
		return false;
	if(i==m)
	{
		if(partialSum==0)
			return true;
		else return false;
	}
	for(int j=p;j<m;++j)
	{
		if(!visited[j])
		{
			visited[j]=1;
			if(BackTrack(i+1,partialSum+sticks[j],j+1))
				return true;
			visited[j]=0;
		}
	}
	return false;
}

int main()
{	
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		sum=0;
		for(int i=0;i<m;++i)
		{
			scanf("%d",&sticks[i]);
			visited[i]=0;
			sum+=sticks[i];
		}
		if(sum%4==0)
		{
			sum/=4;
			if(BackTrack(0,0,0))
				printf("yes\n");
			else printf("no\n");
		}
		else 
			printf("no\n");
	}
	return 0;
}