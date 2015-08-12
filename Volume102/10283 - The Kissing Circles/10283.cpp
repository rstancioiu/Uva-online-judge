#include <bits/stdc++.h>

using namespace std;

int R,n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double pi=2*acos(0);
	while(cin>>R>>n)
	{
	    if(n>=3)
        {
            double r=(double)R/(1.0/sin(pi/n)+1.0);
            double a=n*(R-r)*(R-r)*sin(2*pi/n)/2;
            double acb=R*R*pi;
            double acl=n*r*r;
            printf("%.10f %.10f %.10f\n",r,a-acl*(pi/2-pi/n),acb-a-acl*(pi/2+pi/n));
        }
        else if(n==2)
        {
            printf("%.10f %.10f %.10f\n",(double)R/2,0.0,pi*R*R/2);
        }
        else if(n==1)
        {
           printf("%.10f %.10f %.10f\n",(double)R,0.0,0.0);
        }
	}
	return 0;
}
