// Author: Stancioiu Nicu Razvan
// Problem: http://uva.onlinejudge.org/external/116/11609.html
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int t;
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>n;
		long long int ans=n;
		n--;
		long long int p=2;
		for( int j=0;(1<<j)<=n;++j)
		{
			if((1<<j)&n)
			{
				ans=(ans*p)%MOD;
			}
			p=(p*p)%MOD;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}