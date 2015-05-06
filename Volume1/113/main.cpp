// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/1/113.html 
//			Power of Cryptography
// Description: Maths
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

// Given two integers n and p we have to compute p^(1/n)
int main()
{
	double n,p;
	while(scanf("%lf %lf",&n,&p)==2)
	{
		printf("%.0lf\n",pow(p,1/n));
	}
	return 0;
}