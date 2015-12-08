#include <bits/stdc++.h>

using namespace std;
long long s,d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>s>>d)
	{
		d=s*(s-1)+2*d;
		long long p = sqrt(d);
		if(p*(p+1)<d)
		{
			p++;
		}
		cout<<p<<"\n";
	}
	return 0;
}