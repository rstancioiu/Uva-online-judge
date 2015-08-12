#include <bits/stdc++.h>
#define EPS 1e-7

using namespace std;
int t;
double l,d,h;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double pi=2*acos(0);
	cin>>t;
	while(t--)
	{
		cin>>d>>l;
        h=sqrt(l*l-d*d)/2;
		double A=pi*l*h/2;
		cout<<fixed<<setprecision(3)<<A<<endl;
	}

	return 0;
}
