//Author Stancioiu Nicu Razvan 
//Problem: uva.onlinejudge.org/external/1/138.html
//Description: ad-hoc
// 	We search the first 10 numbers that have the following
//	property: there are 2 integers n and m so that 
//  n*(n-1)/2 = (m-n)*(m+n+1)/2
//  Like the problem 136 given the fact that we have to find
//  only 10 pair of numbers we can precompute them to speed up
// 	our solution
#include <cstdio>
#include <cmath>

int v[20]=
{
	6, 8,
	35, 49, 
	204, 288, 
	1189, 1681,
	6930, 9800,
	40391, 57121,
	235416, 332928, 
	1372105, 1940449, 
	7997214, 11309768, 
	46611179, 65918161
};

int main()
{
	int t=0;
	double i=8;
	for(int i=0;i<20;i+=2)
	{
		printf("%10d%10d\n",v[i],v[i+1]);
	}
	return 0;
}