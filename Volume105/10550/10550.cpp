// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/105/10550.html
#include <cstdio>

using namespace std;

int main()
{
	int start,pos1,pos2,pos3,turning,current;
	while(scanf("%d %d %d %d",&start,&pos1,&pos2,&pos3)==4 && 
		!(start==0 && pos1==0 && pos2==0 && pos3==0))
	{
		turning=0;
		current=start;
		turning+=2*40;
		turning+=(current-pos1+40)%40;
		current=pos1;
		turning+=40;
		turning+=(-current+pos2+40)%40;
		current=pos2;
		turning+=(-pos3+current+40)%40;
		printf("%d\n",turning*9);
	}
	return 0;
}