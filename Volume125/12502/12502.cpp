// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/125/12502.html
#include <cstdio>

using namespace std;

int main()
{
	int t,x,y,z,avgtime,timespent;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&x,&y,&z);
		x*=60;
		y*=60;
		avgtime=(x+y)/3;
		timespent=x-avgtime;	
		printf("%d\n",(timespent>=0)?(timespent*z)/avgtime:0);
	}
	return 0;
}