#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-7

using namespace std;

double d,D,V;

int main()
{
	while(cin>>D>>V && (D!=0 && V!=0))
	{
		d=pow(D*D*D-6.0*V / M_PI, 1.0/3);
		printf("%.3lf\n",d+eps);
	}

	return 0;
}