#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double pi=2*acos(0);
	int n;
	double A;
	int c=0;
	while(cin>>n>>A && n>2)
	{
		double R2=sqrt(2*A/(sin(2*pi/n)*n));
		double h=cos(pi/n)*R2;
		cout<<fixed<<setprecision(5)<<"Case "<<++c<<": "<<R2*R2*pi-A<<" "<<A-h*h*pi<<endl;
	}
	return 0;
}
