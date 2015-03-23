#include <cstdio>

using namespace std;

int main()
{
	int day;
	double h,u,d,f,current,df;
	while(scanf("%lf %lf %lf %lf",&h,&u,&d,&f)==4)
	{
		if(h==0)
		{
			break;
		}
		day=0;
		current=0;
		df=u*f/100;
		while(1)
		{
			current+=u;
			day++;
			if(current>h)
				break;
			current-=d;
			if(current<0)
				break;
			u=(u>=df)? u-df : 0;
		}
		if(current<0)
		{
			printf("failure on day %d\n",day);
		}
		else
		{
			printf("success on day %d\n",day);
		}
	}
	return 0;
}