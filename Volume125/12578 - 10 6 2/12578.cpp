#include <bits/stdc++.h>

using namespace std;
int t;
double n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	double pi=acos(-1);
	while(t--)
	{
		cin>>n;
		double r= n/5;
		double width=r*3;
		double At=n*width;
		double Ar=r*r*pi;
		printf("%.2f %.2f\n",Ar,At-Ar);
	}
	return 0;
}
