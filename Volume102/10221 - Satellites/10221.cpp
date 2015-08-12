#include <bits/stdc++.h>

using namespace std;

int s;
double a;
string t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int re=6440;
	double pi=2*acos(0);
	while(cin>>s>>a>>t)
	{
		if(t=="min")
            a/=60;
		double r=s+re;
		a=(360-a>a)?a:360-a;
		if(a!=180)
            printf("%.6f %.6f\n",2*r*pi*a/360,2*sin(pi*a/360)*r);
        else
            printf("%.6f %.6f\n",2*r*pi*a/360,2*r);
	}
	return 0;
}
