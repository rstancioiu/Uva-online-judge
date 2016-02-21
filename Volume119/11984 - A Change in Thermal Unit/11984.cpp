#include <bits/stdc++.h>

using namespace std;
double a,b;
int t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int c=1;c<=t;++c)
	{
		cin>>a>>b;
		cout<<"Case "<<c<<": "<<fixed<<setprecision(2)<<a+5.0/9*b<<endl;
	}
	return 0;
}