#include <cstdio>

using namespace std;
int s,p,y,j,d,spot,puff,yertle,dif;

int main()
{
	d=12;
	while(scanf("%d %d %d %d",&s,&p,&y,&j)==4)
	{
		dif=j+d-y-p;
		yertle=dif/3;
		dif=j+d-yertle-s;
		puff=dif/2;
		spot=j+d-puff-yertle;
		printf("%d %d %d\n",spot,puff,yertle);
	}
	return 0;
}