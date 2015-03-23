#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	double d;
	while(!feof(stdin) && scanf("%lf",&d)==1)
	{
		if(d==0)
		{
			break;
		}
		else
		{
			double i=2.0;
			double sum=1/i;
			while(sum<d)
			{
				i++;
				sum+=1/i;
			}
			printf("%d card(s)\n",(int)i-1);
		}
	}
	return 0;
}