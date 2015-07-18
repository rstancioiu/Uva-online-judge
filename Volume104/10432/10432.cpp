// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/104/10432.html
#include <bits/stdc++.h>

using namespace std;

int n;
double r;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>r>>n)
	{
		printf("%.3f\n",n*r*r*sin(2*M_PI/n)/2);
	}
	return 0;
}