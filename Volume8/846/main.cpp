#include <cstdio>

using namespace std;
int t,x,y,steps,distance;

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&x,&y);
		distance=y-x;
		int sum=0;
		for(steps=0;;++steps)
		{
			if(steps%2==0)
			{
				sum+=steps/2;
			}
			else sum+=steps/2+1;
			if(sum>=distance)
				break;
		}
		printf("%d\n",steps);

	}
	return 0;
}