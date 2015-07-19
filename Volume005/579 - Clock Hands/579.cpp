// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/5/579.html
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main()
{
	float hour,min;
	while(scanf("%f:%f",&hour,&min)==2)
	{
		if(hour==0 && min==0)
			break;
		if(hour==12)
			hour=0;
		hour=30.0*hour + (min/60.0)*30.0;
		min*=6.0;
		float res=abs(hour-min);
		res=round(res*1000)/1000;
		if(res>180)
			printf("%.3f\n",360.0-res);
		else
			printf("%.3f\n",res);
		
	}
	return 0;
}