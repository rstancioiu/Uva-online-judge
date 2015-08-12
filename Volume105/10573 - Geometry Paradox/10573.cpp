#include <bits/stdc++.h>

using namespace std;

int T;
string s;
double r1,r2,t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	double pi=2*acos(0);
	cin>>T;
	getline(cin,s);
	while(T--)
	{
		getline(cin,s);
		istringstream iss(s);
		iss>>t;
		bool c=false;
		if(iss>>r2)
		{
			c=true;
			r1=t;
		}
		if(c)
		{
			printf("%.4f\n",pi*2*r1*r2);
		}
		else printf("%.4f\n",pi*t*t/8);
	}

}
